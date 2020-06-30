%option noyywrap nodefault yylineno
%{
#  include "ast.h"
#  include "parser.tab.h"
#  include "operations.h"
%}

alpha     [a-zA-Z]
digit     [0-9]
alnum     {alpha}|{digit}
print     [^\"]

NAME      {alpha}+{alnum}*
INTEGER   "0"|[1-9]{digit}*
REAL      "0"|{digit}*"."{digit}+
STRING    \"{print}*\"

%%

"list"          { return LST; }
"periferica"    { return PERI; }
"integer"       { yylval.type = 'I'; return INT; }
"real"          { yylval.type = 'R'; return RL; }
"string"        { yylval.type = 'S'; return STR; }
"if"            { return IF; }
"else"          { return ELSE; }
"do"            { return DO; }
"while"         { return WHILE; }
"for"           { return FOR; }
"return"        { return RETURN; }
"def"           { return DEF; }
"print"         { yylval.fn = B_print; return PRINT; }
"println"       { yylval.fn = B_println; return PRINTLN; }
"time"          { return TIME; }

"+"     { return ADDOP; }
"-"     { return SUBOP; }
"*"     { return MULOP; }
"/"     { return DIVOP; }
"%"     { return MODOP; }
"++"    { return INCR; }
"--"    { return DECR; }
"|"     { return ABSOP; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"]"     { return RBRACK; }
"["     { return LBRACK; }
"{"     { return LBRACE; }
"}"     { return RBRACE; }
";"     { return SEMI; }
"."     { return DOT; }
","     { return COMMA; }
"="     { return ASSIGN; }

"OR"|"or"     { return OROP; }
"AND"|"and"   { return ANDOP; }
"NOT"|"not"   { return NOTOP; }

">"     { yylval.fn = 1; return CMP; }
"<"     { yylval.fn = 2; return CMP; }
"!="    { yylval.fn = 3; return CMP; }
"=="    { yylval.fn = 4; return CMP; }
">="    { yylval.fn = 5; return CMP; }
"<="    { yylval.fn = 6; return CMP; }


{NAME}      { yylval.s = lookup(yytext); return NAME; } 
{INTEGER}   { yylval.i = atoi(yytext); return INTEGER;}
{REAL}      { yylval.r = atof(yytext); return REAL; }
{STRING}    { yylval.string = malloc(yyleng * sizeof(char));
                strcpy(yylval.string, yytext); return STRING; }

"//".*
[ \t]   /* ignore white space */
\\\n    { printf("c> "); } /* ignore line continuation */
"\n"    { printf("\n> "); }

.	{ yyerror("Mystery character %c\n", *yytext); exit(1); }
%%
