#include<stdio.h>
#include<string.h>
main()
{
	char buff[100];
	char *temp;
//	strcpy(buff,"hello");
	printf("%d\n",(int)strlen(buff));
	printf("%s\n",buff);
//	memset(buff,0,sizeof(buff));
	printf("enter the string\n");
	scanf("%s",buff);
//	strcpy(buff,temp);
	printf("temp %s\n",temp);
	printf("buff = %s\n",buff);
			
}
