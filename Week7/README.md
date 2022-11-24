# Interrupts

## Notes

![Interrupt](https://user-images.githubusercontent.com/60868965/203674889-cd57ad2d-b5ae-472d-b94c-19ca2b78a240.png)
![Interrupt (2)](https://user-images.githubusercontent.com/60868965/203674896-c9b17b63-aa20-4512-b643-e9a25781fda9.png)

[Excalidraw's link](https://excalidraw.com/#json=KN8NDZF8FKmMH3xqWUf4l,mtXavF0HhEw6u1svydAVcA)

## Activities

### 1) Extenal Interrupt

Turn LED on/off via button

[Code](https://github.com/iqfareez/mcte4342-embedded-system-design/blob/main/Week7/external-interrupt/src/main.cpp)

#### Circuit

![IMG_20221121_183653](https://user-images.githubusercontent.com/60868965/203564758-e4e22847-5f7a-4653-861c-334e9f58d705.jpg)

![external-interrupt_bb](https://user-images.githubusercontent.com/60868965/203564793-89480197-cdd1-4ff0-83b8-3a28a7979544.png)

### 2) Motor RPM using [encoder sensor module](https://my.cytron.io/p-encoder-sensor-module-digital-output?ref=99Y7TxrNIn6Jo) 

![image](https://user-images.githubusercontent.com/60868965/203565023-bd55e807-80ce-4bed-a11e-7a80270d79f6.png)

> This Encoder Sensor Module Digital Output can use to check the rate of an electric motor. This module can be used with a microcontroller for motor speed detection, pulse count and position limit. In principle, any rate meter simply measures the rate at which some event occurs. Usually, this is done by counting the events for a given period of time (integration interval) and then simply dividing the number of events by the time to get the rate.

**Note** I don't have the require wheel (like [this one](https://www.teknatool.com/wp-content/uploads/2020/10/46061_Wheel_01.jpg) to actually count the RPM. I've replaced it with a slotted rectangle instead. The concept remains the same ie if you move the thing faster, the measured rate increases.

To interface with the encoder, we can use polling or interrupt. Both are possible. However, the former may have risks of missing signal if the rate is very fast. 

https://user-images.githubusercontent.com/60868965/203591441-b46ffbd4-f7d5-4bad-9f3c-9fbb27a033f0.mp4
