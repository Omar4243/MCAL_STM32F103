/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-04-01 23:11:48                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-04-04 13:50:15                              *
 * @FilePath              : STK_int.h                                        *
 ****************************************************************************/

#ifndef STK_INT_H_
#define STK_INT_H_

/**
 * @section Includes
*/

#include "std_type.h"
#include "bit_math.h"

/**
 * @section APIs
*/

std_errorStatus_t STK_init                  (void);
std_errorStatus_t STK_set_period_us         (u32 local_u32Clk_KHZ, u32 local_u32Pertiod);
void STK_start                              (void);
void STK_stop                               (void);
std_errorStatus_t STK_set_callback_function (void(*local_cb_func)(void));

#endif