%{
	#include <stdio.h>
	#include "parse.tab.h"

	extern int yylval;
%}

%% 
"+" printf("Add\n"); return ADD;
"-" printf("SUB\n"); return SUB;
[0-9]* yylval=atoi(yytext); printf("%d\n", yylval); return NUMBER;
[a-zA-Z]* printf("Word\n");
%%