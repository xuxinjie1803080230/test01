/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

* �ļ���  ��led
* ����    ��xuxinjie
* �汾    ��V0.0.1
* ʱ��    ��2020/10/20
* ����    ��led�����ļ�
********************************************************************
* ����
*
*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/* ͷ�ļ� ----------------------------------------------------------------*/
#include "led.h"
/* �궨�� ----------------------------------------------------------------*/
//D1 D2 D3 P1_0 P1_1 P1_4
#define LED1 P1_0
#define LED2 P1_1
#define LED3 P1_4
#define LED_ON 0
#define LED_OFF 1
/* �ṹ���ö�� ----------------------------------------------------------------*/
/* �ڲ��������� ----------------------------------------------------------------*/






/* ���� ----------------------------------------------------------------*/
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

* ������  ��LedInit
* ����    ��void
* ����    ��void
* ����    ��xuxinjie
* ʱ��    ��2020/10/20
* ����    ��Led��ʼ��
----------------------------------------------------------------*/
void LedInit(void)
{
  //P1SEL��Ӧλ����Ϊͨ��IO(���㣩
   P1SEL &= 0xEC;
  //P1��Ӧλ����Ϊ�������1��
   P1DIR |= 0x13;
   //�����еƶ��ص�
    P1 |= 0x13;
   
  
  
}



/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

* ������  ��LedOn
* ����    ��unsigned char ucLedNum 0 ���Ե���;  1 D1��; 2 D2���� 3 D3��
* ����    ��void
* ����    ��xuxinjie
* ʱ��    ��2020/10/17
* ����    ������
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

* ������  ��LedOff
* ����    ��unsigned char ucLedNum
* ����    ��void
* ����    ��xuxinjie
* ʱ��    ��2020/10/20
* ����    ���ص�
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

* ������  ��LedToggle
* ����    ��unsigned char ucLedNum
* ����    ��void
* ����    ��xuxinjie
* ʱ��    ��2020/10/20
* ����    ����ת
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