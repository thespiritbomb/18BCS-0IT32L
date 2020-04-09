int tempPin=A0;
int ledPin=13;
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
int temp=0;
int prevTemp;
int mins=0;
int readings=0;
int lastTotalTemp=0;
int avgTotalTemp=0;
void loop()
{
  prevTemp=temp;
  temp=analogRead(tempPin);
  temp=temp*0.488;
  lastTotalTemp+=temp;
  readings+=1;
  if(mins==10000){
    Serial.println("Time elapsed > 10 seconds");
    avgTotalTemp=0.15*(lastTotalTemp/readings);
    int lastTwoAvg=(prevTemp+temp)/2;
    Serial.print("Average of last two temp: ");
    Serial.println(lastTwoAvg);
    Serial.print("15% of Average of Total Temp: ");
    Serial.println(avgTotalTemp);
    if(lastTwoAvg>avgTotalTemp){
      digitalWrite(ledPin,HIGH);
      delay(4000);
      digitalWrite(ledPin,LOW);
    }
    lastTotalTemp=0;
    readings=0;
    mins=0;
  }
  Serial.print("Total temperature: ");
  Serial.println(lastTotalTemp);
  Serial.print("No. of readings: ");
  Serial.println(readings);
  Serial.print("Time elapsed: ");
  Serial.println(mins);
  delay(1000);
  mins=mins+1000;
}
