#include <Arm7Bot.h>
Arm7Bot Arm;
void setup()
{
    Arm.begin(&Serial);
    Arm.initialMove();
	Serial.begin(9600);
	Serial.println(F("ArmGuider Initialization Done."));
    help();
}
void loop()
{
  
   double angles_1[SERVO_NUM] =  {90, 90, 65, 90, 90, 90, 50};     //初始姿态
  
   double angles_2[SERVO_NUM] =  {90, 52, 110, 90, 130, 90, 50};   //寻找姿态
  
   double angles_3[SERVO_NUM] =  {90, 52, 110, 90, 130, 90, 10};   //抓取姿态
  
   double angles_4[SERVO_NUM] =  {130, 90, 65, 90, 90, 90, 10};    //移动姿态
  
   double angles_5[SERVO_NUM] =  {130, 52, 110, 90, 125, 90, 50};  //下落姿态
    if(Serial.available()){
        char c=Serial.read();
        if(c == 'a'||c == 'A'){
            Serial.println(F("ArmGuider is Working for Capturing"));
            Arm.move(angles_1);
            delay(2000);
            Arm.move(angles_2);
            delay(2000);
            Arm.move(angles_3);
            delay(2000);
            Arm.move(angles_4);
            delay(2000);
            Arm.move(angles_5);
            delay(2000);
            Arm.move(angles_1);
            delay(2000);
            Arm.forcelessMode();// Set mode to forceless
            delay(3000);
            Serial.println(F("Work Done"));
        }
         else if(c == 'b'||c == 'B'){
            Serial.println(F("ArmGuider is Working for Moving"));
            Arm.move(angles_1);
            delay(2000);
            Arm.move(angles_2);
            delay(2000);
            Arm.move(angles_5);
            delay(2000);
            Arm.move(angles_1);
            delay(2000);
            Arm.forcelessMode();// Set mode to forceless
            delay(3000);
            Serial.println(F("Work Done"));
        }
        else if(c == 'h'){
            help();
        }
        
    }
}

void help() {

  Serial.println(F("COMMANDS:"));

  Serial.println(F(" [a]/[A] to Call Capture"));

  Serial.println(F(" [b]/[B] to Call Next Posture"));

  Serial.println(F(" [h] this help"));

}