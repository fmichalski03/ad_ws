// import Chart from 'chart.js/auto'

// const ws = new WebSocket('ws://localhost:8000/ws?fields=torque');
// // Chart.register(ChartZoom);

let ws = null;
let chart = null;
let maxYValue = 0;
let maxDataPoints = 1050;
let cutoff = 10;
// const maxDataPointsElement = document.getElementById("maxDataPoints");

function initializeChart() {
  const ctx = document.getElementById("acquisitions").getContext("2d");
  return new Chart(ctx, {
    type: "line",
    data: {
      labels: [],
      datasets: [],
    },
    options: {
      layout: {
        padding: 50,
      },
      animation: false,
      // responsive: true,
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
  if (ws) {
    ws.close();
  }

  if (chart) {
    chart.destroy();
  }

  chart = initializeChart();

  ws = new WebSocket(`ws://${location.hostname}:${location.port}/ws?fields=${field}`);

  ws.onmessage = function (event) {
    const batch = JSON.parse(event.data);

    batch.forEach((data) => {
        Object.entries(data).forEach(([fieldName, dataArray]) => {
            let dataset = chart.data.datasets.find((ds) => ds.label === fieldName);
            if (!dataset) {
                dataset = {
                    label: fieldName,
                    data: [],
                    borderColor: getRandomColor(),
                    fill: false
                };
                chart.data.datasets.push(dataset);
            }

            dataArray.forEach((dataPoint) => {
                dataset.data.push({
                    x: dataPoint.time,
                    y: dataPoint.value
                });

                if (dataset.data.length > maxDataPoints) {
                    dataset.data.shift();
                }

                if (dataPoint.value > (maxYValue * 1.1) || dataPoint.value < -(maxYValue * 1.1)) {
                    maxYValue = Math.abs(dataPoint.value);
                    chart.options.scales.y.max = maxYValue * 1.2;
                    chart.options.scales.y.min = -(maxYValue * 1.2);
                }
            });
        });
    });

    // Re-render the chart
    chart.update('none');
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

window.updateNumericField = function () {
  const numericFieldValue = document.getElementById('numericField').value;
  if (cutoff !== numericFieldValue) {
    cutoff = numericFieldValue;
    fetch('/subscriber', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ floatField: numericFieldValue }),
  })
    .then(response => response.json())
    .then(data => {
      console.log('Success:', data);
    })
    .catch((error) => {
      console.error('Error:', error);
    });
  }

  maxDataPoints = document.getElementById('maxDataPoints').value;

  if (chart) {
    chart.data.datasets.forEach((dataset) => {
      if (dataset.data.length > maxDataPoints) {
        dataset.data.splice(0, dataset.data.length - maxDataPoints);
      }
    });

    chart.update('none');
  }
}

function createButtons(fields) {
  const buttonContainer = document.getElementById("button-container");

  fields.forEach((field) => {
    const button = document.createElement("button");
    button.textContent = field;
    button.setAttribute("data-field", field);
    button.classList.add("field-button");

    button.addEventListener("click", () => {
      showChart(field);
    });

    buttonContainer.appendChild(button);
  });
}

function createStopButton() {
  const buttonContainer = document.getElementById("button-container");

  const button = document.createElement("button");
  button.textContent = "Stop";
  button.classList.add("stop-button");
  button.id = "stop-button";

  button.addEventListener("click", () => {
    if (ws) {
      ws.close();
    }
  });

  buttonContainer.appendChild(button);
}

async function initialize() {
  try {
    const response = await fetch("/fields");
    const data = await response.json();
    const fields = data.fields;

    // Create buttons for each field
    createButtons(fields);
    // load first chart
    createStopButton();

    if (fields.length > 0) {
      showChart(fields[0]);
    }
  } catch (error) {
    console.error("Failed to fetch fields:", error);
  }
}

let colorIndex = 0; // Track the index of the current color

function getRandomColor() {
    const colors = ["green", "red"]; // Define the color sequence
    const color = colors[colorIndex % colors.length]; // Cycle through the colors
    colorIndex++; // Increment the index for the next call
    return color;
}

initialize();

