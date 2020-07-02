/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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
int yylex();

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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
    TIME = 266,
    POP = 267,
    PUSH = 268,
    APP = 269,
    DEL = 270,
    INS = 271,
    NAME = 272,
    FUNC = 273,
    LST = 274,
    PERI = 275,
    IF = 276,
    ELSE = 277,
    DO = 278,
    WHILE = 279,
    FOR = 280,
    CONTINUE = 281,
    BREAK = 282,
    RETURN = 283,
    DEF = 284,
    ADDOP = 285,
    SUBOP = 286,
    MULOP = 287,
    DIVOP = 288,
    ABSOP = 289,
    OROP = 290,
    ANDOP = 291,
    NOTOP = 292,
    INCR = 293,
    DECR = 294,
    LPAREN = 295,
    RPAREN = 296,
    LBRACK = 297,
    RBRACK = 298,
    LBRACE = 299,
    RBRACE = 300,
    SEMI = 301,
    DOT = 302,
    COMMA = 303,
    ASSIGN = 304,
    CMP = 305,
    MODOP = 306,
    UMINUS = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "parser.y"

    struct ast *a; /*Struttura albero*/
    double r; /*Indicherà i reali*/
    int i; /*Indicherà gli interi*/
    char *string; /*Indicherà le stringhe*/
    struct peripheral *p; /*Indicherà la periferica*/
    struct symbol *s; /* Indicherà il simbolo */
    struct symlist *sl;  /* Lista di simboli */
    int fn; /* Indicherà quale funzione */
    int type;
    struct listexp *l;

#line 196 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   519

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

#define YYUNDEFTOK  2
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    62,    63,    66,    67,    68,    69,    70,
      71,    72,    73,    76,    77,    80,    83,    86,    89,    90,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   114,   115,   116,   119,   120,
     121,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     136,   137,   138,   139,   142,   143,   144,   145,   146,   149,
     150,   151,   154,   155,   156,   159,   160,   163,   164,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STR", "INT", "RL", "INTEGER", "REAL",
  "STRING", "PRINT", "PRINTLN", "TIME", "POP", "PUSH", "APP", "DEL", "INS",
  "NAME", "FUNC", "LST", "PERI", "IF", "ELSE", "DO", "WHILE", "FOR",
  "CONTINUE", "BREAK", "RETURN", "DEF", "ADDOP", "SUBOP", "MULOP", "DIVOP",
  "ABSOP", "OROP", "ANDOP", "NOTOP", "INCR", "DECR", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMI", "DOT", "COMMA", "ASSIGN",
  "CMP", "MODOP", "UMINUS", "$accept", "program", "statement",
  "if_statement", "for_statement", "while_statement", "do_while_statement",
  "tail", "exp", "declaration", "type", "init", "value", "functionV",
  "functionR", "explist", "value_list", "symlist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -88,   145,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -33,
     -17,   -15,     6,    16,    18,    20,    24,   -18,    -2,     1,
      26,    23,    28,    31,    52,   269,   269,   269,   269,   -88,
     -88,   -88,   -88,   -88,   -22,    27,    58,    37,   -88,    38,
     -88,   269,   269,    54,    76,    82,    95,   107,   110,   -88,
     -88,   269,   102,    80,   -88,   269,   183,   269,    99,    94,
      97,   -88,     3,   -88,    46,   269,   269,   269,   269,   269,
     269,   -88,   269,   269,   -88,    81,   -88,   -88,    90,   280,
     -88,   105,    87,   115,   119,   123,   454,   -29,   204,   454,
     257,   287,   183,    93,   309,    62,   126,   155,   127,   158,
     -88,   -88,    29,    29,   -88,   -88,    19,   468,   461,   -88,
     269,   -88,   -88,   -88,   269,   269,   269,   269,   -88,   269,
     -88,   316,   134,   219,   454,   136,   -88,   154,   137,    80,
      81,   269,   135,   143,   454,   338,   345,   367,   374,   454,
     269,   -88,   -88,   162,   183,   161,   183,   396,   158,   165,
     -88,   -88,   -88,   269,   -88,   -88,   168,   269,   173,    99,
     -88,   183,   403,   200,   425,   -88,   187,   196,   -88,   185,
     186,   189,   269,   183,   -88,   183,   432,   192,   194,   195,
     -88,   -88,   -88
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    39,    38,    40,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       5,     6,     7,     8,     0,     0,     0,     0,    32,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      44,    62,     0,    36,    37,     0,    18,     0,     0,     0,
      50,    31,     0,    28,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     9,    35,    10,    12,     0,     0,
      59,     0,     0,     0,     0,     0,    64,     0,     0,    42,
       0,     0,    18,     0,     0,     0,     0,     0,     0,    67,
      29,    30,    21,    22,    23,    24,    26,    27,    20,    25,
       0,    54,    55,    60,     0,     0,     0,     0,    34,     0,
      49,    66,     0,     0,    46,     0,    19,     0,     0,     0,
       0,     0,    68,     0,    41,     0,     0,     0,     0,    63,
       0,    48,    47,     0,    18,     0,    18,     0,    67,     0,
      58,    56,    61,     0,    65,    45,     0,     0,     0,     0,
      69,    18,     0,    13,     0,    16,     0,     0,    57,     0,
       0,     0,     0,    18,    17,    18,     0,     0,     0,     0,
      14,    15,     4
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   241,   -88,   -88,   -88,   -88,   -87,   -25,   -88,
     -54,   -52,   -88,   -88,   -88,   -88,   -68,    98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    92,    30,    31,    32,    33,    93,    34,    35,
      36,    37,    38,    39,    40,    87,   122,   133
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    62,    63,    64,    97,   126,    98,    41,    65,    66,
      67,    68,   118,    69,    70,    53,    78,    79,    54,   119,
      49,    50,    51,    42,    71,    43,    86,    89,    72,    73,
      91,    52,    94,    65,    66,    67,    68,   100,    69,    70,
     102,   103,   104,   105,   106,   107,    44,   108,   109,    65,
      66,    67,    68,    72,    73,   143,    45,   156,    46,   158,
      47,    67,    68,   121,    48,   124,    55,    56,    57,    59,
      73,    58,   154,    74,   167,    75,    65,    66,    67,    68,
      73,    69,    70,    76,    77,   134,   177,   101,   178,   135,
     136,   137,   138,    81,   139,    80,    72,    73,   121,    82,
      49,    50,     3,     4,     5,    97,   147,   166,     6,     7,
       8,    52,    83,    11,    12,   121,    95,    15,    96,    60,
      65,    66,    67,    68,    84,    69,    70,    85,   162,    90,
     110,   111,   164,    25,    99,   114,    26,    51,   127,    27,
      72,    73,    28,   129,    88,     2,   113,   176,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   115,    18,    19,    20,   116,    21,    22,
      23,   117,   130,   131,    24,   132,    25,   141,   145,    26,
     144,   146,    27,   148,   149,    28,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   157,    18,    19,    20,   155,    21,    22,    23,   161,
       6,     7,     8,   163,    25,    11,    12,    26,   165,    15,
      27,    60,   169,    28,   172,     6,     7,     8,   171,   173,
      11,    12,   174,   175,    15,    25,    60,   180,    26,   181,
     182,    27,    29,     0,    28,     0,   160,   120,     0,     0,
      25,     0,     0,    26,     0,     0,    27,     0,     0,    28,
       0,     0,   142,     6,     7,     8,     0,     0,    11,    12,
       0,     0,    15,     0,    60,     6,     7,     8,     0,     0,
      11,    12,     0,     0,    15,     0,    60,     0,    25,     0,
       0,    26,     0,     0,    27,     0,     0,    28,     0,   123,
      25,     0,     0,    26,     0,     0,    27,     0,     0,    28,
      65,    66,    67,    68,     0,    69,    70,    65,    66,    67,
      68,   112,    69,    70,     0,     0,     0,     0,   125,     0,
      72,    73,     0,     0,     0,     0,     0,    72,    73,    65,
      66,    67,    68,     0,    69,    70,    65,    66,    67,    68,
     128,    69,    70,     0,     0,     0,     0,     0,     0,    72,
      73,     0,     0,     0,   140,     0,    72,    73,    65,    66,
      67,    68,     0,    69,    70,    65,    66,    67,    68,   150,
      69,    70,     0,     0,     0,     0,   151,     0,    72,    73,
       0,     0,     0,     0,     0,    72,    73,    65,    66,    67,
      68,     0,    69,    70,    65,    66,    67,    68,   152,    69,
      70,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,     0,   153,     0,    72,    73,    65,    66,    67,    68,
       0,    69,    70,    65,    66,    67,    68,     0,    69,    70,
       0,     0,   159,     0,   168,     0,    72,    73,     0,     0,
       0,     0,     0,    72,    73,    65,    66,    67,    68,     0,
      69,    70,    65,    66,    67,    68,   170,    69,    70,     0,
       0,     0,     0,     0,     0,    72,    73,     0,   179,     0,
       0,     0,    72,    73,    65,    66,    67,    68,     0,    69,
      70,    65,    66,    67,    68,     0,    69,    70,    65,    66,
      67,    68,     0,    69,    72,    73,     0,     0,     0,     0,
       0,    -1,    73,     0,     0,     0,     0,     0,     0,    73
};

static const yytype_int16 yycheck[] =
{
      25,    26,    27,    28,    58,    92,    58,    40,    30,    31,
      32,    33,    41,    35,    36,    17,    41,    42,    17,    48,
      38,    39,    40,    40,    46,    40,    51,    52,    50,    51,
      55,    49,    57,    30,    31,    32,    33,    34,    35,    36,
      65,    66,    67,    68,    69,    70,    40,    72,    73,    30,
      31,    32,    33,    50,    51,   123,    40,   144,    40,   146,
      40,    32,    33,    88,    40,    90,    40,    44,    40,    17,
      51,    40,   140,    46,   161,    17,    30,    31,    32,    33,
      51,    35,    36,    46,    46,   110,   173,    41,   175,   114,
     115,   116,   117,    17,   119,    41,    50,    51,   123,    17,
      38,    39,     3,     4,     5,   159,   131,   159,     6,     7,
       8,    49,    17,    11,    12,   140,    17,    15,    19,    17,
      30,    31,    32,    33,    17,    35,    36,    17,   153,    49,
      49,    41,   157,    31,    40,    48,    34,    40,    45,    37,
      50,    51,    40,    17,    42,     0,    41,   172,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    48,    19,    20,    21,    48,    23,    24,
      25,    48,    17,    46,    29,    17,    31,    43,    24,    34,
      44,    44,    37,    48,    41,    40,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    40,    19,    20,    21,    43,    23,    24,    25,    44,
       6,     7,     8,    45,    31,    11,    12,    34,    45,    15,
      37,    17,    22,    40,    28,     6,     7,     8,    41,    44,
      11,    12,    46,    44,    15,    31,    17,    45,    34,    45,
      45,    37,     1,    -1,    40,    -1,   148,    43,    -1,    -1,
      31,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,
      -1,    -1,    43,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    15,    -1,    17,     6,     7,     8,    -1,    -1,
      11,    12,    -1,    -1,    15,    -1,    17,    -1,    31,    -1,
      -1,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,    42,
      31,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,
      30,    31,    32,    33,    -1,    35,    36,    30,    31,    32,
      33,    41,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    50,    51,    30,
      31,    32,    33,    -1,    35,    36,    30,    31,    32,    33,
      41,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    48,    -1,    50,    51,    30,    31,
      32,    33,    -1,    35,    36,    30,    31,    32,    33,    41,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    50,    51,    30,    31,    32,
      33,    -1,    35,    36,    30,    31,    32,    33,    41,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    48,    -1,    50,    51,    30,    31,    32,    33,
      -1,    35,    36,    30,    31,    32,    33,    -1,    35,    36,
      -1,    -1,    46,    -1,    41,    -1,    50,    51,    -1,    -1,
      -1,    -1,    -1,    50,    51,    30,    31,    32,    33,    -1,
      35,    36,    30,    31,    32,    33,    41,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    46,    -1,
      -1,    -1,    50,    51,    30,    31,    32,    33,    -1,    35,
      36,    30,    31,    32,    33,    -1,    35,    36,    30,    31,
      32,    33,    -1,    35,    50,    51,    -1,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    54,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    19,    20,
      21,    23,    24,    25,    29,    31,    34,    37,    40,    55,
      56,    57,    58,    59,    61,    62,    63,    64,    65,    66,
      67,    40,    40,    40,    40,    40,    40,    40,    40,    38,
      39,    40,    49,    17,    17,    40,    44,    40,    40,    17,
      17,    61,    61,    61,    61,    30,    31,    32,    33,    35,
      36,    46,    50,    51,    46,    17,    46,    46,    61,    61,
      41,    17,    17,    17,    17,    17,    61,    68,    42,    61,
      49,    61,    55,    60,    61,    17,    19,    63,    64,    40,
      34,    41,    61,    61,    61,    61,    61,    61,    61,    61,
      49,    41,    41,    41,    48,    48,    48,    48,    41,    48,
      43,    61,    69,    42,    61,    41,    60,    45,    41,    17,
      17,    46,    17,    70,    61,    61,    61,    61,    61,    61,
      48,    43,    43,    69,    44,    24,    44,    61,    48,    41,
      41,    41,    41,    48,    69,    43,    60,    40,    60,    46,
      70,    44,    61,    45,    61,    45,    64,    60,    41,    22,
      41,    41,    28,    44,    46,    44,    61,    60,    60,    46,
      45,    45,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    58,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    67,    68,    68,    68,    69,    69,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,    12,     1,     1,     1,     1,     2,
       2,     2,     2,     7,    11,    11,     7,     9,     0,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     2,     1,     1,     4,     2,     2,     2,     1,     1,
       1,     4,     3,     2,     2,     6,     4,     5,     5,     4,
       1,     1,     1,     1,     4,     4,     6,     8,     6,     3,
       4,     6,     0,     3,     1,     3,     1,     0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
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

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
#line 62 "parser.y"
                    { evaluate((yyvsp[0].a)); treefree((yyvsp[0].a)); }
#line 1552 "parser.tab.c"
    break;

  case 4:
#line 63 "parser.y"
                                                                            { dodef((yyvsp[-9].s), (yyvsp[-7].sl), (yyvsp[-4].a),(yyvsp[-2].a)); }
#line 1558 "parser.tab.c"
    break;

  case 5:
#line 66 "parser.y"
                        { }
#line 1564 "parser.tab.c"
    break;

  case 6:
#line 67 "parser.y"
                { }
#line 1570 "parser.tab.c"
    break;

  case 7:
#line 68 "parser.y"
                  { }
#line 1576 "parser.tab.c"
    break;

  case 8:
#line 69 "parser.y"
                     { }
#line 1582 "parser.tab.c"
    break;

  case 9:
#line 70 "parser.y"
                   { }
#line 1588 "parser.tab.c"
    break;

  case 10:
#line 71 "parser.y"
            { }
#line 1594 "parser.tab.c"
    break;

  case 11:
#line 72 "parser.y"
           { }
#line 1600 "parser.tab.c"
    break;

  case 12:
#line 73 "parser.y"
                 { }
#line 1606 "parser.tab.c"
    break;

  case 13:
#line 76 "parser.y"
                                                      { (yyval.a)=newflow('F', (yyvsp[-4].a), (yyvsp[-1].a), NULL, NULL); }
#line 1612 "parser.tab.c"
    break;

  case 14:
#line 77 "parser.y"
                                                                  { (yyval.a)=newflow('F', (yyvsp[-8].a), (yyvsp[-5].a), (yyvsp[-1].a), NULL); }
#line 1618 "parser.tab.c"
    break;

  case 15:
#line 80 "parser.y"
                                                                            { (yyval.a)=newflow('Q', (yyvsp[-6].a), (yyvsp[-1].a), (yyvsp[-4].a), (yyvsp[-8].a)); }
#line 1624 "parser.tab.c"
    break;

  case 16:
#line 83 "parser.y"
                                                            { (yyval.a)=newflow('W', (yyvsp[-4].a), (yyvsp[-1].a), NULL, NULL); }
#line 1630 "parser.tab.c"
    break;

  case 17:
#line 86 "parser.y"
                                                                       { (yyval.a)=newflow('D', (yyvsp[-2].a), (yyvsp[-6].a), NULL, NULL); }
#line 1636 "parser.tab.c"
    break;

  case 18:
#line 89 "parser.y"
      { (yyval.a) = NULL; }
#line 1642 "parser.tab.c"
    break;

  case 19:
#line 90 "parser.y"
                 { { if ((yyvsp[0].a) == NULL)
	                (yyval.a) = (yyvsp[-1].a);
                      else
			(yyval.a) = newast('Z', (yyvsp[-1].a), (yyvsp[0].a));
                    } }
#line 1652 "parser.tab.c"
    break;

  case 20:
#line 97 "parser.y"
                 { (yyval.a) = newast((yyvsp[-1].fn) ,(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1658 "parser.tab.c"
    break;

  case 21:
#line 98 "parser.y"
                { (yyval.a) = newast('+',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1664 "parser.tab.c"
    break;

  case 22:
#line 99 "parser.y"
                {(yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1670 "parser.tab.c"
    break;

  case 23:
#line 100 "parser.y"
                { (yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1676 "parser.tab.c"
    break;

  case 24:
#line 101 "parser.y"
                { (yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1682 "parser.tab.c"
    break;

  case 25:
#line 102 "parser.y"
                { (yyval.a) = newast('%', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1688 "parser.tab.c"
    break;

  case 26:
#line 103 "parser.y"
               {(yyval.a) = newast('O',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1694 "parser.tab.c"
    break;

  case 27:
#line 104 "parser.y"
                {(yyval.a) = newast('A',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1700 "parser.tab.c"
    break;

  case 28:
#line 105 "parser.y"
            { (yyval.a) = newast('N', (yyvsp[0].a), NULL); }
#line 1706 "parser.tab.c"
    break;

  case 29:
#line 106 "parser.y"
                  { (yyval.a) = newast('|', (yyvsp[-1].a), NULL); }
#line 1712 "parser.tab.c"
    break;

  case 30:
#line 107 "parser.y"
                    { (yyval.a)=(yyvsp[-1].a); }
#line 1718 "parser.tab.c"
    break;

  case 31:
#line 108 "parser.y"
                         { (yyval.a) = newast('M',(yyvsp[0].a),NULL); }
#line 1724 "parser.tab.c"
    break;

  case 34:
#line 111 "parser.y"
                             { (yyval.a) = newcall((yyvsp[-3].s), (yyvsp[-1].a)); }
#line 1730 "parser.tab.c"
    break;

  case 35:
#line 114 "parser.y"
                       { (yyval.a) = newsymdecl((yyvsp[-1].type), (yyvsp[0].s));}
#line 1736 "parser.tab.c"
    break;

  case 36:
#line 115 "parser.y"
           { (yyval.a) = newsymdecl((yyvsp[-1].i), (yyvsp[0].s)); }
#line 1742 "parser.tab.c"
    break;

  case 37:
#line 116 "parser.y"
            { (yyval.a) = newsymdecl((yyvsp[-1].i), (yyvsp[0].s)); }
#line 1748 "parser.tab.c"
    break;

  case 41:
#line 124 "parser.y"
                           { (yyval.a) = newasgn((yyvsp[-3].type), (yyvsp[-2].s), (yyvsp[0].a)); }
#line 1754 "parser.tab.c"
    break;

  case 42:
#line 125 "parser.y"
                  { (yyval.a) = newsasgn((yyvsp[-2].s), (yyvsp[0].a)); }
#line 1760 "parser.tab.c"
    break;

  case 43:
#line 126 "parser.y"
            { (yyval.a) = newinc('P', (yyvsp[-1].s)); }
#line 1766 "parser.tab.c"
    break;

  case 44:
#line 127 "parser.y"
            { (yyval.a) = newinc('E', (yyvsp[-1].s)); }
#line 1772 "parser.tab.c"
    break;

  case 45:
#line 128 "parser.y"
                                           { (yyval.a) = newlasgn((yyvsp[-5].i), (yyvsp[-4].s), (yyvsp[-1].l)); }
#line 1778 "parser.tab.c"
    break;

  case 46:
#line 129 "parser.y"
                      { (yyval.a) = newasgn((yyvsp[-3].i), (yyvsp[-2].s), (yyvsp[0].a)); }
#line 1784 "parser.tab.c"
    break;

  case 47:
#line 130 "parser.y"
                                 { (yyval.a) = newlasgn((yyvsp[-4].i), (yyvsp[-3].s), NULL); }
#line 1790 "parser.tab.c"
    break;

  case 48:
#line 131 "parser.y"
                                       { (yyval.a) = newlsasgn((yyvsp[-4].s), (yyvsp[-1].l)); }
#line 1796 "parser.tab.c"
    break;

  case 49:
#line 132 "parser.y"
                            { (yyval.a) = newlsasgn((yyvsp[-3].s), NULL); }
#line 1802 "parser.tab.c"
    break;

  case 50:
#line 136 "parser.y"
            { (yyval.a) = newref((yyvsp[0].s)); }
#line 1808 "parser.tab.c"
    break;

  case 51:
#line 137 "parser.y"
          { (yyval.a) = newInteger('I', (yyvsp[0].i)); }
#line 1814 "parser.tab.c"
    break;

  case 52:
#line 138 "parser.y"
       { (yyval.a) = newReal('R', (yyvsp[0].r)); }
#line 1820 "parser.tab.c"
    break;

  case 53:
#line 139 "parser.y"
         { (yyval.a) = newString('S', (yyvsp[0].string)); }
#line 1826 "parser.tab.c"
    break;

  case 54:
#line 142 "parser.y"
                                   { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a)); }
#line 1832 "parser.tab.c"
    break;

  case 55:
#line 143 "parser.y"
                            { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a)); }
#line 1838 "parser.tab.c"
    break;

  case 56:
#line 144 "parser.y"
                                   { (yyval.a) = newlfunc((yyvsp[-5].fn), (yyvsp[-3].s), (yyvsp[-1].a), NULL); }
#line 1844 "parser.tab.c"
    break;

  case 57:
#line 145 "parser.y"
                                             { (yyval.a) = newlfunc((yyvsp[-7].fn), (yyvsp[-5].s), (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 1850 "parser.tab.c"
    break;

  case 58:
#line 146 "parser.y"
                                    { (yyval.a) = newlfunc((yyvsp[-5].fn), (yyvsp[-3].s), (yyvsp[-1].a), NULL); }
#line 1856 "parser.tab.c"
    break;

  case 59:
#line 149 "parser.y"
                              { (yyval.a) = newfunc((yyvsp[-2].fn), NULL); }
#line 1862 "parser.tab.c"
    break;

  case 60:
#line 150 "parser.y"
                         { (yyval.a) = newlfunc((yyvsp[-3].fn), (yyvsp[-1].s), NULL, NULL); }
#line 1868 "parser.tab.c"
    break;

  case 61:
#line 151 "parser.y"
                                   { (yyval.a) = newlfunc((yyvsp[-5].fn), (yyvsp[-3].s), (yyvsp[-1].a), NULL); }
#line 1874 "parser.tab.c"
    break;

  case 62:
#line 154 "parser.y"
                     { (yyval.a)=NULL; }
#line 1880 "parser.tab.c"
    break;

  case 63:
#line 155 "parser.y"
                    { (yyval.a) = newast('Z', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1886 "parser.tab.c"
    break;

  case 65:
#line 159 "parser.y"
                                 { (yyval.l) = newlist('Y', (yyvsp[-2].a), (yyvsp[0].l)); }
#line 1892 "parser.tab.c"
    break;

  case 66:
#line 160 "parser.y"
      { (yyval.l) = newlist('Y', (yyvsp[0].a), NULL); }
#line 1898 "parser.tab.c"
    break;

  case 67:
#line 163 "parser.y"
                     { (yyval.sl)=NULL; }
#line 1904 "parser.tab.c"
    break;

  case 68:
#line 164 "parser.y"
       { (yyval.sl) = newsymlist((yyvsp[0].s), NULL); }
#line 1910 "parser.tab.c"
    break;

  case 69:
#line 165 "parser.y"
                     { (yyval.sl) = newsymlist((yyvsp[-2].s), (yyvsp[0].sl)); }
#line 1916 "parser.tab.c"
    break;


#line 1920 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 167 "parser.y"

