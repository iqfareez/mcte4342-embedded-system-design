//Déclaration des constantes
#define UPDATE_TIME 20
//Déclaration des paramètres
int servoPin = 11;
void setup() {
  // Code d'initialisation
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600); // Initialise la communication série PC/Arduino
}
void loop() {
  // Code principal
  for (int i = 0; i < 180; i++) {
    analogWrite(servoPin, convertirAngleEnPWM(i));
    delay(UPDATE_TIME);
  }
  delay(200);
  for (int i = 180; i >= 0; i--) {
    analogWrite(servoPin, convertirAngleEnPWM(i));
    delay(UPDATE_TIME);
  }
  delay(200);
}
// Déclaration d'un sous fonction
int convertirAngleEnPWM(int ang) {
  float a = 255.0 / 180.0;
  return (a * ang);
}
