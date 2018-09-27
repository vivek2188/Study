/*
	-----------------SIMPLE HELLO-WORLD PROGRAM----------------------
	File Name: hello-world.c

	Command:   gcc hello-world.c    // Compiling your code
		   // Saving object file
		   gcc hello-world.c -o object-file-helloworld
		   ./a.out
		   // Strace command is used to see various system calls generated during the course of execution of the program
		   strace ./object-file-helloworld
		   // Creating strace log file
		   strace -o strace-log-file ./object-file-helloworld
		
		   
*/
#include <stdio.h>

int main(){
	printf("Hello, It's Vivek!\n");
	return 0;
}
