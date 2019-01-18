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

	char id[5];
	printf("Enter an operator: ");
	scanf("%s", id);
	printf("-----------------------------\n");

	// Check whether Keyword is valid or not
	int matched = match_word(id, "Operators.txt");
	if(matched==-1){
		printf("ERROR: Invalid Operator\n");
	}
	else{
		printf("Valid Operator\n");
		// Append to Symbol Table if not present
		int present = match_word(id, "SymbolTableOperator.txt");
		if(present!=-1)
			printf("-> Present at index %d\n", present);
		else{
			FILE *fpa = fopen("SymbolTableOperator.txt","a");
			fprintf(fpa, "%s\n", id);
			fclose(fpa);
		}
	}
	return 0;
}
