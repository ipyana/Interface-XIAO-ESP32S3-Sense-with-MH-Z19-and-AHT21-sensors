# Interface-XIAO-ESP32S3-Sense-with-MH-Z19-and-AHT21-sensors

# ESP32S3 Environmental Sensor Array

This project uses an ESP32S3 microcontroller to read data from an MH-Z19B CO2 sensor and an AHT temperature/humidity sensor. It demonstrates how to interface with multiple sensors and print their data to the serial monitor.

## Hardware Requirements

- ESP32S3 board (e.g., Seeed XIAO ESP32S3 Sense)
- MH-Z19B CO2 sensor
- AHT20 or AHT10 temperature and humidity sensor

## Wiring

- MH-Z19B:
  - VCC to 5V
  - GND to GND
  - TX to D10 on ESP32S3
  - RX to D9 on ESP32S3

- AHT sensor:
  - VCC to 3.3V
  - GND to GND
  - SDA to SDA on ESP32S3 (usually D4)
  - SCL to SCL on ESP32S3 (usually D5)

## Software Dependencies

This project requires the following libraries:

- HardwareSerial (built-in)
- MHZ19 (by Jonathan Dempsey)
- Adafruit_AHTX0 (by Adafruit)

You can install these libraries through the Arduino IDE Library Manager.

## Functionality

The program does the following:

1. Initializes the MH-Z19B CO2 sensor and the AHT temperature/humidity sensor.
2. Every 5 seconds, it reads data from both sensors.
3. Prints the CO2 concentration in ppm, temperature in Celsius, and relative humidity percentage to the serial monitor.

## Usage

1. Connect the sensors as described in the Wiring section.
2. Install the required libraries.
3. Upload the code to your ESP32S3 board.
4. Open the Serial Monitor at 115200 baud to view the sensor readings.

## Customization

- You can adjust the reading interval by changing the value in the `if (millis() - getDataTimer >= 5000)` line.
- The MH-Z19B auto-calibration is turned on by default. You can disable it by changing `myMHZ19.autoCalibration(true)` to `myMHZ19.autoCalibration(false)`.

## Troubleshooting

- If you're not getting readings from the MH-Z19B, double-check the wiring and make sure you're using the correct RX and TX pins.
- If the AHT sensor is not found, verify the I2C connections and make sure you're using a compatible AHT10 or AHT20 sensor.

## License

This project is open source and available under the [MIT License](LICENSE).
