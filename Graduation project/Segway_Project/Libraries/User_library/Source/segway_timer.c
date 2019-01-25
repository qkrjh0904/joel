/* Segway_Timer 관련 c파일*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

int16_t Tim_Prescaler = 84-1;
int16_t Tim_Period = 5000-1;
float Tim_Dt;	// 제어 주기
float Temp;
extern float Output_Right;
extern float Output_Left;
extern float Angle_Pitch, Angle_Roll;
extern char buf[100];

//  PI 제어 관련  //
uint16_t PID_control(int value);
uint16_t PID_saturate(uint16_t input, uint16_t min, uint16_t max);

#define Kp 10
#define Ki  0.005
#define MIN 3000
#define MAX 4500

float target_value = 0;
float err, err_sum;
float P_control, I_control;
uint16_t PI_control;
/************************************************************************/

//  이동평균 필터 관련  //
int Moving_Average_Filter(int input);

int output;
int data_buf[21]; // 이동평균 필터에 사용되는 데이터를 저장
uint32_t f_volt;
int for_cnt=0;
int n=20;
/************************************************************************/

//  ADC 관련  //
int adc_initial_value;
int adc_result;
float bb;
float cc;
int cal_value=0;

int object=0;
int delta=0;
uint16_t PWM_duty;

int state;

uint32_t speed;
int phase;
int counter, counter_sum;   //
int counter_cal;
int initial_value =  0; //4465
/************************************************************************/

void TIM5_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;					// TIMEBASE Type 재정의
	NVIC_InitTypeDef NVIC_InitStructure;							// NVIC Type 재정의
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);			// TIM5 Clock 설정
  
	TIM_TimeBaseStructure.TIM_Prescaler = Tim_Prescaler;			// 84MHz/84 = 1MHz
	TIM_TimeBaseStructure.TIM_Period = Tim_Period;					// 0.000001 * 1000 = 0.001 = 1ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		// 업카운트 모드
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;					// 디지털 필터 및 dead band에 사용
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);              
	TIM_ITConfig(TIM5,TIM_IT_Update, ENABLE);						// TIM9 인터럽트 업데이트 사용
	TIM_Cmd(TIM5,ENABLE);    

	TIM_Dt(Tim_Prescaler, Tim_Period);						// 제어주기,적분 값	

	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;					// TIM5 인터럽트 핸들러 사용
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			// 서브 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler사용

	NVIC_Init(&NVIC_InitStructure);
}

void TIM_Dt(int16_t Prescaler, int16_t Period)
{
    Temp = (float)1/(84000000/((Prescaler+1)*(Period+1)));
	Tim_Dt = Temp;
}

void TIM5_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM5,TIM_IT_Update)==SET) // 인터럽트 발생했는지 확인 
	{
		TIM_ClearITPendingBit(TIM5, TIM_IT_Update);	 

		adc_initial_value = (ADC1ConvertedValue[0] * 33000 / 4095);
    
    
		adc_result = Moving_Average_Filter(adc_initial_value);
    
    
		if(adc_result<11000 && adc_result>8428)
		{
			state = 1;
			bb = 0.009652;
			cc = 368.648;
    	}
    	else if(adc_result<8428 && adc_result>2455)
    	{
   			state = 2;
   			bb = 0.00977;
    		cc = 377.48494;
    	}
   		else if(adc_result<2455 && adc_result>1358)
    	{
   	    	state = 3;
   			bb = 0.21239;
    		cc = -119.92935;
    	}
    
    	else
    	{
    		state = 0;
    	}
 
    	cal_value = (((bb * adc_result)+cc)*10); // ADC 값을 0.1mm 단위로 계산하고 카운터 단위로 변환 (0.1mm당 카운터 수 22)

/****************************************************************************************************/
    
    	/* 엔코더 값 일기 */
    
    	counter = TIM_GetCounter(TIM2);
    
    	if(counter > 30000)
    	{
    		counter = (-1)*counter + 65536; // 모터의 역방향 카운터에 대한 연산 -> 액추에이터 상승
    		counter_sum -= counter; // 상승된 만큼 카운터 증가
    	}
    	else if(counter < 30000)
    	{
    		counter_sum += counter;
    	}

    	counter_cal = (float)counter_sum/2.20429;
    
    	TIM_SetCounter(TIM2, 0); // 카운터 초기화

/****************************************************************************************************/

    	/* 1단계 : 초기 위치로 이동 */
		if(phase == 0)
		{
			/* 하강 */
			if(counter_sum > (initial_value+10)) // 2113은 초기 위치에 대한 카운터 값
			{
				TIM_SetCompare1(TIM1, (uint16_t)2500);
				GPIO_ResetBits(GPIOE, GPIO_Pin_1);
		  	}
		  	/* 상승 */
		  	else if(counter_sum < (initial_value-10))
		  	{
				TIM_SetCompare1(TIM1, (uint16_t)2500);
				GPIO_SetBits(GPIOE, GPIO_Pin_1);
		  	}
		 	else // 초기 목표 도달 시 정지 후 phase 값을 변화
			{
				TIM_SetCompare1(TIM1, (uint16_t)0);
				phase = 1;
			}
		}

/****************************************************************************************************/
		
		/* 2단계 : ADC 변화량을 통해 목표 값 설정 후 높이 보상 */
		else if (phase == 1)
		{
			if(cal_value > 4630)
			{
				if(delta > -50 && delta < 50)
				{
					delta = 0;
					object = 0;
				}
				else
				{
					object = 4630 - cal_value; // 센서 값 변화량 (4752는 기준 ADC 값을 카운터로 변환한 값)
					delta = (counter_sum - initial_value) - object;
				}
		  	}
		  	else
		  	{
				object = 4630 - cal_value; // 센서 값 변화량 (4752는 기준 ADC 값을 카운터로 변환한 값)
				delta = (counter_sum - initial_value) - object;
		 	}

		  	PWM_duty = PID_control(delta);
		 	TIM_SetCompare1(TIM1, PWM_duty);

		  	/* 하강 */
		 	if(delta > 0)
		  	{
				GPIO_ResetBits(GPIOE, GPIO_Pin_1);
		  	}
		  	/* 상승 */
		  	else if(delta < 0)
		  	{
				GPIO_SetBits(GPIOE, GPIO_Pin_1);
		  	}
		  	else // 목표 범위에 도착하면 정지
		  	{
				//TIM_SetCompare1(TIM1, (uint16_t)0);
		  	}
		}
		
		sprintf(buf,"%d\n",delta);		// UART 사용법
		USART_puts(USART1, buf);
     /**********************************************************/
		// SEA PWM Output    -> Max:5000, Min:0
//		TIM_SetCompare1(TIM1, (uint16_t)1000);
//		TIM_SetCompare2(TIM1, (uint16_t)2000);
//		TIM_SetCompare3(TIM1, (uint16_t)3000);
//		TIM_SetCompare4(TIM1, (uint16_t)4000);

//		SPRINTF(BUF,"%6.2F \N",aNGLE_rOLL);		// uart 사용법
//		usart_PUTS(usart1, BUF); 
//		flag=1;
	}
}

