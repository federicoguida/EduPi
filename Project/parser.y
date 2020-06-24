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
    int type;
}

 /* declare tokens */
%token <type> STR INT RL
%token <i> INTEGER
%token <r> REAL
%token <string> STRING
/*function*/
%token PRINT
%token PRINTLN
 /* %token <p> PERIPHERAL (ancora non esiste il token)*/
%token <s> NAME
%token <fn> FUNC
%token EOL
%token <i> LST PERI IF ELSE DO WHILE FOR CONTINUE BREAK RETURN DEF 
%token <i> ADDOP SUBOP MULOP DIVOP ABSOP OROP ANDOP NOTOP
%token <i> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN

 /* precedencies and associativities */
%nonassoc <fn> CMP
%left COMMA
%right ASSIGN
%left ANDOP
%left OROP
%left ADDOP SUBOP
%left MULOP DIVOP
%right NOTOP
%left LPAREN RPAREN LBRACK RBRACK
%nonassoc ABSOP UMINUS /* non so cosa sia UMINUS */

%type <a> statement if_statement for_statement while_statement do_while_statement declarations declaration inits init exp tail else_if optional_else type value value_list functionB explist
%type <sl> symlist

%start program

%%

program: /* nothing */
| program statement EOL { yyerrok; printf("\n> ");}
;

statement: if_statement { }
| for_statement { }
| while_statement { }
| do_while_statement { }
| declarations { }
| inits { }
| functions { }
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

for_statement: FOR LPAREN init SEMI exp SEMI exp RPAREN LBRACE tail RBRACE { }
; /*da rivedere*/

while_statement: WHILE LPAREN exp RPAREN LBRACE tail RBRACE { }
;

do_while_statement: DO LBRACE tail RBRACE WHILE LPAREN exp RPAREN LBRACE tail RBRACE { }
;

tail: /* nothing */
| statement { }
; 

exp: exp CMP exp { $$ = newast($2 ,evaluate($1),evaluate($3)); }
| exp ADDOP exp { $$ = newast('+',evaluate($1),evaluate($3)); }
| exp SUBOP exp {$$ = newast('-',evaluate($1),evaluate($3)); }
| exp MULOP exp { $$ = newast('*',evaluate($1),evaluate($3)); }
| exp DIVOP exp { $$ = newast('/',evaluate($1),evaluate($3)); }
| exp OROP exp {$$ = newast('O',evaluate($1),evaluate($3)); }
| exp ANDOP exp {$$ = newast('A',evaluate($1),evaluate($3)); }
| NOTOP exp { }
| ABSOP exp { }
| LPAREN exp LPAREN { }
| SUBOP exp %prec UMINUS { $$ = newast('M',evaluate($2),NULL); }
| value 
;

declarations: declarations declaration { }
| declaration { }
;

declaration: type NAME SEMI { }
| LST NAME SEMI { }
| PERI NAME SEMI { }
;

type: INT { }
| STR { }
| RL { }
;

inits: inits init { }
| init { }
;

init: type NAME ASSIGN exp SEMI { evaluate(newasgn($1, $2,$4)); }
| NAME ASSIGN exp SEMI { }
| LST NAME ASSIGN LBRACK value_list RBRACK SEMI { }
| NAME ASSIGN LBRACK value_list RBRACK SEMI { }
 /* da aggiungere la periferica */
;

value: NAME { $$=evaluate(newref($1)); }
| INTEGER { $$ = newInteger('I', $1); }
| REAL { $$= newReal('R', $1); }
| STRING { $$= newString('S', $1); }
;

value_list: value_list COMMA exp { }
| exp { }
;

functions: functions functionB 
| functionB ;

functionB: PRINT LPAREN exp RPAREN SEMI { print(evaluate($3));  }
| PRINTLN LPAREN exp RPAREN SEMI { println(evaluate($3));  }
;

explist: exp { }
| exp COMMA explist { }
;

%%

