%{
	int ckeywords = 0, cidentifier = 0;
%}
digit [0-9]
alphabet [A-Za-z]
identifier ("_"|{alphabet})("_"|{digit}|{alphabet})*
%%
[\t\n]+ /* Simply ignore these characters */
{identifier} {
	printf("%s is an identifier.\n", yytext);
}
auto|break|case|char|const|continue|default|do|double|else|enum		|
extern|float|for|goto|if|int|long|register|return|short|signed		|
sizeofstatic|struct|switch|typedef|union|unsigned|void|volatile|while {
	printf("%s is a keyword.\n", yytext);
}
. { 
	/* Unrecognised keyword */
	printf("char: %s\n", yytext);
}
%%
int main(int argc, char *argv[]){
	if(argc>1)
		yyin = fopen(argv[1], "r");
	else yyin = fopen("read_file.txt", "r");
	yylex();
	return 0;
}
