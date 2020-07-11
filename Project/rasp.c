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

#define GPIO 1
#define SPI 2
#define I2C 3
#define UART 4

extern int edu;

int controlPin(int pin) {
    int res;
    switch(pin) {
        case 2: res = I2C; break;
        case 3: res = I2C; break;
        case 4: res = GPIO; break;
        case 17: res = GPIO; break;
        case 27: res = GPIO; break;
        case 22: res = GPIO; break;
        case 10: res = SPI; break;
        case 9: res = SPI; break;
        case 11: res = SPI; break;
        case 0: res = I2C; break;
        case 5: res = GPIO; break;
        case 6: res = GPIO; break;
        case 13: res = GPIO; break;
        case 19: res = SPI; break;
        case 26: res = GPIO; break;
        case 14: res = UART; break;
        case 15: res = UART; break;
        case 18: res = GPIO; break;
        case 23: res = GPIO; break;
        case 24: res = GPIO; break;
        case 25: res = GPIO; break;
        case 8: res = SPI; break;
        case 7: res = SPI; break;
        case 1: res = I2C; break;
        case 12: res = GPIO; break;
        case 16: res = GPIO; break;
        case 20: res = SPI; break;
        case 21: res = SPI; break;
        default: res = 0; break;
    }
    return res;
}

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
        default: {
            yyerror("CONVERT-PIN: Undefined Pin, or power supply pin");
            exit(1);
        }
    }
    return res;
}

void status(void) {
    system("gpio readall");
    fflush(stdout);
}

void ledRGB(struct ast *pin, struct ast *channel) {
    if((pin != NULL) && (channel != NULL)) {
        struct value *v1=(struct value *)pin;
        struct value *v2=(struct value *)channel;
        if((v1->nodetype == 'I') && (v2->nodetype == 'I')) {
            struct integerType *i=(struct integerType *)v1->structType;
            struct integerType *c=(struct integerType *)v2->structType;
            if((controlPin(i->value) != GPIO) && (edu == 1)) {
                if(controlPin(i->value) == SPI)
                    yyerror("SPI PIN SELECTED");
                else if(controlPin(i->value) == I2C)
                    yyerror("I2C PIN SELECTED");
                else if(controlPin(i->value) == UART)
                    yyerror("UART PIN SELECTED");
                else
                    yyerror("Undefined Pin, or power supply pin");
                exit(1);
            }else {
                if(wiringPiSetup() == -1) { //when initialize wiringPi failed, print message to screen
                    yyerror("Setup wiringPi failed!");
                    exit(1);
                }
                if((c->value >= 0) && (c->value <= 100)) {
                    softPwmCreate(convertPin(i->value), 0, 100);
                    softPwmWrite(convertPin(i->value), c->value); //[0, 100]
                }else {
                    yyerror("LED-RGB: Unknown channel!");
                }
            }
        }else {
            yyerror("LED-RGB: Incompatible type!");
        }
    }else {
		yyerror("LED-RGB: Argument not defined");
	}
}

void setOutPin(struct ast *pin, struct ast *mode) {
    if((pin != NULL) && (mode != NULL)) {
        struct value *v1=(struct value *)pin;
        struct value *v2=(struct value *)mode;
        if((v1->nodetype == 'I') && (v2->nodetype == 'S')) {
            struct integerType *i=(struct integerType *)v1->structType;
            struct stringType *s=(struct stringType *)v2->structType;
            if((controlPin(i->value) != GPIO) && (edu == 1)) {
                if(controlPin(i->value) == SPI)
                    yyerror("SPI PIN SELECTED");
                else if(controlPin(i->value) == I2C)
                    yyerror("I2C PIN SELECTED");
                else if(controlPin(i->value) == UART)
                    yyerror("UART PIN SELECTED");
                else
                    yyerror("Undefined Pin, or power supply pin");
                exit(1);
            }else {
                if(wiringPiSetup() == -1) { //when initialize wiringPi failed, print message to screen
                    yyerror("Setup wiringPi failed!");
                    exit(1);
                }
                pinMode(convertPin(i->value), OUTPUT);
                if(strcmp(s->value, "HIGH") == 0)
                    digitalWrite(convertPin(i->value), HIGH);  //led on
                else if(strcmp(s->value, "LOW") == 0)
                    digitalWrite(convertPin(i->value), LOW);  //led off
                else
                    yyerror("SET-OUT-PIN: Incompatible mode!");
            }
        }else {
            yyerror("SET-OUT-PIN: Incompatible type!");
        }
    }else {
		yyerror("SET-OUT-PIN: Argument not defined");
	}
}

struct ast *button(struct ast *pin) {
    if(pin != NULL) {
        struct value *v1=(struct value *)pin;
        if(v1->nodetype == 'I') {
            struct integerType *i=(struct integerType *)v1->structType;
            if((controlPin(i->value) != GPIO) && (edu == 1)) {
                if(controlPin(i->value) == SPI)
                    yyerror("SPI PIN SELECTED");
                else if(controlPin(i->value) == I2C)
                    yyerror("I2C PIN SELECTED");
                else if(controlPin(i->value) == UART)
                    yyerror("UART PIN SELECTED");
                else
                    yyerror("Undefined Pin, or power supply pin");
                exit(1);
            }else {
                if(wiringPiSetup() == -1) { //when initialize wiringPi failed, print message to screen
                    yyerror("Setup wiringPi failed!");
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
            }
        }else {
            yyerror("BUTTON: Incompatible type!");
        }
    }else {
		yyerror("BUTTON: Argument not defined");
	}
}

#define I2C_ADDR 0x27       // I2C device address
#define LCD_CHR 1           // Mode - Sending data
#define LCD_CMD 0           // Mode - Sending command
#define LINE1 0x80          // 1st line
#define LINE2 0xC0          // 2nd line
#define LCD_BACKLIGHT 0x08  // On
#define ENABLE 0b00000100   // Enable bit

int fd;

void lcd_toggle_enable(int bits) {
    // Toggle enable pin on LCD display
    delayMicroseconds(500);
    wiringPiI2CReadReg8(fd, (bits | ENABLE));
    delayMicroseconds(500);
    wiringPiI2CReadReg8(fd, (bits & ~ENABLE));
    delayMicroseconds(500);
}

void lcd_byte(int bits, int mode) {
    //Send byte to data pins
    // bits = the data
    // mode = 1 for data, 0 for command
    int bits_high;
    int bits_low;
    // uses the two half byte writes to LCD
    bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT ;
    bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT ;
    // High bits
    wiringPiI2CReadReg8(fd, bits_high);
    lcd_toggle_enable(bits_high);
    // Low bits
    wiringPiI2CReadReg8(fd, bits_low);
    lcd_toggle_enable(bits_low);
}

void lcd_init(void) {
    if(wiringPiSetup() == -1) { //when initialize wiringPi failed, print message to screen
        yyerror("Setup wiringPi failed!");
        exit(1);
    }
    fd = wiringPiI2CSetup(I2C_ADDR);
    if(fd < 0) {
        yyerror("Setup wiringPiI2C failed!");
        exit(1);
    }
    // Initialise display
    lcd_byte(0x33, LCD_CMD); // Initialise
    lcd_byte(0x32, LCD_CMD); // Initialise
    lcd_byte(0x06, LCD_CMD); // Cursor move direction
    lcd_byte(0x0C, LCD_CMD); // 0x0F On, Blink Off
    lcd_byte(0x28, LCD_CMD); // Data length, number of lines, font size
    lcd_byte(0x01, LCD_CMD); // Clear display
    delayMicroseconds(500);
}

void sendIntegerLcd(struct ast *integer) {
    if(integer != NULL) {
        struct value *v=(struct value *)integer;
        if(v->nodetype == 'I') {
            struct integerType *i=(struct integerType *)v->structType;
            char *str;
            asprintf(&str, "%d", i->value);
            struct value *res=malloc(sizeof(struct value));
            struct stringType *sres=malloc(sizeof(struct stringType));
            sres->value=str;
            res->nodetype='S';
            res->structType=sres;
            sendStringLcd((struct ast *)res);
        }else {
            yyerror("SEND-INTEGER: Incompatible type!");
        }
    }else {
		yyerror("SET-INTEGER: Argument not defined");
	}
}

void sendRealLcd(struct ast *real) {
    if(real != NULL) {
        struct value *v=(struct value *)real;
        if(v->nodetype == 'R') {
            struct realType *r=(struct realType *)v->structType;
            char *str;
            asprintf(&str, "%g", r->value);
            struct value *res=malloc(sizeof(struct value));
            struct stringType *sres=malloc(sizeof(struct stringType));
            sres->value=str;
            res->nodetype='S';
            res->structType=sres;
            sendStringLcd((struct ast *)res);
        }else {
            yyerror("SEND-REAL: Incompatible type!");
        }
    }else {
		yyerror("SEND-REAL: Argument not defined");
	}
}

void sendStringLcd(struct ast *string) {
    if(string != NULL) {
        struct value *v=(struct value *)string;
        if(v->nodetype == 'S') {
            struct stringType *s=(struct stringType *)v->structType;
            char *str=strdup(s->value);
            while(*str) lcd_byte(*(str++), LCD_CHR);
        }else {
            yyerror("SEND-STRING: Incompatible type!");
        }
    }else {
		yyerror("SEND-STRING: Argument not defined");
	}
}

void lcdLoc(struct ast *line) {
    if(line != NULL) {
        struct value *v=(struct value *)line;
        if(v->nodetype == 'S') {
            struct stringType *s=(struct stringType *)v->structType;
            if(strcmp(s->value, "LINE1") == 0)
                lcd_byte(LINE1, LCD_CMD);
            else if(strcmp(s->value, "LINE2") == 0)
                lcd_byte(LINE2, LCD_CMD);
            else
                yyerror("LINE-LCD: Incompatible LINE!");
        }else {
            yyerror("LINE-LCD: Incompatible type!");
        }
    }
    else {
		yyerror("LINE-LCD: Argument not defined");
	}	
}

void clrLcd(void) {
    lcd_byte(0x01, LCD_CMD);
    lcd_byte(0x02, LCD_CMD);
}
