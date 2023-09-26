# ESP8266 & Arduino Uno with Pulse and Oximetry Monitor with ThingSpeak Integration

This project integrates an ESP8266 WiFi module with an Arduino Uno to capture pulse and oximetry data, which is then displayed on an LCD screen and sent to the cloud database, ThingSpeak.

## Hardware Requirements:
- Arduino Uno board
- ESP8266 WiFi module
- 16×2 LCD Screen
- Potentiometer

## Project Structure:

### Source Files:

- `main.c`: This is the main program file where the execution begins. It initializes the necessary modules and manages the primary application loop.

- `ESP8266.c`: Contains the functions related to the ESP8266 WiFi module for connecting to networks, sending, and receiving data.

- `lcd.c`: Implements functions for interfacing and displaying data on the LCD screen.

- `uart.c`: Functions for UART (Universal Asynchronous Receiver-Transmitter) communication, allowing the microcontroller to communicate with devices like the ESP8266.

### Header Files:

- `ESP8266.h`: Header file for the `ESP8266.c`, declaring the function prototypes and any constants or macros used.

- `lcd.h`: Header file for the `lcd.c` source, containing declarations related to the LCD operations.

- `uart.h`: Contains the function prototypes, constants, and macros for UART operations in the `uart.c` source file.

### Miscellaneous:

- `Makefile`: Used for compiling and building the project. Contains rules and commands to create the final executable from the source files.

- `Schematic.JPG`: An image file illustrating the wiring and connection details for the entire setup.

- `README.md`: This file provides an overview and instructions related to the project.

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

## Setup & Usage:

Refer to the instructions earlier in this document for detailed setup and usage steps.
Configure your WiFi credentials and ThingSpeak channel details in the code.

###Generate the HEX File:
Open a command prompt or terminal in the directory containing your project files.
Run the following command:
`make all`

If you wish to upload the HEX file to a physical device, you can use the isp target in the Makefile. Connect your device to the appropriate COM port and execute:
`make isp`

## Simulation:
To understand the project better and see it in action, check out the simulation on Wokwi: [Wokwi Simulation](https://wokwi.com/projects/376921405150878721).
