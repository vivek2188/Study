#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid<0)
		printf("Fork failed\nPID: %d\n",getpid());
	else if(pid==0){
		printf("Child Process\nPID: %d\n",getpid());
	}
	else{
		sleep(10);
		printf("Parent Process\nPID: %d\n",getpid());
	}
	return 0;
}
