#  define _GNU_SOURCE
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <math.h>
#  include "ast.h"
#  include "operations.h"
#  include "rasp.h"

char *clearString(char *str) {
    char *result;
    result=strndup(str+1, strlen(str)-2);
    return result;
}

char *strmul(char *str, int n) {
    int len = (strlen(str)*n)+1;
    char *result=malloc(sizeof(char)*len);
    if(!str || n<=0){
      return "";
    }
    for(int i=0; i<n; i++){
        strcat(result, str);
    }
    free(str);
    return result;
}

struct ast *orr(struct ast *value1, struct ast *value2) {
      struct value *val1;
      struct value *val2;
      struct value *result;
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
              val1=(struct value *)value1;
              intValue1=(struct integerType *)val1->structType;
              switch(value2->nodetype) {
                case 'I':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res=(intValue1->value || intValue2->value);
                      break;
                case 'R':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res=(intValue1->value || realValue1->value);
                      break;
                case 'S':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res=(intValue1->value || stringValue1->value);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        case 'R':
              val1=(struct value *)value1;
              realValue1=(struct realType *)val1->structType;
              switch(value2->nodetype) {
                case 'I':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      res=(realValue1->value || intValue1->value);
                      break;
                case 'R':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      res=(realValue1->value || realValue2->value);
                      break;
                case 'S':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res=(realValue1->value || stringValue1->value);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        case 'S':
              val1=(struct value *)value1;
              stringValue1=(struct stringType *)val1->structType;
              switch(value2->nodetype) {
                case 'I':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      res=(stringValue1->value || intValue1->value);
                      break;
                case 'R':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res=(stringValue1->value || realValue1->value);
                      break;
                case 'S':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue2=(struct stringType *)val2->structType;
                      res=(stringValue1->value || stringValue2->value);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        default: printf("Internal error"); exit(1);
      }
      return (struct ast *)result;
}

struct ast *and(struct ast *value1, struct ast *value2) {
      struct value *val1;
      struct value *val2;
      struct value *result;
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
              val1=(struct value *)value1;
              intValue1=(struct integerType *)val1->structType;
              switch(value2->nodetype) {
                case 'I':
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res=(intValue1->value && intValue2->value);
                      break;
                case 'R':
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res=(intValue1->value && realValue1->value);
                      break;
                case 'S':
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res=(intValue1->value && stringValue1->value);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        case 'R':
              val1=(struct value *)value1;
              realValue1=(struct realType *)val1->structType;
              switch(value2->nodetype) {
                case 'I':
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      res=(realValue1->value && intValue1->value);
                      break;
                case 'R':
                      intResult=malloc(sizeof(struct integerType));
                      result= malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      res=(realValue1->value && realValue2->value);
                      break;
                case 'S':
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      res=(realValue1->value && stringValue1->value);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        case 'S':
              val1=(struct value *)value1;
              stringValue1=(struct stringType *)val1->structType;
              switch(value2->nodetype) {
                case 'I':
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      res=(stringValue1->value && intValue1->value);
                      break;
                case 'R':
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      res=(stringValue1->value && realValue1->value);
                      break;
                case 'S':
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue2=(struct stringType *)val2->structType;
                      res=(stringValue1->value && stringValue2->value);
                      break;
              }
              result->nodetype='I';
              intResult->value=res;
              result->structType=intResult;
              break;

        default: printf("Internal error"); exit(1);
      }
      return (struct ast *)result;
}

struct ast *not(struct ast *tree) {
  struct value *a;
  struct value *temp;
  struct integerType *i;
  struct realType *r;
  struct stringType *s;
  struct integerType *intResult;
  int inresult;

  switch(tree->nodetype) {
    case 'I' :
          intResult=malloc(sizeof(struct integerType));
          a=malloc(sizeof(struct value));      
          temp=(struct value *)tree;
          i=(struct integerType *)temp->structType;
          inresult=!(i->value);
          break;
    case 'R' :
          intResult=malloc(sizeof(struct integerType));
          a=malloc(sizeof(struct value));      
          temp=(struct value *)tree;
          r=(struct realType *)temp->structType;
          inresult=!(r->value);
          break;
    case 'S' :
          intResult=malloc(sizeof(struct integerType));
          a=malloc(sizeof(struct value));      
          temp=(struct value *)tree;
          s=(struct stringType *)temp->structType;
          inresult=!(s->value);
          break;
    default:
        printf("Internal error"); 
        exit(1);
  }
  intResult->value=inresult;
  a->nodetype='I';
  a->structType=intResult;

  return (struct ast* )a;
}

struct ast *negateValue(struct ast *tree) {
  struct value * a;
  struct value * temp;
  struct integerType *i;
  struct realType *r;
  struct realType *rres;
  struct integerType *ires;
  switch(tree->nodetype){
    case 'I' :  
          a=malloc(sizeof(struct value));
          temp=(struct value *)tree;
          i=(struct integerType *)temp->structType;
          ires=malloc(sizeof(struct integerType));
          ires->value=i->value*(-1);
          a->nodetype='I';
          a->structType=ires;
          break;
    case 'R' :
          temp=(struct value *)tree;
          a=malloc(sizeof(struct value));
          r=(struct realType *)temp->structType;
          ires=malloc(sizeof(struct realType));
          rres->value=r->value*(-1);
          a->nodetype='R';
          a->structType=rres;
          break;
    case 'S' :
          yyerror("Cannot negate String");
          exit(1);
          break;
    default: 
        printf("Internal error"); 
        exit(1);
  }
  return (struct ast* )a;
}

struct ast *compare(int type, struct ast *l, struct ast *r){
      struct value *val1;
      struct value *val2;
      struct value *result;
      struct integerType *intResult;
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
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    intResult=malloc(sizeof(struct integerType));
                    result=malloc(sizeof(struct value));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value > intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    intResult=malloc(sizeof(struct integerType));
                    result=malloc(sizeof(struct value));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value > realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
                break;
              case 'R':
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value > intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value > realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
                break;
              case 'S':
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'S':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) > strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                }
                break;
            }
            break;
        /*Cambio case e vado nel minore*/
        case 2:
            switch(l->nodetype){
              case 'I':
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value < intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value < realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
                break;
              case 'R':
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value < intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value < realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
                break;
              case 'S':
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'S':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) < strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                }
                break;
            }
            break;
        /*FINE CASO MINORE*/
        /*Cambio !=*/
        case 3:
            switch(l->nodetype){
              case 'I':
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value != intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value != realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
                break;
              case 'R':
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value != intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value != realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
                break;
              case 'S':
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'S':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) != strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                }
                break;
            }
            break;
        /*FINE CASO !=*/
        /* CASO == */
        case 4:
            switch(l->nodetype){
              case 'I':
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value == intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value == realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
                break;
              case 'R':
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value == intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value == realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
                break;
              case 'S':
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'S':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strcmp(stringValue1->value, stringValue2->value) == 0 ? 1 : 0);
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                }
                break;
            }
            break;
        /*FINE CASO ==*/
        /* CASO >= */
        case 5:
            switch(l->nodetype){
              case 'I':
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value >= intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value >= realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
                break;
              case 'R':
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value >= intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value >= realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
                break;
              case 'S':
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'S':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) >= strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                }
                break;
            }
            break;
        /*FINE CASO ==*/
        /* CASO >= */
        case 6:
            switch(l->nodetype){
              case 'I':
                val1=(struct value*)l;
                intValue1=(struct integerType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (intValue1->value <= intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (intValue1->value <= realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare IntegerType to StringType");
                    exit(1);
                }
                break;
              case 'R':
                val1=(struct value*)l;
                realValue1=(struct realType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    intValue2=(struct integerType *)val2->structType;
                    res = (realValue1->value <= intValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'R':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    realValue2=(struct realType *)val2->structType;
                    res = (realValue1->value <= realValue2->value)? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                  case 'S':
                    yyerror("Cannot compare realType to StringType");
                    exit(1);
                }
                break;
              case 'S':
                val1=(struct value*)l;
                stringValue1=(struct stringType *)val1->structType;
                switch(r->nodetype){
                  case 'I':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'R':
                    yyerror("Cannot compare  StringType to IntegerType");
                    exit(1);
                  case 'S':
                    result=malloc(sizeof(struct value));
                    intResult=malloc(sizeof(struct integerType));
                    val2=(struct value*)r;
                    stringValue2=(struct stringType *)val2->structType;
                    res = (strlen(stringValue1->value) <= strlen(stringValue2->value))? 1 : 0;
                    result->nodetype='I';
                    intResult->value=res;
                    result->structType=intResult;
                    break;
                }
                break;
            }
            break;
        /*FINE CASO <=*/
      }
      return (struct ast *)result;
}

struct ast *sum(struct ast *value1, struct ast *value2) {
      struct value *val1;
      struct value *val2;
      struct value *result;
      struct integerType *intValue1;
      struct integerType *intValue2;
      struct integerType *intResult;
      int len;
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
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      result=malloc(sizeof(struct value));
                      intResult=malloc(sizeof(struct integerType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res=intValue1->value + intValue2->value ;
                      result->nodetype='I';
                      intResult->value=res;
                      result->structType=intResult;
                      break;
                    case 'R' :
                      result=malloc(sizeof(struct value));
                      realResult=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      dbres= intValue1->value + realValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'S' :
                      result=malloc(sizeof(struct value));
                      stringResult=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      asprintf(&str1, "%d", intValue1->value);
                      len = (strlen(str1) + strlen(stringValue1->value)+1);
                      stres=malloc(sizeof(char)*len);
                      strcat(stres, str1);
                      strcat(stres, stringValue1->value);
                      stringResult->value=stres;
                      result->nodetype='S';
                      result->structType=stringResult;
                      break;
                  }
                  break ;

          case 'R' :
                  val1=(struct value *)value1;
                  realValue1=(struct realType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      dbres= realValue1->value + (double)intValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= realValue1->value + realValue2->value;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'S' :
                      result=malloc(sizeof(struct value));
                      stringResult=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      asprintf(&str1, "%g", realValue1->value);
                      len = (strlen(str1) + strlen(stringValue1->value) +1);
                      stres=malloc(sizeof(char)*len);
                      strcat(stres, str1);
                      strcat(stres, stringValue1->value);
                      stringResult->value=stres;
                      result->nodetype='S';
                      result->structType=stringResult;
                      break;
                  }
                  break ;
          
          case 'S' :
                  val1=(struct value *)value1;
                  stringValue1=(struct stringType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      result=malloc(sizeof(struct value));
                      stringResult=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      stres=strdup(stringValue1->value);
                      asprintf(&str1, "%d", intValue1->value);
                      len = (strlen(str1) + strlen(stringValue1->value) +1);
                      stres=malloc(sizeof(char)*len);
                      strcat(stres, stringValue1->value);
                      strcat(stres, str1);
                      stringResult->value=stres;
                      result->nodetype='S';
                      result->structType=stringResult;
                      break;
                    case 'R' :
                      result=malloc(sizeof(struct value));
                      stringResult=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      stres=strdup(stringValue1->value);
                      asprintf(&str1, "%g", realValue1->value);
                      len = (strlen(str1) + strlen(stringValue1->value) +1);
                      stres=malloc(sizeof(char)*len);
                      strcat(stres, stringValue1->value);
                      strcat(stres, str1);
                      stringResult->value=stres;
                      result->nodetype='S';
                      result->structType=stringResult;
                      break;
                    case 'S' :
                      result=malloc(sizeof(struct value));
                      stringResult=malloc(sizeof(struct stringType));
                      val2=(struct value *)value2;
                      stringValue2=(struct stringType *)val2->structType;
                      str1=strdup(stringValue1->value);
                      str2=strdup(stringValue2->value);
                      len = (strlen(str1) + strlen(str2) + 1);
                      stres=malloc(sizeof(char)*len);
                      strcat(stres,str1);
                      strcat(stres, str2);
                      result->nodetype='S';
                      stringResult->value=stres;
                      result->structType=stringResult;
                      break;
                  }
                  break ;

          default: printf("Internal error"); exit(1);
      }
      return (struct ast *)result;
}

struct ast *sub(struct ast *value1, struct ast *value2) {
      struct value *val1;
      struct value *val2;
      struct value *result;
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
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res= intValue1->value - intValue2->value ;
                      result->nodetype='I';
                      intResult->value=res;
                      result->structType=intResult;
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      dbres= intValue1->value - realValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'S' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      dbres= intValue1->value - atof(stringValue1->value) ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                  }
                  break ;

          case 'R' :
                  val1=(struct value *)value1;
                  realValue1=(struct realType *)val1->structType;
                  realResult=malloc(sizeof(struct realType));
                  switch(value2->nodetype){
                    case 'I' :
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      dbres= realValue1->value - (double)intValue1->value ;
                      break;
                    case 'R' :
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= realValue1->value - realValue2->value ;
                      break;
                    case 'S' :
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      dbres= realValue1->value - atof(stringValue1->value);
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

          default: printf("Internal error"); exit(1);
      }

      return (struct ast *)result;
}

struct ast *mul(struct ast *value1, struct ast *value2) {
      struct value *val1;
      struct value *val2;
      struct value *result;
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
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      res= intValue1->value * intValue2->value ;
                      result->nodetype='I';
                      intResult->value=res;
                      result->structType=intResult;
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      dbres= intValue1->value * realValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'S' :
                      stringResult=malloc(sizeof(struct stringType));
                      result=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      int mult=intValue1->value;
                      char *stringa=strdup(stringValue1->value);
                      stringa=strmul(stringa,mult);
                      result->nodetype='S';
                      stringResult->value=stringa;
                      result->structType=stringResult;
                      break;
                  }
                  break ;
          case 'R' :
                  val1=(struct value *)value1;
                  realValue1=(struct realType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      dbres=realValue1->value * (double)intValue1->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= realValue1->value * realValue2->value;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'S' :
                      stringResult=malloc(sizeof(struct stringType));
                      result=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      mult=(int)realValue1->value;
                      stringa=strdup(stringValue1->value);
                      stringa=strmul(stringa,mult);
                      result->nodetype='S';
                      stringResult->value=stringa;
                      result->structType=stringResult;
                  }
                  break ;
          case 'S' :
                  val1=(struct value *)value1;
                  stringValue1=(struct stringType *)val1->structType;
                  stringResult=malloc(sizeof(struct stringType));
                  switch(value2->nodetype){
                    case 'I' :
                      result=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      mult=intValue1->value;
                      stringa=strdup(stringValue1->value);
                      stringa=strmul(stringa,mult);
                      result->nodetype='S';
                      stringResult->value=stringa;
                      result->structType=stringResult;
                      break;
                    case 'R' :
                      result=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      mult=(int)realValue1->value;
                      stringa=strdup(stringValue1->value);
                      stringa=strmul(stringa,mult);
                      result->nodetype='S';
                      stringResult->value=stringa;
                      result->structType=stringResult;
                      break;
                    case 'S' :
                      yyerror("invalid operation.. cannot mul string with string type ");
                      exit(1);
                      break;
                  }
                  break ;

          default: printf("Internal error"); exit(1);
      }
      return (struct ast *)result;
}

struct ast *rdiv(struct ast *value1, struct ast *value2) {
      struct value *val1;
      struct value *val2;
      struct value *result;
      struct integerType *intValue1;
      struct integerType *intValue2;
      struct realType *realValue1;
      struct realType *realValue2;
      struct realType *realResult;
      double dbres;
      switch(value1->nodetype){
          case 'I' :
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      dbres= (double)intValue1->value / (double)intValue2->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= (double)intValue1->value / realValue2->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'S' :
                      yyerror("invalid operation.. String cannot div with double type ");
                      exit(1);
                      break;
                  }
                  break ;

          case 'R' :
                  val1=(struct value *)value1;
                  realValue1=(struct realType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      dbres= realValue1->value / (double)intValue2->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      dbres= realValue1->value / realValue2->value ;
                      result->nodetype='R';
                      realResult->value=dbres;
                      result->structType=realResult;
                      break;
                    case 'S' :
                      yyerror("invalid operation.. String cannot div with double type ");
                      exit(1);
                      break;
                  }
                  result->nodetype='R';
                  realResult->value=dbres;
                  result->structType=realResult;
                  break ;
          
          case 'S' :
                yyerror("invalid operation.. String cannot div ");
                exit(1);
                break;

          default: printf("Internal error"); exit(1);
      }
      return (struct ast *)result;
}

struct ast *mod(struct ast *value1, struct ast *value2) {
      struct value *val1;
      struct value *val2;
      struct value *result;
      struct integerType *intValue1;
      struct integerType *intValue2;
      struct integerType *intResult;
      int inres;
      switch(value1->nodetype){
          case 'I' :
                  val1=(struct value *)value1;
                  intValue1=(struct integerType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      intResult=malloc(sizeof(struct integerType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      inres=(intValue1->value) % (intValue2->value);
                      result->nodetype='I';
                      intResult->value=inres;
                      result->structType=intResult;
                      break;
                    case 'R' :
                      yyerror("invalid operation.. Integer cannot mod with Real type ");
                      exit(1);
                    case 'S' :
                      yyerror("invalid operation.. Integer cannot mod with String type ");
                      exit(1);
                  }
                  break ;

          case 'R' :
                yyerror("invalid operation.. Real cannot mod ");
                exit(1);
          
          case 'S' :
                yyerror("invalid operation.. String cannot mod ");
                exit(1);

          default: printf("Internal error"); exit(1);
      }
      return (struct ast *)result;
}

struct ast *abss(struct ast *tree) {
  struct value *a;
  struct value *temp;
  struct integerType *i;
  struct realType *r;
  struct integerType *ires;
  struct realType *rres;
  int inresult; 
  double dbresult;
  switch(tree->nodetype) {
    case 'I' :
          a=malloc(sizeof(struct value));
          temp=(struct value *)tree;
          i=(struct integerType *)temp->structType;
          ires=malloc(sizeof(struct integerType));
          ires->value=abs(i->value);
          a->nodetype='I';
          a->structType=ires;
          break;
    case 'R' :
          a=malloc(sizeof(struct value));
          temp=(struct value *)tree;
          r=(struct realType *)temp->structType;
          rres=malloc(sizeof(struct realType));
          rres->value=fabs(r->value);
          a->nodetype='R';
          a->structType=rres;
          break;
    case 'S' :
          yyerror("Cannot negate String");
          exit(1);
          break;
    default: 
        printf("Internal error"); 
        exit(1);
  }
  return (struct ast* )a;
}

