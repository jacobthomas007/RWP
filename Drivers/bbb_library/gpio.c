#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"gpio.h"
#define DEBUG

main()
{
//	printf("size of unsigned int %d\n", sizeof(unsigned int));	
	volatile void *gpio1_addr=NULL;
	volatile unsigned int *gpio_oe_addr=NULL;
	volatile unsigned int *gpio_dataout=NULL;
	volatile unsigned int *gpio_setdataout=NULL;
	volatile unsigned int *gpio_cleardataout=NULL;
	unsigned int reg;

	int fd = open("/dev/mem", O_RDWR);
	if(fd < -1)
	{
		printf("error in opening file %s",fd);
		exit(0);
	}
	printf("Mapping %X - %X (size: %X)\n", GPIO1_STARTADDR, GPIO1_ENDADDR,
	GPIO_SIZE);
	
	gpio1_addr = mmap(0,GPIO_SIZE,PROT_READ | PROT_WRITE, MAP_SHARED, fd,
	GPIO1_STARTADDR);

	if(gpio1_addr == MAP_FAILED)
	{
		printf("Unable to map memory\n");
		exit(0);
	}	

	gpio_oe_addr = gpio1_addr + GPIO_OE;
	gpio_dataout = gpio1_addr + GPIO_DATAOUT;
	gpio_setdataout = gpio1_addr + GPIO_SETDATAOUT;
	gpio_cleardataout = gpio1_addr + GPIO_CLEARDATAOUT;
	
#ifdef DEBUG
	printf("GPIO mapped %p \n",gpio1_addr);
	printf("GPIO OE mapped %p, %x \n",gpio_oe_addr, *gpio_oe_addr);
#endif
	reg = *gpio_oe_addr;
	/*	
		making the particular pin as output
	*/
	reg = reg & (0XFFFFFFFF ^ ( 1 << 28) );
#ifdef DEBUG	
	printf("reg = %x \n",reg);
#endif
	*gpio_oe_addr = reg;
	
//	printf("gpio_dataout = %x \n",*gpio_dataout);
	
	while(1)
	{
		*gpio_dataout = (1 << 28);
		sleep(2);
		*gpio_dataout = (0 << 28);
		sleep(2);
//	*gpio_setdataout = (1<<28);
//	*gpio_cleardataout = (1<<28);
	}

	close(fd);
}




