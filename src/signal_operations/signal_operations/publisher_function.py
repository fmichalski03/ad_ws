import rclpy
from rclpy.node import Node

from ad_ws_interfaces.msg import Xsens
from control_interfaces.msg import Control
import numpy as np


def generate_signal():
    f = 5         # częstotliwość w Hz
    fs = 500      # częstotliwość próbkowania w Hz
    t = np.arange(0, 1, 1/fs)  # przedział czasu od 0 do 1 sekundy

    # Generowanie sygnału sinusoidalnego
    amplitude = 0.5  # amplituda sygnału
    signal = amplitude * np.sin(2 * np.pi * f * t)
    signal_array = signal.tolist()
    return signal_array

signal_array = generate_signal()

class SignalPublisher(Node):

    def __init__(self):
        super().__init__('singal_publisher')
        self.publisher_ = self.create_publisher(Control, 'commands/ctrl', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = Control()
        # -0.5 to 0.5
        msg.steering_angle = signal_array[self.i]
        self.i+=1
        if self.i == len(signal_array):
            self.i=0
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%f"' % msg.steering_angle)




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
