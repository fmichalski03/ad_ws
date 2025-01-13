# Używamy obrazu bazowego dla ROS2 Humble
FROM osrf/ros:humble-desktop

# Ustaw zmienną środowiskową dla implementacji komunikacji
ENV RMW_IMPLEMENTATION=rmw_fastrtps_cpp

# Aktualizacja systemu i instalacja zależności (jeśli potrzebne)
# RUN apt-get update && apt-get install -y \
#     python3-pip \
#     build-essential \
#     && rm -rf /var/lib/apt/lists/*

# Skopiowanie workspace do obrazu
COPY ./ros2_ws /ros2_ws

# Ustawienie katalogu roboczego
WORKDIR /ros2_ws

# Budowanie workspace (jeśli używasz colcona)
RUN apt-get update && \
    rosdep update && \
    rosdep install --from-paths src --ignore-src -r -y && \
    colcon build

# Ustawienie domyślnego polecenia (bash w tym przypadku)
CMD ["/bin/bash"]
