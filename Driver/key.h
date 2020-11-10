/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
* �ļ���  ��key
* ����    ��xuxinjie
* �汾    ��V0.0.1
* ʱ��    ��2020/10/27
* ����    ����������ͷ�ļ�
********************************************************************
* ����
*
*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/


#ifndef _KEY_H
#define _KEY_H

/* ͷ�ļ� ----------------------------------------------------------------*/
#include<ioCC2530.h>
/* �궨�� ----------------------------------------------------------------*/
#define KEY_PRESS 0
#define KEY_RELEASE 1
#define KEY_ERROR 255
/* �ṹ���ö�� ----------------------------------------------------------------*/
typedef enum enKeyNum
{
  KEY_DEFAULT_E,
  KEY_KEY1_E,
  KEY_KEY2_E,
  KEY_MAX
}KEY_NUM_E;
/* ��������----------------------------------------------------------------*/
void KeyInit(void);
unsigned char KeyStateGet(unsigned char ucKeyNum);
/* �ⲿ�������� ----------------------------------------------------------------*/

#endif // _KEY_H