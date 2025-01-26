from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from fastapi.responses import HTMLResponse
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates
from fastapi.requests import Request
import asyncio

from app.database import QueryInflux

app = FastAPI()
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"],
)

# mounting static directory
app.mount("/static", StaticFiles(directory="static"), name="static")
templates = Jinja2Templates(directory="templates")


@app.get("/", response_class=HTMLResponse)
async def get(request: Request):
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
            # feed is a list of lists containing the data from queries on each field
            feed = [data_feed(q_handler) for q_handler in query_handlers]
            for field_nr, field in enumerate(fields):
                sensor_feed = feed[field_nr]
                batch = []

                for el in sensor_feed:
                    batch.append({field: el})

                if not batch:
                    # print("No data")
                    break
                await websocket.send_json(batch)
                # print("Sent batch")
            await asyncio.sleep(0.02)
    except WebSocketDisconnect:
        print("Client disconnected")
        await websocket.close()


def data_feed(query_handler: QueryInflux):
    # query = QueryInflux(10, 10, 100,field=field)
    result = query_handler.query()
    results = []
    for table in result:
        # print("Table", table)
        for record in table.records:
            results.append(
                {
                    "time": record.get_time().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3],
                    "value": record.get_value()
                }
            )

    # print(len(results))
    return results
