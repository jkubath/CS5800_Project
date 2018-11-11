
run: lex parse
	gcc -o calc lex.yy.c parse.tab.c -lfl -lm

lex: calc.l
	flex calc.l

parse: parse.y
	bison -d -t parse.y

use:
	./calc

test: test.l test.y
	flex test.l
	bison -d -t test.y
	gcc -o test lex.yy.c test.tab.c -lfl -lm

clean:
	rm calc lex.yy.c parse.tab.c parse.tab.h