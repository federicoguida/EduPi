#  define _GNU_SOURCE
#  include <stdio.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include <stdarg.h>
#  include <string.h>
#  include <math.h>
#  include <time.h>
#  include "ast.h"
#  include "operations.h"
#  include "rasp.h"

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
		struct ast  **val;	/* saved arg values */
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
		val = malloc(nargs * sizeof(struct ast*));
		if(!val) {
			yyerror("Out of space in %s", fn->name); exit(1);
		}
		
		/* evaluate the arguments */
		for(i = 0; i < nargs; i++) {
			if(!args) {
				yyerror("too few args in call to %s", fn->name);
				free(val);
				exit(1);
			}

			if(args->nodetype == 'Z') {	/* if this is a list node */
				val[i] = evaluate(args->l);
				args = args->r;
			} else {			/* if it's the end of the list */
				val[i] = evaluate(args);
				args = NULL;
			}
		}
					
		sl = fn->syms;
		for(i = 0; i < nargs; i++) {
			struct symbol *s = sl->sym;
			if(val[i]->nodetype=='Y'){
				s->l = (struct listexp*)val[i];
				s->nodetype = s->l->nodetype;
			}else{
				s->v = (struct value*)val[i];
				s->nodetype = s->v->nodetype;
			}
			sl = sl->next;
		}

		evaluate(fn->func);
		if(fn->returnValue){
				v=evaluate(fn->returnValue);
		}

		sl = fn->syms;
		for(i = 0; i < nargs; i++) {
			struct symbol *s = sl->sym;
			s->nodetype=-1;
			s->v = NULL;
			s->func = NULL;
			s->syms = NULL;
			sl=sl->next;
		}
		
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

			case '=':
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

void assign(struct symasgn *tree) {
		
		if(tree->s->nodetype!='Y'){
			struct value* v=(struct value*)(evaluate(tree->v));
				if(tree->s->nodetype!=v->nodetype){
					if(tree->s->nodetype=='R' && v->nodetype=='I'){
							tree->s->v=v;
							struct realType *r=malloc(sizeof(struct realType));
							struct value *val=malloc(sizeof(struct value));
							double value=(double)(((struct integerType*)(v->structType))->value);
							r->value=value;
							val->nodetype='R';
							val->structType=r;
							tree->s->v=val;

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
					struct listexp *l = (struct listexp *)(evaluate(tree->v));
					tree->s->l=l;
				}
		}
}
/********************************END-VARIABLE********************************/

/********************************LIST****************************************/

struct listexp *newlist(int nodetype, struct ast *exp, struct listexp *next) {
    struct listexp *l = malloc(sizeof(struct listexp));

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
	if(!s){
		//yyerror("Function pop: null pointer");
		return NULL;
	}else{
		if(s->nodetype=='Y'){
			if(s->l->exp != NULL) {
				struct ast* a=s->l->exp;
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
				yyerror("Cannot pop empty list");
				return NULL;
			}
		}else{
			yyerror("Cannot pop %c TYPE", s->nodetype);
			return NULL;
		}
	}
}

void append(struct symbol *s, struct ast *exp) {
	if(!s){
		//yyerror("Function append: null pointer");
	}else{
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
			else {
				yyerror("argument not defined");
			}
		}
		else{
			yyerror("Cannot push %c TYPE", s->nodetype);
		}
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
	if(!s){
		//yyerror("Function size: null pointer");
		return NULL;
	}else{
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
	}
}

struct ast *delete(struct symbol *s, struct ast *exp) {
	if(!s || !exp){
		//yyerror("Function delete: null pointer");
		return NULL;
	}else{
		if(s->nodetype == 'Y' && exp->nodetype == 'I') {
			if(exp != NULL) {
				struct listexp *l=s->l;
				int size = sizeList(l);
				struct value *v=(struct value *)exp;
				struct integerType *i=(struct integerType *)v->structType;
				if(i->value > size-1) {
					yyerror("out of bounds!");
				}
				for(int n = 0; n <= i->value; n++) {
					if(i->value == 0)
						return pop(s);
					if(n == (i->value)-1) {
						struct ast *a=l->next->exp;
						l->next=l->next->next;
						return a;
					}
					l=l->next;
				}
			}
			else {
				yyerror("arguments not defined");
				return NULL;
			}
		}
		else{
			yyerror("Cannot delete %c TYPE", s->nodetype);
			return NULL;
		}
	}
}

struct ast *get(struct symbol *s, struct ast *exp) {
	if(!s || !exp){
		//yyerror("Function get: null pointer");
		return NULL;
	}else{
		if(s->nodetype == 'Y' && exp->nodetype == 'I') {
			if(exp != NULL) {
				struct listexp *l=s->l;
				int size = sizeList(l);
				struct value *v=(struct value *)exp;
				struct integerType *i=(struct integerType *)v->structType;
				if(i->value > size-1) {
					yyerror("out of bounds!");
				}
				for(int n = 0; n <= i->value; n++) {
					if(n == i->value) {
						struct ast *a=l->exp;
						return a;
					}
					l=l->next;
				}
			}
			else {
				yyerror("argument not defined");
				return NULL;
			}
		}
		else{
			yyerror("Cannot get %c TYPE", s->nodetype);
			return NULL;
		}
	}
}

void push(struct symbol *s, struct ast *exp) {
	if(!s || !exp){
		//yyerror("Function push: null pointer");
	}else{
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
			else {
				yyerror("argument not defined");
			}
		}
		else{
			yyerror("Cannot push %c TYPE", s->nodetype);
		}
	}
}

void insert(struct symbol *s, struct ast *exp, struct ast *val) {
	if(!s || !exp){
		//yyerror("Function insert: null pointer");
	}else{
		if(s->nodetype == 'Y' && exp->nodetype == 'I') {
			if(exp != NULL && val != NULL) {
				struct listexp *l=s->l;
				int size = sizeList(l);
				struct value *v=(struct value *)exp;
				struct integerType *i=(struct integerType *)v->structType;
				if(i->value > size) {
					yyerror("out of bounds!");
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
			else {
				yyerror("arguments not defined");
			}
		}
		else{
			yyerror("Cannot insert %c TYPE", s->nodetype);
		}
	}
}

struct ast *search(struct symbol *s, struct ast *exp) {
	if(!s || !exp){
		//yyerror("Function search: null pointer");
		return NULL;
	}else{
		if(s->nodetype == 'Y') {
			if(exp != NULL) {
				struct listexp *l=s->l;
				int count = 0;
				struct value *val1=(struct value *)l->exp;
				struct value *val2=(struct value *)exp;
				struct value *res;
				struct integerType *inres;
				struct integerType *int1;
				struct integerType *int2;
				struct realType *real1;
				struct realType *real2;
				struct stringType *str1;
				struct stringType *str2;
				while(l) {
					switch(val1->nodetype) {
						case 'I':
							if(val1->nodetype == val2->nodetype) {
								int1=(struct integerType *)val1->structType;
								int2=(struct integerType *)val2->structType;
								if(int1->value == int2->value) {
									inres=malloc(sizeof(struct integerType));
									res=malloc(sizeof(struct value));
									inres->value=count;
									res->nodetype='I';
									res->structType=inres;
									return (struct ast *)res;
								}
							}
							break;
						case 'R':
							if(val1->nodetype == val2->nodetype) {
								real1=(struct realType *)val1->structType;
								real2=(struct realType *)val2->structType;
								if(real1->value == real2->value) {
									inres=malloc(sizeof(struct integerType));
									res=malloc(sizeof(struct value));
									inres->value=count;
									res->nodetype='I';
									res->structType=inres;
									return (struct ast *)res;
								}
							}
							break;
						case 'S':
							if(val1->nodetype == val2->nodetype) {
								str1=(struct stringType *)val1->structType;
								str2=(struct stringType *)val2->structType;
								if(strcmp(str1->value, str2->value) == 0) {
									inres=malloc(sizeof(struct integerType));
									res=malloc(sizeof(struct value));
									inres->value=count;
									res->nodetype='I';
									res->structType=inres;
									return (struct ast *)res;
								}
							}
							break;
						case 'Y':
							yyerror("Cannot search list!");
							break;
						default:
							yyerror("search error type!");
							exit(1);
					}
					count++;
					l=l->next;
					if(l)
						val1=(struct value *)l->exp;
				}
				return NULL;
			}
			yyerror("Value NULL!");
			return NULL;
		}
		else{
			yyerror("Cannot search %c TYPE", s->nodetype);
			return NULL;
		}
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
    struct value *v=(struct value*)evaluate(f->cond);
    struct integerType *i=(struct integerType*)v->structType;
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
		struct value *v=(struct value*)evaluate(f->cond);
		struct integerType *i=(struct integerType*)v->structType;
		if(f->tl) { 
				while(i->value != 0){
						evaluate(f->tl);
						v=(struct value*)evaluate(f->cond);
						i=(struct integerType*)v->structType;
				} 
		}
}

void dowhileop(struct flow *f) {
		struct value *v;
		struct integerType *i;
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
    struct value *v=(struct value*)evaluate(f->cond);
    struct integerType *i=(struct integerType*)v->structType;
    if(f->tl && f->in && f->el) {
        while(i->value) {
						evaluate(f->tl);
						evaluate(f->el);
						v=(struct value*)evaluate(f->cond);
						i=(struct integerType*)v->structType;
        }
    }
}

struct ast *newForEach(int nodetype, struct symbol* i, struct symbol* list, struct ast* body){
	struct for_each *f=malloc(sizeof(struct for_each));
	f->nodetype='B';
	f->i=i;
	f->list=list;
	f->body=body;
	return (struct ast*)f;
}

void foreach(struct for_each *f){
	if(f->list->nodetype!='Y'){
		yyerror("Second operator must be list");
	}else{
		if(f->list->l->exp){
			struct listexp* l=(struct listexp*)f->list->l;
			while(l){
				if(l->exp->nodetype=='Y'){
					f->i->nodetype='Y';
					f->i->l=(struct listexp*)evaluate(l->exp);
				}else{
					f->i->nodetype='V';
					f->i->v=(struct value*)l->exp;
				}
				evaluate(f->body);
				l=l->next;
			}
		}else{
			yyerror("List dont have elements");
		}
	}
}

/*********************************END-FLOW*************************************/


/************************************************************************BUILT*/
struct ast *newfunc(int functype, struct ast *l, struct ast *r, struct ast *c) {
		struct fncall *a = malloc(sizeof(struct fncall));
		
		if(!a) {
				yyerror("out of space");
				exit(0);
		}
		a->nodetype = 'L';
		a->l = l;
		a->r = r;
		a->c = c;
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
    struct ast* a;
    enum bifs functype = f->functype;

    switch(functype) {
				case B_print:
					if(!f->l){
						yyerror("no arguments for print...");
						free(a);
						break;
					}
					print(evaluate(f->l));
					break;
				case B_println:
					if(!f->l){
						yyerror("no arguments for print...");
						free(a);
						break;
					}
					println(evaluate(f->l));
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
				case B_search:
					if(!f->s || !f->l) {
						yyerror("no arguments for search...");
						free(a);
						break;
					}
					a=search(f->s, evaluate(f->l));
					break;
				case B_size:
					if(!f->s) {
						yyerror("no arguments for size...");
						free(a);
						break;
					}
					a=size(f->s);
					break;
				case B_slp:
					if(!f->l){
						yyerror("no arguments for sleep...");
						free(a);
						break;
					}
					bsleep(evaluate(f->l));
					break;
				case B_type:
					if(!f->l) {
						yyerror("no arguments for type...");
						free(a);
						break;
					}
					a=type(evaluate(f->l));
					break;
				case B_sqrt:
					if(!f->l) {
						yyerror("no arguments for sqrt...");
						free(a);
						break;
					}
					a=ssqrt(evaluate(f->l));
					break;
				case B_pow:
					if(!f->l || !f->r) {
						yyerror("no arguments for pow...");
						free(a);
						break;
					}
					a=ppow(evaluate(f->l), evaluate(f->r));
					break;
				case B_led:
					if(!f->l || !f->r) {
						yyerror("no arguments for led...");
						free(a);
						break;
					}
					led(evaluate(f->l), evaluate(f->r), evaluate(f->c));
					break;
				case B_butt:
					if(!f->l) {
						yyerror("no arguments for button...");
						free(a);
						break;
					}
					a=button(evaluate(f->l));
					break;
				default:
					yyerror("Unknown built-in function %d", functype);
 		}
  	return a;
}

void print(struct ast *val) {
	if(!val)
	yyerror("Cannot print null element");
	else{
		struct value *a;
		struct integerType *i;
		struct realType *r;
		struct stringType *s;
		struct listexp *l;
		struct peripherical *p;
		struct funclist *f;
		struct ast *printlist;

		switch(val->nodetype){
			case 'I' :  
						a=(struct value *)val;
						i=(struct integerType *)a->structType;
						int intero= i->value;
						printf("%d", intero);
						break;
			case 'R' :
						a=(struct value *)val;
						r=(struct realType *)a->structType;
						double reale= r->value;
						printf("%g", reale);
						break;
			case 'S' :
						a=(struct value *)val;
						s=(struct stringType *)a->structType;
						char * stringa=s->value;
						printf("%s", stringa);
						break;   
			case 'Y' :
						l=(struct listexp *)val;
						printf("[ ");
						printList(l);
						printf("]");
						break;
			case 'K' :
						p=(struct peripherical*)val;
						printf("Peripheral ID: %s\n",p->name);
						f=p->f;
						while(f){
							printf("Method --> %s\n", f->bcall->s->name);
							f=f->next;
						}
						break;
			case 'Z' :
						printlist=val;
						while(printlist){
							if(printlist->l){
								print(printlist->l);
							}
							printlist=printlist->r;
						}
						break;

			default: printf("Error print"); exit(1);
		}
	}
}

void println(struct ast *val) {
		if(!val)
			yyerror("Cannot print null element");
		else{
		print(val); 
		printf("\n");
		}
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
void bsleep(struct ast *val) {
	struct value *a;
	struct integerType *i;
	if(val->nodetype=='I'){
        a=(struct value *)val;
        i=(struct integerType *)a->structType;
        int intero= i->value;
        fflush(stdout);
        usleep(intero*1000);
  	}else{
		yyerror("Integer type expected on sleep function");
  	}
}

struct ast *type(struct ast *val) {
	if(val != NULL) {
		struct value *res;
		struct stringType *str;
		switch(val->nodetype) {
			case 'I':
				res=malloc(sizeof(struct value));
				str=malloc(sizeof(struct stringType));
				str->value = "integer";
				res->nodetype = 'S';
				res->structType = str;
				return (struct ast *)res;
			case 'R':
				res=malloc(sizeof(struct value));
				str=malloc(sizeof(struct stringType));
				str->value = "real";
				res->nodetype = 'S';
				res->structType = str;
				return (struct ast *)res;
			case 'S':
				res=malloc(sizeof(struct value));
				str=malloc(sizeof(struct stringType));
				str->value = "string";
				res->nodetype = 'S';
				res->structType = str;
				return (struct ast *)res;
			case 'Y':
				res=malloc(sizeof(struct value));
				str=malloc(sizeof(struct stringType));
				str->value = "list";
				res->nodetype = 'S';
				res->structType = str;
				return (struct ast *)res;
			case 'K':
				res=malloc(sizeof(struct value));
				str=malloc(sizeof(struct stringType));
				str->value = "peripheral";
				res->nodetype = 'S';
				res->structType = str;
				return (struct ast *)res;
			default:
				yyerror("error type!");
				exit(1);
		}
	}
	else {
		yyerror("argument not defined");
		return NULL;
	}
}

struct ast *ssqrt(struct ast *val) {
	if(val != NULL) {
		struct value *v=(struct value *)val;
		if(v->nodetype == 'I') {
			struct value *res=malloc(sizeof(struct value));
			struct realType *r=malloc(sizeof(struct realType));
			struct integerType *intValue=(struct integerType *)v->structType;
			r->value=sqrt(intValue->value);
			res->nodetype='R';
			res->structType=r;
			return (struct ast *)res;
		}
		else if(v->nodetype == 'R') {
			struct value *res=malloc(sizeof(struct value));
			struct realType *r=malloc(sizeof(struct realType));
			struct realType *realValue=(struct realType *)v->structType;
			r->value=sqrt(realValue->value);
			res->nodetype='R';
			res->structType=r;
			return (struct ast *)res;
		}
		else {
			yyerror("Incompatible type!");
			return NULL;
		}
	}
	else {
		yyerror("argument not defined");
		return NULL;
	}
}

struct ast *ppow(struct ast *val1, struct ast *val2) {
	if((val1 != NULL) && (val2 != NULL)) {
		struct value *v1=(struct value *)val1;
		struct value *v2=(struct value *)val2;
		if(v1->nodetype == 'I') {
			if(v2->nodetype == 'I') {
				struct value *res=malloc(sizeof(struct value));
				struct realType *r=malloc(sizeof(struct realType));
				struct integerType *intValue1=(struct integerType *)v1->structType;
				struct integerType *intValue2=(struct integerType *)v2->structType;
				r->value=pow(intValue1->value, intValue2->value);
				res->nodetype='R';
				res->structType=r;
				return (struct ast *)res;
			}
			else if(v2->nodetype == 'R') {
				struct value *res=malloc(sizeof(struct value));
				struct realType *r=malloc(sizeof(struct realType));
				struct integerType *intValue1=(struct integerType *)v1->structType;
				struct realType *realValue2=(struct realType *)v2->structType;
				r->value=pow(intValue1->value, realValue2->value);
				res->nodetype='R';
				res->structType=r;
				return (struct ast *)res;
			}
			else {
				yyerror("Incompatible type!");
				return NULL;
			}
		}
		else if(v1->nodetype == 'R') {
			if(v2->nodetype == 'I') {
				struct value *res=malloc(sizeof(struct value));
				struct realType *r=malloc(sizeof(struct realType));
				struct realType *realValue1=(struct realType *)v1->structType;
				struct integerType *intValue2=(struct integerType *)v2->structType;
				r->value=pow(realValue1->value, intValue2->value);
				res->nodetype='R';
				res->structType=r;
				return (struct ast *)res;
			}
			else if(v2->nodetype == 'R') {
				struct value *res=malloc(sizeof(struct value));
				struct realType *r=malloc(sizeof(struct realType));
				struct realType *realValue1=(struct realType *)v1->structType;
				struct realType *realValue2=(struct realType *)v2->structType;
				r->value=pow(realValue1->value, realValue2->value);
				res->nodetype='R';
				res->structType=r;
				return (struct ast *)res;
			}
			else {
				yyerror("Incompatible type!");
				return NULL;
			}
		}
		else {
			yyerror("Incompatible type!");
			return NULL;
		}
	}
	else {
		yyerror("argument not defined");
		return NULL;
	}
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
      exit(1);
      }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
  return a;
}
/*****************************END-INIT*******************************************/

/*****************NODETYPE TABLE********************
+	SUM
-	SUB
*	MUL
/	DIV
%	MOD
|	ABS
I	INTEGER
S	STRING
R	REAL
Y	LIST
K	PERIPHERICAL
B	FOREACH
M	NEGATE VALUE
O	OR
A	AND
N	NOT
=	ASSIGN OPERATION
V	REF OF VARIABLE USED FOR CONTENT OF VARIABLE
X	DECLARATION OF SYMBOL
F	IF ELSE..
W	WHILE
D	DO WHILE
Q	FOR 
L 	CALL BUILTIN
C	CALL USER
Z 	TREE OF STATEMENTS
1	>
2	<
3	!=
4	==
5	>=
6	<=
/*****************NODETYPE TABLE********************/



/**************PERI WORK IN PROGRESS**********************/
struct ast* newperipherical(int nodetype, struct symbol *var, char *name, struct funclist *fl ){
	struct periassign* p=malloc(sizeof(struct periassign));
	
	if(!var || !name || !fl){
		//yyerror("no arguments for declaration of peripheral");
		return NULL;
	}

	p->nodetype='_';
	p->type=nodetype;
	p->var=var;
	p->name=name;
	p->fl=fl;
	return (struct ast*)p;
}

void assignPeri(struct periassign* p){

	if(!p){
		//yyerror("no arguments for declaration of peripheral");
		//return NULL;
	}
	struct peripherical *peri=malloc(sizeof(struct peripherical));
	peri->nodetype='K';
	peri->name=p->name;
	peri->f=p->fl;
	p->var->nodetype=p->type;
	p->var->p=peri;
}

/* TYPE C USERFUNC - TYPE L BUILTFUNC */

struct funclist* newfunclist(struct ast* func, struct funclist *next){
	struct funclist *fn=malloc(sizeof(struct funclist));
		fn->bcall=(struct ufncall*)func;
		fn->next=next;
		return fn;
}

struct ast* newperipheralcall(struct symbol *s, struct ast* a, struct symbol *f, struct ast *expl ){
	if(!s){

	}else{
		struct perimethod *m=malloc(sizeof(struct perimethod));
		m->nodetype='J';
		m->s=s;
		m->a=a;
		m->f=f;
		m->expl=expl;
	}
}

void peripheralcall(struct perimethod *m) {
	if(m->a){
		printf("Peripheral ID -> %s\n",m->s->p->name);
	}else {
		int done=0;
		struct funclist *fl=m->s->p->f;
		while(fl){
			if((char*)fl->bcall->s->name==(char*)m->f->name){
				fl->bcall->l=m->expl;
				calluser(fl->bcall);
				done=1;
				break;
			}
			fl=fl->next;
		}
			if(done==0){
			printf("%s: ", m->f->name );
			printf("Method not found");
			}
	}
}



/****************************EVALUATE*******************************************/
struct ast *evaluate(struct ast *tree) {
    struct ast *result;
    struct ast *temp;
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
		case 'B' :
			  foreach((struct for_each*)tree);
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
			  else if(s->nodetype =='K')
			  	result=(struct ast *)(s->p);
              else
                result=(struct ast *)(s->v);
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
		case '_' :
			  assignPeri((struct periassign*)tree);
			  break;
		case 'J' :
			  peripheralcall((struct perimethod*)tree);
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