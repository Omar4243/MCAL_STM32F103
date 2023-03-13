/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 22:09:56                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-13 23:57:53                              *
 * @FilePath              : GPIO_Priv.h                                      *
 ****************************************************************************/

#define GPIO_PRIV_
/*INCLUDE FILES*/
#include "std_type.h"

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
	u32 Reg;
struct
 {
	 u32 MODE0  : 2 ;
	 u32  CNF0  : 2 ;	 
	 u32 MODE1  : 2 ;
	 u32  CNF1  : 2 ;	 
	 u32 MODE2  : 2 ;
	 u32  CNF2  : 2 ; 
	 u32 MODE3  : 2 ;
	 u32  CNF3  : 2 ; 
	 u32 MODE4  : 2 ;
	 u32  CNF4  : 2 ;	 
	 u32 MODE5  : 2 ;
	 u32  CNF5  : 2 ;	 
	 u32 MODE6  : 2 ;
	 u32  CNF6  : 2 ;	 
	 u32 MODE7  : 2 ;
	 u32  CNF7  : 2 ;
 }Bit;
 }CRL_Typ;
 
 /*REG GPIOx_CRH*/
typedef union
{
	u32 Reg;
	struct
 {
	 u32  MODE8 : 2 ;
	 u32   CNF8 : 2 ;	 
	 u32  MODE9 : 2 ;
	 u32   CNF9 : 2 ;	 
	 u32 MODE10 : 2 ;
	 u32  CNF10 : 2 ; 
	 u32 MODE11 : 2 ;
	 u32  CNF11 : 2 ; 
	 u32 MODE12 : 2 ;
	 u32  CNF12 : 2 ;	 
	 u32 MODE13 : 2 ;
	 u32  CNF13 : 2 ;	 
	 u32 MODE14 : 2 ;
	 u32  CNF14 : 2 ;	 
	 u32 MODE15 : 2 ;
	 u32  CNF15 : 2 ;
 }Bit;
 }CRH_Typ;
 /*REG GPIOx_IDR*/
typedef union
{
	u32 Reg;
	struct
 {
	 u32 IDR0  : 1 ;
	 u32 IDR1  : 1 ;	 
	 u32 IDR2  : 1 ;
	 u32 IDR3  : 1 ;	 
	 u32 IDR4  : 1 ;
	 u32 IDR5  : 1 ; 
	 u32 IDR6  : 1 ;
	 u32 IDR7  : 1 ; 
	 u32 IDR8  : 1 ;
	 u32 IDR9  : 1 ;	 
	 u32 IDR10 : 1 ;
	 u32 IDR11 : 1 ;	 
	 u32 IDR12 : 1 ;
	 u32 IDR13 : 1 ;	 
	 u32 IDR14 : 1 ;
	 u32 IDR15 : 1 ;
 }Bit;
 }IDR_Typ;
  /*REG GPIOx_ODR*/
typedef union
{
	u32 Reg;
	struct
 {
	 u32 ODR0 : 1 ;
	 u32 ODR1 : 1 ;	 
	 u32 ODR2 : 1 ;
	 u32 ODR3 : 1 ;	 
	 u32 ODR4 : 1 ;
	 u32 ODR5 : 1 ; 
	 u32 ODR6 : 1 ;
	 u32 ODR7 : 1 ; 
	 u32 ODR8 : 1 ;
	 u32 ODR9 : 1 ;	 
	 u32 ODR10: 1 ;
	 u32 ODR11: 1 ;	 
	 u32 ODR12: 1 ;
	 u32 ODR13: 1 ;	 
	 u32 ODR14: 1 ;
	 u32 ODR15: 1 ;
 }Bit;
 }ODR_Typ;
 /*REG GPIOx_BSRR*/
typedef union
{
	u32 Reg;
	struct
 {
	 u32 BS0  : 1 ;
	 u32 BS1  : 1 ;	 
	 u32 BS2  : 1 ;
	 u32 BS3  : 1 ;	 
	 u32 BS4  : 1 ;
	 u32 BS5  : 1 ; 
	 u32 BS6  : 1 ;
	 u32 BS7  : 1 ; 
	 u32 BS8  : 1 ;
	 u32 BS9  : 1 ;	 
	 u32 BS10 : 1 ;
	 u32 BS11 : 1 ;	 
	 u32 BS12 : 1 ;
	 u32 BS13 : 1 ;	 
	 u32 BS14 : 1 ;
	 u32 BS15 : 1 ;
	 u32 BR0  : 1 ;
	 u32 BR1  : 1 ;	 
	 u32 BR2  : 1 ;
	 u32 BR3  : 1 ;	 
	 u32 BR4  : 1 ;
	 u32 BR5  : 1 ; 
	 u32 BR6  : 1 ;
	 u32 BR7  : 1 ; 
	 u32 BR8  : 1 ;
	 u32 BR9  : 1 ;	 
	 u32 BR10 : 1 ;
	 u32 BR11 : 1 ;	 
	 u32 BR12 : 1 ;
	 u32 BR13 : 1 ;	 
	 u32 BR14 : 1 ;
	 u32 BR15 : 1 ;
 }Bit;
 }BSRR_Typ;
  /*REG GPIOx_BRR*/
typedef union
{
	u32 Reg;
	struct
 {
	 u32 BR0  : 1 ;
	 u32 BR1  : 1 ;	 
	 u32 BR2  : 1 ;
	 u32 BR3  : 1 ;	 
	 u32 BR4  : 1 ;
	 u32 BR5  : 1 ; 
	 u32 BR6  : 1 ;
	 u32 BR7  : 1 ; 
	 u32 BR8  : 1 ;
	 u32 BR9  : 1 ;	 
	 u32 BR10 : 1 ;
	 u32 BR11 : 1 ;	 
	 u32 BR12 : 1 ;
	 u32 BR13 : 1 ;	 
	 u32 BR14 : 1 ;
	 u32 BR15 : 1 ;
 }Bit;
 }BRR_Typ;
 /*REG GPIOx_LCKR*/
typedef union
{
	u32 Reg;
	struct
 {
	 u32 LCK0  : 1 ;
	 u32 LCK1  : 1 ;
     u32 LCK2  : 1 ;	 
	 u32 LCK3  : 1 ;
	 u32 LCK4  : 1 ;	 
	 u32 LCK5  : 1 ;
	 u32 LCK6  : 1 ; 
	 u32 LCK7  : 1 ;
	 u32 LCK8  : 1 ; 
	 u32 LCK9  : 1 ;
	 u32 LCK10 : 1 ;	 
	 u32 LCK11 : 1 ;
	 u32 LCK12 : 1 ;	 
	 u32 LCK13 : 1 ;
	 u32 LCK14 : 1 ;	 
	 u32 LCK15 : 1 ;
	 u32 LCK16 : 1 ;
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
