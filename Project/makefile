edupi: lexer.l parser.y ast.c ast.h
	flex lexer.l ; bison -d parser.y ; gcc -lfl *.c -o edupi;
	rm lex.yy.c parser.tab.*;
