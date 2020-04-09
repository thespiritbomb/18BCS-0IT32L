int echo=7, trig=6, buzzer=13, led=10;
void setup()
{
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
int duration;
void loop()
{
  digitalWrite(trig,LOW);
  delay(500);
  digitalWrite(trig,HIGH);
  delay(500);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  int distance=duration*0.034/2;
  int distanceInFeet=distance*0.0328;
  Serial.println(distanceInFeet);
    if(distanceInFeet<3){
    Serial.println("ALERT!!");
    digitalWrite(led,HIGH);
    tone(13,800,2000);
    delay(2000);
    digitalWrite(led,LOW);
  }
  delay(3000);
}
