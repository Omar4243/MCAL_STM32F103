// Header: Stm32f103c8 Drivers
// File Name: SysTick function implementation File
// Author: Omar Megahed Ismail
// Date: 2022/03/19
#include "Std_Type.h"
#include "SysTick.h"



void SysTick_Interrupt_Init(uint8 ms)
{
	if(ms>200){ms=200;}
SysTick->CTRL.Bit.CLKSOURCE=1;// PROCESSOR CLK SOURCE	
SysTick->LOAD.data=(uint32)((SYS_CLK_FRQ/1000)*ms);	
}
void SysTick_Start(void)
{
SysTick->CTRL.Bit.ENABLE=1; //ENABLE COUNTER
SysTick->CTRL.Bit.TICKINT=1; //ASSERT SYSTEM EXCEPTION
}


