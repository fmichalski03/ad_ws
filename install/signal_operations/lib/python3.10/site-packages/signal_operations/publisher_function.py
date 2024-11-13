import rclpy
from rclpy.node import Node

from ad_ws_interfaces.msg import Xsens


class SignalPublisher(Node):

    def __init__(self):
        super().__init__('singal_publisher')
        self.publisher_ = self.create_publisher(Xsens, 'xsens_node', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = Xsens()
        msg.acc_x = 1.2
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%f"' % msg.acc_x)
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    signal_publisher = SignalPublisher()

    rclpy.spin(signal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    signal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
