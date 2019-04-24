#include <Arm7Bot.h>
#include <stdio.h>
Arm7Bot Arm;
int IKdegree[4];
int i=0,j=0;
void setup() {
  // initial 7Bot Arm, the default mode is Normal Servo
  Arm.begin(&Serial);
  Arm.initialMove();
  delay(50);
  Serial.begin(9600);
  while(Serial.read()>= 0){
    }
}

void loop() {
    Arm.maxSpeed[0] = 100;

        while (Serial.available() > 0)
        {  
             delay(100);
             IKdegree[0] = Serial.read();     
             IKdegree[1] = Serial.read(); 
             IKdegree[2] = Serial.read(); 
             IKdegree[3] = Serial.read(); 
             Serial.write(char(IKdegree[0]));
             Serial.write(char(IKdegree[1]));
             Serial.write(char(IKdegree[2]));
             Serial.write(char(IKdegree[3]));
         }
         

    Arm.moveIK5( {double(IKdegree[0]),double(IKdegree[1]),double(IKdegree[2])}, {0, 0, -1}, 60, double(IKdegree[3]) );
    while (!Arm.allConverge()) delay(20);
    delay(1000); 
  }
