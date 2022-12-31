const int IN_1 = 6;
const int IN_2 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
}

void counter_clockwise() {
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
}

void clockwise() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
}


void stop() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
}

void loop() {
  counter_clockwise();
  delay(2000);

  clockwise();
  delay(1000);

  stop();
  delay(1000);
}
