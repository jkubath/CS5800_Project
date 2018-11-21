/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */

/* 	CS5800 Final Project - Calculator
	Summary: Calculator implementation using FLEX.

	Team Members:	Ioannis Nearchou
					Jonah Kubath

	Date: 11/09/2018
*/

/*
	Resources
	http://www.gnu.org/software/bison/manual/html_node/Error-Recovery.html
	https://www.ibm.com/developerworks/library/l-flexbison/index.html
*/

struct data_s {
	char * s;
	double num;
	char ref;
} YYSTYPE;

#define YYSTYPE struct data_s
#define arraySize 1024

#define YYERROR_VERBOSE 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double calcMod(double a,double b);
void derivative(char * s, char ref);
void functionDeriv(char * s, char * function, char ref);
void combineStruct(struct data_s * end, struct data_s * left, struct data_s * right, char * bin);

int yylex();

void yyerror(const char *s) {
	printf("Error %s\n", s);
}

char resultString[arraySize];


#line 114 "parse.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EQUALS = 258,
    NUMBER = 259,
    POWER = 260,
    MODULO = 261,
    EOLN = 262,
    SIN = 263,
    COS = 264,
    TAN = 265,
    CSC = 266,
    SEC = 267,
    COT = 268,
    DERIV = 269,
    STRING = 270,
    ERROR = 271,
    LEFT_B = 272,
    RIGHT_B = 273,
    PLUS = 274,
    MINUS = 275,
    MULTIPLY = 276,
    DIVIDE = 277,
    NOT = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 189 "parse.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  34
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  84

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    61,    63,    73,    76,    79,    80,    81,
      84,    85,    86,    87,    89,    90,    93,    95,    97,    99,
     102,   104,   106,   108,   110,   112,   114,   116,   118,   121,
     122,   125,   131,   133,   135
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQUALS", "NUMBER", "POWER", "MODULO",
  "EOLN", "SIN", "COS", "TAN", "CSC", "SEC", "COT", "DERIV", "STRING",
  "ERROR", "LEFT_B", "RIGHT_B", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "NOT", "$accept", "commands", "exp", "add_sub", "mult_div", "power",
  "function", "derivative", "polynomial", "primary", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278
};
# endif

#define YYPACT_NINF -36

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -36,    41,   -36,     0,   -36,   -36,    21,    29,    30,    -2,
     -36,    60,     6,   -15,    -4,    47,   -36,   -36,   -36,   -36,
      49,    62,    72,    40,    50,    -9,   -36,    60,    60,    60,
      60,    60,    -1,    73,    74,    75,    -1,    76,    78,    79,
      80,    81,    82,     1,   -36,   -36,    -4,    -4,    47,    47,
      47,   -36,   -36,   -36,   -36,     9,   -36,    -1,    -1,    -1,
      -1,    -1,   -36,    -1,    -1,    83,    12,    53,    61,    64,
      67,   -36,   -36,   -36,    84,    85,    86,    87,    88,   -36,
     -36,   -36,   -36,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    32,     3,     0,     0,     0,     0,
      33,     0,     0,     6,     7,    10,    14,    16,    20,     5,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,    29,    34,     8,     9,    13,    11,
      12,    15,    17,    18,    19,     0,    28,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    31,    21,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,    89,    16,    59,   -36,   -36,   -35,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    12,    13,    14,    15,    16,    17,    43,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    55,    29,     4,    27,    28,    23,    19,    51,    45,
      27,    28,    44,    26,    10,    24,    11,    30,    31,    62,
      63,    64,    66,    67,    68,    69,    70,    65,    63,    64,
      74,    63,    64,    44,    44,    44,    44,    44,    20,    71,
      72,     2,     3,    46,    47,     4,    21,    22,     5,     6,
       7,     8,    32,    33,    37,     9,    10,    36,    11,    38,
      39,    40,    41,    42,     4,    10,    34,    11,     6,     7,
       8,    75,    63,    64,     9,    10,    35,    11,     0,    76,
      63,    64,    77,    63,    64,    78,    63,    64,    48,    49,
      50,    52,    53,    54,    56,    57,    58,    59,    60,    61,
      25,    73,    79,    80,    81,    82,    83
};

static const yytype_int8 yycheck[] =
{
      24,    36,     6,     4,    19,    20,     8,     7,    32,    18,
      19,    20,    36,     7,    15,    17,    17,    21,    22,    18,
      19,    20,    57,    58,    59,    60,    61,    18,    19,    20,
      18,    19,    20,    57,    58,    59,    60,    61,    17,    63,
      64,     0,     1,    27,    28,     4,    17,    17,     7,     8,
       9,    10,     5,     4,     4,    14,    15,    17,    17,     9,
      10,    11,    12,    13,     4,    15,     4,    17,     8,     9,
      10,    18,    19,    20,    14,    15,     4,    17,    -1,    18,
      19,    20,    18,    19,    20,    18,    19,    20,    29,    30,
      31,    18,    18,    18,    18,    17,    17,    17,    17,    17,
      11,    18,    18,    18,    18,    18,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,     0,     1,     4,     7,     8,     9,    10,    14,
      15,    17,    26,    27,    28,    29,    30,    31,    33,     7,
      17,    17,    17,     8,    17,    27,     7,    19,    20,     6,
      21,    22,     5,     4,     4,     4,    17,     4,     9,    10,
      11,    12,    13,    32,    33,    18,    28,    28,    29,    29,
      29,    33,    18,    18,    18,    32,    18,    17,    17,    17,
      17,    17,    18,    19,    20,    18,    32,    32,    32,    32,
      32,    33,    33,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    25,    25,    25,    26,    27,    27,    27,
      28,    28,    28,    28,    29,    29,    30,    30,    30,    30,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    32,
      32,    32,    33,    33,    33
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     1,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     4,     4,     4,
       1,     6,     7,     7,     7,     7,     7,     4,     4,     1,
       3,     3,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 4:
#line 64 "parse.y" /* yacc.c:1646  */
    { 
		if((yyvsp[-1]).s != NULL && (yyvsp[-1]).s[0] != '\0') {
			printf("\t= %s\n", (yyvsp[-1]).s); return 0;
		}
		else {
			printf("\t= %g\n", (yyvsp[-1]).num); return 0;
		}
	}
#line 1321 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 73 "parse.y" /* yacc.c:1646  */
    { (yyvsp[-1]).s[0] = '\0'; }
#line 1327 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 80 "parse.y" /* yacc.c:1646  */
    { (yyval).num = (yyvsp[-2]).num + (yyvsp[0]).num; }
#line 1333 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 81 "parse.y" /* yacc.c:1646  */
    { (yyval).num = (yyvsp[-2]).num - (yyvsp[0]).num; }
#line 1339 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 85 "parse.y" /* yacc.c:1646  */
    { (yyval).num = (yyvsp[-2]).num * (yyvsp[0]).num; }
#line 1345 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 86 "parse.y" /* yacc.c:1646  */
    { (yyval).num = (yyvsp[-2]).num / (yyvsp[0]).num; }
#line 1351 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 87 "parse.y" /* yacc.c:1646  */
    { (yyval).num = calcMod((yyvsp[-2]).num, (yyvsp[0]).num); }
#line 1357 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "parse.y" /* yacc.c:1646  */
    { (yyval).num = pow((yyvsp[-2]).num, (yyvsp[0]).num); }
#line 1363 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 95 "parse.y" /* yacc.c:1646  */
    { (yyval).num = sinf((yyvsp[-1]).num); }
#line 1369 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "parse.y" /* yacc.c:1646  */
    { (yyval).num = cosf((yyvsp[-1]).num); }
#line 1375 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "parse.y" /* yacc.c:1646  */
    { (yyval).num = tanf((yyvsp[-1]).num); }
#line 1381 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 104 "parse.y" /* yacc.c:1646  */
    { functionDeriv((yyvsp[-1]).s, "sin", (yyvsp[-5]).s[0]); (yyval).s = resultString; }
#line 1387 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 106 "parse.y" /* yacc.c:1646  */
    { functionDeriv((yyvsp[-2]).s, "cos", (yyvsp[-6]).s[0]); (yyval).s = resultString; }
#line 1393 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 108 "parse.y" /* yacc.c:1646  */
    { functionDeriv((yyvsp[-2]).s, "tan", (yyvsp[-6]).s[0]); (yyval).s = resultString; }
#line 1399 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 110 "parse.y" /* yacc.c:1646  */
    { functionDeriv((yyvsp[-2]).s, "csc", (yyvsp[-6]).s[0]); (yyval).s = resultString; }
#line 1405 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 112 "parse.y" /* yacc.c:1646  */
    { functionDeriv((yyvsp[-2]).s, "sec", (yyvsp[-6]).s[0]); (yyval).s = resultString; }
#line 1411 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 114 "parse.y" /* yacc.c:1646  */
    { functionDeriv((yyvsp[-2]).s, "cot", (yyvsp[-6]).s[0]); (yyval).s = resultString; }
#line 1417 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 116 "parse.y" /* yacc.c:1646  */
    { derivative((yyvsp[-1]).s, (yyvsp[-3]).s[0]); (yyval).s = resultString; }
#line 1423 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 118 "parse.y" /* yacc.c:1646  */
    { (yyval).s = "0"; }
#line 1429 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 122 "parse.y" /* yacc.c:1646  */
    { 
		combineStruct(&((yyval)), &((yyvsp[-2])), &((yyvsp[0])), " + ");
	}
#line 1437 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 125 "parse.y" /* yacc.c:1646  */
    {
		combineStruct(&((yyval)), &((yyvsp[-2])), &((yyvsp[0])), " - ");
	}
#line 1445 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 131 "parse.y" /* yacc.c:1646  */
    { (yyval).num = (yyvsp[0]).num; (yyval).s = NULL;}
#line 1451 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 133 "parse.y" /* yacc.c:1646  */
    { (yyval).s = calloc(strlen((yyvsp[0]).s), sizeof(char)); strcpy((yyval).s, (yyvsp[0]).s); }
#line 1457 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 135 "parse.y" /* yacc.c:1646  */
    { (yyval).num = (yyvsp[-1]).num; }
#line 1463 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 1467 "parse.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 138 "parse.y" /* yacc.c:1906  */


/**
 * Function for modulo of two doubles
 */
double calcMod(double a,double b) {
	int intA = a;
	int intB = b;
	if (intA != (double) a || intB != (double) b) {
		printf("Double was cast to integer. (%d %% %d)\n", intA, intB);
	}

	return (double) (intA % intB);
}

/** 
 * Calculate the derivative of the given string in referance to the given
 * character 'ref'
 * Example:
 * s = '2x^2'
 * ref = 'x'
 * answer = '4x'
 */
void derivative(char * s, char ref) {
  	char * token = NULL;
  	char * nextToken = NULL;
  	char * result = calloc(arraySize, sizeof(char));
  	char * individualTerm = calloc(arraySize, sizeof(char));;

  	/* Break the given equation into tokens seperated by spaces */
  	token = strtok_r(s, " ", &nextToken);

  	while (token != NULL) {
    	double coef = 1;
    	double exponent = 0;

    	char * coefString = calloc(arraySize, sizeof(char));
    	char * base = calloc(arraySize, sizeof(char));
    	char * expString = calloc(arraySize, sizeof(char));
    	char * variables = calloc(arraySize, sizeof(char)); // Used to hold other variables no being derived
    	int negative = 0;

    	/* --------------------------------------------------------- */
    	/* Break the string into 4 parts - coeficient, variables, base, exponent */
    	if(strlen(token) > 1 && token[0] == '-') {
    		negative = 1;
    		token++;
    	}

    	/* Remove any coefficient from the front */
    	int coefIndex = 0;
    	while(token[0] != '\0' && isdigit(token[0])) {
    		coefString[coefIndex] = token[0];
    		token++;
    		coefIndex++;
    	}
    	
    	//Remove variables not being derived
		int varIndex = 0;
		while(token[0] != '\0') {
			/* We have found the variable to derive by */
			if(token[0] == ref) {
				base[0] = token[0];
				token++;
				/* Is there an exponent for the variable */
				if(token[0] == '^') {
					token++;
					/* Remove all the digits for the exponent */
					int index = 0;
					while(isdigit(token[0]) || token[0] == '-'){
						expString[index] = token[0];
						token++;
						index++;
					}
				}
			}
			else {
				/* Add it to the string of not derived variables */
				variables[varIndex] = token[0];
				token++;
				varIndex++;
			}
			
		}

    	/* Done splitting string */
    	/* --------------------------------------------------------- */
    	
    	/* --------------------------------------------------------- */
    	/* Convert strings to doubles */
    	if(coefString != NULL && strlen(coefString) > 0) {
    		coef = atof(coefString);
    	}

    	/* Multiply the coef by the exponent and drop by 1 */
    	if(expString != NULL && strlen(expString) > 0) {
    		exponent = atof(expString);
    		coef *= exponent;
    		exponent -= 1;
    	}
    	/* Done splitting strings */
    	/* --------------------------------------------------------- */
    	
    	/* --------------------------------------------------------- */
    	/* Make result string */
    	if(base != NULL && strlen(base) > 0 ) {
    		if(exponent != 0 && coef != 1) {
    			if(exponent == 1) {
    				snprintf(individualTerm, arraySize, "%G%s%s", coef, variables, base);
    			}
    			else {
    				snprintf(individualTerm, arraySize, "%G%s%s^%G", coef, variables, base, exponent);
    			}
    		}
    		else if(exponent == 0 && coef != 1) {
    			snprintf(individualTerm, arraySize, "%G%s", coef, variables);
    		}
    		else if(exponent != 0 && coef == 1) {
    			printf("Here\n");
    			snprintf(individualTerm, arraySize, "%s%s^%G", variables, base, exponent);
    		}
    		else if(exponent == 0 && coef == 1) {
    			if(strlen(variables) > 0)
    				snprintf(individualTerm, arraySize, "%s", variables);
    			else {
    				snprintf(individualTerm, arraySize, "%s", "1");
    			}
    		}
	    	else {
	    		printf("Derivative error\n");
	    	}

    	}
    	else {
    		if(variables[0] == '+' || variables[0] == '-') {
    			snprintf(individualTerm, arraySize, " %s ", variables);
    		}
    		else {
    			individualTerm[0] = '\0';
    			result[strlen(result) - 2] = '\0';
    		}
    	}

    	if(strlen(individualTerm) != 0) {
    		//Double negative
    		if(individualTerm[0] == '-') {
    			individualTerm++;

    			/* Flip negative */
    			if(negative) {
    				negative = 0;
    			}
    			else
    				negative = 1;
    		}

    		/* Is the term negative */
    		if(negative == 1) {
    			int end = strlen(result);
    			if(end - 2 < 0) {
    				result[0] = '-';
    			}
    			else if(result[end - 2] == '-') {
    				result[end - 2] = '+';
    			}
    			else {
    				result[end - 2] = '-';
    			}
    		}
    		strcat(result, individualTerm);
    	}
    	/* Done building result string */
    	/* --------------------------------------------------------- */

    	free(coefString);
    	free(base);
    	free(expString);
    	free(variables);

    	//Get the next token
    	token = strtok_r(NULL, " ", &nextToken);
  	}

  	if(result[0] == '\0') {
  		//No string to copy
  		resultString[0] = '\0';
  	}
  	else {
	  	//Remove any numbers at the front that are null
	  	while(!isalpha(result[0]) && !isdigit(result[0]) && result[0] != '-') {
	  		result++;
	  	}

  		strncpy(resultString, result, arraySize);
 	}



  	//free(result);
  	//free(individualTerm);
}

/**
 * Calculate the derivative of various functions
 * sin, cos, tan, 
 */
void functionDeriv(char * s, char * function, char ref) {
	char * original = calloc(strlen(s), sizeof(char));
	//Copy original string
	strcpy(original, s);
	//Get the derivative of the inner function
	derivative(s, ref);

	//Copy the derivative string
	char * deriv = calloc(strlen(resultString), sizeof(char));
	strcpy(deriv, resultString);

	/* SIN */
	if(strcmp(function, "sin") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "cos(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, arraySize, "(%s)cos(%s)", deriv, original);
		}

	}
	/* COS */
	else if(strcmp(function, "cos") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "-sin(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, arraySize, "-(%s)sin(%s)", deriv, original);
		}

	}
	/* TAN */
	else if(strcmp(function, "tan") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "sec^2(%s)", original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, arraySize, "(%s)sec^2(%s)", deriv, original);
		}
	}
	/* CSC */
	else if(strcmp(function, "csc") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "-csc(%s)cot(%s)", original, original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			/* Double negative */
			if(deriv[0] == '-') {
				deriv++;
				snprintf(resultString, arraySize, "(%s)csc(%s)cot(%s)", deriv, original, original);
			}
			else {
				snprintf(resultString, arraySize, "-(%s)csc(%s)cot(%s)", deriv, original, original);
			}
		}
	}
	/* SEC */
	else if(strcmp(function, "sec") == 0) {
		if(strlen(deriv) == 1 && deriv[0] == '1') {
			snprintf(resultString, arraySize, "sec(%s)tan(%s)", original, original);
		}
		else if(strlen(deriv) > 0 && deriv[0] != '0') {
			snprintf(resultString, arraySize, "(%s)sec(%s)tan(%s)", deriv, original, original);
		}
	}

	free(original);
	free(deriv);

}

/**
 * Combined the left and right data into the end struct
 * bin is used for the addition or subtraction
 */
void combineStruct(struct data_s * end, struct data_s * left, struct data_s * right, char * bin) {
	//Allocate for string
	end->s = calloc(arraySize, sizeof(char));

	//Copy left data
	if(left->s != NULL){ 
		//printf("left string %s\n", left->s);
		strcat(end->s, left->s);
		strcat(end->s, bin);
		free(left->s);
	} 
	else {
		//printf("left number %G\n", left->num);
		char * temp = calloc(arraySize, sizeof(char));
		snprintf(temp, arraySize, "%G", left->num);
		strcat(end->s, temp);
		strcat(end->s, bin);
		free(temp);
	}

	//Copy right data
	if(right->s != NULL){ 
		//printf("right string %s\n", right->s);
		strcat(end->s, right->s);
		free(right->s);
	} 
	else {
		//printf("right number %G\n", right->num);
		char * temp = calloc(arraySize, sizeof(char));
		snprintf(temp, arraySize, "%G", right->num);
		strcat(end->s, temp);
		free(temp);
	}

	//printf("Final - %s\n", end->s);
}

int main() 
{ 
	yyparse();
}


