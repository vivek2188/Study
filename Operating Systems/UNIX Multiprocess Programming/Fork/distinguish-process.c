#include <stdio.h>
#include <sys/types.h>
#define MAX_COUNT 100

void ChildProcess();
void ParentProcess();

int main(){
	pid_t pid;
	pid = fork();	// Number of processes will increase by the factor of two.
	if(pid==0)	// Child Process
		ChildProcess();
	else 
		ParentProcess();
	return 0;
}

void ChildProcess(){
	int i;
	for(i=0;i<MAX_COUNT;i++)
		printf("Child: %d\n",i);
	printf("-----Child Process-----\n");
}

void ParentProcess(){
	int i;
	for(i=0;i<MAX_COUNT;i++)
		printf("Parent: %d\n",i);
	printf("-----Parent Process-----\n");
}

/*
 Due to the fact that the CPU scheduler will assign a time quantum to
 each process, the parent or the child process will run for some time
 before the control is switched to the other and the running process
 will print some lines before you can see any line printed by the other
 process. Therefore, the value of MAX_COUNT should be large enough so
 that both processes will run for at least two or more time quanta. If
 the value of MAX_COUNT is so small that a process can finish in one
 time quantum, you will see two groups of lines, each of which contains
 all lines printed by the same process. 
*/
