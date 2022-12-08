# Week 6 - Timer

## Notes

TODO

## Activities

### Software PWM

PWM is available on PORT that has Timer. In Uno, it is pins 3, 5, 6, 9, 10, 11. But, we can also turn any pins to PWM. We can emulate the PWM signal by turning ON (HIGH) & OFF (LOW) real quick. In this activity, I used Software PWM to control the brightness of the LED.

![image](https://user-images.githubusercontent.com/60868965/201619942-a0792f22-3a14-485a-8a72-9eae9d6793e2.png)

The PWM is 10%, so the LED is dimmed

### Servo PWM

Most of the time, we used [Servo](https://www.arduino.cc/reference/en/libraries/servo/) library to interact with Servo. We just supply the angle
and the Servo moves to the position. But, what 'message' exactly did Arduino send to the Servo so that it moved?

Turns out, the servo can be controlled via a PWM signal.

https://user-images.githubusercontent.com/60868965/201619291-494618c9-e231-431d-b371-0ea7f92136bf.mp4

_not really sure how does he goes 360 there :shrug:_
