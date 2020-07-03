/***************** STRUCT DEF****************************/
// Struct for variable
struct symbol {
    char * name;
    int nodetype;
    struct value *v;
    struct listexp *l;
    struct ast *func;
    struct symlist *syms;
    struct ast *returnValue;
};

// Struct for store and search variable
#define NHASH 9997
struct symbol symtab[NHASH];
struct symbol *lookup(char*);


// List of symbol 
struct symlist {
  struct symbol *sym;
  struct symlist *next;
};

// Struct for ref variable
struct symref {
  int nodetype;			/* type N */
  struct symbol *s;
};

// Struct for asgn
struct symasgn {
  int nodetype;			/* type = */
  struct symbol *s;
  struct ast *v;		
};

// Struct for decl
struct symdecl {
  int nodetype;     /* type X */
  int type;
  struct symbol *s;
};

// Struct for type list
struct listexp {
  int nodetype;     /* tupe Y */
  struct ast *exp;
  struct listexp *next;
};

// Struct flow
struct flow {
  int nodetype;			/* type F or W */
  struct ast *cond;		/* condition */
  struct ast *tl;		/* then or do list */
  struct ast *el;		/* optional else list */
  struct ast *in;  /* for init */
};

struct for_each{
  int nodetype;
  struct symbol *i;
  struct symbol *list;
  struct ast *body;
};

enum bifs {			/* built-in functions */
  B_print=1,
  B_println=2,
  B_time=3,
  B_pop=4,
  B_app=5,
  B_del=6,
  B_ins=7,
  B_push=8,
  B_get=9,
  B_size=10,
  B_search=11,
};

// built-in function 
struct fncall {			
  int nodetype;			/* type L */
  struct ast *l;
  struct ast *r;
  struct symbol *s;
  enum bifs functype;
};

// General Tree
struct ast {
    int nodetype; 
    struct ast *l;
    struct ast *r;
};

// Struct value
struct value{
    int nodetype;
    void * structType;
};

// Struct for type int
struct integerType{
    int value;
};

// Struct for type string
struct stringType{
    char * value;
};

// Struct for type real
struct realType{
    double value;
};
/*****************END-STRUCT DEF****************************/

/********************************VARIABLE********************************/
struct ast *newref(struct symbol *s);
struct ast *newasgn(int type,struct symbol *s, struct ast *v);
struct ast *newsasgn(struct symbol *s, struct ast *v);
struct ast *newsymdecl(int node, struct symbol *s);
struct ast *newinc(int nodetype, struct symbol *s);
void incr(struct symbol *s);
void decr(struct symbol *s);
void assign(struct symasgn *tree);
/********************************VARIABLE********************************/

/*******************************START LIST*************************************/
struct listexp *newlist(int nodetype, struct ast *exp, struct listexp *next);
void printList(struct listexp *l);
struct ast *newlasgn(int type, struct symbol *s, struct listexp *l);
struct ast *newlsasgn(struct symbol *s, struct listexp *l);
struct ast *pop(struct symbol *s);
void push(struct symbol *s, struct ast *exp);
void append(struct symbol *s, struct ast *exp);
struct ast *delete(struct symbol *s, struct ast *exp);
void insert(struct symbol *s, struct ast *exp, struct ast *val);
struct ast *get(struct symbol *s, struct ast *exp);
struct ast *search(struct symbol *s, struct ast *exp);
struct ast *size(struct symbol *s);
int sizeList(struct listexp *l);
/********************************END-LIST**************************************/

/******************************FLOW*/
struct ast *newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *tr, struct ast *in);
void ifop(struct flow *f);
void whileop(struct flow *f);
void dowhileop(struct flow *f);
void forop(struct flow *f);
/******************************END-FLOW*/

/**********************BUILT*/
struct ast *newfunc(int functype, struct ast *l);
struct ast *newlfunc(int functype, struct symbol *l, struct ast *exp, struct ast *val);
struct ast *callbuiltin(struct fncall *f);
struct ast *date();
char *printString(char *value);
void println(struct ast *val);
void print(struct ast *val);
struct ast *newForEach(int nodetype, struct symbol* i, struct symbol* list, struct ast* body);
/*****************END-BUILT*/

/*********************************Type INIT*/
struct ast *newast(int nodetype, struct ast *value1, struct ast *value2);
struct ast *newInteger(int nodetype, int value);
struct ast *newString(int nodetype, char *value);
struct ast *newReal(int nodetype, double value);
struct ast *evaluate(struct ast *value);
struct symlist *newsymlist(struct symbol *sym, struct symlist *next);
/*********************************END-Type INIT*/

/***********************OTHER UTILITY*/
void treefree(struct ast *);
void symlistfree(struct symlist *sl);
/* interface to the lexer */
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);
/***********************END-OTHER UTILITY*/




void dodef(struct symbol *name, struct symlist *syms, struct ast *func, struct ast *returnValue);

struct ufncall {		/* user function */
  int nodetype;			/* type C */
  struct ast *l;		/* list of arguments */
  struct symbol *s;
};
struct ast* calluser(struct ufncall *f);

struct ast *newcall(struct symbol *s, struct ast *l);