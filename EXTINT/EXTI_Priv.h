// Header: Stm32f103c8 Drivers
// File Name: EXTI REGISTER MAP File
// Author: Omar Megahed Ismail
// Date: 2022/03/20
#ifndef EXTI_PRIV_
#define EXTI_PRIV_
#include "Std_Type.h"
/*EXTI REGISTERS*/
#define EXTI_BASEADD (0x40010400)

#define EXTI_IMR   (*((volatile uint8*)(EXTI_BASEADD + 0X00)))
#define EXTI_EMR   (*((volatile uint8*)(EXTI_BASEADD + 0X04)))
#define EXTI_RTSR  (*((volatile uint8*)(EXTI_BASEADD + 0X08)))
#define EXTI_FTSR  (*((volatile uint8*)(EXTI_BASEADD + 0X0C)))
#define EXTI_SWIER (*((volatile uint8*)(EXTI_BASEADD + 0X10)))
#define EXTI_PR    (*((volatile uint8*)(EXTI_BASEADD + 0X14)))

/*AFIO REGISTERS*/
#define AFIO_BASEADD (0x40010000)

#define AFIO_EVCR    (*((volatile uint8*)(AFIO_BASEADD + 0X00)))
#define AFIO_MAPR    (*((volatile uint8*)(AFIO_BASEADD + 0X04)))
#define AFIO_EXTICR1 (*((volatile uint8*)(AFIO_BASEADD + 0X08)))
#define AFIO_EXTICR2 (*((volatile uint8*)(AFIO_BASEADD + 0X0C)))
#define AFIO_EXTICR3 (*((volatile uint8*)(AFIO_BASEADD + 0X10)))
#define AFIO_EXTICR4 (*((volatile uint8*)(AFIO_BASEADD + 0X14)))
#define AFIO_MAPR2   (*((volatile uint8*)(AFIO_BASEADD + 0X1C)))

#endif
