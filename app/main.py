import re
from dataclasses import fields
from time import sleep

from typing import List, Tuple
from pydantic import BaseModel
from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from fastapi.responses import HTMLResponse
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates
from fastapi.requests import Request
import asyncio
import app.start as start

from app.database import QueryInflux
# from build.signal_operations.signal_operations.base import query

app = FastAPI()
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"],
)

# mounting static directory
app.mount("/static", StaticFiles(directory="app/static"), name="static")
templates = Jinja2Templates(directory="app/templates")

class FloatFieldModel(BaseModel):
    floatField: float

id_of_subprocess = None

@app.post("/subscriber")
async def post(data: FloatFieldModel):
    global id_of_subprocess
    field_value = data.floatField
    print(field_value)
    if id_of_subprocess:
        start.stop_subscriber_node(id_of_subprocess)

    id_of_subprocess = start.start_subscriber_node(field_value)
    return {"status": "success", "numericField": field_value}

@app.get("/fields")
async def fields():
    query = QueryInflux()
    fields = query.get_field_keys()
    return {"fields": fields}


@app.get("/", response_class=HTMLResponse)
async def get(request: Request):
    global id_of_subprocess
    id_of_subprocess = start.start_subscriber_node(10.0)
    query = QueryInflux()
    fields = query.get_field_keys()
    return templates.TemplateResponse("index.html", {"request": request, "fields": fields})


@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket, fields: str):
    await websocket.accept()
    fields = fields.split(",")
    print("Connected, fields: ", fields)

    # create a QueryInflux object for each requested field
    query_handlers = []

    for field in fields:
        query = QueryInflux(field=field)
        query_handlers.append(query)
    try:
        while True:
            # feed is a list of tuples of lists :) containing the data from queries on each field and their filtered form
            feed = [data_feed(q_handler) for q_handler in query_handlers]
            for data, filtered_data in feed:
                batch = []
                batch.append(
                    {field: data}
                )
                batch.append(
                    {field + "_filtered": filtered_data}
                )
                await websocket.send_json(batch)
            # for field_nr, field in enumerate(fields):
            #     sensor_feed = feed[field_nr]
            #     batch = []
            #
            #     for el in sensor_feed:
            #         batch.append({field: el},)
            #
            #     if not batch:
            #         # print("No data")
            #         break
            #     await websocket.send_json(batch)
                # print("Sent batch")
            await asyncio.sleep(0.02)
    except WebSocketDisconnect:
        print("Client disconnected")
        await websocket.close()


def data_feed(query_handler: QueryInflux) -> Tuple[List, List]:
    # query = QueryInflux(10, 10, 100,field=field)
    result = query_handler.query()
    results = []
    results_filtered = []
    for table in result:
        # print("Table", table)
        for record in table.records:
            if (re.search("filtered_", record.get_field())):
                results_filtered.append(
                    {
                    "time": record.get_time().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3],
                    "value": record.get_value()
                    }
                )
            else:
                results.append(
                    {
                        "time": record.get_time().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3],
                        "value": record.get_value()
                    }
                )

    # print(len(results))
    return results, results_filtered

#on shutdown
@app.on_event("shutdown")
async def shutdown_event():
    global id_of_subprocess
    if id_of_subprocess:
        start.stop_subscriber_node(id_of_subprocess)
        id_of_subprocess = None
        print("Subscriber node stopped")