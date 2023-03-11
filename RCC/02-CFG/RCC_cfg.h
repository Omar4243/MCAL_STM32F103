/*****************************************************************************
 * @Author                : Islam Tarek<islam.tarek@valeo.com>               *
 * @CreatedDate           : 2023-03-09 00:36:39                              *
 * @LastEditors           : Islam Tarek<islam.tarek@valeo.com>               *
 * @LastEditDate          : 2023-03-09 10:44:38                              *
 * @FilePath              : RCC_cfg.h                                        *
 ****************************************************************************/

#ifndef RCC_CFG_H_
#define RCC_CFG_H_

/**
 * @brief Clock Source options
 */

#define PLL             0U  
#define HSE             1U  /* External High Speed Clock (4 to 16 MHZ and up to 25 MHZ if bypass) */
#define HSI             2U  /* Internal High Speed Clock (8 MHZ)  */
#define LSE             3U  /* External Low Speed Clock  (32 KHZ) */
#define LSI             4U  /* Internal Low Speed Clock  (40 KHZ) */

/**
 * @brief Clock Security System (CSS) options
 */

#define CSS_DISABLE     0U  /* Disable Clock Securtiy System */
#define CSS_ENABLE      1U  /* Enable Clock Security System */

/**
 * todo HSI Clock Trimming options
 */


/**
 * @brief Microcontroller Clock Output opitons
 * !Note: Make sure that output clock doesn't exceed 50 MHZ.
 * !Note: MCO pin on blue pill is PA8 pin.
 */

#define MCO_NO_CLK              0U  /* MCO will not output a clock */
#define MCO_SYSCLK              4U  /* Output of MCO Pin will be the system clock */
#define MCO_HSI_CLK             5U  /* Output of MCO Pin will be the high speed Internal RC clock */
#define MCO_HSE_CLK             6U  /* Output of MCO pin will be the high speed External clock */
#define MCO_PLL_CLK_DIV_BY_2    7U  /* Output of MCO pin will be output of PLL divided by 2 */

#endif 