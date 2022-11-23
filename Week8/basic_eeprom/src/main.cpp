#include <Arduino.h>
#include <EEPROM.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  // check if eeprom is empty
  if (EEPROM.read(0) == 0)
  {
    // if empty, write 1 to eeprom
    EEPROM.write(0, 1);
    Serial.println("Eeprom successfully written");
  }
  else
  {
    // if not empty, read eeprom
    int value = EEPROM.read(0);
    Serial.println(value);
  }
}

void loop()
{
  if (digitalRead(2) == LOW)
  {
    // clear eeprom
    EEPROM.write(0, 0);
    Serial.println("Eeprom successfully cleared");
    delay(200); // prevnt button bounce
  }

  if (digitalRead(3) == LOW)
  {
    // clear eeprom
    EEPROM.update(0, 11);
    Serial.println("Eeprom successfully updated");
    delay(20); // prevnt button bounce
    // read current eeprom value
    int value = EEPROM.read(0);
    Serial.println("Current eeprom value is " + String(value));
    delay(200); // prevnt button bounce
  }
}