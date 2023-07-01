/*
 * SPI_Init.h
 *
 *  Created on: Oct 15, 2022
 *      Author: mahmo
 */

#ifndef SPI_INIT_H_
#define SPI_INIT_H_

#define SPI_MASTER_SELECT 0x10
#define SPI_ENABLE 0x40
#define SPI_INTERRUPT_FLAG 0x80
#define SPI_CLK_DIV_16 0x01

void SPI_MasterInit();
void SPI_SlaveInit();
void SPI_MasterSend(u8 data);
u8 SPI_SlaveRecieve();
u8 SPI_Transciever(u8 data);



#endif /* SPI_INIT_H_ */
