import rclpy
from rclpy.node import Node

from control_interfaces.msg import ServoState
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from vesc_msgs.msg import VescStateStamped


class ServoSubscriber(Node):
    def __init__(self):
        super().__init__('servo_subscriber')

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
    rclpy.init(args=args)

    servo_subscriber = ServoSubscriber()
    state_subscriber = StateSubscriber()

    rclpy.spin(servo_subscriber)
    rclpy.spin(state_subscriber)

    servo_subscriber.destroy_node()
    state_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
