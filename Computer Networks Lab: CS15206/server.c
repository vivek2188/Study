#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void){
	// Creating client and server socket descriptor
	int ssock, csock;
	unsigned int len;
	// Creating server and client socket object
	struct sockaddr_in server, client;
	ssock = socket(AF_INET,SOCK_STREAM,0);
	if(ssock==-1){
		perror("Socket not created\n");
		return 1;
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(10000);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero,0);

	len = sizeof(struct sockaddr_in);
	// Binding port and IP Address
	if(bind(ssock,(struct sockaddr *)&server,len)==-1){
		perror("Bind...\n");
		return 1;
	}
	// Listening client
	if(listen(ssock,5)==-1){
		perror("Listen...\n");
		return -1;
	}
	// Accepting connection
	csock = accept(ssock,(struct sockaddr *)&client,&len);
	if(csock==-1){
		perror("Accept...\n");
		return 1;
	}
	while(1){
		// Write code here
	}
	close(ssock);
	return 0;
}