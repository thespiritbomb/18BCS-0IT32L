int led = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0 ; i <= 255; i++) {
    analogWrite(led, i);
    delay(20);
  }
  Serial.println("Max brightness");
  delay(500);
  for (int i = 255 ; i >= 0; i--) {
    analogWrite(led, i);
    delay(20);
  }
  Serial.println("Min brightness");
  delay(500);
}
