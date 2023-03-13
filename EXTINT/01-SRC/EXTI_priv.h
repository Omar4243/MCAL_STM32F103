/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 23:34:24                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-13 23:57:12                              *
 * @FilePath              : EXTI_priv.h                                      *
 ****************************************************************************/

#ifndef EXTI_PRIV_
#define EXTI_PRIV_
#include "std_type.h"
/*EXTI REGISTERS*/
#define EXTI_BASEADD (0x40010400)

#define EXTI_IMR   (*((volatile u8*)(EXTI_BASEADD + 0X00)))
#define EXTI_EMR   (*((volatile u8*)(EXTI_BASEADD + 0X04)))
#define EXTI_RTSR  (*((volatile u8*)(EXTI_BASEADD + 0X08)))
#define EXTI_FTSR  (*((volatile u8*)(EXTI_BASEADD + 0X0C)))
#define EXTI_SWIER (*((volatile u8*)(EXTI_BASEADD + 0X10)))
#define EXTI_PR    (*((volatile u8*)(EXTI_BASEADD + 0X14)))

/*AFIO REGISTERS*/
#define AFIO_BASEADD (0x40010000)

#define AFIO_EVCR    (*((volatile u8*)(AFIO_BASEADD + 0X00)))
#define AFIO_MAPR    (*((volatile u8*)(AFIO_BASEADD + 0X04)))
#define AFIO_EXTICR1 (*((volatile u8*)(AFIO_BASEADD + 0X08)))
#define AFIO_EXTICR2 (*((volatile u8*)(AFIO_BASEADD + 0X0C)))
#define AFIO_EXTICR3 (*((volatile u8*)(AFIO_BASEADD + 0X10)))
#define AFIO_EXTICR4 (*((volatile u8*)(AFIO_BASEADD + 0X14)))
#define AFIO_MAPR2   (*((volatile u8*)(AFIO_BASEADD + 0X1C)))

#endif
