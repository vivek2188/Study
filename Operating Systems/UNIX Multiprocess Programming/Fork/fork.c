// fork() System Call for creating the processes

#include <stdio.h>
#include <sys/types.h>	// defines the datatype pid_t = Process Id
#include <string.h>

#define MAX 100

int main(){
	pid_t pid;
	fork();
	pid = getpid();
	// Can use getppid() for accessing the Parent Process ID.
	char output_string[MAX];

	int i;
	for(i=0;i<5;i++){
		//printf("Process ID: %d Int: %d\n",pid,i);
		sprintf(output_string,"Process ID: %d Int: %d\n",pid,i);
        	// First argument denotes the file descriptor(fd)
                // It represent the STDOUT file as its default fd is 1.
		write(1,output_string,strlen(output_string)); 
/*
 What is the reason of using write rather than printf? It is because
 printf() is "buffered," meaning printf() will group the output of a
 process together. While buffering the output for the parent process,
 the child may also use printf to print out some information, which will
 also be buffered. As a result, since the output will not be send to
 screen immediately, you may not get the right order of the expected
 result. Worse, the output from the two processes may be mixed in
 strange ways. To overcome this problem, you may consider to use the "unbuffered" write.
*/

	}
	return 0;
}
