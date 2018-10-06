#include <stdio.h>
#include "PID_Manager.h"

int allocate_map(void){
	// Initialising the data structure for representing PIDs
	for(int i=0;i<SIZE;i++)
		map[i] = 0;
	return 1;
}

int allocate_pid(void){
	// Allocating a pid
	int j;
	for(j=0;j<SIZE;j++){
		if(map[j]==0){
			map[j] = 1;
			return (j + MIN_PID);
		}
	}
	// All PIDs in use
	return 1;
}

void release_pid(int pid){
	// Release a pid
	map[pid-MIN_PID] = 0;
}
