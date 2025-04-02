#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"


#define KEY1   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)//��ȡ����1
#define KEY2   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)//��ȡ����2
#define KEY3   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)//��ȡ����3
#define KEY4   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//��ȡ����4

 

#define RIGHT	1	//KEY1����
#define LEFT	2	//KEY2����
#define DOWN	3	//KEY3����
#define UP		4	//KEY4����

void KEY_Init(void);//IO��ʼ��	
//int Key_Scan(int flag);//����ɨ��
u8 KEY_Scan(u8);  	//����ɨ�躯��
#endif


