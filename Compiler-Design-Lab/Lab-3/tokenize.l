%{
	/* TOKENIZATION CODE */
%}

digit		[0-9]
alphabet	[A-Za-z]
identifier	("_"|{alphabet})("_"|{digit}|{alphabet})*

unary_op	"++"|"--"
arithemetic_op	"+"|"-"|"*"|"/"|"%"
relational_op	"<"|"<="|">"|">="|"=="|"!="
assignment_op	"="|"+="|"-="|"*="|"/="|"%="
bitwise_op	"&"|"|"|"<<"|">>"|"~"|"^"
logical_op	"&&"|"||"|"!"

separator	";"|","|"."|"("|")"|"["|"]"|"{"|"}"

%%

(" "|\t|\n)+                /* WHITESPACES */

[/]"*"(.|" "|\n|\t)*"*"[/] /* MULTI-LINE COMMENT */

[/]{2}.*$                  /* SINGLE LINE COMMENT */

{digit}+ {
	/* INTEGERS */
	printf("'%s': INTEGER, ", yytext);
}

{digit}+\.{digit}*|{digit}*\.{digit}+ {
	/* FLOATING POINT NUMBER */
	printf("'%s': FLOATING POINT NUMBER\t", yytext);
}

auto|break|case|char|const|continue|default|do|double|else|enum		|
extern|float|for|goto|if|int|long|register|return|short|signed		|
sizeofstatic|struct|switch|typedef|union|unsigned|void|volatile|while {
	/* KEYWORDS */
	printf("'%s': KEYWORD, ", yytext);
}

{identifier} {
	/* IDENTIFIERS */
	printf("'%s': IDENTIFIER, ", yytext);
}

{unary_op}|{arithemetic_op}|{relational_op}	|
{assignment_op}|{bitwise_op}|{logical_op} {
	/* OPERATORS */
	printf("'%s': OPERATOR, ", yytext);
}

{separator} {
	/* SEPARATORS */
	printf("'%s': SEPARATOR\n", yytext);
}

.     /* UNRECOGNISED CHARACTERS */

%%

int main(int argc, char *argv[]){
	if(argc>1)
		yyin = fopen(argv[1], "r");
	else yyin = fopen("read_file.txt", "r");
	yylex();
	return 0;
}
