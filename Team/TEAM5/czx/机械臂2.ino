#include <Arm7Bot.h>
Arm7Bot Arm;

double  angles_1[7] =  {170, 90, 60, 90, 90, 90, 75};
double  angles_2[7] =  {90, 115, 65, 90, 90, 90, 75};
double  angles_3[7] =  {170, 90, 60, 90, 90, 90, 75};
double  angles_4[7] =  {90, 115, 65, 90, 90, 90, 75};
char flag;

void setup() {
  // initial 7Bot Arm, the default mode is Normal Servo
  Arm.begin(&Serial);
  Serial.begin(9600);
  Arm.initialMove();

}

void loop() {

 /* Test */
  // Move to a lower pose
  flag = Serial.read();
  if(flag == '1') {
    action2();
  }
  if(flag == '2') {
    action2();
  }
  /*double angles_1[SERVO_NUM] =  {90, 90, 90, 90, 90, 90, 20};
  Arm.move(angles_1);
  delay(2000);*/
  /*double angles_1[SERVO_NUM] =  {90, 50, 130, 90, 90, 90, 75};
  Arm.move(angles_1);
  delay(1000);
  
  double angles_3[SERVO_NUM] =  {90, 43, 130, 90, 105, 90, 20};
  Arm.move(angles_3);
  delay(3000);
  double angles_4[SERVO_NUM] =  {170, 55, 130, 90, 90, 90, 20};
  Arm.move(angles_4);
  delay(1000);
  
  double angles_5[SERVO_NUM] =  {170, 55, 130, 90, 105, 90, 75};
  Arm.move(angles_5);
  delay(2000);
  double angles_6[SERVO_NUM] =  {90, 115, 65, 90, 90, 90, 75};
  Arm.move(angles_6);
  delay(2000);*/

  // Set mode to forceless
  //Arm.forcelessMode();
 // delay(3000);
}

void action1(){
  //double angles_1[SERVO_NUM] =  {90, 50, 130, 90, 90, 90, 75};
  Arm.move(angles_1);
  delay(1000);

  //double angles_2[SERVO_NUM] =  {90, 115, 65, 90, 90, 90, 75};
  Arm.move(angles_2);
  delay(2000);
}

void action2(){
  //double angles_3[SERVO_NUM] =  {170, 90, 60, 90, 90, 90, 75};
  Arm.move(angles_3);
  delay(2000);

  //double angles_4[SERVO_NUM] =  {90, 115, 65, 90, 90, 90, 75};
  Arm.move(angles_4);
  delay(2000);
}
