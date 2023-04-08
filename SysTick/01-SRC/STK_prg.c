/*****************************************************************************
 * @Author                : Islam Tarek<islamtarek0550@gmail.com>            *
 * @CreatedDate           : 2023-04-01 23:11:23                              *
 * @LastEditors           : Islam Tarek<islamtarek0550@gmail.com>            *
 * @LastEditDate          : 2023-04-08 16:00:15                              *
 * @FilePath              : STK_prg.c                                        *
 ****************************************************************************/

/**
 * @section Includes 
*/
#include "STK_priv.h"
#include "STK_cfg.h"
#include "STK_int.h"
#include "RCC_int.h"

/**
 * @section Global Variables
*/

/**
 * @brief Global Pointer to function
 */
static void (*STK_ISR_FUNC)(void) = STD_NULL;

/**
 * @section APIs Implementation
*/

/**
 * @brief This API is used to Initialize SysTick
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t STK_init(void)
{
    std_errorStatus_t error_state = STD_OK;

    /* Set SysTick clock source */
    #if ((STK_CLK_SRC == STK_AHB_CLK_DIV_BY_8) || (STK_CLK_SRC == STK_AHB_CLK))
        ((STK_REG -> STK_CTRL).bits.CLKSOURCE) =  STK_CLK_SRC;
    #else
        error_state = STD_NOT_VALID_VALUE;
    #endif

    /* Set SysTick exception request state */
    #if((STK_EXCEPTION_REQ_STATE == STK_EXCEPTION_REQ_DISABLE) || (STK_EXCEPTION_REQ_STATE == STK_EXCEPTION_REQ_ENABLE))
        ((STK_REG -> STK_CTRL).bits.TICKINT) = STK_EXCEPTION_REQ_STATE;
    #else
        error_state = STD_NOT_VALID_VALUE;
    #endif

    return error_state;
}

/**
 * @brief This API is used to set the period in micro seconds.
 * @param local_u32Pertiod is the period in micor seconds at which action will be taken.
 * @return Error state which describes the state of API (Passed or failed). 
 * @note The result of ((local_u32Pertiod * stk_clk) / 1000) must not exceed the value 0x00FFFFFF.
 */
std_errorStatus_t STK_set_period_us(u32 local_u32Pertiod)
{
    std_errorStatus_t error_state = STD_OK;
    RCC_clk_t clocks = {
        STD_u32MIN_VALUE,
        STD_u32MIN_VALUE,
        STD_u32MIN_VALUE,
        STD_u32MIN_VALUE
    };
    u32 AHB_clk_KHZ = STD_u32MIN_VALUE;
    u32 STK_clk_KHZ = STD_u32MIN_VALUE;

    /* Get clocks' values */
    error_state = RCC_get_clk_value(&clocks);

    /* Get AHb clock value */
    AHB_clk_KHZ = clocks.AHB_clk_KHZ;

    /* Calculate systick clock value */
    #if(STK_CLK_SRC == STK_AHB_CLK)
        STK_clk_KHZ = AHB_clk_KHZ;
    #elif(STK_CLK_SRC == STK_AHB_CLK_DIV_BY_8)
        STK_clk_KHZ = AHB_clk_KHZ >> DIV_BY_8;
    #else
        error_state = STD_NOT_VALID_VALUE;
    #endif

    /* Calculate the Load Value */
    u64 STK_u32Load_Value = (((u64)(STK_clk_KHZ * (u64)local_u32Pertiod)) / CONVERT_FROM_MS_TO_US);
    
    /* Check if the calculated load Value in the accepted range of the load register or not */
    if( STK_u32Load_Value <= LOAD_REG_MAX_VALUE)
    {
        /* Update the load register */
        ((STK_REG -> STK_LOAD).bits.RELOAD) = STK_u32Load_Value - STK_MODE;
    }
    else
    {
        error_state = STD_NOT_VALID_VALUE;
    }

    return error_state;
}

/**
 * @brief This API is used to enable SysTick.
 */
void STK_start(void)
{
    /* Enable SysTick */
    ((STK_REG -> STK_CTRL).bits.ENABLE) = STK_COUNTER_ENABLE;
}

/**
 * @brief This API is used to disable SysTick.
 */
void STK_stop(void)
{
    /* Disable SysTick */
    ((STK_REG -> STK_CTRL).bits.ENABLE) = STK_COUNTER_DISABLE;
}

/**
 * @brief This API is used to set callback function that will be used for ISR.
 * @param local_cb_func is a pointer to function which will be used as ISR function.
 * @return Error state which describes the state of API (Passed or failed). 
 */
std_errorStatus_t STK_set_callback_function(void(*local_cb_func)(void))
{
    std_errorStatus_t error_state = STD_OK;

    /* Check that the pointer doesn't point to NULL */
    if(local_cb_func != STD_NULL)
    {
        /* Set the ISR function poiter by the local function pointer */
        STK_ISR_FUNC = local_cb_func;
    }
    else
    {
        error_state = STD_NULL_POINTER;
    }

    return error_state;
}

void SysTick_handler(void)
{
    u8 flag_reading = FLAG_NOT_READ;
    
    /* Check if there is call back function or not */
    if(STK_ISR_FUNC != STD_NULL)
    {
        /* Call the callback function */
        STK_ISR_FUNC();
    }
    else
    {
        /* Do Nothing */
    }

    /* Clear flag */
    flag_reading  = CHECK_BIT((STK_REG -> STK_CTRL.reg), (STK_REG -> STK_CTRL.bits.COUNT_FLAG));
}