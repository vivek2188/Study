%{
	#include <math.h>
	// float_val = 4.56
%}
digit [0-9]
id ("_"|[A-Za-z])("_"|[A-Za-z0-9])*
%%
{digit}+ {
	printf("%s is an integer.\n", yytext);
}
{digit}+\.{digit}* {
	printf("%s is a floating point value.\n", yytext);
}
{id} {
	printf("%s is an identifier.\n", yytext);
}
.[\n] {
	printf("'%c'\n", yytext[0]);
}
[\t\n]+
.
%%
int main(int argc, char *argv[]){
	if(argc>1)
		yyin = fopen(argv[1], "r");
	else
		yyin = stdin;
	yylex();
	printf("# of cmd args: %d\n", argc);
}
