import os
import subprocess
import signal

# Funkcja do uruchomienia node'a subscribera z paczki signal_operations
def start_subscriber_node(cutoff):
    try:
        command = (
            'source /opt/ros/humble/setup.bash && '
            'source install/setup.bash && '
            f'ros2 run signal_operations subscriber --ros-args -p butter_filter_cutoff:={cutoff}'
        )
        process = subprocess.Popen(command, shell=True, executable='/bin/bash', preexec_fn=os.setsid)
        print(f"Node 'subscriber' started with PID {process.pid}")
        return process
    except Exception as e:
        print(f"Failed to start node: {e}")
        return None

# Funkcja do zamknięcia node'a
def stop_subscriber_node(process):
    if process is not None:
        try:
            os.killpg(os.getpgid(process.pid), signal.SIGTERM)
            print("Sent SIGTERM to process group.")

            process.wait(timeout=5)
            print("Node 'subscriber' stopped successfully.")
        except subprocess.TimeoutExpired:
            print("Process did not terminate gracefully. Forcefully killing...")
            os.killpg(os.getpgid(process.pid), signal.SIGKILL)  # Forcefully kill the process group
            process.wait()
            print("Node 'subscriber' forcefully killed.")
        except Exception as e:
            print(f"Failed to stop node: {e}")

# Przykład uruchomienia i zamknięcia node'a
if __name__ == '__main__':
    node_process = start_subscriber_node()
    try:
        input("Press Enter to stop the node...\n")
    finally:
        stop_subscriber_node(node_process)
