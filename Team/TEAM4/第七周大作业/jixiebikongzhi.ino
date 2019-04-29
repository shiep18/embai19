#include<Arm7Bot.h>
#include<stdio.h>
Arm7Bot Arm;

double x = 0, y = 200, z = 100, m = 60, n = 50;

char tag1;
char tag2;

void setup() {

  Arm.begin(&Serial);
  Arm.initialMove();
  Serial.begin(9600);
  Arm.maxSpeed[0] = 100;

  while (!Arm.allConverge())
  {
    delay(20);
  }
  Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
  tag1 = Serial.read();

  // put your setup code here, to run once:

}

void loop() {
  delay(100);
  if(Serial.available())
  {
  tag1 = Serial.read();
  }
  while (tag1 == '4') {         
                             //向右
    x += 1;
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
   
    
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }
  }
  while (tag1 == '5')
  //向左
  {
    x -= 1;
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
 
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }
  }
 while (tag1 == '2')
 //向前
  {
    y += 1;
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
 
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }
  }
 while (tag1 == '3')
 //向后
  {
    y -= 1;
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
 
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }
  }
 while (tag1 == '6')
 //向上
  {
    z += 1;
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
 
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }
  }
   while (tag1 == '7')
   //向下
  {
    z -= 1;
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
 
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }
  }
   while (tag1 == 'b')
   //吸
  {
    n= 10;
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
 
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }
  }
 while (tag1 == 'c')
 //停止吸
  {
    n= 60;
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
 
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }
  }
     while (tag1 == 'a')
  {
    Arm.moveIK5({x, y, z}, {0, 0, -1}, m, n);
 
    if (Serial.available() > 0)
    {
      tag2 = Serial.read();
      tag1 = tag2;
      break;
    }//停下
  } 
  while(tag1=='8')
  //喝水
  {
    delay(100);
    if(Serial.available()==0)
{ x=100;y=200;z=100;m=60;n=20; 
  Arm.moveIK5( {x,y,z}, {0, 0, -1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(1000);
}
else
{break;}
if(Serial.available()==0)
  {x=100;y=200;z=47;m=60;n=20;
  Arm.moveIK5( {x,y,z}, {0, 0,-1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(2000);
  }
  else
  {break;}
  if(Serial.available()==0)
{ x=100;y=200;z=150;m=60;n=20; 
  Arm.moveIK5( {x,y,z}, {0, 0, -1}, m, n);
  while (!Arm.allConverge()) delay(20);
  delay(1000);
}
else
{break;}
if(Serial.available()==0)
  {x=-50;y=200;z=150;m=60;n=20;
  Arm.moveIK5( {x,y,z}, {0, 0, -1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(1000);}
  else
  {break;}
  if(Serial.available()==0)
{ x=-50;y=200;z=150;m=60;n=20; 
   Arm.moveIK5( {x,y,z}, {4, 2, -1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(3000);
}
else
{break;}
if(Serial.available()==0)
{ x=-50;y=200;z=150;m=60;n=20;
 Arm.moveIK5( {x,y,z}, {0, 0, -1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(1000);
}
else
{break;}
if(Serial.available()==0)
   {x=100;y=200;z=150;m=60;n=20;
    Arm.moveIK5( {x,y,z}, {0, 0, -1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(1000);
   }
   else
   {break;}
if(Serial.available()==0)
{ x=100;y=200;z=65;m=60;n=20 ;
 Arm.moveIK5( {x,y,z}, {0, 0, -1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(1000);
}
else
{break;}
if(Serial.available()==0)
{ x=100;y=200;z=65;m=60;n=80;
   Arm.moveIK5( {x,y,z}, {0, 0, -1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(1000);
}
else
{break;}
if(Serial.available()==0)
  {x=100;y=200;z=150;m=60;n=80;
    Arm.moveIK5( {x,y,z}, {0, 0, -1}, m, n );
  while (!Arm.allConverge()) delay(20);
  delay(1000);
  }
  else
  {break;}



 
      if(Serial.available()>0)
      {tag2 = Serial.read();
      tag1 = tag2;
      break;
      }
  }

  // put your main code here, to run repeatedly:

}

