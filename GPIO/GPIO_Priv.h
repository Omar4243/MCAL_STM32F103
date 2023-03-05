// Header: Stm32f103c8 Drivers
// File Name: GPIO Register map File
// Author: Omar Megahed Ismail
// Date: 2022/03/16
#ifndef GPIO_PRIV_
#define GPIO_PRIV_
/*INCLUDE FILES*/
#include "Std_Type.h"

/*GPIOX BASE ADDRESSES */
#define GPIOA ((GPIOx*)0x40010800)
#define GPIOB ((GPIOx*)0x40010C00)
#define GPIOC ((GPIOx*)0x40011000)
#define GPIOD ((GPIOx*)0x40011400)
#define GPIOE ((GPIOx*)0x40011800)
#define GPIOF ((GPIOx*)0x40011C00)
#define GPIOG ((GPIOx*)0x40012000)
/*REG GPIOx_CRL*/
typedef union
{
	uint32 Reg;
struct
 {
	 uint32 MODE0  : 2 ;
	 uint32  CNF0  : 2 ;	 
	 uint32 MODE1  : 2 ;
	 uint32  CNF1  : 2 ;	 
	 uint32 MODE2  : 2 ;
	 uint32  CNF2  : 2 ; 
	 uint32 MODE3  : 2 ;
	 uint32  CNF3  : 2 ; 
	 uint32 MODE4  : 2 ;
	 uint32  CNF4  : 2 ;	 
	 uint32 MODE5  : 2 ;
	 uint32  CNF5  : 2 ;	 
	 uint32 MODE6  : 2 ;
	 uint32  CNF6  : 2 ;	 
	 uint32 MODE7  : 2 ;
	 uint32  CNF7  : 2 ;
 }Bit;
 }CRL_Typ;
 
 /*REG GPIOx_CRH*/
typedef union
{
	uint32 Reg;
	struct
 {
	 uint32  MODE8 : 2 ;
	 uint32   CNF8 : 2 ;	 
	 uint32  MODE9 : 2 ;
	 uint32   CNF9 : 2 ;	 
	 uint32 MODE10 : 2 ;
	 uint32  CNF10 : 2 ; 
	 uint32 MODE11 : 2 ;
	 uint32  CNF11 : 2 ; 
	 uint32 MODE12 : 2 ;
	 uint32  CNF12 : 2 ;	 
	 uint32 MODE13 : 2 ;
	 uint32  CNF13 : 2 ;	 
	 uint32 MODE14 : 2 ;
	 uint32  CNF14 : 2 ;	 
	 uint32 MODE15 : 2 ;
	 uint32  CNF15 : 2 ;
 }Bit;
 }CRH_Typ;
 /*REG GPIOx_IDR*/
typedef union
{
	uint32 Reg;
	struct
 {
	 uint32 IDR0  : 1 ;
	 uint32 IDR1  : 1 ;	 
	 uint32 IDR2  : 1 ;
	 uint32 IDR3  : 1 ;	 
	 uint32 IDR4  : 1 ;
	 uint32 IDR5  : 1 ; 
	 uint32 IDR6  : 1 ;
	 uint32 IDR7  : 1 ; 
	 uint32 IDR8  : 1 ;
	 uint32 IDR9  : 1 ;	 
	 uint32 IDR10 : 1 ;
	 uint32 IDR11 : 1 ;	 
	 uint32 IDR12 : 1 ;
	 uint32 IDR13 : 1 ;	 
	 uint32 IDR14 : 1 ;
	 uint32 IDR15 : 1 ;
 }Bit;
 }IDR_Typ;
  /*REG GPIOx_ODR*/
typedef union
{
	uint32 Reg;
	struct
 {
	 uint32 ODR0 : 1 ;
	 uint32 ODR1 : 1 ;	 
	 uint32 ODR2 : 1 ;
	 uint32 ODR3 : 1 ;	 
	 uint32 ODR4 : 1 ;
	 uint32 ODR5 : 1 ; 
	 uint32 ODR6 : 1 ;
	 uint32 ODR7 : 1 ; 
	 uint32 ODR8 : 1 ;
	 uint32 ODR9 : 1 ;	 
	 uint32 ODR10: 1 ;
	 uint32 ODR11: 1 ;	 
	 uint32 ODR12: 1 ;
	 uint32 ODR13: 1 ;	 
	 uint32 ODR14: 1 ;
	 uint32 ODR15: 1 ;
 }Bit;
 }ODR_Typ;
 /*REG GPIOx_BSRR*/
typedef union
{
	uint32 Reg;
	struct
 {
	 uint32 BS0  : 1 ;
	 uint32 BS1  : 1 ;	 
	 uint32 BS2  : 1 ;
	 uint32 BS3  : 1 ;	 
	 uint32 BS4  : 1 ;
	 uint32 BS5  : 1 ; 
	 uint32 BS6  : 1 ;
	 uint32 BS7  : 1 ; 
	 uint32 BS8  : 1 ;
	 uint32 BS9  : 1 ;	 
	 uint32 BS10 : 1 ;
	 uint32 BS11 : 1 ;	 
	 uint32 BS12 : 1 ;
	 uint32 BS13 : 1 ;	 
	 uint32 BS14 : 1 ;
	 uint32 BS15 : 1 ;
	 uint32 BR0  : 1 ;
	 uint32 BR1  : 1 ;	 
	 uint32 BR2  : 1 ;
	 uint32 BR3  : 1 ;	 
	 uint32 BR4  : 1 ;
	 uint32 BR5  : 1 ; 
	 uint32 BR6  : 1 ;
	 uint32 BR7  : 1 ; 
	 uint32 BR8  : 1 ;
	 uint32 BR9  : 1 ;	 
	 uint32 BR10 : 1 ;
	 uint32 BR11 : 1 ;	 
	 uint32 BR12 : 1 ;
	 uint32 BR13 : 1 ;	 
	 uint32 BR14 : 1 ;
	 uint32 BR15 : 1 ;
 }Bit;
 }BSRR_Typ;
  /*REG GPIOx_BRR*/
typedef union
{
	uint32 Reg;
	struct
 {
	 uint32 BR0  : 1 ;
	 uint32 BR1  : 1 ;	 
	 uint32 BR2  : 1 ;
	 uint32 BR3  : 1 ;	 
	 uint32 BR4  : 1 ;
	 uint32 BR5  : 1 ; 
	 uint32 BR6  : 1 ;
	 uint32 BR7  : 1 ; 
	 uint32 BR8  : 1 ;
	 uint32 BR9  : 1 ;	 
	 uint32 BR10 : 1 ;
	 uint32 BR11 : 1 ;	 
	 uint32 BR12 : 1 ;
	 uint32 BR13 : 1 ;	 
	 uint32 BR14 : 1 ;
	 uint32 BR15 : 1 ;
 }Bit;
 }BRR_Typ;
 /*REG GPIOx_LCKR*/
typedef union
{
	uint32 Reg;
	struct
 {
	 uint32 LCK0  : 1 ;
	 uint32 LCK1  : 1 ;
     uint32 LCK2  : 1 ;	 
	 uint32 LCK3  : 1 ;
	 uint32 LCK4  : 1 ;	 
	 uint32 LCK5  : 1 ;
	 uint32 LCK6  : 1 ; 
	 uint32 LCK7  : 1 ;
	 uint32 LCK8  : 1 ; 
	 uint32 LCK9  : 1 ;
	 uint32 LCK10 : 1 ;	 
	 uint32 LCK11 : 1 ;
	 uint32 LCK12 : 1 ;	 
	 uint32 LCK13 : 1 ;
	 uint32 LCK14 : 1 ;	 
	 uint32 LCK15 : 1 ;
	 uint32 LCK16 : 1 ;
	 }Bit;
 }LCKR_Typ;

/*GPIOX*/
typedef struct
{
CRL_Typ    CRL;
CRH_Typ    CRH;
IDR_Typ    IDR;
ODR_Typ    ODR;
BSRR_Typ   BSRR;
BRR_Typ    BRR;
LCKR_Typ   LCKR;
}GPIOx;


#endif
