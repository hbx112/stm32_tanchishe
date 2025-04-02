#include "keyscan_exit.h"
#include "led.h"
#include "key.h"
#include "delay.h" 
#include "snake.h"
int flag=0;
void EXTIX_Init(void)
{
 
   	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;
    KEY_Init();	 //	�����˿ڳ�ʼ��
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��
	
   //GPIOA1  �ж����Լ��жϳ�ʼ������ 
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG,GPIO_PinSource0);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_Init(&EXTI_InitStructure);	  	

   //GPIOA2	  
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG,GPIO_PinSource1);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line1;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_Init(&EXTI_InitStructure);	  	


   //GPIOA3	  
 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG,GPIO_PinSource3); 

  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_Init(&EXTI_InitStructure);		

  //GPIOA4  
 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG,GPIO_PinSource4); 

  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_Init(&EXTI_InitStructure);		

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
  	NVIC_Init(&NVIC_InitStructure); 

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
  	NVIC_Init(&NVIC_InitStructure);  	  
	
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
  	NVIC_Init(&NVIC_InitStructure);  	  
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	 
 
}

//�ⲿ�ж�0������� 
void EXTI0_IRQHandler(void)//��
{
	
	flag=1;
	delay_ms(10);//����
	if(KEY1==0)
	{
		KEY_Scan(0);
		LED1=!LED1;
	}
	EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ  
}
 

//�ⲿ�ж�1�������
void EXTI1_IRQHandler(void)//��
{
	flag=2;
	delay_ms(10);//����
	if(KEY2==0)
	{
		KEY_Scan(0);
		LED1=!LED1;
	}
	EXTI_ClearITPendingBit(EXTI_Line1);  //���LINE3�ϵ��жϱ�־λ  
}

//�ⲿ�ж�3�������
void EXTI3_IRQHandler(void)//��
{
	flag=3;
	delay_ms(10);//����
	if(KEY3==0)
	{
		KEY_Scan(0);
		LED1=!LED1;
	}
	EXTI_ClearITPendingBit(EXTI_Line3);  //���LINE4�ϵ��жϱ�־λ  
}

//�ⲿ�ж�4�������
void EXTI4_IRQHandler(void)//��
{
	flag=4;
	delay_ms(10);//����
	if(KEY4==0)
	{
		KEY_Scan(0);
		LED1=!LED1;
	}
	EXTI_ClearITPendingBit(EXTI_Line4);   //���LINE4�ϵ��жϱ�־λ  
}
