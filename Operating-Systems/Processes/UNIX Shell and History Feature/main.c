#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80	// Maximum length command

int main(void){
	int should_run = 1;    	  // Flag to determine when to exit program
	char *args[MAX_LINE/2+1]; // Command line arguments
	
	while(should_run){
		printf("osh> ");
		fflush(stdout);
		char ch;	
		while((ch=fgetc(stdin))!='\n');
	}
	return 0;
}
