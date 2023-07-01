/*
 * SPI_Prog.c
 *
 *  Created on: Oct 15, 2022
 *      Author: mahmo
 */

#include "BIT_Math.h"
#include "STD_Types.h"
#include <avr/io.h>
#include "SPI_Init.h"
#include "DIO_Init.h"


void SPI_MasterInit()
{
	DDRB |= (1 << DDB5) | (1 << DDB7) | (1 << DDB4);
	//Select Master Mode
	SPCR |= SPI_MASTER_SELECT;
	//Select Clock
	SPCR |= SPI_CLK_DIV_16;
	//Enable SPI bit
	SPCR |= SPI_ENABLE;
}

void SPI_SlaveInit()
{
	//Select Master Mode
	SPCR &= ~(SPI_MASTER_SELECT);
	//Select Clock
	SPCR |= SPI_CLK_DIV_16;
	//Enable SPI bit
	SPCR |= SPI_ENABLE;
}


void SPI_MasterSend(u8 data)
{
	//Poll over the interrupt flag
	u8 flush;
	SPDR = data;
	while(!(SPSR & SPI_INTERRUPT_FLAG));
	flush = SPDR;
}

u8 SPI_SlaveRecieve()
{
	while(!(SPSR & SPI_INTERRUPT_FLAG));
	return SPDR;
}
