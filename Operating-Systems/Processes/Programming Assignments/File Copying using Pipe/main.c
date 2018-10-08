#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 150
#define READ_END 0
#define WRITE_END 1

int main(int argc,char *argv[]){
if(argc<2){
		printf("Didn't pass any parameters\n");
		exit(1);
	}
	printf("Parameters: ");
	for(int i=0;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n");
	// Messages to be passes via pipe
	char write_msg[BUFFER_SIZE] = "";
	char read_msg[BUFFER_SIZE];
	FILE *fp;
	// Reading the input file and copying its content to write message
	fp = fopen(argv[1],"r");
	char ptr[BUFFER_SIZE];
	while(fgets(ptr,BUFFER_SIZE,fp)!=NULL)
		strcat(write_msg,ptr);
	return 0;
}
