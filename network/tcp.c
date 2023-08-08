//-------------------------Client-------------------------//
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<netdb.h>
int main()
{
	int serversocket,clientsocket,port;
	char m1[50];
	struct sockaddr_in serveraddr;
	socklen_t len;
	char message[50];
	struct serveraddr;
	clientsocket=socket(AF_INET,SOCK_STREAM,0);
	bzero((char*)&serveraddr,sizeof(serveraddr));
	len=sizeof(serveraddr);
	serveraddr.sin_family=AF_INET;
	printf("Enter the port number: ");
	scanf("%d",&port);
	serveraddr.sin_port=htons(port);
	printf("\n Trying to connect to the server.\n");
	connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	printf("\nConnected to the server.\n");
	printf("\nSending message for server connection");
	printf("\nEnter the message: ");
	scanf("%s",m1);
	send(clientsocket,m1,sizeof(m1),0);
	printf("\nRecieving message from server.\n");
	recv(clientsocket,message,sizeof(message),0);
	printf("\nMessage recieved.\t%s\n",message);
	close(serversocket);
}

//-------------------------Server-------------------------//

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
int main()
{
	int serversocket,clientsocket,port;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t len;
	char message[50],reply[50];
	struct serveraddr;
	serversocket=socket(AF_INET,SOCK_STREAM,0);
	bzero((char*)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	printf("Enter the port number: ");
	scanf("%d",&port);
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=INADDR_ANY;
	bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	bzero((char*)&clientaddr,sizeof(clientaddr));
	len=sizeof(clientaddr);
	listen(serversocket,5);
	printf("\nwaiting for client connection\n");
	printf("\nhai: ");
	clientsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&len);
	printf("\n Client connectivity recieved.\n");
	printf("\n Reading message from the client.\n");
	read(clientsocket,message,sizeof(message));
	printf("\nThe client has sent:%s",message);
	printf("\nSend reply: ");
	scanf("%s",reply);
	printf("\nSending message to the client.\n");
	write(clientsocket,reply,sizeof(reply));
	close(clientsocket);
	close(serversocket);
}
