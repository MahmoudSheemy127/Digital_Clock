#ifndef MAX7219_INIT_H
#define MAX7219_INIT_H

#define DECODE_MODE 0x09
#define NO_DECODE 0x00
#define DECODE_ENABLE 0xFF
#define SHUT_DOWN_CMD 0x0C
#define NORMAL_OPERATION 0x01
#define SCAN_LIMIT 0x0B
#define SHOW_ALL 0xFF

void MAX7219_Init();
void MAX7219_SendDigit(u8 digit, u8 num);

#endif