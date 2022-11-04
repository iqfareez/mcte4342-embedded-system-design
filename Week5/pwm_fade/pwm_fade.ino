/*
 * Fade LED using PWM signal
 */

const int LED_PIN = 6;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  // empty
}

void loop() {
  analogWrite(LED_PIN, brightness);

  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 190) {
    fadeAmount = -fadeAmount;
  }
  // wait to see the dimming effect
  delay(30);
}
