#include <stm32f4xx.h>
#include <stdio.h>
#include "math.h"

void TIM5_Config(void);
void USART1_Config(void);
void ADC_Config(void);

//  시스템 제어 관련  //
int16_t Tim_Prescaler = 840-1;
int16_t Tim_Period = 10000-1;

float Sensor_Data;

//  USART1 관련  //
char buf[100];
void USART_puts(USART_TypeDef* USARTx, volatile char *s);

int main(void)
{
  ADC_Config();
  USART1_Config();
  TIM5_Config();
  
 while(1)
 {
 }
}

//////////////////////////// 시스템 제어주기 설정 /////////////////////////////
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
	TIM_ITConfig(TIM5,TIM_IT_Update, ENABLE);						// TIM5 인터럽트 업데이트 사용
	TIM_Cmd(TIM5,ENABLE);    	
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;					// TIM5 인터럽트 핸들러 사용
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			// 서브 우선순위 0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler사용+

	NVIC_Init(&NVIC_InitStructure);
}

//////////////////////////// 제어 타이머 (1ms) /////////////////////////////
void TIM5_IRQHandler()
{
  if(TIM_GetITStatus(TIM5, TIM_IT_Update) == SET)
  {
        /* Start ADC1 Software Conversion */
	ADC_SoftwareStartConv(ADC1);
        
        if(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == SET)
        {
            Sensor_Data = ADC_GetConversionValue(ADC1);
        }
        
        TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
  }
}

/////////////////////////// Uart 관련 함수 ///////////////////////////////
void USART1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;                    // GPIO  Type 재정의     
	USART_InitTypeDef USART_InitStructure;                  // USART Type 재정의
	NVIC_InitTypeDef NVIC_InitStructure;                    // NVIC Type 재정의  

	/* Peripheral Clock Config */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);   // PORTA  사용
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);  // USART1 사용

	/* Gpio Config */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  // Tx 
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); // Rx 
   
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;           // USART1_TX 핀설정
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;         // 대체기능 사용
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         // 내부풀업 사용
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        // 출력 타입 Push Poll
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    // 출력 스피드 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;          // USART1_RX 핀설정
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;         // 대체기능 사용
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         // 내부풀업 사용
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        // 출력 타입 Push Poll
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    // 출력 스피드 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Interrupt Config*/ 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Usart Config */
	USART_InitStructure.USART_BaudRate   = 115200;                                   // 보레이트 설정
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;                      // 길이 8bit
	USART_InitStructure.USART_StopBits   = USART_StopBits_1;                         // stop bit 1
	USART_InitStructure.USART_Parity     = USART_Parity_No ;                         // parity 사용안함
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  // 흐름제어 사용안함
	USART_InitStructure.USART_Mode       = USART_Mode_Rx | USART_Mode_Tx;            // 모드 Rx/Tx 설정
	
	USART_Init(USART1, &USART_InitStructure);  // UART1에 설정 저장                                    
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART1, ENABLE);

}

void USART_puts(USART_TypeDef* USARTx, volatile char *s)
{
	while(*s)	// wait until data register is empty
	{
		while( !(USARTx->SR & 0x00000040) );
		USART_SendData(USARTx, *s);
		*s++;
	}
//	sprintf(buf,"%d %d \n",aa, value_sum);		// UART 사용법
//	USART_puts(USART1, buf); 

}

void ADC_Config(void)
{
        ADC_InitTypeDef ADC_InitStruct;
        ADC_CommonInitTypeDef ADC_CommonInitStruct;
        GPIO_InitTypeDef GPIO_InitStructure;
        
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);		// GPIOA AHB1 Clock Enable
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);		// ADC1  APB2 Clock Enable
        
        /* Gpio Config */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	// PIN3,PIN4,PIN5,PIN6 설정
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;					// Analog Input 모드 사용
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;				// PULL UP,PULL DOWN 사용안함
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					// PULL UP 사용
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;				// 스피드 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);


        /* Adc Common Config */
	ADC_CommonInitStruct.ADC_Mode = ADC_Mode_Independent;			// ADC 독립모드		
	ADC_CommonInitStruct.ADC_Prescaler = ADC_Prescaler_Div4;		// ADC 2분주
	ADC_CommonInitStruct.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;		// Multi ADC DMA모드 사용안함
	ADC_CommonInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_10Cycles;	// Sampling Delay 5Cycle 
	ADC_CommonInit(&ADC_CommonInitStruct);
        
        /* Adc Config */
	ADC_DeInit();
	ADC_InitStruct.ADC_Resolution = ADC_Resolution_12b;				// ADC 분해능 12Bit
	ADC_InitStruct.ADC_ScanConvMode = ENABLE;						// Scan 모트 사용
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;					// Continuous 모드 사용
	ADC_InitStruct.ADC_ExternalTrigConv = 0;						// 외부 Trigger Conversion 사용안함
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;	// 외부 Trigger Conversion 사용안함
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;				// 데이터 오른쪽 정렬
	ADC_InitStruct.ADC_NbrOfConversion = 5;							// ADC 변환 갯수 
	ADC_Init(ADC1, &ADC_InitStruct);
        
        ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 1, ADC_SampleTime_112Cycles);		// GPIOE_Pin_1
        
        ADC_Cmd(ADC1, ENABLE);

	
}
        