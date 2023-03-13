/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 21:26:25                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-13 22:14:19                              *
 * @FilePath              : GPIO_int.h                                       *
 ****************************************************************************/


#ifndef GPIO_H_
#define GPIO_H_
/*Include Files*/
#include "GPIO_priv.h"
/*Enums*/
typedef enum
{
  Low=0,
	High
}Logic_Type;
typedef enum
{
  
	Output_PushPull=0,
	Output_OpenDrain,
	Output_OpenDrain_PullUp,
	
	AltFunc_PushPull,
	AltFunc_OpenDrain,

	
	Input_Analog,
	Input_Floating,
	Input_PullDown,
	Input_PullUp
	
}Pin_Status_Type;

typedef enum
{
    LowSpeed=0, //MAX SPEED 2  MHZ
	MedSpeed,   //MAX SPEED 10 MHZ
	HighSpeed   //MAX SPEED 50 MHZ
	
}Pin_Speed_Type;
typedef enum
{
    PIN0=0,
	PIN1 ,
	PIN2 ,
	PIN3 ,
	PIN4 ,
	PIN5 ,
	PIN6 ,
	PIN7 ,
	PIN8 ,
	PIN9 ,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}Pin_Num_Type;

/*Gpio Functions*/
void vGPIO_Pin_Set_Mode        (GPIOx * GPIO  ,  Pin_Num_Type  PinNum  ,  Pin_Status_Type     Pin_Status    );//OUTPUT DEFUALT SPEED -> MED {MAX 10 MHZ}

void vGPIO_Pin_Set_OutputSpeed (GPIOx * GPIO  ,  Pin_Num_Type  PinNum  ,  Pin_Speed_Type      SpeedType     );

void vGPIO_Pin_Write           (GPIOx * GPIO  ,  Pin_Num_Type  PinNum  ,  Logic_Type          Logic         );

u8 u8GPIO_Pin_Read          (GPIOx * GPIO  ,  Pin_Num_Type  PinNum );



#endif

