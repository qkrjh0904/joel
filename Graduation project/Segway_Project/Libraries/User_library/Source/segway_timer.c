/* Segway_Timer ���� c����*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

int16_t Tim_Prescaler = 84-1;
int16_t Tim_Period = 5000-1;
float Tim_Dt;	// ���� �ֱ�
float Temp;
extern float Output_Right;
extern float Output_Left;
extern float Angle_Pitch, Angle_Roll;
extern char buf[100];

//  PI ���� ����  //
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

//  �̵���� ���� ����  //
int Moving_Average_Filter(int input);

int output;
int data_buf[21]; // �̵���� ���Ϳ� ���Ǵ� �����͸� ����
uint32_t f_volt;
int for_cnt=0;
int n=20;
/************************************************************************/

//  ADC ����  //
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
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;					// TIMEBASE Type ������
	NVIC_InitTypeDef NVIC_InitStructure;							// NVIC Type ������
    
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);			// TIM5 Clock ����
  
	TIM_TimeBaseStructure.TIM_Prescaler = Tim_Prescaler;			// 84MHz/84 = 1MHz
	TIM_TimeBaseStructure.TIM_Period = Tim_Period;					// 0.000001 * 1000 = 0.001 = 1ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		// ��ī��Ʈ ���
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;					// ������ ���� �� dead band�� ���
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);              
	TIM_ITConfig(TIM5,TIM_IT_Update, ENABLE);						// TIM9 ���ͷ�Ʈ ������Ʈ ���
	TIM_Cmd(TIM5,ENABLE);    

	TIM_Dt(Tim_Prescaler, Tim_Period);						// �����ֱ�,���� ��	

	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;					// TIM5 ���ͷ�Ʈ �ڵ鷯 ���
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// �켱���� 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			// ���� �켱���� 0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler���

	NVIC_Init(&NVIC_InitStructure);
}

void TIM_Dt(int16_t Prescaler, int16_t Period)
{
    Temp = (float)1/(84000000/((Prescaler+1)*(Period+1)));
	Tim_Dt = Temp;
}

void TIM5_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM5,TIM_IT_Update)==SET) // ���ͷ�Ʈ �߻��ߴ��� Ȯ�� 
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
 
    	cal_value = (((bb * adc_result)+cc)*10); // ADC ���� 0.1mm ������ ����ϰ� ī���� ������ ��ȯ (0.1mm�� ī���� �� 22)

/****************************************************************************************************/
    
    	/* ���ڴ� �� �ϱ� */
    
    	counter = TIM_GetCounter(TIM2);
    
    	if(counter > 30000)
    	{
    		counter = (-1)*counter + 65536; // ������ ������ ī���Ϳ� ���� ���� -> ���߿����� ���
    		counter_sum -= counter; // ��µ� ��ŭ ī���� ����
    	}
    	else if(counter < 30000)
    	{
    		counter_sum += counter;
    	}

    	counter_cal = (float)counter_sum/2.20429;
    
    	TIM_SetCounter(TIM2, 0); // ī���� �ʱ�ȭ

/****************************************************************************************************/

    	/* 1�ܰ� : �ʱ� ��ġ�� �̵� */
		if(phase == 0)
		{
			/* �ϰ� */
			if(counter_sum > (initial_value+10)) // 2113�� �ʱ� ��ġ�� ���� ī���� ��
			{
				TIM_SetCompare1(TIM1, (uint16_t)2500);
				GPIO_ResetBits(GPIOE, GPIO_Pin_1);
		  	}
		  	/* ��� */
		  	else if(counter_sum < (initial_value-10))
		  	{
				TIM_SetCompare1(TIM1, (uint16_t)2500);
				GPIO_SetBits(GPIOE, GPIO_Pin_1);
		  	}
		 	else // �ʱ� ��ǥ ���� �� ���� �� phase ���� ��ȭ
			{
				TIM_SetCompare1(TIM1, (uint16_t)0);
				phase = 1;
			}
		}

/****************************************************************************************************/
		
		/* 2�ܰ� : ADC ��ȭ���� ���� ��ǥ �� ���� �� ���� ���� */
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
					object = 4630 - cal_value; // ���� �� ��ȭ�� (4752�� ���� ADC ���� ī���ͷ� ��ȯ�� ��)
					delta = (counter_sum - initial_value) - object;
				}
		  	}
		  	else
		  	{
				object = 4630 - cal_value; // ���� �� ��ȭ�� (4752�� ���� ADC ���� ī���ͷ� ��ȯ�� ��)
				delta = (counter_sum - initial_value) - object;
		 	}

		  	PWM_duty = PID_control(delta);
		 	TIM_SetCompare1(TIM1, PWM_duty);

		  	/* �ϰ� */
		 	if(delta > 0)
		  	{
				GPIO_ResetBits(GPIOE, GPIO_Pin_1);
		  	}
		  	/* ��� */
		  	else if(delta < 0)
		  	{
				GPIO_SetBits(GPIOE, GPIO_Pin_1);
		  	}
		  	else // ��ǥ ������ �����ϸ� ����
		  	{
				//TIM_SetCompare1(TIM1, (uint16_t)0);
		  	}
		}
		
		sprintf(buf,"%d\n",delta);		// UART ����
		USART_puts(USART1, buf);
     /**********************************************************/
		// SEA PWM Output    -> Max:5000, Min:0
//		TIM_SetCompare1(TIM1, (uint16_t)1000);
//		TIM_SetCompare2(TIM1, (uint16_t)2000);
//		TIM_SetCompare3(TIM1, (uint16_t)3000);
//		TIM_SetCompare4(TIM1, (uint16_t)4000);

//		SPRINTF(BUF,"%6.2F \N",aNGLE_rOLL);		// uart ����
//		usart_PUTS(usart1, BUF); 
//		flag=1;
	}
}

