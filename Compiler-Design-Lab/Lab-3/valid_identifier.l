%{
	int ckeywords = 0, cidentifier = 0;
%}

digit		[0-9]
alphabet	[A-Za-z]
identifier	("_"|{alphabet})("_"|{digit}|{alphabet})*

%%

[\t\n]+|" "+ {
	/* WHITESPACES */
}

{digit}+ {
	/* INTEGERS */
}

{digit}+\.{digit}*|{digit}*\.{digit}+ {
	/* FLOATING POINT NUMBER */
}

auto|break|case|char|const|continue|default|do|double|else|enum		|
extern|float|for|goto|if|int|long|register|return|short|signed		|
sizeofstatic|struct|switch|typedef|union|unsigned|void|volatile|while {
	/* KEYWORDS */
}

{identifier} {
	/* IDENTIFIERS */
	printf("\"%s\" is an IDENTIFIER.\n", yytext);
}

. {
	/* UNRECOGNISED CHARACTERS */
}

%%

int main(int argc, char *argv[]){
	if(argc>1)
		yyin = fopen(argv[1], "r");
	else yyin = fopen("read_file.txt", "r");
	yylex();
	return 0;
}
