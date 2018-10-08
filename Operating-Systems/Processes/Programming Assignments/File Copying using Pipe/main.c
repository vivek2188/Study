// Command:	./filecopy input.txt copy.txt
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
	char read_msg[BUFFER_SIZE] = " ";
	int fd[2];
	// Create the pid
	if(pipe(fd)==-1){
		printf("Pipe failed\n");
		return 1;
	}
	// Fork a child process
	pid_t pid;
	pid = fork();
	if(pid<0){
		printf("Fork failed\n");
		return 1;
	}
	else if(pid>0){ // Parent Process
		// Close the unused end
		close(fd[READ_END]);
		FILE *fp;
		// Reading the input file and copying its content to write message
		fp = fopen(argv[1],"r");
		char ptr[BUFFER_SIZE];
		while(fgets(ptr,BUFFER_SIZE,fp)!=NULL)
			strcat(write_msg,ptr);
		// Writing to the pipe
		printf("Writing onto the pipe\n");
		write(fd[WRITE_END],write_msg,strlen(write_msg)+1);
		// Closing the write end
		close(fd[WRITE_END]);
	}
	else{ // Child Process
		// Close the unused end
		close(fd[WRITE_END]);
		// Reading from the pipe
		printf("Reading from the pipe\n");
		read(fd[READ_END],read_msg,BUFFER_SIZE);
		// Triming the message received from the pipe to get rid of NULL characters
		int length = 0;
		for(int i=0;i<BUFFER_SIZE && read_msg[i]!='\0';i++)
			length++;
		// Copying to the given file
		printf("Copying to copy.txt\n");
		FILE *fp = fopen(argv[2],"w");
		fwrite(read_msg,sizeof(char),length*sizeof(char),fp);
		fclose(fp);
		// Closing the read end
		close(fd[READ_END]);
	}
	return 0;
}
