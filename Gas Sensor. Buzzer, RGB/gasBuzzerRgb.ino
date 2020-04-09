int G=2;
int R=4;
int B=3;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorInput=analogRead(A0);
  Serial.println(sensorInput);
  if(sensorInput>250){
    analogWrite(R,255);
    analogWrite(G,0);
    analogWrite(B,0);
    tone(13,1000,2000);
    delay(2000);
    analogWrite(R,0);
    analogWrite(G,0);
    analogWrite(B,0);
  }
  else{
    analogWrite(R,0);
    analogWrite(G,255);
    analogWrite(B,0);
    delay(2000);
    analogWrite(R,0);
    analogWrite(G,0);
    analogWrite(B,0);
  }
  delay(2000);
}
