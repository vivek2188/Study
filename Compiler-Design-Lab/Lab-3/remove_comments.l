%{
	int ckeywords = 0, cidentifier = 0;
%}

digit		[0-9]
alphabet	[A-Za-z]
identifier	("_"|{alphabet})("_"|{digit}|{alphabet})*

%%

[/]{2}.*$ {
	/* ONE LINE COMMENT */
}

[/]"*"(.|" "|\n|\t)*"*"[/] {
	/* MULTI-LINE COMMENT */
}

. {
	printf("%s", yytext);
}

%%

int main(int argc, char *argv[]){
	if(argc>1)
		yyin = fopen(argv[1], "r");
	else yyin = fopen("read_file.txt", "r");
	yylex();
	return 0;
}
