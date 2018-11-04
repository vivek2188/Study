/*
	WAP using client server socket programming: A client enters an integer number n and server returns
	the results Fi where 0 ≤ i ≤ n respectively. Fi denotes the Fibonacci number of ith position.

	E.g., if n = 6
	Output : F0 = 0, F1 = 1, F2 = 1, F3 = 2, F4 = 3, F5 = 5, F6 = 8
*/
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
	int ssock, csock;
	unsigned int len;

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

	if(bind(ssock,(struct sockaddr *)&server,len)==-1){
		perror("Bind failed\n");
		return 1;
	}
	if(listen(ssock,5)==-1){
		perror("Listen failed\n");
		return -1;
	}
	csock = accept(ssock,(struct sockaddr *)&client,&len);
	if(csock==-1){
		perror("Not accepted\n");
		return 1;
	}
	while(1){
		// Write code
	}
	close(ssock);
	return 0;
}