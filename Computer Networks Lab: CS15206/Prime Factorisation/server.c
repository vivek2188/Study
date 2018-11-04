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
		int n;	// Input variables
		recv(csock,&n,sizeof(n),0);
		int k = n;
		int ans[k];
		for(int i=0;i<k;i++)
			ans[i] = -1;
		int j=0;
		for(int i=2;i*i<=n;i++){
			while(n%i==0){
				ans[j] = i;
				n = n/i;
				j = j+1;
			}
		}
		if(n>1)
			ans[j] = n;
		send(csock,ans,sizeof(int)*k,0);
	}
	close(ssock);
	return 0;
}