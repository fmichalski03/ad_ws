# ad_ws
## ROS2 workspace for ambedded systems project
### FIlip Michalski
### Piotr Laskowski
### Paweł Mazurkiewicz
## Instal ROS2 Humble
[link](https://docs.ros.org/en/humble/Installation.html)
## Clone repository
```
git clone --recursive-submodules git@github.com:fmichalski03/ad_ws.git
```
## Source ROS2
```
source /opt/ros/humble/setup.bash
```
## Building workspace
```
colcon build
```
## Source bash
```
souce install/setup.bash
```
## Launch entire workspace
```
ros2 launch launch/ad_ws.launch.py
```
## Running subscriber
```
ros2 run signal_operations subscriber
```
## Running publisher
```
ros2 run signal_operations publisher
```
## Rqt_graph
```
ros2 run rqt_graph rqt_graph
```
## Run backend
```
uvicorn app.main:app --reload
```
## Run bag file
```
ros2 bag play <bag file>
```
