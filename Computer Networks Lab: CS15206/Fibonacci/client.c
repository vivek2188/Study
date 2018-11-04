// Client side code
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void){
	int csock;
	unsigned int len;

	struct sockaddr_in client;

	csock = socket(AF_INET,SOCK_STREAM,0);
	if(csock==-1){
		perror("Socket not created\n");
		return 1;
	}

	client.sin_family = AF_INET;
	client.sin_port = htons(10000);
	client.sin_addr.s_addr = INADDR_ANY;
	bzero(&client.sin_zero,0);

	len = sizeof(struct sockaddr_in);

	if(connect(csock,(struct sockaddr *)&client,len)==-1){
		perro("Connection failed\n");
		return 1;
	}
	while(1){
		// Write code
	}
	close(csock);
	return 0;
}