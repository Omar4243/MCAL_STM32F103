/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 23:37:58                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-13 23:38:50                              *
 * @FilePath              : SysTick_prg.c                                    *
 ****************************************************************************/

#include "SysTick_int.h"

void SysTick_Interrupt_Init(u8 ms)
{
	if(ms>200){ms=200;}
SysTick->CTRL.Bit.CLKSOURCE=1;// PROCESSOR CLK SOURCE	
SysTick->LOAD.data=(u32)((SYS_CLK_FRQ/1000)*ms);	
}
void SysTick_Start(void)
{
SysTick->CTRL.Bit.ENABLE=1; //ENABLE COUNTER
SysTick->CTRL.Bit.TICKINT=1; //ASSERT SYSTEM EXCEPTION
}


