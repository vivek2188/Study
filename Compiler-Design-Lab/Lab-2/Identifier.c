#include <stdio.h>
#include <string.h>

int valid(char *id){
	printf("Identifier: %s, Length: %d\n", id, strlen(id));
	int Valid = 1;
	if(id[0]=='_' || (id[0]>=65 && id[0]<=90) || (id[0]>=97 && id[0]<=122)){
		for(int i=1; i<strlen(id); i++){
			if(id[i]=='_' || (id[i]>=65 && id[i]<=90) || (id[i]>=97 && id[i]<=122) || (id[i]>='0' && id[i]<='9'))
				continue;
			else{
		 		Valid = 0;
				break;
			}
		}
	}
	else Valid = 0;	
	return Valid;
}

int main(){
	char id[32];
	printf("Enter an identifier: ");
	scanf("%s", id);
	// Check whether identifier is valid or not
	valid(id);
	return 0;
}
