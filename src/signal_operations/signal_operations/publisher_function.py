import rclpy
from rclpy.node import Node

from ad_ws_interfaces.msg import Xsens
from control_interfaces.msg import Control
import numpy as np
from signal_operations.generate_signal import generate_control_points
from dotenv import load_dotenv
import os

import influxdb_client
from influxdb_client.client.write_api import SYNCHRONOUS

class SignalPublisher(Node):

    def __init__(self, write_api, bucket, org):
        super().__init__('singal_publisher')
        self.publisher_ = self.create_publisher(Control, '/mpc/ctrl', 10)
        timer_period = 0.01  # seconds
        self.steering_array = generate_control_points(value_range=(-0.5, 0.5))
        self.speed_array = generate_control_points(value_range=(0.5, 4))
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

        self.write_api = write_api
        self.bucket = bucket
        self.org = org

    def timer_callback(self):
        msg = Control()
        msg.control_mode = msg.SPEED_MODE
        msg.steering_angle = self.steering_array[self.i]
        msg.set_speed = self.speed_array[self.i]
        self.i += 1
        if self.i == len(self.steering_array):
            self.steering_array = generate_control_points(value_range=(-0.5, 0.5))
            self.speed_array = generate_control_points(value_range=(0.5, 4))
            self.i = 0
        self.publisher_.publish(msg)
        
        # Log and save data to InfluxDB
        self.get_logger().info('Publishing steering: "%f"' % msg.steering_angle)
        self.get_logger().info('Publishing speed: "%f"' % msg.set_speed)

        point = (
            influxdb_client.Point("control_signal")
            .field("steering_angle", msg.steering_angle)
            .field("set_speed", msg.set_speed)
        )
        self.write_api.write(bucket=self.bucket, org=self.org, record=point)

def main(args=None):
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
    write_api = client.write_api(write_options=SYNCHRONOUS)

    rclpy.init(args=args)

    signal_publisher = SignalPublisher(write_api, bucket, org)

    rclpy.spin(signal_publisher)

    signal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()