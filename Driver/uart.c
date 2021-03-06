/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* 文件名  ： uart
* 作者    ： xuxinjie
* 版本    ： V1.0.0
* 时间    ： 2020-12-23
* 简要    ： 串口驱动文件 
********************************************************************
* 副本
*
*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/* 头文件 ----------------------------------------------------------------*/
#include <string.h>
#include "uart.h"
/* 宏定义 ----------------------------------------------------------------*/
/* 内部函数声明 -------------------------------------------------------------*/
#define UART0_TX_MAX_SIZE 255
unsigned char g_aucUart0TxBuf[UART0_TX_MAX_SIZE];
unsigned char g_ucUart0TxLen = 0;
unsigned char g_ucUart0TxPos = 0;
/*函数-------------------------------------------------------------------*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 函数名：UartInit
* 参数：void
* 返回：void
* 作者：xuxinjie
* 时间：2020-12-23
* 描述：串口0的驱动函数
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void UartInit(void)
{
    //UART0的IO设置
    //1、确定位置
    PERCFG &= 0xFE;
    //2、设置IO为外设功能 PO_2 P0_3
    P0SEL |= 0x0C;
    //3、UART0优先级设为最高
    P2DIR &= 0x3F;
    //二、UART0 N81 波特率设置
    U0CSR |= 0x80;
    //N81
    U0UCR = 0x02;
    //3、波特率 16M时钟下的9600
    U0BAUD = 59;
    U0GCR = 9;
    //三、中断使能
    IEN2 |= 0x04; //UTX0IE = 1;
    URX0IE = 1;
    EA = 1;
    //UART0接收使能
    U0CSR |= 0x40;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 函数名：UartSend
* 参数：void
* 返回：void
* 作者：xuxinjie
* 时间：2020-12-23
* 描述：串口0的驱动函数
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void UartSend(unsigned char *pBuf,unsigned char ucLen) 
{
    memcpy(g_aucUart0TxBuf,pBuf,ucLen);
    g_ucUart0TxLen = ucLen;
    g_ucUart0TxPos = 1;
    U0DBUF = g_aucUart0TxBuf[0];
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 函数名：UTX0_SIR
* 参数：void
* 返回：void
* 作者：xuxinjie
* 时间：2020-12-23
* 描述：串口发送中断
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#pragma vector = UTX0_VECTOR
__interrupt void UTX0_ISR(void)
{
    if(g_ucUart0TxPos < g_ucUart0TxLen )
    {
        //其他字符发送
        U0DBUF = g_aucUart0TxBuf[g_ucUart0TxPos];
        g_ucUart0TxPos ++;
    }
    UTX0IF = 0;   
}