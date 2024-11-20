from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution

from launch_ros.substitutions import FindPackageShare



def generate_launch_description():

    return LaunchDescription(
        [
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    PathJoinSubstitution(
                        [
                            "src/signal_operations",
                            "launch",
                            "signal_operations.launch.py",
                        ]
                    )
                )
            ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    PathJoinSubstitution(
                        [
                            "src/bluespace_ai_xsens_ros_mti_driver-ros2_0_galactic",
                            "launch",
                            "xsens_mti_node.launch.py",
                        ]
                    )
                )
            )
        ]
    )