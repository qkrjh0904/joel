/* Segway_Usart 관련 c파일*/
#include "stm32f4xx.h"
#include "segway_header.h"
#include <stdio.h>
#include <math.h>

char buf[100];

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
//	sprintf(buf,"%d \n",i);		// UART 사용법
//	USART_puts(USART1, buf); 

}
