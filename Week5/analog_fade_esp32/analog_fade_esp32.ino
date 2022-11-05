/*
 * Fade LED using analog signal
 * Utilizes build in DAC
 * 
 * ESP32 has two 8-bit DAC (digital to analog converter) 
 * channels, connected to GPIO25 (Channel 1) and GPIO26 
 * (Channel 2). The DAC driver allows these channels to 
 * be set to arbitrary voltages.
 * 
 * Change board: Tools > Board > ESP32 > DOIT ESP32 DEVKIT V1
 */

const int LED_PIN = 25; // DAC1
int fadeAmount = 5;
int brightness = 0;

void setup() {
  // empty
}

void loop() {
  dacWrite(LED_PIN, brightness);  

  brightness = brightness + fadeAmount;

  // DAC 8 bit. 2^8 = 256 resolution
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait to see the dimming effect
  delay(30);
}
