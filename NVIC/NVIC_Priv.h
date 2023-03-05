// Header: Stm32f103c8 Drivers
// File Name: NVIC Memory Map "Register Addresses"
// Author: Omar Megahed Ismail
// Date: 2022/03/20
/********************************************
*	CORTEX M3 NVIC CAN SUPPORT UP TO 81 EXTINT	
*********************************************/
#ifndef NVIC_Priv_
#define NVIC_Priv_
/*include files*/
#include "Std_Type.h"
/*NVIC BASE ADDRESS*/
#define NVIC_BASEADD   (0xE000E100)
/*NVIC REGISTERS*/
/*Interrupt Set Enable Register*/
#define NVIC_ISER0    (*((volatile uint32*)(NVIC_BASEADD + 0X000)))
#define NVIC_ISER1    (*((volatile uint32*)(NVIC_BASEADD + 0X004)))
#define NVIC_ISER2    (*((volatile uint32*)(NVIC_BASEADD + 0X008)))
/*Interrupt Clear Enable Register*/																										 
#define NVIC_ICER0    (*((volatile uint32*)(NVIC_BASEADD + 0X080)))
#define NVIC_ICER1    (*((volatile uint32*)(NVIC_BASEADD + 0X084)))
#define NVIC_ICER2    (*((volatile uint32*)(NVIC_BASEADD + 0X088)))
/*Interrupt Set Pending Register*/																										 
#define NVIC_ISPR0    (*((volatile uint32*)(NVIC_BASEADD + 0X100)))
#define NVIC_ISPR1    (*((volatile uint32*)(NVIC_BASEADD + 0X104)))
#define NVIC_ISPR2    (*((volatile uint32*)(NVIC_BASEADD + 0X108)))
/*Interrupt Clear Pending Register*/																										 
#define NVIC_ICPR0    (*((volatile uint32*)(NVIC_BASEADD + 0X180)))
#define NVIC_ICPR1    (*((volatile uint32*)(NVIC_BASEADD + 0X184)))
#define NVIC_ICPR2    (*((volatile uint32*)(NVIC_BASEADD + 0X188)))
/*Interrupt Active Bit Register*/																										 
#define NVIC_IABR0    (*((volatile uint32*)(NVIC_BASEADD + 0X200)))
#define NVIC_IABR1    (*((volatile uint32*)(NVIC_BASEADD + 0X204)))
#define NVIC_IABR2    (*((volatile uint32*)(NVIC_BASEADD + 0X208)))
/*Interrupt Priority Register*/ // each interrupt have 8bit(USED 4) >>(81*8)/32=21reg
#define NVIC_IPR      (((volatile uint8*)(NVIC_BASEADD + 0X300))) /*WE CAN POINT THIS ADDRESS TO UINT8 ARR[81] */
/*SCB Register*/
#define SCB_BASEADD   (0xE000ED00) 
#define SCB_VECTKEY       (0x05FA)
#define SCB_AIRCR     (((volatile SCB_AIRCR_t*)( SCB_BASEADD + 0X0C))) 
/*Software Trigger Interrupt Register*/
#define STIR_BASEADD  (0xE000EF00)
#define NVIC_STIR     (*((volatile uint32*)( STIR_BASEADD + 0XE00))) 
/*SCB REG STRUCT MAP*/	
typedef struct
{
	uint32 VECTRESET     :1;
	uint32 VECTCLRACTIVE :1;
	uint32 SYSRESETREQ   :1;
	uint32               :5;
	uint32 PRIGROUP      :3;
	uint32               :4;
	uint32 ENDIANESS     :1;
	uint32 VECTKEY       :16;
}SCB_AIRCR_t;
#endif
