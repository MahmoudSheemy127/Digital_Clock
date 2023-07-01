MAIN_FILES = main.c src/MAX7219.c src/DIO_Prog.c src/SPI_Prog.c src/RTC_Prog.c src/I2C_Prog.c src/UART_Prog.c 
COMPILER = avr-gcc
TARGET_NAME = Clock
CFLAGS = -Wall -Wextra -I/include
TARGET = atmega32
DEVICE = m32
PORT = usb
PROGRAMMER = usbasp

all:
	build upload

build:
	${COMPILER} ${MAIN_FILES} -o ${TARGET_NAME}.elf -I./include -mmcu=${TARGET} -DF_CPU=8000000UL -Os
	avr-objcopy ${TARGET_NAME}.elf -O ihex ${TARGET_NAME}.hex

upload:
	avrdude -c ${PROGRAMMER} -p ${DEVICE} -U flash:w:"build/${TARGET_NAME}.hex":a -P ${PORT}

clean:
	rm -f *.hex
	rm -f *.elf