/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 23:26:27                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-13 23:58:17                              *
 * @FilePath              : NVIC_prg.c                                       *
 ****************************************************************************/

#include "NVIC_int.h"
#include "NVIC_cfg.h"
#include "bit_math.h"

void vNVIC_EnableIRQ( u8 IRQn ) 
{
if(IRQn<=31)
  {
  SET_BIT(NVIC_ISER0,IRQn);
  }
else if((IRQn>31) && (IRQn<=63))
  {
  SET_BIT(NVIC_ISER1,(IRQn-32));
  }
else if((IRQn>63) && (IRQn<=80))
  {
  SET_BIT(NVIC_ISER2,(IRQn-64));
  }
 else{}
}

void vNVIC_DisableIRQ( u8 IRQn )
{
if(IRQn<=31)
  {
   SET_BIT(NVIC_ICER0,IRQn);
	}
else if((IRQn>31) && (IRQn<=63))
  {
	 SET_BIT(NVIC_ICER1,(IRQn-32));
	}
else if((IRQn>63) && (IRQn<=80))
  {
   SET_BIT(NVIC_ICER2,(IRQn-64));
  }
 else{}
}	
														 					 
void vNVIC_SetPendingIRQ   ( u8 IRQn )
{
if(IRQn<=31)
  {
   SET_BIT(NVIC_ISPR0,IRQn);
	}
else if((IRQn>31) && (IRQn<=63))
  {
	 SET_BIT(NVIC_ISPR1,(IRQn-32));
	}
else if((IRQn>63) && (IRQn<=80))
  {
   SET_BIT(NVIC_ISPR2,(IRQn-64));
  }
 else{}
}
void vNVIC_ClearPendingIRQ ( u8 IRQn )
{
	if(IRQn<=31)
  {
   SET_BIT(NVIC_ICPR0,IRQn);
	}
else if((IRQn>31) && (IRQn<=63))
  {
	 SET_BIT(NVIC_ICPR1,(IRQn-32));
	}
else if((IRQn>63) && (IRQn<=80))
  {
   SET_BIT(NVIC_ICPR2,(IRQn-64));
  }
 else{}
}
														 					 
u8 u8NVIC_GetActive     ( u8 IRQn )
{
	u8 status=0;
 if(IRQn<=31)
  {
   status = CHECK_BIT(NVIC_IABR0,IRQn);
	}
else if((IRQn>31) && (IRQn<=63))
  {
	 status = CHECK_BIT(NVIC_IABR1,(IRQn-32));
	}
else if((IRQn>63) && (IRQn<=80))
  {
   status = CHECK_BIT(NVIC_IABR2,(IRQn-64));
  }
 else{status=2;}
 return status;
}
														 					 
void vNVIC_SetPriority     ( u8 IRQn ,  u8 Subpriority  ,  u8 GroupPriority )
{
/*SET Priorty Config*/
	SCB_AIRCR->VECTKEY=SCB_VECTKEY; /*MUST WRITE KEY BEFORE SET SCB_AIRCR REG*/
	switch(PRIORTY_CONFIG)
	{
		case 1: SCB_AIRCR->PRIGROUP=0b011;
						NVIC_IPR[IRQn]=(GroupPriority<<4U);
			break;
		case 2: SCB_AIRCR->PRIGROUP=0b100; 
						NVIC_IPR[IRQn]=((Subpriority<<4U)|(GroupPriority<<5U));
			break;
		case 3: SCB_AIRCR->PRIGROUP=0b101;  
						NVIC_IPR[IRQn]=((Subpriority<<4U)|(GroupPriority<<6U));
			break;
		case 4: SCB_AIRCR->PRIGROUP=0b110; 
						NVIC_IPR[IRQn]=((Subpriority<<4U)|(GroupPriority<<7U));
			break;
		case 5: SCB_AIRCR->PRIGROUP=0b111;  
						NVIC_IPR[IRQn]=(Subpriority<<4U);
			break;
		/***defautl configration***/
		default:SCB_AIRCR->PRIGROUP=0b111; 
						NVIC_IPR[IRQn]=(Subpriority<<4U);						
			break;
	}


}

