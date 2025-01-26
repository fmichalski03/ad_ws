import os
import subprocess

# Funkcja do uruchomienia node'a subscribera z paczki signal_operations
def start_subscriber_node():
    try:
        command = (
            'source /opt/ros/humble/setup.bash && '
            'source install/setup.bash && '
            'ros2 run signal_operations publisher'
        )
        process = subprocess.Popen(command, shell=True, executable='/bin/bash')
        print(f"Node 'publisher' started with PID {process.pid}")
        return process
    except Exception as e:
        print(f"Failed to start node: {e}")
        return None

# Funkcja do zamknięcia node'a
def stop_subscriber_node(process):
    if process is not None:
        try:
            process.terminate()
            process.wait()
            print("Node 'publisher' stopped successfully.")
        except Exception as e:
            print(f"Failed to stop node: {e}")

# Przykład uruchomienia i zamknięcia node'a
if __name__ == '__main__':
    node_process = start_subscriber_node()
    try:
        input("Press Enter to stop the node...\n")
    finally:
        stop_subscriber_node(node_process)
