/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

* 文件名  ：led
* 作者    ：xuxinjie
* 版本    ：V0.0.1
* 时间    ：2020/10/20
* 描述    ：led驱动文件
********************************************************************
* 副本
*
*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* 头文件 ----------------------------------------------------------------*/
#include "led.h"
/* 宏定义 ----------------------------------------------------------------*/
//D1 D2 D3 P1_0 P1_1 P1_4
#define LED1 P1_0
#define LED2 P1_1
#define LED3 P1_4
#define LED_ON 0
#define LED_OFF 1
/* 结构体或枚举 ----------------------------------------------------------------*/
/* 内部函数声明 ----------------------------------------------------------------*/






/* 函数 ----------------------------------------------------------------*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

* 函数名  ：LedInit
* 参数    ：void
* 返回    ：void
* 作者    ：xuxinjie
* 时间    ：2020/10/20
* 描述    ：Led初始化
----------------------------------------------------------------*/
void LedInit(void)
{
  //P1SEL对应位设置为通用IO(清零）
   P1SEL &= 0xEC;
  //P1对应位设置为输出（置1）
   P1DIR |= 0x13;
   //让所有灯都关掉
    P1 |= 0x13;
   
  
  
}



/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

* 函数名  ：LedOn
* 参数    ：unsigned char ucLedNum 0 所以灯亮;  1 D1亮; 2 D2亮； 3 D3亮
* 返回    ：void
* 作者    ：xuxinjie
* 时间    ：2020/10/17
* 描述    ：开灯
----------------------------------------------------------------*/
void  LedOn(unsigned char ucLedNum)
{
  if( LED_ALL_E == ucLedNum )
  {
    LED1 = LED_ON;
    LED2 = LED_ON;
    LED3 = LED_ON;
  }
  else if ( LED_LED1_E == ucLedNum)
  {
    LED1 =LED_ON;
  
  }
   else if ( LED_LED2_E == ucLedNum)
  {
    LED2 =LED_ON;
  
  }
   else if ( LED_LED3_E == ucLedNum)
  {
    LED3 =LED_ON;
  
  }
  else
  {
    //do nothing
  }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

* 函数名  ：LedOff
* 参数    ：unsigned char ucLedNum
* 返回    ：void
* 作者    ：xuxinjie
* 时间    ：2020/10/20
* 描述    ：关灯
----------------------------------------------------------------*/
void  LedOff(unsigned char ucLedNum)
{
  
   if( LED_ALL_E == ucLedNum )
  {
    LED1 = LED_OFF;
    LED2 = LED_OFF;
    LED3 = LED_OFF;
  }
  else if ( LED_LED1_E == ucLedNum)
  {
    LED1 =LED_OFF;
  
  }
   else if ( LED_LED2_E == ucLedNum)
  {
    LED2 =LED_OFF;
  
  }
   else if ( LED_LED3_E == ucLedNum)
  {
    LED3 =LED_OFF;
  
  }
  else
  {
    //do nothing
  }
  
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

* 函数名  ：LedToggle
* 参数    ：unsigned char ucLedNum
* 返回    ：void
* 作者    ：xuxinjie
* 时间    ：2020/10/20
* 描述    ：翻转
----------------------------------------------------------------*/
void  LedToggle(unsigned char ucLedNum)
{
  if ( LED_LED1_E == ucLedNum)
  {
    LED1 =LED_OFF;
    LED2 =LED_ON;
    LED3 =LED_ON;
  }
   else if ( LED_LED2_E == ucLedNum)
  {
    LED1 =LED_ON;
    LED2 =LED_OFF;
    LED3 =LED_ON;
  }
   else if ( LED_LED3_E == ucLedNum)
  {
    LED1 =LED_ON;
    LED2 =LED_ON;
    LED3 =LED_OFF;
  } 
  
  
}