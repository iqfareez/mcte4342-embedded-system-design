unsigned char *B_dir = (unsigned char* ) 0x2A;
unsigned char *B_writer = (unsigned char* ) 0x2B;
unsigned char *B_reader = (unsigned char* ) 0x29;

unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

class MyButton {
  public:
    int binPin;
    int lastButtonState = LOW;  // the previous reading from the input pin
    int buttonState;            // the current reading from the input pin
    unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
    int count = 0;
    MyButton(int pin) {

      switch (pin) {
        case 0: binPin = 0b00000001; break;
        case 1: binPin = 0b00000010; break;
        case 2: binPin = 0b00000100; break;
        case 3: binPin = 0b00001000; break;
        case 4: binPin = 0b00010000; break;
        case 5: binPin = 0b00100000; break;
        case 6: binPin = 0b01000000; break;
        case 7: binPin = 0b10000000; break;
      }
    }
};

void setup() {
  *B_dir = 0b00100000;   //or *dir = 32 or *dir = 0x20
  *B_writer = 0b00111000;

  *B_dir = 0b00000000;   //or *dir = 32 or *dir = 0x20
  *B_writer = 0b11111000;
  //  pinMode(3, INPUT_PULLUP);
  //  pinMode(4, INPUT_PULLUP);
  //  pinMode(5, INPUT_PULLUP);
  //  pinMode(6, INPUT_PULLUP);
  //  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);
}

// For now, only port B is supported
MyButton btns[] = {
  MyButton(3), MyButton(4), MyButton(5), MyButton(6), MyButton(7),
};

int numOfBtns = sizeof(btns) / sizeof(int);

void loop() {

  for (int i = 0; i < numOfBtns; i++) {
    int reading = (((*B_reader) & btns[i].binPin) != 0);

    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (reading != btns[i].lastButtonState) {
      // reset the debouncing timer
      btns[i].lastDebounceTime = millis();
    }

    if ((millis() - btns[i].lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:

      //    Serial.println(buttonState);
      // if the button state has changed:
      if (reading != btns[i].buttonState) {
        btns[i].buttonState = reading;
        if (btns[i].buttonState == LOW) btns[i].count += 1;
      }
    }

    // save the reading. Next time through the loop, it'll be the lastButtonState:
    btns[i].lastButtonState = reading;
  }

  char str[80];
  sprintf(str, "Btn A: %d, Btn B: %d, Btn C: %d, Btn D: %d, Btn E: %d", btns[0].count, btns[1].count, btns[2].count, btns[3].count, btns[4].count);
  Serial.println(str);

}
