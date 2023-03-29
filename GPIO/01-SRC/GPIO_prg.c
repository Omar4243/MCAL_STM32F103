/*****************************************************************************
 * @Author                : Islam Tarek<islamtarek0550@gmail.com>            *
 * @CreatedDate           : 2023-03-28 09:34:24                              *
 * @LastEditors           : Islam Tarek<islamtarek0550@gmail.com>            *
 * @LastEditDate          : 2023-03-28 09:34:25                              *
 * @FilePath              : GPIO_prg.c                                       *
 * @CopyRight             : Islam Tarek CopyRight                            *
 ****************************************************************************/

/**
 * @section Includes
 */
#include "GPIO_priv.h"
#include "GPIO_int.h"
#include "RCC_int.h"

/**
 * @section Global Variables
 */

/**
 * @brief GPIO Array
 */
static GPIO_reg_t *GPIO_ARR[GPIO_LAST] =
    {
        GPIO_A_REG,
        GPIO_B_REG,
        GPIO_C_REG,
        GPIO_D_REG,
        GPIO_E_REG};

/**
 * @section APIs Implementation
 */

/**
 * @brief This API is used for GPIO Initialization
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t GPIO_init(void)
{
}

/**
 * @brief This API is used to set the Pin Mode.
 * @note Modes are:
 * @note - GPIO_PIN_MODE_AN_INPUT
 * @note - GPIO_PIN_MODE_FLOATING_INPUT
 * @note - GPIO_PIN_MODE_PD_INPUT
 * @note - GPIO_PIN_MODE_PU_INPUT
 * @note - GPIO_PIN_MODE_GP_PP_OUTPUT
 * @note - GPIO_PIN_MODE_GP_OD_OUTPUT
 * @note - GPIO_PIN_MODE_AF_PP_OUTPUT
 * @note - GPIO_PIN_MODE_AF_OD_OUTPUT
 * @param local_enuPort is the Port whose pin mode will be set (GPIO_x, x: (A -> E)).
 * @param local_enuPin is the pin whose mode will be set (GPIO_PIN_x, x: (0 -> 15)).
 * @param local_enuPinMode the mode to which the pin will set to.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t GPIO_set_pin_mode(gpio_port_t local_enuPort, gpio_pin_t local_enuPin, gpio_pin_mode_t local_enuPinMode)
{
    std_errorStatus_t error_state = STD_OK;

    /* Initialize ODR register by zeros */
    (GPIO_ARR[local_enuPort]->GPIO_ODR).reg = RESET_BY_ZERO;

    /* Check if the Port exists or not */
    if ((local_enuPort >= GPIO_A) && (local_enuPort < GPIO_LAST))
    {
        /* Enable GPIO clock */
        error_state = RCC_enable_peripheral_clk((local_enuPort + PORT_TO_PERIPHERAL));

        /* Set Pin Mode */
        if ((local_enuPinMode >= GPIO_PIN_MODE_AN_INPUT) && (local_enuPinMode < GPIO_PIN_MODE_LAST))
        {
            /* Check if the mode is Pull-up or not */
            if (local_enuPinMode == GPIO_PIN_MODE_PU_INPUT)
            {
                /* Set ODR Bit */
                ((GPIO_ARR[local_enuPort]->GPIO_ODR).reg) |= (HIGH << local_enuPin);

                /* Update Mode value */
                local_enuPinMode = GPIO_PIN_MODE_PD_INPUT;
            }
            else
            {
                /* Do Nothing */
            }

            /* Configure the Pin mode */
            if (local_enuPin >= GPIO_PIN_0 && local_enuPin <= GPIO_PIN_7)
            {
                /* Clear Pin previous configuration */
                ((GPIO_ARR[local_enuPort]->GPIO_CRL).reg) &= ~(PIN_CFG_MASK << (local_enuPin * PIN_CFG_SHIFT));
                /* Set Pin configuration */
                ((GPIO_ARR[local_enuPort]->GPIO_CRL).reg) |= (local_enuPinMode << (local_enuPin * PIN_CFG_SHIFT));
            }
            else if (local_enuPin >= GPIO_PIN_8 && local_enuPin < GPIO_PIN_LAST)
            {
                /* Clear Pin previous configuration */
                ((GPIO_ARR[local_enuPort]->GPIO_CRH).reg) &= ~(PIN_CFG_MASK << (local_enuPin * PIN_CFG_SHIFT));
                /* Set Pin configuration */
                ((GPIO_ARR[local_enuPort]->GPIO_CRH).reg) |= (local_enuPinMode << (local_enuPin * PIN_CFG_SHIFT));
            }
            else
            {
                error_state = STD_NOT_VALID_VALUE;
            }
        }
        else
        {
            error_state = STD_NOT_VALID_VALUE;
        }
    }
    else
    {
        error_state = STD_INDEX_OUT_OF_RANGE;
    }

    return error_state;
}

/**
 * @brief This API is used to set the Pin Level.
 * @note Levels are:
 * @note GPIO_PIN_LOW
 * @note GPIO_PIN_HIGH
 * @param local_enuPort is the Port whose pin level will be set (GPIO_x, x: (A -> E)).
 * @param local_enuPin is the pin whose level will be set (GPIO_PIN_x, x: (0 -> 15)).
 * @param local_enuPinLevel is the level to which the pin will be set.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t GPIO_set_pin_level(gpio_port_t local_enuPort, gpio_pin_t local_enuPin, gpio_pin_level_t local_enuPinLevel)
{
    std_errorStatus_t error_state = STD_OK;

    /* Check if the Port exists or not */
    if((local_enuPort >= GPIO_A) && (local_enuPort < GPIO_LAST))
    {
        /* Check if the Pin exists or not */
        if((local_enuPin >= GPIO_PIN_0) && (local_enuPin < GPIO_PIN_LAST))
        {
            /* Check if the level is valid or not */
            if((local_enuPinLevel == GPIO_PIN_LOW) || (local_enuPinLevel == GPIO_PIN_LOW))
            {
                /* Clear Pin previous level */
                ((GPIO_ARR[local_enuPort] -> GPIO_ODR).reg) &= ~(PIN_LEVEL_MASK << local_enuPin);
                /* Set Pin level */
                ((GPIO_ARR[local_enuPort] -> GPIO_ODR).reg) |= (local_enuPinLevel << local_enuPin);
            }
            else
            {
                error_state = STD_NOT_VALID_VALUE;
            }
        }
        else
        {
            error_state = STD_NOT_VALID_VALUE;
        }
    }
    else
    {
        error_state = STD_INDEX_OUT_OF_RANGE;
    }
}

/**
 * @brief This API is used to get the Pin Level.
 * @note Levels are:
 * @note GPIO_PIN_LOW
 * @note GPIO_PIN_HIGH
 * @param local_enuPort is the Port whose pin level will be got (GPIO_x, x: (A -> E)).
 * @param local_enuPin is the pin whose level will be got (GPIO_PIN_x, x: (0 -> 15)).
 * @param local_enuPinLevel is the level which will be got.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t GPIO_get_pin_level(gpio_port_t local_enuPort, gpio_pin_t local_enuPin, gpio_pin_level_t *local_enuPinLevel)
{
}

/**
 * @brief This API is used to set the Pin max output speed.
 * @note Output Speeds are:
 * @note GPIO_PIN_MAX_OUTPUT_SPEED_2MHZ
 * @note GPIO_PIN_MAX_OUTPUT_SPEED_10MHZ
 * @note GPIO_PIN_MAX_OUTPUT_SPEED_50MHZ
 * @param local_enuPort is the Port whose pin level will be got (GPIO_x, x: (A -> E)).
 * @param local_enuPin is the pin whose level will be got (GPIO_PIN_x, x: (0 -> 15)).
 * @param local_enuPinSpeed is the speed to which the Pin output speed will be set.
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t GPIO_set_pin_speed(gpio_port_t local_enuPort, gpio_pin_t local_enuPin, gpio_pin_speed_t local_enuPinSpeed)
{
}

/**
 * @brief This API is used to toggle Pin Level.
 * @param local_enuPort is the Port whose pin level will be got (GPIO_x, x: (A -> E)).
 * @param local_enuPin is the pin whose level will be got (GPIO_PIN_x, x: (0 -> 15)).
 * @return Error state which describes the state of API (Passed or failed).
 */
std_errorStatus_t GPIO_toggle_pin_level(gpio_port_t local_enuPort, gpio_pin_t local_enuPin)
{
}
