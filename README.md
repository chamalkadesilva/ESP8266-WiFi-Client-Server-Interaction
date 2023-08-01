# ESP8266-WiFi-Client-Server-Interaction
This repository contains code for setting up an ESP8266 microcontroller as a client and a server using WiFi connectivity. The client sends HTTP POST requests to the server with the message "Message" every second.

**Getting Started**
These instructions will help you get a copy of the project up and running on your local machine for development and testing purposes.

**Prerequisites**
You will need the Arduino IDE installed on your local machine. Also, make sure to install the ESP8266 board in your Arduino IDE from the Board Manager. The necessary libraries (ESP8266WiFi.h and ESP8266HTTPClient.h for the client, ESP8266WiFi.h and ESP8266WebServer.h for the server) are included in the ESP8266 board installation.

**Setup & Installation**
Clone this repository.
Open client.ino and server.ino with your Arduino IDE.
Update ssid and password in both files to match your WiFi network's SSID and password.
Upload the client.ino code to your ESP8266 client device and server.ino to your ESP8266 server device.
Usage
Once both ESP8266 devices are up and running, the client will start sending HTTP POST requests to the server every second. The server will then log the body of the incoming requests to the serial monitor.

**Code Details**
client.ino: This code connects the ESP8266 microcontroller (acting as a client) to a specified WiFi network and sends HTTP POST requests with the message "FIRE DETECTED" to the server every second.

server.ino: This code connects the ESP8266 microcontroller (acting as a server) to a specified WiFi network. It listens for HTTP POST requests on the "/post" endpoint and logs the body of the incoming requests to the serial monitor.

**Contributing**
Contributions are welcome! Please read the contributing guidelines before getting started.

**License**
This project is licensed under the MIT License - see the LICENSE file for details.
