#include <Arm7Bot.h>
Arm7Bot Arm;

double offsetValues[SERVO_NUM] = {-9,2,-2,-10,0,2,0};

void setup() {
  Arm.begin(&Serial);
  for(int i=0; i<SERVO_NUM; i++)
  Arm.offset[i] = offsetValues[i];
  Arm.initialMove();
  while (!Arm.allConverge()) delay(20);

  Arm.moveIK5( {100, 200, 100}, {0, 0, -1}, 60, 20 );
  while (!Arm.allConverge()) delay(20);
  delay(1000);

  Arm.moveIK5( {100, 200, 45}, {0, 0,-1}, 60, 20 );
  while (!Arm.allConverge()) delay(20);
  delay(1000);

  Arm.moveIK5( {100, 200, 150}, {0, 0, -1}, 60, 20);
  while (!Arm.allConverge()) delay(20);
  delay(1000);

  Arm.moveIK5( {-50, 200, 150}, {0, 0, -1}, 60, 20 );
  while (!Arm.allConverge()) delay(20);
  delay(1000);
  
  Arm.moveIK5( {-50, 200, 150}, {4, 2, -1}, 60, 20 );
  while (!Arm.allConverge()) delay(20);
  delay(3000);

  Arm.moveIK5( {-50, 200, 150}, {0, 0, -1}, 60, 20 );
  while (!Arm.allConverge()) delay(20);
  delay(1000);

   Arm.moveIK5( {100, 200, 150}, {0, 0, -1}, 60, 20 );
  while (!Arm.allConverge()) delay(20);
  delay(1000);

  Arm.moveIK5( {100, 200, 55}, {0, 0, -1}, 60, 20 );
  while (!Arm.allConverge()) delay(20);
  delay(1000);

  Arm.moveIK5( {100, 200, 55}, {0, 0, -1}, 60, 80 );
  while (!Arm.allConverge()) delay(20);
  delay(1000);

  Arm.moveIK5( {100, 200, 150}, {0, 0, -1}, 60, 80 );
  while (!Arm.allConverge()) delay(20);
  delay(1000);
  Arm.initialMove();
  while (!Arm.allConverge()) delay(20);
}

void loop() {


}
