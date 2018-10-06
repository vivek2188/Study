#ifndef PID_MANAGER_H	// Header Gaurds
#define PID_MANAGER_H

#define MIN_PID 300
#define MAX_PID 5000
#define SIZE 300

int map[SIZE];

// Functions
int allocate_map(void);

int allocated_pid(void);

void release_pid(int pid);
#endif
