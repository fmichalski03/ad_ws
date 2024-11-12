import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from std_msgs.msg import Float32


class XsensSubscriber(Node):

    def __init__(self):
        super().__init__('xsens_subscriber')
        self.subscription = self.create_subscription(
            Float32,
            'signal',
            self.listener_callback,
            10)
        self.subscription 

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%f"' % msg.data)


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