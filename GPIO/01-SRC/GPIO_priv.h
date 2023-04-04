/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-03-28 09:34:28                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-04-03 21:54:04                              *
 * @FilePath              : GPIO_priv.h                                      *
 ****************************************************************************/

#ifndef GPIO_PRIV_H_
#define GPIO_PRIV_H

/**
 * @section Includes
*/
#include "std_type.h"


/**
 * @section Typedefs
*/

/**
 * @brief GPIO Configuration Register Low and its bits (for bits 0 --> 7).
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 MODE0   :2 ;
        u32 CNF0    :2 ;
        u32 MODE1   :2 ;
        u32 CNF1    :2 ;
        u32 MODE2   :2 ;
        u32 CNF2    :2 ;
        u32 MODE3   :2 ;
        u32 CNF3    :2 ;
        u32 MODE4   :2 ;
        u32 CNF4    :2 ;
        u32 MODE5   :2 ;
        u32 CNF5    :2 ;
        u32 MODE6   :2 ;
        u32 CNF6    :2 ;
        u32 MODE7   :2 ;
        u32 CNF7    :2 ;
    }bits;

}GPIO_CRL_t;

/**
 * @brief GPIO Configuration Register High and its bits (for bits 8 --> 15).
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 MODE8   :2 ;
        u32 CNF8    :2 ;
        u32 MODE9   :2 ;
        u32 CNF9    :2 ;
        u32 MODE10  :2 ;
        u32 CNF10   :2 ;
        u32 MODE11  :2 ;
        u32 CNF11   :2 ;
        u32 MODE12  :2 ;
        u32 CNF12   :2 ;
        u32 MODE13  :2 ;
        u32 CNF13   :2 ;
        u32 MODE14  :2 ;
        u32 CNF14   :2 ;
        u32 MODE15  :2 ;
        u32 CNF15   :2 ;
    }bits;

}GPIO_CRH_t;

/**
 * @brief GPIO Input Data Register and its bits.
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 IDR0     :1 ;
        u32 IDR1     :1 ;
        u32 IDR2     :1 ;
        u32 IDR3     :1 ;
        u32 IDR4     :1 ;
        u32 IDR5     :1 ;
        u32 IDR6     :1 ;
        u32 IDR7     :1 ;
        u32 IDR8     :1 ;
        u32 IDR9     :1 ;
        u32 IDR10    :1 ;
        u32 IDR11    :1 ;
        u32 IDR12    :1 ;
        u32 IDR13    :1 ;
        u32 IDR14    :1 ;
        u32 IDR15    :1 ;
        u32 Reserved :16;
    }bits;

}GPIO_IDR_t;

/**
 * @brief GPIO Output Data Register and its bits.
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 ODR0     :1 ;
        u32 ODR1     :1 ;
        u32 ODR2     :1 ;
        u32 ODR3     :1 ;
        u32 ODR4     :1 ;
        u32 ODR5     :1 ;
        u32 ODR6     :1 ;
        u32 ODR7     :1 ;
        u32 ODR8     :1 ;
        u32 ODR9     :1 ;
        u32 ODR10    :1 ;
        u32 ODR11    :1 ;
        u32 ODR12    :1 ;
        u32 ODR13    :1 ;
        u32 ODR14    :1 ;
        u32 ODR15    :1 ;
        u32 Reserved :16;
    }bits;

}GPIO_ODR_t;

/**
 * @brief GPIO Bit Set/Reset Register and its bits. 
 * !Note: BS has priority in case both BS and BR for same bit are set.
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 BS0  :1 ;
        u32 BS1  :1 ;
        u32 BS2  :1 ;
        u32 BS3  :1 ;
        u32 BS4  :1 ;
        u32 BS5  :1 ;
        u32 BS6  :1 ;
        u32 BS7  :1 ;
        u32 BS8  :1 ;
        u32 BS9  :1 ;
        u32 BS10 :1 ;
        u32 BS11 :1 ;
        u32 BS12 :1 ;
        u32 BS13 :1 ;
        u32 BS14 :1 ;
        u32 BS15 :1 ;
        u32 BR0  :1 ;
        u32 BR1  :1 ;
        u32 BR2  :1 ;
        u32 BR3  :1 ;
        u32 BR4  :1 ;
        u32 BR5  :1 ;
        u32 BR6  :1 ;
        u32 BR7  :1 ;
        u32 BR8  :1 ;
        u32 BR9  :1 ;
        u32 BR10 :1 ;
        u32 BR11 :1 ;
        u32 BR12 :1 ;
        u32 BR13 :1 ;
        u32 BR14 :1 ;
        u32 BR15 :1 ;
    }bits;
    
}GPIO_BSRR_t;

/**
 * @brief GPIO Bit Reset Register and its bits. 
 */
typedef union 
{
    u32 reg;
    struct
    {
        u32 BR0      :1 ;
        u32 BR1      :1 ;
        u32 BR2      :1 ;
        u32 BR3      :1 ;
        u32 BR4      :1 ;
        u32 BR5      :1 ;
        u32 BR6      :1 ;
        u32 BR7      :1 ;
        u32 BR8      :1 ;
        u32 BR9      :1 ;
        u32 BR10     :1 ;
        u32 BR11     :1 ;
        u32 BR12     :1 ;
        u32 BR13     :1 ;
        u32 BR14     :1 ;
        u32 BR15     :1 ;
        u32 Reserved :16;
    }bits;
    
}GPIO_BRR_t;

/**
 * @brief GPIO Configuration Lock Register and its bits.
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 LCK0     :1 ;
        u32 LCK1     :1 ;
        u32 LCK2     :1 ;
        u32 LCK3     :1 ;
        u32 LCK4     :1 ;
        u32 LCK5     :1 ;
        u32 LCK6     :1 ;
        u32 LCK7     :1 ;
        u32 LCK8     :1 ;
        u32 LCK9     :1 ;
        u32 LCK10    :1 ;
        u32 LCK11    :1 ;
        u32 LCK12    :1 ;
        u32 LCK13    :1 ;
        u32 LCK14    :1 ;
        u32 LCK15    :1 ;
        u32 LCKK     :1 ;
        u32 Reserved :15 ;
    }bits;
    
}GPIO_LCKR_t;

/**
 * @brief GPIO Registers Structure.
 */
typedef struct 
{
    volatile GPIO_CRL_t GPIO_CRL  ;
    volatile GPIO_CRH_t GPIO_CRH  ;
    volatile GPIO_IDR_t GPIO_IDR  ;
    volatile GPIO_ODR_t GPIO_ODR  ;
    volatile GPIO_BSRR_t GPIO_BSRR;
    volatile GPIO_BRR_t GPIO_BRR  ;
    volatile GPIO_LCKR_t GPIO_LCKR;
}GPIO_reg_t;


/**
 * @section Defintions 
*/

/**
 * @brief GPIO Registers base address
 */
#define GPIOA_BASE          0x40010800
#define GPIOB_BASE          0x40010C00
#define GPIOC_BASE          0x40011000
#define GPIOD_BASE          0x40011400
#define GPIOE_BASE          0x40011800

/**
 * @brief Mapping of GPIO Registers to memory.
 */
#define GPIO_A_REG      ((GPIO_reg_t *)(GPIOA_BASE))
#define GPIO_B_REG      ((GPIO_reg_t *)(GPIOB_BASE))
#define GPIO_C_REG      ((GPIO_reg_t *)(GPIOC_BASE))

/**
 * @brief Map GPIO Port number to GPIO Peripheral number 
 */
#define PORT_TO_PERIPHERAL      34U

/**
 * @brief Map Pin number to its configuration bits
 */
#define PIN_CFG_SHIFT           4U
#define GPIO_PIN_DIFF           8U
/**
 * @brief GPIO Pin  masks
 */
#define PIN_CFG_MASK            0x0000000F  /* Pin configuration mask */
#define PIN_LEVEL_MASK          0x00000001  /* Pin level mask */
/**
 * @brief Reset Values
 */
#define RESET_BY_ZERO           0x00000000

#endif
