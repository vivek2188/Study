/*
	WAP using client server socket programming: Client will enter two numbers n and m. The server will
	return the results of addition (a = n + m), subtraction (b = n − m), multiplication (c = n × m) and
	division (d = n/m).

	E.g., if n = 10 and m = 5
	Output : a = n + m = 15, b = n − m = 5, c = n × m = 50, d = n/m = 2
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

struct arithemetic{
	int a;	// Addition
	int s;	// Subtraction
	int m;	// Multiplication
	int d;	// Division (Integer Division)
};

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

	int n,m;	// Input variables

	while(1){
		recv(csock,&n,sizeof(n),0);
		recv(csock,&m,sizeof(m),0);
		struct arithemetic ans;
		ans.a = n+m;
		ans.s = n-m;
		ans.m = n*m;
		ans.d = n/m;
		send(csock,&ans,sizeof(struct arithemetic),0);
	}
	close(ssock);
	return 0;
}