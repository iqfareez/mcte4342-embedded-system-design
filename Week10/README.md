# Motors

## Notes

|                                                                                                                              |                                                                                                                                 |
| ---------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| ![Motor Introduction](https://user-images.githubusercontent.com/60868965/208287824-1139f4f4-6a95-4a94-8380-87f1169197ad.png) | ![Motor - DC Motor](https://user-images.githubusercontent.com/60868965/208287867-61fbdd62-1b95-4b98-a485-e25f676a612f.png)      |
| ![Motor - Servo](https://user-images.githubusercontent.com/60868965/208287886-38b7dc94-38fb-4e0d-b30a-6881530017ac.png)      | ![Motor - Stepper motor](https://user-images.githubusercontent.com/60868965/208287897-c068a4ea-237c-4e84-aef9-c3875bc77eb9.png) |

[[Excalidraw link]](https://excalidraw.com/#json=wm4Y0oTpcoa_cIgU9xSAM,t9QZ_YXj_MQE-WBmD-lOOg) <sub>_Copyright 2022 Muhammad Fareez. All rights reserved_<sub>

## Controlling Servo

Servo can be controlled via PWM

- Servo used: [SG90 Micro Servo](https://my.cytron.io/c-motor-and-motor-driver/c-dc-motor/c-servo-motor/p-sg90-micro-servo?ref=99Y7TxrNIn6Jo)

https://user-images.githubusercontent.com/60868965/210133641-ac691a1b-1d1e-45f7-b61e-906344516405.mp4

## Controlling DC motor

A DC motor can be controlled via Motor Driver.

- DC motor: [3V - 6V Dual Axis TT Gear Motor](https://my.cytron.io/p-3v-6v-dual-axis-tt-gear-motor?ref=99Y7TxrNIn6Jo) (technically you can also use DC motor from RC Car etc.)
- Motor Driver: [Amp 7V-30V L298N Motor Driver / Stepper Driver](https://my.cytron.io/p-2amp-7v-30v-l298n-motor-driver-stepper-driver-2-channels?ref=99Y7TxrNIn6Jo)

Note: I'm using a **12V** power supply, connected to the L298N. Remember to common ground the driver to the Arduino.

### Controlling the direction

https://user-images.githubusercontent.com/60868965/210133626-aab5faf4-08e3-493d-a848-324b7329d442.mp4

### Controlling the speed

The video below is in slow-motion to better see the speed differences.

https://user-images.githubusercontent.com/60868965/210133613-cd5dbe8e-7f04-44d8-bf4a-955608460aec.mp4
