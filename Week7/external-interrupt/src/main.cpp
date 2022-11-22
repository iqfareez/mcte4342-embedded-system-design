#include <Arduino.h>

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void blink(); // function prototype

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop()
{
  digitalWrite(ledPin, state);
}

void blink()
{
  // note that, this debouncing code may have unexpected behavior
  // for interrupt CHANGE and FALLING mode
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 200)
  {
    state = !state;
  }
  last_interrupt_time = interrupt_time;
}