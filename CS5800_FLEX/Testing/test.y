%{
#include <stdio.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int yyerror(const char * s) {
	printf("Error %s\n", s);
}

%}

%token NUMBER ADD SUB

%%
expr: NUMBER               { $$ = $1; }
	|
	NUMBER "+" NUMBER	{ printf("%d\n", ($1 + $3)); }
	|
	NUMBER ADD NUMBER {printf("Addition\n");}
	|
	ADD {
		printf("Addition\n");
	}
	;



%%
int main() { yyparse(); }