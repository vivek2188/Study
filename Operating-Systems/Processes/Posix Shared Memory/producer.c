#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(){
	// the size of shared memory object
	const int SIZE = 4096;
	// Name of the shared memory object
	const char *name = "Shary";
	// String to bes written to shared memory
	const char *m0 = "Hello";
	const char *m1 = "World";
	// Shared memory file descriptor
	int shm_fd;
	// Pointer to the shared memory object
	void *ptr;
	// Create shared memory object
	shm_fd = shm_open(name,O_CREAT | O_RDWR,0666);
	// Configure the shared memory object
	ftruncate(shm_fd,SIZE);
	// Momory map to the shared memory object
	ptr = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shm_fd,0);
	// Writing to the shared memory
	sprintf(ptr,"%s",m0);
	ptr += strlen(m0);
	sprintf(ptr,"%s",m1);
	ptr += strlen(m1);
	return 0;
}

// Compile with: gcc producer.c -o producer -lrt
