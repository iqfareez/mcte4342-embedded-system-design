void setup()
{
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

  // RGB led go blue, then green, then red
  analogWrite(9, 200);
  analogWrite(10, 0);
  analogWrite(11, 0);
  delay(1000);
  
  analogWrite(9, 0);
  analogWrite(10, 200);
  analogWrite(11, 0);
  delay(1000);
  
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 200);
  delay(1000);
}
