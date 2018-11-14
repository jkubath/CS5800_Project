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
void derivative(char * s, char ref);
void functionDeriv(char * s, char * function, char ref);

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

function: derivative
	|
	SIN LEFT_B NUMBER RIGHT_B { $$.num = sinf($3.num);}
	|
	COS LEFT_B NUMBER RIGHT_B { $$.num = cosf($3.num);}
	|
	TAN LEFT_B NUMBER RIGHT_B { $$.num = tanf($3.num);}
	;

derivative:
	DERIV LEFT_B SIN LEFT_B STRING RIGHT_B RIGHT_B { functionDeriv($5.s, "sin", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B COS LEFT_B STRING RIGHT_B RIGHT_B { functionDeriv($5.s, "cos", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B TAN LEFT_B STRING RIGHT_B RIGHT_B { functionDeriv($5.s, "tan", $1.s[0]); $$.s = resultString; }
	|
	DERIV LEFT_B STRING RIGHT_B { derivative($3.s, $1.s[0]); $$.s = resultString; }
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

void derivative(char * s, char ref) {
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
    	char variables[1024]; // Used to hold other variables no being derived
    	memset(variables, 0, sizeof(variables));
    	int negative = 0;

    	/* --------------------------------------------------------- */
    	/* Break the string into 4 parts - coeficient, variables, base, exponent */
    	if(strlen(token) > 1 && token[0] == '-') {
    		negative = 1;
    		token++;
    	}

    	if(isdigit(token[0])) {
    		sscanf(token, "%lf", &coef);

    		//Remove the coefficient digits
    		while(isdigit(token[0]) && token[0] != '\0') {
    			token++;
    		}

    		//Remove variables not being derived
    		int index = 0;
    		while(token[0] != ref && token[0] != '\0') {
    			variables[index] = token[0];
    			token++;
    			index++;
    		}

    		if(strlen(token) > 0) {
    			base = strtok_r(token , "^", &remaining);
    			expString = remaining;
    		}
    	}
    	//No coefficient
    	else {
    		//Remove variables not being derived
    		int index = 0;
    		while(strlen(token) > 0 && token[0] != ref) {
    			variables[index] = token[0];
    			token++;
    			index++;
    		}

    		if(strlen(token) > 0) {
	    		base = strtok_r(token, "^", &expString);
    		}
    	}

    	/* Done splitting string */
    	/* --------------------------------------------------------- */
    	
    	/* --------------------------------------------------------- */
    	/* Convert strings to doubles */
    	if(coefString != NULL && strlen(coefString) > 0) {
    		coef = atof(coefString);
    	}

    	if(base != NULL && strlen(base) > 0 && expString != NULL && strlen(expString) == 0) {
    		exponent = 0;
    	}
    	else if(expString != NULL && strlen(expString) > 0) {
    		coef *= atof(expString);
    		exponent = atof(expString);
    		exponent -= 1;
    	}
    	/* Done splitting strings */
    	/* --------------------------------------------------------- */
    	
    	/* --------------------------------------------------------- */
    	/* Make result string */
    	if(base != NULL && strlen(base) > 0 ) {
    		if(exponent != 0 && coef != 1) {
    			if(exponent == 1) {
    				snprintf(individualTerm, sizeof(individualTerm), "%G%s%s", coef, variables, base);
    			}
    			else {
    				snprintf(individualTerm, sizeof(individualTerm), "%G%s%s^%G", coef, variables, base, exponent);
    			}
    		}
    		else if(exponent == 0 && coef != 1) {
    			snprintf(individualTerm, sizeof(individualTerm), "%G%s", coef, variables);
    		}
    		else if(exponent != 0 && coef == 1) {
    			snprintf(individualTerm, sizeof(individualTerm), "%s%s^%G", variables, base, exponent);
    		}
    		else if(exponent == 0 && coef == 1) {
    			if(strlen(variables) > 0)
    				snprintf(individualTerm, sizeof(individualTerm), "%s", variables);
    			else {
    				snprintf(individualTerm, sizeof(individualTerm), "%s", "1");
    			}
    		}
	    	else {
	    		printf("None\n");
	    	}

    	}
    	else {
    		if(variables[0] == '+' || variables[0] == '-') {
    			snprintf(individualTerm, sizeof(individualTerm), " %s ", variables);
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

    			if(negative) {
    				negative = 0;
    			}
    			else
    				negative = 1;
    		}
    		if(negative) {
    			int end = strlen(result);
    			if(result[end - 2] == '-') {
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

  	strncpy(resultString, result, 1024);
}

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
			snprintf(resultString, sizeof(resultString), "cos(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, sizeof(resultString), "(%s)cos(%s)", deriv, original);
		}

	}
	/* COS */
	else if(strcmp(function, "cos") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, sizeof(resultString), "-sin(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, sizeof(resultString), "-(%s)sin(%s)", deriv, original);
		}

	}
	/* TAN */
	else if(strcmp(function, "tan") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, sizeof(resultString), "sec^2(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, sizeof(resultString), "(%s)sec^2(%s)", deriv, original);
		}

	}



}

int main() 
{ 
	yyparse();
}


