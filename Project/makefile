edupi: lexer.l parser.y ast.c ast.h operations.c operations.h
	flex lexer.l ; bison -d parser.y ; gcc -lfl *.c -o edupi -lm;
	rm lex.yy.c parser.tab.*;
