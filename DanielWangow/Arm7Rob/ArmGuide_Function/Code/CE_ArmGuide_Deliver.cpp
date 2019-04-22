#include <Arm7Bot.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
Arm7Bot Arm;
#define POSITION_NUM 15   //平面区域总数
#define SERVO_NUM 7       //可控自由度数
double angles_up[SERVO_NUM] = {90, 90, 65, 90, 90, 90, 50}; 
double angles_up_catch[SERVO_NUM] = {90, 90, 65, 90, 90, 90, 10}; 
double angles_up_left[SERVO_NUM] = {123, 90, 65, 90, 90, 90, 10}; 
double angles_left[SERVO_NUM] = {123, 90, 65, 90, 90, 90, 50}; 
double angles_up_right[SERVO_NUM] = {70, 90, 65, 90, 90, 90, 10}; 
double angles_right[SERVO_NUM] = {70, 90, 65, 90, 90, 90, 50}; 
double angles_move[SERVO_NUM] = {180, 90, 65, 90, 90, 90, 50}; 
double angles_deliver[SERVO_NUM] = {180, 50, 120, 90, 125, 90, 10}; 
//xy坐标————各自由度位置
const double angle_set[POSITION_NUM][SERVO_NUM] =
{
{ 123, 60, 125, 90, 120, 90, 50 },{ 105, 70, 110, 90, 110, 90, 50 },
{ 90, 65, 115, 90, 110, 90, 50 },{ 70, 65, 115, 90, 110, 90, 50 },
{ 57, 60, 125, 90, 120, 90, 50 },{ 113, 40, 110, 90, 125, 90, 50 },
{ 103, 45, 105, 90, 125, 90, 50 },{ 90, 50, 110, 90, 120, 90, 50 },
{ 75, 45, 105, 90, 125, 90, 50 },{ 67, 40, 110, 90, 125, 90, 50 },
{ 110, 10, 93, 90, 150, 90, 50 },{ 100, 10, 83, 90, 150, 90, 50 },
{ 90, 23, 93, 91, 135, 90, 50 },{ 80, 10, 82, 90, 150, 90, 50 },
{ 70, 10, 90, 90, 150, 90, 50 }
};
//x-y坐标结构体
struct return_pxy
{
	int int_px;
	int int_py;
};

void setup()
{
    Arm.begin(&Serial);
    Arm.initialMove();
	Serial.begin(9600);
}

void loop()
{
    //int done_p_x; int done_p_y;
    struct return_pxy stu_position;
    char receive_char;
    char serial_receive[30];
    int select_num,read_flag=0,bit_temp,read_open=1;
    //while(Serial.available()&&read_open){
    while(1){
        if(Serial.available()){
        receive_char = Serial.read();
        if(receive_char == 'F')
        {
            read_flag = 1;
            bit_temp = 0;
        }
        if(read_flag)
        {
            if(receive_char == 'L')
            {
                serial_receive[bit_temp-1] = '\0';
                read_flag = 0;
                //read_open = 0;
                break;
            }
            else
            {
                if(bit_temp){
                serial_receive[bit_temp-1] = receive_char;
                bit_temp++;
                }
                else bit_temp++;
            }    
        }
    }
    }
    stu_position=get_position(serial_receive);
    select_num = step_zone(stu_position.int_px,stu_position.int_py);
    step_select(select_num);
    Serial.print("1");








        /*
    //串口读取为整型int
       char serial_receive[30]={Serial.read()};
       stu_position=get_position(serial_receive);
       select_num = step_zone(stu_position.int_px,stu_position.int_py);
       step_select(select_num);
       */
      /*
    串口读取为字符型char
       char ch=Serial.read();
       step_switch_ch(ch);
       */
    
   
}


//抓取操作
void step_deliver(double a[],double b[],int select_num)
{
    if(select_num==12||select_num==13)
    {
    Arm.move(angles_up);
    delay(2000);
    Arm.move(angles_move);
    delay(2000);
    Arm.move(angles_deliver);
    delay(2000);
    Arm.move(angles_up_left);
    delay(2000);
    //Arm.move(b);
    //delay(2000);
    Arm.move(a);
    delay(2000);
    Arm.move(angles_left);
    delay(2000);
    Arm.move(angles_up);
    delay(2000);
    }
    else if(select_num==14)
    {
    Arm.move(angles_up);
    delay(2000);
    Arm.move(angles_move);
    delay(2000);
    Arm.move(angles_deliver);
    delay(2000);
    Arm.move(angles_up_right);
    delay(2000);
    //Arm.move(b);
    //delay(2000);
    Arm.move(a);
    delay(2000);
    Arm.move(angles_right);
    delay(2000);
    Arm.move(angles_up);
    delay(2000);
    }
    else{
    Arm.move(angles_up);
    delay(2000);
    Arm.move(angles_move);
    delay(2000);
    Arm.move(angles_deliver);
    delay(2000);
    Arm.move(angles_up_catch);
    delay(2000);
    //Arm.move(b);
    //delay(2000);
    Arm.move(a);
    delay(2000);
    Arm.move(angles_up);
    delay(2000);
    }
}


//判断符为整型
void step_select(int select_num)
{
    int i;
	double ftransfer[SERVO_NUM];
	double ftransfer_catch[SERVO_NUM];
    for (i = 0; i < SERVO_NUM; i++)
	{
		ftransfer[i] = angle_set[select_num-1][i];
        ftransfer_catch[i] = angle_set[select_num - 1][i];
	}
	ftransfer_catch[SERVO_NUM-1] = 10;   
    step_deliver(ftransfer,ftransfer_catch,select_num); 
}

//判断符为字符型
void step_switch_ch(char ch)
{
    int select_num; 
    switch (ch)
    {
        case '1':
            {
               select_num=1; 
               step_select(select_num);
            }
                break;
        case '2':
            {
               select_num=2; 
               step_select(select_num);
            }
                break;
        case '3':
            {
               select_num=3; 
               step_select(select_num);
            }
                break;
        case '4':
            {
               select_num=4; 
               step_select(select_num);
            }
                break;
        case '5':
            {
               select_num=5; 
               step_select(select_num);
            }
                break;
        case '6':
            {
               select_num=6; 
               step_select(select_num);  
            }
                break;
        case '7':
            {
               select_num=7; 
               step_select(select_num);
            }
                break;
        case '8':
            {
               select_num=8; 
               step_select(select_num);
            }
                break;
        case '9':
            {
               select_num=9; 
               step_select(select_num);  
            }
                break;
        case '10':
            {
               select_num=10; 
               step_select(select_num);
            }
                break;
        case '11':
            {
               select_num=11; 
               step_select(select_num);
            }
                break;
        case '12':
            {
               select_num=12; 
               step_select(select_num);
            }
                break;
        case '13':
            {
               select_num=13; 
               step_select(select_num);
            }
                break;
        case '14':
            {
               select_num=14; 
               step_select(select_num);
            }
                break;
        case '15':
            {
               select_num=15; 
               step_select(select_num);
            }
                break;
        default:
             break;
    }    
}

//读取串口字符串(char)并进行分割、转为x，y坐标(int)
//返回x-y坐标结构体
struct return_pxy get_position(char serial_input[])
{
	struct return_pxy stu_position;
    char*p_x; char*p_y;
    int int_p_x,int_p_y;
    p_x = strtok(serial_input, "/");
    int_p_x = atoi(p_x);
	stu_position.int_px = int_p_x ;
    p_y = strtok(NULL, "/");
    int_p_y = atoi(p_y);
	stu_position.int_py =  int_p_y;
	return stu_position;
}

int step_zone(int x,int y)
{
  int x_mark,y_mark;
  //确定y坐标区域标志
  if(y>=0&&y<=150)          y_mark=1;
  else if(y>150&&y<=285)    y_mark=6;
  else if(y>285&&y<=460)    y_mark=11;
  //确定x坐标区域标志
  if(x>=0&&x<=110)          x_mark=0;
  else if(x>100&&x<=240)    x_mark=1;
  else if(x>240&&x<=370)    x_mark=2;
  else if(x>360&&x<=510)    x_mark=3;
  else if(x>510&&y<=640)    x_mark=4;
  return x_mark+y_mark;
}
