/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STR = 258,
    INT = 259,
    RL = 260,
    INTEGER = 261,
    REAL = 262,
    STRING = 263,
    PRINT = 264,
    PRINTLN = 265,
    SCAN = 266,
    TIME = 267,
    SLP = 268,
    TYPE = 269,
    SQRT = 270,
    POW = 271,
    POP = 272,
    PUSH = 273,
    APP = 274,
    DEL = 275,
    INS = 276,
    GET = 277,
    SIZE = 278,
    SEARCH = 279,
    LED = 280,
    RGB = 281,
    BUTT = 282,
    NAME = 283,
    LST = 284,
    PERI = 285,
    IF = 286,
    ELSE = 287,
    DO = 288,
    WHILE = 289,
    FOR = 290,
    RETURN = 291,
    DEF = 292,
    IN = 293,
    ARR = 294,
    ID = 295,
    ADDOP = 296,
    SUBOP = 297,
    MULOP = 298,
    DIVOP = 299,
    ABSOP = 300,
    OROP = 301,
    ANDOP = 302,
    NOTOP = 303,
    INCR = 304,
    DECR = 305,
    CNC = 306,
    LPAREN = 307,
    RPAREN = 308,
    LBRACK = 309,
    RBRACK = 310,
    LBRACE = 311,
    RBRACE = 312,
    SEMI = 313,
    DOT = 314,
    COMMA = 315,
    ASSIGN = 316,
    CMP = 317,
    MODOP = 318,
    UMINUS = 319
  };
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
    struct funclist *fl; /* Lista di funzioni */
    int fn; /* Indicherà quale funzione */
    int type;
    struct listexp *l;

#line 136 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
