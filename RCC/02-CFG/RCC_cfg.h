/*****************************************************************************
 * @Author                : Islam Tarek<islamtarek0550@gmail.com>            *
 * @CreatedDate           : 2023-03-09 00:36:39                              *
 * @LastEditors           : Islam Tarek<islamtarek0550@gmail.com>            *
 * @LastEditDate          : 2023-03-14 00:12:46                              *
 * @FilePath              : RCC_cfg.h                                        *
 * @CopyRight             : Islam Tarek CopyRight                            *
 ****************************************************************************/

#ifndef RCC_CFG_H_
#define RCC_CFG_H_

/*********************************************************************************************/
/*                                      Options Section                                      */
/*********************************************************************************************/

/**
 * @brief Clock Source options
 */

#define HSI   0U  /* Internal High Speed Clock (8 MHZ)                                  */
#define HSE   1U  /* External High Speed Clock (4 to 16 MHZ and up to 25 MHZ if bypass) */
#define PLL   2U  

/**
 * @brief HSE Clock Source options
 */

#define HSE_NOT_BYPASS  0U
#define HSE_BYPASS      1U

/**
 * @brief PLL cClock Source options
 */
#define HSI_CLK_DIV_BY_2   0U  /* HSI / 2 will be PLL source        */
#define HSE_CLK            1U  /* HSE or HSE / 2 will be PLL source */
#define HSE_CLK_DIV_BY_2   3U  /* HSE / 2 will be PLL source */

/**
 * @brief PLL Multiplication factor options
 */

#define PLL_CLK_MUL_BY_2    0U  /* PLL input clock *  2 */
#define PLL_CLK_MUL_BY_3    1U  /* PLL input clock *  3 */
#define PLL_CLK_MUL_BY_4    2U  /* PLL input clock *  4 */
#define PLL_CLK_MUL_BY_5    3U  /* PLL input clock *  5 */
#define PLL_CLK_MUL_BY_6    4U  /* PLL input clock *  6 */
#define PLL_CLK_MUL_BY_7    5U  /* PLL input clock *  7 */
#define PLL_CLK_MUL_BY_8    6U  /* PLL input clock *  8 */
#define PLL_CLK_MUL_BY_9    7U  /* PLL input clock *  9 */
#define PLL_CLK_MUL_BY_10   8U  /* PLL input clock * 10 */
#define PLL_CLK_MUL_BY_11   9U  /* PLL input clock * 11 */
#define PLL_CLK_MUL_BY_12   10U /* PLL input clock * 12 */
#define PLL_CLK_MUL_BY_13   11U /* PLL input clock * 13 */
#define PLL_CLK_MUL_BY_14   12U /* PLL input clock * 14 */
#define PLL_CLK_MUL_BY_15   13U /* PLL input clock * 15 */
#define PLL_CLK_MUL_BY_16   15U /* PLL input clock * 16 */


/**
 * @brief Clock Security System (CSS) options
 */

#define CSS_DISABLE   0U  /* Disable Clock Securtiy System */
#define CSS_ENABLE    1U  /* Enable Clock Security System  */

/**
 * todo HSI Clock Trimming options
 */


/**
 * @brief Micro_controller Clock Output (MCO) options
 */

#define MCO_NO_CLK             0U  /* MCO will not output a clock                                */
#define MCO_SYSCLK             4U  /* Output of MCO Pin will be the system clock                 */
#define MCO_HSI_CLK            5U  /* Output of MCO Pin will be the high speed Internal RC clock */
#define MCO_HSE_CLK            6U  /* Output of MCO pin will be the high speed External clock    */
#define MCO_PLL_CLK_DIV_BY_2   7U  /* Output of MCO pin will be output of PLL / 2                */

/**
 * @brief AHB Clock Pre_scaler options
 */

#define SYSCLK              0U  /* AHB Clock will be the System Clock       */
#define SYSCLK_DIV_BY_2     8U  /* AHB Clock will be the System Clock / 2   */
#define SYSCLK_DIV_BY_4     9U  /* AHB Clock will be the System Clock / 4   */
#define SYSCLK_DIV_BY_8     10U /* AHB Clock will be the System Clock / 8   */
#define SYSCLK_DIV_BY_16    11U /* AHB Clock will be the System Clock / 16  */
#define SYSCLK_DIV_BY_64    12U /* AHB Clock will be the System Clock / 64  */
#define SYSCLK_DIV_BY_128   13U /* AHB Clock will be the System Clock / 128 */
#define SYSCLK_DIV_BY_256   14U /* AHB Clock will be the System Clock / 256 */
#define SYSCLK_DIV_BY_512   15U /* AHB Clock will be the System Clock / 512 */

/**
 * @brief APB Clock Pre_scaler options
 */

#define HCLK             0U  /* APB Clock will be same as AHB Clock */
#define HCLK_DIV_BY_2    4U  /* APB Clock will be AHB Clock / 2     */
#define HCLK_DIV_BY_4    5U  /* APB Clock will be AHB Clock / 4     */
#define HCLK_DIV_BY_8    6U  /* APB Clock will be AHB Clock / 8     */
#define HCLK_DIV_BY_16   7U  /* APB Clock will be AHB Clock / 16    */

/**
 * @brief USB Clock Pre_scaler options.
 */

#define PLL_CLK_DIV_BY_1_5   0U  /* USB clock will be PLL clock / 1.5 */
#define PLL_CLK              1U  /* USB clock will be PLL clock       */

/**
 * @brief ADC Clock Pre_scaler options.
 */

#define PCLK2_DIV_BY_2   0U  /* ADC Clock will be APB2 Clock / 2 */
#define PCLK2_DIV_BY_4   1U  /* ADC Clock will be APB2 Clock / 4 */
#define PCLK2_DIV_BY_6   2U  /* ADC Clock will be APB2 Clock / 6 */
#define PCLK2_DIV_BY_8   3U  /* ADC Clock will be APB2 Clock / 8 */


/*********************************************************************************************/
/*                                  Configuration Section                                    */
/*********************************************************************************************/

/**
 * @brief System Clock Configuration
 * * Options (HSI, HSE, PLL)
 */

#define SYSCLK_SRC              HSI

/**
 * @brief HSE Clock Configuration
 * * Options (HSE_NOT_BYPASS, HSE_BYPASS)
 */

#define HSE_CLK_SRC     HSE_NOT_BYPASS

/**
 * @brief PLL Clock Configuration
 * * Options (HSI_CLK_DIV_BY_2, HSE_CLK, HSE_CLK_DIV_BY_2)
 * !Note: PLL source can be selected only when PLL is disabled.
 */

#define PLL_CLK_SRC             HSI_CLK_DIV_BY_2 

/**
 * @brief PLL Multiplication Factor Configuration
 * * Options (PLL_CLK_MUL_BY_2, PLL_CLK_MUL_BY_3, PLL_CLK_MUL_BY_4, PLL_CLK_MUL_BY_5, PLL_CLK_MUL_BY_6, PLL_CLK_MUL_BY_7, PLL_CLK_MUL_BY_8 ,PLL_CLK_MUL_BY_9,
 * *          PLL_CLK_MUL_BY_10, PLL_CLK_MUL_BY_11, PLL_CLK_MUL_BY_12, PLL_CLK_MUL_BY_13, PLL_CLK_MUL_BY_14, PLL_CLK_MUL_BY_15, PLL_CLK_MUL_BY_16)
 * !Note: PLL Multiplication factor can be set only when PLL is disabled.
 * !Note: PLL output frequency must not exceed 72 MHZ.
 */

#define PLL_MUL_FACTOR          PLL_CLK_MUL_BY_2

/**
 * @brief Clock System Security (CSS) Configuration
 * * Options (CSS_DISABLE, CSS_ENABLE)
 */

#define CSS                     CSS_DISABLE

/**
 * @brief Micro_controller output (MCO) Configuration
 * * Options (MCO_NO_CLK, MCO_SYSCLK, MCO_HSI_CLK, MCO_HSE_CLK, MCO_PLL_CLK_DIV_BY_2)
 * !Note: Make sure that output clock doesn't exceed 50 MHZ.
 * !Note: MCO pin on blue pill is PA8 pin.
 */

#define MCO_CLK                 MCO_NO_CLK

/**
 * @brief AHB CLock Pre_scaler Configuration
 * * Options (SYSCLK, SYSCLK_DIV_BY_2, SYSCLK_DIV_BY_4, SYSCLK_DIV_BY_8, SYSCLK_DIV_BY_16, 
 * *          SYSCLK_DIV_BY_64, SYSCLK_DIV_BY_128, SYSCLK_DIV_BY_256, SYSCLK_DIV_BY_512)
 * !Note: SYSCLK is the clock of the system. 
 * !Note: The Maximum allowed Speed for AHB Bus is 72 MHZ
 */

#define AHB_CLK_PRESCALER       SYSCLK

/**
 * @brief APB cLock Pre_scaler Configuration
 * * Options (HCLK, HCLK_DIV_BY_2, HCLK_DIV_BY_4, HCLK_DIV_BY_8, HCLK_DIV_BY_16)
 * !Note: HCLK is the the clock of AHB Bus
 * !Note: The maximum allowed frequency for APB2 Bus is 72 MHZ
 * !Note: The maximum allowed frequency for APB1 Bus is 36 MHZ 
 */

#define APB2_CLK_PRESCALER      HCLK
#define APB1_CLK_PRESCALER      HCLK_DIV_BY_2

/**
 * @brief USB Clock Pre_scaler Configuration
 * * Options (PLL_CLK_DIV_BY_1_5, PLL_CLK)
 * !Note: USB Pre_scaler must be valid before enabling USB clock.
 * !Note: USB clock is 48 MHZ.
 */

#define USB_CLK_PRESCALER       PLL_CLK

/**
 * @brief ADC Clock Pre_scaler Configuration
 * * Options (PCLK2_DIV_BY_2, PCLK2_DIV_BY_4, PCLK2_DIV_BY_6, PCLK2_DIV_BY_8)
 * !Note: PCLK2 is the clock of the APB2 Bus
 */

#define ADC_CLK_PRESCALER       PCLK2_DIV_BY_2

#endif 