#include "UART.h"
#include "NVIC.h"
#include "RCC.h"
#include "GPIO.h"
#include "Macros.h"

void vUART_Enable(UART_TYP *UART, uint32 baud_rate, uint8 data_bits, PARITY_TYP parity, uint8 stop_bit)
{
	/*NOTE: THIS CONFIGRATION NO HANDEL REMAP FUNC*/
	if (UART == UART1) /*UART 1 CONFIG*/
	{
		/*RCC CONFIG*/
		vRCC_EnPerClk(APB2, USART1EN); /*enable RCC for uart1 */
		vRCC_EnPerClk(APB2, IOPAEN);   /*enable RCC for uart gpio pins*/
		/*GPIO CONFIG ALTFUNCTION*/
		vGPIO_Pin_Set_Mode(GPIOA, PIN9, AltFunc_PushPull); /*TX PIN*/
		vGPIO_Pin_Set_Mode(GPIOA, PIN10, Input_PullUp);	   /*RX PIN*/
		/*Baudrate config*/
		UART->BRR.Bit.Mantissa = (uint16)((Fclk_ABP2 / baud_rate) / 16);
		UART->BRR.Bit.Fraction = ((((float32)Fclk_ABP2 / baud_rate) / 16) - (UART->BRR.Bit.Mantissa)) * 16;
	}
	else if (UART == UART2) /*UART 2 CONFIG*/
	{
		/*RCC CONFIG*/
		vRCC_EnPerClk(APB1, USART2EN); /*enable RCC for uart2 */
		vRCC_EnPerClk(APB2, IOPAEN);   /*enable RCC for uart gpio pins*/
		/*GPIO CONFIG ALTFUNCTION*/
		vGPIO_Pin_Set_Mode(GPIOA, PIN2, AltFunc_PushPull); /*TX PIN*/
		vGPIO_Pin_Set_Mode(GPIOA, PIN3, Input_PullUp);	   /*RX PIN*/
														   /*Baudrate config*/
		UART->BRR.Bit.Mantissa = (uint16)((Fclk_ABP1 / baud_rate) / 16);
		UART->BRR.Bit.Fraction = ((((float32)Fclk_ABP1 / baud_rate) / 16) - (UART->BRR.Bit.Mantissa)) * 16;
	}
	else if (UART == UART3) /*UART 3 CONFIG*/
	{
		/*RCC CONFIG*/
		vRCC_EnPerClk(APB1, USART3EN); /*enable RCC for uart3 */
		vRCC_EnPerClk(APB2, IOPBEN);   /*enable RCC for uart gpio pins*/
		/*GPIO CONFIG ALTFUNCTION*/
		vGPIO_Pin_Set_Mode(GPIOB, PIN10, AltFunc_PushPull); /*TX PIN*/
		vGPIO_Pin_Set_Mode(GPIOB, PIN11, Input_PullUp);		/*RX PIN*/
															/*Baudrate config*/
		UART->BRR.Bit.Mantissa = (uint16)((Fclk_ABP1 / baud_rate) / 16);
		UART->BRR.Bit.Fraction = ((((float32)Fclk_ABP1 / baud_rate) / 16) - (UART->BRR.Bit.Mantissa)) * 16;
	}
	/*UART ENABLE*/
	UART->CR1.UE = 0b1;
	/*TX ENABLE*/
	UART->CR1.TE = 0b1;
	/*RX ENABLE*/
	UART->CR1.RE = 0b1;
	/*word size*/
	switch (data_bits)
	{
	case 8:
		UART->CR1.M = 0b0;
		break;
	case 9:
		UART->CR1.M = 0b1;
		break;
	default:
		UART->CR1.M = 0b0;
		break;
	}
	/*parity config*/
	switch (parity)
	{
	case NoParity:
		UART->CR1.PCE = 0b0;
		break;
	case Even:
		UART->CR1.PCE = 0b1;
		UART->CR1.PS = 0b0;
		;
		break;
	case Odd:
		UART->CR1.PCE = 0b1;
		UART->CR1.PS = 0b1;
		break;
	default:
		UART->CR1.PCE = 0b0;
		break;
	}
	/*STOP BIT CONFIG*/
	switch (stop_bit)
	{
	case 1:
		UART->CR2.STOP = 0b00;
		break;
	case 2:
		UART->CR2.STOP = 0b10;
		break;
	default:
		UART->CR2.STOP = 0b00;
		break;
	}
}

/*UART SEND UINT DATA FUNC*/
void vUART_Sendu8(UART_TYP *UART, uint8 data)
{
	while (!(UART->SR.TXE))
	{
		;
	}
	UART->DR.DR = data;
}

/*UART SEND STRING FUNC*/
void vUART_SendSTR(UART_TYP *UART, uint8 *str)
{
	uint8 i = 0;
	while (str[i] != '\0')
	{
		vUART_Sendu8(UART, str[i]);
		i++;
	}
}
/*UART RECEIVE POLLING*/
uint8 u8UART_ReceivePolling(UART_TYP *UART)
{
	while (!(UART->SR.RXNE))
	{
		;
	}
	return UART->DR.DR;
}
/***************************
	Interrupt Functions
**************************/
/*uart enable RX interrupt*/
void vUART_EnableRXInterrupt(UART_TYP *UART)
{
	UART->CR1.RXNEIE = 1;
	if (UART == UART1)
	{
		vNVIC_EnableIRQ(UART1_NVIC_NUM);
	}
	else if (UART == UART2)
	{
		vNVIC_EnableIRQ(UART2_NVIC_NUM);
	}
	else if (UART == UART3)
	{
		vNVIC_EnableIRQ(UART3_NVIC_NUM);
	}
}
/*read rx buffer*/
uint8 u8UART_ReadRXBuffer(UART_TYP *UART)
{
	return UART->DR.DR;
}
