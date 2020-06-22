#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include <string.h>
#  include <math.h>
#  include "ast.h"

struct ast *
newInteger(int value)
{
  struct value *a = malloc(sizeof(struct value));
  struct integerType *i = malloc(sizeof(struct integerType));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'I';
  i->value=value;
  a->number = i;
  return (struct ast *)a;
}

void print(struct ast *val){
    void * v;
    switch(val->nodetype){
        case 'I' : v = ((struct value *)val)->structType->value;
                    printf("%d", value);
                    break;
        default: printf("Error");
    }
}