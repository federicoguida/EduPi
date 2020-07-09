#  define _GNU_SOURCE
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <math.h>
#  include "ast.h"
#  include "operations.h"
#  include "rasp.h"

char *clearString(char *str) {
    char *result = strndup(str+1, strlen(str)-2);
    return result;
}

struct ast *operation(int op, struct ast* value1, struct ast* value2) {
  if((value1 != NULL) && (value2 != NULL)) {
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
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue2=(struct integerType *)val2->structType;
                      switch(op){
                      case '+' : res=intValue1->value + intValue2->value ; break;
                      case '-' : res=intValue1->value - intValue2->value ; break;
                      case '*' : res=intValue1->value * intValue2->value ; break;
                      case '/' : dbres= (double)intValue1->value / (double)intValue2->value ; break;
                      case '%' : res=intValue1->value % intValue2->value ; break;
                      case 'O' : res=intValue1->value || intValue2->value ; break;
                      case 'A' : res=intValue1->value && intValue2->value ; break;
                      case 1   : res = (intValue1->value > intValue2->value)? 1 : 0; break;
                      case 2   : res = (intValue1->value < intValue2->value)? 1 : 0; break;
                      case 3   : res = (intValue1->value != intValue2->value)? 1 : 0; break;
                      case 4   : res = (intValue1->value == intValue2->value)? 1 : 0; break;
                      case 5   : res = (intValue1->value >= intValue2->value)? 1 : 0; break;
                      case 6   : res = (intValue1->value <= intValue2->value)? 1 : 0; break;
                      }
                      if(op=='/'){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
                      break;
                    case 'R' :
                      result=malloc(sizeof(struct value));
                      realResult=malloc(sizeof(struct realType));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      switch(op){
                      case '+' : dbres=intValue1->value + realValue1->value ; break;
                      case '-' : dbres=intValue1->value - realValue1->value ; break;
                      case '*' : dbres=intValue1->value * realValue1->value ; break;
                      case '/' : dbres=intValue1->value / realValue1->value ; break;
                      case '%' : printf("Operation is not supported : Type %c mod Type %c\n", value1->nodetype, value2->nodetype ); return NULL; break;
                      case 'O' : res=intValue1->value || realValue1->value ; break;
                      case 'A' : res=intValue1->value && realValue1->value ; break;
                      case 1   : res = (intValue1->value > realValue1->value)? 1 : 0; break;
                      case 2   : res = (intValue1->value < realValue1->value)? 1 : 0; break;
                      case 3   : res = (intValue1->value != realValue1->value)? 1 : 0; break;
                      case 4   : res = (intValue1->value == realValue1->value)? 1 : 0; break;
                      case 5   : res = (intValue1->value >= realValue1->value)? 1 : 0; break;
                      case 6   : res = (intValue1->value <= realValue1->value)? 1 : 0; break;
                      }
                      if(op!='O' && op!='A' && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
                      break;
                    case 'S' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      switch(op){
                      case '+' : dbres= intValue1->value + atof(stringValue1->value) ; break;
                      case '-' : dbres= intValue1->value - atof(stringValue1->value) ; break;
                      case '*' : dbres= intValue1->value * atof(stringValue1->value) ; break;
                      case '/' : dbres= intValue1->value / atof(stringValue1->value) ; break;
                      case '%' : printf("Operation is not supported : Type %c mod Type %c\n", value1->nodetype, value2->nodetype ); return NULL;  break;
                      case 'O' : res=intValue1->value || atof(stringValue1->value); break;
                      case 'A' : res=intValue1->value && atof(stringValue1->value); break;
                      case 1   : res = (intValue1->value > strlen(stringValue1->value))? 1 : 0; break;
                      case 2   : res = (intValue1->value < strlen(stringValue1->value))? 1 : 0; break;
                      case 3   : res = (intValue1->value != strlen(stringValue1->value))? 1 : 0; break;
                      case 4   : res = (intValue1->value == strlen(stringValue1->value))? 1 : 0; break;
                      case 5   : res = (intValue1->value >= strlen(stringValue1->value))? 1 : 0; break;
                      case 6   : res = (intValue1->value <= strlen(stringValue1->value))? 1 : 0; break;
                      }
                      if(op!='O' && op!='A' && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
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
                      switch(op){
                      case '+' : dbres= realValue1->value + intValue1->value ; break;
                      case '-' : dbres= realValue1->value - intValue1->value ; break;
                      case '*' : dbres= realValue1->value * intValue1->value ; break;
                      case '/' : dbres= realValue1->value / intValue1->value ; break;
                      case '%' : printf("Operation is not supported : Type %c mod Type %c\n", value1->nodetype, value2->nodetype ); return NULL;  break;
                      case 'O' : res=realValue1->value || intValue1->value; break;
                      case 'A' : res=realValue1->value && intValue1->value; break; 
                      case 1   : res = (realValue1->value > intValue1->value)? 1 : 0; break;
                      case 2   : res = (realValue1->value < intValue1->value)? 1 : 0; break;
                      case 3   : res = (realValue1->value != intValue1->value)? 1 : 0; break;
                      case 4   : res = (realValue1->value == intValue1->value)? 1 : 0; break;
                      case 5   : res = (realValue1->value >= intValue1->value)? 1 : 0; break;
                      case 6   : res = (realValue1->value <= intValue1->value)? 1 : 0; break;
                      }
                      if(op!='O' && op!='A' && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue2=(struct realType *)val2->structType;
                      switch(op){
                      case '+' : dbres= realValue1->value + realValue2->value; break;
                      case '-' : dbres= realValue1->value - realValue2->value; break;
                      case '*' : dbres= realValue1->value * realValue2->value; break;
                      case '/' : dbres= realValue1->value / realValue2->value; break;
                      case '%' : printf("Operation is not supported : Type %c mod Type %c\n", value1->nodetype, value2->nodetype ); return NULL;  break;
                      case 'O' : res=realValue1->value || realValue2->value; break;
                      case 'A' : res=realValue1->value && realValue2->value; break;
                      case 1   : res = (realValue1->value > realValue2->value)? 1 : 0; break;
                      case 2   : res = (realValue1->value < realValue2->value)? 1 : 0; break;
                      case 3   : res = (realValue1->value != realValue2->value)? 1 : 0; break;
                      case 4   : res = (realValue1->value == realValue2->value)? 1 : 0; break;
                      case 5   : res = (realValue1->value >= realValue2->value)? 1 : 0; break;
                      case 6   : res = (realValue1->value <= realValue2->value)? 1 : 0; break;
                      }
                      if(op!='O' && op!='A' && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
                      break;
                    case 'S' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue1=(struct stringType *)val2->structType;
                      switch(op){
                      case '+' : dbres= realValue1->value + atof(stringValue1->value) ; break;
                      case '-' : dbres= realValue1->value - atof(stringValue1->value) ; break;
                      case '*' : dbres= realValue1->value * atof(stringValue1->value) ; break;
                      case '/' : dbres= realValue1->value / atof(stringValue1->value) ; break;
                      case '%' : printf("Operation is not supported : Type %c mod Type %c\n", value1->nodetype, value2->nodetype ); return NULL;  break;
                      case 'O' : res=realValue1->value || atof(stringValue1->value); break;
                      case 'A' : res=realValue1->value && atof(stringValue1->value); break;
                      case 1   : res = (realValue1->value > strlen(stringValue1->value))? 1 : 0; break;
                      case 2   : res = (realValue1->value < strlen(stringValue1->value))? 1 : 0; break;
                      case 3   : res = (realValue1->value != strlen(stringValue1->value))? 1 : 0; break;
                      case 4   : res = (realValue1->value == strlen(stringValue1->value))? 1 : 0; break;
                      case 5   : res = (realValue1->value >= strlen(stringValue1->value))? 1 : 0; break;
                      case 6   : res = (realValue1->value <= strlen(stringValue1->value))? 1 : 0; break;
                      }
                      if(op!='O' && op!='A' && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
                      break;
                  }
                  break ;
          
          case 'S' :
                  val1=(struct value *)value1;
                  stringValue1=(struct stringType *)val1->structType;
                  switch(value2->nodetype){
                    case 'I' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      intValue1=(struct integerType *)val2->structType;
                      switch(op){
                      case '+' : dbres=  atof(stringValue1->value) + intValue1->value ; break;
                      case '-' : dbres=  atof(stringValue1->value) - intValue1->value ; break;
                      case '*' : dbres=  atof(stringValue1->value) * intValue1->value ; break;
                      case '/' : dbres=  atof(stringValue1->value) / intValue1->value ; break;
                      case '%' : printf("Operation is not supported : Type %c mod Type %c\n", value1->nodetype, value2->nodetype ); return NULL;  break;
                      case 'O' : res= atof(stringValue1->value) || intValue1->value; break;
                      case 'A' : res= atof(stringValue1->value) && intValue1->value; break;
                      case 1   : res = (strlen(stringValue1->value) > intValue1->value)? 1 : 0; break;
                      case 2   : res = (strlen(stringValue1->value) < intValue1->value)? 1 : 0; break;
                      case 3   : res = (strlen(stringValue1->value) != intValue1->value)? 1 : 0; break;
                      case 4   : res = (strlen(stringValue1->value) == intValue1->value)? 1 : 0; break;
                      case 5   : res = (strlen(stringValue1->value) >= intValue1->value)? 1 : 0; break;
                      case 6   : res = (strlen(stringValue1->value) <= intValue1->value)? 1 : 0; break;
                      }
                      if(op!='O' && op!='A' && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
                      break;
                    case 'R' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      realValue1=(struct realType *)val2->structType;
                      switch(op){
                      case '+' : dbres=  atof(stringValue1->value) + realValue1->value ; break;
                      case '-' : dbres=  atof(stringValue1->value) - realValue1->value ; break;
                      case '*' : dbres=  atof(stringValue1->value) * realValue1->value ; break;
                      case '/' : dbres=  atof(stringValue1->value) / realValue1->value ; break;
                      case '%' : printf("Operation is not supported : Type %c mod Type %c\n", value1->nodetype, value2->nodetype ); return NULL;  break;
                      case 'O' : res=   atof(stringValue1->value) ||  realValue1->value; break;
                      case 'A' : res=   atof(stringValue1->value) && realValue1->value; break;
                      case 1   : res = (strlen(stringValue1->value) > realValue1->value)? 1 : 0; break;
                      case 2   : res = (strlen(stringValue1->value) < realValue1->value)? 1 : 0; break;
                      case 3   : res = (strlen(stringValue1->value) != realValue1->value)? 1 : 0; break;
                      case 4   : res = (strlen(stringValue1->value) == realValue1->value)? 1 : 0; break;
                      case 5   : res = (strlen(stringValue1->value) >= realValue1->value)? 1 : 0; break;
                      case 6   : res = (strlen(stringValue1->value) <= realValue1->value)? 1 : 0; break;
                      }
                      if(op!='O' && op!='A' && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
                      break;
                    case 'S' :
                      realResult=malloc(sizeof(struct realType));
                      result=malloc(sizeof(struct value));
                      val2=(struct value *)value2;
                      stringValue2=(struct stringType *)val2->structType;
                      switch(op){
                      case '+' : dbres= atof(stringValue1->value) + atof(stringValue2->value) ; break;
                      case '-' : dbres= atof(stringValue1->value) - atof(stringValue2->value) ; break;
                      case '*' : dbres= atof(stringValue1->value) * atof(stringValue2->value) ; break;
                      case '/' : dbres= atof(stringValue1->value) / atof(stringValue2->value) ; break;
                      case '%' : printf("Operation is not supported : Type %c mod Type %c\n", value1->nodetype, value2->nodetype ); return NULL;  break;
                      case 'O' : res=atof(stringValue1->value) || atof(stringValue2->value) ; break;
                      case 'A' : res=atof(stringValue1->value) && atof(stringValue2->value) ; break;
                      case 1   : res = (strlen(stringValue1->value) > strlen(stringValue2->value))? 1 : 0; break;
                      case 2   : res = (strlen(stringValue1->value) < strlen(stringValue2->value))? 1 : 0; break;
                      case 3   : res = (strcmp(stringValue1->value, stringValue2->value))? 1 : 0; break;
                      case 4   : res = (strcmp(stringValue1->value, stringValue2->value))? 0 : 1; break;
                      case 5   : res = (strlen(stringValue1->value) >= strlen(stringValue2->value))? 1 : 0; break;
                      case 6   : res = (strlen(stringValue1->value) <= strlen(stringValue2->value))? 1 : 0; break;
                      }
                      if(op!='O' && op!='A' && op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6){
                        realResult=malloc(sizeof(struct realType));
                        result->nodetype='R';
                        realResult->value=dbres;
                        result->structType=realResult;
                      }else{
                      result->nodetype='I';
                      intResult=malloc(sizeof(struct integerType));
                      intResult->value=res;
                      result->structType=intResult;
                      }
                      break;
                  }
                  break;

          default: 
          if(op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6)
            yyerror("OPERATIONS-2: Operation is not supported : Type %c %c Type %c\n", value1->nodetype, op, value2->nodetype );
          else{
            yyerror("OPERATIONS-2: Operation is not supported : Type %c compare Type %c\n", value1->nodetype,value2->nodetype );
          }
          return NULL;

      }
      return (struct ast *)result;
    }else {
		    yyerror("OPERATIONS-2: Argument not defined");
		    return NULL;
	  }
}

struct ast *sop(int op, struct ast * tree) {
  if(tree != NULL) {
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
            switch(op){
                case '|' : ires->value=abs(i->value); break;
                case 'M' : ires->value=i->value*(-1); break;
                case 'N' : ires->value=!(i->value); break;
            }
            a->nodetype='I';
            a->structType=ires;
            break;
      case 'R' :
            temp=(struct value *)tree;
            a=malloc(sizeof(struct value));
            r=(struct realType *)temp->structType;
            ires=malloc(sizeof(struct realType));
            switch(op){
                case '|' : rres->value=fabs(r->value); break;
                case 'M' : rres->value=r->value*(-1); break;
                case 'N' : rres->value=!(r->value); break;
            }
            a->nodetype='R';
            a->structType=rres;
            break;
      case 'S' :
            switch(op){
                case '|' : yyerror("Cannot abs String"); return NULL; break;
                case 'M' : yyerror("Cannot negate String"); return NULL; break;
                case 'N' : ires->value=!(r->value); break;
            }
            a->nodetype='I';
            a->structType=ires;
            break;
      default: 
          yyerror("OPERATIONS-1: Operation %c is not supported : Type %c \n", op, tree->nodetype );
          return NULL;
    }
    return (struct ast* )a;
  }else {
		  yyerror("OPERATIONS-1: Argument not defined");
		  return NULL;
	}
}
