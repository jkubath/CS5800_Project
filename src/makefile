all: lex parse run

run: parse lex
	gcc -o calc lex.yy.c parse.tab.c -lfl -lm

lex: calc.l
	flex calc.l

parse: parse.y
	bison -d -t parse.y

use:
	./calc

clean:
	rm calc lex.yy.c parse.tab.c parse.tab.h

test: all test.txt
	./calc < test.txt