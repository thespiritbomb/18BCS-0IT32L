void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  int sensorInput=analogRead(A0);
  Serial.println(sensorInput);
  if(sensorInput>300){
    Serial.println("ALERT!!");
    tone(13,1000,2000);
  }
  delay(5000);
}
