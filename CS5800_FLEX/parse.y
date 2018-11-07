%{
#include <stdio.h>
#include <string.h>

int yylex();

void yyerror(const char *s) {
	printf("Error %s\n", s);
}

%}

%token NUMBER ADD SUB

%%
commands: 
	/* Empty */
	| 
	commands command
	;


command:
	add 
	| 
	sub
	;

add:
	NUMBER ADD NUMBER
	{
		printf("%d\n", ($1 + $3));
	}
	;

sub: 
	NUMBER SUB NUMBER
	{
		printf("%d\n", ($1 - $3));
	}
	;

%%

int main() { yyparse(); }
