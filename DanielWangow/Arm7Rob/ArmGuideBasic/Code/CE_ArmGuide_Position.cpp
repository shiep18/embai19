#include <Arm7Bot.h>
Arm7Bot Arm;
double angles_up[SERVO_NUM] = {90, 90, 65, 90, 90, 90, 50}; 
double angles_move[SERVO_NUM] = {180, 90, 65, 90, 180, 90, 10}; 
double angles_drop[SERVO_NUM] = {180, 52, 110, 90, 125, 90, 50}; 
void setup()
{
  Arm.begin(&Serial);
  Arm.initialMove();
  Serial.begin(9600);
  Serial.println(F("ArmGuider Initialization Done."));
}


void loop()
{
   //double angle数组修改第1位、第2位、第3位、第5位 
   double angles_3[SERVO_NUM] =  {90, 65, 125, 90, 110, 90, 50}; 
   double angles_3_catch[SERVO_NUM] = {90, 65, 125, 90, 110, 90, 10};
    Arm.move(angles_up);
    delay(2000);
    Arm.move(angles_3);
    delay(2000);
    Arm.move(angles_3_catch);
    delay(2000);
    step_move();
}

void step_move()
{
    Arm.move(angles_move);
    delay(2000);
    Arm.move(angles_drop);
    delay(2000);
    Arm.move(angles_up);
    delay(2000);
}

