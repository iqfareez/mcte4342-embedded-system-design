#include <Arduino.h>
#include <SevSeg.h>
#include <EEPROM.h>

SevSeg sevseg; // Instantiate a seven segment controller object

unsigned long previousMillis = 0; // will store last time LED was updated

// constants won't change:
const long interval = 1000; // interval at which to blink (milliseconds)

const int buttonPin = 3;   // the number of the pushbutton pin
int buttonState;           // the current reading from the input pin
int lastButtonState = LOW; // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers

/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
int address = 0;

int counter;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);

  // reset the eeprom at address
  // EEPROM.write(address, 0);

  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12};
  bool resistorsOnSegments = true;    // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false;      // Default 'false' is Recommended
  bool leadingZeros = false;          // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true;        // Use 'true' if your decimal point doesn't exist or isn't connected

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(60);
  // sevseg.setNumber(7);
  // sevseg.refreshDisplay();

  // set counter from eeprom
  counter = EEPROM.read(address);
}


void loop()
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState)
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState)
    {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH)
      {
        counter++;
        if (counter > 9)
          counter = 0;
        Serial.println(counter);
        EEPROM.update(address, counter);
      }
    }
  }

  // set the LED:
  sevseg.setNumber(counter);
  sevseg.refreshDisplay();

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}