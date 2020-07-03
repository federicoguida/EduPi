#  define _GNU_SOURCE
#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include <string.h>
#  include <math.h>
#  include <time.h>
#  include "ast.h"
#  include "operations.h"

/********************************USER-FUNC******************************/
struct symlist *newsymlist(struct symbol *sym, struct symlist *next){
		struct symlist *sl = malloc(sizeof(struct symlist));
		
		if(!sl) {
				yyerror("out of space");
				exit(0);
		}
		sl->sym = sym;
		sl->next = next;
		return sl;
}

void symlistfree(struct symlist *sl){
		struct symlist *nsl;

		while(sl) {
				nsl = sl->next;
				free(sl);
				sl = nsl;
		}
}

void dodef(struct symbol *name, struct symlist *syms, struct ast *func, struct ast *returnValue){
		if(name->syms) symlistfree(name->syms);
		if(name->func) treefree(name->func);
		name->syms = syms;
		name->func = func;
		name->returnValue=returnValue;
}

struct ast *newcall(struct symbol *s, struct ast *l){
		struct ufncall *a = malloc(sizeof(struct ufncall));
		
		if(!a) {
				yyerror("out of space");
				exit(0);
		}
		a->nodetype = 'C';
		a->l = l;
		a->s = s;
		return (struct ast *)a;
}



struct ast* calluser(struct ufncall *f){
		struct symbol *fn = f->s;	/* function name */
		struct symlist *sl;		/* dummy arguments */
		struct ast *args = f->l;	/* actual arguments */
		struct ast **oldval, **newval;	/* saved arg values */
		struct ast *v=NULL;
		int nargs;
		int i;

		 if(!fn->func) {
			yyerror("function do not have body", fn->name);
			exit(1);
		} 

		/* count the arguments */
		sl = fn->syms;
		for(nargs = 0; sl; sl = sl->next)
			nargs++;

		/* prepare to save them */
		oldval = (struct ast **)malloc(nargs * sizeof(struct ast*));
		newval = (struct ast **)malloc(nargs * sizeof(struct ast*));
		if(!oldval || !newval) {
				yyerror("Out of space in %s", fn->name); exit(1);
		}
		
		/* evaluate the arguments */
		for(i = 0; i < nargs; i++) {
				if(!args) {
						yyerror("too few args in call to %s", fn->name);
						free(oldval); free(newval);
						exit(1);
				}

				if(args->nodetype == 'Z') {	/* if this is a list node */
					newval[i] = evaluate(args->l);
					args = args->r;
				} else {			/* if it's the end of the list */
					newval[i] = evaluate(args);
					args = NULL;
				}
		}
					
		//save old values of dummies, assign new ones 
		sl = fn->syms;
		for(i = 0; i < nargs; i++) {
				struct symbol *s = sl->sym;
				s->v = (struct value*)newval[i];
				s->nodetype = s->v->nodetype;
				sl = sl->next;
		}

		/*free(newval); */

		/* evaluate the function */
		evaluate(fn->func);
		if(fn->returnValue){
				v=evaluate(fn->returnValue);
		}
		/*	/* put the dummies back 
		sl = fn->syms;
		for(i = 0; i < nargs; i++) {
				struct symbol *s = sl->sym;
				s->v = (struct value*)oldval[i];
				sl = sl->next;
		}

		free(oldval); */
		
		return v;
}

void treefree(struct ast *a){
		switch(a->nodetype) {
			case 'I': case 'R': case 'S':
			free(((struct value *)a)->structType);
			break;

			case '+': case 1: case 2: case 3: case 4: case 5: case 6:
			treefree(a->l);
			treefree(a->r);
			break;

			case 'F': case 'W' : case 'D': case 'Q':
			free( ((struct flow *)a)->cond);
    	if( ((struct flow *)a)->tl) free( ((struct flow *)a)->tl);
    	if( ((struct flow *)a)->el) free( ((struct flow *)a)->el);
    	break;
		}
		free(a); /* always free the node itself */
}
/********************************END-USER-FUNC******************************/


/********************************VARIABLE********************************/
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

void assign(struct symasgn *tree) {
		
		if(tree->s->nodetype!='Y'){
			struct value* v=(struct value*)(evaluate(tree->v));
				if(tree->s->nodetype!=v->nodetype){
					if(tree->s->nodetype=='R' && v->nodetype=='I'){
							tree->s->v=v;
					}else{
							yyerror("Type %c of variable is not compatible with the type %c of value. ", tree->s->nodetype, v->nodetype );
							exit(1);
					}
				}else{
					tree->s->v=v;
				}
		}else {
				if(!tree->v){
					struct listexp *node=malloc(sizeof(struct listexp));
					node->nodetype='Y';
					node->exp=NULL;
					node->next=NULL;
					tree->s->l=node;
				}else{
					struct listexp *l = malloc(sizeof(struct listexp));
					l = (struct listexp *)(evaluate(tree->v));
					tree->s->l=l;
				}
		}
}
/********************************END-VARIABLE********************************/

/********************************LIST****************************************/

struct listexp *newlist(int nodetype, struct ast *exp, struct listexp *next) {
    struct listexp *l = malloc(sizeof(struct value));

    if(!l) {
		yyerror("out of space");
		exit(0);
    }
    l->nodetype = nodetype;
    l->exp = exp;
    l->next = next;
    return l;
}

void printList(struct listexp *l) {
    struct ast *a;
    struct value *v;
	if(!l->exp){
	}else{
		while(l) {
			a = evaluate(l->exp);
			v = (struct value *)a;
			print((struct ast *)v);
			printf(" ");
			l = l->next;
		}
	}
}

struct ast *newlasgn(int type, struct symbol *s, struct listexp *l) {
    struct symasgn *a = malloc(sizeof(struct symasgn));

    if(!a) {
		yyerror("out of space");
		exit(0);
    }
    a->nodetype = '=';
    s->nodetype = type;
    a->s = s;
    a->v = (struct ast *)l;
    return (struct ast *)a;
}

struct ast *newlsasgn(struct symbol *s, struct listexp *l) {
    struct symasgn *a = malloc(sizeof(struct symasgn));

    if(!a) {
		yyerror("out of space");
		exit(0);
    }
    a->nodetype = '=';
    a->s = s;
    a->v = (struct ast *)l;
    return (struct ast *)a;
}

struct ast *pop(struct symbol *s) {
		if(s->nodetype=='Y'){
				if(s->l->exp != NULL) {
						struct ast* a=malloc(sizeof(struct ast));
						a=s->l->exp;
						free(s->l);
						if(!s->l->next){
							struct listexp *node=malloc(sizeof(struct listexp));
							node->nodetype='Y';
							node->exp=NULL;
							node->next=NULL;
							s->l=node;
							return a;
						}else{
						s->l=s->l->next;
						return a;
						}
				}else{
					struct ast* a=malloc(sizeof(struct ast));
					yyerror("Cannot pop empty list");
					return a;
				}
		}else{
			yyerror("Cannot pop %c TYPE", s->nodetype);
			exit(1);
		}
}

void append(struct symbol *s, struct ast *exp) {
	if(s->nodetype == 'Y') {
		if(exp != NULL) {
			struct listexp *l=s->l;
			while(l) {
				if(l->next==NULL){
					struct listexp *node=malloc(sizeof(struct listexp));
					node->nodetype='Y';
					node->exp=exp;
					node->next=NULL;
					l->next=node;
					break;
				}
				l=l->next;
			}
			if(!l->exp){
				struct listexp *node=malloc(sizeof(struct listexp));
				node->nodetype='Y';
				node->exp=exp;
				node->next=NULL;
				s->l=node;
			}	
		}
	}
	else{
		yyerror("Cannot push %c TYPE", s->nodetype);
		exit(1);
	}
}

int sizeList(struct listexp *l) {
	int size = 0;
	while(l) {
		size++;
		l=l->next;
	}
	return size;
}

struct ast *size(struct symbol *s) {
	if(sizeList(s->l)){
		struct value *v=malloc(sizeof(struct value));
		struct integerType *i=malloc(sizeof(struct integerType));
		if(s->l->exp == NULL) {
			i->value=0;
			v->nodetype='I';
			v->structType=i;
			return (struct ast *)v;
		}else {
			i->value=sizeList(s->l);
			v->nodetype='I';
			v->structType=i;
			return (struct ast *)v;
		}
	}
	yyerror("List null!");
	exit(1);
}

struct ast *delete(struct symbol *s, struct ast *exp) {
	if(s->nodetype == 'Y' && exp->nodetype == 'I') {
		if(exp != NULL) {
			struct listexp *l=s->l;
			int size = sizeList(l);
			struct value *v=(struct value *)exp;
			struct integerType *i=(struct integerType *)v->structType;
			if(i->value > size-1) {
				yyerror("out of bounds!");
				exit(1);
			}
			for(int n = 0; n <= i->value; n++) {
				if(i->value == 0)
					return pop(s);
				if(n == (i->value)-1) {
					struct ast *a=malloc(sizeof(struct ast));
					a=l->next->exp;
					l->next=l->next->next;
					return a;
				}
				l=l->next;
			}
		}
	}
	else{
		yyerror("Cannot delete %c TYPE", s->nodetype);
		exit(1);
	}
}

struct ast *get(struct symbol *s, struct ast *exp) {
	if(s->nodetype == 'Y' && exp->nodetype == 'I') {
		if(exp != NULL) {
			struct listexp *l=s->l;
			int size = sizeList(l);
			struct value *v=(struct value *)exp;
			struct integerType *i=(struct integerType *)v->structType;
			if(i->value > size-1) {
				yyerror("out of bounds!");
				exit(1);
			}
			for(int n = 0; n <= i->value; n++) {
				if(n == i->value) {
					struct ast *a=malloc(sizeof(struct ast));
					a=l->exp;
					return a;
				}
				l=l->next;
			}
		}
	}
	else{
		yyerror("Cannot get %c TYPE", s->nodetype);
		exit(1);
	}
}

void push(struct symbol *s, struct ast *exp) {
	if(s->nodetype == 'Y') {
		if(exp != NULL) {
			if(s->l->exp == NULL) {
				struct listexp *r=malloc(sizeof(struct listexp));
				r->nodetype='Y';
				r->exp=exp;
				r->next=NULL;
				s->l=r;
			}
			else {
				struct listexp *r=malloc(sizeof(struct listexp));
				r->nodetype='Y';
				r->exp=exp;
				r->next=s->l;
				s->l=r;
			}
		}
	}
	else{
		yyerror("Cannot push %c TYPE", s->nodetype);
		exit(1);
	}
}

void insert(struct symbol *s, struct ast *exp, struct ast *val) {
	if(s->nodetype == 'Y' && exp->nodetype == 'I') {
		if(exp != NULL && val != NULL) {
			struct listexp *l=s->l;
			int size = sizeList(l);
			struct value *v=(struct value *)exp;
			struct integerType *i=(struct integerType *)v->structType;
			if(i->value > size) {
				yyerror("out of bounds!");
				exit(1);
			}
			for(int n = 0; n <= i->value; n++) {
				if(i->value == 0) {
					push(s,val);
					break;
				}
				if(n == (i->value)-1) {
					struct listexp *r=malloc(sizeof(struct listexp));
					r->exp=val;
					r->next=l->next;
					l->next=r;
				}
				l=l->next;
			}
		}
	}
	else{
		yyerror("Cannot insert %c TYPE", s->nodetype);
		exit(1);
	}
}

/**********************************END-LIST**********************************/

/*********************************FLOW***************************************/
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
/*********************************END-FLOW*************************************/


/************************************************************************BUILT*/
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

struct ast *newlfunc(int functype, struct symbol *l, struct ast *exp, struct ast *val) {
		struct fncall *a = malloc(sizeof(struct fncall));
		
		if(!a) {
				yyerror("out of space");
				exit(0);
		}
		a->nodetype = 'L';
		a->s = l;
		a->l = exp;
		a->r = val;
		a->functype = functype;
		return (struct ast *)a;	
}

struct ast* callbuiltin(struct fncall *f){
    struct ast* a=malloc(sizeof(struct ast));
    enum bifs functype = f->functype;

    switch(functype) {
				case B_print:
						a = evaluate(f->l);
						if(!a){
							yyerror("no arguments for print...");
							free(a);
							break;
						}
						print(a);
						break;
				case B_println:
						a = evaluate(f->l);
						if(!a){
							yyerror("no arguments for print...");
							free(a);
							break;
						}
						println(a);
						break;
				case B_time:
						a = date();
						break;
				case B_pop:
						if(!f->s){
							yyerror("no arguments for pop...");
							free(a);
							break;
						}
						a=pop(f->s);
						break;
				case B_push:
						if(!f->l) {
							yyerror("no arguments for push...");
							free(a);
							break;
						}
						push(f->s, evaluate(f->l));
						break;
				case B_app:
						if(!f->l){
							yyerror("no arguments for push...");
							free(a);
							break;
						}
						append(f->s, evaluate(f->l));
						break;
				case B_del:
						if(!f->s || !f->l) {
							yyerror("no arguments for delete...");
							free(a);
							break;
						}
						a=delete(f->s, evaluate(f->l));
						break;
				case B_get:
						if(!f->s || !f->l) {
							yyerror("no arguments for get...");
							free(a);
							break;
						}
						a=get(f->s, evaluate(f->l));
						break;
				case B_ins:
						if(!f->l || !f->r) {
							yyerror("no arguments for insert...");
							free(a);
							break;
						}
						insert(f->s, evaluate(f->l), evaluate(f->r));
						break;
				case B_size:
					if(!f->s) {
						yyerror("no arguments for size...");
						free(a);
						break;
					}
					a=size(f->s);
					break;
				default:
						yyerror("Unknown built-in function %d", functype);
 		}
  	return a;
}

void print(struct ast *val) {
    struct value *a= malloc(sizeof(struct value));
    struct integerType *i;
    struct realType *r;
    struct stringType *s;
    struct listexp *l;

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
        case 'Y' :
                    l=malloc(sizeof(struct listexp));
                    l=(struct listexp *)val;
                    printf("[ ");
                    printList(l);
                    printf("]");
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
/*******************************************************************END-BUILT*/



/*****************************INIT*******************************************/
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
/*****************************END-INIT*******************************************/

/****************************EVALUATE*******************************************/
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
        case 'Y' :
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
              if(s->nodetype == 'Y') 
                result=(struct ast *)(s->l);
              else
                result=(struct ast *)(s->v);
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
				case 'C' :
              result=calluser((struct ufncall *)tree);
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
/****************************EVALUATE*******************************************/

void yyerror(char *s, ...) {
  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}