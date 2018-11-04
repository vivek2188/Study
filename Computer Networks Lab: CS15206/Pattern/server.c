/*
	WAP using client-server programming: A client sends a composite number to the server and the server
	replies with the prime factorization of the number. Connection should not terminate till the client
	wants to.
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
		int k;	// Input variables
		recv(csock,&k,sizeof(k),0);
		int n = k * (2*k-1);
		char ptr[n];
		for(int i=0;i<n;i++)
			ptr[i] = ' ';
		for(int i=0;i<k;i++){
			for(int j=i;j<2*k-1-i;j+=2)
				ptr[i*(2*k-1)+j] = '*';
		}
		send(csock,ptr,sizeof(char)*n,0);
	}
	close(ssock);
	return 0;
}