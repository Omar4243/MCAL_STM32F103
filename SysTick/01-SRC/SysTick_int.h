// Header: Stm32f103c8 Drivers
// File Name: SYS TICK function Header File
// Author: Omar Megahed Ismail
// Date: 2022/03/19
#ifndef _SYSTICK_
#define _SYSTICK_
#include "Std_Type.h"
#include "SysTick_Priv.h"
/*sys clock freq*/
#define SYS_CLK_FRQ  (72000000Ul)


void SysTick_Interrupt_Init(uint8 ms);/*max 200 ms*/

void SysTick_Start(void);

#endif




