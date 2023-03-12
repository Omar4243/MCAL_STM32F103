/*****************************************************************************
 * @Author                : Islam Tarek<islamtarek0550@gmail.com>            *
 * @CreatedDate           : 2023-03-11 21:14:58                              *
 * @LastEditors           : Islam Tarek<islamtarek0550@gmail.com>            *
 * @LastEditDate          : 2023-03-11 21:23:19                              *
 * @FilePath              : RCC_prg.c                                        *
 * @CopyRight             : Islam Tarek CopyRight                            *
 ****************************************************************************/

/**
 * @brief  Includes Section
 */

#include "RCC_priv.h"
#include "../02-CFG/RCC_cfg.h"
#include "RCC_int.h"

/**
 * @brief  This API is used to initialize RCC driver with the given configurations.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t MCAL_enu_Rcc_init(void)
{
    /* Configure System clock Source */


    /* Configure PLL clock Source */


    /* Configure Clock Security System */


    /* Configure PLL Multiplication Factor */

    
}

/**
 * @brief This API is used to Enable the clock for the given Peripheral.
 * @param local_enuPeripheral The peripheral whose clock will be enabled.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t MCAL_enu_Rcc_enable (peripheral_t local_enuPeripheral)
{
    std_errorStatus_t error_state = STD_OK;
    /* Check peripheral belongs to which bus */
    if(local_enuPeripheral >= AHB_MIN_LIMIT && local_enuPeripheral < AHB_MAX_LIMIT)
    {
        /* Enable Peripheral Clock */
        SET_BIT((RCC_REG -> RCC_AHBENR), local_enuPeripheral);
    }
    elseif(local_enuPeripheral >= APB2_MIN_LIMIT && local_enuPeripheral < APB2_MAX_LIMIT)
    {
        /* Enable Peripheral Clock */
        SET_BIT((RCC_REG -> RCC_APB2ENR), (local_enuPeripheral - APB2_MIN_LIMIT));
    }
    elseif(local_enuPeripheral >= APB1_MIN_LIMIT && local_enuPeripheral < APB1_MAX_LIMIT)
    {
        /* Enable Peripheral Clock */
        SET_BIT((RCC_REG -> RCC_APB1ENR), (local_enuPeripheral - APB1_MIN_LIMIT));
    }
    else
    {
        /* Peripheral not existed */
        error_state = STD_NOK;
    }

    return error_state;
}

/**
 * @brief This API is used to disable the clock for the given Peripheral.
 * @param local_enuPeripheral The peripheral whose clock will be disabled.
 * @return Error state which describes the state of API (Passed or failed). 
 */
std_errorStatus_t MCAL_enu_Rcc_disable(peripheral_t local_enuPeripheral)
{
    std_errorStatus_t error_state = STD_OK;
    /* Check peripheral belongs to which bus */
    if(local_enuPeripheral >= AHB_MIN_LIMIT && local_enuPeripheral < AHB_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
        CLR_BIT((RCC_REG -> RCC_AHBENR), local_enuPeripheral);
    }
    elseif(local_enuPeripheral >= APB2_MIN_LIMIT && local_enuPeripheral < APB2_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
        CLR_BIT((RCC_REG -> RCC_APB2ENR), (local_enuPeripheral - APB2_MIN_LIMIT));
    }
    elseif(local_enuPeripheral >= APB1_MIN_LIMIT && local_enuPeripheral < APB1_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
        CLR_BIT((RCC_REG -> RCC_APB1ENR), (local_enuPeripheral - APB1_MIN_LIMIT));
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
std_errorStatus_t MCAL_enu_Rcc_reset(peripheral_t local_enuPeripheral)
{
    std_errorStatus_t error_state = STD_OK;
    /* Check peripheral belongs to which bus */
    if(local_enuPeripheral >= APB2_MIN_LIMIT && local_enuPeripheral < APB2_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
        CLR_BIT((RCC_REG -> RCC_APB2RSTR), (local_enuPeripheral - APB2_MIN_LIMIT));
    }
    elseif(local_enuPeripheral >= APB1_MIN_LIMIT && local_enuPeripheral < APB1_MAX_LIMIT)
    {
        /* Disable Peripheral Clock */
        CLR_BIT((RCC_REG -> RCC_APB1RSTR), (local_enuPeripheral - APB1_MIN_LIMIT));
    }
    else
    {
        /* Peripheral not existed */
        error_state = STD_NOK;
    }

    return error_state;
}