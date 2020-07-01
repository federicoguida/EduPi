/***************** STRUCT DEF****************************/
// Struct for variable
struct symbol {
    char * name;
    int nodetype;
    struct value *v;
    struct listexp *l;
    struct ast *func;
    struct symlist *syms;
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

enum bifs {			/* built-in functions */
  B_print=1,
  B_println=2,
};

// built-in function 
struct fncall {			
  int nodetype;			/* type L */
  struct ast *l;
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
struct ast *incr(struct symbol *s);
struct ast *decr(struct symbol *s);
void assign(struct symasgn *tree);
/********************************VARIABLE********************************/

/*******************************START LIST*************************************/
struct listexp *newlist(int nodetype, struct ast *exp, struct listexp *next);
void printList(struct listexp *l);
struct ast *newlasgn(int type, struct symbol *s, struct listexp *l);
struct ast *newlsasgn(struct symbol *s, struct listexp *l);
struct ast *pop(struct symbol *s);
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
struct ast *callbuiltin(struct fncall *f);
struct ast *date();
char *printString(char *value);
void println(struct ast *val);
void print(struct ast *val);
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