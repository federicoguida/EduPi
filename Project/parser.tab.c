/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

#  include <stdio.h>
#  include <stdlib.h>
#  include "ast.h"
#  include "operations.h"

#line 78 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 188 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STR = 3,                        /* STR  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_RL = 5,                         /* RL  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_REAL = 7,                       /* REAL  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_PRINT = 9,                      /* PRINT  */
  YYSYMBOL_PRINTLN = 10,                   /* PRINTLN  */
  YYSYMBOL_TIME = 11,                      /* TIME  */
  YYSYMBOL_NAME = 12,                      /* NAME  */
  YYSYMBOL_FUNC = 13,                      /* FUNC  */
  YYSYMBOL_EOL = 14,                       /* EOL  */
  YYSYMBOL_LST = 15,                       /* LST  */
  YYSYMBOL_PERI = 16,                      /* PERI  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_CONTINUE = 22,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 23,                     /* BREAK  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_DEF = 25,                       /* DEF  */
  YYSYMBOL_ADDOP = 26,                     /* ADDOP  */
  YYSYMBOL_SUBOP = 27,                     /* SUBOP  */
  YYSYMBOL_MULOP = 28,                     /* MULOP  */
  YYSYMBOL_DIVOP = 29,                     /* DIVOP  */
  YYSYMBOL_ABSOP = 30,                     /* ABSOP  */
  YYSYMBOL_OROP = 31,                      /* OROP  */
  YYSYMBOL_ANDOP = 32,                     /* ANDOP  */
  YYSYMBOL_NOTOP = 33,                     /* NOTOP  */
  YYSYMBOL_INCR = 34,                      /* INCR  */
  YYSYMBOL_DECR = 35,                      /* DECR  */
  YYSYMBOL_LPAREN = 36,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 37,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 38,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 39,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 40,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 41,                    /* RBRACE  */
  YYSYMBOL_SEMI = 42,                      /* SEMI  */
  YYSYMBOL_DOT = 43,                       /* DOT  */
  YYSYMBOL_COMMA = 44,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 45,                    /* ASSIGN  */
  YYSYMBOL_CMP = 46,                       /* CMP  */
  YYSYMBOL_MODOP = 47,                     /* MODOP  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_if_statement = 52,              /* if_statement  */
  YYSYMBOL_for_statement = 53,             /* for_statement  */
  YYSYMBOL_while_statement = 54,           /* while_statement  */
  YYSYMBOL_do_while_statement = 55,        /* do_while_statement  */
  YYSYMBOL_tail = 56,                      /* tail  */
  YYSYMBOL_exp = 57,                       /* exp  */
  YYSYMBOL_declaration = 58,               /* declaration  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_init = 60,                      /* init  */
  YYSYMBOL_value = 61,                     /* value  */
  YYSYMBOL_value_list = 62,                /* value_list  */
  YYSYMBOL_functionV = 63,                 /* functionV  */
  YYSYMBOL_functionR = 64                  /* functionR  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    59,    62,    63,    64,    65,    66,    67,
      68,    69,    72,    73,    76,    79,    82,    85,    86,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   109,   110,   111,   114,   115,   116,   119,
     120,   121,   122,   123,   124,   128,   129,   130,   131,   134,
     135,   138,   139,   142
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STR", "INT", "RL",
  "INTEGER", "REAL", "STRING", "PRINT", "PRINTLN", "TIME", "NAME", "FUNC",
  "EOL", "LST", "PERI", "IF", "ELSE", "DO", "WHILE", "FOR", "CONTINUE",
  "BREAK", "RETURN", "DEF", "ADDOP", "SUBOP", "MULOP", "DIVOP", "ABSOP",
  "OROP", "ANDOP", "NOTOP", "INCR", "DECR", "LPAREN", "RPAREN", "LBRACK",
  "RBRACK", "LBRACE", "RBRACE", "SEMI", "DOT", "COMMA", "ASSIGN", "CMP",
  "MODOP", "UMINUS", "$accept", "program", "statement", "if_statement",
  "for_statement", "while_statement", "do_while_statement", "tail", "exp",
  "declaration", "type", "init", "value", "value_list", "functionV",
  "functionR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,    92,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -30,
     -29,   -14,    46,     7,     8,    -9,    -8,    -5,     3,    57,
      57,    57,    57,   -65,   -65,   -65,   -65,   -65,   -17,     1,
      48,    16,   -65,    20,   -65,    57,    57,    30,   -65,   -65,
     143,    31,   -65,    57,   126,    57,    74,   -65,   -65,    25,
     -65,   137,    57,    57,    57,    57,    57,    57,   -65,    57,
      57,   -65,    38,   -65,   -65,   159,   166,   -65,    57,   246,
      50,   188,   126,    69,   195,    46,   102,   103,    75,   -65,
     -65,    77,    77,   -65,   -65,   181,    19,   253,   -65,    57,
     -65,   -65,   246,   -26,    57,    76,   -65,    98,    80,    31,
      38,    57,   246,   -65,    57,   -16,   126,    85,   126,   217,
     246,   -65,    82,    57,    86,    74,   108,   224,   -65,   107,
      99,   106,   100,   126,   -65,   126,   111,   116,   -65,   -65
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    37,    36,    38,    46,    47,    48,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     0,     0,
       0,     0,    31,     0,    32,     0,     0,     0,    41,    42,
       0,    34,    35,     0,    17,     0,     0,    45,    30,     0,
      27,     0,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     8,    33,     9,    11,     0,     0,    53,     0,    40,
       0,     0,    17,     0,     0,     0,     0,     0,     0,    28,
      29,    20,    21,    22,    23,    25,    26,    19,    24,     0,
      51,    52,    50,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    39,    44,     0,     0,    17,     0,    17,     0,
      49,    43,     0,     0,     0,     0,    12,     0,    15,     0,
       0,     0,     0,    17,    16,    17,     0,     0,    13,    14
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   157,   -65,   -65,   -65,   -65,   -64,   -19,   -65,
     -42,   -41,   -65,    66,   -65,   -65
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    72,    24,    25,    26,    27,    73,    28,    29,
      30,    31,    32,    93,    33,    34
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    49,    50,    51,    77,    78,    35,    36,    96,    52,
      53,    54,    55,   103,    56,    57,    65,    66,   104,    41,
      42,    69,    37,   111,    71,    58,    74,    43,   104,    59,
      60,    45,    44,    81,    82,    83,    84,    85,    86,    46,
      87,    88,   112,    61,   114,    52,    53,    54,    55,    92,
      56,    52,    53,    54,    55,    79,    56,    57,    63,   126,
      62,   127,    64,     6,     7,     8,    60,    67,    11,    47,
     102,    59,    60,    77,   119,    92,    70,     3,     4,     5,
      38,    39,   109,    89,    19,   110,    75,    20,    94,    76,
      21,    40,     2,    22,   117,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    54,    55,    13,    14,    15,
      97,    16,    17,    18,    99,   100,   106,   101,   107,    19,
     108,   113,    20,   116,    60,    21,   120,   118,    22,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   123,
     125,    13,    14,    15,   122,    16,    17,    18,   124,     6,
       7,     8,   128,    19,    11,    47,    20,   129,    23,    21,
     105,     0,    22,    52,    53,    54,    55,     0,    56,    57,
      19,     0,     0,    20,    80,     0,    21,     0,     0,    22,
       0,    68,     0,    59,    60,    52,    53,    54,    55,     0,
      56,    57,    52,    53,    54,    55,    90,    56,    57,     0,
       0,     0,     0,    91,     0,    59,    60,    52,    53,    54,
      55,     0,    59,    60,    52,    53,    54,    55,     0,    56,
      57,    52,    53,    54,    55,    95,    56,    57,    60,     0,
       0,     0,    98,     0,    59,    60,     0,     0,     0,     0,
       0,    59,    60,    52,    53,    54,    55,     0,    56,    57,
      52,    53,    54,    55,     0,    56,    57,     0,     0,   115,
       0,   121,     0,    59,    60,     0,     0,     0,     0,     0,
      59,    60,    52,    53,    54,    55,     0,    56,    57,    52,
      53,    54,    55,     0,    56,    57,     0,     0,     0,     0,
       0,     0,    59,    60,     0,     0,     0,     0,     0,    -1,
      60
};

static const yytype_int8 yycheck[] =
{
      19,    20,    21,    22,    46,    46,    36,    36,    72,    26,
      27,    28,    29,    39,    31,    32,    35,    36,    44,    12,
      12,    40,    36,    39,    43,    42,    45,    36,    44,    46,
      47,    36,    40,    52,    53,    54,    55,    56,    57,    36,
      59,    60,   106,    42,   108,    26,    27,    28,    29,    68,
      31,    26,    27,    28,    29,    30,    31,    32,    42,   123,
      12,   125,    42,     6,     7,     8,    47,    37,    11,    12,
      89,    46,    47,   115,   115,    94,    45,     3,     4,     5,
      34,    35,   101,    45,    27,   104,    12,    30,    38,    15,
      33,    45,     0,    36,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    28,    29,    15,    16,    17,
      41,    19,    20,    21,    12,    12,    40,    42,    20,    27,
      40,    36,    30,    41,    47,    33,    18,    41,    36,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    40,
      40,    15,    16,    17,    37,    19,    20,    21,    42,     6,
       7,     8,    41,    27,    11,    12,    30,    41,     1,    33,
      94,    -1,    36,    26,    27,    28,    29,    -1,    31,    32,
      27,    -1,    -1,    30,    37,    -1,    33,    -1,    -1,    36,
      -1,    38,    -1,    46,    47,    26,    27,    28,    29,    -1,
      31,    32,    26,    27,    28,    29,    37,    31,    32,    -1,
      -1,    -1,    -1,    37,    -1,    46,    47,    26,    27,    28,
      29,    -1,    46,    47,    26,    27,    28,    29,    -1,    31,
      32,    26,    27,    28,    29,    37,    31,    32,    47,    -1,
      -1,    -1,    37,    -1,    46,    47,    -1,    -1,    -1,    -1,
      -1,    46,    47,    26,    27,    28,    29,    -1,    31,    32,
      26,    27,    28,    29,    -1,    31,    32,    -1,    -1,    42,
      -1,    37,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      46,    47,    26,    27,    28,    29,    -1,    31,    32,    26,
      27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    46,
      47
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    50,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    15,    16,    17,    19,    20,    21,    27,
      30,    33,    36,    51,    52,    53,    54,    55,    57,    58,
      59,    60,    61,    63,    64,    36,    36,    36,    34,    35,
      45,    12,    12,    36,    40,    36,    36,    12,    57,    57,
      57,    57,    26,    27,    28,    29,    31,    32,    42,    46,
      47,    42,    12,    42,    42,    57,    57,    37,    38,    57,
      45,    57,    51,    56,    57,    12,    15,    59,    60,    30,
      37,    57,    57,    57,    57,    57,    57,    57,    57,    45,
      37,    37,    57,    62,    38,    37,    56,    41,    37,    12,
      12,    42,    57,    39,    44,    62,    40,    20,    40,    57,
      57,    39,    56,    36,    56,    42,    41,    57,    41,    60,
      18,    37,    37,    40,    42,    40,    56,    56,    41,    41
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    54,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    64
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     2,     2,
       2,     2,     7,    11,    11,     7,     9,     0,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     2,     2,     2,     1,     1,     1,     4,
       3,     2,     2,     6,     5,     1,     1,     1,     1,     3,
       1,     4,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3:
#line 59 "parser.y"
                    { evaluate((yyvsp[0].a)); }
#line 1352 "parser.tab.c"
    break;

  case 4:
#line 62 "parser.y"
                        { }
#line 1358 "parser.tab.c"
    break;

  case 5:
#line 63 "parser.y"
                { }
#line 1364 "parser.tab.c"
    break;

  case 6:
#line 64 "parser.y"
                  { }
#line 1370 "parser.tab.c"
    break;

  case 7:
#line 65 "parser.y"
                     { }
#line 1376 "parser.tab.c"
    break;

  case 8:
#line 66 "parser.y"
                   { }
#line 1382 "parser.tab.c"
    break;

  case 9:
#line 67 "parser.y"
            { }
#line 1388 "parser.tab.c"
    break;

  case 10:
#line 68 "parser.y"
           { }
#line 1394 "parser.tab.c"
    break;

  case 11:
#line 69 "parser.y"
                 { }
#line 1400 "parser.tab.c"
    break;

  case 12:
#line 72 "parser.y"
                                                      { (yyval.a)=newflow('F', (yyvsp[-4].a), (yyvsp[-1].a), NULL, NULL); }
#line 1406 "parser.tab.c"
    break;

  case 13:
#line 73 "parser.y"
                                                                  { (yyval.a)=newflow('F', (yyvsp[-8].a), (yyvsp[-5].a), (yyvsp[-1].a), NULL); }
#line 1412 "parser.tab.c"
    break;

  case 14:
#line 76 "parser.y"
                                                                            { (yyval.a)=newflow('Q', (yyvsp[-6].a), (yyvsp[-1].a), (yyvsp[-4].a), (yyvsp[-8].a)); }
#line 1418 "parser.tab.c"
    break;

  case 15:
#line 79 "parser.y"
                                                            { (yyval.a)=newflow('W', (yyvsp[-4].a), (yyvsp[-1].a), NULL, NULL); }
#line 1424 "parser.tab.c"
    break;

  case 16:
#line 82 "parser.y"
                                                                       { (yyval.a)=newflow('D', (yyvsp[-2].a), (yyvsp[-6].a), NULL, NULL); }
#line 1430 "parser.tab.c"
    break;

  case 17:
#line 85 "parser.y"
      { (yyval.a) = NULL; }
#line 1436 "parser.tab.c"
    break;

  case 18:
#line 86 "parser.y"
                 { { if ((yyvsp[0].a) == NULL)
	                (yyval.a) = (yyvsp[-1].a);
                      else
			(yyval.a) = newast('Z', (yyvsp[-1].a), (yyvsp[0].a));
                    } }
#line 1446 "parser.tab.c"
    break;

  case 19:
#line 93 "parser.y"
                 { (yyval.a) = newast((yyvsp[-1].fn) ,(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1452 "parser.tab.c"
    break;

  case 20:
#line 94 "parser.y"
                { (yyval.a) = newast('+',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1458 "parser.tab.c"
    break;

  case 21:
#line 95 "parser.y"
                {(yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1464 "parser.tab.c"
    break;

  case 22:
#line 96 "parser.y"
                { (yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1470 "parser.tab.c"
    break;

  case 23:
#line 97 "parser.y"
                { (yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1476 "parser.tab.c"
    break;

  case 24:
#line 98 "parser.y"
                { (yyval.a) = newast('%', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1482 "parser.tab.c"
    break;

  case 25:
#line 99 "parser.y"
               {(yyval.a) = newast('O',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1488 "parser.tab.c"
    break;

  case 26:
#line 100 "parser.y"
                {(yyval.a) = newast('A',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1494 "parser.tab.c"
    break;

  case 27:
#line 101 "parser.y"
            { (yyval.a) = newast('N', (yyvsp[0].a), NULL); }
#line 1500 "parser.tab.c"
    break;

  case 28:
#line 102 "parser.y"
                  { (yyval.a) = newast('|', (yyvsp[-1].a), NULL); }
#line 1506 "parser.tab.c"
    break;

  case 29:
#line 103 "parser.y"
                    { (yyval.a)=(yyvsp[-1].a); }
#line 1512 "parser.tab.c"
    break;

  case 30:
#line 104 "parser.y"
                         { (yyval.a) = newast('M',(yyvsp[0].a),NULL); }
#line 1518 "parser.tab.c"
    break;

  case 33:
#line 109 "parser.y"
                       { (yyval.a) = newsymdecl((yyvsp[-1].type), (yyvsp[0].s));}
#line 1524 "parser.tab.c"
    break;

  case 34:
#line 110 "parser.y"
           { (yyval.a) = newsymdecl((yyvsp[-1].i), (yyvsp[0].s)); }
#line 1530 "parser.tab.c"
    break;

  case 35:
#line 111 "parser.y"
            { (yyval.a) = newsymdecl((yyvsp[-1].i), (yyvsp[0].s)); }
#line 1536 "parser.tab.c"
    break;

  case 39:
#line 119 "parser.y"
                           { (yyval.a) = newasgn((yyvsp[-3].type), (yyvsp[-2].s), (yyvsp[0].a)); }
#line 1542 "parser.tab.c"
    break;

  case 40:
#line 120 "parser.y"
                  { (yyval.a) = newsasgn((yyvsp[-2].s), (yyvsp[0].a)); }
#line 1548 "parser.tab.c"
    break;

  case 41:
#line 121 "parser.y"
            { (yyval.a) = newinc('P', (yyvsp[-1].s)); }
#line 1554 "parser.tab.c"
    break;

  case 42:
#line 122 "parser.y"
            { (yyval.a) = newinc('E', (yyvsp[-1].s)); }
#line 1560 "parser.tab.c"
    break;

  case 43:
#line 123 "parser.y"
                                           { }
#line 1566 "parser.tab.c"
    break;

  case 44:
#line 124 "parser.y"
                                       { }
#line 1572 "parser.tab.c"
    break;

  case 45:
#line 128 "parser.y"
            { (yyval.a) = newref((yyvsp[0].s)); }
#line 1578 "parser.tab.c"
    break;

  case 46:
#line 129 "parser.y"
          { (yyval.a) = newInteger('I', (yyvsp[0].i)); }
#line 1584 "parser.tab.c"
    break;

  case 47:
#line 130 "parser.y"
       { (yyval.a)= newReal('R', (yyvsp[0].r)); }
#line 1590 "parser.tab.c"
    break;

  case 48:
#line 131 "parser.y"
         { (yyval.a)= newString('S', (yyvsp[0].string)); }
#line 1596 "parser.tab.c"
    break;

  case 49:
#line 134 "parser.y"
                                 { }
#line 1602 "parser.tab.c"
    break;

  case 50:
#line 135 "parser.y"
      { }
#line 1608 "parser.tab.c"
    break;

  case 51:
#line 138 "parser.y"
                                   { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a)); }
#line 1614 "parser.tab.c"
    break;

  case 52:
#line 139 "parser.y"
                            { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a)); }
#line 1620 "parser.tab.c"
    break;

  case 53:
#line 142 "parser.y"
                              { (yyval.a) = date(); }
#line 1626 "parser.tab.c"
    break;


#line 1630 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 149 "parser.y"

