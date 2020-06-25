#  define _GNU_SOURCE
#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include <string.h>
#  include <math.h>
#  include <time.h>
#  include "ast.h"
#  include "operations.h"

/********************************WORKING ON VARIABLE********************************/

static unsigned symhash(char *sym) {
  unsigned int hash = 0;
  unsigned c;

  while(c = *sym++) hash = hash*9 ^ c;

  return hash;
}

struct symbol *lookup(char* sym) {
  struct symbol *sp = &symtab[symhash(sym)%NHASH];
  int scount = NHASH;		/* how many have we looked at */
  while(--scount >= 0) {
    if(sp->name && !strcmp(sp->name, sym)) { return sp; }

    if(!sp->name) {		/* new entry */
      sp->name = strdup(sym);
      sp->v = NULL;
      sp->func = NULL;
      sp->syms = NULL;
      return sp;
    }

    if(++sp >= symtab+NHASH) sp = symtab; /* try the next entry */
  }
  yyerror("symbol table overflow\n");
  abort(); /* tried them all, table is full */

}

struct ast *newref(struct symbol *s) {
  struct symref *a = malloc(sizeof(struct symref));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'V';
  a->s = s;
  return (struct ast *)a;
}

struct ast *newasgn(int type, struct symbol *s, struct ast *v)
{
  struct symasgn *a = malloc(sizeof(struct symasgn));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = '=';
  s->nodetype = type;
  a->s = s;
  a->v = v;
  if( s->nodetype != v->nodetype){
    if(s->nodetype == 'R' && ( v->nodetype == 'I' || v->nodetype == 'R') ) 
        return (struct ast *)a;
    yyerror("Invalid operation trying to ass %c to %c", s->nodetype,v->nodetype);
    exit(1);
  } 
  return (struct ast *)a;
}

struct ast *newsasgn(struct symbol *s, struct ast *v) {
  struct symasgn *a = malloc(sizeof(struct symasgn));
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = '=';
  a->s = s;
  a->v = v;
  if( s->nodetype != v->nodetype){
      if(s->nodetype == 'R' && ( v->nodetype == 'I' || v->nodetype == 'R') ) 
        return (struct ast *)a;
    yyerror("Invalid operation trying to ass %c to %c", s->nodetype,v->nodetype);
    exit(1);
  } 
  return (struct ast *)a;
}

struct ast *newsymdecl(int node, struct symbol *s){
  struct symdecl *a=malloc(sizeof(struct symdecl));
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'X' ;
  a->type = node;
  a->s=s;

  return (struct ast *)a;
}

void varType(int type, struct symbol *s){
    s->nodetype=type;
}

/********************************WORKING ON VARIABLE********************************/

/*****************FLOW*/
struct ast *
newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *el)
{
  struct flow *a = malloc(sizeof(struct flow));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->cond = cond;
  a->tl = tl;
  a->el = el;
  return (struct ast *)a;
}
/*****************FLOW*/


/********** BUILT*/
struct ast *
newfunc(int functype, struct ast *l)
{
  struct fncall *a = malloc(sizeof(struct fncall));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'L';
  a->l = l;
  a->functype = functype;
  return (struct ast *)a;
}


struct ast* callbuiltin(struct fncall *f){
    struct ast* a=malloc(sizeof(struct ast));
    enum bifs functype = f->functype;
    a = evaluate(f->l);

    switch(functype) {
      case B_print:
      print(a);
      return a;
      break;
      case B_println:
      println(a);
      return a;
      break;
     default:
    yyerror("Unknown built-in function %d", functype);
  }
}
/***********B*/

struct ast *newInteger(int nodetype, int value) {
  struct value *a = malloc(sizeof(struct value));
  struct integerType *i = malloc(sizeof(struct integerType));

  if(!a || !i) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  i->value=value;
  a->structType = i;
  return (struct ast *)a;
}

struct ast *newReal(int nodetype, double value) {
  struct value *a = malloc(sizeof(struct value));
  struct realType *r = malloc(sizeof(struct realType));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  r->value=value;
  a->structType = r;
  return (struct ast *)a;
}

struct ast *newString(int nodetype, char *value) {
  struct value *a = malloc(sizeof(struct value));
  struct stringType *s = malloc(sizeof(struct stringType));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  s->value=clearString(value);
  a->structType = s;
  return (struct ast *)a;
}

struct ast *newast(int nodetype, struct ast *l, struct ast *r) {
      struct ast *a = malloc(sizeof(struct ast));
      if(!a) {
      yyerror("out of space");
      exit(0);
      }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
  return a;
}

struct ast *evaluate(struct ast *tree) {
    struct ast *result=malloc(sizeof(struct ast));
    struct ast *temp=malloc(sizeof(struct ast));
    struct symasgn *sym;
    struct symbol *s;
    struct value *v;
    struct symdecl *sde;
    switch(tree->nodetype) {
        case '+' :
              result=sum(tree->l, tree->r);
              break;
        case '-' :
              result=sub(tree->l, tree->r);
              break;
        case '*' :
              result=mul(tree->l, tree->r);
              break;
        case '/' :
              result=rdiv(tree->l, tree->r);
              break;
        case '|' :
              result=abss(tree->l);
              break;
        case 'I' :
              result=tree;
              break;
        case 'S' :
              result=tree;
              break;
        case 'R' :
              result=tree;
              break;
        case 'M' :
              result=negateValue(tree->l);
              break;
        case 'O' :
              result=orr(tree->l,tree->r);
              break;
        case 'A' :
              result=and(tree->l,tree->r);
              break;
        case 'N' :
              result=not(tree->l);
              break;
        case '=' :
              sym=malloc(sizeof(struct symasgn));
              sym=(struct symasgn *)tree;
              sym->s->v=(struct value*)evaluate(sym->v);
              break;
        case 'V' :
              s=((struct symref*)tree)->s; result=(struct ast*)s->v;
            break;
        case 'X' :
              sde=(struct symdecl*)tree;
              varType(sde->type,sde->s);
              break;
        case 'F' :
              ifop((struct flow *)tree);
              break;
        case 'L' :
              result=callbuiltin((struct fncall *)tree); 
              break;
        case 'Z': temp=evaluate(tree->l); result=evaluate(tree->r); free(temp); break;
        case 1: result = compare(1,tree->l,tree->r); break; // >
        case 2: result = compare(2,tree->l,tree->r); break; // <
        case 3: result = compare(3,tree->l,tree->r); break; // !=
        case 4: result = compare(4,tree->l,tree->r); break; // ==
        case 5: result = compare(5,tree->l,tree->r); break; // >=
        case 6: result = compare(6,tree->l,tree->r); break; // <=
        default: printf("internal error debug"); 
    }
    return result;
}

void ifop(struct flow *f){
    struct value *v=malloc(sizeof(struct value));
    v=(struct value*)evaluate(f->cond);
    struct integerType *i=malloc(sizeof(struct integerType));
    i=(struct integerType*)v->structType;
    if(i->value!=0){
      evaluate(f->tl);
    }else{
      printf("Non entro IF");
    }
}

void print(struct ast *val) {
    struct value *a= malloc(sizeof(struct value));
    struct integerType *i;
    struct realType *r;
    struct stringType *s;
    switch(val->nodetype){
        case 'I' :  
                    i=malloc(sizeof(struct integerType));
                    a=(struct value *)val;
                    i=(struct integerType *)a->structType;
                    int intero= i->value;
                    printf("%d", intero);
                    break;
        case 'R' :
                    r=malloc(sizeof(struct realType));
                    a=(struct value *)val;
                    r=(struct realType *)a->structType;
                    double reale= r->value;
                    printf("%g", reale);
                    break;
        case 'S' :
                    s=malloc(sizeof(struct stringType));
                    a=(struct value *)val;
                    s=(struct stringType *)a->structType;
                    char * stringa=s->value;
                    printf("%s", stringa);
                    break;   
        default: printf("Error print"); exit(1);
    }
}

void println(struct ast *val) {
  print(val); 
  printf("\n");
}


struct ast *date(){
    struct value *a=malloc(sizeof(struct value));
    struct stringType *s=malloc(sizeof(struct stringType));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    asprintf(&(s->value),"%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    a->nodetype='S';
    a->structType=s;
    return (struct ast*)a;
}

void yyerror(char *s, ...) {
  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

int main() {
  printf("> ");
  return yyparse();
}