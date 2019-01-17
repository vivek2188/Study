#include <stdio.h>
#include <string.h>

int compare(char *id, char *kw){
	int len1, len2;
	len1 = strlen(id);
	len2 = strlen(kw);

	if(len1!=len2)
		return 0;	// Different
	for(int i=0; i<len1; i++){
		if(id[i]!=kw[i])
			return 0;	// Different
	}
	return 1;	// Same
}

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

int match_kwords(char *id, char *file){
	FILE *fptr;
	int MAX = 100, idx = 1, match = 0;

	fptr = fopen(file, "r");
	char line[MAX];
	while( fgets(line,MAX,fptr) ){
		if(compare(id, line) == 1){
			printf("%s", line);
			match = 1;
			break;
		}
	}
	return match;
}

int main(){
	char id[32];
	printf("Enter an identifier: ");
	scanf("%s", id);
	// Check whether identifier is valid or not
	if(valid(id)){
		// Check if it matches with any of the keywords
		printf("%d", match_kwords(id, "Keywords.txt"));
	}
	else
		printf("ERROR: Invalid Identifier\n");
	return 0;
}
