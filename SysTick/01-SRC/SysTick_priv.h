// Header: Stm32f103c8 Drivers
// File Name: SYSTICK Reg Map File
// Author: Omar Megahed Ismail
// Date: 2022/03/19
#ifndef SYSTICK_PRIV_
#define SYSTICK_PRIV_
/*include lib*/
#include "Std_Type.h"
/*systick base address*/
#define SysTick ((SysTick_Type*)0xE000E010)  
/*systick reg struct*/
/*STK_CTRL*/
typedef union
{
	uint32 data;
	struct
    {
			uint32 ENABLE    :1;
			uint32 TICKINT   :1;
			uint32 CLKSOURCE :1;
			uint32           :13;
			uint32 COUNTFLAG :1;
			uint32           :15;
    }Bit;
}CTRL_TYP;
/*STK_LOAD*/
typedef union
{
	uint32 data;
	struct
    {
			uint32 RELOAD    :24;
			uint32           :8;

    }Bit;
}LOAD_TYP;
/*STK_VAL*/ /*CURRENT VALUE*/
typedef union
{
	uint32 data;
	struct
    {
			uint32 CURRENT    :24;
			uint32            :8;

    }Bit;
}VAL_TYP;
/*STK_CALIB*/ 
typedef union
{
	uint32 data;
	struct
    {
			uint32 TENMS      :24;
			uint32            :6;
			uint32 SKEW       :1;
			uint32 NOREF      :1;
   
    }Bit;
}CALIB_TYP;

/*SYSTICK REGISTERS MAP*/
typedef struct
{
CTRL_TYP   CTRL;
LOAD_TYP   LOAD;
VAL_TYP    VAL;
CALIB_TYP	 CALIB;

}SysTick_Type;




#endif

