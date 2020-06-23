#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include <string.h>
#  include <math.h>
#  include "ast.h"


char * clearString( char * str){
    char * result;
    result=strndup(str+1, strlen(str)-2);
    return result;
}

struct ast *
newInteger(int nodetype , int value)
{
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
  s->value=clearString(value);
  a->structType = s;
  return (struct ast *)a;
}

void
treefree(struct ast *a)
{
  switch(a->nodetype) {
      case 'I' : case 'R' : case 'S':
      break;
      
  }
  free(a); /* always free the node itself */
}


struct ast *newast(int nodetype, struct ast* l, struct ast* r){
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


struct ast *evaluate(struct ast* tree){
    struct ast *result=malloc(sizeof(struct ast));
    switch(tree->nodetype){
        case '+' :
              result=sum(tree->l, tree->r);
              free(tree);
              break;
        case '-' :
              result=sub(tree->l, tree->r);
              free(tree);
              break;
        case '*' :
              result=mul(tree->l, tree->r);
              free(tree);
              break;
        case '/' :
              result=rdiv(tree->l, tree->r);
              free(tree);
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
        case 'M' :
              result=negateValue(tree->l);
              break;
        case 'O' :
              result=or(tree->l,tree->r);
              free(tree);
              break;
        case 1: result = compare(1,tree->l,tree->r); break; // >
        case 2: result = compare(2,tree->l,tree->r); break; // <
        case 3: result = compare(3,tree->l,tree->r); break; // !=
        case 4: result = compare(4,tree->l,tree->r); break; // ==
        case 5: result = compare(5,tree->l,tree->r); break; // >=
        case 6: result = compare(6,tree->l,tree->r); break; // <=
        default: printf("internal error debug");
    }
    return result;

}

struct ast *compare(int type, struct ast *l, struct ast *r){
      struct value *val1= malloc(sizeof(struct value));
      struct value *val2= malloc(sizeof(struct value));
      struct value *result= malloc(sizeof(struct value));
      struct integerType *intResult=malloc(sizeof(struct integerType));
      int res;
      struct integerType *intValue1;
      struct integerType *intValue2;
      struct realType *realValue1;
      struct realType *realValue2;
      struct stringType *stringValue1;
      struct stringType *stringValue2;
      switch(type){
        /* CASE > */
        case 1:  
            switch(l->nodetype){
              case 'I':
                intValue1=malloc(sizeof(struct integerType));
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value > intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value > realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
              case 'R':
                realValue1=malloc(sizeof(struct realType));
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value > intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value > realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
              case 'S':
                stringValue1=malloc(sizeof(struct stringType));
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'S':
                    stringValue2=malloc(sizeof(struct stringType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) > strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(stringValue1);
                    free(stringValue2);
                    break;
                }
            }
        break;
        /*Cambio case e vado nel minore*/
        case 2:
            switch(l->nodetype){
              case 'I':
                intValue1=malloc(sizeof(struct integerType));
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value < intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value < realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
              case 'R':
                realValue1=malloc(sizeof(struct realType));
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value < intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value < realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
              case 'S':
                stringValue1=malloc(sizeof(struct stringType));
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'S':
                    stringValue2=malloc(sizeof(struct stringType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) < strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(stringValue1);
                    free(stringValue2);
                    break;
                }
            }
        break;
        /*FINE CASO MINORE*/
        /*Cambio !=*/
        case 3:
            switch(l->nodetype){
              case 'I':
                intValue1=malloc(sizeof(struct integerType));
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value != intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value != realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
              case 'R':
                realValue1=malloc(sizeof(struct realType));
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value != intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value != realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
              case 'S':
                stringValue1=malloc(sizeof(struct stringType));
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'S':
                    stringValue2=malloc(sizeof(struct stringType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) != strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(stringValue1);
                    free(stringValue2);
                    break;
                }
            }
        break;
        /*FINE CASO !=*/
        /* CASO == */
        case 4:
            switch(l->nodetype){
              case 'I':
                intValue1=malloc(sizeof(struct integerType));
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value == intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value == realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
              case 'R':
                realValue1=malloc(sizeof(struct realType));
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value == intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value == realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
              case 'S':
                stringValue1=malloc(sizeof(struct stringType));
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'S':
                    stringValue2=malloc(sizeof(struct stringType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) == strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(stringValue1);
                    free(stringValue2);
                    break;
                }
            }
        break;
        /*FINE CASO ==*/
        /* CASO >= */
        case 5:
            switch(l->nodetype){
              case 'I':
                intValue1=malloc(sizeof(struct integerType));
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value >= intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value >= realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
              case 'R':
                realValue1=malloc(sizeof(struct realType));
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value >= intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value >= realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
              case 'S':
                stringValue1=malloc(sizeof(struct stringType));
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'S':
                    stringValue2=malloc(sizeof(struct stringType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) >= strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(stringValue1);
                    free(stringValue2);
                    break;
                }
            }
        break;
        /*FINE CASO ==*/
        /* CASO >= */
        case 6:
            switch(l->nodetype){
              case 'I':
                intValue1=malloc(sizeof(struct integerType));
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value <= intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value <= realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(intValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
              case 'R':
                realValue1=malloc(sizeof(struct realType));
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intValue2=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value <= intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(intValue2);
                    break;
                  case 'R':
                    realValue2=malloc(sizeof(struct realType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value <= realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(realValue1);
                    free(realValue2);
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
              case 'S':
                stringValue1=malloc(sizeof(struct stringType));
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                    break;
                  case 'S':
                    stringValue2=malloc(sizeof(struct stringType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) <= strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    free(val1);
                    free(val2);
                    free(stringValue1);
                    free(stringValue2);
                    break;
                }
            }
        break;
        /*FINE CASO <=*/
      }
      return (struct ast *)result;
}




struct ast *or(struct ast* value1, struct ast* value2){
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
      char * str1;
      char * str2;
      char * stres;
              intValue1=malloc(sizeof(struct integerType));
              val1=(struct value *)value1;
              intValue1=(struct integerType *)val1->structType;
              intResult=malloc(sizeof(struct integerType));
              intValue2=malloc(sizeof(struct integerType));
              val2=(struct value *)value2;
              intValue2=(struct integerType *)val2->structType;
              res=(intValue1->value || intValue2->value);
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;


  return (struct ast *)result;
}


struct ast *negateValue(struct ast* tree){
  struct value * a=malloc(sizeof(struct value));
  struct integerType * i;
  struct realType * r;
  switch(tree->nodetype){
    case 'I' :  
          a=(struct value *)tree;
          i=malloc(sizeof(struct integerType));
          i=(struct integerType *)a->structType;
          int inresult=i->value*(-1);
          i->value=inresult;
          a->nodetype='I';
          a->structType=i;
          break;
    case 'R' :
          a=(struct value *)tree;
          r=malloc(sizeof(struct realType));
          r=(struct realType *)a->structType;
          double dbresult=r->value*(-1);
          r->value=dbresult;
          a->nodetype='R';
          a->structType=r;
          break;
    case 'S' :
          yyerror("Cannot negate String");
          exit(1);
          break;
  }

  return (struct ast* )a;
}
    
char * strmul(char *str, int n){
    char *result=strdup(str);
    if(!str || n<=0){
      return "";
    }
    for(int i=0; i<n-1; i++){
        strcat(result, str);
    }
    free(str);
    return result;
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
      char * str1;
      char * str2;
      char * stres;


      switch(value1->nodetype){
          case 'I' :
                  intValue1=malloc(sizeof(struct integerType));
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      intResult=malloc(sizeof(struct integerType));
                      intValue2=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res= intValue1->value + intValue2->value ;
                      result->nodetype='I';
                      intResult->value=res;
                      result->structType=intResult;
                      free(intValue1);
                      free(intValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      dbres= intValue1->value + realValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(intValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      yyerror("invalid operation.. Incompatible type IntType + StringType");
                      exit(1);
                      break;
                  }
                  break ;

          case 'R' :
                  realValue1=malloc(sizeof(struct realType));
                  val1=(struct value *)value1;
                  realValue1=(struct realType *)val1->structType;
                  realResult=malloc(sizeof(struct realType));
                  switch(value2->nodetype){
                    case 'I' :
                      intValue1=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      dbres= realValue1->value + (double)intValue1->value ;
                      free(realValue1);
                      free(intValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realValue2=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= realValue1->value + realValue2->value ;
                      free(realValue1);
                      free(realValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      yyerror("invalid operation.. Incompatible type RealType + StringType");
                      exit(1);
                      break;
                  }
                  result->nodetype='R';
                  realResult->value=dbres;
                  result->structType=realResult;
                  break ;
          
          case 'S' :
                  stringValue1=malloc(sizeof(struct stringType));
                  val1=(struct value *)value1;
                  stringValue1=(struct stringType *)val1->structType;
                  stringResult=malloc(sizeof(struct stringType));
                  switch(value2->nodetype){
                    case 'I' :
                      yyerror("invalid operation.. Incompatible type StringType + IntType");
                      exit(1);
                      break;
                    case 'R' :
                      yyerror("invalid operation.. Incompatible type StringType + RealType");
                      exit(1);
                      break;
                    case 'S' :
                      stringValue2=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue2=(struct stringType *)val2->structType;
                      str1=strdup(stringValue1->value);
                      str2=strdup(stringValue2->value);
                      strcat(str1,str2);
                      free(stringValue1);
                      free(stringValue2);
                      free(val1);
                      free(val2);
                      result->nodetype='S';
                      stringResult->value=str1;
                      result->structType=stringResult;
                      break;
                  }
                  break ;

          default: printf("internal error");
      }
      return (struct ast *)result;
}

struct ast * mul(struct ast* value1, struct ast* value2){
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
      char * str1;
      char * str2;
      char * stres;
      int mult; char *stringa;

      switch(value1->nodetype){
          case 'I' :
                  intValue1=malloc(sizeof(struct integerType));
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      intResult=malloc(sizeof(struct integerType));
                      intValue2=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res= intValue1->value * intValue2->value ;
                      result->nodetype='I';
                      intResult->value=res;
                      result->structType=intResult;
                      free(intValue1);
                      free(intValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      dbres= intValue1->value * realValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(intValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      stringResult=malloc(sizeof(struct stringType));
                      int mult=intValue1->value;
                      char *stringa=strdup(stringValue1->value);
                      stringa=strmul(stringa,mult);
                      result->nodetype='S';
                      stringResult->value=stringa;
                      result->structType=stringResult;
                      free(intValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
                  }
                  break ;
          case 'R' :
                  realValue1=malloc(sizeof(struct realType));
                  val1=(struct value *)value1;
                  realValue1=(struct realType *)val1->structType;
                  realResult=malloc(sizeof(struct realType));
                  switch(value2->nodetype){
                    case 'I' :
                      intValue1=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      dbres=realValue1->value * (double)intValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(realValue1);
                      free(intValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realValue2=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= realValue1->value * realValue2->value;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(realValue1);
                      free(realValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      stringResult=malloc(sizeof(struct stringType));
                      mult=(int)realValue1->value;
                      stringa=strdup(stringValue1->value);
                      stringa=strmul(stringa,mult);
                      result->nodetype='S';
                      stringResult->value=stringa;
                      result->structType=stringResult;
                      free(stringValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                  }
                  break ;
          case 'S' :
                  stringValue1=malloc(sizeof(struct stringType));
                  val1=(struct value *)value1;
                  stringValue1=(struct stringType *)val1->structType;
                  stringResult=malloc(sizeof(struct stringType));
                  switch(value2->nodetype){
                    case 'I' :
                      intValue1=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      mult=intValue1->value;
                      stringa=strdup(stringValue1->value);
                      stringa=strmul(stringa,mult);
                      result->nodetype='S';
                      stringResult->value=stringa;
                      result->structType=stringResult;
                      free(intValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      mult=(int)realValue1->value;
                      stringa=strdup(stringValue1->value);
                      stringa=strmul(stringa,mult);
                      result->nodetype='S';
                      stringResult->value=stringa;
                      result->structType=stringResult;
                      free(stringValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      yyerror("invalid operation.. cannot mul string with string type ");
                      exit(1);
                      break;
                  }
                  break ;

          default: printf("internal error");
      }
      return (struct ast *)result;
}


struct ast *rdiv(struct ast* value1, struct ast* value2){
      struct value *val1= malloc(sizeof(struct value));
      struct value *val2= malloc(sizeof(struct value));
      struct value *result= malloc(sizeof(struct value));
      struct integerType *intValue1;
      struct integerType *intValue2;
      struct realType *realValue1;
      struct realType *realValue2;
      struct realType *realResult;
      double dbres;
      switch(value1->nodetype){
          case 'I' :
                  intValue1=malloc(sizeof(struct integerType));
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      realResult=malloc(sizeof(struct realType));
                      intValue2=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      dbres= (double)intValue1->value / (double)intValue2->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(intValue1);
                      free(intValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      realValue2=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= (double)intValue1->value / realValue2->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(intValue1);
                      free(realValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      yyerror("invalid operation.. String cannot div with double type ");
                      exit(1);
                      break;
                  }
                  break ;

          case 'R' :
                  realValue1=malloc(sizeof(struct realType));
                  val1=(struct value *)value1;
                  realValue1=(struct realType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      realResult=malloc(sizeof(struct realType));
                      intValue2=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      dbres= realValue1->value / (double)intValue2->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(realValue1);
                      free(intValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      realValue2=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= realValue1->value / realValue2->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(realValue1);
                      free(realValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      yyerror("invalid operation.. String cannot div with double type ");
                      exit(1);
                  }
                  result->nodetype='R';
                  realResult->value=dbres;
                  result->structType=realResult;
                  break ;
          
          case 'S' :
                yyerror("invalid operation.. String cannot div ");
                exit(1);

          default: printf("internal error");
      }
      return (struct ast *)result;
}

struct ast * sub(struct ast* value1, struct ast* value2){
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
      char * str1;
      char * str2;
      char * stres;

      switch(value1->nodetype){
          case 'I' :
                  intValue1=malloc(sizeof(struct integerType));
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      intResult=malloc(sizeof(struct integerType));
                      intValue2=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res= intValue1->value - intValue2->value ;
                      result->nodetype='I';
                      intResult->value=res;
                      result->structType=intResult;
                      free(intValue1);
                      free(intValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      dbres= intValue1->value - realValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(intValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      realResult=malloc(sizeof(struct realType));
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      dbres= intValue1->value - atof(stringValue1->value) ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      free(intValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
                  }
                  break ;

          case 'R' :
                  realValue1=malloc(sizeof(struct realType));
                  val1=(struct value *)value1;
                  realValue1=(struct realType *)val1->structType;
                  realResult=malloc(sizeof(struct realType));
                  switch(value2->nodetype){
                    case 'I' :
                      intValue1=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      dbres= realValue1->value - (double)intValue1->value ;
                      free(realValue1);
                      free(intValue1);
                      free(val1);
                      free(val2);
                      break;
                    case 'R' :
                      realValue2=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= realValue1->value - realValue2->value ;
                      free(realValue1);
                      free(realValue2);
                      free(val1);
                      free(val2);
                      break;
                    case 'S' :
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      dbres= realValue1->value - atof(stringValue1->value+1) ;
                      free(realValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
                  }
                  result->nodetype='R';
                  realResult->value=dbres;
                  result->structType=realResult;
                  break ;
          
          case 'S' :
                  yyerror("Cannot substract string type");
                  exit(1);
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
                    printf("%d", intero);
                    free(i);
                    break;
        case 'R' :
                    r=malloc(sizeof(struct realType));
                    a=(struct value *)val;
                    r=(struct realType *)a->structType;
                    double reale= r->value;
                    printf("%g", reale);
                    free(r);
                    break;
        case 'S' :
                    s=malloc(sizeof(struct stringType));
                    a=(struct value *)val;
                    s=(struct stringType *)a->structType;
                    char * stringa=s->value;
                    printf("%s", stringa);
                    free(s);
                    break;   

        default: printf("Error");
    }
}

void println(struct ast *val){
  print(val); 
  printf("\n");
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
  printf("> ");
  return yyparse();
}