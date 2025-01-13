from collections import namedtuple

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

# Record = namedtuple('Record', ['time', 'field', 'value'])

class QueryInflux:
    def __init__(self, timerange = 10, chunk_size = 100, field = ""):
        self.timerange = timerange
        self.chunk_size = chunk_size
        self.field = field
        self.query_api = client.query_api()

    def query(self):
        # Query database
        # query_api = client.query_api()

        query = (f'from(bucket:"ad_ws")\
        |> range(start: -{self.timerange}h)\
        |> limit(n: {self.chunk_size})\
        |> filter(fn: (r) => r._field == "{self.field}")')

        result = self.query_api.query(org=org, query=query)

        # results = []
        # for table in result:
        #     for record in table.records:
        #         # strftime view last 3 digits
        #         results.append(Record(record.get_time().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3], record.get_field(), record.get_value()))

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


query_influx = QueryInflux()
result = query_influx.get_field_keys()
print(result)


# query_influx = QueryInflux(field='velocity')
# query_influx.timerange = 1000
# result = query_influx.query()
# print(result)