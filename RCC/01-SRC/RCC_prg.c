/*****************************************************************************
 * @Author                : Islam Tarek<islamtarek0550@gmail.com>            *
 * @CreatedDate           : 2023-03-11 21:14:58                              *
 * @LastEditors           : Islam Tarek<islamtarek0550@gmail.com>            *
 * @LastEditDate          : 2023-03-29 17:38:26                              *
 * @FilePath              : RCC_prg.c                                        *
 * @CopyRight             : Islam Tarek CopyRight                            *
 ****************************************************************************/

/**
 * @section Includes
*/

#include "RCC_priv.h"
#include "RCC_cfg.h"
#include "RCC_int.h"

/**
 * @section APIs Implementation
*/

/**
 * @brief  This API is used to initialize RCC driver with the given configurations.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t RCC_init(void)
{
    std_errorStatus_t error_state = STD_OK;
    
    /* Configure clock security system */
    #if (CSS == CSS_DISABLE || CSS_ENABLE)
        RCC_REG->RCC_CR.bits.CSSON = CSS;
    # else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif 
    
    /* Set System clock Source */
    #if (SYSCLK_SRC == HSI || SYSCLK_SRC == HSE || SYSCLK_SRC == PLL)
        RCC_REG->RCC_CFGR.bits.SW = SYSCLK_SRC;
        
        #if SYSCLK_SRC == HSI
            /* Turn HSI oscillator on */
            RCC_REG->RCC_CR.bits.HSION = OSC_ON;
            /* Turn other oscillators off */
            RCC_REG->RCC_CR.bits.HSEON = OSC_OFF;
            RCC_REG->RCC_CR.bits.PLLON = OSC_OFF;
            /* Wait until the HSI oscillator is ready */
            while (!(RCC_REG->RCC_CR.bits.HSIRDY));
        #elif SYSCLK_SRC == HSE
            /* Set HSE clock source */
            RCC_REG -> RCC_CR.bits.HSEBYP = HSE_CLK_SRC;
            /* Turn HSE oscillator on */
            RCC_REG -> RCC_CR.bits.HSEON = OSC_ON;
            /* Turn other oscillators off */
            RCC_REG->RCC_CR.bits.HSION = OSC_OFF;
            RCC_REG->RCC_CR.bits.PLLON = OSC_OFF;

            /* Wait until the HSE oscillator is ready */
            while(!(RCC_REG -> RCC_CR.bits.HSERDY));
        #else 
            /* Set PLL clock Source */
            #if(PLL_CLK_SRC == HSI_CLK_DIV_BY_2 || PLL_CLK_SRC == HSE_CLK || PLL_CLK_SRC == HSE_CLK_DIV_BY_2)
                RCC_REG -> RCC_CFGR.bits.PLLSRC = PLL_CLK_SRC;
            #else
                /* Option doesn't exist */
                error_state = STD_NOT_VALID_VALUE;  
            #endif 
            
            /* Set PLL multiplication factor */
            #if(PLL_MUL_FACTOR >= PLL_CLK_MUL_BY_2 && PLL_MUL_FACTOR <= PLL_CLK_MUL_BY_16)
                RCC_REG -> RCC_CFGR.bits.PLLMUL = PLL_MUL_FACTOR;
            #else
                /* Option doesn't exist */
                error_state = STD_NOT_VALID_VALUE;  
            #endif
            
            /* Turn PLL oscillator on */
            RCC_REG -> RCC_CR.bits.PLLON = OSC_ON;
            /* Turn other oscillators off */
            RCC_REG->RCC_CR.bits.HSION = OSC_OFF;
            RCC_REG->RCC_CR.bits.HSEON = OSC_OFF;
            /* Wait until the PLL oscillator is ready */
            while(!(RCC_REG -> RCC_CR.bits.PLLRDY));
        #endif
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif
    
    /* Set AHB clock pre_scaler */
    # if(AHB_CLK_PRESCALER >= SYSCLK && AHB_CLK_PRESCALER <= SYSCLK_DIV_BY_512)
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif
    
    /* Set APB2 clock pre_scaler */
    #if(APB2_CLK_PRESCALER >= HCLK && APB2_CLK_PRESCALER <= HCLK_DIV_BY_16 )
        RCC_REG -> RCC_CFGR.bits.PPRE2 = APB2_CLK_PRESCALER;
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif 
    
    /* Set APB1 clock pre_scaler */
    #if(APB1_CLK_PRESCALER >= HCLK && APB1_CLK_PRESCALER <= HCLK_DIV_BY_16 )
        RCC_REG -> RCC_CFGR.bits.PPRE1 = APB1_CLK_PRESCALER;
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif
    
    /*  Configure micro_controller output (MCO)  */
    #if (MCO_CLK >= MCO_NO_CLK && MCO_CLK <= MCO_PLL_CLK_DIV_BY_2)
        RCC_REG -> RCC_CFGR.bits.MCO = MCO_CLK;
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif
    
    /* Set USB clock pre_scaler */
    #if (USB_CLK_PRESCALER == PLL_CLK_DIV_BY_1_5 || USB_CLK_PRESCALER == PLL_CLK)
        RCC_REG -> RCC_CFGR.bits.USBPRE = USB_CLK_PRESCALER;
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif
    
    /* Set ADC clock pre_scaler */
    #if (ADC_CLK_PRESCALER >= PCLK2_DIV_BY_2 && ADC_CLK_PRESCALER <= PCLK2_DIV_BY_8)
        RCC_REG -> RCC_CFGR.bits.ADCPRE = ADC_CLK_PRESCALER;
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif 
    
    return error_state;
}

/**
 * @brief This API is used to Enable the clock for the given Peripheral.
 * @param local_enuPeripheral The peripheral whose clock will be enabled.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t RCC_enable_peripheral_clk (RCC_peripheral_t local_enuPeripheral)
{
    std_errorStatus_t error_state = STD_OK;
    /* Check peripheral belongs to which bus */
    if(local_enuPeripheral >= AHB_MIN_LIMIT && local_enuPeripheral < AHB_MAX_LIMIT)
    {
        /* Enable Peripheral Clock */
        SET_BIT((RCC_REG -> RCC_AHBENR.reg), local_enuPeripheral);
    }
    else if(local_enuPeripheral >= APB2_MIN_LIMIT && local_enuPeripheral < APB2_MAX_LIMIT)
    {
        /* Enable Peripheral Clock */
        SET_BIT((RCC_REG -> RCC_APB2ENR.reg), (local_enuPeripheral - APB2_MIN_LIMIT));
    }
    else if(local_enuPeripheral >= APB1_MIN_LIMIT && local_enuPeripheral < APB1_MAX_LIMIT)
    {
        /* Enable Peripheral Clock */
        SET_BIT((RCC_REG -> RCC_APB1ENR.reg), (local_enuPeripheral - APB1_MIN_LIMIT));
    }
    else
    {
        /* Peripheral does not exist */
        error_state = STD_NOK;
    }

    return error_state;
}

/**
 * @brief This API is used to disable the clock for the given Peripheral.
 * @param local_enuPeripheral The peripheral whose clock will be disabled.
 * @return Error state which describes the state of API (Passed or failed). 
 */
std_errorStatus_t RCC_disable_peripheral_clk(RCC_peripheral_t local_enuPeripheral)
{
    std_errorStatus_t error_state = STD_OK;
    /* Check peripheral belongs to which bus */
    if(local_enuPeripheral >= AHB_MIN_LIMIT && local_enuPeripheral < AHB_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
    	CLEAR_BIT((RCC_REG -> RCC_AHBENR.reg), local_enuPeripheral);
    }
    else if(local_enuPeripheral >= APB2_MIN_LIMIT && local_enuPeripheral < APB2_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
    	CLEAR_BIT((RCC_REG -> RCC_APB2ENR.reg), (local_enuPeripheral - APB2_MIN_LIMIT));
    }
    else if(local_enuPeripheral >= APB1_MIN_LIMIT && local_enuPeripheral < APB1_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
    	CLEAR_BIT((RCC_REG -> RCC_APB1ENR.reg), (local_enuPeripheral - APB1_MIN_LIMIT));
    }
    else
    {
        /* Peripheral not existed */
        error_state = STD_NOK;
    }

    return error_state;
}

/**
 * @brief This API is used to reset the given Peripheral.
 * @param local_enuPeripheral The peripheral which will be reset.
 * @return Error state which describes the state of API (Passed or failed). 
 */
std_errorStatus_t RCC_reset_peripheral(RCC_peripheral_t local_enuPeripheral)
{
    std_errorStatus_t error_state = STD_OK;
    /* Check peripheral belongs to which bus */
    if(local_enuPeripheral >= APB2_MIN_LIMIT && local_enuPeripheral < APB2_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
    	SET_BIT((RCC_REG -> RCC_APB2RSTR.reg), (local_enuPeripheral - APB2_MIN_LIMIT));
    }
    else if(local_enuPeripheral >= APB1_MIN_LIMIT && local_enuPeripheral < APB1_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
    	SET_BIT((RCC_REG -> RCC_APB1RSTR.reg), (local_enuPeripheral - APB1_MIN_LIMIT));
    }
    else
    {
        /* Peripheral not existed */
        error_state = STD_NOK;
    }

    return error_state;
}