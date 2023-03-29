/*****************************************************************************
 * @Author                : Islam Tarek<islamtarek0550@gmail.com>            *
 * @CreatedDate           : 2023-03-28 09:34:18                              *
 * @LastEditors           : Islam Tarek<islamtarek0550@gmail.com>            *
 * @LastEditDate          : 2023-03-28 09:34:18                              *
 * @FilePath              : GPIO_int.h                                       *
 * @CopyRight             : Islam Tarek CopyRight                            *
 ****************************************************************************/

/**
 * @section Includes
*/

#include "std_type.h"
#include "bit_math.h"

/**
 * @section Typedefs
*/

/**
 * @brief GPIO Ports 
 */
typedef enum
{
    GPIO_A = (u8) 0 ,
    GPIO_B          ,
    GPIO_C          ,
    GPIO_D          ,
    GPIO_E          ,
    GPIO_LAST
}gpio_port_t;

/**
 * @brief GPIO Pins
 */
typedef enum
{
    GPIO_PIN_0 = (u8) 0  ,
    GPIO_PIN_1           ,  
    GPIO_PIN_2           ,  
    GPIO_PIN_3           ,  
    GPIO_PIN_4           ,  
    GPIO_PIN_5           ,  
    GPIO_PIN_6           ,  
    GPIO_PIN_7           ,  
    GPIO_PIN_8           ,  
    GPIO_PIN_9           ,  
    GPIO_PIN_10          ,  
    GPIO_PIN_11          ,  
    GPIO_PIN_12          ,  
    GPIO_PIN_13          ,  
    GPIO_PIN_14          ,  
    GPIO_PIN_15          ,  
    GPIO_PIN_LAST  
}gpio_pin_t;

/**
 * @brief GPIO Pin levels
 */
typedef enum
{
    GPIO_PIN_LOW  = LOW ,
    GPIO_PIN_HIGH = HIGH
}gpio_pin_level_t;

/**
 * @brief GPIO Pin modes
 */
typedef enum
{
    GPIO_PIN_MODE_AN_INPUT              = 0b00000  ,    /* Pin is used as GPIO analog    input */
    GPIO_PIN_MODE_FLOATING_INPUT        = 0b00100  ,    /* Pin is used as GPIO floating  input */
    GPIO_PIN_MODE_PD_INPUT              = 0b01000  ,    /* Pin is used as GPIO pull-down input */
    GPIO_PIN_MODE_PU_INPUT              = 0b11000  ,    /* Pin is used as GPIO pull-up   input */
    GPIO_PIN_MODE_GP_PP_OUTPUT_2MHZ     = 0b00010  ,    /* Pin is used as GPIO push-pull  output with max output speed  2 MHZ */
    GPIO_PIN_MODE_GP_PP_OUTPUT_10MHZ    = 0b00001  ,    /* Pin is used as GPIO push-pull  output with max output speed 10 MHZ */
    GPIO_PIN_MODE_GP_PP_OUTPUT_50MHZ    = 0b00011  ,    /* Pin is used as GPIO push-pull  output with max output speed 50 MHZ */
    GPIO_PIN_MODE_GP_OD_OUTPUT_2MHZ     = 0b00110  ,    /* Pin is used as GPIO open-drain output with max output speed  2 MHZ */
    GPIO_PIN_MODE_GP_OD_OUTPUT_10MHZ    = 0b00101  ,    /* Pin is used as GPIO open-drain output with max output speed 10 MHZ */
    GPIO_PIN_MODE_GP_OD_OUTPUT_50MHZ    = 0b00111  ,    /* Pin is used as GPIO open-drain output with max output speed 50 MHZ */
    GPIO_PIN_MODE_AF_PP_OUTPUT_2MHZ     = 0b01010  ,    /* Pin is used as AFIO push-pull  output with max output speed  2 MHZ */
    GPIO_PIN_MODE_AF_PP_OUTPUT_10MHZ    = 0b01001  ,    /* Pin is used as AFIO push-pull  output with max output speed 10 MHZ */
    GPIO_PIN_MODE_AF_PP_OUTPUT_50MHZ    = 0b01011  ,    /* Pin is used as AFIO push-pull  output with max output speed 50 MHZ */
    GPIO_PIN_MODE_AF_OD_OUTPUT_2MHZ     = 0b01110  ,    /* Pin is used as AFIO open-drain output with max output speed  2 MHZ */
    GPIO_PIN_MODE_AF_OD_OUTPUT_10MHZ    = 0b01101  ,    /* Pin is used as AFIO open-drain output with max output speed 10 MHZ */
    GPIO_PIN_MODE_AF_OD_OUTPUT_50MHZ    = 0b01111  ,    /* Pin is used as AFIO open-drain output with max output speed 50 MHZ */
    GPIO_PIN_MODE_LAST
}gpio_pin_mode_t;

/**
 * @brief GPIO Pin speeds
 */
typedef enum
{
    GPIO_PIN_INPUT_MODE = (u8)0      ,   /* The pin is input, this value is reserved  */
    GPIO_PIN_MAX_OUTPUT_SPEED_10MHZ  ,   /* Maximum output speed of the pin is 10 MHZ */ 
    GPIO_PIN_MAX_OUTPUT_SPEED_2MHZ   ,   /* Maximum output speed of the pin is 2 MHZ  */
    GPIO_PIN_MAX_OUTPUT_SPEED_50MHZ  ,   /* Maximum output speed of the pin is 50 MHZ */
    GPIO_PIN_MAX_OUTPUT_SPEED_LAST
}gpio_pin_speed_t;


/**
 * @section APIs
*/

std_errorStatus_t GPIO_init             (void);
std_errorStatus_t GPIO_set_pin_mode     (gpio_port_t local_enuPort, gpio_pin_t local_enuPin, gpio_pin_mode_t local_enuPinMode);
std_errorStatus_t GPIO_set_pin_level    (gpio_port_t local_enuPort, gpio_pin_t local_enuPin, gpio_pin_level_t local_enuPinLevel);
std_errorStatus_t GPIO_get_pin_level    (gpio_port_t local_enuPort, gpio_pin_t local_enuPin, gpio_pin_level_t* local_enuPinLevel);
std_errorStatus_t GPIO_set_pin_speed    (gpio_port_t local_enuPort, gpio_pin_t local_enuPin, gpio_pin_speed_t local_enuPinSpeed);
std_errorStatus_t GPIO_toggle_pin_level (gpio_port_t local_enuPort, gpio_pin_t local_enuPin);

