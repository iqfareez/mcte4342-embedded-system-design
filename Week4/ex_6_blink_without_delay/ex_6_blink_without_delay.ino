unsigned long previousTime;
unsigned char *D_dir = (unsigned char *)0x2a;     //Points to DDRD
unsigned char *D_writer = (unsigned char *)0x2b;  //Points to PORTD

void setup() {
  *D_dir = 0b00000100; // make PD2 as output
}

void loop() {
  unsigned long currentTime = millis();
  if (((*D_writer) & 0b00000100) == 0)  //If the LED is currently OFF
  {
    if (currentTime - previousTime >= 2000)  //2000 is OFF duration
    {
      *D_writer |= 0b00000100;     //Turn ON the LED (pin PD2)
      previousTime = currentTime;  //Take note of the time
    }
  } else  //LED is currently ON
  {
    if (currentTime - previousTime >= 2000)  //2000 is ON duration
    {
      *D_writer &= 0b11111011;     //Turn OFF the LED (pin PD2)
      previousTime = currentTime;  //Take note of the time
    }
  }
}