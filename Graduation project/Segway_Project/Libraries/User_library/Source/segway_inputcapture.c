/* Segway_InpuCapture ���� c����*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

int Capture_1;				//  Left Input Capture Count ��
int Capture_2;				// Right Input Capture Count ��
int Diff_1;					//  Left Input Capture Cal �ӽ� ����
int Diff_2;					// Right Input Capture Cal �ӽ� ����
int Capture_Prev_1;			//  Left ���� Capture ��
int Capture_Prev_2;			// Right ���� Capture ��
int Timer_Update_Cnt_1;		//  Left Timer Update Count ��
int Timer_Update_Cnt_2;		// Right Timer Update Count ��
float Segway_RPM_1;			//  Left Wheel RPM ��
float Segway_RPM_2;			// Right Wheel RPM ��
float Segway_Prev_RPM_1;	//  Left Wheel Previous RPM ��
float Segway_Prev_RPM_2;	// Right Wheel Previous RPM ��
uint16_t PrescalerValue;	// Prescaler Value ��

void INPUT_CAPTURE_Config(void)
{
    TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;				// TIMEBase Type ������
	GPIO_InitTypeDef GPIO_InitStructure;						// GPIO Type ������
	NVIC_InitTypeDef NVIC_InitStructure;						// NVIC Type ������
  
	/* Peripheral Clock Config */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);		// TIM10 APB2 Clock Enable
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);		// TIM11 APB2 Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);		// GPIOB AHB1 Clock Enable

	/* Gpio Config */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);	// B��Ʈ8 (A��) TIM10 �̿��ؼ� ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					// PIN8 ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                // AF���� ���
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;               // PULL UP ���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              // PUSH-PULL���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // ���ǵ�  50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);	// B��Ʈ9 (A��) TIM11 �̿��ؼ� ���
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					// PIN9 ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                // AF���� ���
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;               // PULL UP ���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              // PUSH-PULL���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // ���ǵ�  50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

	/* Time Base Config  */
    SystemCoreClockUpdate();
    PrescalerValue = (uint16_t) (SystemCoreClock / TIMER_PRESCALER_FREQ) - 1;	// 168000000 / 1000000)�� 1MHz �Է�

	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;			// 168000000 / 1000000 = 168           
	TIM_TimeBaseStructure.TIM_Period = TIMER_PERIOD;				// 1MHz ���� Count Up
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;					// Digital filter �� Dead band ������
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		// Up counter ���
	TIM_TimeBaseInit(TIM10, &TIM_TimeBaseStructure); 
	TIM_TimeBaseInit(TIM11, &TIM_TimeBaseStructure); 

	/* Input Capture Config  */
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;				// TIM Channel 1 ���
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Falling;	// Pulse�� Falling Edge���� Capture �߻�
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;	// InputCapture�� ������� �ٷ� �Է�
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;			// Pulse�� �߻��� �� ���� �ٷ� ����
    TIM_ICInitStructure.TIM_ICFilter = 0xf;							// Signal Filter 0x0~0xf Noise Ŭ���� 0xf������

	TIM_ICInit(TIM10, &TIM_ICInitStructure);
	TIM_ICInit(TIM11, &TIM_ICInitStructure);

	/* Interrupt Config  */
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;		// TIM10 ���ͷ�Ʈ �ڵ鷯 ���
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// �켱���� 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;			// ���� �켱���� 0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler���
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_TIM11_IRQn;	// TIM11 ���ͷ�Ʈ �ڵ鷯 ���
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// �켱���� 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler���
	NVIC_Init(&NVIC_InitStructure);

	TIM_ITConfig(TIM10, TIM_IT_Update | TIM_IT_CC1, ENABLE);		// ���ͷ�Ʈ ����
	TIM_Cmd(TIM10, ENABLE);

	TIM_ITConfig(TIM11, TIM_IT_Update | TIM_IT_CC1, ENABLE);		// ���ͷ�Ʈ ����
	TIM_Cmd(TIM11, ENABLE);
}

void TIM1_UP_TIM10_IRQHandler(void)			// ���� ���� �ӵ��� ���
{
    if (TIM_GetITStatus(TIM10, TIM_IT_Update) == SET)
    {
        TIM_ClearITPendingBit(TIM10, TIM_IT_Update);		// TIM10 Update PendingBit Clear	
        Timer_Update_Cnt_1++;								// Capture���� Overflow �� �� ���� 1�� ����
    }
    if (TIM_GetITStatus(TIM10, TIM_IT_CC1) == SET)
    {
		TIM_ClearITPendingBit(TIM10, TIM_IT_CC1);			// TIM10 Capture Compare PendingBit Clear
		Capture_1 = TIM_GetCapture1(TIM10);					// ���� Capture �� ����
		Diff_1 = Timer_Update_Cnt_1 * TIMER_PERIOD + Capture_1 - Capture_Prev_1;	// �� �޽��� ��� ī��Ʈ �ƴ���  
		Segway_RPM_1 = (float)(60*1000000)/(Diff_1*10);		// RPM = (60*1000000)/(Diff_1*x) -> x�� ���谪 10

		if(Segway_RPM_1<0)
			Segway_RPM_1 = Segway_Prev_RPM_1;		// RPM���� -�� ����RPM���� ���� RPM���� ���� 
		else 
			Segway_Prev_RPM_1 = Segway_RPM_1;		// RPM���� +�� ����RPM���� ���� RPM���� ����
		
		Capture_Prev_1 = Capture_1;					// ���� Capture ���� ���� Capture���� ����				
		Timer_Update_Cnt_1 = 0;						// Overflow ���� �ʱ�ȭ
    }
}
void TIM1_TRG_COM_TIM11_IRQHandler(void)	// ������ ���� �ӵ��� ���
{
    if (TIM_GetITStatus(TIM11, TIM_IT_Update) == SET)
    {
        TIM_ClearITPendingBit(TIM11, TIM_IT_Update);		// TIM11 Update PendingBit Clear	
        Timer_Update_Cnt_2++;								// Capture���� Overflow �� �� ���� 1�� ����
    }
    if (TIM_GetITStatus(TIM11, TIM_IT_CC1) == SET)
    {
		TIM_ClearITPendingBit(TIM11, TIM_IT_CC1);			// TIM11 Capture Compare PendingBit Clear
		Capture_2 = TIM_GetCapture1(TIM11);					// ���� Capture �� ����
		Diff_2 = Timer_Update_Cnt_2 * TIMER_PERIOD + Capture_2 - Capture_Prev_2;	// �� �޽��� ��� ī��Ʈ �ƴ���  
		Segway_RPM_2 = (float)(60*1000000)/(Diff_2*10);		// RPM = (60*1000000)/(Diff_2*x) -> x�� ���谪 10

		if(Segway_RPM_2<0)
			Segway_RPM_2 = Segway_Prev_RPM_2;		// RPM���� -�� ����RPM���� ���� RPM���� ���� 
		else 
			Segway_Prev_RPM_2 = Segway_RPM_2;		// RPM���� +�� ����RPM���� ���� RPM���� ����
		
		Capture_Prev_2 = Capture_2;					// ���� Capture ���� ���� Capture���� ����
		Timer_Update_Cnt_2 = 0;						// Overflow ���� �ʱ�ȭ
    }
}