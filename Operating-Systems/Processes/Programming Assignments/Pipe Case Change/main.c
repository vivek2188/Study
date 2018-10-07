#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MAX_BUFFER 25
#define READ_END 0
#define WRITE_END 1

int main(){
	char write_msg[MAX_BUFFER];
	char read_msg[MAX_BUFFER];
	// Getting the input
	printf("Input string: ");
	gets(write_msg);
	int fd[2];
	pid_t pid;
	// Create the pipe
	if(pipe(fd)==-1){
		fprintf(stderr,"Pipe failed\n");
		return 1;
	}
	// Fork a child process
	pid = fork();
	if(pid<0){
		fprintf(stderr,"Fork failed\n");
		return 1;
	}
	// Child Process
	else if(pid==0){
		// Close the unused end of the pipe
		close(fd[READ_END]);
		// Changing the CASE
		for(int i=0;i<MAX_BUFFER && write_msg[i]!='\0';i++){
			if(write_msg[i]==' ')
				continue;
			if(write_msg[i]-'A'<=25)
				write_msg[i] = write_msg[i] - 'A' + 'a';
			else write_msg[i] = write_msg[i] - 'a' + 'A';
		}
		
		// Writing to the pipe
		write(fd[WRITE_END],write_msg,strlen(write_msg)+1);
		// Close the write end
		close(fd[WRITE_END]);
		
	}
	// Parent Process
	else{
		// Close the unused end
		close(fd[WRITE_END]);
		// Reading from the pipe
		read(fd[READ_END],read_msg,MAX_BUFFER);
		printf("Output string: %s\n",read_msg);
		// Close the read end
		close(fd[READ_END]);
	}
	return 0;
}
