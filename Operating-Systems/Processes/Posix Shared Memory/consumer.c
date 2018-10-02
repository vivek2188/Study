#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>	// Provides file control options: O_RDWR, O_WRONLY, O_RDONLY etc.
#include <stdlib.h>

int main(){
	// the size of shared memory object
	const int SIZE = 4096;
	// Name of the shared memory object
	const char *name = "Shary";
	// Shared memory file descriptor
	int shm_fd;
	// Pointer to the shared memory object
	void *ptr;
	// Create shared memory object
	shm_fd = shm_open(name,O_RDONLY,0666);
	// Configure the shared memory object
	ftruncate(shm_fd,SIZE);
	// Momory map to the shared memory object
	ptr = mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
	// Reading the shared memory object	
	printf("%s\n",(char*)ptr);
	// Remove the shared memory object
	shm_unlink(name);
	return 0;
}

// Compile with: gcc producer.c -o producer -lrt
