# Non-volatile memory

## Internal memory

### Basic write and get EEPROM

In this activity, I made a basic script to test the write, read and update the EEPROM value.

If the memory in address `0` is empty, it will write value `1`. Press button 2 to reset/clear the eeprom. Press button 3 to write value `11` to the eeprom. This
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

### Remembering counter state

The counter value will be incremented for every button press. The value is stored in
EEPROM so the counter state can be recovered when a power loss occurs.

The video below is the demo of the program. The counter value is displayed on the 7-Segment LED.

#### Code

[Here.](https://github.com/iqfareez/mcte4342-embedded-system-design/blob/main/Week8/write_get_memory/src/main.cpp)

I'm using PlatformIO for development. To open it via the Arduino IDE, change the extension of the file to `.ino` (e.g., `main.cpp` --> `main.ino`)

#### Circuit diagram

![7 segment eeprom_bb](https://user-images.githubusercontent.com/60868965/203562125-66dec166-2338-4a8c-85c8-51fe295e7266.png)

![IMG_20221123_191147](https://user-images.githubusercontent.com/60868965/203562178-9a94e1e1-055f-469a-9ef0-e38287b9d5cb.jpg)

#### Demo

https://user-images.githubusercontent.com/60868965/203562215-40517516-3b2c-486b-b9cf-19423014fe79.mp4

## External memory

### CardInfo

This program will read the card information and display it on the serial monitor.

This program is available in the IDE. To open it, go to `File` --> `Examples` --> `SD` --> `CardInfo`

#### Circuit diagram

![image](https://user-images.githubusercontent.com/60868965/209552589-21b73b67-85ae-41e6-a973-a50653c2ed7c.png)

| Arduino Uno | SD Card Module |
| ----------- | -------------- |
| 5V          | VCC            |
| GND         | GND            |
| 8           | CS             |
| 11          | MOSI           |
| 12          | MISO           |
| 13          | SCK            |

#### Serial monitor output

```
Initializing SD card...Wiring is correct and a card is present.

Card type:         SDHC
Clusters:          121664
Blocks x Cluster:  64
Total Blocks:      7786496

Volume type is:    FAT32
Volume size (Kb):  3893248
Volume size (Mb):  3802
Volume size (Gb):  3.71

Files found on the card (name, date and size in bytes):
SYSTEM~1/     2021-04-17 14:19:00
  WPSETT~1.DAT  2021-04-17 14:19:00 12
  INDEXE~1      2021-04-17 14:19:02 76
HORNET~1/     2021-04-17 10:18:06
  ENDG-C~1.TXT  2020-09-27 15:28:12 114
  HORNET~1.CUR  2020-09-22 17:18:18 3311
  HORNET~2.CUR  2020-09-22 17:18:30 3315
  **output truncated for clarity**
```

### Save your name

Enter some string in the Serial Monitor and it will be saved in the SD card.

https://user-images.githubusercontent.com/60868965/209552746-531c9267-430c-47b2-8b87-5001b2025aad.mp4

Then, open the file using a computer and this is the written names:

![Screenshot_20221225_072148](https://user-images.githubusercontent.com/60868965/209552690-4a1bc708-78fb-4a8d-847f-bd43b489491f.png)

#### Code

[Here](https://github.com/iqfareez/mcte4342-embedded-system-design/blob/main/Week8/name_saver/name_saver.ino)

### Datalogger

#### Circuit diagram

![image](https://user-images.githubusercontent.com/60868965/209552568-d11da229-4201-4b1a-babd-54916a2357e1.png)

SD Card circuit same as above, just with a few addition:

| Arduino Uno | Servo |
| ----------- | ----- |
| 5V          | VCC   |
| GND         | GND   |
| 3           | SIG   |

| Arduino Uno | Potentiometer |
| ----------- | ------------- |
| A0          | CENTER        |
| 5V          | VCC           |
| GND         | GND           |

This program will store the servo angle in the SD card.

Sometimes it shows the write is failed. I'm not sure why. I suspect that the Servo was pulling too much current, but that seems not to be the problem since the issues persist even after I disconnect the power to the servo.

The saved data looks like this:

```txt
84
84
94
46
55
95
44
95
52
45
87
51
84
89
75
92
93
51
```

#### Code

[Here](https://github.com/iqfareez/mcte4342-embedded-system-design/blob/main/Week8/datalogger-servo/datalogger-servo.ino)

# Caution

If the SDCard is removed while Arduino is writing data to it, there is a chance that the data will be corrupted (which happened to me). Make sure the SD card is closed before taking it out, or uploading a new sketch, or unplugging the power.

If corrupted, you can Format it. Sometimes, you need to disable the Quick Format option.
