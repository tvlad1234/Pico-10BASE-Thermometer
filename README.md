# Pico-10BASE-Thermometer
Thermometer which outputs data over 10BASE-T Ethernet 

This project is meant as an example for [Pico-10BASE-T-Library](https://github.com/tvlad1234/Pico-10BASE-T-Library)\
It uses a BMP085 or BMP180 sensor to measure temperature and humidity and trasmit the data over Ethernet. This data can be received and displayed by another computer using _netcat_.

## Hardware
The sensor is connected via I2C, SDA on GPIO0 and SCL on GPIO1. The Ethernet is wired just like in the example from [Pico-10BASE-T](https://github.com/kingyoPiyo/Pico-10BASE-T).

## Software
Replace the IP addresses in [main.c](main.c) with ones coresponding to your configuration. The board will send data to port 1234 of the destination computer which can be received with netcat on Linux, by listening to UDP connections on port 1234, like so: \
`nc -u -l 0.0.0.0 1234 -v`

