// Header: Stm32f103c8 Drivers
// File Name: GPIO Source File
// Author: Omar Megahed Ismail
// Date: 2022/03/18
/*Include files*/
#include "GPIO.h"
#include "Macros.h"
#include "RCC.h"

/*GPIO Functions*/
void vGPIO_Pin_Set_Mode(GPIOx *GPIO, Pin_Num_Type PinNum, Pin_Status_Type Pin_Status)
{
	/*RCC CLOCK ENABLE*/
	if (GPIO == GPIOA)
	{
		vRCC_EnPerClk(APB2, IOPAEN);
	}
	else if (GPIO == GPIOB)
	{
		vRCC_EnPerClk(APB2, IOPBEN);
	}
	else if (GPIO == GPIOC)
	{
		vRCC_EnPerClk(APB2, IOPCEN);
	}
	else if (GPIO == GPIOD)
	{
		vRCC_EnPerClk(APB2, IOPDEN);
	}
	else if (GPIO == GPIOE)
	{
		vRCC_EnPerClk(APB2, IOPEEN);
	}
	else if (GPIO == GPIOF)
	{
		vRCC_EnPerClk(APB2, IOPFEN);
	}
	else if (GPIO == GPIOG)
	{
		vRCC_EnPerClk(APB2, IOPGEN);
	}

	switch (Pin_Status)
	{
	case Output_PushPull:
		if (PinNum <= 7)
		{
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 2); /*CNF0=0*/
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 3); /*CNF1=0*/

			SET_BIT(GPIO->CRL.Reg, ((PinNum)*4)); /*MODE0=1*/ /*speed med*/
			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4) + 1);		  /*MODE1=0*/
		}
		else if ((PinNum > 7) && (PinNum <= 15))
		{
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 2); /*CNF0=0*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 3); /*CNF1=0*/

			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4)); /*MODE0=1*/ /*speed med*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1);		/*MODE1=0*/
		}

		break;

	case Output_OpenDrain:
		if (PinNum <= 7)
		{
			SET_BIT(GPIO->CRL.Reg, (PinNum * 4) + 2);	/*CNF0=0*/
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 3); /*CNF1=0*/

			SET_BIT(GPIO->CRL.Reg, ((PinNum)*4)); /*MODE0=1*/ /*speed med*/
			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4) + 1);		  /*MODE1=0*/
		}
		else if ((PinNum > 7) && (PinNum <= 15))
		{
			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 2);	  /*CNF0=0*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 3); /*CNF1=0*/

			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4)); /*MODE0=1*/ /*speed med*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1);		/*MODE1=0*/
		}

		break;
	case AltFunc_PushPull:
		if (PinNum <= 7)
		{
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 2); /*CNF0=0*/
			SET_BIT(GPIO->CRL.Reg, (PinNum * 4) + 3);	/*CNF1=0*/

			SET_BIT(GPIO->CRL.Reg, ((PinNum)*4)); /*MODE0=1*/ /*speed med*/
			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4) + 1);		  /*MODE1=0*/
		}
		else if ((PinNum > 7) && (PinNum <= 15))
		{
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 2); /*CNF0=0*/
			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 3);	  /*CNF1=0*/

			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4)); /*MODE0=1*/ /*speed med*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1);		/*MODE1=0*/
		}
		break;
	case AltFunc_OpenDrain:
		if (PinNum <= 7)
		{
			SET_BIT(GPIO->CRL.Reg, (PinNum * 4) + 2); /*CNF0=0*/
			SET_BIT(GPIO->CRL.Reg, (PinNum * 4) + 3); /*CNF1=0*/

			SET_BIT(GPIO->CRL.Reg, ((PinNum)*4)); /*MODE0=1*/ /*speed med*/
			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4) + 1);		  /*MODE1=0*/
		}
		else if ((PinNum > 7) && (PinNum <= 15))
		{
			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 2); /*CNF0=0*/
			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 3); /*CNF1=0*/

			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4)); /*MODE0=1*/ /*speed med*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1);		/*MODE1=0*/
		}
		break;
	case Input_Analog:
		if (PinNum <= 7)
		{
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 2); /*CNF0=0*/
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 3); /*CNF1=0*/

			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4)); /*MODE0=0*/ /*INPUT MODE*/
			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4) + 1);			/*MODE1=0*/
		}
		else if ((PinNum > 7) && (PinNum <= 15))
		{
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 2); /*CNF0=0*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 3); /*CNF1=0*/

			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4)); /*MODE0=0*/ /*INPUT MODE*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1);		  /*MODE1=0*/
		}

		break;
	case Input_Floating:
		if (PinNum <= 7)
		{
			SET_BIT(GPIO->CRL.Reg, (PinNum * 4) + 2);	/*CNF0=0*/
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 3); /*CNF1=0*/

			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4)); /*MODE0=0*/ /*INPUT MODE*/
			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4) + 1);			/*MODE1=0*/
		}
		else if ((PinNum > 7) && (PinNum <= 15))
		{
			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 2);	  /*CNF0=0*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 3); /*CNF1=0*/

			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4)); /*MODE0=0*/ /*INPUT MODE*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1);		  /*MODE1=0*/
		}
		break;
	case Input_PullDown:
		if (PinNum <= 7)
		{
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 2); /*CNF0=0*/
			SET_BIT(GPIO->CRL.Reg, (PinNum * 4) + 3);	/*CNF1=0*/

			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4)); /*MODE0=0*/ /*INPUT MODE*/
			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4) + 1);			/*MODE1=0*/
		}
		else if ((PinNum > 7) && (PinNum <= 15))
		{
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 2); /*CNF0=0*/
			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 3);	  /*CNF1=0*/

			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4)); /*MODE0=0*/ /*INPUT MODE*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1);		  /*MODE1=0*/
		}
		CLEAR_BIT(GPIO->ODR.Reg, PinNum); /*ODR=0 ACTIVATE PULL DOWN*/
		break;
	case Input_PullUp:
		if (PinNum <= 7)
		{
			CLEAR_BIT(GPIO->CRL.Reg, (PinNum * 4) + 2); /*CNF0=0*/
			SET_BIT(GPIO->CRL.Reg, (PinNum * 4) + 3);	/*CNF1=0*/

			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4)); /*MODE0=0*/ /*INPUT MODE*/
			CLEAR_BIT(GPIO->CRL.Reg, ((PinNum)*4) + 1);			/*MODE1=0*/
		}
		else if ((PinNum > 7) && (PinNum <= 15))
		{
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 2); /*CNF0=0*/
			SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 3);	  /*CNF1=0*/

			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4)); /*MODE0=0*/ /*INPUT MODE*/
			CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1);		  /*MODE1=0*/
		}
		SET_BIT(GPIO->ODR.Reg, PinNum); /*ODR=1 ACTIVATE PULL UP*/
		break;

	default:
		break;
	}
}

void vGPIO_Pin_Set_OutputSpeed(GPIOx *GPIO, Pin_Num_Type PinNum, Pin_Speed_Type SpeedType)
{
	switch (SpeedType)
	{
	case LowSpeed:
		CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4));	/*MODE0=0*/
		SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1); /*MODE1=1*/
		break;
	case MedSpeed:
		SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4));		  /*MODE0=1*/
		CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1); /*MODE1=0*/
		break;
	case HighSpeed:
		SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4));		/*MODE0=1*/
		SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1); /*MODE1=1*/
		break;
	default:
		SET_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4));		  /*MODE0=1*/
		CLEAR_BIT(GPIO->CRH.Reg, ((PinNum - 8) * 4) + 1); /*MODE1=0*/
		break;
	}
}

void vGPIO_Pin_Write(GPIOx *GPIO, Pin_Num_Type PinNum, Logic_Type Logic)
{
	switch (Logic)
	{
	case Low:
		CLEAR_BIT(GPIO->ODR.Reg, PinNum);
		break;
	case High:
		SET_BIT(GPIO->ODR.Reg, PinNum);
		break;
	default:
		CLEAR_BIT(GPIO->ODR.Reg, PinNum);
		break;
	}
}
uint8 u8GPIO_Pin_Read(GPIOx *GPIO, Pin_Num_Type PinNum)
{
	return CHECK_BIT(GPIO->IDR.Reg, PinNum);
}
