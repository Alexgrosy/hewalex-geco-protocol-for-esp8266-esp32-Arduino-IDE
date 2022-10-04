# hewalex-geco-protocol for esp8266/esp32

Thank you for aelias-eu for the initial Work.
You will need:
- An esp8266/esp32 microcontroller
- A MAX3485 RS485 transceiver

Basically that's all. This very simple code is working fine on a esp8266. You can easily adapt it for esp32. It is tested on the Hewalex PCWU 3.0 kW heatpump with firmware .1o

we'll use the esp8266/esp32 SoftwareSerial Library to communicate with the MAX3485

No WiFi connectivity is shown, just some output to the serial port, but you can also very easily adapt everything for your needs.

The wiring is simple: In case of the esp8266:
- D1    --> MAX3485 Pin 1
- D0    --> MAX3485 Pin 2&3
- D2    --> MAX3485 Pin 4
- GND   --> MAX3485 Pin 5
- 3.3V  --> MAX3485 Pin 8
- Pin6&7 Is the RS485 +/- which connect to the geco controller. Make sure you add a 120 Ohm termination resistor between Pin 6&7 of the MAX3485.

Upload the Code and Enjoy! :)
