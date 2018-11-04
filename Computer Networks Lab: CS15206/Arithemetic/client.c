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

struct arithemetic{
	int a;	// Addition
	int s;	// Subtraction
	int m;	// Multiplication
	int d;	// Division (Integer Division)
};

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
		perror("Connection failed\n");
		return 1;
	}

	int n,m;	// Input variables
	int ch = 1;

	while(1){
		printf("Enter numbers: ");
		scanf("%d %d",&n,&m);
		send(csock,&n,sizeof(n),0);
		send(csock,&m,sizeof(m),0);
		struct arithemetic ans;
		recv(csock,&ans,sizeof(struct arithemetic),0);
		printf("Addition: %d\n",ans.a);
		printf("Subtraction: %d\n",ans.s);
		printf("Multiplication: %d\n",ans.m);
		printf("Integer Division: %d\n",ans.d);
		printf("Continue? ");
		scanf("%d",&ch);
		if(ch!=1){
			close(csock);
			return 0;
		}
	}
	close(csock);
	return 0;
}