/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2007; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                            EXAMPLE CODE
*
*                                     ST Microelectronics STM32
*                                              on the
*
*                                     Micrium uC-Eval-STM32F107
*                                        Evaluation Board
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : JJL
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <includes.h>
#include <app_cfg.h>
#include <lcd.h>
#include <bsp.h>
#include <os.h>
#include "stm32f10x.h"

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           LOCAL VARIABLES
*********************************************************************************************************
*/

static  OS_TCB   AppTaskStartTCB; 
static  OS_TCB   AppTask1_TCB;
static  OS_TCB   AppTask2_TCB;
//static  OS_TCB   AppTask3_TCB;

static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];
static  CPU_STK  AppTask1_Stk[128];
static  CPU_STK  AppTask2_Stk[128];
//static  CPU_STK  AppTask3_Stk[128];

 int k =0;
int BS_1=0;
int BS_2=0;
int BS_3=0;
int distance =0;
 __IO uint32_t ADC_DualConvertedValueTab[4];
 
ADC_InitTypeDef ADC_InitStructure;
GPIO_InitTypeDef myGPIO;
DMA_InitTypeDef DMA_InitStructure;

/*
*********************************************************************************************************
*                                                STACKS
*********************************************************************************************************
*/

static  CPU_STK         AppTaskStartStk[APP_TASK_START_STK_SIZE];


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  OS_SEM   AppSem; 
static  void  AppTaskStart (void *p_arg);
static  void  AppTaskCreate1  (void);
static  void  AppTaskCreate2  (void);
//static  void  AppTaskCreate3  (void);
static  void  AppTask1  (void *p_arg);
static  void  AppTask2  (void *p_arg);
//static  void  AppTask3  (void *p_arg);

/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Arguments   : none
*
* Returns     : none
*********************************************************************************************************
*/

void init_port() {
    
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE); // RCC GPIO D
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); // RCC GPIO C
    
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE); // ADC1 동작
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    
    myGPIO.GPIO_Pin= 0x009E;     //0b 0000 0111 0000 0000 (2,3,4 번 핀 사용. )
    myGPIO.GPIO_Mode = GPIO_Mode_Out_PP;
    myGPIO.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &myGPIO);
    
    myGPIO.GPIO_Pin= GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4; 
    myGPIO.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOC, &myGPIO);
    
    //ADC_InitStructure 초기화
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = ENABLE; 
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 4;
    //ADC1 Channel 및 Sampling Time 설정(ADC1의 7번 채널을 이용하고, 55.5cycle로 설정)
    ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 2, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 3, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 4, ADC_SampleTime_55Cycles5);
    ADC_Init(ADC1, &ADC_InitStructure);
    ADC_DMACmd(ADC1, ENABLE);

    //NVIC configuration
    /*NVIC_InitTypeDef NVIC_init;
    NVIC_init.NVIC_IRQChannel = ENABLE;
    NVIC_init.NVIC_IRQChannelCmd = ENABLE;
    NVIC_init.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_init.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVIC_init);*/
    
    //DMA1 channel1 configuration -----
    DMA_DeInit(DMA1_Channel1);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADC_DualConvertedValueTab;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = 4;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word; // 32bit
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word; // 32bit
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    // Enable DMA1 Channel1
    DMA_Cmd(DMA1_Channel1, ENABLE);
    
    //ADC1 채널 Calibration
    //ADC1 Calibration reset. 
    ADC_Cmd(ADC1, ENABLE);
    
    ADC_ResetCalibration(ADC1);
    while(ADC_GetResetCalibrationStatus(ADC1)); //end of ADC1 체크
    //ADC1 Calibration start.
    ADC_StartCalibration(ADC1);
    while(ADC_GetCalibrationStatus(ADC1));      //end of ADC1 체크

    ADC_Cmd(ADC1, ENABLE);
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);                                                        
}


int  main (void)
{
    OS_ERR  err;
    unsigned int i=0;
    init_port();
    
    OSInit(&err);                                               /* Init uC/OS-III.                                      */
    
    LCD_Configuration();
    LCD_Init();
    
   while (1) 
  {
        BS_1 = (ADC_DualConvertedValueTab[0]-400)*10/1800;
        BS_2 = (ADC_DualConvertedValueTab[1]-1500)*10/1100;
        BS_3 = (ADC_DualConvertedValueTab[2]-1500)*10/1100;
        distance = ((ADC_DualConvertedValueTab[3]-3000)*10-5000)*10/5000;
       // BS check :  (int)ADC_DualConvertedValueTab[0]
        if(BS_3 > 2){
          GPIOD->BSRR = GPIO_Pin_1;
          if(BS_1 <= 2 && BS_2 <= 2){
            GPIOD->BSRR = GPIO_Pin_2;
            GPIOD->BRR = GPIO_Pin_3;
            GPIOD->BSRR = GPIO_Pin_4;
            GPIOD->BRR = GPIO_Pin_7;
            //OSTimeDly (1, OS_OPT_TIME_DLY, &err); // move forward
          }else if(BS_1 <= 2 && BS_2 > 2){
            GPIOD->BSRR = GPIO_Pin_2;
            GPIOD->BRR = GPIO_Pin_3;
            GPIOD->BRR = GPIO_Pin_4;
            GPIOD->BSRR = GPIO_Pin_7;
            //OSTimeDly (1, OS_OPT_TIME_DLY, &err); // move right
          }else if(BS_1 > 2 && BS_2 <= 2){
            GPIOD->BRR = GPIO_Pin_2;
            GPIOD->BSRR = GPIO_Pin_3;
            GPIOD->BSRR = GPIO_Pin_4;
            GPIOD->BRR = GPIO_Pin_7;
            //OSTimeDly (1, OS_OPT_TIME_DLY, &err); // move left
          }else if(BS_1 > 2 && BS_2 >  2){
            GPIOD->BRR = GPIO_Pin_2;
            GPIOD->BRR = GPIO_Pin_3;
            GPIOD->BRR = GPIO_Pin_4;
            GPIOD->BRR = GPIO_Pin_7;
            //OSTimeDly (1, OS_OPT_TIME_DLY, &err); // stop
          }
        }else{
          GPIOD->BSRR = GPIO_Pin_1;
          GPIOD->BRR = GPIO_Pin_2;
          GPIOD->BRR = GPIO_Pin_3;
          GPIOD->BRR = GPIO_Pin_4;
          GPIOD->BRR = GPIO_Pin_7;
          
          char abc[18] = "119 CONNECTING...";
            const char *Interrupted = &abc[0];
    
            for(int i=0; i<3; i++){
              LCD_Clear(BLACK);
              GPIOD->BRR = GPIO_Pin_1;
              LCD_ShowCharString(55, 240, Interrupted, RED, WHITE);
              LCD_ShowCharString(63, 240, Interrupted+1, RED, WHITE);
              LCD_ShowCharString(71, 240, Interrupted+2, RED, WHITE);
              LCD_ShowCharString(79, 240, Interrupted+3, RED, WHITE);
              LCD_ShowCharString(87, 240, Interrupted+4, RED, WHITE);
              LCD_ShowCharString(95, 240, Interrupted+5, RED, WHITE);
              LCD_ShowCharString(103, 240, Interrupted+6, RED, WHITE);
              LCD_ShowCharString(111, 240, Interrupted+7, RED, WHITE);
              LCD_ShowCharString(119, 240, Interrupted+8, RED, WHITE);
              LCD_ShowCharString(127, 240, Interrupted+9, RED, WHITE);
              LCD_ShowCharString(135, 240, Interrupted+10, RED, WHITE);
              LCD_ShowCharString(143, 240, Interrupted+11, RED, WHITE);
              LCD_ShowCharString(151, 240, Interrupted+12, RED, WHITE);
              LCD_ShowCharString(159, 240, Interrupted+13, RED, WHITE);
              LCD_ShowCharString(167, 240, Interrupted+14, RED, WHITE);
              LCD_ShowCharString(175, 240, Interrupted+15, RED, WHITE);
              LCD_ShowCharString(183, 240, Interrupted+16, RED, WHITE);
              LCD_DrawRectangle(60, 110, 178, 160);
              LCD_Fill(60, 110, 178, 160, GREEN);
              LCD_DrawRectangle(94, 76, 144, 194);
              LCD_Fill(94, 76, 144, 194, GREEN);
              GPIOD->BSRR = GPIO_Pin_1;
          }
          LCD_Clear(BLACK);
        }
        for(i=0; i<50000 ; i++);

        char bs1[5] = "BS1:";
        const char *bending_1 = &bs1[0];
        char bs2[5] = "BS2:";
        const char *bending_2 = &bs2[0];
        char bs3[5] = "BS3:";
        const char *bending_3 = &bs3[0];
        char dis[10] = "Distance:";
        const char *Interrupted_1 = &dis[0];
    
        char danger[2] = "!";
        const char *Interrupted_2 = &danger[0];
        
    
        LCD_ShowCharString(70, 124, bending_1, WHITE, RED);
        LCD_ShowCharString(78, 124, bending_1+1, WHITE, RED);
        LCD_ShowCharString(86, 124, bending_1+2, WHITE, RED);
        LCD_ShowCharString(94, 124, bending_1+3, WHITE, RED);
        LCD_ShowNum(102, 124, BS_1, 5, WHITE, RED);
        
        LCD_ShowCharString(70, 94, bending_2, WHITE, RED);
        LCD_ShowCharString(78, 94, bending_2+1, WHITE, RED);
        LCD_ShowCharString(86, 94, bending_2+2, WHITE, RED);
        LCD_ShowCharString(94, 94, bending_2+3, WHITE, RED);
        LCD_ShowNum(102, 94, BS_2, 5, WHITE, RED);
        
        LCD_ShowCharString(70, 184, bending_3, WHITE, RED);
        LCD_ShowCharString(78, 184, bending_3+1, WHITE, RED);
        LCD_ShowCharString(86, 184, bending_3+2, WHITE, RED);
        LCD_ShowCharString(94, 184, bending_3+3, WHITE, RED);
        LCD_ShowNum(102, 184, BS_3, 5, WHITE, RED);
      
     

      if(distance > 5){
        LCD_ShowCharString(70, 154, Interrupted_1, WHITE, RED);
        LCD_ShowCharString(78, 154, Interrupted_1+1, WHITE, RED);
        LCD_ShowCharString(86, 154, Interrupted_1+2, WHITE, RED);
        LCD_ShowCharString(94, 154, Interrupted_1+3, WHITE, RED);
        LCD_ShowCharString(102, 154, Interrupted_1+4, WHITE, RED);
        LCD_ShowCharString(110, 154, Interrupted_1+5, WHITE, RED);
        LCD_ShowCharString(118, 154, Interrupted_1+6, WHITE, RED);
        LCD_ShowCharString(126, 154, Interrupted_1+7, WHITE, RED);
        LCD_ShowCharString(134, 154, Interrupted_1+8, WHITE, RED);
        LCD_ShowNum(142, 154, distance, 5, WHITE, RED);
        k = 0;
        for(int i = 1 ; i < 29; i++){
          k = k + 8;
          LCD_ShowCharString(k , 0 , Interrupted_2, BLACK, YELLOW);
        } k = 0;
        for(int j = 1; j < 20 ; j++){
          LCD_ShowCharString(232 , k , Interrupted_2, BLACK, YELLOW);
          k = k + 16;
        } k = 232;
        for(int i = 1 ; i < 31; i++){
          LCD_ShowCharString(k , 304 , Interrupted_2, BLACK, YELLOW);
          k = k - 8;
        } k = 304;
        for(int j = 1; j < 20 ; j++){
          k = k - 16;
          LCD_ShowCharString(0 , k , Interrupted_2, BLACK, YELLOW);
        }
        GPIOD->BRR = GPIO_Pin_1;
        k = 1;
        for(i=0; i<50000 ; i++);
      }else if(distance <=5 && k == 1){
        GPIOD->BSRR = GPIO_Pin_1;
        LCD_Clear(BLACK);
        LCD_ShowCharString(70, 154, Interrupted_1, WHITE, RED);
        LCD_ShowCharString(78, 154, Interrupted_1+1, WHITE, RED);
        LCD_ShowCharString(86, 154, Interrupted_1+2, WHITE, RED);
        LCD_ShowCharString(94, 154, Interrupted_1+3, WHITE, RED);
        LCD_ShowCharString(102, 154, Interrupted_1+4, WHITE, RED);
        LCD_ShowCharString(110, 154, Interrupted_1+5, WHITE, RED);
        LCD_ShowCharString(118, 154, Interrupted_1+6, WHITE, RED);
        LCD_ShowCharString(126, 154, Interrupted_1+7, WHITE, RED);
        LCD_ShowCharString(134, 154, Interrupted_1+8, WHITE, RED);
        LCD_ShowNum(142, 154, distance, 5, WHITE, RED);
        for(i=0; i<50000 ; i++);
        k = 0;
      }else{
        LCD_ShowCharString(70, 154, Interrupted_1, WHITE, RED);
        LCD_ShowCharString(78, 154, Interrupted_1+1, WHITE, RED);
        LCD_ShowCharString(86, 154, Interrupted_1+2, WHITE, RED);
        LCD_ShowCharString(94, 154, Interrupted_1+3, WHITE, RED);
        LCD_ShowCharString(102, 154, Interrupted_1+4, WHITE, RED);
        LCD_ShowCharString(110, 154, Interrupted_1+5, WHITE, RED);
        LCD_ShowCharString(118, 154, Interrupted_1+6, WHITE, RED);
        LCD_ShowCharString(126, 154, Interrupted_1+7, WHITE, RED);
        LCD_ShowCharString(134, 154, Interrupted_1+8, WHITE, RED);
        LCD_ShowNum(142, 154, distance, 5, WHITE, RED);
      }
    
  }
    
    
    

    OSSchedRoundRobinCfg((CPU_BOOLEAN)DEF_TRUE,
                         (OS_TICK    )10,
                         (OS_ERR    *)&err);
    
    OSTaskCreate((OS_TCB     *)&AppTaskStartTCB,                /* Create the start task                                */
                 (CPU_CHAR   *)"App Task Start",
                 (OS_TASK_PTR )AppTaskStart, 
                 (void       *)0,
                 (OS_PRIO     )APP_TASK_START_PRIO,
                 (CPU_STK    *)&AppTaskStartStk[0],
                 (CPU_STK_SIZE)APP_TASK_START_STK_SIZE / 10,
                 (CPU_STK_SIZE)APP_TASK_START_STK_SIZE,
                 (OS_MSG_QTY  )0,
                 (OS_TICK     )0,
                 (void       *)0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);

    OSStart(&err);                                              /* Start multitasking (i.e. give control to uC/OS-III). */
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'AppTaskStart()' by 'OSTaskCreate()'.
*
* Returns     : none
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  AppTaskStart (void *p_arg)
{
    p_arg = p_arg;
    CPU_INT32U  cpu_clk_freq;
    CPU_INT32U  cnts;
    OS_ERR      err;
    
   (void)p_arg;
   
    OSSemCreate(&AppSem, "Test Sem", 0, &err);
   
    CPU_Init();

    cpu_clk_freq = BSP_CPU_ClkFreq();
    cnts         = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;/* Determine nbr SysTick increments                         */
    OS_CPU_SysTickInit(cnts);                                   /* Init uC/OS periodic time src (SysTick).                  */
    
#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running                */
#endif

    CPU_IntDisMeasMaxCurReset();
    
  
 // make code...  
    
    
    
    AppTaskCreate1();                                            /* Create application tasks                                 */
    AppTaskCreate2();
    //AppTaskCreate3();
      
    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.           */
        OSTimeDlyHMSM(0, 0, 0, 250, 
                      OS_OPT_TIME_HMSM_STRICT, 
                      &err);
    }
}


/*
*********************************************************************************************************
*                                      CREATE APPLICATION TASKS
*
* Description:  This function creates the application tasks.
*
* Arguments  :  none
*
* Returns    :  none
*********************************************************************************************************
*/

static  void  AppTaskCreate1 (void)
{
    OS_ERR  err;
    OSTaskCreate((OS_TCB     *)&AppTask1_TCB,                   
                 (CPU_CHAR   *)"App Task 1",
                 (OS_TASK_PTR )AppTask1, 
                 (void       *)0,
                 (OS_PRIO     )3,
                 (CPU_STK    *)&AppTask1_Stk[0],
                 (CPU_STK_SIZE)128/ 10,
                 (CPU_STK_SIZE)128,
                 (OS_MSG_QTY  )0,
                 (OS_TICK     )0,
                 (void       *)0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
    
}

static void AppTask1 (void *p_arg){
  OS_ERR err;
  p_arg = p_arg;
  unsigned int i;
    while (1) 
    {
      
    }
}



static  void  AppTaskCreate2 (void)
{
    OS_ERR  err;
    OSTaskCreate((OS_TCB     *)&AppTask2_TCB,                   
                 (CPU_CHAR   *)"App Task 2",
                 (OS_TASK_PTR )AppTask2, 
                 (void       *)0,
                 (OS_PRIO     )3,
                 (CPU_STK    *)&AppTask2_Stk[0],
                 (CPU_STK_SIZE)128/ 10,
                 (CPU_STK_SIZE)128,
                 (OS_MSG_QTY  )0,
                 (OS_TICK     )0,
                 (void       *)0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
}

static void AppTask2 (void *p_arg){
  OS_ERR err;
  p_arg = p_arg;
  OSTaskTimeQuantaSet(&AppTask2_TCB,3,&err);
  /*distance below 20 -> warning, and if distance is increase, disappear warning
   and show normal distance display*/
  int distance = 19;  
  int k;
    while(1){/*
      if(distance < 20){
        LCD_ShowCharString(70, 154, Interrupted_1, WHITE, RED);
        LCD_ShowCharString(78, 154, Interrupted_1+1, WHITE, RED);
        LCD_ShowCharString(86, 154, Interrupted_1+2, WHITE, RED);
        LCD_ShowCharString(94, 154, Interrupted_1+3, WHITE, RED);
        LCD_ShowCharString(102, 154, Interrupted_1+4, WHITE, RED);
        LCD_ShowCharString(110, 154, Interrupted_1+5, WHITE, RED);
        LCD_ShowCharString(118, 154, Interrupted_1+6, WHITE, RED);
        LCD_ShowCharString(126, 154, Interrupted_1+7, WHITE, RED);
        LCD_ShowCharString(134, 154, Interrupted_1+8, WHITE, RED);
        LCD_ShowNum(142, 154, distance, 5, WHITE, RED);
        k = 0;
        for(int i = 1 ; i < 29; i++){
          k = k + 8;
          LCD_ShowCharString(k , 0 , Interrupted_2, BLACK, YELLOW);
        } k = 0;
        for(int j = 1; j < 20 ; j++){
          LCD_ShowCharString(232 , k , Interrupted_2, BLACK, YELLOW);
          k = k + 16;
        } k = 232;
        for(int i = 1 ; i < 31; i++){
          LCD_ShowCharString(k , 304 , Interrupted_2, BLACK, YELLOW);
          k = k - 8;
        } k = 304;
        for(int j = 1; j < 20 ; j++){
          k = k - 16;
          LCD_ShowCharString(0 , k , Interrupted_2, BLACK, YELLOW);
        } k = 1;
      }else if(distance >=20 && k == 1){ 
        LCD_Clear(BLACK);
        LCD_ShowCharString(70, 154, Interrupted_1, WHITE, RED);
        LCD_ShowCharString(78, 154, Interrupted_1+1, WHITE, RED);
        LCD_ShowCharString(86, 154, Interrupted_1+2, WHITE, RED);
        LCD_ShowCharString(94, 154, Interrupted_1+3, WHITE, RED);
        LCD_ShowCharString(102, 154, Interrupted_1+4, WHITE, RED);
        LCD_ShowCharString(110, 154, Interrupted_1+5, WHITE, RED);
        LCD_ShowCharString(118, 154, Interrupted_1+6, WHITE, RED);
        LCD_ShowCharString(126, 154, Interrupted_1+7, WHITE, RED);
        LCD_ShowCharString(134, 154, Interrupted_1+8, WHITE, RED);
        LCD_ShowNum(142, 154, distance, 5, WHITE, RED);
      k = 0;
      }else{
        LCD_ShowCharString(70, 154, Interrupted_1, WHITE, RED);
        LCD_ShowCharString(78, 154, Interrupted_1+1, WHITE, RED);
        LCD_ShowCharString(86, 154, Interrupted_1+2, WHITE, RED);
        LCD_ShowCharString(94, 154, Interrupted_1+3, WHITE, RED);
        LCD_ShowCharString(102, 154, Interrupted_1+4, WHITE, RED);
        LCD_ShowCharString(110, 154, Interrupted_1+5, WHITE, RED);
        LCD_ShowCharString(118, 154, Interrupted_1+6, WHITE, RED);
        LCD_ShowCharString(126, 154, Interrupted_1+7, WHITE, RED);
        LCD_ShowCharString(134, 154, Interrupted_1+8, WHITE, RED);
        LCD_ShowNum(142, 154, distance, 5, WHITE, RED);
      }
    distance = 56789;
    */}
    //finished..
}



/*static  void  AppTaskCreate3 (void)
{
    OS_ERR  err;
    
   OSTaskCreate((OS_TCB     *)&AppTask3_TCB,                   
                 (CPU_CHAR   *)"App Task 3",
                 (OS_TASK_PTR )AppTask3, 
                 (void       *)0,
                 (OS_PRIO     )3,
                 (CPU_STK    *)&AppTask3_Stk[0],
                 (CPU_STK_SIZE)128/ 10,
                 (CPU_STK_SIZE)128,
                 (OS_MSG_QTY  )0,
                 (OS_TICK     )0,
                 (void       *)0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
}

 
static void AppTask3 (void *p_arg){
  OS_ERR err;
  p_arg = p_arg;
  OSTaskTimeQuantaSet(&AppTask3_TCB,4,&err);
  while (1) {
   
  }
}*/


        