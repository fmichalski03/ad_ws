# Użyj oficjalnego obrazu ROS 2 Humble jako bazowego
FROM ros:humble

# Ustawienie zmiennych środowiskowych dla ROS
ENV DEBIAN_FRONTEND=noninteractive \
    ROS_DISTRO=humble \
    LANG=C.UTF-8 \
    LC_ALL=C.UTF-8

# Zainstaluj narzędzia i zależności
RUN apt-get update && apt-get install -y --no-install-recommends \
    curl \
    wget \
    git \
    build-essential \
    python3-colcon-common-extensions \
    python3-pip \
    && apt-get clean

# Zainstaluj Python SDK dla InfluxDB
RUN pip3 install influxdb-client

# Ustaw katalog roboczy
WORKDIR /ros2_ws

# Skopiuj pliki workspace do obrazu
COPY . /ros2_ws

RUN rosdep install --from-paths ros2_ws/src --ignore-src -r -y


# Ustawienie domyślnego punktu startowego
CMD ["bash"]

