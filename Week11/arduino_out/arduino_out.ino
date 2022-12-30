void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  delay(100);
}
