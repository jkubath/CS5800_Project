%{
/* 	CS5800 Final Project - Calculator
	Summary: Calculator implementation using FLEX.

	Team Members:	Ioannis Nearchou
					Jonah Kubath

	Date: 11/09/2018
*/

/*
	Resources
	http://www.gnu.org/software/bison/manual/html_node/Error-Recovery.html
	https://www.ibm.com/developerworks/library/l-flexbison/index.html
*/

struct data_s {
	char * s;
	double num;
	char ref;
} YYSTYPE;

#define YYSTYPE struct data_s
#define arraySize 1024

#define YYERROR_VERBOSE 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double calcMod(double a,double b);
void derivative(char * s, char ref);
void functionDeriv(char * s, char * function, char ref);

int yylex();

void yyerror(const char *s) {
	printf("Error %s\n", s);
}

char resultString[arraySize];

%}

%token EQUALS NUMBER POWER MODULO EOLN  
%token SIN COS TAN CSC SEC COT 
%token LEFT_B RIGHT_B
%left PLUS MINUS
%left MULTIPLY DIVIDE
%right NOT

%token DERIV STRING ERROR

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
			printf("\t= %g\n", $2.num); return 0;
	}
	|
	commands error EOLN { printf("Input= %s\n", $2.s); return 0; }
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

power: function
	| power POWER primary			{ $$.num = pow($1.num, $3.num); }
	;

function: derivative
	|
	SIN LEFT_B NUMBER RIGHT_B { $$.num = sinf($3.num); }
	|
	COS LEFT_B NUMBER RIGHT_B { $$.num = cosf($3.num); }
	|
	TAN LEFT_B NUMBER RIGHT_B { $$.num = tanf($3.num); }
	;

derivative: primary
	|
	DERIV SIN LEFT_B polynomial RIGHT_B RIGHT_B { functionDeriv($5.s, "sin", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B COS LEFT_B polynomial RIGHT_B RIGHT_B { functionDeriv($5.s, "cos", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B TAN LEFT_B polynomial RIGHT_B RIGHT_B { functionDeriv($5.s, "tan", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B CSC LEFT_B polynomial RIGHT_B RIGHT_B { functionDeriv($5.s, "csc", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B SEC LEFT_B polynomial RIGHT_B RIGHT_B { functionDeriv($5.s, "sec", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B COT LEFT_B polynomial RIGHT_B RIGHT_B { functionDeriv($5.s, "cot", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B polynomial RIGHT_B {printf("Poly %s\n", $2.s); derivative($1.s, $1.ref); $$.s = resultString; }
	|
	DERIV LEFT_B NUMBER RIGHT_B {printf("Derivative number\n"); $$.s = "0"; }
	;

polynomial: primary
	| polynomial PLUS primary { if($3.s != NULL){ printf("primary1 %s\n", $3.s);} else printf("primary1 %G\n", $3.num);}
	| polynomial MINUS primary
	;

primary: 
	NUMBER { $$.num = $1.num; $$.s = NULL;}
	|
	STRING { $$.s = calloc(strlen($1.s), sizeof(char)); strcpy($$.s, $1.s); printf("String %s\n", $$.s);}
	;



%%

/**
 * Function for modulo of two doubles
 */
double calcMod(double a,double b) {
	int intA = a;
	int intB = b;
	if (intA != (double) a || intB != (double) b) {
		printf("Double was cast to integer. (%d %% %d)\n", intA, intB);
	}

	return (double) (intA % intB);
}

/** 
 * Calculate the derivative of the given string in referance to the given
 * character 'ref'
 * Example:
 * s = '2x^2'
 * ref = 'x'
 * answer = '4x'
 */
void derivative(char * s, char ref) {
  	char * token = NULL;
  	char * nextToken = NULL;
  	char * result = calloc(arraySize, sizeof(char));
  	char * individualTerm = calloc(arraySize, sizeof(char));;

  	/* Break the given equation into tokens seperated by spaces */
  	token = strtok_r(s, " ", &nextToken);

  	while (token != NULL)
  	{
    	double coef = 1;
    	double exponent = 0;

    	//char * remaining = NULL;
    	char * coefString = calloc(arraySize, sizeof(char));
    	char * base = calloc(arraySize, sizeof(char));
    	char * expString = calloc(arraySize, sizeof(char));
    	char * variables = calloc(arraySize, sizeof(char)); // Used to hold other variables no being derived
    	int negative = 0;

    	/* --------------------------------------------------------- */
    	/* Break the string into 4 parts - coeficient, variables, base, exponent */
    	if(strlen(token) > 1 && token[0] == '-') {
    		negative = 1;
    		token++;
    	}

    	/* Remove any coefficient from the front */
    	int coefIndex = 0;
    	while(token[0] != '\0' && isdigit(token[0])) {
    		coefString[coefIndex] = token[0];
    		token++;
    		coefIndex++;
    	}
    	
    	//Remove variables not being derived
		int varIndex = 0;
		while(token[0] != '\0') {
			/* We have found the variable to derive by */
			if(token[0] == ref) {
				base[0] = token[0];
				token++;
				/* Is there an exponent for the variable */
				if(token[0] == '^') {
					token++;
					/* Remove all the digits for the exponent */
					int index = 0;
					while(isdigit(token[0]) || token[0] == '-'){
						expString[index] = token[0];
						token++;
						index++;
					}
				}
			}
			else {
				/* Add it to the string of not derived variables */
				variables[varIndex] = token[0];
				token++;
				varIndex++;
			}
			
		}

    	/* Done splitting string */
    	/* --------------------------------------------------------- */
    	
    	/* --------------------------------------------------------- */
    	/* Convert strings to doubles */
    	if(coefString != NULL && strlen(coefString) > 0) {
    		coef = atof(coefString);
    	}

    	/* Multiply the coef by the exponent and drop by 1 */
    	if(expString != NULL && strlen(expString) > 0) {
    		exponent = atof(expString);
    		coef *= exponent;
    		exponent -= 1;
    	}
    	/* Done splitting strings */
    	/* --------------------------------------------------------- */
    	
    	/* --------------------------------------------------------- */
    	/* Make result string */
    	if(base != NULL && strlen(base) > 0 ) {
    		if(exponent != 0 && coef != 1) {
    			if(exponent == 1) {
    				snprintf(individualTerm, arraySize, "%G%s%s", coef, variables, base);
    			}
    			else {
    				snprintf(individualTerm, arraySize, "%G%s%s^%G", coef, variables, base, exponent);
    			}
    		}
    		else if(exponent == 0 && coef != 1) {
    			snprintf(individualTerm, arraySize, "%G%s", coef, variables);
    		}
    		else if(exponent != 0 && coef == 1) {
    			snprintf(individualTerm, arraySize, "%s%s^%G", variables, base, exponent);
    		}
    		else if(exponent == 0 && coef == 1) {
    			if(strlen(variables) > 0)
    				snprintf(individualTerm, arraySize, "%s", variables);
    			else {
    				snprintf(individualTerm, arraySize, "%s", "1");
    			}
    		}
	    	else {
	    		printf("Derivative error\n");
	    	}

    	}
    	else {
    		if(variables[0] == '+' || variables[0] == '-') {
    			snprintf(individualTerm, arraySize, " %s ", variables);
    		}
    		else {
    			individualTerm[0] = '\0';
    			result[strlen(result) - 2] = '\0';
    		}
    	}

    	if(strlen(individualTerm) != 0) {
    		//Double negative
    		if(individualTerm[0] == '-') {
    			int index = 0;
    			while(individualTerm[index] != '\0') {
    				individualTerm[index] = individualTerm[index + 1];
    				index++;
    			}

    			/* Flip negative */
    			if(negative) {
    				negative = 0;
    			}
    			else
    				negative = 1;
    		}

    		/* Is the term negative */
    		if(negative == 1) {
    			int end = strlen(result);
    			if(end - 2 < 0) {
    				result[0] = '-';
    			}
    			else if(result[end - 2] == '-') {
    				result[end - 2] = '+';
    			}
    			else {
    				result[end - 2] = '-';
    			}
    		}
    		strcat(result, individualTerm);
    	}
    	/* Done building result string */
    	/* --------------------------------------------------------- */

    	//Get the next token
    	token = strtok_r(NULL, " ", &nextToken);
  	}

  	strncpy(resultString, result, arraySize);
}

/**
 * Calculate the derivative of various functions
 * sin, cos, tan, 
 */
void functionDeriv(char * s, char * function, char ref) {
	char * original = calloc(strlen(s), sizeof(char));
	//Copy original string
	strcpy(original, s);
	//Get the derivative of the inner function
	derivative(s, ref);

	//Copy the derivative string
	char * deriv = calloc(strlen(resultString), sizeof(char));
	strcpy(deriv, resultString);

	/* SIN */
	if(strcmp(function, "sin") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "cos(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, arraySize, "(%s)cos(%s)", deriv, original);
		}

	}
	/* COS */
	else if(strcmp(function, "cos") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "-sin(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, arraySize, "-(%s)sin(%s)", deriv, original);
		}

	}
	/* TAN */
	else if(strcmp(function, "tan") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "sec^2(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, arraySize, "(%s)sec^2(%s)", deriv, original);
		}
	}
	/* CSC */
	else if(strcmp(function, "csc") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "-csc(%s)cot(%s)", original, original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			/* Double negative */
			if(deriv[0] == '-') {
				deriv++;
				snprintf(resultString, arraySize, "(%s)csc(%s)cot(%s)", deriv, original, original);
			}
			else {
				snprintf(resultString, arraySize, "-(%s)csc(%s)cot(%s)", deriv, original, original);
			}
		}
	}
	/* SEC */
	else if(strcmp(function, "sec") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "sec(%s)tan(%s)", original, original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, arraySize, "(%s)sec(%s)tan(%s)", deriv, original, original);
		}
	}

}

int main() 
{ 
	yyparse();
}


