#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Enter number: ");
	scanf("%d",&n);
	if(n<=0){
		printf("Number should be greater than 0\n");
		exit(0);
	}
	pid_t pid;
	pid = fork();
	if(pid < 0){
		printf("Fork Failed\n");
		exit(1);
	}
	// Child Process
	else if(pid==0){
		printf("Child ProcessID: %d\nPattern: %d ",getpid(),n);
		do{
			// Collatz Conjecture
			if(n%2==0)
				n = n/2;
			else n = 3*n+1;
			printf("%d ",n);
		}while(n!=1);		
		printf("\n");
	}
	// Parent Process
	else{
		printf("Parent ProcessID: %d\n",getpid());
		wait(NULL);
		printf("Child finished its execution\n");	
	}
	return 0;
}
