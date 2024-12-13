import rclpy
from rclpy.node import Node
import influxdb_client
from influxdb_client.client.write_api import SYNCHRONOUS
from dotenv import load_dotenv
import os

from control_interfaces.msg import ServoState
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from vesc_msgs.msg import VescStateStamped

class ServoSubscriber(Node):
    def __init__(self, write_api, bucket, org):
        super().__init__('servo_subscriber')

        self.write_api = write_api
        self.bucket = bucket
        self.org = org

        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10  
        )

        self.subscription = self.create_subscription(
            ServoState,
            'pub_position',
            self.listener_callback,
            qos_profile
        )

    def listener_callback(self, msg):
        point = (
            influxdb_client.Point("my_measurement")
            .field("position", msg.position)
            .field("velocity", msg.velocity)
            .field("torque", msg.torque)
        )
        self.write_api.write(bucket=self.bucket, org=self.org, record=point)

        self.get_logger().info('Position: "%f"' % msg.position)
        self.get_logger().info('Velocity: "%f"' % msg.velocity)
        self.get_logger().info('Torque: "%f"' % msg.torque)


class StateSubscriber(Node):
    def __init__(self):
        super().__init__('state_subscriber')

        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10  
        )

        self.subscription = self.create_subscription(
            VescStateStamped,
            'vesc/core',
            self.listener_callback,
            qos_profile
        )

    def listener_callback(self, msg):
        self.get_logger().info('Motor current: "%f"' % msg.state.current_motor)
        self.get_logger().info('Speed: "%f"' % msg.state.speed)
        self.get_logger().info('Voltage input: "%f"' % msg.state.voltage_input)


def main(args=None):
    load_dotenv()

    # In root of the project, create a .env file with the following variables:
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

    servo_subscriber = ServoSubscriber(write_api, bucket, org)
    state_subscriber = StateSubscriber()

    rclpy.spin(servo_subscriber)
    rclpy.spin(state_subscriber)

    servo_subscriber.destroy_node()
    state_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
