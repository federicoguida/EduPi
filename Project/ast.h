/********************************WORKING ON VARIABLE********************************/
struct symbol {
    char * name;
    int nodetype;
    struct value *v;
    struct ast *func;
    struct symlist *syms;
};

#define NHASH 9997
struct symbol symtab[NHASH];

struct symbol *lookup(char*);

/* list of symbols, for an argument list */
struct symlist {
  struct symbol *sym;
  struct symlist *next;
};

struct symref {
  int nodetype;			/* type N */
  struct symbol *s;
};

struct symasgn {
  int nodetype;			/* type = */
  struct symbol *s;
  struct ast *v;		/* value */
};

struct symdecl {
  int nodetype;
  int type;
  struct symbol *s;
};

struct symlist *newsymlist(struct symbol *sym, struct symlist *next);
void symlistfree(struct symlist *sl);

struct ast *newref(struct symbol *s);
struct ast *newasgn(int type,struct symbol *s, struct ast *v);
struct ast *newsasgn(struct symbol *s, struct ast *v);
struct ast *newsymdecl(int node, struct symbol *s);
/********************************WORKING ON VARIABLE********************************/


/******************************FLOW*/

struct flow {
  int nodetype;			/* type F or W */
  struct ast *cond;		/* condition */
  struct ast *tl;		/* then or do list */
  struct ast *el;		/* optional else list */
  struct ast *in;  /* for init */
};

struct ast *newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *tr, struct ast *in);
void ifop(struct flow *f);
void whileop(struct flow *f);
void dowhileop(struct flow *f);
void forop(struct flow *f);
/******************************FLOW*/

/**********************BUiLT*/
enum bifs {			/* built-in functions */
  B_print=1,
  B_println=2,
};

struct fncall {			/* built-in function */
  int nodetype;			/* type L */
  struct ast *l;
  enum bifs functype;
};

struct ast *newfunc(int functype, struct ast *l);
struct ast *callbuiltin(struct fncall *f);
/*****************BUiLT*/


struct ast {
    int nodetype; 
    struct ast *l;
    struct ast *r;
};

struct value{
    int nodetype;
    void * structType;
};

struct integerType{
    int value;
};

struct stringType{
    char * value;
};

struct realType{
    double value;
};


struct ast *newast(int nodetype, struct ast *value1, struct ast *value2);
struct ast *newInteger(int nodetype, int value);
struct ast *newString(int nodetype, char *value);
struct ast *newReal(int nodetype, double value);
struct ast *evaluate(struct ast *value);
char * printString(char *value);
void println(struct ast *val);
void print(struct ast *val);
struct ast *date();

void treefree(struct ast *);
/* interface to the lexer */
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);
