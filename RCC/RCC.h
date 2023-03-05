// Header: Stm32f103c8 Drivers
// File Name: RCC Header File
// Author: Omar Megahed Ismail
// Date: 2022/03/16
#ifndef RCC_H_
#define RCC_H_
#include "RCC_Priv.h"
#include "RCC_Config.h"

typedef enum
{
  APB1 = 0,
  APB2

} Bus_Name;

void vRCC_Init(void);

void vRCC_EnPerClk(Bus_Name Bus, uint8 Peripheral_Name);

#endif
