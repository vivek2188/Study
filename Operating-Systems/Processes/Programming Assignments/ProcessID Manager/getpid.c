#include <stdio.h>
#include <stdlib.h>
#include "PID_Manager.c"

int main(){
	int j = allocate_map();
	if(j==0){
		printf("Allocation Unsuccessful\n");
		exit(1);
	}
	int pid = allocate_pid();
	if(pid==1)
		printf("All PIDs are in use\n");
	else printf("Process ID: %d\n",pid);
	release_pid(pid);
	return 0;
}
