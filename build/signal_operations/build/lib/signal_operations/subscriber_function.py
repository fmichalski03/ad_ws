import rclpy
from rclpy.node import Node

from ad_ws_interfaces.msg import Xsens


class XsensSubscriber(Node):

    def __init__(self):
        super().__init__('xsens_subscriber')
        self.subscription = self.create_subscription(
            Xsens,
            'xsens_node',
            self.listener_callback,
            10)
        self.subscription 

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%f"' % msg.acc_x)


def main(args=None):
    rclpy.init(args=args)

    xsens_subscriber = XsensSubscriber()

    rclpy.spin(xsens_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    xsens_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()