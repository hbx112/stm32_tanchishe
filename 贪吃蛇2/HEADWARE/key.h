#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"


#define KEY1   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)//读取按键1
#define KEY2   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)//读取按键2
#define KEY3   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)//读取按键3
#define KEY4   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//读取按键4

 

#define RIGHT	1	//KEY1按下
#define LEFT	2	//KEY2按下
#define DOWN	3	//KEY3按下
#define UP		4	//KEY4按下

void KEY_Init(void);//IO初始化	
//int Key_Scan(int flag);//按键扫描
u8 KEY_Scan(u8);  	//按键扫描函数
#endif


