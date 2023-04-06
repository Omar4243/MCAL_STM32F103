/*****************************************************************************
 * @Author                : Islam Tarek<islamtarek0550@gmail.com>            *
 * @CreatedDate           : 2023-03-08 18:24:04                              *
 * @LastEditors           : Islam Tarek<islamtarek0550@gmail.com>            *
 * @LastEditDate          : 2023-03-29 17:37:09                              *
 * @FilePath              : RCC_int.h                                        *
 * @CopyRight             : Islam Tarek CopyRight                            *
 ****************************************************************************/

#ifndef RCC_INT_H_
#define RCC_INT_H_

/**
 * @section Includes
*/

#include "std_type.h"
#include "bit_math.h"

/**
 * @section Typedefs
*/

/**
 * @brief Peripherals whose clock should be enabled before usage. 
 */
typedef enum
{
    DMA1   = (u8) 0  ,
    SRAM   = (u8) 2  ,
    FLITF  = (u8) 4  ,
    CRC    = (u8) 6  ,
    GPIOA  = (u8) 34 ,
    GPIOB            ,
    GPIOC            ,
    GPIOD            ,
    GPIOE            ,
    ADC1   = (u8) 41 ,
    ADC2             ,
    TIM1             ,
    SPI1             ,
    USART1 = (u8) 46 ,
    TIM2   = (u8) 64 ,
    TIM3             ,
    TIM4             ,
    WWDG   = (u8) 75 ,
    SPI2   = (u8) 78 ,
    USART2 = (u8) 81 ,
    USART3           ,
    I2C1   = (u8) 85 ,
    I2C2             ,
    USB              ,
    CAN    = (u8) 89 ,
    BKP    = (u8) 91 ,
}RCC_peripheral_t;

/**
 * @brief Structure of needed clocks.
 */
typedef struct 
{
    u32 SYS_clk_KHZ;
    u32 AHB_clk_KHZ;
    u16 APB1_clk_KHZ;
    u32 APB2_clk_KHZ;
}RCC_clk_t;


/**
 * @section APIs 
*/

std_errorStatus_t RCC_init   				(void);
std_errorStatus_t RCC_get_clk_value         (RCC_clk_t * local_strRCC_clk_value);
std_errorStatus_t RCC_enable_peripheral_clk (RCC_peripheral_t local_enuPeripheral);
std_errorStatus_t RCC_disable_peripheral_clk(RCC_peripheral_t local_enuPeripheral);
std_errorStatus_t RCC_reset_peripheral  	(RCC_peripheral_t local_enuPeripheral);

#endif
