# Serial communication

## Microcontroller :left_right_arrow: microcontroller

Since interfacing Arduino to Arduino is too mainstream, I'm going to go with Raspberry Pi Pico and Microbit.

### Raspberry Pi Pico to microbit

I had trouble getting it to work here.

#### Circuit diagram

<!-- letak circuit diagram -->

#### Code

##### For Pico

<!-- letak code link -->

##### For microbit

<!-- letak screenshot -->

#### Result :x:

I tried to check what are the data received on microbit from Pico. No useful data can be found.

<!-- letak video -->

In my opinion, the CircuitPython API for [writing](https://docs.circuitpython.org/en/latest/shared-bindings/busio/#busio.UART.write) to Serial is quite hard to use. The [documentation](https://learn.adafruit.com/circuitpython-essentials/circuitpython-uart-serial) also lacks examples especially about sending data over the serial port.

So, I've replaced it with Arduino as follows:

### Arduino to microbit

#### Circuit diagram

#### Code

##### For Arduino

##### For microbit

#### Result :white_check_mark:

## Microcontroller :left_right_arrow: X

_X = Other devices_

### Windows laptop

I've made a controller using Arduino and an analog joystick to control a game in Unity over Bluetooth (still a Serial connection).

Details in [this repo](https://github.com/iqfareez/Unity-Bluetooth-Arduino)

### Android smartphone

Control the water pump using Arduino and the Android app over Bluetooth. Also, can read the current soil humidity using the app.

Details in [this repo](https://github.com/iqfareez/soil_humidity)

### 3D printer
