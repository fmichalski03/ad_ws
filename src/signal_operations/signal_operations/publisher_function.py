import rclpy
from rclpy.node import Node

from ad_ws_interfaces.msg import Xsens
from control_interfaces.msg import Control
import numpy as np
from signal_operations.generate_signal import generate_control_points



class SignalPublisher(Node):

    def __init__(self):
        super().__init__('singal_publisher')
        self.publisher_ = self.create_publisher(Control, '/mpc/ctrl', 10)
        timer_period = 0.01  # seconds
        self.steering_array = generate_control_points(value_range=(-0.5,0.5))
        self.speed_array = generate_control_points(value_range=(0.5,4))
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = Control()
        # -0.5 to 0.5
        msg.control_mode = msg.SPEED_MODE
        msg.steering_angle = self.steering_array[self.i]
        msg.set_speed = self.speed_array[self.i]
        self.i+=1
        if self.i == len(self.steering_array):
            self.steering_array = generate_control_points(value_range=(-0.5,0.5))
            self.speed_array = generate_control_points(value_range=(0.5,4))
            self.i=0
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing steering: "%f"' % msg.steering_angle)
        self.get_logger().info('Publishing speed: "%f"' % msg.set_speed)




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
