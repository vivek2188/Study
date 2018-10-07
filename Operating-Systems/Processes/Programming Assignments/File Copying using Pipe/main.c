#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char *argv[]){
	if(argc<2){
		printf("Didn't pass any parameters\n");
		exit(1);
	}
	printf("Parameters: ");
	for(int i=0;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n");
	return 0;
}
