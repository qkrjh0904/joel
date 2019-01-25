/* Segway_InpuCapture 관련 c파일*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

int Capture_1;				//  Left Input Capture Count 값
int Capture_2;				// Right Input Capture Count 값
int Diff_1;					//  Left Input Capture Cal 임시 변수
int Diff_2;					// Right Input Capture Cal 임시 변수
int Capture_Prev_1;			//  Left 이전 Capture 값
int Capture_Prev_2;			// Right 이전 Capture 값
int Timer_Update_Cnt_1;		//  Left Timer Update Count 값
int Timer_Update_Cnt_2;		// Right Timer Update Count 값
float Segway_RPM_1;			//  Left Wheel RPM 값
float Segway_RPM_2;			// Right Wheel RPM 값
float Segway_Prev_RPM_1;	//  Left Wheel Previous RPM 값
float Segway_Prev_RPM_2;	// Right Wheel Previous RPM 값
uint16_t PrescalerValue;	// Prescaler Value 값

void INPUT_CAPTURE_Config(void)
{
    TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;				// TIMEBase Type 재정의
	GPIO_InitTypeDef GPIO_InitStructure;						// GPIO Type 재정의
	NVIC_InitTypeDef NVIC_InitStructure;						// NVIC Type 재정의
  
	/* Peripheral Clock Config */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);		// TIM10 APB2 Clock Enable
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM11, ENABLE);		// TIM11 APB2 Clock Enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);		// GPIOB AHB1 Clock Enable

	/* Gpio Config */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_TIM10);	// B포트8 (A상) TIM10 이용해서 사용
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;					// PIN8 설정
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                // AF모드로 사용
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;               // PULL UP 사용
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              // PUSH-PULL사용
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // 스피드  50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM11);	// B포트9 (A상) TIM11 이용해서 사용
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;					// PIN9 설정
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                // AF모드로 사용
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;               // PULL UP 사용
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;              // PUSH-PULL사용
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           // 스피드  50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

	/* Time Base Config  */
    SystemCoreClockUpdate();
    PrescalerValue = (uint16_t) (SystemCoreClock / TIMER_PRESCALER_FREQ) - 1;	// 168000000 / 1000000)에 1MHz 입력

	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;			// 168000000 / 1000000 = 168           
	TIM_TimeBaseStructure.TIM_Period = TIMER_PERIOD;				// 1MHz 마다 Count Up
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;					// Digital filter 및 Dead band 사용안함
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		// Up counter 모드
	TIM_TimeBaseInit(TIM10, &TIM_TimeBaseStructure); 
	TIM_TimeBaseInit(TIM11, &TIM_TimeBaseStructure); 

	/* Input Capture Config  */
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;				// TIM Channel 1 사용
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Falling;	// Pulse의 Falling Edge에서 Capture 발생
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;	// InputCapture를 변경없이 바로 입력
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;			// Pulse가 발생할 때 마다 바로 읽음
    TIM_ICInitStructure.TIM_ICFilter = 0xf;							// Signal Filter 0x0~0xf Noise 클수록 0xf쪽으로

	TIM_ICInit(TIM10, &TIM_ICInitStructure);
	TIM_ICInit(TIM11, &TIM_ICInitStructure);

	/* Interrupt Config  */
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;		// TIM10 인터럽트 핸들러 사용
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;			// 서브 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler사용
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_TIM11_IRQn;	// TIM11 인터럽트 핸들러 사용
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler사용
	NVIC_Init(&NVIC_InitStructure);

	TIM_ITConfig(TIM10, TIM_IT_Update | TIM_IT_CC1, ENABLE);		// 인터럽트 설정
	TIM_Cmd(TIM10, ENABLE);

	TIM_ITConfig(TIM11, TIM_IT_Update | TIM_IT_CC1, ENABLE);		// 인터럽트 설정
	TIM_Cmd(TIM11, ENABLE);
}

void TIM1_UP_TIM10_IRQHandler(void)			// 왼쪽 바퀴 속도값 계산
{
    if (TIM_GetITStatus(TIM10, TIM_IT_Update) == SET)
    {
        TIM_ClearITPendingBit(TIM10, TIM_IT_Update);		// TIM10 Update PendingBit Clear	
        Timer_Update_Cnt_1++;								// Capture값이 Overflow 될 때 마다 1씩 증가
    }
    if (TIM_GetITStatus(TIM10, TIM_IT_CC1) == SET)
    {
		TIM_ClearITPendingBit(TIM10, TIM_IT_CC1);			// TIM10 Capture Compare PendingBit Clear
		Capture_1 = TIM_GetCapture1(TIM10);					// 현재 Capture 값 측정
		Diff_1 = Timer_Update_Cnt_1 * TIMER_PERIOD + Capture_1 - Capture_Prev_1;	// 한 펄스에 몇번 카운트 됐는지  
		Segway_RPM_1 = (float)(60*1000000)/(Diff_1*10);		// RPM = (60*1000000)/(Diff_1*x) -> x는 실험값 10

		if(Segway_RPM_1<0)
			Segway_RPM_1 = Segway_Prev_RPM_1;		// RPM값이 -면 이전RPM값을 현재 RPM값에 대입 
		else 
			Segway_Prev_RPM_1 = Segway_RPM_1;		// RPM값이 +면 현재RPM값을 이전 RPM값에 대입
		
		Capture_Prev_1 = Capture_1;					// 이전 Capture 값에 현재 Capture값을 저장				
		Timer_Update_Cnt_1 = 0;						// Overflow 갯수 초기화
    }
}
void TIM1_TRG_COM_TIM11_IRQHandler(void)	// 오른쪽 바퀴 속도값 계산
{
    if (TIM_GetITStatus(TIM11, TIM_IT_Update) == SET)
    {
        TIM_ClearITPendingBit(TIM11, TIM_IT_Update);		// TIM11 Update PendingBit Clear	
        Timer_Update_Cnt_2++;								// Capture값이 Overflow 될 때 마다 1씩 증가
    }
    if (TIM_GetITStatus(TIM11, TIM_IT_CC1) == SET)
    {
		TIM_ClearITPendingBit(TIM11, TIM_IT_CC1);			// TIM11 Capture Compare PendingBit Clear
		Capture_2 = TIM_GetCapture1(TIM11);					// 현재 Capture 값 측정
		Diff_2 = Timer_Update_Cnt_2 * TIMER_PERIOD + Capture_2 - Capture_Prev_2;	// 한 펄스에 몇번 카운트 됐는지  
		Segway_RPM_2 = (float)(60*1000000)/(Diff_2*10);		// RPM = (60*1000000)/(Diff_2*x) -> x는 실험값 10

		if(Segway_RPM_2<0)
			Segway_RPM_2 = Segway_Prev_RPM_2;		// RPM값이 -면 이전RPM값을 현재 RPM값에 대입 
		else 
			Segway_Prev_RPM_2 = Segway_RPM_2;		// RPM값이 +면 현재RPM값을 이전 RPM값에 대입
		
		Capture_Prev_2 = Capture_2;					// 이전 Capture 값에 현재 Capture값을 저장
		Timer_Update_Cnt_2 = 0;						// Overflow 갯수 초기화
    }
}