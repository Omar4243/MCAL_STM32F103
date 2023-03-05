//Header: Stm32f103c8 Drivers
//File Name: UART HEADER File
//Author: Omar Megahed Ismail
//Date: 2022/03/20
#ifndef UART_H_
#define UART_H_
#include "UART_Priv.h"
#include "UART_config.h"
/*********************************
                       Fclk
Baudrate (RX/TX)=  -------------
                    16*USARTDIV
**********************************/
/*Parity OPTIONS*/
typedef enum
{
	Odd=0,
	Even,
	NoParity,
}PARITY_TYP;

/*UART FUNCTION*/
void  vUART_Enable(UART_TYP * UART,uint32 baud_rate,uint8 data_bits,PARITY_TYP parity,uint8 stop_bit);

void  vUART_Sendu8(UART_TYP * UART,uint8 data);

void  vUART_SendSTR(UART_TYP * UART,uint8 * str);

uint8 u8UART_ReceivePolling(UART_TYP * UART);
/*interrupt function*/
void  vUART_EnableRXInterrupt(UART_TYP * UART);
uint8 u8UART_ReadRXBuffer(UART_TYP * UART);
/* Ex
void USARTx_IRQHandler(void)
{ 
	if(UART1->SR.RXNE==1)
	{
	uint8 RX_DATA = u8UART_ReadRXBuffer(UART1);
   // do something
	}	
}
*/

#endif
