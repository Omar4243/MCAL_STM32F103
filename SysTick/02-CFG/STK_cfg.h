/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-04-01 23:13:02                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-04-03 22:39:29                              *
 * @FilePath              : STK_cfg.h                                        *
 ****************************************************************************/

#ifndef STK_CFG_H_
#define STK_CFG_H_

/**
 * @section Options
*/

/**
 * @brief SysTick clock source options
 */
#define STK_AHB_CLK_DIV_BY_8        0U  /* AHB clock / 8 will be used as SysTick Source clock */
#define STK_AHB_CLK                 1U  /*   AHB clock will be used as SysTick source clock   */

/**
 * @brief SysTick exception request options
 */
#define STK_EXCEPTION_REQ_DISABLE   0U  /* Systick interrupt is disabled when counts down to 0 */
#define STK_EXCEPTION_REQ_ENABLE    1U  /* Systick interrupt is enabled when counts down to 0  */

/**
 * @section Configurations
*/

/**
 * @brief SysTick clock source configuration
 * Options (STK_AHB_CLK_DIV_BY_8, STK_AHB_CLK)
 */

#define STK_CLK_SRC     STK_AHB_CLK

/**
 * @brief SysTick exception request configuration
 * Options (STK_EXCEPTION_REQ_DISABLE, STK_EXCEPTION_REQ_ENABLE)
 */

#define STK_EXCEPTION_REQ_STATE     STK_EXCEPTION_REQ_ENABLE

#endif