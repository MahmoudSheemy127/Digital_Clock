#include "STD_Types.h"
#include "MAX7219.h"
#include "SPI_Init.h"
#include "DIO_Init.h"
#include <avr/delay.h>

void MAX7219_Init()
{
    
    SPI_MasterInit();

    DIO_SetPinValue(PORT_B, PIN_5, LOW);
    //SEND decode mode
    SPI_MasterSend(DECODE_MODE);
    //set decode for 0-7 digits
    SPI_MasterSend(DECODE_ENABLE);
    DIO_SetPinValue(PORT_B, PIN_5, HIGH);
    


    //set scan limit for all
    DIO_SetPinValue(PORT_B, PIN_5, LOW);
    //SEND decode mode
    SPI_MasterSend(SCAN_LIMIT);
    //set decode for 0-7 digits
    SPI_MasterSend(SHOW_ALL);
    DIO_SetPinValue(PORT_B, PIN_5, HIGH);

    DIO_SetPinValue(PORT_B, PIN_5, LOW);
    //SEND SHUTDOWN CMD
    SPI_MasterSend(SHUT_DOWN_CMD); 
    //set normal operation mode
    SPI_MasterSend(NORMAL_OPERATION);
    DIO_SetPinValue(PORT_B, PIN_5, HIGH);

    DIO_SetPinValue(PORT_B, PIN_5, LOW);

    //SEND SHUTDOWN CMD
    SPI_MasterSend(0x0A); 
    //set normal operation mode
    SPI_MasterSend(0x09);
    DIO_SetPinValue(PORT_B, PIN_5, HIGH);


    // DIO_SetPinValue(PORT_B, PIN_5, HIGH);
    // DIO_SetPinValue(PORT_B, PIN_5, LOW);
    // SPI_MasterSend(1);
    // SPI_MasterSend(2);
    // DIO_SetPinValue(PORT_B, PIN_5, HIGH);

    // DIO_SetPinValue(PORT_B, PIN_5, LOW);
    // SPI_MasterSend(2);
    // SPI_MasterSend(3);
    // DIO_SetPinValue(PORT_B, PIN_5, HIGH);
}

void MAX7219_SendDigit(u8 digit, u8 num)
{
    DIO_SetPinValue(PORT_B, PIN_5, LOW);
    SPI_MasterSend(digit);
    SPI_MasterSend(num);
    DIO_SetPinValue(PORT_B, PIN_5, HIGH);

}
