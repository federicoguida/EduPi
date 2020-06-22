#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include <string.h>
#  include <math.h>
#  include "ast.h"

struct ast *
newInteger(int nodetype , int value)
{
  struct value *a = malloc(sizeof(struct value));
  struct integerType *i = malloc(sizeof(struct integerType));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  i->value=value;
  a->structType = i;
  return (struct ast *)a;
}

struct ast *
newReal(int nodetype , double value)
{
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

struct ast *
newString(int nodetype , char * value)
{
  struct value *a = malloc(sizeof(struct value));
  struct stringType *s = malloc(sizeof(struct stringType));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  s->value=value;
  a->structType = s;
  return (struct ast *)a;
}

void
treefree(struct ast *a)
{
  switch(a->nodetype) {
      case 'I' : case 'R' : case 'S' :
      break;
      default: printf("internal error: free bad node %c\n", a->nodetype);
  }
  free(a); /* always free the node itself */
}

struct ast *sum(struct ast* value1, struct ast* value2){
      struct value *val1= malloc(sizeof(struct value));
      struct value *val2= malloc(sizeof(struct value));
      struct value *result= malloc(sizeof(struct value));
      struct integerType *intValue1;
      struct integerType *intValue2;
      struct integerType *intResult;
      int res;
      struct realType *realValue1;
      struct realType *realValue2;
      struct realType *realResult;
      double dbres;
      struct stringType *stringValue1;
      struct stringType *stringValue2;
      struct stringType *stringResult;
      char * stres;


      switch(value1->nodetype){
          case 'I' :
                  intValue1=malloc(sizeof(struct integerType));
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  intResult=malloc(sizeof(struct integerType));
                  switch(value2->nodetype){
                    case 'I' :
                      intValue2=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res= intValue1->value + intValue2->value ;
                      free(intValue1);
                      free(intValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res= intValue1->value + realValue1->value ;
                      free(intValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res= intValue1->value + stringValue1->value ;
                      free(intValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
                  }
                  result->nodetype='I';
                  intResult->value=res;
                  result->structType=intResult;
                  break ;

          default: printf("internal error");
      }

      return (struct ast *)result;
}

void print(struct ast *val){
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
                    printf("%d\n", intero);
                    free(i);
                    break;
        case 'R' :
                    r=malloc(sizeof(struct realType));
                    a=(struct value *)val;
                    r=(struct realType *)a->structType;
                    double reale= r->value;
                    printf("%g\n", reale);
                    free(r);
                    break;
        case 'S' :
                    s=malloc(sizeof(struct stringType));
                    a=(struct value *)val;
                    s=(struct stringType *)a->structType;
                    char * stringa=s->value;
                    printf("%s\n", stringa);
                    free(s);
                    break;   

        default: printf("Error");
    }

}

void
yyerror(char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

int
main()
{
  return yyparse();
}