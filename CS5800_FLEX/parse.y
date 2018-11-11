%{
/* 	CS5800 Final Project - Calculator
	Summary: Calculator implementation using FLEX.

	Team Members:	Ioannis Nearchou
					Jonah Kubath

	Date: 11/09/2018
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define YYSTYPE double

double calcMod(double a,double b);

int yylex();

void yyerror(const char *s) {
	printf("Error %s\n", s);
}

%}

%token EQUALS NUMBER POWER EOLN MODULO SIN COS TAN DERIV
%left PLUS MINUS
%left MULTIPLY DIVIDE
%right NOT

%%
commands: 
	/* Empty */
	|
	commands EOLN
	| 
	commands exp EOLN			{ printf("= %g\n", $2); return 0;}
	;

exp: 	add_sub
	;

add_sub: mult_div
	|	add_sub PLUS mult_div		{ $$ = $1 + $3; }
	|	add_sub MINUS mult_div		{ $$ = $1 - $3; }

mult_div: power
	|	mult_div MULTIPLY power		{ $$ = $1 * $3; }
	|	mult_div DIVIDE power		{ $$ = $1 / $3; }
	|	mult_div MODULO power		{ $$ = calcMod($1, $3); }

power: primary
	| power POWER primary			{ $$ = pow($1, $3); }
	;

primary:
	NUMBER { $$ = $1;}
	| function
	;

function: SIN NUMBER { $$ = sinf($2);}
	|
	COS NUMBER { $$ = cosf($2);}
	|
	TAN NUMBER { $$ = tanf($2);}
	|
	DERIV {printf("Derivative\n");}
	
;
%%

double calcMod(double a,double b) {
	int intA = a;
	int intB = b;
	if (intA != (double) a || intB != (double) b) {
		printf("Double was cast to integer. (%d %% %d)\n", intA, intB);
	}

	return (double) (intA % intB);
}

int main() 
{ 
	yyparse();
}


