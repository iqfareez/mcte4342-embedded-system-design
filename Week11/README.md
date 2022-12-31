# Serial communication

## Microcontroller :left_right_arrow: microcontroller

Since interfacing Arduino to Arduino is too mainstream, I'm going to go with Raspberry Pi Pico and Microbit.

### Raspberry Pi Pico to microbit

I had trouble getting it to work here.

#### Circuit diagram

![pico-microbit_bb](https://user-images.githubusercontent.com/60868965/210035003-83a06d14-5a02-462b-934f-a9f1278fa6d1.png)

#### Code

| Pico                                                                                                     | Microbit                                                                                                                                 |
| -------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| See [code.py](https://github.com/iqfareez/mcte4342-embedded-system-design/blob/main/Week11/pico/code.py) | ![Screenshot MakeCode microbit 1](https://user-images.githubusercontent.com/60868965/210035118-5fd8354e-fdb7-4459-bc55-b92c77a8d07f.png) |

#### Result :x:

I tried to check what are the data received on microbit from Pico. No useful data can be found.

https://user-images.githubusercontent.com/60868965/210035027-d83053f6-daca-4b78-992e-b8db8d87ddda.mp4

In my opinion, the CircuitPython API for [writing](https://docs.circuitpython.org/en/latest/shared-bindings/busio/#busio.UART.write) to Serial is quite hard to use. The [documentation](https://learn.adafruit.com/circuitpython-essentials/circuitpython-uart-serial) also lacks examples especially about sending data over the serial port.

Another thing I discovered that, when added the line

```python
    uart.write(bytearray(value))
    uart.write(bytearray(" \n".encode()))
```

the programs experiences delay/lagging. Perhaps one of the function (either `uart.write` or `bytearray`) is computationally expensive.

So, I've replaced it with Arduino as follows:

### Arduino to microbit

#### Circuit diagram

| Real                                                                                                                            | Fritzing                                                                                                                      |
| ------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| ![fritzing arduino pico](https://user-images.githubusercontent.com/60868965/210032863-39923713-a0db-436c-9b9e-db22325c7acd.jpg) | ![arduino-microbit_bb](https://user-images.githubusercontent.com/60868965/210034974-f1ab210c-2e2a-43f5-9c47-b5ae2978d5bf.png) |

#### Code

| Pico                                                                                                                            | Microbit                                                                                                                                                        |
| ------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| See [arduino_out.ino](https://github.com/iqfareez/mcte4342-embedded-system-design/blob/main/Week11/arduino_out/arduino_out.ino) | ![codeblock](https://user-images.githubusercontent.com/60868965/210035072-f2fdbd42-d6c3-4de2-afbe-d6f805652e70.png) https://makecode.microbit.org/_FPae6FgPLF8x |

#### Result :white_check_mark:

https://user-images.githubusercontent.com/60868965/210032873-d08cb502-11ca-436a-b739-1a417569fed1.mp4

## Microcontroller :left_right_arrow: X

_X = Everything_

### Windows laptop

I've made a controller using Arduino and an analog joystick to control a game in Unity over Bluetooth (still a Serial connection).

Details in [this repo](https://github.com/iqfareez/Unity-Bluetooth-Arduino)

### Android smartphone

Control the water pump using Arduino and the Android app over Bluetooth. Also, can read the current soil humidity using the app.

Details in [this repo](https://github.com/iqfareez/soil_humidity)

### 3D printer

A 3D printer can be controlled by sending a G-CODE command to it.

Simply connect the PC to the 3D printer using a USB cable. I'm using [CoolTerm](https://freeware.the-meiers.org/) as a Serial Monitor interface (similar to the TeraTerm, SSCom etc.)

3D Printer Model: [Artillery Hornet](https://my.cytron.io/p-artillery-hornet-3d-printer-partially-assembled-diy-kit?ref=99Y7TxrNIn6Jo).

#### Demo 1: Home all axes

https://user-images.githubusercontent.com/60868965/210032828-6016a09a-1222-4590-ad64-a0bfc6fc9171.mp4

#### Demo 2: Go to certain coordinate

https://user-images.githubusercontent.com/60868965/210032800-85be377b-e9b8-455a-be52-9ec3bd92fcba.mp4

_Note that command must followed by a newline (pressing Enter)_

Those commands are Marlin gcode flavored. Theoretically, I can also reverse the conversation i.e. the printer is talking to the PC. This can be done using the [`M118`](https://marlinfw.org/docs/gcode/M118.html) command. View all list of commands [here](https://marlinfw.org/meta/gcode/).
