# esp_code_for-_s
# ESP32 Sensor Testing

This repository contains code to test various sensors with the ESP32, including:
- DHT11/DHT22 Temperature and Humidity Sensor
- MQ-2 Gas Sensor
- GP2Y1010AU0F Dust Sensor

## Requirements

- ESP32 development board
- Arduino IDE with ESP32 board definitions installed
- DHT11 or DHT22 sensor
- MQ-2 gas sensor
- GP2Y1010AU0F dust sensor
- Jumper wires
- Breadboard (optional)

## Installation

1. Install the ESP32 board definitions in the Arduino IDE:
   - Go to `File` > `Preferences`.
   - In the "Additional Boards Manager URLs" field, add the following URL: `https://dl.espressif.com/dl/package_esp32_index.json`.
   - Go to `Tools` > `Board` > `Boards Manager`.
   - Search for `esp32` and install the `esp32` package.

2. Install the required libraries:
   - Go to `Sketch` > `Include Library` > `Manage Libraries`.
   - Search for `DHT sensor library` and install it.

## Wiring

### DHT11/DHT22

| DHT Pin | ESP32 Pin |
|---------|-----------|
| VCC     | 3.3V      |
| GND     | GND       |
| Data    | GPIO 15   |

*Note: Add a 10k Ohm pull-up resistor between the Data pin and VCC if required by your sensor.*

### MQ-2

| MQ-2 Pin    | ESP32 Pin |
|-------------|-----------|
| VCC         | 5V        |
| GND         | GND       |
| Digital Out | GPIO 4    |

### GP2Y1010AU0F

| GP2Y1010AU0F Pin | ESP32 Pin |
|------------------|-----------|
| VCC              | 5V        |
| GND              | GND       |
| LED              | GPIO 5    |
| Analog Out       | GPIO 35   |
