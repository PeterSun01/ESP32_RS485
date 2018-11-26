/*
LED驱动程序
创建日期：2018年10月29日
作者：孙浩

Led_Init(void);
初始化LED，主要为GPIO初始化
GPIO_LED=22

Led_On(void);
点亮LED

Led_Off(void);
熄灭LED

*/
#ifndef _LED_H_
#define _LED_H_

extern void Led_Init(void);
extern void Led_On(void);
extern void Led_Off(void);

#endif

