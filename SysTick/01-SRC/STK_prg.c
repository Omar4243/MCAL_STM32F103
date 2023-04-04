/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-04-01 23:11:23                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-04-04 13:53:56                              *
 * @FilePath              : STK_prg.c                                        *
 ****************************************************************************/

/**
 * @section Includes 
*/
#include "STK_priv.h"
#include "STK_cfg.h"
#include "STK_int.h"

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
 * @param local_u32Clk_KHZ is the SysTick clock in KHz.
 * @return Error state which describes the state of API (Passed or failed). 
 * @note The result of (local_u32Pertiod * local_u32Clk_KHZ) must not exceed the value 0x00FFFFFF.
 */
std_errorStatus_t STK_set_period_us(u32 local_u32Clk_KHZ, u32 local_u32Pertiod)
{
     
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
