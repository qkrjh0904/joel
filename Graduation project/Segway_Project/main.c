#include <stm32f4xx.h>
#include <stdio.h>
#include "math.h"

void TIM5_Config(void);
void USART1_Config(void);
void ADC_Config(void);

//  �ý��� ���� ����  //
int16_t Tim_Prescaler = 840-1;
int16_t Tim_Period = 10000-1;

float Sensor_Data;

//  USART1 ����  //
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

//////////////////////////// �ý��� �����ֱ� ���� /////////////////////////////
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
	TIM_ITConfig(TIM5,TIM_IT_Update, ENABLE);						// TIM5 ���ͷ�Ʈ ������Ʈ ���
	TIM_Cmd(TIM5,ENABLE);    	
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;					// TIM5 ���ͷ�Ʈ �ڵ鷯 ���
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	// �켱���� 0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			// ���� �켱���� 0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// IRQHandler���+

	NVIC_Init(&NVIC_InitStructure);
}

//////////////////////////// ���� Ÿ�̸� (1ms) /////////////////////////////
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

/////////////////////////// Uart ���� �Լ� ///////////////////////////////
void USART1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;                    // GPIO  Type ������     
	USART_InitTypeDef USART_InitStructure;                  // USART Type ������
	NVIC_InitTypeDef NVIC_InitStructure;                    // NVIC Type ������  

	/* Peripheral Clock Config */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);   // PORTA  ���
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);  // USART1 ���

	/* Gpio Config */  
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);  // Tx 
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1); // Rx 
   
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;           // USART1_TX �ɼ���
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;         // ��ü��� ���
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         // ����Ǯ�� ���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        // ��� Ÿ�� Push Poll
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    // ��� ���ǵ� 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;          // USART1_RX �ɼ���
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;         // ��ü��� ���
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         // ����Ǯ�� ���
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        // ��� Ÿ�� Push Poll
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;    // ��� ���ǵ� 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Interrupt Config*/ 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Usart Config */
	USART_InitStructure.USART_BaudRate   = 115200;                                   // ������Ʈ ����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;                      // ���� 8bit
	USART_InitStructure.USART_StopBits   = USART_StopBits_1;                         // stop bit 1
	USART_InitStructure.USART_Parity     = USART_Parity_No ;                         // parity ������
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  // �帧���� ������
	USART_InitStructure.USART_Mode       = USART_Mode_Rx | USART_Mode_Tx;            // ��� Rx/Tx ����
	
	USART_Init(USART1, &USART_InitStructure);  // UART1�� ���� ����                                    
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
//	sprintf(buf,"%d %d \n",aa, value_sum);		// UART ����
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
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	// PIN3,PIN4,PIN5,PIN6 ����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;					// Analog Input ��� ���
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;				// PULL UP,PULL DOWN ������
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					// PULL UP ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;				// ���ǵ� 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);


        /* Adc Common Config */
	ADC_CommonInitStruct.ADC_Mode = ADC_Mode_Independent;			// ADC �������		
	ADC_CommonInitStruct.ADC_Prescaler = ADC_Prescaler_Div4;		// ADC 2����
	ADC_CommonInitStruct.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;		// Multi ADC DMA��� ������
	ADC_CommonInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_10Cycles;	// Sampling Delay 5Cycle 
	ADC_CommonInit(&ADC_CommonInitStruct);
        
        /* Adc Config */
	ADC_DeInit();
	ADC_InitStruct.ADC_Resolution = ADC_Resolution_12b;				// ADC ���ش� 12Bit
	ADC_InitStruct.ADC_ScanConvMode = ENABLE;						// Scan ��Ʈ ���
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;					// Continuous ��� ���
	ADC_InitStruct.ADC_ExternalTrigConv = 0;						// �ܺ� Trigger Conversion ������
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;	// �ܺ� Trigger Conversion ������
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;				// ������ ������ ����
	ADC_InitStruct.ADC_NbrOfConversion = 5;							// ADC ��ȯ ���� 
	ADC_Init(ADC1, &ADC_InitStruct);
        
        ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 1, ADC_SampleTime_112Cycles);		// GPIOE_Pin_1
        
        ADC_Cmd(ADC1, ENABLE);

	
}
        