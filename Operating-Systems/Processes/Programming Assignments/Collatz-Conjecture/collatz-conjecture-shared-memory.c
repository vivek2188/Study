/*
	Implementation of COLLATZ CONJECTURE using shared memory between parent and child process
	Command: gcc collatz-conjecture-shared-memory.c -lrt
		 ./a.out
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <math.h>

// Counts the number of digits in a number
int digits(int n){
	int r = 0;
	while(n>0){
		r++;
		n /= 10;
	}
	return r;
}

int main(){
	// Specifying shared memory object
	const char *name = "collatz";
	int SIZE = 4096;
	int shm_fd;
	void *ptr;
	// Program Input
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
		printf("Child ProcessID: %d\n",getpid());
		// This part performs only the WRITE operation on shared memory object
		shm_fd = shm_open(name,O_CREAT|O_RDWR,0666);
		ftruncate(shm_fd,SIZE);
		ptr = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shm_fd,0);
		sprintf(ptr,"%d ",n);
		ptr += digits(n) + 1;
		do{
			// Collatz Conjecture
			if(n%2==0)
				n = n/2;
			else n = 3*n+1;
			sprintf(ptr,"%d ",n);
			ptr += digits(n) + 1;
		}while(n!=1);
	}
	// Parent Process
	else{
		printf("Parent ProcessID: %d\n",getpid());
		wait(NULL);
		printf("Child finished its execution\n");
		// This part performs only the READ operation on shared memory object
		shm_fd = shm_open(name,O_RDONLY,0666);
		ftruncate(shm_fd,SIZE);
		ptr = mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
		printf("Pattern: %s\n",(char*)ptr);
		shm_unlink(name);	// Removing the shared memory object
	}
	return 0;
}
