# Non-volatile memory

## Notes

## Activities

### Basic write and get EEPROM

In this activity, I made a basic script to test the write, read and update the EEPROM value.

If the memoery in address `0` is empty, it will write value `1`. Press button 2 to reset/clear the eeprom. Press button 3 to write value `11` to the eeprom. This 
value can be verified by resetting the microcontroller (the `setup()` will run)

#### Example output (Serial monitor)
```
1
Eeprom successfully cleared
Eeprom successfully written
Eeprom successfully cleared
Eeprom successfully written
1
Eeprom successfully updated
Current eeprom value is 11
11
```

[Code](https://github.com/iqfareez/mcte4342-embedded-system-design/blob/main/Week8/basic_eeprom/src/main.cpp)

### Rembering counter state

The counter value will be inremented for every button presses. The value is stored in 
EEPROM so the counter state can be recover when a power loss occured.

The video below is the demo of the program. The counter value is displayed on the 7-Segment LED.

#### Code

[Here.](https://github.com/iqfareez/mcte4342-embedded-system-design/blob/main/Week8/write_get_memory/src/main.cpp)

I'm using PlatformIO for development. To open it via the Arduino IDE, change the extension of the file to `.ino` (e.g., `main.cpp` --> `main.ino`)

#### Circuit diagram
![7 segment eeprom_bb](https://user-images.githubusercontent.com/60868965/203562125-66dec166-2338-4a8c-85c8-51fe295e7266.png)

![IMG_20221123_191147](https://user-images.githubusercontent.com/60868965/203562178-9a94e1e1-055f-469a-9ef0-e38287b9d5cb.jpg)

#### Demo

https://user-images.githubusercontent.com/60868965/203562215-40517516-3b2c-486b-b9cf-19423014fe79.mp4


