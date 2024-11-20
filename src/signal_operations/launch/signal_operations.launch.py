from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='signal_operations',
            executable='publisher',
            name='publisher'
        ),
        Node(
            package='signal_operations',
            executable='subscriber',
            name='subscriber'
        )
    ])