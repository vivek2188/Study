#ifndef PID_MANAGER_H	// Header Gaurds
#define PID_MANAGER_H

int MIN_PID = 300;
int MAX_PID = 5000;
int size = 4701;
bool map[size];

// Helper Functions
int allocate_map(void);

int allocated_pid(void);

void release_pid(int pid);
#endif
