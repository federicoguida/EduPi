#ifndef __AST_H__
#define __AST_H__
#define PROMPT "$ "

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

extern int yylineno;
void yyerror(char *s, ...);

/* nodi nella struttura AST */
struct ast
{
    int nodetype;
    struct ast *l;
    struct ast *r;
};

struct numval
{
    int nodetype; /* utilizzero K come nodetype per le costanti */
    double number;
};

/**
 * Funzioni per costruire la AST
 */
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);

double eval(struct ast *a);
void treefree(struct ast *a);

#endif