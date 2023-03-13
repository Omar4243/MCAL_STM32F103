/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 23:37:35                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-14 00:00:48                              *
 * @FilePath              : SysTick_int.h                                    *
 ****************************************************************************/

#ifndef _SYSTICK_
#define _SYSTICK_
#include "std_type.h"
#include "SysTick_priv.h"
/*sys clock freq*/
#define SYS_CLK_FRQ  (72000000Ul)


void SysTick_Interrupt_Init(u8 ms);/*max 200 ms*/

void SysTick_Start(void);

#endif




