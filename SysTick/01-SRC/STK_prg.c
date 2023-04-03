/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-04-01 23:11:23                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-04-03 22:32:18                              *
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
