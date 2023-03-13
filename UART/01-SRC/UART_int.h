/*****************************************************************************
 * @Author                : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @CreatedDate           : 2023-03-13 23:43:50                              *
 * @LastEditors           : Omar MEGAHED<omar.megahed@valeo.com>             *
 * @LastEditDate          : 2023-03-14 00:05:44                              *
 * @FilePath              : UART_int.h                                       *
 ****************************************************************************/

#ifndef UART_H_
#define UART_H_
#include "UART_Priv.h"
#include "UART_cfg.h"
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
void  vUART_Enable(UART_TYP * UART,u32 baud_rate,u8 data_bits,PARITY_TYP parity,u8 stop_bit);

void  vUART_Sendu8(UART_TYP * UART,u8 data);

void  vUART_SendSTR(UART_TYP * UART,u8 * str);

u8 u8UART_ReceivePolling(UART_TYP * UART);
/*interrupt function*/
void  vUART_EnableRXInterrupt(UART_TYP * UART);
u8 u8UART_ReadRXBuffer(UART_TYP * UART);
/* Ex
void USARTx_IRQHandler(void)
{ 
	if(UART1->SR.RXNE==1)
	{
	u8 RX_DATA = u8UART_ReadRXBuffer(UART1);
   // do something
	}	
}
*/

#endif
