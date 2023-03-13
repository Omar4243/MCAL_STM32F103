// Header: Stm32f103c8 Drivers
// File Name: NVIC Header File
// Author: Omar Megahed Ismail
// Date: 2022/03/20
#ifndef NVIC_H_
#define NVIC_H_
#include "NVIC_Priv.h"
/*NVIC FUNCTIONS*/
void vNVIC_EnableIRQ       ( uint8 IRQn );
void vNVIC_DisableIRQ      ( uint8 IRQn );
														 					 
void vNVIC_SetPendingIRQ   ( uint8 IRQn );
void vNVIC_ClearPendingIRQ ( uint8 IRQn );
														 					 
uint8 u8NVIC_GetActive     ( uint8 IRQn );
														 					 
void vNVIC_SetPriority     ( uint8 IRQn ,  uint8 Subpriority  ,  uint8 GroupPriority );

#endif
