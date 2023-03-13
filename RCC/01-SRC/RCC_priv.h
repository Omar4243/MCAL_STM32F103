// Header: Stm32f103c8 Drivers
// File Name: RCC Memory Map "Register Addresses"
// Author: Omar Megahed Ismail
// Date: 2022/03/15
#ifndef RCC_PRIV_
#define RCC_PRIV_
/*include hesder files*/
#include "Std_Type.h"

/*RCC base address*/
#define RCC_BASE (0x40021000)

/*RCC Registers addresses*/
#define RCC_CR       (*((volatile uint32 *)(RCC_BASE + 0x00  )))
#define RCC_CFGR     (*((volatile uint32 *)(RCC_BASE + 0x04  )))    
#define RCC_CIR      (*((volatile uint32 *)(RCC_BASE + 0x08  )))    
#define RCC_APB2RSTR (*((volatile uint32 *)(RCC_BASE + 0x0c  )))    
#define RCC_APB1RSTR (*((volatile uint32 *)(RCC_BASE + 0x010 )))    
#define RCC_AHBENR   (*((volatile uint32 *)(RCC_BASE + 0x14  )))    
#define RCC_APB2ENR  (*((volatile uint32 *)(RCC_BASE + 0x18  )))    
#define RCC_APB1ENR  (*((volatile uint32 *)(RCC_BASE + 0x1c  )))    
#define RCC_BDCR     (*((volatile uint32 *)(RCC_BASE + 0x20  )))    
#define RCC_CSR      (*((volatile uint32 *)(RCC_BASE + 0x24  )))    

/*RCC_CR Bits*/
#define PLLRDY       (25)
#define PLLON        (24)
#define HSEBYP       (18)
#define HSERDY       (17)
#define HSEON        (16)
#define HSION        (0)
#define HSIRDY       (1)

/*RCC_CFGR Bits*/
#define PLLMUL_0     (18)
#define PLLMUL_1     (19)
#define PLLMUL_2     (20)
#define PLLMUL_3     (21)
#define PLLXTPRE     (17)
#define PLLSRC       (16)
#define PPRE2_0      (11)
#define PPRE2_1      (12)
#define PPRE2_2      (13)
#define PPRE1_0      (8)
#define PPRE1_1      (9)
#define PPRE1_2      (10)
#define HPRE_0       (4)
#define HPRE_1       (5)
#define HPRE_2       (6)
#define HPRE_3       (7)
#define SW_0         (0)
#define SW_1         (1)


/*RCC_APB2ENR Bits*/
#define AFIOEN       (0)
#define IOPAEN       (2)
#define IOPBEN       (3)
#define IOPCEN       (4)
#define IOPDEN       (5)
#define IOPEEN       (6)
#define IOPFEN       (7)
#define IOPGEN       (8)
#define ADC1EN       (9)
#define ADC2EN       (10)
#define TIM1EN       (11)
#define SPI1EN       (12)
#define TIM8EN       (13)
#define USART1EN     (14)
#define ADC3EN       (15)
#define TIM9EN       (19)
#define TIM10EN      (20)
#define TIM11EN      (21)

/*RCC_APB1ENR Bits*/
#define TIM2EN       (0)
#define TIM3EN       (1)
#define TIM4EN       (2)
#define TIM5EN       (3)
#define TIM6EN       (4)
#define TIM7EN       (5)
#define TIM12EN      (6)
#define TIM13EN      (7)
#define TIM14EN      (8)
#define WWDGEN       (11)
#define SPI2EN       (14)
#define SPI3EN       (15)
#define USART2EN     (17)
#define USART3EN     (18)
#define USART4EN     (19)
#define USART5EN     (20)
#define I2C1EN       (21)
#define I2C2EN       (22)
#define USBEN        (23)
#define CANEN        (25)
#define BKPEN        (27)
#define PWREN        (28)
#define DACEN        (29)


#endif
