# Week 6 - Timer

## Notes

TODO

## Activities

### Software PWM

PWM is available on PORT that has Timer. In Uno, it is pins 3, 5, 6, 9, 10, 11. But, we can also turn any pins to PWM. We can emulate the PWM signal by turning ON (HIGH) & OFF (LOW) real quick. In this activity, I used Software PWM to control the brightness of the LED.

### Servo PWM

Most of the time, we used [Servo](https://www.arduino.cc/reference/en/libraries/servo/) library to interact with Servo. We just supply the angle
and the Servo moves to the position. But, what 'message' exactly did Arduino send to the Servo so that it moved?

Turns out, the servo can be controlled via a PWM signal.
