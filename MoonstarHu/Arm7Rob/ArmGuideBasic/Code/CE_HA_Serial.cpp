#include <Arm7Bot.h>
Arm7Bot Arm;
void setup()
{
    Arm.begin(&Serial);
    Arm.initialMove();
	Serial.begin(9600);
}
void loop()
{
  while(1)
  {
      delay(1000);
      Serial.print('1');
  }
}