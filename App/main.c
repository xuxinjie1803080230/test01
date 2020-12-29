/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* �ļ���  ��main
* ����    ��xuxinjie
* �汾    ��V0.0.1
* ʱ��    ��2020/10/20
* ����    ���������ļ�
********************************************************************
* ����
*
*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* ͷ�ļ� ----------------------------------------------------------------*/
#include"led.h"
#include"key.h"
#include"timer.h"
/* �궨�� ----------------------------------------------------------------*/
/* �ṹ���ö�� ----------------------------------------------------------------*/
/* �ڲ��������� ----------------------------------------------------------------*/
void Delay(unsigned int time);
/* ���� ----------------------------------------------------------------*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* ������  ��Delay
* ����    ��unsigned int time
* ����    ��void
* ����    ��xuxinjie
* ʱ��    ��2020/10/23
* ����    ������˵��
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
* ������  ��main
* ����    ��void
* ����    ��void
* ����    ��xuxinjie
* ʱ��    ��2020/10/20
* ����    �����������
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
    //Led��ʼ��
    LedInit();
    KeyInit();
    //Led���е���
    LedOff(LED_ALL_E);
    while(1)
    {
        if ( KEY_PRESS == KeyStateGet( KEY_KEY1_E ) )
        {
            //��������
            Delay(100);
            if( KEY_PRESS == KeyStateGet( KEY_KEY1_E ) )
            {
                LedToggle(LED_LED1_E);
                //�ȴ������ɿ�
                while( KEY_PRESS == KeyStateGet( KEY_KEY1_E ) );
            }
        }
        
    }
    if ( KEY_PRESS == KeyStateGet( KEY_KEY2_E ) )
    {
        //��������
        Delay(100);
        if( KEY_PRESS == KeyStateGet( KEY_KEY2_E ) )
        {
            LedToggle(LED_LED2_E);
            //�ȴ������ɿ�
            while( KEY_PRESS == KeyStateGet( KEY_KEY2_E ) );
        }
    }     
}
*/

