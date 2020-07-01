%{
#  include <stdio.h>
#  include <stdlib.h>
#  include "ast.h"
#  include "operations.h"
int yylex();
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
    struct listexp *l;
}

 /* declare tokens */
%token <type> STR INT RL
%token <i> INTEGER
%token <r> REAL
%token <string> STRING
/*function*/
%token <fn>PRINT
%token <fn>PRINTLN
%token TIME
 /* %token <p> PERIPHERAL (ancora non esiste il token)*/
%token <s> NAME
%token <fn> FUNC
%token <i> LST PERI IF ELSE DO WHILE FOR CONTINUE BREAK RETURN DEF 
%token <i> ADDOP SUBOP MULOP DIVOP ABSOP OROP ANDOP NOTOP INCR DECR
%token <i> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN

 /* precedencies and associativities */
%nonassoc <fn> CMP
%left COMMA
%right ASSIGN
%left ANDOP
%left OROP
%left ADDOP SUBOP
%left MULOP DIVOP MODOP
%right NOTOP INCR DECR
%left LPAREN RPAREN LBRACK RBRACK
%nonassoc ABSOP UMINUS /* non so cosa sia UMINUS */

%type <a> statement if_statement for_statement while_statement do_while_statement declaration init tail exp value functionR functionV explist
%type <sl> symlist
%type <type> type
%type <l> value_list
%start program

%%

program: /* nothing */
| program statement { evaluate($2); }
;

statement: if_statement { }
| for_statement { }
| while_statement { }
| do_while_statement { }
| declaration SEMI { }
| init SEMI { }
| exp SEMI { }
| functionV SEMI { }
;

if_statement: IF LPAREN exp RPAREN LBRACE tail RBRACE { $$=newflow('F', $3, $6, NULL, NULL); }
| IF LPAREN exp RPAREN LBRACE tail RBRACE ELSE LBRACE tail RBRACE { $$=newflow('F', $3, $6, $10, NULL); }
;

for_statement: FOR LPAREN init SEMI exp SEMI init RPAREN LBRACE tail RBRACE { $$=newflow('Q', $5, $10, $7, $3); }
;

while_statement: WHILE LPAREN exp RPAREN LBRACE tail RBRACE { $$=newflow('W', $3, $6, NULL, NULL); }
;

do_while_statement: DO LBRACE tail RBRACE WHILE LPAREN exp RPAREN SEMI { $$=newflow('D', $7, $3, NULL, NULL); }
;

tail: { $$ = NULL; }
| statement tail { { if ($2 == NULL)
	                $$ = $1;
                      else
			$$ = newast('Z', $1, $2);
                    } }
;

exp: exp CMP exp { $$ = newast($2 ,$1,$3); }
| exp ADDOP exp { $$ = newast('+',$1,$3); }
| exp SUBOP exp {$$ = newast('-',$1,$3); }
| exp MULOP exp { $$ = newast('*',$1,$3); }
| exp DIVOP exp { $$ = newast('/',$1,$3); }
| exp MODOP exp { $$ = newast('%', $1, $3); }
| exp OROP exp {$$ = newast('O',$1,$3); }
| exp ANDOP exp {$$ = newast('A',$1,$3); }
| NOTOP exp { $$ = newast('N', $2, NULL); }
| ABSOP exp ABSOP { $$ = newast('|', $2, NULL); }
| LPAREN exp RPAREN { $$=$2; }
| SUBOP exp %prec UMINUS { $$ = newast('M',$2,NULL); }
| value 
| functionR
;

declaration: type NAME { $$ = newsymdecl($1, $2);}
| LST NAME { $$ = newsymdecl($1, $2); }
| PERI NAME { $$ = newsymdecl($1, $2); }
;

type: INT 
| STR 
| RL 
;

init: type NAME ASSIGN exp { $$ = newasgn($1, $2, $4); }
| NAME ASSIGN exp { $$ = newsasgn($1, $3); }
| NAME INCR { $$ = newinc('P', $1); }
| NAME DECR { $$ = newinc('E', $1); }
| LST NAME ASSIGN LBRACK value_list RBRACK { $$ = newlasgn($1, $2, $5); }
| NAME ASSIGN LBRACK value_list RBRACK { $$ = newlsasgn($1, $4); }
 /* da aggiungere la periferica */
;

value: NAME { $$ = newref($1); }
| INTEGER { $$ = newInteger('I', $1); }
| REAL { $$ = newReal('R', $1); }
| STRING { $$ = newString('S', $1); }
;

functionV: PRINT LPAREN exp RPAREN { $$ = newfunc($1, $3); }
| PRINTLN LPAREN exp RPAREN { $$ = newfunc($1, $3); }
;

functionR: TIME LPAREN RPAREN { $$ = date(); } 
;

value_list: exp COMMA value_list { $$ = newlist('Y', $1, $3); }
| exp { $$ = newlist('Y', $1, NULL); }
;

explist: explist COMMA exp { }
| exp { }
;

%%
