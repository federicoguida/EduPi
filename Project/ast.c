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
      sp->nodetype=-1;
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

struct ast *newasgn(int type, struct symbol *s, struct ast *v) {
  struct symasgn *a = malloc(sizeof(struct symasgn));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = '=';
  s->nodetype = type;
  a->s = s;
  a->v = v;
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

struct ast *newinc(int nodetype, struct symbol *s) { 
  struct symref *a = malloc(sizeof(struct symref));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->s = s;
  return (struct ast *)a;
}

struct ast *incr(struct symbol *s) { 
  struct integerType *i = malloc(sizeof(struct integerType));

  if(s->v->nodetype != 'I') {
    yyerror("Not increment type");
    exit(1);
  }
  i = (struct integerType *)(s->v->structType);
  i->value += 1;
  s->v->nodetype = 'I';
  s->v->structType = i;
  return (struct ast*)(s->v);
}

struct ast *decr(struct symbol *s) { 
  struct integerType *i = malloc(sizeof(struct integerType));

  if(s->v->nodetype != 'I') {
    yyerror("Not increment type");
    exit(1);
  }
  i = (struct integerType *)(s->v->structType);
  i->value -= 1;
  s->v->nodetype = 'I';
  s->v->structType = i;
  return (struct ast*)(s->v);
}

/********************************WORKING ON VARIABLE********************************/

/*****************FLOW*/
struct ast *newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *el, struct ast *in) {
  struct flow *a = malloc(sizeof(struct flow));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->cond = cond;
  a->tl = tl;
  a->el = el;
  a->in = in;
  return (struct ast *)a;
}
/*****************FLOW*/


/********** BUILT*/
struct ast *newfunc(int functype, struct ast *l) {
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
        break;
      case B_println:
        println(a);
        break;
      default:
        yyerror("Unknown built-in function %d", functype);
  }
  return a;
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

void assign(struct symasgn *tree){
	if(tree->s->nodetype!=tree->v->nodetype){
		if(tree->s->nodetype=='R' && tree->v->nodetype=='I'){
			tree->s->v=(struct value*)(evaluate(evaluate((tree)->v)));
		}else{
		yyerror("Type %c of variable is not compatible with the type %c of value. ", tree->s->nodetype, tree->v->nodetype );
		exit(1);
		}

	}
	tree->s->v=(struct value*)(evaluate(evaluate((tree)->v)));
}

struct ast *evaluate(struct ast *tree) {
    struct ast *result=malloc(sizeof(struct ast));
    struct ast *temp=malloc(sizeof(struct ast));
    struct symasgn *sym;
    struct symbol *s;
    struct value *v;
    struct symdecl *sde;
    struct symbol sv;
    switch(tree->nodetype) {
        case '+' :
              result=sum(evaluate(tree->l), evaluate(tree->r));
              break;
        case '-' :
              result=sub(evaluate(tree->l), evaluate(tree->r));
              break;
        case '*' :
              result=mul(evaluate(tree->l), evaluate(tree->r));
              break;
        case '/' :
              result=rdiv(evaluate(tree->l), evaluate(tree->r));
              break;
        case '%' :
              result=mod(evaluate(tree->l), evaluate(tree->r));
              break;
        case '|' :
              result=abss(evaluate(tree->l));
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
              result=negateValue(evaluate(tree->l));
              break;
        case 'O' :
              result=orr(evaluate(tree->l), evaluate(tree->r));
              break;
        case 'A' :
              result=and(evaluate(tree->l), evaluate(tree->r));
              break;
        case 'N' :
              result=not(evaluate(tree->l));
              break;
        case '=' :
              assign((struct symasgn*) tree);
              break;
        case 'V' :
              s=lookup(((struct symref*)tree)->s->name);
              result=(struct ast*)(s->v);
              break;
        case 'P' :
              s=lookup(((struct symref*)tree)->s->name);
              result=incr(s);
              break;
        case 'E' :
              s=lookup(((struct symref*)tree)->s->name);
              result=decr(s);
              break;
        case 'X' :
              ((struct symdecl*)tree)->s->nodetype=((struct symdecl*)tree)->type;
              break;
        case 'F' :
              ifop((struct flow *)tree);
              break;
        case 'W' :
              whileop((struct flow *)tree);
              break;
        case 'D' :
              dowhileop((struct flow *)tree);
              break;
        case 'Q' :
              forop((struct flow *)tree);
              break;
        case 'L' :
              result=callbuiltin((struct fncall *)tree); 
              break;
        case 'Z': temp=evaluate(tree->l); result=evaluate(tree->r);  break;
        case 1: result = compare(1,evaluate(tree->l), evaluate(tree->r)); break; // >
        case 2: result = compare(2,evaluate(tree->l), evaluate(tree->r)); break; // <
        case 3: result = compare(3,evaluate(tree->l), evaluate(tree->r)); break; // !=
        case 4: result = compare(4,evaluate(tree->l), evaluate(tree->r)); break; // ==
        case 5: result = compare(5,evaluate(tree->l), evaluate(tree->r)); break; // >=
        case 6: result = compare(6,evaluate(tree->l), evaluate(tree->r)); break; // <=
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
      if(f->tl) {
      evaluate(f->tl);
    }
    } else {
      if(f->el) {
       evaluate((f->el));
      }
    }
}

void whileop(struct flow *f) {
  struct value *v=malloc(sizeof(struct value));
  v=(struct value*)evaluate(f->cond);
  struct integerType *i=malloc(sizeof(struct integerType));
  i=(struct integerType*)v->structType;
  if(f->tl) { 
    while(i->value != 0){
      evaluate(f->tl);
      v=(struct value*)evaluate(f->cond);
      i=(struct integerType*)v->structType;
    } 
  }
}

void dowhileop(struct flow *f) {
  struct value *v=malloc(sizeof(struct value));
  struct integerType *i=malloc(sizeof(struct integerType));
  if(f->tl) { 
    do{
      evaluate(f->tl);
      v=(struct value*)evaluate(f->cond);
      i=(struct integerType*)v->structType;
    }while(i->value != 0); 
  }
}

void forop(struct flow *f) { 
    evaluate(f->in);
    struct value *v=malloc(sizeof(struct value));
    v=(struct value*)evaluate(f->cond);
    struct integerType *i=malloc(sizeof(struct integerType));
    i=(struct integerType*)v->structType;
    if(f->tl && f->in && f->el) {
        while(i->value) {
          evaluate(f->tl);
          evaluate(f->el);
          v=(struct value*)evaluate(f->cond);
          i=(struct integerType*)v->structType;
        }
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