// Header: Stm32f103c8 Drivers
// File Name: UART REGISTER MAP File
// Author: Omar Megahed Ismail
// Date: 2022/03/20
#ifndef UART_PRIV_
#define UART_PRIV_
#include "Std_Type.h"

#define UART1 ((UART_TYP *)0x40013800) /*UART1 BASE ADD 0x40013800*/
#define UART2 ((UART_TYP *)0x40004400) /*UART2 BASE ADD 0x40004400*/
#define UART3 ((UART_TYP *)0x40004800) /*UART3 BASE ADD 0x40004800*/

#define UART1_NVIC_NUM (37)
#define UART2_NVIC_NUM (38)
#define UART3_NVIC_NUM (39)
/*status register*/
typedef struct
{
	uint32 PE : 1;	 /*parity error*/
	uint32 FE : 1;	 /*framing error*/
	uint32 NE : 1;	 /*noise error flag*/
	uint32 ORE : 1;	 /*overrun error*/
	uint32 IDLE : 1; /*idele line detected*/
	uint32 RXNE : 1; /*read data register not empty*/
	uint32 TC : 1;	 /*transmission complete*/
	uint32 TXE : 1;	 /*transmit data register empty */
	uint32 LBD : 1;	 /*lin break detected flag*/
	uint32 CTS : 1;	 /*cts flag*/
	uint32 : 0;		 /*pading*/
} UART_SR_TYP;
/*data register*/
typedef struct
{
	uint32 DR : 9;
	uint32 : 0; /*pading*/
} UART_DR_TYP;
/*baud rate register*/
typedef union
{
	uint32 Data;
	struct
	{
		uint32 Fraction : 4;
		uint32 Mantissa : 12;
		uint32 : 0; /*pading*/
	} Bit;
} UART_BRR_TYP;
/*control register 1*/
typedef struct
{
	uint32 SBK : 1;	   /*send break*/
	uint32 RWU : 1;	   /*Receiver wakeup*/
	uint32 RE : 1;	   /*Receiver enable*/
	uint32 TE : 1;	   /*Transmitter enable*/
	uint32 IDLEIE : 1; /*IDLE interrupt enable*/
	uint32 RXNEIE : 1; /*RXNE interrupt enable*/
	uint32 TCIE : 1;   /*Transmission complete interrupt enable*/
	uint32 TXEIE : 1;  /*TXE interrupt enable */
	uint32 PEIE : 1;   /*PE interrupt enable*/
	uint32 PS : 1;	   /* Parity selection*/
	uint32 PCE : 1;	   /*Parity control enable*/
	uint32 WAKE : 1;   /*Wakeup method*/
	uint32 M : 1;	   /*Word length*/
	uint32 UE : 1;	   /*USART enable*/
	uint32 : 0;		   /*pading*/
} UART_CR1_TYP;
/*control register 2*/
typedef struct
{
	uint32 ADD : 4;	  /* Address of the USART node*/
	uint32 : 1;		  /*reserved*/
	uint32 LBDL : 1;  /*lin break detection length*/
	uint32 LBDIE : 1; /*LIN break detection interrupt enable*/
	uint32 : 1;		  /*reserved*/
	uint32 LBCL : 1;  /*Last bit clock pulse*/
	uint32 CPHA : 1;  /*Clock phase*/
	uint32 CPOL : 1;  /*Clock polarity*/
	uint32 CLKEN : 1; /*Clock enable*/
	uint32 STOP : 2;  /*STOP bits*/
	uint32 LINEN : 1; /*LIN mode enable*/
	uint32 : 0;		  /*pading*/
} UART_CR2_TYP;
/*control register 3*/
typedef struct
{
	uint32 EIE : 1;	  /* Error interrupt enable*/
	uint32 IREN : 1;  /*IrDA mode enable*/
	uint32 IRLP : 1;  /*IrDA low-power*/
	uint32 HDSEL : 1; /*Half-duplex selection*/
	uint32 NACK : 1;  /*Smartcard NACK enable*/
	uint32 SCEN : 1;  /*Smartcard mode enable*/
	uint32 DMAR : 1;  /*DMA enable receiver*/
	uint32 DMAT : 1;  /*DMA enable transmitter*/
	uint32 RISE : 1;  /*RTS enable*/
	uint32 CTSE : 1;  /*CTS enable*/
	uint32 CTSIE : 1; /*CTS interrupt enable*/
	uint32 : 0;		  /*pading*/
} UART_CR3_TYP;
/*GUARD TIME AND PRESCALER REGISTER*/
typedef struct
{
	uint32 PSC : 8; /*Prescaler value*/
	uint32 GT : 8;	/*Guard time value*/
	uint32 : 0;		/*pading*/
} UART_GTPR_TYP;

/*UART MAP*/
typedef struct
{
	UART_SR_TYP SR;
	UART_DR_TYP DR;
	UART_BRR_TYP BRR;
	UART_CR1_TYP CR1;
	UART_CR2_TYP CR2;
	UART_CR3_TYP CR3;
	UART_GTPR_TYP GTPR;
} UART_TYP;

#endif
