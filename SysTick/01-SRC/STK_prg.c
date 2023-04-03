/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-04-01 23:11:23                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-04-03 22:48:58                              *
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
static void (*ISR_FUNC)(void) = STD_NULL;

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
 */
std_errorStatus_t STK_set_period_us(u32 local_u32Pertiod)
{

}

/**
 * @brief This API is used to enable SysTick.
 * @return Error state which describes the state of API (Passed or failed). 
 */
std_errorStatus_t STK_start(void)
{

}

/**
 * @brief This API is used to disable SysTick.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t STK_stop(void)
{

}

/**
 * @brief This API is used to set callback function that will be used for ISR.
 * @param local_cb_func is a pointer to function which will be used as ISR function.
 * @return Error state which describes the state of API (Passed or failed). 
 */
std_errorStatus_t STK_set_callback_function (void(*local_cb_func)(void))
{
    
}
