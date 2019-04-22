#include <Arm7Bot.h>
Arm7Bot Arm;

void setup() {
  // initial 7Bot Arm, the default mode is Normal Servo
  Arm.begin(&Serial);
  Arm.initialMove();
}

void loop() {

 /* Test */
  // Move to a lower pose
  double angles_1[SERVO_NUM] =  {90, 140, 65, 90, 90, 90, 75};
  Arm.move(angles_1);
  delay(2000);
double angles_2[SERVO_NUM] =  {45, 45, 65, 90, 140, 90, 75};
  Arm.move(angles_2);
  delay(2000);
double angles_3[SERVO_NUM] =  {45, 45, 100, 105, 140, 90, 10};
  Arm.move(angles_3);
  delay(3000);

double angles_4[SERVO_NUM] =  {45, 45, 100, 105, 140, 90, 10};
  Arm.move(angles_4);
  delay(2000);
  double angles_5[SERVO_NUM] =  {45, 45, 100, 105, 140, 90, 10};
  Arm.move(angles_5);
  delay(2000);

  double angles_6[SERVO_NUM] =  {90, 140, 65, 105, 90, 90, 10};
  Arm.move(angles_6);
  delay(2000);
    double angles_7[SERVO_NUM] =  {135, 45, 65, 90, 135, 90, 10};
  Arm.move(angles_7);
  delay(2000);
  double angles_8[SERVO_NUM] =  {135, 45, 90, 90, 135, 90, 40};
  Arm.move(angles_8);
  delay(2000);
    //double angles_1[SERVO_NUM] =  {90, 140, 65, 90, 90, 90, 75};
  Arm.move(angles_1);
  delay(2000);


  // Set mode to forceless
  Arm.forcelessMode();
  delay(3000);
}
