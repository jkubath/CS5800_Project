%{
	#include <stdio.h>
	#include "parse.tab.h"
%}

%% 
"+" return ADD;
"-" return SUB;
[0-9]* yylval=atoi(yytext); return NUMBER;
[a-zA-Z]* printf("Word\n");
%%