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
#line 1 "fir_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include "ast/all.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 84 "fir_parser.tab.c"

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
#ifndef YY_YY_FIR_PARSER_TAB_H_INCLUDED
# define YY_YY_FIR_PARSER_TAB_H_INCLUDED
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
    tAND = 258,
    tOR = 259,
    tSIZEOF = 260,
    tTYPE_STRING = 261,
    tTYPE_INT = 262,
    tTYPE_FLOAT = 263,
    tTYPE_VOID = 264,
    tINPUT = 265,
    tWRITE = 266,
    tWRITELN = 267,
    tIF = 268,
    tTHEN = 269,
    tELSE = 270,
    tWHILE = 271,
    tDO = 272,
    tFINALLY = 273,
    tLEAVE = 274,
    tRESTART = 275,
    tRETURN = 276,
    tINTEGER = 277,
    tFLOAT = 278,
    tID = 279,
    tSTRING = 280,
    tNULL = 281,
    tNE = 282,
    tEQ = 283,
    tLE = 284,
    tGE = 285,
    tUMINUS = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "fir_parser.y"

  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double		d;	/* double value */
  std::string          *s;	/* symbol name or string literal */

  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lval;
  cdk::basic_type      *types;

  fir::block_node      *block;
  fir::body_node       *body;
  fir::prologue_node   *prologue;

#line 193 "fir_parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<cdk::compiler> compiler);

#endif /* !YY_YY_FIR_PARSER_TAB_H_INCLUDED  */

/* Second part of user prologue.  */
#line 82 "fir_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 213 "fir_parser.tab.c"


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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   424

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


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
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
      44,    45,    37,    35,    43,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      31,    27,    34,    42,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,    28,     2,     2,     2,
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
      25,    26,    29,    30,    32,    33,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    88,    91,    92,    95,    96,    97,   100,
     101,   102,   105,   106,   109,   110,   113,   114,   117,   118,
     119,   120,   123,   126,   127,   130,   131,   132,   135,   138,
     139,   140,   141,   142,   143,   146,   147,   148,   149,   150,
     151,   154,   155,   156,   157,   158,   159,   160,   163,   166,
     169,   170,   173,   174,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   190,   191,   194,   195,   198,
     199,   202,   203,   206,   208,   210,   211,   212,   213,   214,
     216,   217,   218,   219,   220,   221,   222,   223,   225,   226,
     227,   229,   230,   231,   232,   233,   234,   235,   238,   239,
     240,   241,   244,   245,   246,   247,   250,   251,   252,   253
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tAND", "tOR", "tSIZEOF", "tTYPE_STRING",
  "tTYPE_INT", "tTYPE_FLOAT", "tTYPE_VOID", "tINPUT", "tWRITE", "tWRITELN",
  "tIF", "tTHEN", "tELSE", "tWHILE", "tDO", "tFINALLY", "tLEAVE",
  "tRESTART", "tRETURN", "tINTEGER", "tFLOAT", "tID", "tSTRING", "tNULL",
  "'='", "'~'", "tNE", "tEQ", "'<'", "tLE", "tGE", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "tUMINUS", "';'", "'?'", "','", "'('", "')'", "'@'",
  "'{'", "'}'", "'['", "']'", "$accept", "file", "seq_decl", "decl",
  "vardec", "opt_vardecs", "funcvar", "funcvars", "data_type", "void_type",
  "opt_init", "argdecs", "argdec", "fundec", "fundef", "body", "prologue",
  "block", "seq_inst", "opt_inst", "inst", "ifs", "while", "opt_expr",
  "seq_expr", "expr", "lval", "literal", "integer", "float", "string", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,   126,   282,
     283,    60,   284,   285,    62,    43,    45,    42,    47,    37,
     286,    59,    63,    44,    40,    41,    64,   123,   125,    91,
      93
};
# endif

#define YYPACT_NINF (-139)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,  -139,  -139,  -139,  -139,    -3,    13,     3,  -139,    28,
      46,    98,  -139,  -139,    44,  -139,  -139,  -139,    -6,    57,
      86,    71,    92,    97,  -139,   223,    -3,  -139,    35,    87,
      -3,    88,    95,    99,  -139,  -139,   100,  -139,  -139,   223,
     223,   223,   223,  -139,   223,   337,    -9,  -139,  -139,  -139,
     136,   141,   -20,  -139,    -3,  -139,    -3,    64,    -3,    -3,
     223,   223,   360,  -139,  -139,   249,    62,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,  -139,   223,  -139,  -139,    -3,    77,    93,   158,    43,
     159,   182,   267,   142,   162,   337,   163,  -139,   360,   385,
     147,   147,   121,   121,   121,   121,    67,    67,  -139,  -139,
    -139,   337,   116,  -139,   175,   179,   185,    -3,  -139,   192,
     188,  -139,  -139,    43,  -139,  -139,   180,   223,   223,  -139,
     186,    50,    -3,   -10,   195,   196,    -3,   212,   209,   216,
    -139,  -139,   223,   337,   138,  -139,    43,   195,   221,   226,
     223,   223,   223,   223,   -15,     0,  -139,  -139,   195,   214,
    -139,  -139,  -139,   286,  -139,   220,   230,   186,    50,   160,
    -139,  -139,   215,   186,   231,   197,   213,   325,   348,   225,
    -139,   227,  -139,  -139,  -139,  -139,  -139,   223,  -139,    43,
    -139,  -139,  -139,   186,  -139,  -139,   195,   195,  -139,  -139,
     337,  -139,  -139,   258,   246,   195,   195,  -139,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    18,    19,    20,    22,     0,     0,     3,     4,     0,
       0,     0,     7,     8,     0,     1,     5,     6,    23,     0,
       0,     0,     0,     0,    21,     0,    25,    11,    23,     9,
      25,     0,     0,     0,   106,   107,    98,   108,   105,     0,
       0,     0,     0,    91,     0,    24,    96,    73,   102,   103,
     104,     0,     0,    26,    25,    10,    25,     0,    25,    25,
       0,    69,    90,    89,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,   109,    28,     0,    29,     0,     0,    32,
       0,     0,     0,     0,    70,    71,    94,    95,    86,    87,
      85,    82,    80,    81,    83,    84,    75,    76,    77,    78,
      79,    74,     0,    27,     0,     0,     0,    12,    37,    42,
      31,    30,    39,    34,    33,    93,    92,     0,     0,    99,
       0,     0,    12,    41,    52,     0,    13,     0,     0,     0,
      38,    40,     0,    72,     0,    43,     0,    52,     0,    44,
       0,     0,     0,     0,     0,     0,    63,    64,    53,     0,
      50,    54,    55,     0,    16,     0,    14,     0,     0,     0,
     100,    35,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,    61,    51,    49,    56,    17,     0,    46,     0,
     101,    48,    45,     0,    57,    58,     0,     0,    60,    62,
      15,    36,    47,    65,    67,     0,     0,    66,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,   268,  -139,   144,   155,  -139,     1,  -139,
     264,    26,   189,  -139,  -139,   -60,  -139,   -59,  -139,   130,
    -138,  -139,  -139,  -139,  -119,   -25,  -139,  -129,  -139,  -139,
    -139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,   134,   135,   136,    51,    11,
      27,    52,    53,    12,    13,   118,   133,   157,   158,   159,
     160,   161,   162,    93,    94,   163,    46,    47,    48,    49,
      50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    10,   146,     1,     2,     3,    14,   179,    10,     1,
       2,     3,     4,    15,    62,    63,    64,    65,    80,    66,
     183,    25,   181,    85,   148,    86,   180,   119,     5,   122,
     119,   175,   176,    81,     5,    92,    95,   117,    26,   189,
      82,   182,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    57,   112,   203,   204,
     140,   119,    25,   141,   119,    67,    68,   207,   208,    17,
      18,   145,    34,    35,   149,    37,    38,   114,    24,    54,
      87,    28,    88,    19,    90,    91,   171,   119,    20,   116,
     117,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,   143,   144,    77,    78,    79,    85,   188,    89,
      29,   114,    97,   115,   192,    30,    31,   169,   137,    67,
      68,    32,    21,   116,   117,    95,    95,   177,   178,   201,
     119,    56,    58,   137,   202,    22,    85,   137,   120,    59,
      23,    67,    68,    60,    61,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    75,    76,    77,    78,
      79,    83,   200,    67,    68,    84,   129,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    71,    72,
      73,    74,    75,    76,    77,    78,    79,   126,   170,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      33,    85,    85,   121,   123,   127,   150,   151,   152,   130,
     190,   153,   128,   131,   154,   155,   156,    34,    35,    36,
      37,    38,   114,    39,   139,    85,   138,   124,    33,   142,
      40,    41,   132,   117,   116,   117,   166,   164,   194,    42,
     127,    43,   117,   167,    44,    34,    35,    36,    37,    38,
     168,    39,    67,    68,   195,   173,   127,   187,    40,    41,
     174,   186,   184,   191,   206,   193,   198,    42,   199,    43,
      67,    68,    44,   205,   113,    16,   147,   172,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    67,
      68,   165,    55,     0,    96,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,   125,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,   185,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   196,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   197,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    67,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
      25,     0,   131,     6,     7,     8,     5,    22,     7,     6,
       7,     8,     9,     0,    39,    40,    41,    42,    27,    44,
     158,    27,    22,    43,    34,    45,    41,    86,    31,    89,
      89,   150,   151,    42,    31,    60,    61,    47,    44,   168,
      49,    41,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    30,    82,   196,   197,
     120,   120,    27,   123,   123,     3,     4,   205,   206,    41,
      24,   130,    22,    23,   133,    25,    26,    34,    34,    44,
      54,    24,    56,    37,    58,    59,   146,   146,    42,    46,
      47,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   127,   128,    37,    38,    39,    43,   167,    45,
      24,    34,    50,    36,   173,    44,    24,   142,   117,     3,
       4,    24,    24,    46,    47,   150,   151,   152,   153,   189,
     189,    44,    44,   132,   193,    37,    43,   136,    45,    44,
      42,     3,     4,    44,    44,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    35,    36,    37,    38,
      39,    25,   187,     3,     4,    24,    50,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    45,    50,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       5,    43,    43,    45,    45,    43,    11,    12,    13,    34,
      50,    16,    49,    34,    19,    20,    21,    22,    23,    24,
      25,    26,    34,    28,    36,    43,    34,    45,     5,    49,
      35,    36,    47,    47,    46,    47,    24,    41,    41,    44,
      43,    46,    47,    34,    49,    22,    23,    24,    25,    26,
      34,    28,     3,     4,    41,    34,    43,    27,    35,    36,
      34,    41,    48,    48,    18,    34,    41,    44,    41,    46,
       3,     4,    49,    15,    85,     7,   132,   147,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     3,
       4,   136,    28,    -1,    45,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    17,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     3,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    31,    52,    53,    54,    55,
      59,    60,    64,    65,    59,     0,    54,    41,    24,    37,
      42,    24,    37,    42,    34,    27,    44,    61,    24,    24,
      44,    24,    24,     5,    22,    23,    24,    25,    26,    28,
      35,    36,    44,    46,    49,    76,    77,    78,    79,    80,
      81,    59,    62,    63,    44,    61,    44,    62,    44,    44,
      44,    44,    76,    76,    76,    76,    76,     3,     4,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      27,    42,    49,    25,    24,    43,    45,    62,    62,    45,
      62,    62,    76,    74,    75,    76,    45,    50,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    63,    34,    36,    46,    47,    66,    68,
      45,    45,    66,    45,    45,    45,    45,    43,    49,    50,
      34,    34,    47,    67,    56,    57,    58,    59,    34,    36,
      66,    66,    49,    76,    76,    68,    78,    56,    34,    68,
      11,    12,    13,    16,    19,    20,    21,    68,    69,    70,
      71,    72,    73,    76,    41,    57,    24,    34,    34,    76,
      50,    66,    70,    34,    34,    75,    75,    76,    76,    22,
      41,    22,    41,    71,    48,    41,    41,    27,    68,    78,
      50,    48,    68,    34,    41,    41,    14,    17,    41,    41,
      76,    66,    68,    71,    71,    15,    18,    71,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    60,    61,    61,    62,    62,    62,    63,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    67,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    78,    78,    78,    78,    79,    80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     1,     3,
       4,     3,     0,     1,     2,     4,     2,     3,     1,     1,
       1,     3,     1,     0,     2,     0,     1,     3,     2,     5,
       6,     6,     5,     6,     6,     9,    10,     6,     7,     6,
       7,     2,     1,     3,     3,     5,     4,     6,     4,     4,
       1,     2,     0,     1,     1,     1,     2,     3,     3,     2,
       3,     2,     3,     1,     1,     4,     6,     4,     6,     0,
       1,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     4,     4,     3,     3,     1,     2,     1,     4,
       6,     7,     1,     1,     1,     1,     1,     1,     1,     2
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
        yyerror (compiler, YY_("syntax error: cannot back up")); \
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
                  Type, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (compiler);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, compiler);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, std::shared_ptr<cdk::compiler> compiler)
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
                                              , compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYUSE (yyvaluep);
  YYUSE (compiler);
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
yyparse (std::shared_ptr<cdk::compiler> compiler)
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
  case 2:
#line 87 "fir_parser.y"
                           { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1560 "fir_parser.tab.c"
    break;

  case 3:
#line 88 "fir_parser.y"
                           { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1566 "fir_parser.tab.c"
    break;

  case 4:
#line 91 "fir_parser.y"
                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));}
#line 1572 "fir_parser.tab.c"
    break;

  case 5:
#line 92 "fir_parser.y"
                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence));}
#line 1578 "fir_parser.tab.c"
    break;

  case 6:
#line 95 "fir_parser.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 1584 "fir_parser.tab.c"
    break;

  case 7:
#line 96 "fir_parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1590 "fir_parser.tab.c"
    break;

  case 8:
#line 97 "fir_parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1596 "fir_parser.tab.c"
    break;

  case 9:
#line 100 "fir_parser.y"
                                           { (yyval.node) = new fir::variable_declaration_node(LINE, (yyvsp[-2].type), '?', *(yyvsp[0].s), nullptr); delete (yyvsp[0].s); }
#line 1602 "fir_parser.tab.c"
    break;

  case 10:
#line 101 "fir_parser.y"
                                           { (yyval.node) = new fir::variable_declaration_node(LINE, (yyvsp[-3].type), '*', *(yyvsp[-1].s), (yyvsp[0].expression)); delete (yyvsp[-1].s); }
#line 1608 "fir_parser.tab.c"
    break;

  case 11:
#line 102 "fir_parser.y"
                                           { (yyval.node) = new fir::variable_declaration_node(LINE, (yyvsp[-2].type), '\0', *(yyvsp[-1].s), (yyvsp[0].expression)); delete (yyvsp[-1].s); }
#line 1614 "fir_parser.tab.c"
    break;

  case 12:
#line 105 "fir_parser.y"
                           { (yyval.sequence) = NULL; }
#line 1620 "fir_parser.tab.c"
    break;

  case 13:
#line 106 "fir_parser.y"
                            { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1626 "fir_parser.tab.c"
    break;

  case 14:
#line 109 "fir_parser.y"
                                      { (yyval.node) = new fir::variable_declaration_node(LINE,(yyvsp[-1].type), '\0', *(yyvsp[0].s), nullptr); delete (yyvsp[0].s); }
#line 1632 "fir_parser.tab.c"
    break;

  case 15:
#line 110 "fir_parser.y"
                                      { (yyval.node) = new fir::variable_declaration_node(LINE,(yyvsp[-3].type), '\0', *(yyvsp[-2].s), (yyvsp[0].expression)); delete (yyvsp[-2].s);      }
#line 1638 "fir_parser.tab.c"
    break;

  case 16:
#line 113 "fir_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1644 "fir_parser.tab.c"
    break;

  case 17:
#line 114 "fir_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1650 "fir_parser.tab.c"
    break;

  case 18:
#line 117 "fir_parser.y"
                                 { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 1656 "fir_parser.tab.c"
    break;

  case 19:
#line 118 "fir_parser.y"
                                 { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
#line 1662 "fir_parser.tab.c"
    break;

  case 20:
#line 119 "fir_parser.y"
                                 { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
#line 1668 "fir_parser.tab.c"
    break;

  case 21:
#line 120 "fir_parser.y"
                                 { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1674 "fir_parser.tab.c"
    break;

  case 22:
#line 123 "fir_parser.y"
                                { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID);   }
#line 1680 "fir_parser.tab.c"
    break;

  case 23:
#line 126 "fir_parser.y"
                           { (yyval.expression) = nullptr; /* must be nullptr, not NIL */ }
#line 1686 "fir_parser.tab.c"
    break;

  case 24:
#line 127 "fir_parser.y"
                           { (yyval.expression) = (yyvsp[0].expression); }
#line 1692 "fir_parser.tab.c"
    break;

  case 25:
#line 130 "fir_parser.y"
                                  { (yyval.sequence) = new cdk::sequence_node(LINE);  }
#line 1698 "fir_parser.tab.c"
    break;

  case 26:
#line 131 "fir_parser.y"
                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1704 "fir_parser.tab.c"
    break;

  case 27:
#line 132 "fir_parser.y"
                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1710 "fir_parser.tab.c"
    break;

  case 28:
#line 135 "fir_parser.y"
                             { (yyval.node) = new fir::variable_declaration_node(LINE, (yyvsp[-1].type), '\0', *(yyvsp[0].s), nullptr); }
#line 1716 "fir_parser.tab.c"
    break;

  case 29:
#line 138 "fir_parser.y"
                                                 { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-4].type), '\0', *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1722 "fir_parser.tab.c"
    break;

  case 30:
#line 139 "fir_parser.y"
                                                 { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-5].type), '?', *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1728 "fir_parser.tab.c"
    break;

  case 31:
#line 140 "fir_parser.y"
                                                 { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-5].type), '*', *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1734 "fir_parser.tab.c"
    break;

  case 32:
#line 141 "fir_parser.y"
                                                 { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-4].type), '\0', *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1740 "fir_parser.tab.c"
    break;

  case 33:
#line 142 "fir_parser.y"
                                                 { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-5].type), '?', *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1746 "fir_parser.tab.c"
    break;

  case 34:
#line 143 "fir_parser.y"
                                                 { (yyval.node) = new fir::function_declaration_node(LINE, (yyvsp[-5].type), '*', *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 1752 "fir_parser.tab.c"
    break;

  case 35:
#line 146 "fir_parser.y"
                                                                     { (yyval.node) = new fir::function_definition_node(LINE, (yyvsp[-8].type), '\0', *(yyvsp[-7].s), (yyvsp[-5].sequence), (yyvsp[-1].expression), (yyvsp[0].body)); delete (yyvsp[-7].s); }
#line 1758 "fir_parser.tab.c"
    break;

  case 36:
#line 147 "fir_parser.y"
                                                                     { (yyval.node) = new fir::function_definition_node(LINE, (yyvsp[-9].type), '*', *(yyvsp[-7].s), (yyvsp[-5].sequence), (yyvsp[-1].expression), (yyvsp[0].body)); delete (yyvsp[-7].s); }
#line 1764 "fir_parser.tab.c"
    break;

  case 37:
#line 148 "fir_parser.y"
                                                                     { (yyval.node) = new fir::function_definition_node(LINE, (yyvsp[-5].type), '\0', *(yyvsp[-4].s), (yyvsp[-2].sequence), nullptr, (yyvsp[0].body)); delete (yyvsp[-4].s); }
#line 1770 "fir_parser.tab.c"
    break;

  case 38:
#line 149 "fir_parser.y"
                                                                     { (yyval.node) = new fir::function_definition_node(LINE, (yyvsp[-6].type), '*', *(yyvsp[-4].s), (yyvsp[-2].sequence), nullptr, (yyvsp[0].body)); delete (yyvsp[-4].s); }
#line 1776 "fir_parser.tab.c"
    break;

  case 39:
#line 150 "fir_parser.y"
                                                                     { (yyval.node) = new fir::function_definition_node(LINE, (yyvsp[-5].type), '\0', *(yyvsp[-4].s), (yyvsp[-2].sequence), nullptr, (yyvsp[0].body)); delete (yyvsp[-4].s); }
#line 1782 "fir_parser.tab.c"
    break;

  case 40:
#line 151 "fir_parser.y"
                                                                     { (yyval.node) = new fir::function_definition_node(LINE, (yyvsp[-6].type), '*', *(yyvsp[-4].s), (yyvsp[-2].sequence), nullptr, (yyvsp[0].body)); delete (yyvsp[-4].s); }
#line 1788 "fir_parser.tab.c"
    break;

  case 41:
#line 154 "fir_parser.y"
                                               { (yyval.body) = new fir::body_node(LINE, (yyvsp[0].prologue), nullptr, nullptr); }
#line 1794 "fir_parser.tab.c"
    break;

  case 42:
#line 155 "fir_parser.y"
                                               { (yyval.body) = new fir::body_node(LINE, nullptr, (yyvsp[0].block), nullptr); }
#line 1800 "fir_parser.tab.c"
    break;

  case 43:
#line 156 "fir_parser.y"
                                               { (yyval.body) = new fir::body_node(LINE, nullptr, nullptr, (yyvsp[0].block)); }
#line 1806 "fir_parser.tab.c"
    break;

  case 44:
#line 157 "fir_parser.y"
                                               { (yyval.body) = new fir::body_node(LINE, (yyvsp[-1].prologue), (yyvsp[0].block), nullptr); }
#line 1812 "fir_parser.tab.c"
    break;

  case 45:
#line 158 "fir_parser.y"
                                               { (yyval.body) = new fir::body_node(LINE, (yyvsp[-3].prologue), nullptr, (yyvsp[0].block)); }
#line 1818 "fir_parser.tab.c"
    break;

  case 46:
#line 159 "fir_parser.y"
                                               { (yyval.body) = new fir::body_node(LINE, nullptr, (yyvsp[-3].block), (yyvsp[0].block)); }
#line 1824 "fir_parser.tab.c"
    break;

  case 47:
#line 160 "fir_parser.y"
                                               { (yyval.body) = new fir::body_node(LINE, (yyvsp[-4].prologue), (yyvsp[-3].block), (yyvsp[0].block)); }
#line 1830 "fir_parser.tab.c"
    break;

  case 48:
#line 163 "fir_parser.y"
                                            { (yyval.prologue) = new fir::prologue_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1836 "fir_parser.tab.c"
    break;

  case 49:
#line 166 "fir_parser.y"
                                            { (yyval.block) = new fir::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1842 "fir_parser.tab.c"
    break;

  case 50:
#line 169 "fir_parser.y"
                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1848 "fir_parser.tab.c"
    break;

  case 51:
#line 170 "fir_parser.y"
                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1854 "fir_parser.tab.c"
    break;

  case 52:
#line 173 "fir_parser.y"
                           { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1860 "fir_parser.tab.c"
    break;

  case 53:
#line 174 "fir_parser.y"
                           { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1866 "fir_parser.tab.c"
    break;

  case 54:
#line 177 "fir_parser.y"
                                     { (yyval.node) = (yyvsp[0].node); }
#line 1872 "fir_parser.tab.c"
    break;

  case 55:
#line 178 "fir_parser.y"
                                     { (yyval.node) = (yyvsp[0].node); }
#line 1878 "fir_parser.tab.c"
    break;

  case 56:
#line 179 "fir_parser.y"
                                     { (yyval.node) = new fir::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1884 "fir_parser.tab.c"
    break;

  case 57:
#line 180 "fir_parser.y"
                                     { (yyval.node) = new fir::write_node(LINE, (yyvsp[-1].sequence), false); }
#line 1890 "fir_parser.tab.c"
    break;

  case 58:
#line 181 "fir_parser.y"
                                     { (yyval.node) = new fir::write_node(LINE, (yyvsp[-1].sequence), true); }
#line 1896 "fir_parser.tab.c"
    break;

  case 59:
#line 182 "fir_parser.y"
                                     { (yyval.node) = new fir::leave_node(LINE); }
#line 1902 "fir_parser.tab.c"
    break;

  case 60:
#line 183 "fir_parser.y"
                                     { (yyval.node) = new fir::leave_node(LINE, (yyvsp[-1].i)); }
#line 1908 "fir_parser.tab.c"
    break;

  case 61:
#line 184 "fir_parser.y"
                                     { (yyval.node) = new fir::restart_node(LINE); }
#line 1914 "fir_parser.tab.c"
    break;

  case 62:
#line 185 "fir_parser.y"
                                     { (yyval.node) = new fir::restart_node(LINE, (yyvsp[-1].i)); }
#line 1920 "fir_parser.tab.c"
    break;

  case 63:
#line 186 "fir_parser.y"
                                     { (yyval.node) = new fir::return_node(LINE); }
#line 1926 "fir_parser.tab.c"
    break;

  case 64:
#line 187 "fir_parser.y"
                                     { (yyval.node) = (yyvsp[0].block); }
#line 1932 "fir_parser.tab.c"
    break;

  case 65:
#line 190 "fir_parser.y"
                                              { (yyval.node) = new fir::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1938 "fir_parser.tab.c"
    break;

  case 66:
#line 191 "fir_parser.y"
                                              { (yyval.node) = new fir::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1944 "fir_parser.tab.c"
    break;

  case 67:
#line 194 "fir_parser.y"
                                                  { (yyval.node) = new fir::while_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node), nullptr); }
#line 1950 "fir_parser.tab.c"
    break;

  case 68:
#line 195 "fir_parser.y"
                                                  { (yyval.node) = new fir::while_node(LINE, (yyvsp[-4].expression), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1956 "fir_parser.tab.c"
    break;

  case 69:
#line 198 "fir_parser.y"
                           { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1962 "fir_parser.tab.c"
    break;

  case 70:
#line 199 "fir_parser.y"
                           { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1968 "fir_parser.tab.c"
    break;

  case 71:
#line 202 "fir_parser.y"
                                 { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression)); }
#line 1974 "fir_parser.tab.c"
    break;

  case 72:
#line 203 "fir_parser.y"
                                 { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 1980 "fir_parser.tab.c"
    break;

  case 73:
#line 206 "fir_parser.y"
                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 1986 "fir_parser.tab.c"
    break;

  case 74:
#line 208 "fir_parser.y"
                                      { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lval), (yyvsp[0].expression)); }
#line 1992 "fir_parser.tab.c"
    break;

  case 75:
#line 210 "fir_parser.y"
                                      { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1998 "fir_parser.tab.c"
    break;

  case 76:
#line 211 "fir_parser.y"
                                      { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2004 "fir_parser.tab.c"
    break;

  case 77:
#line 212 "fir_parser.y"
                                      { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2010 "fir_parser.tab.c"
    break;

  case 78:
#line 213 "fir_parser.y"
                                      { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2016 "fir_parser.tab.c"
    break;

  case 79:
#line 214 "fir_parser.y"
                                      { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2022 "fir_parser.tab.c"
    break;

  case 80:
#line 216 "fir_parser.y"
                                      { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2028 "fir_parser.tab.c"
    break;

  case 81:
#line 217 "fir_parser.y"
                                      { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2034 "fir_parser.tab.c"
    break;

  case 82:
#line 218 "fir_parser.y"
                                      { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2040 "fir_parser.tab.c"
    break;

  case 83:
#line 219 "fir_parser.y"
                                      { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2046 "fir_parser.tab.c"
    break;

  case 84:
#line 220 "fir_parser.y"
                                      { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2052 "fir_parser.tab.c"
    break;

  case 85:
#line 221 "fir_parser.y"
                                      { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2058 "fir_parser.tab.c"
    break;

  case 86:
#line 222 "fir_parser.y"
                                      { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2064 "fir_parser.tab.c"
    break;

  case 87:
#line 223 "fir_parser.y"
                                      { (yyval.expression) = new cdk::or_node (LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2070 "fir_parser.tab.c"
    break;

  case 88:
#line 225 "fir_parser.y"
                                      { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 2076 "fir_parser.tab.c"
    break;

  case 89:
#line 226 "fir_parser.y"
                                      { (yyval.expression) = new fir::identity_node(LINE, (yyvsp[0].expression));}
#line 2082 "fir_parser.tab.c"
    break;

  case 90:
#line 227 "fir_parser.y"
                                      { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 2088 "fir_parser.tab.c"
    break;

  case 91:
#line 229 "fir_parser.y"
                                      { (yyval.expression) = new fir::input_node(LINE); }
#line 2094 "fir_parser.tab.c"
    break;

  case 92:
#line 230 "fir_parser.y"
                                      { (yyval.expression) = new fir::function_call_node(LINE, *(yyvsp[-3].s), (yyvsp[-1].sequence)); delete (yyvsp[-3].s); }
#line 2100 "fir_parser.tab.c"
    break;

  case 93:
#line 231 "fir_parser.y"
                                      { (yyval.expression) = new fir::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 2106 "fir_parser.tab.c"
    break;

  case 94:
#line 232 "fir_parser.y"
                                      { (yyval.expression) = (yyvsp[-1].expression); }
#line 2112 "fir_parser.tab.c"
    break;

  case 95:
#line 233 "fir_parser.y"
                                      { (yyval.expression) = new fir::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 2118 "fir_parser.tab.c"
    break;

  case 96:
#line 234 "fir_parser.y"
                                      { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lval)); }
#line 2124 "fir_parser.tab.c"
    break;

  case 97:
#line 235 "fir_parser.y"
                                      { (yyval.expression) = new fir::address_of_node(LINE, (yyvsp[-1].lval)); }
#line 2130 "fir_parser.tab.c"
    break;

  case 98:
#line 238 "fir_parser.y"
                                                 { (yyval.lval) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 2136 "fir_parser.tab.c"
    break;

  case 99:
#line 239 "fir_parser.y"
                                                 { (yyval.lval) = new fir::index_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lval)), (yyvsp[-1].expression)); }
#line 2142 "fir_parser.tab.c"
    break;

  case 100:
#line 240 "fir_parser.y"
                                                 { (yyval.lval) = new fir::index_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].expression)); }
#line 2148 "fir_parser.tab.c"
    break;

  case 101:
#line 241 "fir_parser.y"
                                                 { (yyval.lval) = new fir::index_node(LINE, new fir::function_call_node(LINE, *(yyvsp[-6].s), (yyvsp[-4].sequence)), (yyvsp[-1].expression)); }
#line 2154 "fir_parser.tab.c"
    break;

  case 102:
#line 244 "fir_parser.y"
                       { (yyval.expression) = (yyvsp[0].expression);}
#line 2160 "fir_parser.tab.c"
    break;

  case 103:
#line 245 "fir_parser.y"
                       { (yyval.expression) = (yyvsp[0].expression);}
#line 2166 "fir_parser.tab.c"
    break;

  case 104:
#line 246 "fir_parser.y"
                       { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s));}
#line 2172 "fir_parser.tab.c"
    break;

  case 105:
#line 247 "fir_parser.y"
                       { (yyval.expression) = new fir::null_node(LINE);}
#line 2178 "fir_parser.tab.c"
    break;

  case 106:
#line 250 "fir_parser.y"
                              { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 2184 "fir_parser.tab.c"
    break;

  case 107:
#line 251 "fir_parser.y"
                              { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 2190 "fir_parser.tab.c"
    break;

  case 108:
#line 252 "fir_parser.y"
                              { (yyval.s) = (yyvsp[0].s); }
#line 2196 "fir_parser.tab.c"
    break;

  case 109:
#line 253 "fir_parser.y"
                              { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2202 "fir_parser.tab.c"
    break;


#line 2206 "fir_parser.tab.c"

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
      yyerror (compiler, YY_("syntax error"));
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
        yyerror (compiler, yymsgp);
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
                      yytoken, &yylval, compiler);
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
                  yystos[yystate], yyvsp, compiler);
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
  yyerror (compiler, YY_("memory exhausted"));
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
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, compiler);
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
#line 256 "fir_parser.y"

