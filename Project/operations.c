#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <math.h>
#  include "ast.h"
#  include "operations.h"

char *clearString(char *str) {
    char * result;
    result=strndup(str+1, strlen(str)-2);
    return result;
}

char *strmul(char *str, int n) {
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

struct ast *orr(struct ast* value1, struct ast* value2) {
      struct value *val1= malloc(sizeof(struct value));
      struct value *val2= malloc(sizeof(struct value));
      struct value *result= malloc(sizeof(struct value));
      struct integerType *intValue1;
      struct integerType *intValue2;
      struct integerType *intResult;
      struct realType *realValue1;
      struct realType *realValue2;
      struct stringType *stringValue1;
      struct stringType *stringValue2;
      int res;
      
      switch(value1->nodetype) {
        case 'I':
              intValue1=malloc(sizeof(struct integerType));
              val1=(struct value *)value1;
              intValue1=(struct integerType *)val1->structType;
              intResult=malloc(sizeof(struct integerType));
              switch(value2->nodetype) {
                case 'I':
                      intValue2=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res=(intValue1->value || intValue2->value);
                      free(intValue1);
                      free(intValue2);
                      free(val1);
                      free(val2);
                      break;
                case 'R':
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res=(intValue1->value || realValue1->value);
                      free(intValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                case 'S':
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res=(intValue1->value || stringValue1->value);
                      free(intValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        case 'R':
              realValue1=malloc(sizeof(struct realType));
              val1=(struct value *)value1;
              realValue1=(struct realType *)val1->structType;
              intResult=malloc(sizeof(struct integerType));
              switch(value2->nodetype) {
                case 'I':
                      intValue1=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      res=(realValue1->value || intValue1->value);
                      free(realValue1);
                      free(intValue1);
                      free(val1);
                      free(val2);
                      break;
                case 'R':
                      realValue2=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      res=(realValue1->value || realValue2->value);
                      free(realValue1);
                      free(realValue2);
                      free(val1);
                      free(val2);
                      break;
                case 'S':
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res=(realValue1->value || stringValue1->value);
                      free(realValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        case 'S':
              stringValue1=malloc(sizeof(struct stringType));
              val1=(struct value *)value1;
              stringValue1=(struct stringType *)val1->structType;
              intResult=malloc(sizeof(struct integerType));
              switch(value2->nodetype) {
                case 'I':
                      intValue1=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      res=(stringValue1->value || intValue1->value);
                      free(stringValue1);
                      free(intValue1);
                      free(val1);
                      free(val2);
                      break;
                case 'R':
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res=(stringValue1->value || realValue1->value);
                      free(stringValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                case 'S':
                      stringValue2=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue2=(struct stringType *)val2->structType;
                      res=(stringValue1->value || stringValue2->value);
                      free(stringValue1);
                      free(stringValue2);
                      free(val1);
                      free(val2);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        default: printf("internal error");
      }
      return (struct ast *)result;
}

struct ast *and(struct ast* value1, struct ast* value2) {
      struct value *val1= malloc(sizeof(struct value));
      struct value *val2= malloc(sizeof(struct value));
      struct value *result= malloc(sizeof(struct value));
      struct integerType *intValue1;
      struct integerType *intValue2;
      struct integerType *intResult;
      struct realType *realValue1;
      struct realType *realValue2;
      struct stringType *stringValue1;
      struct stringType *stringValue2;
      int res;
      
      switch(value1->nodetype) {
        case 'I':
              intValue1=malloc(sizeof(struct integerType));
              val1=(struct value *)value1;
              intValue1=(struct integerType *)val1->structType;
              intResult=malloc(sizeof(struct integerType));
              switch(value2->nodetype) {
                case 'I':
                      intValue2=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res=(intValue1->value && intValue2->value);
                      free(intValue1);
                      free(intValue2);
                      free(val1);
                      free(val2);
                      break;
                case 'R':
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res=(intValue1->value && realValue1->value);
                      free(intValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                case 'S':
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res=(intValue1->value && stringValue1->value);
                      free(intValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        case 'R':
              realValue1=malloc(sizeof(struct realType));
              val1=(struct value *)value1;
              realValue1=(struct realType *)val1->structType;
              intResult=malloc(sizeof(struct integerType));
              switch(value2->nodetype) {
                case 'I':
                      intValue1=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      res=(realValue1->value && intValue1->value);
                      free(realValue1);
                      free(intValue1);
                      free(val1);
                      free(val2);
                      break;
                case 'R':
                      realValue2=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      res=(realValue1->value && realValue2->value);
                      free(realValue1);
                      free(realValue2);
                      free(val1);
                      free(val2);
                      break;
                case 'S':
                      stringValue1=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res=(realValue1->value && stringValue1->value);
                      free(realValue1);
                      free(stringValue1);
                      free(val1);
                      free(val2);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        case 'S':
              stringValue1=malloc(sizeof(struct stringType));
              val1=(struct value *)value1;
              stringValue1=(struct stringType *)val1->structType;
              intResult=malloc(sizeof(struct integerType));
              switch(value2->nodetype) {
                case 'I':
                      intValue1=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      res=(stringValue1->value && intValue1->value);
                      free(stringValue1);
                      free(intValue1);
                      free(val1);
                      free(val2);
                      break;
                case 'R':
                      realValue1=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res=(stringValue1->value && realValue1->value);
                      free(stringValue1);
                      free(realValue1);
                      free(val1);
                      free(val2);
                      break;
                case 'S':
                      stringValue2=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue2=(struct stringType *)val2->structType;
                      res=(stringValue1->value && stringValue2->value);
                      free(stringValue1);
                      free(stringValue2);
                      free(val1);
                      free(val2);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        default: printf("internal error");
      }
      return (struct ast *)result;
}

struct ast *negateValue(struct ast *tree) {
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

struct ast *compare(int type, struct ast *l, struct ast *r) {
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

struct ast *sum(struct ast *value1, struct ast *value2) {
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
                      res=intValue1->value + intValue2->value ;
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

struct ast *sub(struct ast *value1, struct ast *value2) {
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

struct ast *mul(struct ast *value1, struct ast *value2) {
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

struct ast *rdiv(struct ast *value1, struct ast *value2) {
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
