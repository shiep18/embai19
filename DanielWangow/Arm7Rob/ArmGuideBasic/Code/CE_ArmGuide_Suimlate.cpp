#include<stdio.h>
#include<stdlib.h>
#include <Arm7Bot.h>
Arm7Bot Arm;
#define POSITION_NUM 15   //平面区域总数
#define SERVO_NUM 7       //可控自由度数
double angles_up[SERVO_NUM] = {90, 90, 65, 90, 90, 90, 50}; 
double angles_move[SERVO_NUM] = {180, 90, 65, 90, 180, 90, 10}; 
double angles_drop[SERVO_NUM] = {180, 52, 110, 90, 125, 90, 50}; 
const double angle_set[POSITION_NUM][SERVO_NUM] =
{
{ 123, 60, 120, 90, 120, 90, 50 },{ 105, 65, 125, 90, 110, 90, 50 },
{ 90, 65, 125, 90, 110, 90, 50 },{ 70, 65, 125, 90, 110, 90, 50 },
{ 57, 60, 120, 90, 120, 90, 50 },{ 113, 40, 110, 90, 125, 90, 50 },
{ 103, 45, 115, 90, 125, 90, 50 },{ 90, 50, 120, 90, 120, 90, 50 },
{ 75, 45, 115, 90, 125, 90, 50 },{ 67, 40, 110, 90, 125, 90, 50 },
{ 110, 10, 90, 90, 150, 90, 50 },{ 100, 10, 90, 90, 150, 90, 50 },
{ 90, 23, 100, 90, 135, 90, 50 },{ 80, 10, 90, 90, 150, 90, 50 },
{ 70, 10, 90, 90, 150, 90, 50 }
};
/*
double *loop_assign(int select_num, const double angle_set[][SERVO_NUM])
{
	int i;
	double ftransfer[SERVO_NUM];
	for (i = 0; i < SERVO_NUM; i++)
	{
		ftransfer[i] = angle_set[select_num][i];
		printf("%.3f ", ftransfer[i]);
	}
	printf("\n");
	return ftransfer;
}
*/
int main()
{
	int select_num; int i;
	double ftransfer[SERVO_NUM];
	double ftransfer_catch[SERVO_NUM];
	//printf("Pleace Input a INT number to set select_num: \n");
	//scanf_s("%d", &select_num);
	switch (select_num)
	{
	case 1: {
		for (i = 0; i < SERVO_NUM; i++)
		{
			ftransfer[i] = angle_set[select_num-1][i];
			ftransfer_catch[i] = angle_set[select_num - 1][i];
		}
		ftransfer_catch[SERVO_NUM-1] = 10;
        step_catch(ftransfer,ftransfer_catch);
		/*
        for (i = 0; i < SERVO_NUM; i++)
		{
			printf("%.3f ", ftransfer[i]);
		}
		printf("\n");	
		for (i = 0; i < SERVO_NUM; i++)
		{
			printf("%.3f ", ftransfer_catch[i]);
		}
		printf("\n");
        */
	}
    	case 2: {
		for (i = 0; i < SERVO_NUM; i++)
		{
			ftransfer[i] = angle_set[select_num-1][i];
			ftransfer_catch[i] = angle_set[select_num - 1][i];
		}
		ftransfer_catch[SERVO_NUM-1] = 10;
        step_catch(ftransfer,ftransfer_catch);
        }
	}
	//system("pause");
	//return 0;
}

void step_catch(double a[],double[])
{
    Arm.move(angles_up);
    delay(2000);
    Arm.move(a);
    delay(2000);
    Arm.move(b);
    delay(2000);
    Arm.move(angles_move);
    delay(2000);
    Arm.move(angles_drop);
    delay(2000);
    Arm.move(angles_up);
    delay(2000);
}