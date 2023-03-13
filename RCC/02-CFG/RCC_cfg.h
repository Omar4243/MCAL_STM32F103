// Header: Stm32f103c8 Drivers
// File Name: RCC Configration File
// Author: Omar Megahed Ismail
// Date: 2022/03/16
#ifndef RCC_CONFIG_
#define RCC_CONFIG_
/*CLK_SRC*/
#define PLL (0)
#define HSE (1)
#define HSI (2)
/*OSC_TYPE*/
#define CRYSTAL (0)
#define RC      (1)
/**********************************************************************************
                             User Configration 
***********************************************************************************/
/*System Clock Select Source */
#define SYSTEM_CLK_SRC (PLL)      //System Clock Source {PLL,HSE,HSI}
/*PLL Configration*/
#define PLL_CLK_SRC    (HSE)      //PLL CLK SOURCE {HSE,HSI}
#define HSE_SRC        (CRYSTAL)  //HSE SOURCE {CRYSTAL,RC}
#define HSE_PRE        (1)        //HSE PRESCALER{1,2}"PLL ONLY"
#define PLL_MULT       (9)        //PLL MALTIPLACATION FACTOR {2:16}
#define AHB_PRE        (1)        //AHB PRESCALER {1,2,4,8,16,64,128,256,512} 
#define APB1_PRE       (2)        //APB1 PRESCALER {1,2,4,8,16}
#define APB2_PRE       (1)        //APB2 PRESCALER {1,2,4,8,16}


#endif
