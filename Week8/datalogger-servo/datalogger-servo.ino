/*
  Controlling a servo position using a potentiometer (variable resistor)
  by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

  modified on 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#include <SPI.h>
#include <SD.h>

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

const int chipSelect = 8;

void setup() {
  Serial.begin(9600);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object

  pinMode(2, INPUT_PULLUP);

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value


  File dataFile = SD.open("datalog.txt", FILE_WRITE); // open file
  if (dataFile) {
    dataFile.println(String(val));
    Serial.println(val);
    dataFile.close();
  }
  else {
    Serial.println("error opening datalog.txt");
  }

  delay(15);

  // before unplugging the SDCard/power supply
  // tap button to close the file and prevent any
  // writing to it
  if (digitalRead(2) == LOW) {
    // close the file
    dataFile.close();
    Serial.println("File closed. Safe to eject");
    while (1);

  }
}
