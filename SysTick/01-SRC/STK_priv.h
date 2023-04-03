/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-04-01 23:12:18                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-04-03 22:07:02                              *
 * @FilePath              : STK_priv.h                                       *
 ****************************************************************************/

#ifndef STK_PRIV_H_
#define STK_PRIV_H_

/**
 * @section Includes
*/
#include "std_type.h"

/**
 * @section Typedefs
*/

/**
 * @brief SysTick Control and Status Register and its bits.
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 ENABLE      : 1 ;
        u32 TICKINT     : 1 ;
        u32 CLKSOURCE   : 1 ;
        u32 Reserved_0  : 13;
        u32 COUNT_FLAG  : 1 ;
        u32 Reserved_1  : 15;
    }bits;  
}STK_CTRL_t;

/**
 * @brief SysTick Reload Value Register and its bits.
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 RELOAD      : 24;
        u32 Reserved    : 8 ;
    }bits;
}STK_LOAD_t;

/**
 * @brief SysTick Current Value Register and its bits.
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 CURRENT     : 24;
        u32 Reserved    : 8 ;
    }bits;
}STK_VAL_t;

/**
 * @brief SysTick Calibration Value Register and its bits, (read only register). 
 */
typedef union 
{
    u32 reg;
    struct 
    {
        u32 TENMS       : 24;
        u32 Reserved    : 6 ;  
        u32 SKEW        : 1 ;
        u32 NOREF       : 1 ;
    }bits;
}STK_CALIB_t;

/**
 * @brief SysTick Registers Structure.
 */
typedef struct 
{
    volatile STK_CTRL_t STK_CTRL   ;
    volatile STK_LOAD_t STK_LOAD   ;
    volatile STK_VAL_t STK_VAL     ;
    volatile STK_CALIB_t STK_CALIB ;
}STK_reg_t;


/**
 * @section Definitions
*/

/**
 * @brief SysTick Registers Base Address
 */
#define STK_BASE      0xE000E010    

/**
 * @brief Map SysTick Registers to Memory 
 */
#define STK_REG      ((STK_reg_t *)(STK_BASE))   

/**
 * @brief SysTick counter options
 */
#define STK_COUNTER_DISABLE         0U  /* Disable SysTick */
#define STK_COUNTER_ENABLE          1U  /* Enable Systick  */


#endif