#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//ʹ��PORTA,PORTEʱ��
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;//KEY0-KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOE4,3
}

//int Key_Scan(int flag)
//{
//  int num;
//  switch(flag)
//  {
//	  case 1 :num= 1;break;
//	  case 2 :num= 2;break;
//	  case 3 :num= 3;break;
//	  case 4 :num= 4;break;
//	  default:num= 0;break;
//  }
//  return num;
//}

//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����

//4��KEY3���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY3!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
		delay_ms(10);//ȥ���� 
		key_up=0;
		if(KEY1==0)return RIGHT;
		else if(KEY2==0)return LEFT;
		else if(KEY3==0)return DOWN;
		else if(KEY4==0)return UP;		
	}else if(KEY1==1&&KEY2==1&&KEY3==1||KEY4==1)key_up=1; 	    
 	return 0;// �ް�������
}


