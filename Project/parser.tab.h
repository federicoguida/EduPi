/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STR = 258,                     /* STR  */
    INT = 259,                     /* INT  */
    RL = 260,                      /* RL  */
    INTEGER = 261,                 /* INTEGER  */
    REAL = 262,                    /* REAL  */
    STRING = 263,                  /* STRING  */
    PRINT = 264,                   /* PRINT  */
    PRINTLN = 265,                 /* PRINTLN  */
    TIME = 266,                    /* TIME  */
    NAME = 267,                    /* NAME  */
    FUNC = 268,                    /* FUNC  */
    EOL = 269,                     /* EOL  */
    LST = 270,                     /* LST  */
    PERI = 271,                    /* PERI  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    DO = 274,                      /* DO  */
    WHILE = 275,                   /* WHILE  */
    FOR = 276,                     /* FOR  */
    CONTINUE = 277,                /* CONTINUE  */
    BREAK = 278,                   /* BREAK  */
    RETURN = 279,                  /* RETURN  */
    DEF = 280,                     /* DEF  */
    ADDOP = 281,                   /* ADDOP  */
    SUBOP = 282,                   /* SUBOP  */
    MULOP = 283,                   /* MULOP  */
    DIVOP = 284,                   /* DIVOP  */
    ABSOP = 285,                   /* ABSOP  */
    OROP = 286,                    /* OROP  */
    ANDOP = 287,                   /* ANDOP  */
    NOTOP = 288,                   /* NOTOP  */
    INCR = 289,                    /* INCR  */
    DECR = 290,                    /* DECR  */
    LPAREN = 291,                  /* LPAREN  */
    RPAREN = 292,                  /* RPAREN  */
    LBRACK = 293,                  /* LBRACK  */
    RBRACK = 294,                  /* RBRACK  */
    LBRACE = 295,                  /* LBRACE  */
    RBRACE = 296,                  /* RBRACE  */
    SEMI = 297,                    /* SEMI  */
    DOT = 298,                     /* DOT  */
    COMMA = 299,                   /* COMMA  */
    ASSIGN = 300,                  /* ASSIGN  */
    CMP = 301,                     /* CMP  */
    MODOP = 302,                   /* MODOP  */
    UMINUS = 303                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "parser.y"

    struct ast *a; /*Struttura albero*/
    double r; /*Indicherà i reali*/
    int i; /*Indicherà gli interi*/
    char *string; /*Indicherà le stringhe*/
    struct peripheral *p; /*Indicherà la periferica*/
    struct symbol *s; /* Indicherà il simbolo */
    struct symlist *sl;  /* Lista di simboli */
    int fn; /* Indicherà quale funzione */
    int type;

#line 124 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
