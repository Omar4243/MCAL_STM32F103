/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-03-08 18:24:04                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-03-09 00:13:43                              *
 * @FilePath              : RCC_int.h                                        *
 * @CopyRight             : MerBleueAviation                                 *
 ****************************************************************************/

#ifndef RCC_INT_H_
#define RCC_INT_H_

/**
 * @brief Include Section
 */

#include "../../../../LIB/Std_LIB/std_type.h"

/**
 * @brief Typedefs Section
 */

typedef enum
{
    DMA1    = (u8) 0  ,
    SRAM    = (u8) 2  ,
    FLITF   = (u8) 4  ,
    CRC     = (u8) 6  ,
    GPIO_A  = (u8) 34 ,
    GPIO_B            ,
    GPIO_C            ,
    GPIO_D            ,
    GPIO_E            ,
    ADC_1   = (u8) 41 ,
    ADC_2             ,
    TIM_1             ,
    SPI_1             ,
    USART_1 = (u8) 46 ,
    TIM_2   = (u8) 64 ,
    TIM_3             ,
    TIM_4             ,
    WWDG    = (u8) 75 ,
    SPI_2   = (u8) 78 ,
    USART_2 = (u8) 81 ,
    USART_3           ,
    I2C_1   = (u8) 85 ,
    I2C_2             ,
    USB               ,
    CAN     = (u8) 89 ,
    BKP     = (u8) 91 ,
}peripheral_t;


/**
 * @brief APIs Section
 */

std_errorStatus_t MCAL_enu_Rcc_init   (void);
std_errorStatus_t MCAL_enu_Rcc_enable (peripheral_t local_enuPeripheral);
std_errorStatus_t MCAL_enu_Rcc_disable(peripheral_t local_enuPeripheral);

#endif