int relay=12;
int echo=7;
int trig=6;
void setup()
{
  pinMode(relay, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);
}
int duration;
void loop()
{
  duration=pulseIn(echo,HIGH);
  int distance=duration*0.034/2;
  Serial.println(distance);
    if(distance>5){
    digitalWrite(relay,HIGH);
    delay(2000);
    digitalWrite(relay,LOW);
  }
}
