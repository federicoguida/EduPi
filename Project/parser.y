/* calculator with AST */

%{
#  include <stdio.h>
#  include <stdlib.h>
#  include "ast.h"
%}

%union{
    struct ast *a; /*Struttura albero*/
    double r; /*Indicherà i reali*/
    int i; /*Indicherà gli interi*/
    char *string; /*Indicherà le stringhe*/
    struct peripheral *p; /*Indicherà la periferica*/
    struct symbol *s; /* Indicherà il simbolo */
    struct symlist *sl;  /* Lista di simboli */
    int fn; /* Indicherà quale funzione */
}

/* declare tokens */
%token <i> INTEGER
%token <r> REAL
%token <string> STRING
%token PRINT
/* %token <p> PERIPHERAL (ancora non esiste il token)*/
%token <s> NAME
%token <fn> FUNC
%token EOL
%token <i> LST PERI STR INT RL IF ELSE DO WHILE FOR CONTINUE BREAK RETURN DEF
%token <i> ADDOP SUBOP MULOP DIVOP ABSOP OROP ANDOP NOTOP
%token <i> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN
/* precedencies and associativities */
%nonassoc <fn> CMP
%left LPAREN RPAREN LBRACK RBRACK
%right NOTOP
%left MULOP DIVOP
%left ADDOP SUBOP
%left OROP
%left ANDOP
%right ASSIGN
%left COMMA
%nonassoc ABSOP UMINUS /* non so cosa sia UMINUS */

%type <a> exp statement tail explist value
%type <sl> symlist

%start program

%%

program: /* nothing */
| program statement EOL { }
;

statement: if_statement { }
| for_statement { }
| while_statement { }
| do_while_statement { }
| declarations { }
| inits { }
| functionB { }
;

if_statement: IF LPAREN exp RPAREN LBRACE tail RBRACE else_if optional_else { }
| IF LPAREN exp RPAREN LBRACE tail RBRACE optional_else { }
;

else_if: else_if ELSE IF LPAREN exp RPAREN LBRACE tail RBRACE { }
| ELSE IF LPAREN exp RPAREN LBRACE tail RBRACE { }
;

optional_else: /* empty */
| ELSE LBRACE tail RBRACE { }
;

for_statement: FOR LPAREN exp SEMI exp SEMI exp RPAREN LBRACE tail RBRACE { }
; /*da rivedere*/

while_statement: WHILE LPAREN exp RPAREN LBRACE tail RBRACE { }
;

do_while_statement: DO LBRACE tail RBRACE WHILE LPAREN exp RPAREN LBRACE tail RBRACE { }
;

tail: /* nothing */
| statement SEMI tail { }
;

exp: exp CMP exp { }
| exp ADDOP exp { }
| exp SUBOP exp { }
| exp MULOP exp { }
| exp DIVOP exp { }
| ABSOP exp { }
| LPAREN exp LPAREN { }
| SUBOP exp %prec UMINUS { }
/* da finire */
;

declarations: declarations declaration { }
| declaration { }
;

declaration: type NAME SEMI { }
| LST NAME SEMI { }
;

type: INT { }
| STR { }
| PERI { }
| RL { }
;

inits: inits init { }
| init { }
;

init: type NAME ASSIGN value SEMI { }
| NAME ASSIGN value SEMI { }
| LST NAME ASSIGN value_list SEMI { }
| NAME ASSIGN value_list SEMI { }
/* da aggiungere la periferica */
;

functionB: PRINT LPAREN  value  RPAREN
 { print($3);} 

value: NAME { }
| INTEGER { $$ = newInteger('I', $1); }
| REAL { $$= newReal('R', $1);}
| STRING { $$= newString('S', $1); }
| exp { }
;

value_list: value_list COMMA value { }
| value { }
;

explist: exp { }
| exp COMMA explist { }
;


%%
