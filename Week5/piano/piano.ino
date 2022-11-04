#include "pitches.h"
#define BUZZER_PIN 8

class PianoKey {
    int myPin; // button pin
    int myNote;

  public:
    PianoKey(int pin, int note) {
      myPin = pin;
      myNote = note;

      pinMode(pin, INPUT_PULLUP);
    }

    void playTone() {
      tone(BUZZER_PIN, myNote);
    }

    int buttonPin() {
      return myPin; // return buttonpin
    }
};

PianoKey keys[] =
{
  PianoKey(2, NOTE_GS2),
  PianoKey(3, NOTE_GS3),
  PianoKey(4, NOTE_F4),
  PianoKey(5, NOTE_AS4),
  PianoKey(6, NOTE_D8)
};

const byte numOfBtns = sizeof keys / sizeof * keys;

void setup() {
}

void loop() {

  for (int i = 0; i < numOfBtns; i++) {
    int res = digitalRead(keys[i].buttonPin());

    if (res == LOW) {
      keys[i].playTone();
      delay(500);
    } else {
      noTone(BUZZER_PIN);
    }
  }
}
