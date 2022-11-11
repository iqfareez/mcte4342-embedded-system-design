# Week 5 - Analog Input

## Notes

[![analog_embedded](https://user-images.githubusercontent.com/60868965/201250675-c3a9a927-97e8-4e92-a0b4-788906fb8214.png)](https://excalidraw.com/?#json=I2tZeD7kwnyZZRillXt4K,RiZxuo7eHJYgWIH0ND4Muw)

## Exercises

### Fading LED

#### Arduino

https://user-images.githubusercontent.com/60868965/200447664-5b18d079-7f57-4015-918c-940c0c1ebabb.mp4

Uses [PWM](https://www.analogictips.com/pulse-width-modulation-pwm/) (Fake analog as this chip does not have DAC)

If we use `analogWrite` on analog pins, we got an unexpected outcome.

https://user-images.githubusercontent.com/60868965/200448645-04babb22-936e-4282-b262-51cf392fe739.mp4

(The LED appreared to be blinking where it supposed to fade)

#### ESP32

ESP32 chip has two channel, 8-bit DAC built in. Hence, we can generate a true analog signal with it.

https://user-images.githubusercontent.com/60868965/200448160-957262e2-3774-4b4e-b7d0-eab0b48d1aad.mp4

### Piano

https://user-images.githubusercontent.com/60868965/200448215-86c2d99a-02c7-4752-84af-52c8536b9e33.mp4

*Note: I'm using the on-board piezo pasize buzzer on [Maker Uno](https://my.cytron.io/p-maker-uno-simplifying-arduino-for-education?ref=99Y7TxrNIn6Jo)*

### Potentiometer

Using [Raspberry Pi Pico](https://my.cytron.io/p-raspberry-pi-pico-board?ref=99Y7TxrNIn6Jo) microcontroller, using [MicroPython](https://micropython.org/). The DAC bit can be up to 16 bit!



https://user-images.githubusercontent.com/60868965/200448862-ab174f5f-b03b-4406-90f7-367551bbed93.mp4



### Example 2

Reading analog value using Uno



https://user-images.githubusercontent.com/60868965/200448540-b4152bc4-09e3-4d30-860a-7df67a2fac20.mp4

