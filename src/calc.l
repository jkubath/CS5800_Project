%{

	struct data_s {
		char * s;
		double num;
	} YYSTYPE;

	#define YYSTYPE struct data_s
	
	#include <stdio.h>
	//#include <math.h>
	#include "parse.tab.h"

	extern YYSTYPE yylval;
%}

%% 
[ \t\r]+  { /* eat up whitespace */ }
"+"     return PLUS;
"-"     return MINUS;
"*" 	return MULTIPLY;
"/" 	return DIVIDE;
"%"		return MODULO;
"^"		return POWER;
"sin"	return SIN;
"cos"	return COS;
"tan"	return TAN;
"csc"	return CSC;
"sec"	return SEC;
"cot"	return COT;
"("		return LEFT_B;
")"		return RIGHT_B;
[0-9.]+ { sscanf( yytext, "%lf", &(yylval.num) ); return NUMBER; }
"d"[a-z] 	{ yylval.s = calloc( 1, sizeof(char)); yylval.s[0] = yytext[1]; return DERIV; }
[a-zA-Z0-9.^-]+ { yylval.s = calloc(strlen(yytext)+1, sizeof(char)); strcpy(yylval.s, yytext); return STRING; }
"\n" 	return EOLN;
%%