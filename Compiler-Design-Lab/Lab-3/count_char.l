%{
	int char_count = 0;
	int new_line_character = 0;
%}
%%
. {
	char_count++;
}
\n {
	new_line_character++;
}
%%
int main(){
	yyin = fopen("read_file.txt", "r");
	yylex();
	printf("There are %d characters and %d new line characters.\n",\
		char_count, new_line_character);
	return 0;
}
