/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 23:39:05                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-14 00:01:07                              *
 * @FilePath              : SysTick_priv.h                                   *
 ****************************************************************************/

#ifndef SYSTICK_PRIV_
#define SYSTICK_PRIV_
/*include lib*/
#include "std_type.h"
/*systick base address*/
#define SysTick ((SysTick_Type*)0xE000E010)  
/*systick reg struct*/
/*STK_CTRL*/
typedef union
{
	u32 data;
	struct
    {
			u32 ENABLE    :1;
			u32 TICKINT   :1;
			u32 CLKSOURCE :1;
			u32           :13;
			u32 COUNTFLAG :1;
			u32           :15;
    }Bit;
}CTRL_TYP;
/*STK_LOAD*/
typedef union
{
	u32 data;
	struct
    {
			u32 RELOAD    :24;
			u32           :8;

    }Bit;
}LOAD_TYP;
/*STK_VAL*/ /*CURRENT VALUE*/
typedef union
{
	u32 data;
	struct
    {
			u32 CURRENT    :24;
			u32            :8;

    }Bit;
}VAL_TYP;
/*STK_CALIB*/ 
typedef union
{
	u32 data;
	struct
    {
			u32 TENMS      :24;
			u32            :6;
			u32 SKEW       :1;
			u32 NOREF      :1;
   
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

