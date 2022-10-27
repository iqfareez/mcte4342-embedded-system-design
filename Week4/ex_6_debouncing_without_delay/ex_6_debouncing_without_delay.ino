/*
Debouncing without delay bool waiting;
*/
unsigned int count;
bool previous;
bool waiting;
unsigned long pressed_time;
unsigned char *B_reader = (unsigned char *)0x23;  //Points to PINB

void setup() {
  Serial.begin(9600);
}

void loop()  //To run on Arduino, just change this function to void setup()
{
  //Code to perform other functions (such as LED blinking) can be inserted here
  if (waiting) {
    if (millis() - pressed_time >= 20)  //20ms is the debounce period. (If the debounce period has elapsed)
    {
      waiting = 0;
      bool current = (((*B_reader) & 0b00010000) != 0);  //current = HIGH if input PB4 is HIGH
      if (current)                                       //If PB4 is still HIGH, it means it is a real LOW to HIGH transition
      {
        count++;
        Serial.println(count);
      }
      previous = current;
    }
  } else {
    bool current = (((*B_reader) & 0b00010000) != 0);  //current = HIGH if input PB4 is HIGH
    if (current && !previous)                          //If the PB4 is currently HIGH and previously LOW (LOW to High transition)
    {
      pressed_time = millis();  //Take note of the time and then start waiting
      waiting = 1;
    }
    previous = current;
  }
}