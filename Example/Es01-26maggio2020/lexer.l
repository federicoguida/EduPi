%option noyywrap nodefault yylineno

%{
    #include "ast.h"
    #include "parser.tab.h"
%}

/* Espressione regolare per riconoscere la notazione esponenziale */
EXP ([Ee][-+]?[0-9]+)

%%
"+" |
"-" |
"*" |
"/" |
"|" |
"(" |
")"     { return yytext[0]; }
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylval.d = atof(yytext); return NUMBER; }

\n      { return EOL; }
"//".*  
[ \t]   { /* ignore white space */ }
.	{ yyerror(" %c non e' un carattere riconosciuto.\n", *yytext); }
%%