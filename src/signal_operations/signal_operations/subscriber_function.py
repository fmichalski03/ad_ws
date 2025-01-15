import rclpy
from rclpy.node import Node
import influxdb_client
from influxdb_client.client.write_api import SYNCHRONOUS
from dotenv import load_dotenv
import os

from control_interfaces.msg import ServoState
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from vesc_msgs.msg import VescStateStamped

from scipy.signal import butter, filtfilt

class ButterworthFilter:
    def __init__(self, cutoff, fs, order=4):
        self.cutoff = cutoff
        self.fs = fs
        self.order = order
        self.b, self.a = butter(order, cutoff / (0.5 * fs), btype='low', analog=False)

    def apply(self, data):
        return filtfilt(self.b, self.a, data)


class ServoSubscriber(Node):
    def __init__(self, write_api, bucket, org, butter_filter):
        super().__init__('servo_subscriber')

        self.write_api = write_api
        self.bucket = bucket
        self.org = org
        self.butter_filter = butter_filter

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

        self.data_buffer = {"position": [], "velocity": [], "torque": []}
        self.buffer_size = 50  # Minimalna ilość danych do filtrowania

    def listener_callback(self, msg):
        # Aktualizuj bufor danych
        self.data_buffer["position"].append(msg.position)
        self.data_buffer["velocity"].append(msg.velocity)
        self.data_buffer["torque"].append(msg.torque)

        # Zachowaj ostatnie `buffer_size` próbek
        for key in self.data_buffer:
            if len(self.data_buffer[key]) > self.buffer_size:
                self.data_buffer[key].pop(0)

        # Filtrowanie, gdy zgromadzono wystarczającą liczbę próbek
        if len(self.data_buffer["position"]) >= self.buffer_size:
            filtered_position = self.butter_filter.apply(self.data_buffer["position"])[-1]
            filtered_velocity = self.butter_filter.apply(self.data_buffer["velocity"])[-1]
            filtered_torque = self.butter_filter.apply(self.data_buffer["torque"])[-1]

            # Zapis przefiltrowanych danych do bazy
            point = (
                influxdb_client.Point("my_measurement")
                .field("position", filtered_position)
                .field("velocity", filtered_velocity)
                .field("torque", filtered_torque)
            )
            self.write_api.write(bucket=self.bucket, org=self.org, record=point)

            self.get_logger().info(f'Filtered Position: {filtered_position:.2f}')
            self.get_logger().info(f'Filtered Velocity: {filtered_velocity:.2f}')
            self.get_logger().info(f'Filtered Torque: {filtered_torque:.2f}')

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

    cutoff_frequency = 5.0  # Hz
    sampling_rate = 50.0  # Hz (częstotliwość próbkowania)
    butter_filter = ButterworthFilter(cutoff=cutoff_frequency, fs=sampling_rate, order=4)

    client = influxdb_client.InfluxDBClient(
        url=url,
        token=token,
        org=org
    )
    write_api = client.write_api(write_options=SYNCHRONOUS)

    rclpy.init(args=args)

    servo_subscriber = ServoSubscriber(write_api, bucket,org, butter_filter)
    state_subscriber = StateSubscriber()

    rclpy.spin(servo_subscriber)
    rclpy.spin(state_subscriber)

    servo_subscriber.destroy_node()
    state_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
