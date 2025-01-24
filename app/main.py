from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from fastapi.responses import HTMLResponse
from fastapi.middleware.cors import CORSMiddleware
from typing import List
import asyncio
import random

from rosidl_generator_c import basetype_to_c

from app.database import QueryInflux, result

app = FastAPI()
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"],
)

html = open("app/site/index.html").read()


@app.get("/fields")
async def get_fields():
    query = QueryInflux()
    fields = query.get_field_keys()
    return {"fields": fields}


@app.get("/display", response_class=HTMLResponse)
async def display(fields: str):
    print(fields.split(","))
    return html


@app.get("/", response_class=HTMLResponse)
async def get():
    return main_site


@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket, fields: str):
    await websocket.accept()
    fields = fields.split(",")
    try:
        i = 0
        # mock_feeds = [mock_data_feed(field) for field in fields]
        while True:
            mock_feeds = [data_feed(field) for field in fields]
            while True:
                for field_nr, field in enumerate(fields):
                    mock_feed = mock_feeds[field_nr]
                    batch = []
                    for el in mock_feed[i:i + 5]:
                        batch.append({field: el})
                        # if len(batch) >= 10:
                        #     break
                    i += 5

                    # print("Batch", batch)
                    if not batch:
                        print("No data")
                        # print(field_nr, field)
                        await asyncio.sleep(0.05)
                        continue

                    await websocket.send_json(batch)
                    await asyncio.sleep(0.05)
                    print("Sent batch")
    except WebSocketDisconnect:
        print("Client disconnected")


def data_feed(field):
    query = QueryInflux(1, 100, field)
    result = query.query()
    results = []
    for table in result:

        for record in table.records:
            results.append(
                {"time": record.get_time().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3], "value": record.get_value()})
            # yield {"time": record.get_time().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3], "value": record.get_value()}
            # await asyncio.sleep(1)

    # print(len(results))
    return results



def mock_data_feed(field):
    query = QueryInflux(1000, 10000, field)

    result = query.query()

    # print("Query result", result)
    results = []
    for table in result:

        for record in table.records:
            results.append(
                {"time": record.get_time().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3], "value": record.get_value()})
            # yield {"time": record.get_time().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3], "value": record.get_value()}
            # await asyncio.sleep(1)

    # print(len(results))
    return results


main_site = '''
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>InfluxDB Field Selector</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            padding: 20px;
        }
        .field-checkbox {
            margin-bottom: 10px;
        }
        button {
            margin-top: 20px;
            padding: 10px 20px;
            font-size: 16px;
        }
    </style>
</head>
<body>
    <h1>Select Fields</h1>
    <form id="field-form">
        <div id="checkbox-container"></div>
        <button type="button" id="view-data-button">View Data</button>
    </form>

    <script>
        async function fetchFields() {
            try {
                const response = await fetch("http://localhost:8000/fields");
                const data = await response.json();
                return data.fields; // Assuming your backend sends { fields: [...] }
            } catch (error) {
                console.error("Error fetching fields:", error);
                return [];
            }
        }

        async function initializeForm() {
            const fieldKeys = await fetchFields();
            const checkboxContainer = document.getElementById("checkbox-container");

            if (fieldKeys.length === 0) {
                checkboxContainer.textContent = "No fields available.";
                return;
            }

            fieldKeys.forEach((field) => {
                const checkboxWrapper = document.createElement("div");
                checkboxWrapper.classList.add("field-checkbox");

                const checkbox = document.createElement("input");
                checkbox.type = "checkbox";
                checkbox.id = field;
                checkbox.name = "fields";
                checkbox.value = field;

                const label = document.createElement("label");
                label.htmlFor = field;
                label.textContent = field;

                checkboxWrapper.appendChild(checkbox);
                checkboxWrapper.appendChild(label);
                checkboxContainer.appendChild(checkboxWrapper);
            });
        }

        document.getElementById("view-data-button").addEventListener("click", () => {
            const selectedFields = Array.from(document.querySelectorAll('input[name="fields"]:checked'))
                .map((checkbox) => checkbox.value);

            if (selectedFields.length === 0) {
                alert("Please select at least one field.");
                return;
            }

            // Navigate to the data display page with selected fields
            const params = new URLSearchParams({ fields: selectedFields.join(",") });
            window.location.href = `display?${params.toString()}`;
        });

        initializeForm();

    </script>
</body>
</html>
'''