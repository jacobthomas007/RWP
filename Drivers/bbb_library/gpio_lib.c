	//volatile unsigned int *gpio_oe_addr=NULL;
	//volatile void *gpio1_addr = NULL; 
	//volatile unsigned int *gpio_dataout=NULL;
	//volatile unsigned int *gpio_setdataout=NULL;
	//volatile unsigned int *gpio_cleardataout=NULL;
	
#include "gpio.h"
#include<stdio.h>
#include<stdlib.h>
#define DEBUG
//int pinMode(PIN,MMAP,STATUS) ---  outline 
//int init_gpio()
//{
//	
//}

int pinMode(int pin ,volatile void *gpio1_addr, int status)
{
	unsigned int reg;
	volatile unsigned int *gpio1_oe_addr = NULL;
	gpio1_oe_addr = gpio1_addr + GPIO_OE;
	reg = *gpio1_oe_addr;
	if(status)
	{
		//reg = reg & (0XFFFFFFFF ^ (pin)); // input
	}
	else
	reg = reg & (0XFFFFFFFF ^ (1<<pin));	// output

	#ifdef DEBUG
	printf("GPIO mapped %p \n",gpio1_addr);
	printf("GPIO OE mapped %p, %x \n",gpio1_oe_addr, *gpio1_oe_addr);	
	printf("reg = %x \n",reg);
	#endif

	*gpio1_oe_addr = reg;

	return 1;
}


//int digitalWrite(PIN=GPIO1_28, MMAP, VALUE)
int digitalWrite(int pin, volatile void *gpio1_addr, int value)
{
	volatile unsigned int *gpio1_dataout = NULL;
	gpio1_dataout = gpio1_addr + GPIO_DATAOUT;
	if(value)
	*gpio1_dataout = (1<<pin);
	else
	*gpio1_dataout = (0<<pin);
}
