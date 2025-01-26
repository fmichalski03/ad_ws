// import Chart from 'chart.js/auto'

// const ws = new WebSocket('ws://localhost:8000/ws?fields=torque');
// // Chart.register(ChartZoom);

let ws = null;
let chart = null;
let maxYValue = 0;
const maxDataPoints = 1050;

function initializeChart() {
  const ctx = document.getElementById("acquisitions").getContext("2d");
  return new Chart(ctx, {
    type: "line",
    data: {
      labels: [],
      datasets: [
        {
          label: "",
          data: [],
          borderColor: "rgba(75, 192, 192, 1)",
          backgroundColor: "rgba(75, 192, 192, 0.2)",
        },
      ],
    },
    options: {
      layout: {
        padding: 50,
      },
      animation: false,
      responsive: true,
      scales: {
        x: {
          type: 'time',
          time: {
            unit: 'second',
            displayFormats: {
              second: 'HH:mm:ss',
              millisecond: 'HH:mm:ss.SSS'
            },
            tooltipFormat: 'HH:mm:ss.SSS',
            // stepSize: 1
          },
          title: {
            display: true,
            text: 'Time'
          },
          adapters: {
            date: {
              zone: 'UTC'
            }
          },
          ticks: {
            autoSkip: true,
            maxTicksLimit: 20
          },
        },
        y: {
          title: {
            display: true,
            text: 'Value'
          },
        }
      },
      elements: {
        point: {
          radius: 0,
        },
      },
    },
  });
}

function showChart(field) {
  // Close websocket connection
  if (ws) {
    ws.close();
  }

  // Destroy existing chart
  if (chart) {
    chart.destroy();
  }

  // Initialize a new chart
  chart = initializeChart();

  // Create a new connection with websocket
  ws = new WebSocket(`ws://localhost:8000/ws?fields=${field}`);

  // Handle incoming WebSocket messages
  ws.onmessage = function (event) {
    const batch = JSON.parse(event.data);

    batch.forEach((data) => {
      Object.entries(data).forEach(([sensorName, sensorData]) => {
        // Append new data
        chart.data.datasets[0].label = sensorName;
        chart.data.labels.push(sensorData.time);
        chart.data.datasets[0].data.push(sensorData.value);

        if (sensorData.value > (maxYValue*1.1) || sensorData.value < -(maxYValue*1.1)) {
          maxYValue = Math.abs(sensorData.value)
          chart.options.scales.y.max = (maxYValue * 1.2);
          chart.options.scales.y.min = -(maxYValue * 1.2);
        }

        // Remove old data if the limit is exceeded
        if (chart.data.datasets[0].data.length > maxDataPoints) {
          chart.data.labels.shift(); // Remove the oldest label
          chart.data.datasets[0].data.shift(); // Remove the oldest data point
        }

        // Re-render the chart
        chart.update('none');
      });
    });
  };

  ws.onerror = function (error) {
    console.error("WebSocket error:", error);
  };

  ws.onclose = function () {
    console.log("WebSocket connection closed");
  };
}

// Window resize handler
window.addEventListener('resize', () => {
  if (chart) {
    chart.resize();
  }
});

function createButtons(fields) {
  const buttonContainer = document.getElementById("button-container");

  fields.forEach((field) => {
    const button = document.createElement("button");
    button.textContent = field;
    button.setAttribute("data-field", field);
    button.classList.add("field-button");

    // Add click event listener to the button
    button.addEventListener("click", () => {
      showChart(field);
    });

    buttonContainer.appendChild(button);
  });
}

async function initialize() {
  try {
    const response = await fetch("/fields");
    const data = await response.json();
    const fields = data.fields;

    // Create buttons for each field
    createButtons(fields);

    // load first chart
    if (fields.length > 0) {
      showChart(fields[0]);
    }
  } catch (error) {
    console.error("Failed to fetch fields:", error);
  }
}

initialize();

