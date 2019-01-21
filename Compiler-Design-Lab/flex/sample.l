%{
	#include <math.h>
	// float_val = 4.56
%}
digit [0-9]
id [A-Za-z][A-Za-z0-9]*
%%
{digit}+ {
	printf("%s is an integer.\n", yytext);
}
{digit}+\.{digit}* {
	printf("%s is a floating point value.\n", yytext);
}
[\t\n]+
%%
int main(int argc, char *argv[]){
	if(argc>1)
		yyin = fopen(argv[1], "r");
	else
		yyin = stdin;
	yylex();
	printf("# of cmd args: %d\n", argc);
}
