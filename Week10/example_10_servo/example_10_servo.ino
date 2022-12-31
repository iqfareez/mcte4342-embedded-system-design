/*
   Servo attached at PB0. Make the servo go back and forth with the
   following paramaters:

   Minimum pulse width: 544us
   Maximum pulse width: 2400us
   Step size: 10us
   Delay: 25ms

   Slide Week 10 page 41

*/

// Slide Week 10 page 9
class Blinky
{
  private:
    unsigned long OnTime; //The ON duration in μs
    unsigned long OffTime; //The OFF duration in μs
    unsigned long last_time = 0; //The last time a transition occurred
    char mask; //If pin = 3, mask = 0000 1000
    char mask_inv; //If pin = 3, mask_inv= 1111 0111
    char* DDR;
    char* PORT;
  public:
    Blinky() //Constructor without arguments
    {
      Initialize('B', 5, 1000000, 1000000);
    }
    Blinky(char port, int pin, long ontime, long offtime) //Constructor with arguments
    {
      Initialize(port, pin, ontime, offtime);
    }

    void Initialize(char port, int pin, long ontime, long offtime)
    {
      OnTime = ontime;
      OffTime = offtime;
      switch (port)
      {
        case 'B':
          DDR = (char*) 0x24;
          PORT = (char*) 0x25;
          break;
        case 'C':
          DDR = (char*) 0x27;
          PORT = (char*) 0x28;
          break;
        case 'D':
          DDR = (char*) 0x2A;
          PORT = (char*) 0x2B;
          break;
      }
      mask = (1 << pin); //The expression (1 << pin) will be used often, it is faster to store it
      mask_inv = ~mask; //The inverse of the expression (1 << pin) will also be used often
      *DDR |= mask; //Set the pin as output pin
    }
    void ChangeOnOffTimes(long ontime, long offtime)
    {
      OnTime = ontime;
      OffTime = offtime;
    }

    //The refresh function needs to be constantly called. It performs respective transitions.
    void Refresh()
    {
      unsigned long now = micros();
      if (*PORT & mask) //The pin is currently HIGH
      {
        if (now - last_time >= OnTime) //If the pin has been HIGH for long enough
        {
          if (OffTime > 0) //If OffTime is 0, no need to even turn it OFF
          {
            *PORT &= mask_inv; //Make the pin LOW
          }
          last_time = now; //Take note of the time
        }
      }
      else //The pin is currently LOW
      {
        if (now - last_time >= OffTime) //If the pin has been LOW for long enough
        {
          if (OnTime > 0) //If OnTime is 0, no need to even turn it ON
          {
            *PORT |= mask; //Make the pin HIGH
          }
          last_time = now; //Take note of the time
        }
      }
    }
};

// Slide Week 10 page 38
class Servo
{
  private:
    Blinky oscillator;
    int Period;
  public:
    Servo()
    {
      Initialize('B', 5, 20000);
    }
    Servo(char port, int pin, int period)
    {
      Initialize(port, pin, period);
    }
    void Initialize(char port, int pin, int period)
    {
      Period = period;
      oscillator.Initialize(port, pin, 0, period);
    }
    void Write(int ontime)
    {
      oscillator.ChangeOnOffTimes(ontime, Period - ontime);
    }
    void Refresh()
    {
      oscillator.Refresh();
    }
};

unsigned long last_time;
int Min = 544;
int Max = 2400;
int Step = 10;
int Delay_ms = 25;
int Current = Min;

Servo servo('B', 0, 20000);

void setup() {
  // empty
}

void loop() {
  unsigned long now = millis();

  if (now - last_time >= Delay_ms) {
    last_time = now;
    Current += Step;
    servo.Write(Current);
    if (Current >= Max || Current <= Min) {
      Step = -Step;
    }
  }
  servo.Refresh();
}
