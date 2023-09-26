# ESP8266 & Arduino Uno with Pulse and Oximetry Monitor with ThingSpeak Integration

This project integrates an ESP8266 WiFi module with an Arduino Uno to capture pulse and oximetry data, which is then displayed on an LCD screen and sent to the cloud database, ThingSpeak.

## Hardware Requirements:
- Arduino Uno board
- ESP8266 WiFi module
- LCD Screen (mention model or size if necessary)
- (Any other required components such as resistors, capacitors, etc.)

## Software Requirements:
- Arduino IDE
- ESP8266 library for Arduino
- LCD library (mention the exact library if applicable)
- ThingSpeak library for Arduino

## Wiring/Schematic Connections:

| Source Device | Source Pin | Target Device | Target Pin |
|:-------------:|:----------:|:-------------:|:----------:|
| Uno           | GND        | LCD           | VSS        |
| Uno           | GND        | LCD           | RW         |
| Uno           | 5V         | LCD           | VDD        |
| Uno           | 2          | LCD           | RS         |
| Uno           | 3          | LCD           | E          |
| Uno           | 4          | LCD           | D4         |
| Uno           | 5          | LCD           | D5         |
| Uno           | 6          | LCD           | D6         |
| Uno           | 7          | LCD           | D7         |
| atmodem       | TX         | Uno           | 0          |
| atmodem       | RX         | Uno           | 1          |
| Uno           | GND        | atmodem       | GND        |
| Uno           | 5V         | atmodem       | VCC        |
| Pot           | GND        | uno           | GND.1      |
| Pot           | VCC        | uno           | 5V         |
| Pot           | SIG        | LCD           | V0         |

## Installation and Setup:
1. Set up your Arduino IDE with the necessary libraries.
2. Connect the components as outlined in the table above.
3. Flash the provided code to the Arduino Uno.
4. Configure your WiFi credentials and ThingSpeak channel details in the code.

## Usage:
Once everything is set up:
1. Power on the Arduino and ensure it connects to the WiFi network.
2. Check the LCD for the pulse and oximetry readings.
3. Confirm the data is being updated in your ThingSpeak channel.

## Simulation:
To understand the project better and see it in action, check out the simulation on Wokwi: [Wokwi Simulation](https://wokwi.com/projects/376921405150878721).
