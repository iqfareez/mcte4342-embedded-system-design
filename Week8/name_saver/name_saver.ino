/*
  Enter name in Serial Monitor.
  The name will be saved (or appended in the SD Card)
*/

#include <SPI.h>
#include <SD.h>

const int chipSelect = 8;

void setup() {
  Serial.begin(9600);

  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
}

void saveToSd(String name) {
  File myFile = SD.open("names.txt", FILE_WRITE);
  if (myFile) {
    Serial.print("Writing to names.txt...");
    myFile.println(name);
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop(void) {
  if (Serial.available() > 0)  {
    String myName = Serial.readString();
    saveToSd(myName);
  }
}
