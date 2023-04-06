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
 * @section Global Variables
 */

/**
 * @brief Pointer to clock structure 
 */

RCC_clk_t* CLK_VALUE = STD_NULL;

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
            /* Update source clock value */
            CLK_VALUE -> SYS_clk_KHZ = RCC_8_MHZ;
            /* Turn other oscillators off */
            RCC_REG->RCC_CR.bits.HSEON = OSC_OFF;
            RCC_REG->RCC_CR.bits.PLLON = OSC_OFF;
            /* Wait until the HSI oscillator is ready */
            while (!(RCC_REG->RCC_CR.bits.HSIRDY));
        #elif SYSCLK_SRC == HSE
            /* Set HSE clock source */
            RCC_REG -> RCC_CR.bits.HSEBYP = HSE_CLK_SRC;
            #if (HSE_CLK_SRC == HSE_NOT_BYPASS)
                /* Check that the clock is in the available range for not bypass clock or not */
                #if(HSE_CLK_VAL_KHZ >= RCC_4_MHZ && HSE_CLK_VAL_KHZ <= RCC_16_MHZ)
                    /* Update source clock value */
                    CLK_VALUE -> SYS_clk_KHZ = HSE_CLK_VAL_KHZ;
                #else
                    /* Option doesn't exist */
                    error_state = STD_NOT_VALID_VALUE;  
                #endif
            #elif (HSE_CLK_SRC == HSE_BYPASS)
                /* Check that the clock is in the available range for not bypass clock or not */
                #if(HSE_CLK_VAL_KHZ >= RCC_4_MHZ && HSE_CLK_VAL_KHZ <= RCC_25_MHZ)
                    /* Update source clock value */
                    CLK_VALUE -> SYS_clk_KHZ = HSE_CLK_VAL_KHZ;
                #else
                    /* Option doesn't exist */
                    error_state = STD_NOT_VALID_VALUE;  
                #endif
            #else
                /* Option doesn't exist */
                error_state = STD_NOT_VALID_VALUE; 
            #endif

            /* Turn HSE oscillator on */
            RCC_REG -> RCC_CR.bits.HSEON = OSC_ON;
            /* Turn other oscillators off */
            RCC_REG->RCC_CR.bits.HSION = OSC_OFF;
            RCC_REG->RCC_CR.bits.PLLON = OSC_OFF;

            /* Wait until the HSE oscillator is ready */
            while(!(RCC_REG -> RCC_CR.bits.HSERDY));
        #else 
            #if(PLL_CLK_SRC == HSI_CLK_DIV_BY_2)
                /* Set PLL clock Source */
                RCC_REG -> RCC_CFGR.bits.PLLSRC = PLL_CLK_SRC;
                /* Update source clock value */
                CLK_VALUE -> SYS_clk_KHZ = RCC_4_MHZ;
            #elif(PLL_CLK_SRC == HSE_CLK)
                /* Set PLL clock Source */
                RCC_REG -> RCC_CFGR.bits.PLLSRC = PLL_CLK_SRC;
                /* Update source clock value */
                CLK_VALUE -> SYS_clk_KHZ = HSE_CLK_VAL_KHZ;
            #elif(PLL_CLK_SRC == HSE_CLK_DIV_BY_2)
                /* Set PLL clock Source */
                RCC_REG -> RCC_CFGR.bits.PLLSRC = PLL_CLK_SRC;
                /* Update source clock value */
                CLK_VALUE -> SYS_clk_KHZ = HSE_CLK_VAL_KHZ >> DIV_BY_2;
            #else
                /* Option doesn't exist */
                error_state = STD_NOT_VALID_VALUE; 
            #endif 
            
            /* Check if multiplication factor is in range or not */
            #if(PLL_MUL_FACTOR >= PLL_CLK_MUL_BY_2 && PLL_MUL_FACTOR <= PLL_CLK_MUL_BY_16)
                /* Set PLL multiplication factor */
                RCC_REG -> RCC_CFGR.bits.PLLMUL = PLL_MUL_FACTOR;
                /* Update source clock value */
                CLK_VALUE -> SYS_clk_KHZ *= (PLL_MUL_FACTOR + PLL_MUL_MAP_VAL_2);
            #elif(PLL_MUL_FACTOR == (PLL_CLK_MUL_BY_16 + PLL_MUL_END_VALIDATE))
                /* Set PLL multiplication factor */
                RCC_REG -> RCC_CFGR.bits.PLLMUL = PLL_MUL_FACTOR;
                /* Update source clock value */
                CLK_VALUE -> SYS_clk_KHZ *= (PLL_MUL_FACTOR + PLL_MUL_MAP_VAL_1);
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
    
    /* Cheeck if AHB clock pre_scaler is accepted or not */
    # if(AHB_CLK_PRESCALER == SYSCLK)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = CLK_VALUE ->SYS_clk_KHZ;
    #elif(AHB_CLK_PRESCALER == SYSCLK_DIV_BY_2)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = (CLK_VALUE ->SYS_clk_KHZ) >> DIV_BY_2;
    #elif(AHB_CLK_PRESCALER == SYSCLK_DIV_BY_4)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = (CLK_VALUE ->SYS_clk_KHZ) >> DIV_BY_4;
    #elif(AHB_CLK_PRESCALER == SYSCLK_DIV_BY_8)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = (CLK_VALUE ->SYS_clk_KHZ) >> DIV_BY_8;
    #elif(AHB_CLK_PRESCALER == SYSCLK_DIV_BY_16)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = (CLK_VALUE ->SYS_clk_KHZ) >> DIV_BY_16;
    #elif(AHB_CLK_PRESCALER == SYSCLK_DIV_BY_64)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = (CLK_VALUE ->SYS_clk_KHZ) >> DIV_BY_64;
    #elif(AHB_CLK_PRESCALER == SYSCLK_DIV_BY_128)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = (CLK_VALUE ->SYS_clk_KHZ) >> DIV_BY_128;
    #elif(AHB_CLK_PRESCALER == SYSCLK_DIV_BY_256)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = (CLK_VALUE ->SYS_clk_KHZ) >> DIV_BY_256;
    #elif(AHB_CLK_PRESCALER == SYSCLK_DIV_BY_512)
        /* Set AHB clock Pre-scler */
        RCC_REG -> RCC_CFGR.bits.HPRE = AHB_CLK_PRESCALER;
        /* Update AHB clock value */
        CLK_VALUE -> AHB_clk_KHZ = (CLK_VALUE ->SYS_clk_KHZ) >> DIV_BY_512;
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif
    
    /* Check it sht APB2 clock pre-scaler is accepted or not */
    #if(APB2_CLK_PRESCALER == HCLK)
        /* Set APB2 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE2 = APB2_CLK_PRESCALER;
        /* Update APB2 clock value */
        CLK_VALUE -> APB2_clk_KHZ = CLK_VALUE -> AHB_clk_KHZ;
    #elif(APB2_CLK_PRESCALER == HCLK_DIV_BY_2)
        /* Set APB2 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE2 = APB2_CLK_PRESCALER;
        /* Update APB2 clock value */
        CLK_VALUE -> APB2_clk_KHZ = (CLK_VALUE -> AHB_clk_KHZ) >>  DIV_BY_2;
    #elif(APB2_CLK_PRESCALER == HCLK_DIV_BY_4)
        /* Set APB2 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE2 = APB2_CLK_PRESCALER;
        /* Update APB2 clock value */
        CLK_VALUE -> APB2_clk_KHZ = (CLK_VALUE -> AHB_clk_KHZ) >>  DIV_BY_4;
    #elif(APB2_CLK_PRESCALER == HCLK_DIV_BY_8)
        /* Set APB2 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE2 = APB2_CLK_PRESCALER;
        /* Update APB2 clock value */
        CLK_VALUE -> APB2_clk_KHZ = (CLK_VALUE -> AHB_clk_KHZ) >>  DIV_BY_8;
    #elif(APB2_CLK_PRESCALER == HCLK_DIV_BY_16)
        /* Set APB2 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE2 = APB2_CLK_PRESCALER;
        /* Update APB2 clock value */
        CLK_VALUE -> APB2_clk_KHZ = (CLK_VALUE -> AHB_clk_KHZ) >>  DIV_BY_16;
    #else
        /* Option doesn't exist */
        error_state = STD_NOT_VALID_VALUE;
    #endif 
    
    /* Check if APB1 clock pre_scaler is accepted or not */
    #if(APB1_CLK_PRESCALER == HCLK)
        /* Set APB1 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE1 = APB1_CLK_PRESCALER;
        /* Update APB1 clock value */
        CLK_VALUE -> APB1_clk_KHZ = CLK_VALUE -> AHB_clk_KHZ;
    #elif(APB1_CLK_PRESCALER == HCLK_DIV_BY_2)
        /* Set APB1 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE1 = APB1_CLK_PRESCALER;
        /* Update APB1 clock value */
        CLK_VALUE -> APB1_clk_KHZ = (CLK_VALUE -> AHB_clk_KHZ) >> DIV_BY_2;
    #elif(APB1_CLK_PRESCALER == HCLK_DIV_BY_4)
        /* Set APB1 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE1 = APB1_CLK_PRESCALER;
        /* Update APB1 clock value */
        CLK_VALUE -> APB1_clk_KHZ = (CLK_VALUE -> AHB_clk_KHZ) >> DIV_BY_4;
    #elif(APB1_CLK_PRESCALER == HCLK_DIV_BY_8)
        /* Set APB1 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE1 = APB1_CLK_PRESCALER;
        /* Update APB1 clock value */
        CLK_VALUE -> APB1_clk_KHZ = (CLK_VALUE -> AHB_clk_KHZ) >> DIV_BY_8;
    #elif(APB1_CLK_PRESCALER == HCLK_DIV_BY_16)
        /* Set APB1 clock pre_scaler */
        RCC_REG -> RCC_CFGR.bits.PPRE1 = APB1_CLK_PRESCALER;
        /* Update APB1 clock value */
        CLK_VALUE -> APB1_clk_KHZ = (CLK_VALUE -> AHB_clk_KHZ) >> DIV_BY_16;
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

/**
 * @brief This API is used to get clock value for (Sys clock, AHB clock, APB2 clock, APB1 clock).
 * @param local_strRCC_clk_value is a pointer to structure which contains Sys, AHB, APB2 and APB1 clocks.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t RCC_get_clk_value(RCC_clk_t * local_strRCC_clk_value)
{
    std_errorStatus_t error_state = STD_OK;

    /* Check if the pointer is Null or not */
    if(local_strRCC_clk_value != STD_NULL)
    {
        /* Check is the system clock value is accpeted or not */
        if((CLK_VALUE -> SYS_clk_KHZ) <= SYS_CLK_MAX_KHZ)
        {
            /* Update system clock value */
            local_strRCC_clk_value -> SYS_clk_KHZ = CLK_VALUE -> SYS_clk_KHZ;
        }
        else
        {
            error_state = STD_NOT_VALID_VALUE;
        }

        /* Check is the AHB clock value is accpeted or not */
        if((CLK_VALUE -> AHB_clk_KHZ) <= AHB_CLK_MAX_KHZ)
        {
            /* Update AHB clock value */
            local_strRCC_clk_value -> AHB_clk_KHZ = CLK_VALUE -> AHB_clk_KHZ;
        }
        else
        {
            error_state = STD_NOT_VALID_VALUE;
        }

        /* Check is the APB2 clock value is accpeted or not */
        if((CLK_VALUE -> APB2_clk_KHZ) <= APB2_CLK_MAX_KHZ)
        {
            /* Update APB2 clock value */
            local_strRCC_clk_value -> APB2_clk_KHZ = CLK_VALUE -> APB2_clk_KHZ;
        }
        else
        {
            error_state = STD_NOT_VALID_VALUE;
        }

        /* Check is the APB1 clock value is accpeted or not */
        if((CLK_VALUE -> APB1_clk_KHZ) <= APB1_CLK_MAX_KHZ)
        {
            /* Update APB1 clock value */
            local_strRCC_clk_value -> APB1_clk_KHZ = CLK_VALUE -> APB1_clk_KHZ;
        }
        else
        {
            error_state = STD_NOT_VALID_VALUE;
        }
    }
    else
    {
        error_state = STD_NULL_POINTER;
    }
    
    return error_state;
}