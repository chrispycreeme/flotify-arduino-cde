#include <avr/pgmspace.h>

const char webserver[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>test-ui-run</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@100..900&display=swap" rel="stylesheet">
    <script src="https://unpkg.com/boxicons@2.1.4/dist/boxicons.js"></script>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/chrispycreeme/flotify-pro@main/css/card.css">
</head>

<body>
    <div class="card-info">
        <div class="top-card-content">
            <p class="title-location">Station Approximate Location:</p>
            <p class="location-approximate">Olongapo City, Zambales, Philippines</p>
            <table>
                <tr>
                    <td>
                        <h1 class="status-heading">
                            <span class="icon-wrapper">
                                <box-icon name='thermometer' type='solid' color='#009688'
                                    style="width: 40px; height: 40px; border-radius: 50%; border: 2px solid #009688; padding: 3px;"></box-icon>
                            </span>
                            Temperature:
                        </h1>
                    </td>
                    <td>
                        <h1 class="status-value">36.32 °C</h1>
                    </td>
                </tr>
                <tr>
                    <td>
                        <h1 class="status-heading">
                            <span class="icon-wrapper">
                                <box-icon name='droplet' type='solid' color='#009688'
                                    style="width: 40px; height: 40px; border-radius: 50%; border: 2px solid #009688; padding: 3px;"></box-icon>
                            </span>
                            Humidity:
                        </h1>
                    </td>
                    <td>
                        <h1 class="status-value">50%</h1>
                    </td>
                </tr>
            </table>
        </div>
        <div class="rain-intensity-section">
            <div class="rain-text-cont">
                <p class="rain-stat-text">Rain Intensity:</p>
                <h1 class="rain-stat-auto" id="rainIntensity">No Rain</h1>
            </div>
            <dotlottie-player id="rain-lottie" src="https://lottie.host/9d984846-cd9e-4cef-84b4-f28890870cf7/FTChl2O5SN.json"
                background="transparent" speed="1"
                style="width: 190px; height: 190px; margin-top: -10px; display: inline-block;" loop
                autoplay></dotlottie-player>
        </div>
        <div class="flood-level-section">
            <div class="flood-level-text">
                <p class="flood-stat-text">Flood Levels:</p>
                <h1 class="flood-stat-auto">Safe</h1>
                <h2 class="flood-meter-auto">~ <span id="waterLevel">1.1 meters</span></h2>
            </div>
            <dotlottie-player src="https://lottie.host/b7e6971d-7845-4491-97c4-a8c32cccbddf/ZqtIR8sy8M.json"
                background="transparent" speed="1"
                style="width: 320px; height: 320px; margin-top: -40px; margin-right: -90px;"
                autoplay></dotlottie-player>
        </div>
    </div>
    <script src="https://unpkg.com/@dotlottie/player-component@latest/dist/dotlottie-player.mjs" type="module"></script>
    <script>
      setInterval(function() {
        fetch('/rain').then(response => response.json()).then(data => {
          switch (data.rainIntensity) {
            case 1:
              document.getElementById('rainIntensity').innerText = "No Rain";
              break;
            case 2:
              document.getElementById('rainIntensity').innerText = "Light";
              break;
            case 3:
              document.getElementById('rainIntensity').innerText = "Moderate";
              break;
            case 4:
              document.getElementById('rainIntensity').innerText = "Strong";
              break;
          }
        })
      }, 1000);
    </script>
</body>

</html>
)=====";
