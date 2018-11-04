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
#define BUFFER_SIZE 100

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

	int ch = 1;

	while(1){
		char str[BUFFER_SIZE];
		printf("Enter string: ");
		scanf("%s",str);
		send(csock,str,sizeof(char)*BUFFER_SIZE,0);
		int n;
		printf("Enter number: ");
		scanf("%d",&n);
		send(csock,&n,sizeof(n),0);
		char ans;
		recv(csock,&ans,sizeof(ans),0);
		printf("Answer: %c\n",ans);
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