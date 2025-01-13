# Wybór oficjalnego obrazu ROS2
FROM osrf/ros:humble-desktop

# Ustaw zmienne środowiskowe
ENV DEBIAN_FRONTEND=noninteractive
ENV ROS2_WORKSPACE=/ros2_ws

# Instalacja wymaganych pakietów
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    python3-pip \
    python3-colcon-common-extensions \
    git \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Instalacja dodatkowych zależności Python, jeśli wymagane
RUN pip3 install --upgrade pip && pip3 install \
    argcomplete \
    setuptools \
    empy \
    pytest \
    flake8

# Kopiowanie workspace do kontenera
COPY ./ros2_ws $ROS2_WORKSPACE

# Ustawienia katalogu roboczego
WORKDIR $ROS2_WORKSPACE

# Budowanie workspace
RUN /bin/bash -c "source /opt/ros/humble/setup.bash && colcon build"

# Ustawienie punktu wejścia dla kontenera
ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/humble/setup.bash && source $ROS2_WORKSPACE/install/setup.bash && bash"]
