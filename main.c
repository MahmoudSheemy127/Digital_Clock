#define F_CPU 8000000UL

#include <avr/delay.h>
#include <STD_Types.h>
#include <UART_Init.h>
#include <RTC_Init.h>
#include "MAX7219.h"


void main()
{
    RTC_Handle rtc_handle;
    RTC_Init();
    UART_Init();
    MAX7219_Init();
    while(1)
    {
        //get time
        RTC_getTime(&rtc_handle);
        //Display time on terminal
        UART_PrintNum(rtc_handle.hours);
        UART_SendStr(":");
        UART_PrintNum(rtc_handle.minutes);
        UART_SendStr(":");
        UART_PrintNum(rtc_handle.seconds);
        UART_SendStr("      ");
        MAX7219_SendDigit(2, 6);
        MAX7219_SendDigit(1, 5);
        _delay_ms(1000);
    }

}