# Wybierz obraz bazowy dla ROS2
FROM osrf/ros:humble-desktop

# Zainstaluj dodatkowe pakiety, np. curl do InfluxDB
RUN apt-get update && apt-get install -y \
    curl python3-colcon-common-extensions \
    && rm -rf /var/lib/apt/lists/*

# Skopiuj pliki projektu do kontenera
COPY /src /workspace
WORKDIR /workspace


# Zbuduj workspace ROS2
# RUN colcon build

# Ustaw domyślne środowisko ROS2
# ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/humble/setup.sh && source /workspace/install/setup.sh && exec \"$@\""]
CMD ["bash"]
