void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
int i,ledNumber,totLED=8;
int startLED=6;
char ch;
void loop()
{
  ledNumber=0;
  if( Serial.available())
 	{
   ch = Serial.read();
   if(ch >= '0' && ch <= '8')  
     ledNumber = ch - '0';
  }
  i=0;
  startLED=6;
  while(i<ledNumber){
    digitalWrite(startLED,HIGH);
    startLED++;
    i++;
  }
  delay(500);
  i=0;
  startLED=6;
  while(i<ledNumber){
    digitalWrite(startLED,LOW);
    startLED++;
    i++;
  }
  startLED=6;
}
