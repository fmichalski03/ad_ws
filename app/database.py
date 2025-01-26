from collections import namedtuple
from datetime import timedelta
from time import sleep

import influxdb_client
from influxdb_client.client.write_api import SYNCHRONOUS
import os
from dotenv import load_dotenv
import datetime

load_dotenv()

bucket = os.getenv("INFLUXDB_BUCKET")
org = os.getenv("INFLUXDB_ORG")
token = os.getenv("INFLUXDB_TOKEN")
url = os.getenv("INFLUXDB_URL")

client = influxdb_client.InfluxDBClient(
    url=url,
    token=token,
    org=org
)

class QueryInflux:
    def __init__(self, timerange = 1, offset = 1, chunk_size = 100, field = ""):
        self.timerange = timerange
        self.offset = offset
        self.chunk_size = chunk_size
        self.field = field
        self.query_api = client.query_api()
        self.last_time = datetime.datetime.utcnow() - datetime.timedelta(seconds=timerange)

    def query(self):
        # Query database
        start_time = (self.last_time + datetime.timedelta(milliseconds=1)).strftime('%Y-%m-%dT%H:%M:%S.%fZ')

        self.last_time = datetime.datetime.utcnow()
        stop_time = self.last_time.strftime('%Y-%m-%dT%H:%M:%S.%fZ')

        query = (f'from(bucket:"ad_ws")\
        |> range(start: {start_time}, stop: {stop_time})\
        |> filter(fn: (r) => r._field == "{self.field}")')


        result = self.query_api.query(org=org, query=query)
        return result


    def get_field_keys(self):
        query = '''
        import "influxdata/influxdb/schema"
        schema.fieldKeys(bucket: "ad_ws")
        '''
        result = self.query_api.query(org=org, query=query)
        results = []
        for table in result:
            for record in table.records:
                results.append(record.get_value())
        return results
