%{
/* 	CS5800 Final Project - Calculator
	Summary: Calculator implementation using FLEX.

	Team Members:	Ioannis Nearchou
					Jonah Kubath

	Date: 11/09/2018
*/

struct data_s {
	char * s;
	double num;
} YYSTYPE;

#define YYSTYPE struct data_s


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double calcMod(double a,double b);
void derivative(char * s);

int yylex();

void yyerror(const char *s) {
	printf("Error %s\n", s);
}

char resultString[1024];

%}

%token EQUALS NUMBER POWER EOLN MODULO SIN COS TAN DERIV STRING
%token LEFT_B RIGHT_B
%left PLUS MINUS
%left MULTIPLY DIVIDE
%right NOT

%%
commands: 
	/* Empty */
	|
	commands EOLN
	| 
	commands exp EOLN			
	{ 
		if($2.s != NULL) {
			printf("\t= %s\n", $2.s);
		}
		else
			printf("\t= %g\n", $2.num); return 0;}
	;

exp: 	add_sub
	;

add_sub: mult_div
	|	add_sub PLUS mult_div		{ $$.num = $1.num + $3.num; }
	|	add_sub MINUS mult_div		{ $$.num = $1.num - $3.num; }

mult_div: power
	|	mult_div MULTIPLY power		{ $$.num = $1.num * $3.num; }
	|	mult_div DIVIDE power		{ $$.num = $1.num / $3.num; }
	|	mult_div MODULO power		{ $$.num = calcMod($1.num, $3.num); }

power: primary
	| power POWER primary			{ $$.num = pow($1.num, $3.num); }
	;

primary:
	NUMBER { $$.num = $1.num;}
	| function
	;

function: SIN LEFT_B NUMBER RIGHT_B { $$.num = sinf($3.num);}
	|
	COS LEFT_B NUMBER RIGHT_B { $$.num = cosf($3.num);}
	|
	TAN LEFT_B NUMBER RIGHT_B { $$.num = tanf($3.num);}
	|
	DERIV LEFT_B STRING RIGHT_B { derivative($3.s); $$.s = resultString; }
	|
	DERIV LEFT_B NUMBER RIGHT_B { $$.s = "0"; }
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

void derivative(char * s) {
  	char * token;
  	char * nextToken;
  	char result[1024];
  	char individualTerm[1024];

  	/* Break the given equation into tokens seperated by spaces */
  	token = strtok_r(s, " ", &nextToken);

  	while (token != NULL)
  	{
    	double coef = 1;
    	double exponent = 1;

    	char * remaining = NULL;
    	char * coefString = NULL;
    	char * base = NULL;
    	char * expString = NULL;

    	/* --------------------------------------------------------- */
    	/* Break the string into 3 parts - coeficient, base, exponent */
    	if(isdigit(token[0])) {
    		sscanf(token, "%lf", &coef);

    		//Remove the coefficient digits
    		while(isdigit(token[0])) {
    			token++;
    		}

    		base = strtok_r(token , "^", &remaining);
    		expString = remaining;
    	}
    	//No coefficient
    	else {
    		base = strtok_r(token , "^", &expString);
    	}
    	/* Done splitting string */
    	/* --------------------------------------------------------- */

    	/* --------------------------------------------------------- */
    	/* Convert strings to doubles */
    	if(coefString != NULL) {
    		coef = atof(coefString);
    	}

    	if(strlen(expString) != 0) {
    		coef *= atof(expString);
    		exponent = atof(expString);
    		exponent -= 1;
    	}
    	/* Done splitting strings */
    	/* --------------------------------------------------------- */

    	/* --------------------------------------------------------- */
    	/* Make result string */
    	if(strlen(base) != 0 ) {
    		if(base[0] == '+' || base[0] == '-') {
    			snprintf(individualTerm, sizeof(individualTerm), " %s ", base);
    		}
    		else if(exponent != 0 && coef != 1) {
    			snprintf(individualTerm, sizeof(individualTerm), "%G%s^%G", coef, base, exponent);
    		}
    		else if(exponent == 0) {
    			snprintf(individualTerm, sizeof(individualTerm), "%G", coef);
    		}
    		else if(coef == 1) {
    			snprintf(individualTerm, sizeof(individualTerm), "%s^%G", base, exponent);
    		}
	    	else {
	    		printf("None\n");
	    	}

    	}

    	if(strlen(individualTerm) != 0) {
    		strcat(result, individualTerm);
    	}
    	/* Done building result string */
    	/* --------------------------------------------------------- */

    	//Get the next token
    	token = strtok_r(NULL, " ", &nextToken);
  	}

  	strncpy(resultString, result, 1024);
}

int main() 
{ 
	yyparse();
}


