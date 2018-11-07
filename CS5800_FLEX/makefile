
run: l parse
	gcc -o calc lex.yy.c parse.tab.c -lfl -lm

l: test.l
	flex test.l

parse: parse.y
	bison -d parse.y

use:
	./calc