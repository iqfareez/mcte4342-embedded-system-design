/*
 * Fading LED using Analog pins on Arduino UNO
 * Spoiler: This won't work as this mcu doesn't have DAC
 */

const int LED_PIN = A0;

int brightness = 0;
int fadeAmount = 10;

void setup() {
  // empty
}

void loop() {
  analogWrite(A0, brightness);

  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 1024) {
    fadeAmount = -fadeAmount;
  }
  // wait to see the dimming effect
  delay(30);
}
