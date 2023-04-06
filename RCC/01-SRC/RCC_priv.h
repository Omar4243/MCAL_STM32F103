/*****************************************************************************
 * @Author                : Islam Tarek<islamtarek0550@gmail.com>            *
 * @CreatedDate           : 2023-03-08 07:59:59                              *
 * @LastEditors           : Islam Tarek<islamtarek0550@gmail.com>            *
 * @LastEditDate          : 2023-03-29 17:37:43                              *
 * @FilePath              : RCC_priv.h                                       *
 * @CopyRight             : Islam Tarek CopyRight                            *
 ****************************************************************************/

#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_

/**
* @section Includes
*/

#include "std_type.h"

/**
 * @section Typedefs
*/

/**
 * @brief RCC Clock Control Register and Its bits.
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 HSION       :1 ;
        u32 HSIRDY      :1 ;
        u32 Reseved_0   :1 ;
        u32 HSITRIM     :5 ;
        u32 HSICAL      :8 ;
        u32 HSEON       :1 ;
        u32 HSERDY      :1 ;
        u32 HSEBYP      :1 ;
        u32 CSSON       :1 ;
        u32 Reserved_1  :4 ;
        u32 PLLON       :1 ;
        u32 PLLRDY      :1 ;
        u32 Reserved_2  :6 ;
    }bits;
    
}RCC_CR_t;

/**
 * @brief RCC Clock Configutation Register and Its bits.
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 SW          :2 ;
        u32 SWS         :2 ;
        u32 HPRE        :4 ;
        u32 PPRE1       :3 ;
        u32 PPRE2       :3 ;
        u32 ADCPRE      :2 ;
        u32 PLLSRC      :2 ;
        u32 PLLMUL      :4 ;
        u32 USBPRE      :1 ;
        u32 Reserved_0  :1 ;
        u32 MCO         :3 ;
        u32 Reserved_1  :5 ;
    }bits;

}RCC_CFGR_t;

/**
 * @brief RCC Clock Interrupt Register.
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 LSIRDYF     :1 ;
        u32 LSERDYF     :1 ;
        u32 HSIRDYF     :1 ;
        u32 HSERDYF     :1 ;
        u32 PLLRDYF     :1 ;
        u32 Reserved_0  :2 ;
        u32 CSSF        :1 ;
        u32 LSIRDYIE    :1 ;
        u32 LSERDYIE    :1 ;
        u32 HSIRDYIE    :1 ;
        u32 HSERDYIE    :1 ;
        u32 PLLRDYIE    :1 ;
        u32 Reserved_1  :3 ;
        u32 LSIRDYC     :1 ;
        u32 LSERDYC     :1 ;
        u32 HSIRDYC     :1 ;
        u32 HSERDYC     :1 ;
        u32 PLLRDYC     :1 ;
        u32 Reserved_2  :2 ;
        u32 CSSC        :1 ;
        u32 Reserved_3  :8 ;
    }bits;

}RCC_CIR_t;

/**
 * @brief RCC APB2 Peripheral Reset Register.
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 AFIORST     :1  ;
        u32 Reserved_0  :1  ;
        u32 IOPARST     :1  ;
        u32 IOPBRST     :1  ;
        u32 IOPCRST     :1  ;
        u32 IOPDRST     :1  ;
        u32 IOPERST     :1  ;
        u32 IOPFRST     :1  ;
        u32 IOPGRST     :1  ;
        u32 ADC1RST     :1  ;
        u32 ADC2RST     :1  ;
        u32 TIM1RST     :1  ;
        u32 SPI1RST     :1  ;
        u32 TIM8RST     :1  ;
        u32 USART1RST   :1  ;
        u32 ADC3RST     :1  ;
        u32 Reserved_1  :3  ;
        u32 TIM9RST     :1  ;
        u32 TIM10RST    :1  ;
        u32 TIM11RST    :1  ;
        u32 Reserved_2  :10 ;
    }bits;
    
}RCC_APB2RSTR_t;

/**
 * @brief RCC APB1 Peripheral Reset Register.
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 TIM2RST     :1 ;
        u32 TIM3RST     :1 ;
        u32 TIM4RST     :1 ;
        u32 TIM5RST     :1 ;
        u32 TIM6RST     :1 ;
        u32 TIM7RST     :1 ;
        u32 TIM12RST    :1 ;
        u32 TIM13RST    :1 ;
        u32 TIM14RST    :1 ;
        u32 Reserved_0  :2 ;
        u32 WWDGRST     :1 ;
        u32 Reserved_1  :2 ;
        u32 SPI2RST     :1 ;
        u32 SPI3RST     :1 ;
        u32 Reserved_2  :1 ;
        u32 USART2RST   :1 ;
        u32 USART3RST   :1 ;
        u32 UART4RST    :1 ;
        u32 UART5RST    :1 ;
        u32 I2C1RST     :1 ;
        u32 I2C2RST     :1 ;
        u32 USBRST      :1 ;
        u32 Reserved_3  :1 ;
        u32 CANRST      :1 ;
        u32 Reserved_4  :1 ;
        u32 BKPRST      :1 ;
        u32 PWRRST      :1 ;
        u32 DACRST      :1 ;
        u32 Reserved_5  :2 ;
    }bits;
    
}RCC_APB1RSTR_t;

/**
 * @brief AHB Peripheral Clock Enable Register
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 DMA1EN      :1  ;
        u32 DMA2EN      :1  ;
        u32 SRAMEN      :1  ;
        u32 Reserved_0  :1  ;
        u32 FLITFEN     :1  ;
        u32 Reserved_1  :1  ;
        u32 CRCEN       :1  ;
        u32 Reserved_2  :1  ;
        u32 FSMCEN      :1  ;
        u32 Reserved_3  :1  ;
        u32 SDIOEN      :1  ;
        u32 Reserved_4  :21 ;
    }bits;

}RCC_AHBENR_t;

/**
 * @brief APB2 Peripheral Clock Enable Register
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 AFIOEN      :1  ;
        u32 Reserved_0  :1  ;
        u32 IOPAEN      :1  ;
        u32 IOPBEN      :1  ;
        u32 IOPCEN      :1  ;
        u32 IOPDEN      :1  ;
        u32 IOPEEN      :1  ;
        u32 IOPFEN      :1  ;
        u32 IOPGEN      :1  ;
        u32 ADC1EN      :1  ;
        u32 ADC2EN      :1  ;
        u32 TIM1EN      :1  ;
        u32 SPI1EN      :1  ;
        u32 TIM8EN      :1  ;
        u32 USART1EN    :1  ;
        u32 ADC3EN      :1  ;
        u32 Reserved_1  :3  ;
        u32 TIM9EN      :1  ;
        u32 TIM10EN     :1  ;
        u32 TIM11EN     :1  ;
        u32 Reserved_2  :10 ;
    }bits;
    
}RCC_APB2ENR_t;

/**
 * @brief RCC APB1 Peripheral Clock Enable Register.
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 TIM2EN      :1 ;
        u32 TIM3EN      :1 ;
        u32 TIM4EN      :1 ;
        u32 TIM5EN      :1 ;
        u32 TIM6EN      :1 ;
        u32 TIM7EN      :1 ;
        u32 TIM12EN     :1 ;
        u32 TIM13EN     :1 ;
        u32 TIM14EN     :1 ;
        u32 Reserved_0  :2 ;
        u32 WWDGEN      :1 ;
        u32 Reserved_1  :2 ;
        u32 SPI2EN      :1 ;
        u32 SPI3EN      :1 ;
        u32 Reserved_2  :1 ;
        u32 USART2EN    :1 ;
        u32 USART3EN    :1 ;
        u32 UART4EN     :1 ;
        u32 UART5EN     :1 ;
        u32 I2C1EN      :1 ;
        u32 I2C2EN      :1 ;
        u32 USBEN       :1 ;
        u32 Reserved_3  :1 ;
        u32 CANEN       :1 ;
        u32 Reserved_4  :1 ;
        u32 BKPEN       :1 ;
        u32 PWREN       :1 ;
        u32 DACEN       :1 ;
        u32 Reserved_5  :2 ;
    }bits;
    
}RCC_APB1ENR_t;

/**
 * @brief RCC Backup Domain Control Register. 
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 LSEON       :1  ;
        u32 LSERDY      :1  ;
        u32 LSEBYP      :1  ;
        u32 Reserved_0  :5  ;
        u32 RTCSEL      :2  ;
        u32 Reserved_1  :5  ;
        u32 RTCEN       :1  ;
        u32 BDRST       :1  ;
        u32 Reserved_2  :15 ;
    }bits;

}RCC_BDCR_t;

/**
 * @brief RCC Control/Status Register. 
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 LSION       :1  ;
        u32 LSIRDY      :1  ;
        u32 Reserved_0  :22 ;
        u32 RMVF        :1  ;
        u32 Reserved_1  :1  ;
        u32 PINRSTF     :1  ;
        u32 PORRSTF     :1  ;
        u32 SFTRSTF     :1  ;
        u32 IWDGRSTF    :1  ;
        u32 WWDGRSTF    :1  ;
        u32 LPWRSTF     :1  ;
    }bits;

}RCC_CSR_t;

/**
 * @brief RCC Registers Structure.
 */
typedef struct 
{
    volatile RCC_CR_t        RCC_CR;
    volatile RCC_CFGR_t      RCC_CFGR;
    volatile RCC_CIR_t       RCC_CIR;
    volatile RCC_APB2RSTR_t  RCC_APB2RSTR;
    volatile RCC_APB1RSTR_t  RCC_APB1RSTR;
    volatile RCC_AHBENR_t    RCC_AHBENR;
    volatile RCC_APB2ENR_t   RCC_APB2ENR;
    volatile RCC_APB1ENR_t   RCC_APB1ENR;
    volatile RCC_BDCR_t      RCC_BDCR;
    volatile RCC_CSR_t       RCC_CSR;
}RCC_reg_t;

/**
 * @section Definitions 
*/

/**
 * @brief RCC Registers Base Address.
 */
#define RCC_BASE                0x40021000

/**
 * @brief Mapping of RCC registers structure to memory.
 */
#define RCC_REG     ((RCC_reg_t *)(RCC_BASE))

/**
 * @brief Limits of AHB Bus Peripherals
 */
#define AHB_MIN_LIMIT           0U
#define AHB_MAX_LIMIT           32U

/**
 * @brief Limits of APB2 Bus Peripherals
 * 
 */
#define APB2_MIN_LIMIT          32U
#define APB2_MAX_LIMIT          64U

/**
 * @brief Limits of APB1 Bus Peripherals
 * 
 */
#define APB1_MIN_LIMIT          64U
#define APB1_MAX_LIMIT          96U

/**
 * @brief Oscillator State.
 */

#define OSC_OFF                 0U
#define OSC_ON                  1U

/**
 * @brief Division Factors
 */

#define DIV_BY_1                0U
#define DIV_BY_2                1U 
#define DIV_BY_4                2U
#define DIV_BY_8                3U
#define DIV_BY_16               4U
#define DIV_BY_32               5U
#define DIV_BY_64               6U
#define DIV_BY_128              7U
#define DIV_BY_256              8U
#define DIV_BY_512              9U

/**
 * @brief PLL Multiplication Mapping Values
 */
#define PLL_MUL_MAP_VAL_1         1U
#define PLL_MUL_MAP_VAL_2         2U

/**
 * @brief PLL Multiplication Validate End
 */
#define PLL_MUL_END_VALIDATE        1U
#endif