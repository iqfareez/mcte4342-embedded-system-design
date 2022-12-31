const int IN_1 = 6;
const int IN_2 = 7;
const int EN_A = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(EN_A, OUTPUT);

  // it will go in one direction only
  // so you can also hard wired it
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
}

void loop() {
  // run motor slow
  analogWrite(EN_A, 40);
  delay(2000);

  // run motor medium speed
  analogWrite(EN_A, 10   0);
  delay(2000);

  // run motor full speed
  analogWrite(EN_A, 255);
  delay(2000);
}
