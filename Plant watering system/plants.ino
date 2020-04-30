#include <LiquidCrystal.h>
const int tempSensor = A0;
const int motor = 13;
const int LedRed = 9;
const int LedGreen = 10;
LiquidCrystal lcd(12,11, 5, 4, 3,2);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Automated Plant");
  lcd.setCursor(0,1);
  lcd.print("Watering System!");
  pinMode(motor, OUTPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  delay(2000);
  lcd.clear();
  lcd.print("Temp= ");
  lcd.setCursor(0,1);
  lcd.print("WaterPump= ");
}
void loop() {
  int value = analogRead(tempSensor);
  float Temperature = value * 500.0 / 1023.0;
  lcd.setCursor(6,0);
  lcd.print(Temperature); 
  lcd.setCursor(11,1);
    if (Temperature > 35){
    digitalWrite(motor, HIGH);
    digitalWrite(LedRed, HIGH);
    digitalWrite(LedGreen, LOW);
    lcd.print("ON ");
  }
  else {
    digitalWrite(motor, LOW);
    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, HIGH);
    lcd.print("OFF");
  }
  
   delay(1000);
}
