/* Segway_Encoder ���� C����*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

void ENCODER_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;				// TIMEBase Type ������
	GPIO_InitTypeDef GPIO_InitStructure;						// GPIO Type ������
  
	/* Peripheral Clock Config */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);		// TIM2 APB1  Clock Enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);		// TIM3 APB1  Clock Enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);		// TIM4 APB1  Clock Enable
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);		// TIM1 APB2  Clock Enable

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);		// GPIOA AHB1 Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);		// GPIOB AHB1 Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);		// GPIOC AHB1 Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);		// GPIOD AHB1 Clock Enable

	/* Gpio Config */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);    // A��Ʈ15 (A��) TIM2 ���
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);     // B��Ʈ3  (B��) TIM2 ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;                  // PIN15 ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                // AF���� ���
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;               // PULL UP ���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              // PUSH-PULL���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // ���ǵ�  50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                   // PIN3 ����
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);     // B��Ʈ4 (A��) TIM3 ���
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);     // B��Ʈ5 (B��) TIM3 ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;      // PIN4,PIN5 ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                // AF���� ���
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;               // PULL UP ���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              // PUSH-PULL���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // ���ǵ�  50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);	// D��Ʈ12 (A��) TIM4 ���
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);	// D��Ʈ13 (B��) TIM4 ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;	// PIN12,PIN13 ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                // AF���� ���
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;               // PULL UP ���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              // PUSH-PULL���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // ���ǵ�  50MHz
	GPIO_Init(GPIOD, &GPIO_InitStructure); 

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM8);     // C��Ʈ6 (A��) TIM8 ���
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM8);     // C��Ʈ7 (B��) TIM8 ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;      // PIN6,PIN7 ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                // AF���� ���
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;               // PULL UP ���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              // PUSH-PULL���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // ���ǵ�  50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure); 

	/* Time Base Config */
	TIM_TimeBaseStructure.TIM_Prescaler = 1-1;                      
	TIM_TimeBaseStructure.TIM_Period = 0xffff;                    // Encoder counter�� �ִ밪, ������ overflow
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;       // Digital filter �� Dead band ������
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   // Up counter ���

	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);	//TIM3�� TI1,TI2�� ���    
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);	//TIM3�� TI1,TI2�� ���    
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);	//TIM3�� TI1,TI2�� ���    
	TIM_EncoderInterfaceConfig(TIM8, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);	//TIM3�� TI1,TI2�� ���    
  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);		// TimeBase Init 
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);		// TimeBase Init 
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);		// TimeBase Init 
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);		// TimeBase Init 

	TIM_Cmd(TIM2, ENABLE);      // TIM2 Enable  
	TIM_Cmd(TIM3, ENABLE);      // TIM3 Enable  
	TIM_Cmd(TIM4, ENABLE);      // TIM4 Enable  
	TIM_Cmd(TIM8, ENABLE);      // TIM8 Enable 
}