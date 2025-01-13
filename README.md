# ad_ws
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