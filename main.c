#define F_CPU 8000000UL

#include <avr/delay.h>
#include <STD_Types.h>
#include <UART_Init.h>
#include <RTC_Init.h>
#include "MAX7219.h"

//display time on 7-Seg display
void display_time(RTC_Handle *handle);


void main()
{
    RTC_Handle rtc_handle;
    RTC_Init(); //init real time clock
    UART_Init(); //init UART
    MAX7219_Init(); //init 7-seg display driver
    while(1)
    {
        //get time
        RTC_getTime(&rtc_handle);
        //display time
        display_time(&rtc_handle);
        _delay_ms(1000);
    }

}

void display_time(RTC_Handle *handle)
{
    //display each time interval
    MAX7219_SendDigit(1,(handle->hours/10));
    MAX7219_SendDigit(2,handle->hours%10);
    MAX7219_SendDigit(3,handle->minutes/10);
    MAX7219_SendDigit(4,handle->minutes%10);
    MAX7219_SendDigit(5,handle->seconds/10);
    MAX7219_SendDigit(6,handle->seconds%10);
}