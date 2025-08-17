# Arduino Car Diagnostics - WiFi Connection Test

A simple Arduino sketch that connects to WiFi and displays connection information.

## Setup Instructions

1. **Copy the example config file:**
   ```bash
   cp config.example.h config.h
   ```

2. **Edit config.h with your WiFi credentials:**
   ```cpp
   #define WIFI_SSID "your_actual_wifi_ssid"
   #define WIFI_PASSWORD "your_actual_wifi_password"
   ```

3. **Upload the sketch to your Arduino board**

## Features

- Connects to WiFi using credentials from config.h
- Displays connection status and network information
- Automatically attempts to reconnect if connection is lost
- Monitors signal strength (RSSI)
- Shows IP address, gateway, subnet mask, and DNS information

## Security Note

- The `config.h` file contains your actual WiFi credentials
- This file is automatically ignored by Git (see .gitignore)
- Never commit `config.h` to version control
- Use `config.example.h` as a template for other developers

## Hardware Requirements

- Arduino board with WiFi capability (ESP32, ESP8266, Arduino WiFi Rev2, etc.)
- USB cable for programming

## Serial Monitor

Open the Serial Monitor at 115200 baud to see:
- Connection progress
- WiFi status
- Network information
- Signal strength

## Troubleshooting

- Ensure your WiFi credentials are correct in `config.h`
- Check that your Arduino board supports WiFi
- Verify your WiFi network is accessible
- Monitor the Serial output for error messages
