//Header: Stm32f103c8 Drivers
//File Name: NVIC Configration File
//Author: Omar Megahed Ismail
//Date: 2022/03/20
#ifndef NVIC_CONFIG_
#define NVIC_CONFIG_
/**********************************************************
               NVIC PRIORTY USER CONFIG
***********************************************************
             BINARYPONT   GROUP.PRIORTY   SUB.PRIORTY
CONFIG 1 --> 0bX.X.X.X         16							NONE
CONFIG 2 --> 0bX.X.X.Y         8               2
CONFIG 3 --> 0bX.X.Y.Y         4               4
CONFIG 4 --> 0bX.Y.Y.Y         2               8
CONFIG 5 --> 0bY.Y.Y.Y        NONE             16
***********************************************************/
#define PRIORTY_CONFIG (5)

#endif
