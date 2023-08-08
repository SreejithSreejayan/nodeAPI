//-------------------------Rev-------------------------//
#include<stdio.h>
#include<string.h>
void main()
{
	int i,j=0; 
	char str[50],rev[50];
	printf("Enter the string: ");
	scanf("%s",str);
	int n=strlen(str)-1;
	for(i=n;i>=0;i--)
	{
		rev[j]=str[i];
		j++;
	}
	printf("Rev: %s",rev);
}

//-------------------------Client-------------------------//
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdio.h>
int main()
{
		int clientsocket,port;
		struct sockaddr_in serveraddr;
		socklen_t len;
		struct hostent *server;
		char message[50],str[50];
		clientsocket=socket(AF_INET,SOCK_DGRAM,0);
		bzero((char*)&serveraddr,sizeof(serveraddr));
		len=sizeof(serveraddr);
		serveraddr.sin_family=AF_INET;
		printf("Enter the port number: ");
		scanf("%d",&port);
		serveraddr.sin_port=htons(port);
		fgets(message,2,stdin);
		printf("\nSending message for server connection.\n");
		printf("Enter the string: ");
		scanf("%s",message);
		sendto(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
		printf("\nRecieving message from server.\n");
		recvfrom(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&len);
		printf("\nMessage recieved:\t%s\n",message);
		close(clientsocket);
		
}

//-------------------------Server-------------------------//
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<netdb.h>
#include<string.h>
int main()
{
	int serversocket,port;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t len;
	char message[50],rev[50];
	serversocket=socket(AF_INET,SOCK_DGRAM,0);
	bzero((char*)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	printf("Enter the port number: ");
	scanf("%d",&port);
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=INADDR_ANY;
	bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	printf("\nWaiting for the client connection.\n");
	bzero((char*)&clientaddr,sizeof(clientaddr));
	len=sizeof(clientaddr);
	recvfrom(serversocket,message,sizeof(message),0,(struct sockaddr*)&clientaddr,&len);
	int n=strlen(message)-1;
	int j=0;
	for(int i=n;i>=0;i--)
	{
		rev[j]=message[i];
		j++;
	}
	printf("\nConnection recieved from client.\n");
	printf("\nThe client has send:\t%s\n",message);
	printf("\nSending message to client.\n");
	sendto(serversocket,rev,sizeof(rev),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
	close(serversocket);
}

//-------------------------ClientCLI-------------------------//

#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
		int clientsocket,port;
		struct sockaddr_in serveraddr;
		socklen_t len;
		struct hostent *server;
		char message[50],str[50];
		clientsocket=socket(AF_INET,SOCK_DGRAM,0);
		bzero((char*)&serveraddr,sizeof(serveraddr));
		len=sizeof(serveraddr);
		serveraddr.sin_family=AF_INET;
		port=atoi(argv[1]);
		serveraddr.sin_port=htons(port);
		fgets(message,2,stdin);
		printf("\nSending message for server connection.\n");
		printf("Enter the string: ");
		scanf("%s",message);
		sendto(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
		printf("\nRecieving message from server.\n");
		recvfrom(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&len);
		printf("\nMessage recieved:\t%s\n",message);
		close(clientsocket);
		
}

//-------------------------ServerCLI-------------------------//

#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int serversocket,port;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t len;
	char message[50],rev[50];
	serversocket=socket(AF_INET,SOCK_DGRAM,0);
	bzero((char*)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	port=atoi(argv[1]);
	serveraddr.sin_port=htons(port);
	serveraddr.sin_addr.s_addr=INADDR_ANY;
	bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	printf("\nWaiting for the client connection.\n");
	bzero((char*)&clientaddr,sizeof(clientaddr));
	len=sizeof(clientaddr);
	recvfrom(serversocket,message,sizeof(message),0,(struct sockaddr*)&clientaddr,&len);
	int n=strlen(message)-1;
	int j=0;
	for(int i=n;i>=0;i--)
	{
		rev[j]=message[i];
		j++;
	}
	printf("\nConnection recieved from client.\n");
	printf("\nThe client has send:\t%s\n",message);
	printf("\nSending message to client.\n");
	sendto(serversocket,rev,sizeof(rev),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
	close(serversocket);
}
