/* Segway_PWM ���� c����*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

float Output_Right=0;
float Output_Left=0;


void PWM_Segway_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;			// TIMEBase Type ������
	TIM_OCInitTypeDef TIM_OCInitStructure;					// Tim OutputCompare Type ������
	GPIO_InitTypeDef GPIO_InitStructure;					// GPIO Type ������
	
	/* Peripheral Clock Config */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);	// TIM9 APB2 Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);	// GPIOE AHB1 Clock Enable

	/* Gpio Config */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);	// PWM Channel_1 (Left Wheel)  TIM9 ���
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource6, GPIO_AF_TIM9);	// PWM Channel_2 (Right Wheel) TIM9 ���
     
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;	// PIN5,PIN6 ���� 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			// AF���� ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// ���ǵ�  50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// PUSH-PULL���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;		// PULL UP,PULL DOWN ������	 
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* Time Base Config */
	TIM_TimeBaseStructure.TIM_Prescaler = 2-1;					// 168MHz/2 = 84Mhz
	TIM_TimeBaseStructure.TIM_Period = 5000-1;					// 84MHz/5000 = 16.8KHz
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;				// ������ ���� �� dead band�� ���            
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // ī��Ʈ �� ���
	TIM_TimeBaseInit(TIM9, &TIM_TimeBaseStructure);             
   
	/* Output Compare Config */
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				// OutputCompare PWM1���
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	// ��� ���� ENABLE  
	TIM_OCInitStructure.TIM_Pulse = 0;								// Duty ����
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		// OutputCompare �ؼ� High ���� ���
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;		// OutputCompare IDLE ���� Set      		

	TIM_OC1Init(TIM9, &TIM_OCInitStructure);
	TIM_OC2Init(TIM9, &TIM_OCInitStructure);

	TIM_Cmd(TIM9, ENABLE);                                                
}

void PWM_SEA_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;							// GPIO Type ������
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;					// TIMEBase Type ������
	TIM_OCInitTypeDef TIM_OCInitStructure;							// Tim OutputCompare Type ������

	/* Peripheral Clock Config */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);			// TIM1 APB2 Clock Enable           
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);			// GPIOE AHB1 Clock Enable              

	/* Gpio Config */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_TIM1);			// PWM Channel_1 (SEA_1) TIM1 ���
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);		// PWM Channel_2 (SEA_2) TIM1 ���
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_TIM1);		// PWM Channel_3 (SEA_3) TIM1 ���
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);		// PWM Channel_4 (SEA_4) TIM1 ���
     
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14;	// PIN9,PIN11,PIN13,PIN14 ����  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;					// AF���� ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				// ���ǵ�  50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					// PUSH-PULL���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;				// PULL UP,PULL DOWN ������  
	GPIO_Init(GPIOE, &GPIO_InitStructure);
     
	/* Time Base Config */
	TIM_TimeBaseStructure.TIM_Prescaler = 2 - 1;					// 168MHz/2 = 84Mhz
	TIM_TimeBaseStructure.TIM_Period = 5000 - 1;					// 84MHz/5000 = 16.8KHz
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;					// ������ ���� �� dead band�� ���            
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		// ī��Ʈ �� ���
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	/* Output Compare Config */
	TIM_OCStructInit(&TIM_OCInitStructure);							// TIM OutputCompare �ʱ�ȭ
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				// OutputCompare PWM1���
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	// ��� ���� ENABLE  
	TIM_OCInitStructure.TIM_Pulse = 0;								// Duty ����
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		// OutputCompare �ؼ� High ���� ���
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;		// OutputCompare IDLE ���� Set       		
    
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);	// OutputCompare Init
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);	// OutputCompare Init
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);	// OutputCompare Init
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);	// OutputCompare Init
    
	TIM_Cmd(TIM1, ENABLE);						// TIM1 Enable                                           

	TIM_CtrlPWMOutputs(TIM1, ENABLE);			// MAIN PWM Enable 
}

void PWM_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;  

	/* Peripheral Clock Config */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);		// GPIOD AHB1 Clock Enable
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);		// GPIOE AHB1 Clock Enable
	
	/* Gpio Config */
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0 |GPIO_Pin_1;		// PIN0,PIN1 ���� PWM_DIR
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;				// OUTPUT���� ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			// ���ǵ�  50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;				// PUSH-PULL���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;			// PULL UP,PULL DOWN ������  
	GPIO_Init(GPIOD, &GPIO_InitStructure);						

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;	// PIN1,PIN2,PIN3,PIN4 ����  SEA_DIR
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;				// OUTPUT���� ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			// ���ǵ�  50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;				// PUSH-PULL���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;			// PULL UP,PULL DOWN ������  
	GPIO_Init(GPIOE, &GPIO_InitStructure);

}