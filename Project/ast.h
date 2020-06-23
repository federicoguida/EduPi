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

enum bifs {			/* built-in functions */
  B_printf = 1,
};

struct fncall {			/* built-in function */
  int nodetype;			/* type F */
  struct ast *l;
  enum bifs functype;
};
struct ast *newast(int nodetype, struct ast* value1, struct ast* value2);
struct ast *newInteger(int nodetype, int value);
struct ast *newString(int nodetype, char * value);
struct ast *newReal(int nodetype, double value);
struct ast *sum(struct ast* value1, struct ast* value2);
struct ast *evaluate(struct ast* value);
char * printString(char * value);

void treefree(struct ast *);
/* interface to the lexer */
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);
