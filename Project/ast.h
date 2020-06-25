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

struct symlist *newsymlist(struct symbol *sym, struct symlist *next);
void symlistfree(struct symlist *sl);

struct ast *newref(struct symbol *s);
struct ast *newasgn(int type,struct symbol *s, struct ast *v);
struct ast *newsasgn(struct symbol *s, struct ast *v);
void varType(int type, struct symbol *s);

/********************************WORKING ON VARIABLE********************************/

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

struct flow {
  int nodetype;
  struct ast *cond;
  struct ast *tail;     /*tail*/
  struct ast *el;       /*else*/
};

enum bifs {			/* built-in functions */
  B_printf = 1,
};

struct fncall {			/* built-in function */
  int nodetype;			/* type F */
  struct ast *l;
  enum bifs functype;
};

struct ast *newast(int nodetype, struct ast *value1, struct ast *value2);
struct ast *newInteger(int nodetype, int value);
struct ast *newString(int nodetype, char *value);
struct ast *newReal(int nodetype, double value);
struct ast *evaluate(struct ast *value);

struct ast *newflow(int nodetype, struct ast *cond, struct ast *tail, struct ast *el);
struct ast *if_code(struct ast *cond, struct ast *tail, struct ast *el);

char * printString(char *value);
void println(struct ast *val);
void print(struct ast *val);

void treefree(struct ast *);
/* interface to the lexer */
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);
