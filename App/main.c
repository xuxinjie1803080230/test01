/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 文件名  ：main
* 作者    ：xuxinjie
* 版本    ：V0.0.1
* 时间    ：2020/10/20
* 描述    ：主函数文件
********************************************************************
* 副本
*
*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* 头文件 ----------------------------------------------------------------*/
#include"led.h"
#include"key.h"
#include"timer.h"
/* 宏定义 ----------------------------------------------------------------*/
/* 结构体或枚举 ----------------------------------------------------------------*/
/* 内部函数声明 ----------------------------------------------------------------*/
void Delay(unsigned int time);
/* 函数 ----------------------------------------------------------------*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 函数名  ：Delay
* 参数    ：unsigned int time
* 返回    ：void
* 作者    ：xuxinjie
* 时间    ：2020/10/23
* 描述    ：函数说明
----------------------------------------------------------------*/
void  Delay(unsigned int time)
{
  
  unsigned int i =0;
  unsigned int j;
  for(i = 0; i < time; i++)
  {
    for(j = 0;j <475; j++)
    {
      asm("NOP");
      asm("NOP");
      asm("NOP");
    }
  }
  
  
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 函数名  ：main
* 参数    ：void
* 返回    ：void
* 作者    ：xuxinjie
* 时间    ：2020/10/20
* 描述    ：主函数入口
----------------------------------------------------------------*/
void main(void)
{
    LedInit();
    KeyInit();
    unsigned long ulLedTimer = 0;
    while(1)
    {
        TIMERSET(ulLedTimer,500);
        while(1)
        {
            if(TIMERCHECK(ulLedTimer))
            {
                LedToggle(LED_LED1_E);
                TIMERSET(ulLedTimer,500);
            }
        }
    }
    while(1)
    {
        TIMERSET(ulLedTimer,1000);
        while(1)
        {
            if(TIMERCHECK(ulLedTimer))
            {
                LedToggle(LED_LED2_E);
                TIMERSET(ulLedTimer,1000);
            }
        }
    }
    while(1)
    {
        TIMERSET(ulLedTimer,2000);
        while(1)
        {
            if(TIMERCHECK(ulLedTimer))
            {
                LedToggle(LED_LED3_E);
                TIMERSET(ulLedTimer,2000);
            }
        }
    }
}
/*void  main(void)
{
    //Led初始化
    LedInit();
    KeyInit();
    //Led所有灯灭
    LedOff(LED_ALL_E);
    while(1)
    {
        if ( KEY_PRESS == KeyStateGet( KEY_KEY1_E ) )
        {
            //消除抖动
            Delay(100);
            if( KEY_PRESS == KeyStateGet( KEY_KEY1_E ) )
            {
                LedToggle(LED_LED1_E);
                //等待按键松开
                while( KEY_PRESS == KeyStateGet( KEY_KEY1_E ) );
            }
        }
        
    }
    if ( KEY_PRESS == KeyStateGet( KEY_KEY2_E ) )
    {
        //消除抖动
        Delay(100);
        if( KEY_PRESS == KeyStateGet( KEY_KEY2_E ) )
        {
            LedToggle(LED_LED2_E);
            //等待按键松开
            while( KEY_PRESS == KeyStateGet( KEY_KEY2_E ) );
        }
    }     
}
*/

