/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* �ļ���  �� uart
* ����    �� xuxinjie
* �汾    �� V1.0.0
* ʱ��    �� 2020-12-23
* ��Ҫ    �� ���������ļ� 
********************************************************************
* ����
*
*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/* ͷ�ļ� ----------------------------------------------------------------*/
#include <string.h>
#include "uart.h"
/* �궨�� ----------------------------------------------------------------*/
/* �ڲ��������� -------------------------------------------------------------*/
#define UART0_TX_MAX_SIZE 255
unsigned char g_aucUart0TxBuf[UART0_TX_MAX_SIZE];
unsigned char g_ucUart0TxLen = 0;
unsigned char g_ucUart0TxPos = 0;
/*����-------------------------------------------------------------------*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* ��������UartInit
* ������void
* ���أ�void
* ���ߣ�xuxinjie
* ʱ�䣺2020-12-23
* ����������0����������
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void UartInit(void)
{
    //UART0��IO����
    //1��ȷ��λ��
    PERCFG &= 0xFE;
    //2������IOΪ���蹦�� PO_2 P0_3
    P0SEL |= 0x0C;
    //3��UART0���ȼ���Ϊ���
    P2DIR &= 0x3F;
    //����UART0 N81 ����������
    U0CSR |= 0x80;
    //N81
    U0UCR = 0x02;
    //3�������� 16Mʱ���µ�9600
    U0BAUD = 59;
    U0GCR = 9;
    //�����ж�ʹ��
    IEN2 |= 0x04; //UTX0IE = 1;
    URX0IE = 1;
    EA = 1;
    //UART0����ʹ��
    U0CSR |= 0x40;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* ��������UartSend
* ������void
* ���أ�void
* ���ߣ�xuxinjie
* ʱ�䣺2020-12-23
* ����������0����������
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void UartSend(unsigned char *pBuf,unsigned char ucLen) 
{
    memcpy(g_aucUart0TxBuf,pBuf,ucLen);
    g_ucUart0TxLen = ucLen;
    g_ucUart0TxPos = 1;
    U0DBUF = g_aucUart0TxBuf[0];
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* ��������UTX0_SIR
* ������void
* ���أ�void
* ���ߣ�xuxinjie
* ʱ�䣺2020-12-23
* ���������ڷ����ж�
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#pragma vector = UTX0_VECTOR
__interrupt void UTX0_ISR(void)
{
    if(g_ucUart0TxPos < g_ucUart0TxLen )
    {
        //�����ַ�����
        U0DBUF = g_aucUart0TxBuf[g_ucUart0TxPos];
        g_ucUart0TxPos ++;
    }
    UTX0IF = 0;   
}