%{
#  include <stdio.h>
#  include <stdlib.h>
#  include "ast.h"
#  include "operations.h"
#  include "rasp.h"
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
    struct funclist *fl; /* Lista di funzioni */
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
%token <fn> PRINT EXIT
%token <fn> PRINTLN
%token <fn> SCAN
%token <fn> TIME SLP TYPE SQRT POW RAND STRMRG STRMUL TOSTRING
%token <fn> POP PUSH APP DEL INS GET SIZE SEARCH
%token <fn> SOP RGB BUTT INIT SINT SREAL SSTR SLINE CLEAR STATUS
%token <s> NAME
%token <i> LST PERI IF ELSE DO WHILE FOR RETURN DEF IN ARR ID 
%token <i> ADDOP SUBOP MULOP DIVOP ABSOP OROP ANDOP NOTOP INCR DECR CNC
%token <i> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA ASSIGN 

/* precedencies and associativities */
%nonassoc <fn> CMP
%left COMMA
%right ASSIGN
%left ANDOP
%left OROP
%left ADDOP SUBOP CNC
%left MULOP DIVOP MODOP
%right NOTOP INCR DECR
%left LPAREN RPAREN LBRACK RBRACK
%nonassoc ABSOP UMINUS 

%type <a> statement if_statement for_statement while_statement do_while_statement declaration init tail exp value functionR functionV explist for_each  
%type <a> pericall
%type <sl> symlist
%type <type> type
%type <l> value_list printlist
%type <fl> functionlist
%start program

%%

program: /* nothing */
| program statement { evaluate($2); treefree($2); }
| program DEF NAME LPAREN symlist RPAREN LBRACE tail RETURN exp SEMI RBRACE { dodef($3, $5, $8,$10); }
| program DEF NAME LPAREN symlist RPAREN LBRACE tail RBRACE { dodef($3, $5, $8,NULL); }
;

statement: if_statement { }
| for_statement { }
| for_each {}
| while_statement { }
| do_while_statement { }
| declaration SEMI { }
| init SEMI { }
| exp SEMI { }
| functionV SEMI { }
| pericall SEMI { }
;

if_statement: IF LPAREN exp RPAREN LBRACE tail RBRACE { $$=newflow('F', $3, $6, NULL, NULL); }
| IF LPAREN exp RPAREN LBRACE tail RBRACE ELSE LBRACE tail RBRACE { $$=newflow('F', $3, $6, $10, NULL); }
;

for_statement: FOR LPAREN init SEMI exp SEMI init RPAREN LBRACE tail RBRACE { $$=newflow('Q', $5, $10, $7, $3); }
;

for_each: FOR NAME IN NAME LBRACE tail RBRACE { $$=newForEach('B', $2, $4, $6);}
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
| NAME LPAREN explist RPAREN { $$ = newcall($1, $3); }
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
| NAME INCR { $$ = newsasgn($1, newast('+', newref($1), newInteger('I', 1))); }
| NAME DECR { $$ = newsasgn($1, newast('-', newref($1), newInteger('I', 1))); }
| LST NAME ASSIGN LBRACK value_list RBRACK { $$ = newlasgn($1, $2, $5); }
| LST NAME ASSIGN exp { $$ = newasgn($1, $2, $4); }
| LST NAME ASSIGN LBRACK  RBRACK { $$ = newlasgn($1, $2, NULL); }
| NAME ASSIGN LBRACK value_list RBRACK { $$ = newlsasgn($1, $4); }
| NAME ASSIGN LBRACK RBRACK { $$ = newlsasgn($1, NULL); }
| PERI NAME ASSIGN LBRACK STRING COMMA functionlist RBRACK {$$ = newperipherical($1, $2, $5, $7);}
;

pericall: NAME ARR ID { $$ = newperipheralcall($1, newString('S', "ID"),NULL, NULL); }
| NAME ARR NAME LPAREN explist RPAREN { $$ = newperipheralcall($1, NULL, $3, $5); }
;

functionlist: functionlist COMMA NAME LPAREN explist RPAREN{ $$=newfunclist(newcall($3, $5),$1);}
| NAME LPAREN explist RPAREN { $$=newfunclist(newcall($1, $3),NULL); }
;

value: NAME { $$ = newref($1); }
| INTEGER { $$ = newInteger('I', $1); }
| REAL { $$ = newReal('R', $1); }
| STRING { $$ = newString('S', $1); }
;

functionV: PRINT LPAREN printlist RPAREN { $$ = newfunc($1, (struct ast*)$3, NULL); }
| PRINTLN LPAREN printlist RPAREN { $$ = newfunc($1, (struct ast*)$3, NULL); }
| NAME DOT APP LPAREN exp RPAREN { $$ = newlfunc($3, $1, $5, NULL); }
| NAME DOT INS LPAREN exp COMMA exp RPAREN { $$ = newlfunc($3, $1, $5, $7); }
| NAME DOT PUSH LPAREN exp RPAREN { $$ = newlfunc($3, $1, $5, NULL); }
| SLP LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| SOP LPAREN exp COMMA exp RPAREN { $$ = newfunc($1, $3, $5); }
| RGB LPAREN exp COMMA exp RPAREN { $$ = newfunc($1, $3, $5); }
| INIT LPAREN RPAREN { $$ = newfunc($1, NULL, NULL); }
| SINT LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| SREAL LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| SSTR LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| SLINE LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| CLEAR LPAREN RPAREN { $$ = newfunc($1, NULL, NULL); }
| STATUS LPAREN RPAREN { $$ = newfunc($1, NULL, NULL); }
| EXIT {$$ = newfunc($1,NULL,NULL); }
;

functionR: TIME LPAREN RPAREN { $$ = newfunc($1, NULL, NULL); } 
| NAME DOT POP LPAREN RPAREN { $$ = newlfunc($3, $1, NULL, NULL); }
| NAME DOT DEL LPAREN exp RPAREN { $$ = newlfunc($3, $1, $5, NULL); }
| NAME DOT GET LPAREN exp RPAREN { $$ = newlfunc($3, $1, $5, NULL); }
| NAME DOT SIZE LPAREN RPAREN { $$ = newlfunc($3, $1, NULL, NULL); }
| NAME DOT SEARCH LPAREN exp RPAREN { $$ = newlfunc($3, $1, $5, NULL); }
| TYPE LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| SQRT LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| POW LPAREN exp COMMA exp RPAREN { $$ = newfunc($1, $3, $5); }
| BUTT LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| SCAN LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL); }
| STRMRG LPAREN value_list RPAREN { $$ = newfunc($1, (struct ast*)$3, NULL); }
| STRMUL LPAREN exp COMMA exp RPAREN {$$ = newfunc($1, $3, $5);}
| TOSTRING LPAREN exp RPAREN { $$ = newfunc($1, $3, NULL);}
| RAND LPAREN exp COMMA exp RPAREN { $$ = newfunc($1, $3, $5); }
| LPAREN INT RPAREN LPAREN exp RPAREN { $$=newfunc($2, $5, NULL); }
;

explist: /*nothing*/ { $$=NULL; }
| exp COMMA explist { $$ = newast('Z', $1, $3); }
| exp 
;

printlist: /*nothing*/ { $$=NULL;}
| exp CNC printlist { $$ = newprintlist($1,$3); }
| exp {$$ = newprintlist($1,NULL);}
;

value_list: exp COMMA value_list { $$ = newlist('Y', $1, $3); }
| exp { $$ = newlist('Y', $1, NULL); }
;

symlist: /*nothing*/ { $$=NULL; } 
| NAME { $$ = newsymlist($1, NULL); }
| NAME COMMA symlist { $$ = newsymlist($1, $3); }
;
%%
