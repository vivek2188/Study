#include <stdio.h>
#include <string.h>

int compare(char *id, char *kw){
	int len1, len2;
	len1 = strlen(id);
	len2 = strlen(kw) - 1;

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

int match_word(char *id, char *file){
	FILE *fptr;
	int MAX = 100, idx = 1, match = -1;

	fptr = fopen(file, "r");
	char line[MAX];
	while( fgets(line,MAX,fptr) ){
		if(compare(id, line) == 1){
			match = idx;
			break;
		}
		idx++;
	}
	return match;
}

int main(){

	char id[32];
	printf("Enter an identifier: ");
	scanf("%s", id);
	printf("-----------------------------\n");

	// Check whether identifier is valid or not
	if(valid(id)){

		// Check if it matches with any of the keywords
		int matched = match_word(id, "Keywords.txt");
		if(matched!=-1){
			printf("INVALID: Matched with a keyword\n");
		}
		else{
			printf("Valid Identifier\n");
			// Append to Symbol Table if not present
			int present = match_word(id, "SymbolTableIdentifier.txt");
			if(present!=-1)
				printf("-> Present at index %d\n", present);
			else{
				FILE *fpa = fopen("SymbolTableIdentifier.txt","a");
				fprintf(fpa, "%s\n", id);
				fclose(fpa);
			}
		}
	}
	else
		printf("ERROR: Invalid Identifier\n");
	return 0;
}
