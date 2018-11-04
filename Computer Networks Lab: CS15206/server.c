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

	len = sizeof(struct sockaddr_in);

	while(1){
		// Write code here
	}
	close(ssock);
	return 0;
}