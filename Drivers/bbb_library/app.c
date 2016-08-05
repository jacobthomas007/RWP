#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"gpio.h"
#define DEBUG

int main()
{
	volatile void *gpio1_addr = NULL;
	int fd = open("/dev/mem", O_RDWR);
	if(fd < -1)
	{
		printf("error in opening file %s",fd);
		exit(0);
	}
	gpio1_addr = mmap(0,GPIO_SIZE,PROT_READ | PROT_WRITE, MAP_SHARED, fd,
	GPIO1_STARTADDR);

	if(gpio1_addr == MAP_FAILED)
	{
		printf("Unable to map memory\n");
		exit(0);
	}	

	pinMode(GPIO1_28,gpio1_addr,OUTPUT);
	while(1)
	{
		digitalWrite(GPIO1_28, gpio1_addr, HIGH);
		sleep(2);
		digitalWrite(GPIO1_28, gpio1_addr, LOW);
		sleep(2);
	}
	return 0;
}

