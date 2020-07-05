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

"list"          { yylval.type = 'Y'; return LST; }
"peripheral"    { yylval.type = 'K'; return PERI; }
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
"time"          { yylval.fn = B_time; return TIME; }
"pop"           { yylval.fn = B_pop; return POP; }
"push"          { yylval.fn = B_push; return PUSH; }
"append"        { yylval.fn = B_app; return APP; }
"delete"        { yylval.fn = B_del; return DEL; }
"insert"        { yylval.fn = B_ins; return INS; }
"get"           { yylval.fn = B_get; return GET; }
"size"          { yylval.fn = B_size; return SIZE; }
"search"        { yylval.fn = B_search; return SEARCH; }
"sleep"         { yylval.fn = B_slp; return SLP; }
"type"          { yylval.fn = B_type; return TYPE; }
"sqrt"          { yylval.fn = B_sqrt; return SQRT; }
"pow"           { yylval.fn = B_pow; return POW; }
"in"            { return IN; }
"id"            { return ID; }

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
"->"    { return ARR;}

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
{STRING}    { yylval.string = malloc(yyleng * sizeof(yytext));
                strcpy(yylval.string, yytext); return STRING; }

"//".*
[ \t]   /* ignore white space */
\\\n    { } /* ignore line continuation */
"\n"    { }

.	{ yyerror("Mystery character %c\n", *yytext); exit(1); }
%%

int main(int argc, char **argv) {

  if(argc > 1) {
    if(!(yyin = fopen(argv[1], "r"))) {
      fprintf(stderr, "Not open file: %s\n", argv[1]);
      exit(1);
    }
    return yyparse();
  } else {
    return yyparse();
  }
}