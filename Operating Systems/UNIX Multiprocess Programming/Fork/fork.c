// fork() System Call for creating the processes

#include <stdio.h>
#include <sys/types.h>	// defines the datatype pid_t = Process Id
#include <string.h>

#define MAX 100
#define MAX_COUNT 200
/*
 If fork() returns a negative value, the creation of child process was unsuccessful.
 Returns zero to the newly created child process.
 Returns positive value to the parent.
*/
int main(){
	pid_t pid;
	fork();
	pid = getpid();
	// Can use getppid() for accessing the Parent Process ID.
	char output_string[MAX];

	int i;
	for(i=0;i<MAX_COUNT;i++){
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

 Both the processes run concurrently, the output lines are mixed in a
 rather unpredictable way. Moreover, the order of these lines are
 determined by the CPU Scheduler. Hence, if you run this program again,
 you may get a totally different result.
*/

	}
	return 0;
}
