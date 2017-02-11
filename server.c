#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include"sha1.h"
long long int e=0,n=0;
long long int modexp(long long int x, long long int y)
{
	long long int res=1;
         x = x % n;  
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % n;
        y = y>>1;
        x = (x*x) % n; 
    }
	if(res>0)
    return res;
	else
	return res+n;
}
int main(int argc , char *argv[])
{
    int socket_desc ,i, client_sock , c , read_size ,r2,r3,r4;
	int flag=1;
    struct sockaddr_in server , client;
    unsigned char client_message[2000];
	char sign[2000];
	
	char hash[2000];
	int length;
	   SHA1_CTX obj;
long long int m1, m2, ci[50];
    char server_message[2000];
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
     
    //Receive a message from client
    while( ((read_size = recv(client_sock , client_message , 2000 , 0)) >0) && (r2=recv(client_sock , ci , sizeof(ci) , 0)>0) && (r3=recv(client_sock , &e , sizeof(e) , 0)>0) && (r4=recv(client_sock , &n , sizeof(n) , 0)>0))
    {
        //Send the message back to client
	flag=1;
	printf("CLIENT MESSAGE\n");
	//strcat(client_message,"a");
	puts(client_message);
	length=strlen(client_message);
	sha1_init(&obj);
	sha1_update(&obj,client_message,length);
	sha1_final(&obj,hash);
	
	for(i=0;i<strlen(hash);i++)
	{
	m1=modexp(ci[i],e);
	m2=(long long int)hash[i];
	if(m2<0)
	m2=m2+n;
	if(m1!=m2)
	{
	flag=0; break;}
	}
	if(flag)
	strcpy(server_message,"Authentication successful!");
	else
	strcpy(server_message,"Authentication failed!");
	n=0; e=0;
	//strcpy(server_message,"");
        write(client_sock , server_message , strlen(server_message));
	
    }
     
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
     
    return 0;
}
