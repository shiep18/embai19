#include <stdlib.h>
#include<string.h>
#include <Arm7Bot.h>
Arm7Bot Arm;
void setup()
{
    Arm.begin(&Serial);
    Arm.initialMove();
    Serial.begin(9600);
    Serial.println(F("ArmGuider Initialization Done."));
}
void loop()
{ 
   double angles_1[SERVO_NUM] =  {90, 90, 65, 90, 90, 90, 50};     //初始姿态数组
   char serialread[10];
   double receive_num[SERVO_NUM];
   char *temp;
   int timesFlag;
   if(Serial.available()){
    serialread[10] = Serial.read();
	temp = strtok(serialread, "/");
	receive_num[0] = atof(temp);
	for (timesFlag = 1; timesFlag < 8; timesFlag++)
	{
		receive_num[timesFlag] = 0;
		temp = strtok(NULL, "/");
		receive_num[timesFlag] = atof(temp);
	}
    Serial.println(F("ArmGuider is Working for Capturing"));
    Arm.move(angles_1);
    delay(2000);
    Arm.move(receive_num);
    delay(2000);
    Arm.forcelessMode();// Set mode to forceless
    delay(3000);
    Serial.println(F("Work Done"));
   }
}











    if(Serial.available()){
        char c=Serial.read();
        if(c == '0'||c == 'A'){
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
         else if(c == '1'||c == 'B'){
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