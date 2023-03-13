/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 23:25:56                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-13 23:26:25                              *
 * @FilePath              : NVIC_int.h                                       *
 ****************************************************************************/

// Header: Stm32f103c8 Drivers
// File Name: NVIC Header File
// Author: Omar Megahed Ismail
// Date: 2022/03/20
#ifndef NVIC_H_
#define NVIC_H_
#include "NVIC_priv.h"
/*NVIC FUNCTIONS*/
void vNVIC_EnableIRQ       ( u8 IRQn );
void vNVIC_DisableIRQ      ( u8 IRQn );
														 					 
void vNVIC_SetPendingIRQ   ( u8 IRQn );
void vNVIC_ClearPendingIRQ ( u8 IRQn );
														 					 
u8 u8NVIC_GetActive     ( u8 IRQn );
														 					 
void vNVIC_SetPriority     ( u8 IRQn ,  u8 Subpriority  ,  u8 GroupPriority );

#endif
