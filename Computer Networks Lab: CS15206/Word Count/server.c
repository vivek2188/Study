/*
	WAP using client-server programming: Client sends a word and a number to server and server sends
	the letter which occurs the given number of times in the given word, if it exists else send the letter
	which occurs maximum number of times in the given word. Connection should not terminate till the
	client wants to.
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
#define BUFFER_SIZE 100

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
		char str[BUFFER_SIZE];
		int n;
		recv(csock,str,sizeof(char)*BUFFER_SIZE,0);
		recv(csock,&n,sizeof(n),0);
		int count[26] = {0};
		for(int i=0;i<BUFFER_SIZE && str[i]!='\0';i++){
			if(str[i]>='A' && str[i]<='Z')
				count[str[i]-'A']++;
			else if(str[i]>='a' && str[i]<='z')
				count[str[i]-'a']++;
		}
		char ans;
		int flag = 0;
		for(int i=0;i<BUFFER_SIZE;i++){
			if(count[i]==n){
				ans = 'a' + i;
				flag = 1;
				break;
			}
		}
		if(flag)
			send(csock,&ans,sizeof(ans),0);
		else{
			int max = 0;
			for(int i=1;i<26;i++){
				if(count[i]>count[max])
					max = i;
			}
			ans = 'a' + max;
			send(csock,&ans,sizeof(ans),0);
		}

	}
	close(ssock);
	return 0;
}