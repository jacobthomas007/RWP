/*
	Server program
	accepts a clent and prints the message received feom the client

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc, char *argv[])
{

	int sock;
	struct sockaddr_in server;
	int clientsock;
	char buff[1024];
	int rval;
	
	/* Create Socket*/
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if( sock < 0 )
	{
		perror("Socket failuer");
		exit(1);
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);
	
	/*call bind*/	
	
	if(bind(sock, (struct sockaddr *)&server, sizeof(server)))
	{	
		perror("Binding Error");
		exit(1);
	}

	/*Listen*/

	listen(sock,5);

	/*Accpet*/

	do
	{
		printf("Server started ready to accept client\n");
		clientsock = accept(sock, (struct sockaddr *)0, 0);
		if(clientsock == -1)
		{
			perror("Accept error");
			exit(1);
		}
		else 
		{
			memset(buff, 0, sizeof(buff));
			if((rval = recv(clientsock, buff, sizeof(buff), 0)) < 0)
			{
				perror("Recv error");
				exit(1);	
			}
			else if(rval == 0)
			{
				printf("Error in recv");
			}	
			else
			{
				printf("MSG:= %s\n", buff);	
			}
			printf("Got the message rval = %d\n", rval);
		}
	}
	while(1);
	return 0;
}
