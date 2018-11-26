/*
RS485测试程序

创建日期：2018年11月26日
作者：孙浩

RS485_Init(void);
初始化函数，主要为UART初始化和GPIO初始化
本例使用UART2，115200，8N1

*/
#ifndef _RS485_H_
#define _RS485_H_

extern void RS485_Init(void);
extern void RS485_echo(void);

#endif

