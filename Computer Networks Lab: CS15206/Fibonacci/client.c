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
		perror("Connection failed\n");
		return 1;
	}

	int n;	// Input variable
	int ch = 1;

	while(1){
		printf("Enter number: ");
		scanf("%d",&n);
		int ans[n+1];
		send(csock,&n,sizeof(n),0);
		recv(csock,ans,sizeof(int)*(n+1),0);
		for(int i=0;i<=n;i++)
			printf("F%d: %d\n",i,ans[i]);
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