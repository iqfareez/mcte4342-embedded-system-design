#define UPDATE_TIME 20

int servoPin = 11;
void setup() {
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 180; i++) {
    analogWrite(servoPin, angleToPWM(i));
    delay(UPDATE_TIME);
  }
  delay(200);

  for (int i = 180; i >= 0; i--) {
    analogWrite(servoPin, angleToPWM(i));
    delay(UPDATE_TIME);
  }
  delay(200);
}

int angleToPWM(int ang) {
  float a = 255.0 / 180.0;
  return (a * ang);
}
