/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 22:20:27                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-14 00:01:39                              *
 * @FilePath              : RCC_int.h                                        *
 ****************************************************************************/

#ifndef RCC_H_
#define RCC_H_
#include "RCC_priv.h"
#include "RCC_cfg.h"

typedef enum
{
  APB1 = 0,
  APB2

} Bus_Name;

void vRCC_Init(void);

void vRCC_EnPerClk(Bus_Name Bus, u8 Peripheral_Name);

#endif
