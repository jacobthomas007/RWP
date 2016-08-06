#ifndef _GPIO_H_
#define _GPIO_H_

#define GPIO_OE 0X134
#define GPIO_DATAIN 0X138
#define GPIO_DATAOUT 0X13C
#define GPIO1_STARTADDR 0X4804C000
#define GPIO1_ENDADDR  0X4804CFFF
#define GPIO_CLEARDATAOUT 0X190
#define GPIO_SETDATAOUT 0X194
#define GPIO_SIZE (GPIO1_ENDADDR - GPIO1_STARTADDR)
#define OUTPUT 0
#define INPUT 1
#define HIGH 1
#define LOW 0
#define GPIO1_28 28

int pinMode(int pin ,volatile void *gpio1_addr, int status);
int digitalWrite(int pin, volatile void *gpio1_addr, int value);
int digitalRead(int pin, volatile void *gpio1_addr);
