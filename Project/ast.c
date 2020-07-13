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

struct listexp *listcopy(struct listexp* lista) {
	struct listexp *l=malloc(sizeof(struct listexp));
	if(!l){
		yyerror("out of space");
		exit(0);
	}
	struct listexp *tmp=lista;
	struct listexp *val=l;
	val->nodetype='Y';
	val->exp=tmp->exp;
	val->next=NULL;
	tmp=tmp->next;
	while(tmp) {
		struct listexp *node=malloc(sizeof(struct listexp));
		node->nodetype='Y';
		node->exp=tmp->exp;
		node->next=NULL;
		val->next=node;
		val=val->next;
		tmp=tmp->next;
	}
	return l;
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
			yyerror("CALLUSER: Function do not have body", fn->name);
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
				yyerror("CALLUSER: Too few args in call to %s", fn->name);
				free(val);
				exit(1);
			}

			if(args->nodetype == 'Z') {	/* if this is a list node */
				struct ast* temp=evaluate(args->l);
				if(!temp){
					yyerror("CALLUSER: Args cannot be null");
					exit(1);
				}
				val[i] = temp;
				args = args->r;
			} else {			/* if it's the end of the list */
				struct ast* temp=evaluate(args);
				if(!temp){
					yyerror("CALLUSER: Args cannot be null");
					exit(1);
				}
				val[i] = temp;
				args = NULL;
			}
		}
					
		sl = fn->syms;
		for(i = 0; i < nargs; i++) {
			struct symbol *s = sl->sym;
			if(val[i]->nodetype=='Y'){
				s->l = listcopy((struct listexp*)val[i]);
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
		yyerror("LOOKUP: symbol table overflow\n");
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
			if(evaluate(tree->v)) {
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
								yyerror("ASSIGN: Type %c of variable is not compatible with the type %c of value. ", tree->s->nodetype, v->nodetype );
								exit(1);
						}
					}else{
						tree->s->v=v;
					}
			}else {
				yyerror("ASSIGN: Cannot assign null element!");
			}
		}else {
				if(!tree->v){
					struct listexp *node=malloc(sizeof(struct listexp));
					node->nodetype='Y';
					node->exp=NULL;
					node->next=NULL;
					tree->s->l=node;
				}else{
					if((evaluate(tree->v))->nodetype == 'Y' ) {
						struct listexp *l = (struct listexp *)(evaluate(tree->v));
						tree->s->l=l;
					}else {
						yyerror("ASSIGN: Cannot assign %c type to %c type!", tree->v->nodetype, tree->s->nodetype);
					}
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
				yyerror("POP: Cannot pop empty list");
				return NULL;
			}
		}else{
			yyerror("POP: Cannot pop %c TYPE", s->nodetype);
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
				yyerror("APPEND: Argument not defined");
			}
		}
		else{
			yyerror("APPEND: Cannot push %c TYPE", s->nodetype);
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
					yyerror("DELETE: Out of bounds!");
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
				yyerror("DELETE: Arguments not defined");
				return NULL;
			}
		}
		else{
			yyerror("DELETE: Cannot delete %c TYPE", s->nodetype);
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
					yyerror("GET: Out of bounds!");
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
				yyerror("GET: Argument not defined");
				return NULL;
			}
		}
		else{
			yyerror("GET: Cannot get %c TYPE", s->nodetype);
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
				yyerror("PUSH: Argument not defined");
			}
		}
		else{
			yyerror("PUSH: Cannot push %c TYPE", s->nodetype);
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
					yyerror("INSERT: Out of bounds!");
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
				yyerror("INSERT: Arguments not defined");
			}
		}
		else{
			yyerror("INSERT: Cannot insert %c TYPE", s->nodetype);
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
							yyerror("SEARCH: Cannot search list!");
							break;
						default:
							yyerror("SEARCH: Error type!");
							exit(1);
					}
					count++;
					l=l->next;
					if(l)
						val1=(struct value *)l->exp;
				}
				return NULL;
			}
			yyerror("SEARCH: Value NULL!");
			return NULL;
		}
		else{
			yyerror("SEARCH: Cannot search %c TYPE", s->nodetype);
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
	if(!evaluate(f->cond)) {
		yyerror("IF-ELSE: Undefined condition!");
	}else {
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
}

void whileop(struct flow *f) {
	if(!evaluate(f->cond)) {
		yyerror("WHILE: Undefined condition!");
	}else {
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
}

void dowhileop(struct flow *f) {
	struct value *v;
	struct integerType *i;
	if(f->tl) { 
		do{
			evaluate(f->tl);
			if(!evaluate(f->cond)) {
				yyerror("DO-WHILE: Undefined condition!");
				break;
			}
			v=(struct value*)evaluate(f->cond);
			i=(struct integerType*)v->structType;
		}while(i->value != 0); 
	}
}

void forop(struct flow *f) { 
	evaluate(f->in);
	if(!evaluate(f->cond)) {
		yyerror("FOR: Undefined condition!");
	}else {
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
	if(!(f->list->l)) {
		yyerror("FOR-EACH: Undefined list!");
	}else {
		if(f->list->nodetype!='Y'){
			yyerror("FOR-EACH: Second operator must be list");
		}else{
			if(f->list->l->exp){
				struct listexp* l=(struct listexp*)f->list->l;
				while(l){
					if(l->exp->nodetype=='Y'){
						f->i->nodetype='Y';
						f->i->l=(struct listexp*)evaluate(l->exp);
					}else{
						f->i->nodetype=l->exp->nodetype;
						f->i->v=(struct value*)l->exp;
					}
					evaluate(f->body);
					l=l->next;
				}
			}else{
				yyerror("FOR-EACH: List dont have elements");
			}
		}
	}
}

/*********************************END-FLOW*************************************/


/************************************************************************BUILT*/
struct ast *newfunc(int functype, struct ast *l, struct ast *r) {
		struct fncall *a = malloc(sizeof(struct fncall));
		
		if(!a) {
				yyerror("out of space");
				exit(0);
		}
		a->nodetype = 'L';
		a->l = l;
		a->r = r;
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

struct ast* strmrg(struct ast *value){
	char *res="";
	struct listexp *list=(struct listexp*)value;
	while(list){
		if(list->exp){
			struct ast* tmp=evaluate(list->exp);
			if(tmp) {
				if(tmp->nodetype=='S'){
					struct value *v=(struct value*)tmp;
					struct stringType *s=(struct stringType *)(v->structType);
					asprintf(&res, "%s%s", res, s->value);
					list=list->next;
				}else{
					yyerror("STRMRG: Cannot concat String with %c", tmp->nodetype);
					return NULL;
				}
			}
			else {
				list=list->next;
			}
		}
	}
	struct value *r=malloc(sizeof(struct value));
	struct stringType *result=malloc(sizeof(struct stringType));
	r->nodetype='S';
	result->value=res;
	r->structType=result;
	return (struct ast*)r;
}

struct ast* strmul(struct ast* string, struct ast* mul){
	if((string != NULL) && (mul != NULL)) {
		char *result="";
		if(mul->nodetype=='I' && string->nodetype=='S'){
			struct value* val=(struct value*)mul;
			struct value* st=(struct value*)string;
			int v=((struct integerType*)val->structType)->value;
			char *str=((struct stringType*)(st->structType))->value;
			for (int i =0; i<v; i++){
				asprintf(&result, "%s%s", result, str );
			}
			struct value * res=malloc(sizeof(struct value));
			struct stringType *sres=malloc(sizeof(struct stringType));
			sres->value=result;
			res->nodetype='S';
			res->structType=sres;
			return (struct ast*)res;
		}else if(mul->nodetype=='R' && string->nodetype=='S') {
			struct value* val=(struct value*)mul;
			struct value* st=(struct value*)string;
			int v=(int)(((struct realType*)val->structType)->value);
			char *str=((struct stringType*)(st->structType))->value;
			for (int i =0; i<v; i++){
				asprintf(&result, "%s%s", result, str );
			}
			struct value * res=malloc(sizeof(struct value));
			struct stringType *sres=malloc(sizeof(struct stringType));
			sres->value=result;
			res->nodetype='S';
			res->structType=sres;
			return (struct ast*)res;
		}else{
			yyerror("STRMUL: Types of arguments not compatible: %c %c", string->nodetype, mul->nodetype);
			return NULL;
		}
	}else {
		yyerror("STRMUL: Argument not defined");
		return NULL;
	}
}

char *itoa(int value){
	char *result;
	asprintf(&result,"%d",value);
	return result;
}

char *dtoa(double value){
	char *result;
	asprintf(&result,"%g",value);
	return result;
}

struct ast *toString(struct ast* exp){
	if(exp != NULL) {
		char *string;
		struct value* v;
		struct value* result;
		struct stringType* sres;
		if(exp->nodetype=='I' || exp->nodetype=='R'){
			switch(exp->nodetype){
				case 'I' :
					v=(struct value*)exp;
					string=itoa(((struct integerType*)(v->structType))->value);
					result=malloc(sizeof(struct value));
					sres=malloc(sizeof(struct stringType));
					sres->value=string;
					result->nodetype='S';
					result->structType=sres;
					return (struct ast*)result;
				case 'R' :
					v=(struct value*)exp;
					string=dtoa(((struct realType*)(v->structType))->value);
					result=malloc(sizeof(struct value));
					sres=malloc(sizeof(struct stringType));
					sres->value=string;
					result->nodetype='S';
					result->structType=sres;
					return (struct ast*)result;
			}
		}else{
			yyerror("TO-STRING: Types of arguments not compatible: %c", exp->nodetype);
			return NULL;
		}
	}else {
		yyerror("TO-STRING: Argument not defined");
		return NULL;
	}
}

struct ast* toInt(struct ast * value){
	if(value->nodetype!='I' && value->nodetype!='R'){
		yyerror("TO-INTEGER: Cannot convert to integer %c TYPE", value->nodetype);
		return NULL;
	}
	struct value *result=malloc(sizeof(struct value));
	struct integerType *res=malloc(sizeof(struct value));
	struct value *point=(struct value *)value;
	struct realType* real;
	switch(value->nodetype){
		case 'I':
			free(result);
			free(res);
			return (struct ast*)value;
		case 'R':
			real=(struct realType* )(point->structType);
			result->nodetype='I';
			res->value=(int)real->value;
			result->structType=res;
			return (struct ast*)result;
	}
}

struct ast* callbuiltin(struct fncall *f){
    struct ast* a;
    enum bifs functype = f->functype;

    switch(functype) {
				case B_print:
					if(!f->l){
						yyerror("FUNC: No arguments for print...");
						free(a);
						break;
					}
					print(evaluate(f->l));
					break;
				case B_println:
					if(!f->l){
						yyerror("FUNC: No arguments for println...");
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
						yyerror("FUNC: No arguments for pop...");
						free(a);
						break;
					}
					a=pop(f->s);
					break;
				case B_push:
					if(!f->l) {
						yyerror("FUNC: No arguments for push...");
						free(a);
						break;
					}
					push(f->s, evaluate(f->l));
					break;
				case B_app:
					if(!f->l){
						yyerror("FUNC: No arguments for append...");
						free(a);
						break;
					}
					append(f->s, evaluate(f->l));
					break;
				case B_del:
					if(!f->s || !f->l) {
						yyerror("FUNC: No arguments for delete...");
						free(a);
						break;
					}
					a=delete(f->s, evaluate(f->l));
					break;
				case B_get:
					if(!f->s || !f->l) {
						yyerror("FUNC: No arguments for get...");
						free(a);
						break;
					}
					a=get(f->s, evaluate(f->l));
					break;
				case B_ins:
					if(!f->l || !f->r) {
						yyerror("FUNC: No arguments for insert...");
						free(a);
						break;
					}
					insert(f->s, evaluate(f->l), evaluate(f->r));
					break;
				case B_search:
					if(!f->s || !f->l) {
						yyerror("FUNC: No arguments for search...");
						free(a);
						break;
					}
					a=search(f->s, evaluate(f->l));
					break;
				case B_size:
					if(!f->s) {
						yyerror("FUNC: No arguments for size...");
						free(a);
						break;
					}
					a=size(f->s);
					break;
				case B_slp:
					if(!f->l){
						yyerror("FUNC: No arguments for sleep...");
						free(a);
						break;
					}
					bsleep(evaluate(f->l));
					break;
				case B_type:
					if(!f->l) {
						yyerror("FUNC: No arguments for type...");
						free(a);
						break;
					}
					a=type(f->l);
					break;
				case B_sqrt:
					if(!f->l) {
						yyerror("FUNC: No arguments for sqrt...");
						free(a);
						break;
					}
					a=ssqrt(evaluate(f->l));
					break;
				case B_pow:
					if(!f->l || !f->r) {
						yyerror("FUNC: No arguments for pow...");
						free(a);
						break;
					}
					a=ppow(evaluate(f->l), evaluate(f->r));
					break;
				case B_random:
					if(!f->l || !f->r) {
						yyerror("FUNC: No arguments for random...");
						free(a);
						break;
					}
					a=rrandom(evaluate(f->l), evaluate(f->r));
					break;
				case B_sop:
					if(!f->l || !f->r) {
						yyerror("FUNC: No arguments for setOutPin...");
						free(a);
						break;
					}
					setOutPin(evaluate(f->l), evaluate(f->r));
					break;
				case B_rgb:
					if(!f->l || !f->r) {
						yyerror("FUNC: No arguments for ledRGB...");
						free(a);
						break;
					}
					ledRGB(evaluate(f->l), evaluate(f->r));
					break;
				case B_butt:
					if(!f->l) {
						yyerror("FUNC: No arguments for button...");
						free(a);
						break;
					}
					a=button(evaluate(f->l));
					break;
				case B_scan:
					if(!f->l) {
						yyerror("FUNC: No type specified for scan...");
						free(a);
						break;
					}
					a=scan(evaluate(f->l));
					break;
				case B_init:
					lcd_init();
					break;
				case B_sendInt:
					if(!f->l) {
						yyerror("FUNC: No type specified for send integer lcd...");
						free(a);
						break;
					}
					sendIntegerLcd(evaluate(f->l));
					break;
				case B_sendReal:
					if(!f->l) {
						yyerror("FUNC: No type specified for send real lcd...");
						free(a);
						break;
					}
					sendRealLcd(evaluate(f->l));
					break;
				case B_sendString:
					if(!f->l) {
						yyerror("FUNC: No type specified for send string lcd...");
						free(a);
						break;
					}
					sendStringLcd(evaluate(f->l));
					break;
				case B_sLine:
					if(!f->l) {
						yyerror("FUNC: No type specified for lcd line...");
						free(a);
						break;
					}
					lcdLoc(evaluate(f->l));
					break;
				case B_clear:
					clrLcd();
					break;
				case B_strmrg:
					if(!f->l){
						yyerror("FUNC: No arguments for strmrg...");
						free(a);
						break;
					}
					a=strmrg(evaluate(f->l));
					break;
				case B_strmul:
					if(!f->l || !f->r){
						yyerror("FUNC: No arguments for strmul...");
						free(a);
						break;
					}
					a=strmul(evaluate(f->l),evaluate(f->r));
					break;
				case B_toString:
					if(!f->l){
						yyerror("FUNC: No arguments for toString...");
						free(a);
						break;
					}
					a=toString(evaluate(f->l));
					break;
				case B_status:
					status();
					break;
				case 'I':
					if(!f->l){
						yyerror("FUNC: No arguments for convert to integer");
						free(a);
						break;
					}
					a=toInt(evaluate(f->l));
					break;
				case B_exit:
					exit(0);
				default:
					yyerror("Unknown built-in function %d", functype);
 		}
		if(!a){
			a=malloc(sizeof(struct ast*));
			return a;
		}
  		return a;
}

void print(struct ast *val) {
	if(!val)
		yyerror("PRINT: Cannot print null element");
	else{
		struct value *a;
		struct integerType *i;
		struct realType *r;
		struct stringType *s;
		struct listexp *l;
		struct peripherical *p;
		struct funclist *f;
		struct ast* listPrint;
		struct symlist *sl;

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
						printf("Peripheral Description: %s\n",p->name);
						f=p->f;
						while(f){
							printf("Method --> %s(", f->bcall->s->name);
							sl=f->bcall->s->syms;
							while(sl){
								if(sl->sym)
									printf("%s",sl->sym->name);
								if(sl->next)
									printf(",");
								sl=sl->next;
							}
							printf(")\n");
							f=f->next;
						}
						break;
			case 'P' :
						listPrint=val;
						while(listPrint){
							if(listPrint->l){
								print(evaluate(listPrint->l));
							}
							listPrint=listPrint->r;
						}
						break;

			default: printf("Error print"); exit(1);
		}
	}
}

void println(struct ast *val) {
	if(!val)
		yyerror("PRINTLN: Cannot print null element");
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
	if(val != NULL) {
		struct value *a;
		struct integerType *i;
		struct realType *r;
		if(val->nodetype=='I'){
			a=(struct value *)val;
			i=(struct integerType *)a->structType;
			int intero= i->value;
			fflush(stdout);
			usleep(intero*1000);
		}else if(val->nodetype=='R') {
			a=(struct value *)val;
			r=(struct realType *)a->structType;
			double reale= r->value;
			fflush(stdout);
			usleep(reale*1000);
		}else{
			yyerror("SLEEP: Integer type expected on sleep function");
		}
	}else {
		yyerror("SLEEP: Argument not defined");
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
			case 'V':
				res=malloc(sizeof(struct value));
				str=malloc(sizeof(struct stringType));
				switch(((struct symref*)val)->s->nodetype) {
					case 'I': str->value = "integer"; break;
					case 'R': str->value = "real"; break;
					case 'S': str->value = "string"; break;
					case 'Y': str->value = "list"; break;
					case 'K': str->value = "peripheral"; break;
					case 'L': type(evaluate(val)); break;
					case 'C': type(evaluate(val)); break;
					default: str->value = "undefined type"; break;
				}
				res->nodetype = 'S';
				res->structType = str;
				return (struct ast *)res;
			case 'L':
				type(evaluate(val));
				break;
			case 'C':
				type(evaluate(val));
				break;
			default:
				yyerror("TYPE: Error type!");
				exit(1);
		}
	}
	else {
		yyerror("TYPE: Argument not defined");
		return NULL;
	}
}

struct ast *scan(struct ast *val) {
	if(val != NULL) {
		struct value *v=(struct value *)val;
		struct stringType *s=(struct stringType *)v->structType;
		struct value *res;
		struct integerType *inres;
		struct realType *dbres;
		struct stringType *stres;
		int i;
		double d;
		char *str;
		if(strcmp(s->value, "I") == 0) {
			res=malloc(sizeof(struct value));
			inres=malloc(sizeof(struct integerType));
			scanf("%d", &i);
			inres->value=i;
			res->nodetype='I';
			res->structType=inres;
			return (struct ast *)res;
		}else if(strcmp(s->value, "R") == 0) {
			res=malloc(sizeof(struct value));
			dbres=malloc(sizeof(struct realType));
			scanf("%g", &d);
			dbres->value=d;
			res->nodetype='R';
			res->structType=dbres;
			return (struct ast *)res;
		}else if(strcmp(s->value, "S") == 0) {
			res=malloc(sizeof(struct value));
			stres=malloc(sizeof(struct stringType));
			str=malloc(sizeof(char)*50);
			scanf("%s", str);
			stres->value=str;
			res->nodetype='S';
			res->structType=stres;
			return (struct ast *)res;
		}else {
			yyerror("SCAN: Type not defined");
			return NULL;
		}
	}else {
		yyerror("SCAN: Argument not defined");
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
			yyerror("SQRT: Incompatible type!");
			return NULL;
		}
	}
	else {
		yyerror("SQRT: Argument not defined");
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
				yyerror("POW: Incompatible type!");
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
			}else {
				yyerror("POW: Incompatible type!");
				return NULL;
			}
		}else {
			yyerror("POW: Incompatible type!");
			return NULL;
		}
	}else {
		yyerror("POW: Argument not defined");
		return NULL;
	}
}

struct ast *rrandom(struct ast *val1, struct ast *val2) {
	if((val1 != NULL) && (val2 != NULL)) {
		struct value *v1=(struct value *)val1;
		struct value *v2=(struct value *)val2;
		srand(time(0));
		if(v1->nodetype == 'I') {
			if(v2->nodetype == 'I') {
				struct value *res=malloc(sizeof(struct value));
				struct integerType *i=malloc(sizeof(struct integerType));
				struct integerType *intValue1=(struct integerType *)v1->structType;
				struct integerType *intValue2=(struct integerType *)v2->structType;
				i->value=(intValue1->value)+rand()%(intValue2->value);
				res->nodetype='I';
				res->structType=i;
				return (struct ast *)res;
			}else {
				yyerror("RANDOM: Incompatible type!");
				return NULL;
			}
		}else {
			yyerror("RANDOM: Incompatible type!");
			return NULL;
		}
	}else {
		yyerror("RANDOM: Argument not defined");
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



/**************PERIPHERAL**********************/
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
		yyerror("ASSIGN-PERI: No arguments for declaration of peripheral");
	}
	struct peripherical *peri=malloc(sizeof(struct peripherical));
	peri->nodetype='K';
	peri->name=p->name;
	peri->f=p->fl;
	p->var->nodetype=p->type;
	p->var->p=peri;
}

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
	if(m->s->p){
		if(m->a){
			printf("Peripheral ID -> %s\nPeripheral Description: %s\n",m->s->name,m->s->p->name);
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
	}else{
		yyerror("Peripheral not found!");
	}
}

struct listexp* newprintlist(struct ast *p, struct listexp *list){
		struct listexp *l=malloc(sizeof(struct listexp));

		l->nodetype = 'P';
    	l->exp = p;
    	l->next = list;
		return l;
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
              result=operation('+',evaluate(tree->l), evaluate(tree->r));
              break;
        case '-' :
              result=operation('-',evaluate(tree->l), evaluate(tree->r));
              break;
        case '*' :
              result=operation('*',evaluate(tree->l), evaluate(tree->r));
              break;
        case '/' :
              result=operation('/',evaluate(tree->l), evaluate(tree->r));
              break;
        case '%' :
              result=operation('%',evaluate(tree->l), evaluate(tree->r));
              break;
        case '|' :
              result=sop('|',evaluate(tree->l));
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
		case 'P' :
			  result=tree;
			  break;
		case 'B' :
			  foreach((struct for_each*)tree);
			  break;
        case 'M' :
              result=sop('M',evaluate(tree->l));
              break;
        case 'O' :
              result=operation('O',evaluate(tree->l), evaluate(tree->r));
              break;
        case 'A' :
              result=operation('A',evaluate(tree->l), evaluate(tree->r));
              break;
        case 'N' :
              result=sop('N',evaluate(tree->l));
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
			  ((struct symdecl*)tree)->s->v=NULL;
			  ((struct symdecl*)tree)->s->l=NULL;
			  ((struct symdecl*)tree)->s->p=NULL;
			  ((struct symdecl*)tree)->s->func=NULL;
			  ((struct symdecl*)tree)->s->syms=NULL;
			  ((struct symdecl*)tree)->s->returnValue=NULL;
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
        case 1: result = operation(1,evaluate(tree->l), evaluate(tree->r)); break; // >
        case 2: result = operation(2,evaluate(tree->l), evaluate(tree->r)); break; // <
        case 3: result = operation(3,evaluate(tree->l), evaluate(tree->r)); break; // !=
        case 4: result = operation(4,evaluate(tree->l), evaluate(tree->r)); break; // ==
        case 5: result = operation(5,evaluate(tree->l), evaluate(tree->r)); break; // >=
        case 6: result = operation(6,evaluate(tree->l), evaluate(tree->r)); break; // <=
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