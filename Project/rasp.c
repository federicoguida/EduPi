#  define _GNU_SOURCE
#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <math.h>
#  include "ast.h"
#  include "operations.h"
#  include "rasp.h"
#  include <wiringPi.h>
#  include <wiringPiI2C.h>
#  include <softPwm.h>

int convertPin(int Pin) {
    int res;
    switch(Pin) {
        case 2: res = 8; break;
        case 3: res = 9; break;
        case 4: res = 7; break;
        case 17: res = 0; break;
        case 27: res = 2; break;
        case 22: res = 3; break;
        case 10: res = 12; break;
        case 9: res = 13; break;
        case 11: res = 14; break;
        case 0: res = 30; break;
        case 5: res = 21; break;
        case 6: res = 22; break;
        case 13: res = 23; break;
        case 19: res = 24; break;
        case 26: res = 25; break;
        case 14: res = 15; break;
        case 15: res = 16; break;
        case 18: res = 1; break;
        case 23: res = 4; break;
        case 24: res = 5; break;
        case 25: res = 6; break;
        case 8: res = 10; break;
        case 7: res = 11; break;
        case 1: res = 31; break;
        case 12: res = 26; break;
        case 16: res = 27; break;
        case 20: res = 28; break;
        case 21: res = 29; break;
        default:
            yyerror("undefined Pin!");
            exit(1);
    }
    return res;
}

void ledRGB(struct ast *pin, struct ast *channel) {
    if((pin != NULL) && (channel != NULL)) {
        struct value *v1=(struct value *)pin;
        struct value *v2=(struct value *)channel;
        if((v1->nodetype == 'I') && (v2->nodetype == 'I')) {
            struct integerType *i=(struct integerType *)v1->structType;
            struct integerType *c=(struct integerType *)v2->structType;
            if(wiringPiSetup() == -1) { //when initialize wiringPi failed, print message to screen
                yyerror("setup wiringPi failed!");
                exit(1);
            }
            if((c->value >= 0) && (c->value <= 100)) {
                softPwmCreate(convertPin(i->value), 0, 100);
                softPwmWrite(convertPin(i->value), c->value); //[0, 100]
            }else {
                yyerror("unknown channel!");
            }
        }else {
            yyerror("incompatible type!");
        }
    }else {
		yyerror("argument not defined");
	}
}

void setOutPin(struct ast *pin, struct ast *mode) {
    if((pin != NULL) && (mode != NULL)) {
        struct value *v1=(struct value *)pin;
        struct value *v2=(struct value *)mode;
        if((v1->nodetype == 'I') && (v2->nodetype == 'S')) {
            struct integerType *i=(struct integerType *)v1->structType;
            struct stringType *s=(struct stringType *)v2->structType;
            if(wiringPiSetup() == -1) { //when initialize wiringPi failed, print message to screen
                yyerror("setup wiringPi failed!");
                exit(1);
            }
            pinMode(convertPin(i->value), OUTPUT);
            if(strcmp(s->value, "HIGH") == 0)
                digitalWrite(convertPin(i->value), HIGH);  //led on
            else if(strcmp(s->value, "LOW") == 0)
                digitalWrite(convertPin(i->value), LOW);  //led off
            else
                yyerror("incompatible mode!");
        }else {
            yyerror("incompatible type!");
        }
    }else {
		yyerror("argument not defined");
	}
}

struct ast *button(struct ast *pin) {
    if(pin != NULL) {
        struct value *v1=(struct value *)pin;
        if(v1->nodetype == 'I') {
            struct integerType *i=(struct integerType *)v1->structType;
            if(wiringPiSetup() == -1) { //when initialize wiringPi failed, print message to screen
                yyerror("setup wiringPi failed!");
                exit(1);
            }
            pinMode(convertPin(i->value), INPUT);
            pullUpDnControl(convertPin(i->value), PUD_UP);
            struct value *res=malloc(sizeof(struct value));
            struct integerType *inres=malloc(sizeof(struct integerType));
            inres->value=(digitalRead(convertPin(i->value)) == LOW);
            res->nodetype='I';
            res->structType=inres;
            return (struct ast *)res;
        }else {
            yyerror("incompatible type!");
        }
    }else {
		yyerror("argument not defined");
	}
}

void buzz(struct ast *pin, struct ast *mode) {
    if((pin != NULL) && (mode != NULL)) {
        struct value *v1=(struct value *)pin;
        struct value *v2=(struct value *)mode;
        if((v1->nodetype == 'I') && (v2->nodetype == 'S')) {
            struct integerType *i=(struct integerType *)v1->structType;
            struct stringType *s=(struct stringType *)v2->structType;
            if(wiringPiSetup() == -1) { //when initialize wiringPi failed, print message to screen
                yyerror("setup wiringPi failed!");
                exit(1);
            }
            pinMode(convertPin(i->value), OUTPUT);
            if(strcmp(s->value, "ON") == 0)
                digitalWrite(convertPin(i->value), HIGH);  //led on
            else if(strcmp(s->value, "OFF") == 0)
                digitalWrite(convertPin(i->value), LOW);  //led off
            else
                yyerror("incompatible mode!");
        }else {
            yyerror("incompatible type!");
        }
    }else {
		yyerror("argument not defined");
	}
}







