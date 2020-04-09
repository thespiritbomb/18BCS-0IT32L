int pir=2, buzzer=13, tmp=A0;
void setup()
{
  pinMode(pir,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}
float temp=0,ftemp=0;
int people=0;
void loop()
{
  if(digitalRead(pir)==HIGH){
    people++;
    Serial.print(people);
    temp=analogRead(tmp);
  	temp=temp*0.488;
    ftemp=(temp*9/5)+32;
    if(ftemp>98){
      Serial.print("ALERT!");
      Serial.print(ftemp);
      tone(13,800,500);
    }
  }
  delay(2000);
}
