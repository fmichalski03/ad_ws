import rclpy
from rclpy.node import Node

from ad_ws_interfaces.msg import Xsens
from geometry_msgs.msg import Vector3Stamped
from geometry_msgs.msg import PoseStamped
from control_interfaces.msg import ServoState


class XsensSubscriber(Node):

    def __init__(self):
        super().__init__('xsens_subscriber')
        self.subscription = self.create_subscription(
            PoseStamped,
            'optitrack/rigid_body_0',
            self.listener_callback,
            10)
        self.subscription 

    def listener_callback(self, msg):
        self.get_logger().info('Angular velocity x: "%f"'% msg.vector.x)
        self.get_logger().info('Angular velocity y: "%f"'% msg.vector.y)
        self.get_logger().info('Angular velocity z: "%f"'% msg.vector.z)

class ServoSubscriber(Node):
    def __init__(self):
        super().__init__('servo_subscriber')
        self.subscription = self.create_subscription(
            ServoState,
            'pub_position',
            self.listener_callback,
            10)
        self.subscription 

    def listener_callback(self, msg):
        self.get_logger().info('Angular velocity x: "%f"'% msg.vector.x)
        self.get_logger().info('Angular velocity y: "%f"'% msg.vector.y)
        self.get_logger().info('Angular velocity z: "%f"'% msg.vector.z)



def main(args=None):
    rclpy.init(args=args)

    xsens_subscriber = XsensSubscriber()
    servo_subscriber = XsensSubscriber()

    rclpy.spin(xsens_subscriber)
    rclpy.spin(servo_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    xsens_subscriber.destroy_node()
    servo_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()