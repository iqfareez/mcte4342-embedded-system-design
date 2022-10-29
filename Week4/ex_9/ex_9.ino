/*
There are two LEDs whose anodes are connected to PD5 and PD6 respectively. The LED 1
needs to be flashing with ON time 750 ms and OFF time 350 ms. The LED 2 needs to be
flashing with ON time 400 and OFF time 600 ms
*/


/**
 * Blink LED with given port and pin with certain
 * amount of on duration and off duration
 * 
 * Supported port: B, C, D
 * Supported pin: 1-7
 *
 */
class LedBlinky {
  char port;
  int pin;
  int pinBin;
  int onDurationMs;
  int offDurationMs;
  unsigned char *writer;  // Port data register
  unsigned long previousMillis;


public:
  LedBlinky(char port, int pin, int onDur, int offDur) {
    port = port;
    pin = pin;
    onDurationMs = onDur;
    offDurationMs = offDur;

    previousMillis = 0;

    // hardcode the binary representation for now
    switch (pin) {
      case 0: pinBin = 0b00000001; break;
      case 1: pinBin = 0b00000010; break;
      case 2: pinBin = 0b00000100; break;
      case 3: pinBin = 0b00001000; break;
      case 4: pinBin = 0b00010000; break;
      case 5: pinBin = 0b00100000; break;
      case 6: pinBin = 0b01000000; break;
      case 7: pinBin = 0b10000000; break;
    }

    switch (port) {
      case 'B': writer = (unsigned char *)0x25; break;
      case 'C': writer = (unsigned char *)0x28; break;
      case 'D': writer = (unsigned char *)0x2b; break;
    }
  }
  void Run() {
    unsigned long currentTime = millis();

    if (((*writer) & pinBin) == 0)  //If the LED is currently OFF
    {
      if (currentTime - previousMillis >= offDurationMs)  // OFF duration
      {
        *writer |= pinBin;  // Turn ON LED
        previousMillis = currentTime;
      }
    } else  //LED is currently ON
    {
      if (currentTime - previousMillis >= onDurationMs)  // ON duration
      {
        // Bitwise, if pinBin is 0b00001000, then ~pinBin is 0b11110111
        *writer &= ~pinBin;  // Turn OFF Led.
        previousMillis = currentTime;
      }
    }
  }
};

LedBlinky leds[] = {
  LedBlinky('D', 2, 781, 515),
  LedBlinky('D', 3, 2014, 1348),
  LedBlinky('D', 4, 343, 573),
  LedBlinky('D', 5, 678, 1389),
  LedBlinky('D', 6, 342, 534),
  LedBlinky('D', 7, 1478, 326),
  LedBlinky('B', 0, 1859, 351),
  LedBlinky('B', 1, 777, 888),
};

int numOfLeds = sizeof(leds)/sizeof(int);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  for (int i = 0; i < numOfLeds; i++) {
    leds[i].Run();
  }
}