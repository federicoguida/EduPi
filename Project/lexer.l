%option noyywrap nodefault yylineno
%{
# include "ast.h"
# include "parser.tab.h"
%}

alpha     [a-zA-Z]
digit     [0-9]
alnum     {alpha}|{digit}
print     [ -~]

NAME        {alpha}+{alnum}*
INTEGER     "0"|[1-9]{digit}*
REAL        "0"|{digit}*"."{digit}+
STRING      \"{print}*\"

%%

"list"          { return LST; }
"periferica"    { return PERI; }
"string"        { return STR; }
"integer"       { return INT; }
"real"          { return RL; }
"if"            { return IF; }
"else"          { return ELSE; }
"do"            { return DO; }
"while"         { return WHILE; }
"for"           { return FOR; }
"continue"      { return CONTINUE; }
"break"         { return BREAK; }
"return"        { return RETURN; }
"def"           { return DEF; }

"+"     { return ADDOP; }
"-"     { return SUBOP; }
"*"     { return MULOP; }
"/"     { return DIVOP; }
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

"OR"    { return OROP; }
"AND"   { return ANDOP; }
"NOT"   { return NOTOP; }

">"     { yylval.fn = 1; return CMP; }
"<"     { yylval.fn = 2; return CMP; }
"!="    { yylval.fn = 3; return CMP; }
"=="    { yylval.fn = 4; return CMP; }
">="    { yylval.fn = 5; return CMP; }
"<="    { yylval.fn = 6; return CMP; }

 /* built in functions */
"sqrt"  { yylval.fn = B_sqrt; return FUNC; }
"exp"   { yylval.fn = B_exp; return FUNC; }
"log"   { yylval.fn = B_log; return FUNC; }
"print" { yylval.fn = B_print; return FUNC; }

 /* debug hack */
"debug"[0-9]+ { debug = atoi(&yytext[5]); printf("debug set to %d\n", debug); }

{NAME}      { yylval.s = lookup(yytext); return NAME; }
{INTEGER}   { yylval.i = atoi(yytext); return INTEGER;}
{REAL}      { yylval.r = atof(yytext); return REAL; }
{STRING}    { yylval.string = malloc(yyleng * sizeof(char));
                strcpy(yylval.string, yytext); return STRING; }

"//".*
[ \t]   /* ignore white space */
\\\n    printf("c> "); /* ignore line continuation */
"\n"    { return EOL; }

.	{ yyerror("Mystery character %c\n", *yytext); }
%%
