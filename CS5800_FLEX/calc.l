%{
	#define YYSTYPE double
	#include <stdio.h>
	#include "parse.tab.h"
	#include <math.h>


	extern double yylval;
%}

%% 
[ \t] { ; }
"+"     return PLUS;
"-"     return MINUS;
"*" 	return MULTIPLY;
"/" 	return DIVIDE;
"%"		return MODULO;
"^"		return POWER;
"sin"	return SIN;
"cos"	return COS;
"tan"	return TAN;
"dx" printf("Derivative");
[0-9.]+ { sscanf( yytext, "%lf", &yylval ); return NUMBER ; }
[a-zA-Z0-9.]+ { return DERIV; }
"\n" 	return EOLN;
%%