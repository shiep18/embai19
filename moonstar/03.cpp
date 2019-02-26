void setup()
{
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
}


void loop()w
{
  if(digitalRead(2))
 {
     digitalWrite(4,HIGH);

 }
 else
 {
     digitalWrite(4,LOW);

 }

}