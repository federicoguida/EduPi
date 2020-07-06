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
#line 1 "parser.y"

#  include <stdio.h>
#  include <stdlib.h>
#  include "ast.h"
#  include "operations.h"
#  include "rasp.h"
int yylex();

#line 79 "parser.tab.c"

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
    SLP = 267,
    TYPE = 268,
    SQRT = 269,
    POW = 270,
    POP = 271,
    PUSH = 272,
    APP = 273,
    DEL = 274,
    INS = 275,
    GET = 276,
    SIZE = 277,
    SEARCH = 278,
    LED = 279,
    BUTT = 280,
    NAME = 281,
    LST = 282,
    PERI = 283,
    IF = 284,
    ELSE = 285,
    DO = 286,
    WHILE = 287,
    FOR = 288,
    RETURN = 289,
    DEF = 290,
    IN = 291,
    ARR = 292,
    ID = 293,
    ADDOP = 294,
    SUBOP = 295,
    MULOP = 296,
    DIVOP = 297,
    ABSOP = 298,
    OROP = 299,
    ANDOP = 300,
    NOTOP = 301,
    INCR = 302,
    DECR = 303,
    LPAREN = 304,
    RPAREN = 305,
    LBRACK = 306,
    RBRACK = 307,
    LBRACE = 308,
    RBRACE = 309,
    SEMI = 310,
    DOT = 311,
    COMMA = 312,
    ASSIGN = 313,
    CMP = 314,
    MODOP = 315,
    UMINUS = 316
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

#line 207 "parser.tab.c"

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
#define YYLAST   793

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    64,    65,    66,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    81,    82,    85,    88,
      91,    94,    97,    98,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   122,
     123,   124,   127,   128,   129,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   145,   146,   149,   150,   153,
     154,   155,   156,   159,   160,   161,   162,   163,   164,   165,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     180,   181,   182,   185,   186,   189,   190,   191
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STR", "INT", "RL", "INTEGER", "REAL",
  "STRING", "PRINT", "PRINTLN", "TIME", "SLP", "TYPE", "SQRT", "POW",
  "POP", "PUSH", "APP", "DEL", "INS", "GET", "SIZE", "SEARCH", "LED",
  "BUTT", "NAME", "LST", "PERI", "IF", "ELSE", "DO", "WHILE", "FOR",
  "RETURN", "DEF", "IN", "ARR", "ID", "ADDOP", "SUBOP", "MULOP", "DIVOP",
  "ABSOP", "OROP", "ANDOP", "NOTOP", "INCR", "DECR", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMI", "DOT", "COMMA", "ASSIGN",
  "CMP", "MODOP", "UMINUS", "$accept", "program", "statement",
  "if_statement", "for_statement", "for_each", "while_statement",
  "do_while_statement", "tail", "exp", "declaration", "type", "init",
  "pericall", "functionlist", "value", "functionV", "functionR", "explist",
  "value_list", "symlist", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF (-151)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -151,   190,  -151,  -151,  -151,  -151,  -151,  -151,  -151,   -38,
     -37,   -35,   -13,    -5,    -4,    10,    22,    23,    21,     2,
      26,    24,    14,    29,   -18,    54,   343,   343,   343,   343,
    -151,  -151,  -151,  -151,  -151,  -151,   274,    27,    62,    35,
      36,  -151,    38,  -151,   343,   343,    44,   343,   343,   343,
     343,   343,   343,     3,  -151,  -151,   343,   355,   281,    39,
      41,   343,   237,   343,    60,    12,    51,   -29,  -151,   214,
    -151,   320,   343,   343,   343,   343,   343,   343,  -151,   343,
     343,  -151,    46,  -151,  -151,  -151,   354,   361,  -151,   383,
     390,   412,   419,   441,   448,    56,  -151,   470,    68,    63,
      70,    76,    88,    89,    90,    91,    99,    49,   711,   297,
     141,   478,   237,    96,   500,   125,    18,   126,   129,   130,
     102,   133,    87,  -151,  -151,     1,     1,  -151,  -151,   103,
     147,   733,  -151,   343,  -151,  -151,  -151,  -151,  -151,   343,
     343,   343,   343,   343,  -151,   110,   343,   343,   343,   343,
     343,   112,   343,  -151,   507,   113,   121,   711,   109,   115,
    -151,   137,   118,   119,    39,    41,    46,   343,   117,   128,
     711,   529,   536,   558,   131,  -151,  -151,   565,   587,   594,
     616,   624,  -151,   646,   343,  -151,  -151,   123,   150,   237,
     134,   237,   237,   653,   133,   127,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,   343,  -151,  -151,  -151,  -151,   135,   122,
     154,   343,   156,   157,    12,  -151,   237,   675,   343,   186,
     152,   682,  -151,  -151,   163,   -21,  -151,   170,   175,   173,
     172,   176,   343,  -151,  -151,   343,   237,  -151,   237,   704,
     178,   177,   180,   181,  -151,  -151,  -151,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    43,    42,    44,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     6,     7,     8,     9,    10,     0,     0,     0,     0,
       0,    36,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,    80,     0,     0,    40,
      41,     0,    22,     0,     0,     0,     0,    59,    35,     0,
      32,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,    11,    39,    12,    15,    14,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,    55,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,    33,    34,    25,    26,    27,    28,    30,
      31,    24,    29,     0,    63,    64,    68,    76,    77,     0,
       0,     0,    80,    80,    38,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    84,     0,     0,    50,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,    86,     0,
      45,     0,     0,     0,     0,    81,    71,     0,     0,     0,
       0,     0,    74,     0,     0,    52,    51,     0,     0,    22,
       0,    22,    22,     0,    85,     0,    78,    69,    79,    56,
      67,    65,    72,     0,    73,    75,    83,    49,     0,    54,
       0,     0,     0,     0,     0,    87,    22,     0,    80,     0,
      16,     0,    20,    19,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     5,    58,    80,    22,    21,    22,     0,
       0,     0,     0,     0,    57,    17,    18,     4
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,   231,  -151,  -151,  -151,  -151,  -151,  -105,   -26,
    -151,   -61,   -60,  -151,  -151,  -151,  -151,  -151,  -133,  -150,
      43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   112,    31,    32,    33,    34,    35,   113,    36,
      37,    38,    39,    40,   209,    41,    42,    43,    98,   155,
     169
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    69,    70,    71,   119,   120,   187,   160,    64,   174,
     175,    44,    45,   232,    46,     3,     4,     5,    86,    87,
      56,    89,    90,    91,    92,    93,    94,   122,    59,    95,
      97,    65,   108,   233,   206,   111,    47,   114,   116,   117,
     118,    96,    74,    75,    48,    49,   125,   126,   127,   128,
     129,   130,    60,   131,   132,     6,     7,     8,    53,    50,
      11,    80,    13,    14,    15,    54,    55,    62,    54,    55,
      56,    51,    52,    61,    17,    67,    58,    57,    63,    58,
      66,   154,    81,   157,   210,   227,   212,   213,    82,    26,
      83,    84,    27,    85,    88,    28,   115,   109,    29,   110,
     121,   153,   240,    99,   133,   142,   102,   170,   104,   105,
     106,   225,   145,   171,   172,   173,    97,    97,   144,   146,
     177,   178,   179,   180,   181,   147,   183,     6,     7,     8,
     154,   241,    11,   242,    13,    14,    15,   148,   149,   150,
     151,   193,    72,    73,    74,    75,    17,    67,   152,   158,
     161,   163,   164,   119,   224,   165,   166,   167,   154,   168,
     176,    26,   182,    80,    27,   185,   188,    28,   189,   190,
      29,   191,   192,   186,   194,   207,   208,   217,   195,   219,
     216,   199,   229,   211,   218,   221,    72,    73,    74,    75,
       2,    76,    97,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   239,    80,   220,    97,
     222,   223,   228,   231,    16,    17,    18,    19,    20,    21,
     234,    22,    23,    24,   235,    25,   236,   237,   244,   238,
      26,   245,    30,    27,   246,   247,    28,   215,     0,    29,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    72,    73,    74,    75,   123,    76,    77,
       0,    16,    17,    18,    19,    20,    21,     0,    22,    23,
      24,     0,     0,    79,    80,     0,     0,    26,     0,     0,
      27,     0,     0,    28,     0,     0,    29,     6,     7,     8,
       0,     0,    11,     0,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     6,     7,     8,    17,    67,    11,     0,
      13,    14,    15,    72,    73,    74,    75,     0,    76,    77,
       0,    26,    17,    67,    27,     0,     0,    28,     0,    78,
      29,     0,   107,    79,    80,     0,     0,    26,     0,     0,
      27,     0,     0,    28,     0,     0,    29,     0,   156,     6,
       7,     8,     0,     0,    11,     0,    13,    14,    15,    72,
      73,    74,    75,     0,    76,    77,     0,     0,    17,    67,
     124,    99,   100,   101,   102,   103,   104,   105,   106,    79,
      80,     0,     0,    26,     0,     0,    27,     0,     0,    28,
       0,     0,    29,    72,    73,    74,    75,     0,    76,    77,
      72,    73,    74,    75,   134,    76,    77,     0,     0,     0,
       0,   135,     0,    79,    80,     0,     0,     0,     0,     0,
      79,    80,    72,    73,    74,    75,     0,    76,    77,    72,
      73,    74,    75,   136,    76,    77,     0,     0,     0,     0,
     137,     0,    79,    80,     0,     0,     0,     0,     0,    79,
      80,    72,    73,    74,    75,     0,    76,    77,    72,    73,
      74,    75,   138,    76,    77,     0,     0,     0,     0,     0,
       0,    79,    80,     0,     0,     0,   139,     0,    79,    80,
      72,    73,    74,    75,     0,    76,    77,    72,    73,    74,
      75,     0,    76,    77,     0,     0,     0,     0,   140,     0,
      79,    80,     0,     0,     0,   141,     0,    79,    80,    72,
      73,    74,    75,     0,    76,    77,     0,    72,    73,    74,
      75,     0,    76,    77,     0,     0,     0,   143,   159,    79,
      80,     0,     0,     0,     0,     0,     0,    79,    80,    72,
      73,    74,    75,     0,    76,    77,    72,    73,    74,    75,
     162,    76,    77,     0,     0,     0,     0,     0,     0,    79,
      80,     0,     0,     0,   184,     0,    79,    80,    72,    73,
      74,    75,     0,    76,    77,    72,    73,    74,    75,   196,
      76,    77,     0,     0,     0,     0,   197,     0,    79,    80,
       0,     0,     0,     0,     0,    79,    80,    72,    73,    74,
      75,     0,    76,    77,    72,    73,    74,    75,   198,    76,
      77,     0,     0,     0,     0,   200,     0,    79,    80,     0,
       0,     0,     0,     0,    79,    80,    72,    73,    74,    75,
       0,    76,    77,    72,    73,    74,    75,   201,    76,    77,
       0,     0,     0,     0,   202,     0,    79,    80,     0,     0,
       0,     0,     0,    79,    80,    72,    73,    74,    75,     0,
      76,    77,     0,    72,    73,    74,    75,     0,    76,    77,
       0,     0,     0,   203,   204,    79,    80,     0,     0,     0,
       0,     0,     0,    79,    80,    72,    73,    74,    75,     0,
      76,    77,    72,    73,    74,    75,   205,    76,    77,     0,
       0,     0,     0,     0,     0,    79,    80,     0,   214,     0,
       0,     0,    79,    80,    72,    73,    74,    75,     0,    76,
      77,    72,    73,    74,    75,   226,    76,    77,     0,     0,
       0,     0,   230,     0,    79,    80,     0,     0,     0,     0,
       0,    79,    80,    72,    73,    74,    75,     0,    76,    77,
      72,    73,    74,    75,     0,    76,    77,     0,     0,   243,
       0,     0,     0,    79,    80,     0,     0,     0,     0,     0,
      79,    80,    72,    73,    74,    75,     0,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -1,    80
};

static const yytype_int16 yycheck[] =
{
      26,    27,    28,    29,    65,    65,   156,   112,    26,   142,
     143,    49,    49,    34,    49,     3,     4,     5,    44,    45,
      49,    47,    48,    49,    50,    51,    52,    56,    26,    26,
      56,    49,    58,    54,   184,    61,    49,    63,    26,    27,
      28,    38,    41,    42,    49,    49,    72,    73,    74,    75,
      76,    77,    26,    79,    80,     6,     7,     8,    37,    49,
      11,    60,    13,    14,    15,    47,    48,    53,    47,    48,
      49,    49,    49,    49,    25,    26,    58,    56,    49,    58,
      26,   107,    55,   109,   189,   218,   191,   192,    26,    40,
      55,    55,    43,    55,    50,    46,    36,    58,    49,    58,
      49,    52,   235,    16,    58,    49,    19,   133,    21,    22,
      23,   216,    49,   139,   140,   141,   142,   143,    50,    49,
     146,   147,   148,   149,   150,    49,   152,     6,     7,     8,
     156,   236,    11,   238,    13,    14,    15,    49,    49,    49,
      49,   167,    39,    40,    41,    42,    25,    26,    49,     8,
      54,    26,    26,   214,   214,    26,    26,    55,   184,    26,
      50,    40,    50,    60,    43,    52,    57,    46,    53,    32,
      49,    53,    53,    52,    57,    52,    26,   203,    50,    57,
      53,    50,    30,    49,    49,   211,    39,    40,    41,    42,
       0,    44,   218,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   232,    60,    54,   235,
      54,    54,    26,    50,    24,    25,    26,    27,    28,    29,
      50,    31,    32,    33,    49,    35,    53,    55,    50,    53,
      40,    54,     1,    43,    54,    54,    46,   194,    -1,    49,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    39,    40,    41,    42,    43,    44,    45,
      -1,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    -1,    59,    60,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,     6,     7,     8,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    25,    26,    11,    -1,
      13,    14,    15,    39,    40,    41,    42,    -1,    44,    45,
      -1,    40,    25,    26,    43,    -1,    -1,    46,    -1,    55,
      49,    -1,    51,    59,    60,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    46,    -1,    -1,    49,    -1,    51,     6,
       7,     8,    -1,    -1,    11,    -1,    13,    14,    15,    39,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    25,    26,
      50,    16,    17,    18,    19,    20,    21,    22,    23,    59,
      60,    -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    39,    40,    41,    42,    -1,    44,    45,
      39,    40,    41,    42,    50,    44,    45,    -1,    -1,    -1,
      -1,    50,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      59,    60,    39,    40,    41,    42,    -1,    44,    45,    39,
      40,    41,    42,    50,    44,    45,    -1,    -1,    -1,    -1,
      50,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    59,
      60,    39,    40,    41,    42,    -1,    44,    45,    39,    40,
      41,    42,    50,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    57,    -1,    59,    60,
      39,    40,    41,    42,    -1,    44,    45,    39,    40,    41,
      42,    -1,    44,    45,    -1,    -1,    -1,    -1,    57,    -1,
      59,    60,    -1,    -1,    -1,    57,    -1,    59,    60,    39,
      40,    41,    42,    -1,    44,    45,    -1,    39,    40,    41,
      42,    -1,    44,    45,    -1,    -1,    -1,    57,    50,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    39,
      40,    41,    42,    -1,    44,    45,    39,    40,    41,    42,
      50,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    57,    -1,    59,    60,    39,    40,
      41,    42,    -1,    44,    45,    39,    40,    41,    42,    50,
      44,    45,    -1,    -1,    -1,    -1,    50,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    59,    60,    39,    40,    41,
      42,    -1,    44,    45,    39,    40,    41,    42,    50,    44,
      45,    -1,    -1,    -1,    -1,    50,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    59,    60,    39,    40,    41,    42,
      -1,    44,    45,    39,    40,    41,    42,    50,    44,    45,
      -1,    -1,    -1,    -1,    50,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    59,    60,    39,    40,    41,    42,    -1,
      44,    45,    -1,    39,    40,    41,    42,    -1,    44,    45,
      -1,    -1,    -1,    57,    50,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    39,    40,    41,    42,    -1,
      44,    45,    39,    40,    41,    42,    50,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    55,    -1,
      -1,    -1,    59,    60,    39,    40,    41,    42,    -1,    44,
      45,    39,    40,    41,    42,    50,    44,    45,    -1,    -1,
      -1,    -1,    50,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    59,    60,    39,    40,    41,    42,    -1,    44,    45,
      39,    40,    41,    42,    -1,    44,    45,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      59,    60,    39,    40,    41,    42,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    24,    25,    26,    27,
      28,    29,    31,    32,    33,    35,    40,    43,    46,    49,
      64,    65,    66,    67,    68,    69,    71,    72,    73,    74,
      75,    77,    78,    79,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    37,    47,    48,    49,    56,    58,    26,
      26,    49,    53,    49,    26,    49,    26,    26,    71,    71,
      71,    71,    39,    40,    41,    42,    44,    45,    55,    59,
      60,    55,    26,    55,    55,    55,    71,    71,    50,    71,
      71,    71,    71,    71,    71,    26,    38,    71,    80,    16,
      17,    18,    19,    20,    21,    22,    23,    51,    71,    58,
      58,    71,    64,    70,    71,    36,    26,    27,    28,    73,
      74,    49,    56,    43,    50,    71,    71,    71,    71,    71,
      71,    71,    71,    58,    50,    50,    50,    50,    50,    57,
      57,    57,    49,    57,    50,    49,    49,    49,    49,    49,
      49,    49,    49,    52,    71,    81,    51,    71,     8,    50,
      70,    54,    50,    26,    26,    26,    26,    55,    26,    82,
      71,    71,    71,    71,    80,    80,    50,    71,    71,    71,
      71,    71,    50,    71,    57,    52,    52,    81,    57,    53,
      32,    53,    53,    71,    57,    50,    50,    50,    50,    50,
      50,    50,    50,    57,    50,    50,    81,    52,    26,    76,
      70,    49,    70,    70,    55,    82,    53,    71,    49,    57,
      54,    71,    54,    54,    74,    70,    50,    80,    26,    30,
      50,    50,    34,    54,    50,    49,    53,    55,    53,    71,
      80,    70,    70,    55,    50,    54,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    67,
      68,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,    12,     9,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     7,    11,    11,     7,
       7,     9,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     1,     1,     4,     2,
       2,     2,     1,     1,     1,     4,     3,     2,     2,     6,
       4,     5,     5,     4,     6,     3,     6,     6,     4,     1,
       1,     1,     1,     4,     4,     6,     8,     6,     4,     6,
       3,     5,     6,     6,     5,     6,     4,     4,     6,     6,
       0,     3,     1,     3,     1,     0,     1,     3
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
#line 64 "parser.y"
                    { evaluate((yyvsp[0].a)); treefree((yyvsp[0].a)); }
#line 1649 "parser.tab.c"
    break;

  case 4:
#line 65 "parser.y"
                                                                            { dodef((yyvsp[-9].s), (yyvsp[-7].sl), (yyvsp[-4].a),(yyvsp[-2].a)); }
#line 1655 "parser.tab.c"
    break;

  case 5:
#line 66 "parser.y"
                                                            { dodef((yyvsp[-6].s), (yyvsp[-4].sl), (yyvsp[-1].a),NULL); }
#line 1661 "parser.tab.c"
    break;

  case 6:
#line 69 "parser.y"
                        { }
#line 1667 "parser.tab.c"
    break;

  case 7:
#line 70 "parser.y"
                { }
#line 1673 "parser.tab.c"
    break;

  case 8:
#line 71 "parser.y"
           {}
#line 1679 "parser.tab.c"
    break;

  case 9:
#line 72 "parser.y"
                  { }
#line 1685 "parser.tab.c"
    break;

  case 10:
#line 73 "parser.y"
                     { }
#line 1691 "parser.tab.c"
    break;

  case 11:
#line 74 "parser.y"
                   { }
#line 1697 "parser.tab.c"
    break;

  case 12:
#line 75 "parser.y"
            { }
#line 1703 "parser.tab.c"
    break;

  case 13:
#line 76 "parser.y"
           { }
#line 1709 "parser.tab.c"
    break;

  case 14:
#line 77 "parser.y"
                 { }
#line 1715 "parser.tab.c"
    break;

  case 15:
#line 78 "parser.y"
                { }
#line 1721 "parser.tab.c"
    break;

  case 16:
#line 81 "parser.y"
                                                      { (yyval.a)=newflow('F', (yyvsp[-4].a), (yyvsp[-1].a), NULL, NULL); }
#line 1727 "parser.tab.c"
    break;

  case 17:
#line 82 "parser.y"
                                                                  { (yyval.a)=newflow('F', (yyvsp[-8].a), (yyvsp[-5].a), (yyvsp[-1].a), NULL); }
#line 1733 "parser.tab.c"
    break;

  case 18:
#line 85 "parser.y"
                                                                            { (yyval.a)=newflow('Q', (yyvsp[-6].a), (yyvsp[-1].a), (yyvsp[-4].a), (yyvsp[-8].a)); }
#line 1739 "parser.tab.c"
    break;

  case 19:
#line 88 "parser.y"
                                              { (yyval.a)=newForEach('B', (yyvsp[-5].s), (yyvsp[-3].s), (yyvsp[-1].a));}
#line 1745 "parser.tab.c"
    break;

  case 20:
#line 91 "parser.y"
                                                            { (yyval.a)=newflow('W', (yyvsp[-4].a), (yyvsp[-1].a), NULL, NULL); }
#line 1751 "parser.tab.c"
    break;

  case 21:
#line 94 "parser.y"
                                                                       { (yyval.a)=newflow('D', (yyvsp[-2].a), (yyvsp[-6].a), NULL, NULL); }
#line 1757 "parser.tab.c"
    break;

  case 22:
#line 97 "parser.y"
      { (yyval.a) = NULL; }
#line 1763 "parser.tab.c"
    break;

  case 23:
#line 98 "parser.y"
                 { { if ((yyvsp[0].a) == NULL)
	                (yyval.a) = (yyvsp[-1].a);
                      else
			(yyval.a) = newast('Z', (yyvsp[-1].a), (yyvsp[0].a));
                    } }
#line 1773 "parser.tab.c"
    break;

  case 24:
#line 105 "parser.y"
                 { (yyval.a) = newast((yyvsp[-1].fn) ,(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1779 "parser.tab.c"
    break;

  case 25:
#line 106 "parser.y"
                { (yyval.a) = newast('+',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1785 "parser.tab.c"
    break;

  case 26:
#line 107 "parser.y"
                {(yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1791 "parser.tab.c"
    break;

  case 27:
#line 108 "parser.y"
                { (yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1797 "parser.tab.c"
    break;

  case 28:
#line 109 "parser.y"
                { (yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1803 "parser.tab.c"
    break;

  case 29:
#line 110 "parser.y"
                { (yyval.a) = newast('%', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1809 "parser.tab.c"
    break;

  case 30:
#line 111 "parser.y"
               {(yyval.a) = newast('O',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1815 "parser.tab.c"
    break;

  case 31:
#line 112 "parser.y"
                {(yyval.a) = newast('A',(yyvsp[-2].a),(yyvsp[0].a)); }
#line 1821 "parser.tab.c"
    break;

  case 32:
#line 113 "parser.y"
            { (yyval.a) = newast('N', (yyvsp[0].a), NULL); }
#line 1827 "parser.tab.c"
    break;

  case 33:
#line 114 "parser.y"
                  { (yyval.a) = newast('|', (yyvsp[-1].a), NULL); }
#line 1833 "parser.tab.c"
    break;

  case 34:
#line 115 "parser.y"
                    { (yyval.a)=(yyvsp[-1].a); }
#line 1839 "parser.tab.c"
    break;

  case 35:
#line 116 "parser.y"
                         { (yyval.a) = newast('M',(yyvsp[0].a),NULL); }
#line 1845 "parser.tab.c"
    break;

  case 38:
#line 119 "parser.y"
                             { (yyval.a) = newcall((yyvsp[-3].s), (yyvsp[-1].a)); }
#line 1851 "parser.tab.c"
    break;

  case 39:
#line 122 "parser.y"
                       { (yyval.a) = newsymdecl((yyvsp[-1].type), (yyvsp[0].s));}
#line 1857 "parser.tab.c"
    break;

  case 40:
#line 123 "parser.y"
           { (yyval.a) = newsymdecl((yyvsp[-1].i), (yyvsp[0].s)); }
#line 1863 "parser.tab.c"
    break;

  case 41:
#line 124 "parser.y"
            { (yyval.a) = newsymdecl((yyvsp[-1].i), (yyvsp[0].s)); }
#line 1869 "parser.tab.c"
    break;

  case 45:
#line 132 "parser.y"
                           { (yyval.a) = newasgn((yyvsp[-3].type), (yyvsp[-2].s), (yyvsp[0].a)); }
#line 1875 "parser.tab.c"
    break;

  case 46:
#line 133 "parser.y"
                  { (yyval.a) = newsasgn((yyvsp[-2].s), (yyvsp[0].a)); }
#line 1881 "parser.tab.c"
    break;

  case 47:
#line 134 "parser.y"
            { (yyval.a) = newsasgn((yyvsp[-1].s), newast('+', newref((yyvsp[-1].s)), newInteger('I', 1))); }
#line 1887 "parser.tab.c"
    break;

  case 48:
#line 135 "parser.y"
            { (yyval.a) = newsasgn((yyvsp[-1].s), newast('-', newref((yyvsp[-1].s)), newInteger('I', 1))); }
#line 1893 "parser.tab.c"
    break;

  case 49:
#line 136 "parser.y"
                                           { (yyval.a) = newlasgn((yyvsp[-5].i), (yyvsp[-4].s), (yyvsp[-1].l)); }
#line 1899 "parser.tab.c"
    break;

  case 50:
#line 137 "parser.y"
                      { (yyval.a) = newasgn((yyvsp[-3].i), (yyvsp[-2].s), (yyvsp[0].a)); }
#line 1905 "parser.tab.c"
    break;

  case 51:
#line 138 "parser.y"
                                 { (yyval.a) = newlasgn((yyvsp[-4].i), (yyvsp[-3].s), NULL); }
#line 1911 "parser.tab.c"
    break;

  case 52:
#line 139 "parser.y"
                                       { (yyval.a) = newlsasgn((yyvsp[-4].s), (yyvsp[-1].l)); }
#line 1917 "parser.tab.c"
    break;

  case 53:
#line 140 "parser.y"
                            { (yyval.a) = newlsasgn((yyvsp[-3].s), NULL); }
#line 1923 "parser.tab.c"
    break;

  case 54:
#line 141 "parser.y"
                                             {(yyval.a) = newperipherical((yyvsp[-5].i), (yyvsp[-4].s), (yyvsp[-2].string), (yyvsp[0].fl));}
#line 1929 "parser.tab.c"
    break;

  case 55:
#line 145 "parser.y"
                      { (yyval.a) = newperipheralcall((yyvsp[-2].s), newString('S', "ID"),NULL, NULL); }
#line 1935 "parser.tab.c"
    break;

  case 56:
#line 146 "parser.y"
                                      { (yyval.a) = newperipheralcall((yyvsp[-5].s), NULL, (yyvsp[-3].s), (yyvsp[-1].a)); }
#line 1941 "parser.tab.c"
    break;

  case 57:
#line 149 "parser.y"
                                                           { (yyval.fl)=newfunclist(newcall((yyvsp[-3].s), (yyvsp[-1].a)),(yyvsp[-5].fl));}
#line 1947 "parser.tab.c"
    break;

  case 58:
#line 150 "parser.y"
                             { (yyval.fl)=newfunclist(newcall((yyvsp[-3].s), (yyvsp[-1].a)),NULL); }
#line 1953 "parser.tab.c"
    break;

  case 59:
#line 153 "parser.y"
            { (yyval.a) = newref((yyvsp[0].s)); }
#line 1959 "parser.tab.c"
    break;

  case 60:
#line 154 "parser.y"
          { (yyval.a) = newInteger('I', (yyvsp[0].i)); }
#line 1965 "parser.tab.c"
    break;

  case 61:
#line 155 "parser.y"
       { (yyval.a) = newReal('R', (yyvsp[0].r)); }
#line 1971 "parser.tab.c"
    break;

  case 62:
#line 156 "parser.y"
         { (yyval.a) = newString('S', (yyvsp[0].string)); }
#line 1977 "parser.tab.c"
    break;

  case 63:
#line 159 "parser.y"
                                   { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a), NULL); }
#line 1983 "parser.tab.c"
    break;

  case 64:
#line 160 "parser.y"
                            { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a), NULL); }
#line 1989 "parser.tab.c"
    break;

  case 65:
#line 161 "parser.y"
                                 { (yyval.a) = newlfunc((yyvsp[-3].fn), (yyvsp[-5].s), (yyvsp[-1].a), NULL); }
#line 1995 "parser.tab.c"
    break;

  case 66:
#line 162 "parser.y"
                                           { (yyval.a) = newlfunc((yyvsp[-5].fn), (yyvsp[-7].s), (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 2001 "parser.tab.c"
    break;

  case 67:
#line 163 "parser.y"
                                  { (yyval.a) = newlfunc((yyvsp[-3].fn), (yyvsp[-5].s), (yyvsp[-1].a), NULL); }
#line 2007 "parser.tab.c"
    break;

  case 68:
#line 164 "parser.y"
                        { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a), NULL); }
#line 2013 "parser.tab.c"
    break;

  case 69:
#line 165 "parser.y"
                                  { (yyval.a) = newfunc((yyvsp[-5].fn), (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 2019 "parser.tab.c"
    break;

  case 70:
#line 168 "parser.y"
                              { (yyval.a) = newfunc((yyvsp[-2].fn), NULL, NULL); }
#line 2025 "parser.tab.c"
    break;

  case 71:
#line 169 "parser.y"
                             { (yyval.a) = newlfunc((yyvsp[-2].fn), (yyvsp[-4].s), NULL, NULL); }
#line 2031 "parser.tab.c"
    break;

  case 72:
#line 170 "parser.y"
                                 { (yyval.a) = newlfunc((yyvsp[-3].fn), (yyvsp[-5].s), (yyvsp[-1].a), NULL); }
#line 2037 "parser.tab.c"
    break;

  case 73:
#line 171 "parser.y"
                                 { (yyval.a) = newlfunc((yyvsp[-3].fn), (yyvsp[-5].s), (yyvsp[-1].a), NULL); }
#line 2043 "parser.tab.c"
    break;

  case 74:
#line 172 "parser.y"
                              { (yyval.a) = newlfunc((yyvsp[-2].fn), (yyvsp[-4].s), NULL, NULL); }
#line 2049 "parser.tab.c"
    break;

  case 75:
#line 173 "parser.y"
                                    { (yyval.a) = newlfunc((yyvsp[-3].fn), (yyvsp[-5].s), (yyvsp[-1].a), NULL); }
#line 2055 "parser.tab.c"
    break;

  case 76:
#line 174 "parser.y"
                         { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a), NULL); }
#line 2061 "parser.tab.c"
    break;

  case 77:
#line 175 "parser.y"
                         { (yyval.a) = newfunc((yyvsp[-3].fn), (yyvsp[-1].a), NULL); }
#line 2067 "parser.tab.c"
    break;

  case 78:
#line 176 "parser.y"
                                  { (yyval.a) = newfunc((yyvsp[-5].fn), (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 2073 "parser.tab.c"
    break;

  case 79:
#line 177 "parser.y"
                                   { (yyval.a) = newfunc((yyvsp[-5].fn), (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 2079 "parser.tab.c"
    break;

  case 80:
#line 180 "parser.y"
                     { (yyval.a)=NULL; }
#line 2085 "parser.tab.c"
    break;

  case 81:
#line 181 "parser.y"
                    { (yyval.a) = newast('Z', (yyvsp[-2].a), (yyvsp[0].a)); }
#line 2091 "parser.tab.c"
    break;

  case 83:
#line 185 "parser.y"
                                 { (yyval.l) = newlist('Y', (yyvsp[-2].a), (yyvsp[0].l)); }
#line 2097 "parser.tab.c"
    break;

  case 84:
#line 186 "parser.y"
      { (yyval.l) = newlist('Y', (yyvsp[0].a), NULL); }
#line 2103 "parser.tab.c"
    break;

  case 85:
#line 189 "parser.y"
                     { (yyval.sl)=NULL; }
#line 2109 "parser.tab.c"
    break;

  case 86:
#line 190 "parser.y"
       { (yyval.sl) = newsymlist((yyvsp[0].s), NULL); }
#line 2115 "parser.tab.c"
    break;

  case 87:
#line 191 "parser.y"
                     { (yyval.sl) = newsymlist((yyvsp[-2].s), (yyvsp[0].sl)); }
#line 2121 "parser.tab.c"
    break;


#line 2125 "parser.tab.c"

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
#line 193 "parser.y"

