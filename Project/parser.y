/* calculator with AST */

%{
#  include <stdio.h>
#  include <stdlib.h>
#  include "ast.h"
#  include "operations.h"
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
%token <fn>PRINT
%token <fn>PRINTLN
%token TIME
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

%type <a> statement if_statement for_statement while_statement declaration init tail exp value value_list functionR functionV explist
%type <sl> symlist
%type <type> type
%start program

%%

program: /* nothing */
| program statement { evaluate($2); printf("\n> ");}
| program EOL
;

statement: if_statement { }
| for_statement { }
| while_statement { }
| declaration { }
| init { }
| exp SEMI { }
| functionR { }
| functionV { }
;

if_statement: IF LPAREN exp RPAREN LBRACE tail RBRACE  { $$=(newflow('F',evaluate($3),$6,NULL)); }
;

for_statement: FOR LPAREN init SEMI exp SEMI exp RPAREN LBRACE tail RBRACE { }
; /*da rivedere*/

while_statement: WHILE LPAREN exp RPAREN LBRACE tail RBRACE { }
;

tail: { $$ = NULL; }
| statement tail { { if ($2 == NULL)
	                $$ = $1;
                      else
			$$ = newast('Z', $1, $2);
                    } }
;

exp: exp CMP exp { $$ = newast($2 ,evaluate($1),evaluate($3)); }
| exp ADDOP exp { $$ = newast('+',evaluate($1),evaluate($3)); }
| exp SUBOP exp {$$ = newast('-',evaluate($1),evaluate($3)); }
| exp MULOP exp { $$ = newast('*',evaluate($1),evaluate($3)); }
| exp DIVOP exp { $$ = newast('/',evaluate($1),evaluate($3)); }
| exp OROP exp {$$ = newast('O',evaluate($1),evaluate($3)); }
| exp ANDOP exp {$$ = newast('A',evaluate($1),evaluate($3)); }
| NOTOP exp { $$ = newast('N', evaluate($2), NULL); }
| ABSOP exp ABSOP { $$ = newast('|', evaluate($2), NULL); }
| LPAREN exp RPAREN { $$=evaluate($2); }
| SUBOP exp %prec UMINUS { $$ = newast('M',evaluate($2),NULL); }
| value 
;

declaration: type NAME SEMI { $$ = newsymdecl($1, $2);}
| LST NAME SEMI { $$ = newsymdecl($1, $2); }
| PERI NAME SEMI { $$ = newsymdecl($1, $2); }
;

type: INT 
| STR 
| RL 
;

init: type NAME ASSIGN exp SEMI { $$ = newasgn($1, $2, evaluate($4)); }
| NAME ASSIGN exp SEMI { $$ = newsasgn($1, evaluate($3)); }
| LST NAME ASSIGN LBRACK value_list RBRACK SEMI { }
| NAME ASSIGN LBRACK value_list RBRACK SEMI { }
| type NAME ASSIGN functionR { $$ =  newasgn($1, $2, evaluate($4)); }
| NAME ASSIGN functionR { $$ = newsasgn($1, evaluate($3)); }
 /* da aggiungere la periferica */
;

value: NAME { $$ = newref($1); }
| INTEGER { $$ = newInteger('I', $1); }
| REAL { $$= newReal('R', $1); }
| STRING { $$= newString('S', $1); }
;

value_list: value_list COMMA exp { }
| exp { }
;

functionV: PRINT LPAREN exp RPAREN SEMI { $$ = newfunc($1, $3); }
| PRINTLN LPAREN exp RPAREN SEMI { $$ = newfunc($1, $3); }
;

functionR: TIME LPAREN RPAREN SEMI { $$ = date(); } 
;

explist: exp { }
| exp COMMA explist { }
;

%%
