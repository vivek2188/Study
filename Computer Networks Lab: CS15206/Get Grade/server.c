/*
	WAP using client server socket programming: Server keeps the grade record as 85 − 100 : Grade A,
	70 − 84 : Grade B, 60 − 69 : Grade C, 50 − 59 : Grade D, 0 − 50: fail. Client enters a mark n and get
	the grade.

	E.g., if n = 75
	Output : Grade B
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

	int n;	// Input variable

	while(1){
		recv(csock,&n,sizeof(n),0);
		int grade;
		if(n>=85 && n<=100)
			grade = 0;
		else if(n>=70 && n<=84)
			grade = 1;
		else if(n>=60 && n<=69)
			grade = 2;
		else if(n>=50 && n<=59)
			grade = 3;
		else grade = -1;
		send(csock,&grade,sizeof(grade),0);
	}
	close(ssock);
	return 0;
}