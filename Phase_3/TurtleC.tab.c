/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "TurtleC.y"

#include <stdio.h>
#include <string.h>
extern FILE * yyin;
extern int current_line;
extern int current_column; 


int yylex (void);
void yyerror(const char * msg) {
	printf("Error: On line %d, column %d: %s \n", current_line, current_column, msg);
}

static char* genTempName() {
	static unsigned long long counter;

	static char buff[4096]; 
    sprintf(buff, "_temp%llu", counter++);
	return strdup(buff);
}


typedef struct {char *name; char *code;} NameAndCodeData;

// Function variables
int param_index = 0;
int is_main_function = 0;
int has_return_statement = 0;


#line 102 "TurtleC.tab.c"

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
    CALL = 258,                    /* CALL  */
    BACKSLASH = 259,               /* BACKSLASH  */
    RETURN = 260,                  /* RETURN  */
    WHILE = 261,                   /* WHILE  */
    VALID_CHAR = 262,              /* VALID_CHAR  */
    TERMINATE = 263,               /* TERMINATE  */
    UNDERSCORE = 264,              /* UNDERSCORE  */
    READ = 265,                    /* READ  */
    WRITE = 266,                   /* WRITE  */
    COLON = 267,                   /* COLON  */
    THIS = 268,                    /* THIS  */
    IF = 269,                      /* IF  */
    ELIF = 270,                    /* ELIF  */
    ELSE = 271,                    /* ELSE  */
    COMMA = 272,                   /* COMMA  */
    INTEGER_ARRAY_DATATYPE = 273,  /* INTEGER_ARRAY_DATATYPE  */
    EQUIVALENT = 274,              /* EQUIVALENT  */
    NOT_EQUIVALENT = 275,          /* NOT_EQUIVALENT  */
    SEMICOLON = 276,               /* SEMICOLON  */
    PERIOD = 277,                  /* PERIOD  */
    RETURN_TYPE_ARROW = 278,       /* RETURN_TYPE_ARROW  */
    L_BRACKET = 279,               /* L_BRACKET  */
    R_BRACKET = 280,               /* R_BRACKET  */
    TRUE = 281,                    /* TRUE  */
    FALSE = 282,                   /* FALSE  */
    GREATER_THAN_EQUAL = 283,      /* GREATER_THAN_EQUAL  */
    LESS_THAN_EQUAL = 284,         /* LESS_THAN_EQUAL  */
    GREATER_THAN = 285,            /* GREATER_THAN  */
    LESS_THAN = 286,               /* LESS_THAN  */
    NOT = 287,                     /* NOT  */
    OR = 288,                      /* OR  */
    AND = 289,                     /* AND  */
    COMMENT = 290,                 /* COMMENT  */
    L_PARENTHESIS = 291,           /* L_PARENTHESIS  */
    R_PARENTHESIS = 292,           /* R_PARENTHESIS  */
    QUOTE = 293,                   /* QUOTE  */
    ASSIGNMENT = 294,              /* ASSIGNMENT  */
    INTEGER_DATATYPE = 295,        /* INTEGER_DATATYPE  */
    L_CURLY = 296,                 /* L_CURLY  */
    R_CURLY = 297,                 /* R_CURLY  */
    NUM = 298,                     /* NUM  */
    IDENTIFIER = 299,              /* IDENTIFIER  */
    PLUS = 300,                    /* PLUS  */
    MINUS = 301,                   /* MINUS  */
    TIMES = 302,                   /* TIMES  */
    DIVIDE = 303                   /* DIVIDE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "TurtleC.y"

	char *strVal; // To hold string values of identifiers and numbers
	char *operator; // To hold string values of an operator
	NameAndCodeData nameAndCode 


#line 204 "TurtleC.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CALL = 3,                       /* CALL  */
  YYSYMBOL_BACKSLASH = 4,                  /* BACKSLASH  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_VALID_CHAR = 7,                 /* VALID_CHAR  */
  YYSYMBOL_TERMINATE = 8,                  /* TERMINATE  */
  YYSYMBOL_UNDERSCORE = 9,                 /* UNDERSCORE  */
  YYSYMBOL_READ = 10,                      /* READ  */
  YYSYMBOL_WRITE = 11,                     /* WRITE  */
  YYSYMBOL_COLON = 12,                     /* COLON  */
  YYSYMBOL_THIS = 13,                      /* THIS  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELIF = 15,                      /* ELIF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_INTEGER_ARRAY_DATATYPE = 18,    /* INTEGER_ARRAY_DATATYPE  */
  YYSYMBOL_EQUIVALENT = 19,                /* EQUIVALENT  */
  YYSYMBOL_NOT_EQUIVALENT = 20,            /* NOT_EQUIVALENT  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_PERIOD = 22,                    /* PERIOD  */
  YYSYMBOL_RETURN_TYPE_ARROW = 23,         /* RETURN_TYPE_ARROW  */
  YYSYMBOL_L_BRACKET = 24,                 /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 25,                 /* R_BRACKET  */
  YYSYMBOL_TRUE = 26,                      /* TRUE  */
  YYSYMBOL_FALSE = 27,                     /* FALSE  */
  YYSYMBOL_GREATER_THAN_EQUAL = 28,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_LESS_THAN_EQUAL = 29,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN = 30,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 31,                 /* LESS_THAN  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_OR = 33,                        /* OR  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_COMMENT = 35,                   /* COMMENT  */
  YYSYMBOL_L_PARENTHESIS = 36,             /* L_PARENTHESIS  */
  YYSYMBOL_R_PARENTHESIS = 37,             /* R_PARENTHESIS  */
  YYSYMBOL_QUOTE = 38,                     /* QUOTE  */
  YYSYMBOL_ASSIGNMENT = 39,                /* ASSIGNMENT  */
  YYSYMBOL_INTEGER_DATATYPE = 40,          /* INTEGER_DATATYPE  */
  YYSYMBOL_L_CURLY = 41,                   /* L_CURLY  */
  YYSYMBOL_R_CURLY = 42,                   /* R_CURLY  */
  YYSYMBOL_NUM = 43,                       /* NUM  */
  YYSYMBOL_IDENTIFIER = 44,                /* IDENTIFIER  */
  YYSYMBOL_PLUS = 45,                      /* PLUS  */
  YYSYMBOL_MINUS = 46,                     /* MINUS  */
  YYSYMBOL_TIMES = 47,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 48,                    /* DIVIDE  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_functions = 51,                 /* functions  */
  YYSYMBOL_function = 52,                  /* function  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_params = 54,                    /* params  */
  YYSYMBOL_statements = 55,                /* statements  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_arg_list = 57,                  /* arg_list  */
  YYSYMBOL_function_call = 58,             /* function_call  */
  YYSYMBOL_break = 59,                     /* break  */
  YYSYMBOL_read = 60,                      /* read  */
  YYSYMBOL_write = 61,                     /* write  */
  YYSYMBOL_add_operator = 62,              /* add_operator  */
  YYSYMBOL_mult_operator = 63,             /* mult_operator  */
  YYSYMBOL_term = 64,                      /* term  */
  YYSYMBOL_factor = 65,                    /* factor  */
  YYSYMBOL_numeric_expression = 66,        /* numeric_expression  */
  YYSYMBOL_assignment_statement = 67,      /* assignment_statement  */
  YYSYMBOL_variable_declaration = 68,      /* variable_declaration  */
  YYSYMBOL_variable_assignment = 69,       /* variable_assignment  */
  YYSYMBOL_array_declaration = 70,         /* array_declaration  */
  YYSYMBOL_relational_expression = 71,     /* relational_expression  */
  YYSYMBOL_while_statement = 72,           /* while_statement  */
  YYSYMBOL_return_statement = 73,          /* return_statement  */
  YYSYMBOL_if_then_else_statement = 74,    /* if_then_else_statement  */
  YYSYMBOL_if_statement = 75,              /* if_statement  */
  YYSYMBOL_else_statement = 76,            /* else_statement  */
  YYSYMBOL_elif_statement = 77,            /* elif_statement  */
  YYSYMBOL_single_comment = 78             /* single_comment  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    54,    57,    62,    62,    82,    91,    98,
     104,   105,   107,   110,   112,   114,   116,   118,   120,   122,
     124,   126,   128,   130,   134,   146,   157,   168,   170,   173,
     180,   187,   195,   203,   210,   232,   242,   248,   257,   263,
     273,   291,   299,   304,   306,   310,   313,   321,   324,   326,
     328,   330,   333,   335,   338,   345,   348,   351,   354,   357,
     360,   363
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CALL", "BACKSLASH",
  "RETURN", "WHILE", "VALID_CHAR", "TERMINATE", "UNDERSCORE", "READ",
  "WRITE", "COLON", "THIS", "IF", "ELIF", "ELSE", "COMMA",
  "INTEGER_ARRAY_DATATYPE", "EQUIVALENT", "NOT_EQUIVALENT", "SEMICOLON",
  "PERIOD", "RETURN_TYPE_ARROW", "L_BRACKET", "R_BRACKET", "TRUE", "FALSE",
  "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL", "GREATER_THAN", "LESS_THAN",
  "NOT", "OR", "AND", "COMMENT", "L_PARENTHESIS", "R_PARENTHESIS", "QUOTE",
  "ASSIGNMENT", "INTEGER_DATATYPE", "L_CURLY", "R_CURLY", "NUM",
  "IDENTIFIER", "PLUS", "MINUS", "TIMES", "DIVIDE", "$accept", "program",
  "functions", "function", "$@1", "params", "statements", "statement",
  "arg_list", "function_call", "break", "read", "write", "add_operator",
  "mult_operator", "term", "factor", "numeric_expression",
  "assignment_statement", "variable_declaration", "variable_assignment",
  "array_declaration", "relational_expression", "while_statement",
  "return_statement", "if_then_else_statement", "if_statement",
  "else_statement", "elif_statement", "single_comment", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -35,   -90,    27,   -90,   -35,    19,   -90,   -90,    14,    -4,
     -90,     7,    -3,     4,   -90,    -1,     2,     3,    37,    32,
      18,    26,    20,   -90,    13,    22,   -90,    25,    23,    -1,
     -90,   -90,   -90,   -90,   -22,   -90,   -16,   -90,    46,    47,
     -90,   -90,   -90,   -90,    21,   -90,    33,    49,    59,   -90,
      28,    29,    31,   -90,   -31,    53,     8,   -90,   -90,   -90,
     -90,    13,   -90,   -90,    13,   -90,   -90,    41,    38,   -90,
      62,    13,   -90,    44,    45,    30,    60,   -90,   -90,    48,
     -16,   -90,   -22,    42,    -1,   -90,   -14,   -16,    43,   -90,
     -90,   -90,   -90,   -90,    50,   -90,    51,    30,    54,    13,
     -90,    -9,    52,    56,    55,   -90,   -16,    57,    58,    63,
     -90,    64,    -1,    66,    -1,    65,    67,    69,    70,    -1,
     -90,    -1,   -90,    71,    72,   -90,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     5,     0,     2,     4,     0,     1,     3,     0,     9,
       8,     0,     0,     0,     7,    11,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,    37,    39,     0,    11,
      38,    15,    13,    14,    41,    35,    12,    16,    18,    17,
      19,    20,    21,    22,    55,    23,     0,     0,     0,    27,
       0,     0,     0,    39,     0,    44,     0,     6,    10,    33,
      32,     0,    30,    31,     0,    42,    43,     0,     0,    56,
       0,     0,    54,     0,     0,     0,     0,    36,    45,     0,
      46,    34,    40,     0,    11,    57,     0,    25,     0,    29,
      51,    50,    49,    48,     0,    47,     0,     0,     0,     0,
      26,     0,     0,     0,     0,    59,    24,     0,     0,     0,
      28,     0,    11,     0,    11,     0,     0,     0,     0,    11,
      53,    11,    58,     0,     0,    60,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,    84,   -90,   -90,   -90,   -29,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,    36,    61,   -23,   -90,   -90,
     -90,   -90,   -89,   -90,   -90,   -90,   -90,    35,   -90,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    11,    28,    29,    86,    30,
      31,    32,    33,    64,    61,    34,    35,    36,    37,    38,
      39,    40,    94,    41,    42,    43,    44,    69,    70,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      58,    54,    16,    99,    17,    18,    77,    19,   104,     1,
      20,    16,   108,    21,    62,    63,    16,    22,    79,    90,
      91,    92,    93,   100,    12,    59,    60,     6,   107,    62,
      63,     8,    13,    80,    23,    24,    67,    68,     9,    25,
      10,    14,    26,    27,    24,    15,    46,    47,    87,    24,
      48,    26,    53,    49,    50,    98,    26,    53,    90,    91,
      92,    93,    51,    52,    56,    57,    55,    65,    66,    71,
      72,    73,    74,    75,    78,    76,   106,    83,    68,    84,
      88,    95,    89,   116,    96,   118,    97,   101,     7,   109,
     123,     0,   124,   110,   102,   103,   105,     0,   112,   111,
      82,   115,   113,   117,   114,    85,   119,     0,     0,   120,
     121,     0,   122,   125,   126,     0,     0,     0,     0,     0,
       0,     0,    81
};

static const yytype_int8 yycheck[] =
{
      29,    24,     3,    17,     5,     6,    37,     8,    97,    44,
      11,     3,   101,    14,    45,    46,     3,    18,    10,    28,
      29,    30,    31,    37,    17,    47,    48,     0,    37,    45,
      46,    12,    25,    56,    35,    36,    15,    16,    24,    40,
      44,    44,    43,    44,    36,    41,    44,    44,    71,    36,
      13,    43,    44,    21,    36,    84,    43,    44,    28,    29,
      30,    31,    36,    43,    39,    42,    44,    21,    21,    36,
      21,    12,    44,    44,    21,    44,    99,    36,    16,    41,
      36,    21,    37,   112,    36,   114,    44,    44,     4,    37,
     119,    -1,   121,    37,    44,    44,    42,    -1,    41,    44,
      64,    37,    44,    37,    41,    70,    41,    -1,    -1,    42,
      41,    -1,    42,    42,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    50,    51,    52,    53,     0,    51,    12,    24,
      44,    54,    17,    25,    44,    41,     3,     5,     6,     8,
      11,    14,    18,    35,    36,    40,    43,    44,    55,    56,
      58,    59,    60,    61,    64,    65,    66,    67,    68,    69,
      70,    72,    73,    74,    75,    78,    44,    44,    13,    21,
      36,    36,    43,    44,    66,    44,    39,    42,    55,    47,
      48,    63,    45,    46,    62,    21,    21,    15,    16,    76,
      77,    36,    21,    12,    44,    44,    44,    37,    21,    10,
      66,    65,    64,    36,    41,    76,    57,    66,    36,    37,
      28,    29,    30,    31,    71,    21,    36,    44,    55,    17,
      37,    44,    44,    44,    71,    42,    66,    37,    71,    37,
      37,    44,    41,    44,    41,    37,    55,    37,    55,    41,
      42,    41,    42,    55,    55,    42,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    53,    52,    54,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    59,    60,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    70,    71,    71,
      71,    71,    72,    72,    73,    74,    74,    74,    75,    76,
      77,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     9,     3,     1,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     5,     2,     6,     4,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       3,     1,     2,     2,     2,     3,     3,     4,     1,     1,
       1,     1,    11,     9,     3,     1,     2,     3,     9,     4,
       9,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 5: /* $@1: %empty  */
#line 62 "TurtleC.y"
               {
        param_index = 0; // Reset parameter index for the new function
        printf("func %s\n", (yyvsp[0].strVal));
        is_main_function = (strcmp((yyvsp[0].strVal), "main") == 0); // Set flag if function is "main"
    }
#line 1622 "TurtleC.tab.c"
    break;

  case 6: /* function: IDENTIFIER $@1 COLON L_BRACKET params R_BRACKET L_CURLY statements R_CURLY  */
#line 68 "TurtleC.y"
    {
        if (!is_main_function && !has_return_statement) {
            yyerror("Non-main function must have a return statement.");
        }
        // Reset the flag for the next function
        is_main_function = 0;
        has_return_statement = 0;
        printf("endfunc\n");
    }
#line 1636 "TurtleC.tab.c"
    break;

  case 8: /* params: IDENTIFIER  */
#line 92 "TurtleC.y"
        {
		printf(". %s\n" , (yyvsp[0].strVal));
		printf("= %s, $%d\n", (yyvsp[0].strVal), param_index++); 
	}
#line 1645 "TurtleC.tab.c"
    break;

  case 9: /* params: %empty  */
#line 98 "TurtleC.y"
        {/* epsilon */ }
#line 1651 "TurtleC.tab.c"
    break;

  case 10: /* statements: statement statements  */
#line 104 "TurtleC.y"
                                 {/* printf("statements -> statement statements\n"); */}
#line 1657 "TurtleC.tab.c"
    break;

  case 11: /* statements: %empty  */
#line 105 "TurtleC.y"
                                        { /* printf("statements -> epsilon\n"); */ }
#line 1663 "TurtleC.tab.c"
    break;

  case 12: /* statement: numeric_expression  */
#line 108 "TurtleC.y"
                        {}
#line 1669 "TurtleC.tab.c"
    break;

  case 13: /* statement: read  */
#line 111 "TurtleC.y"
                        {printf("statement -> read\n");}
#line 1675 "TurtleC.tab.c"
    break;

  case 14: /* statement: write  */
#line 113 "TurtleC.y"
                        {/* printf("statement -> write\n"); */}
#line 1681 "TurtleC.tab.c"
    break;

  case 15: /* statement: break  */
#line 115 "TurtleC.y"
                        {printf("statement -> break\n");}
#line 1687 "TurtleC.tab.c"
    break;

  case 16: /* statement: assignment_statement  */
#line 117 "TurtleC.y"
                        {printf("statement -> assignment_statement\n");}
#line 1693 "TurtleC.tab.c"
    break;

  case 17: /* statement: variable_assignment  */
#line 119 "TurtleC.y"
                        {/* printf("statement -> variable_assignment\n"); */}
#line 1699 "TurtleC.tab.c"
    break;

  case 18: /* statement: variable_declaration  */
#line 121 "TurtleC.y"
                        {printf("statement -> variable_declaration\n");}
#line 1705 "TurtleC.tab.c"
    break;

  case 19: /* statement: array_declaration  */
#line 123 "TurtleC.y"
                        {printf("statement -> array_declaration\n");}
#line 1711 "TurtleC.tab.c"
    break;

  case 20: /* statement: while_statement  */
#line 125 "TurtleC.y"
                        {printf("statement -> while_statement\n");}
#line 1717 "TurtleC.tab.c"
    break;

  case 21: /* statement: return_statement  */
#line 127 "TurtleC.y"
                        {/* printf("statement -> return_statement\n"); */}
#line 1723 "TurtleC.tab.c"
    break;

  case 22: /* statement: if_then_else_statement  */
#line 129 "TurtleC.y"
                        {printf("statement -> if_then_else_statement\n");}
#line 1729 "TurtleC.tab.c"
    break;

  case 23: /* statement: single_comment  */
#line 131 "TurtleC.y"
                        {printf("statement -> comment\n");}
#line 1735 "TurtleC.tab.c"
    break;

  case 24: /* arg_list: arg_list COMMA numeric_expression  */
#line 136 "TurtleC.y"
        {
		char* parameter = genTempName();
		printf(". %s\n" , parameter);

		printf("= %s, %s\n" , parameter, (yyvsp[0].nameAndCode).name);
		printf("param %s\n", parameter); // Append each parameter
    }
#line 1747 "TurtleC.tab.c"
    break;

  case 25: /* arg_list: numeric_expression  */
#line 147 "TurtleC.y"
        {
		// printf("arg_list -> numeric_expression\n");
		char* parameter = genTempName();
		printf(". %s\n" , parameter);

		printf("= %s, %s\n" , parameter, (yyvsp[0].nameAndCode).name);
		printf("param %s\n", parameter);

	}
#line 1761 "TurtleC.tab.c"
    break;

  case 26: /* function_call: CALL IDENTIFIER L_PARENTHESIS arg_list R_PARENTHESIS  */
#line 158 "TurtleC.y"
        {

		// name, dest
		char *registerName = genTempName();
		(yyval.nameAndCode).name = registerName;
		printf(". %s\n" , registerName);
		printf("call %s, %s\n" , (yyvsp[-3].strVal), registerName);
		// printf("function_call -> IDENTIFIER L_PARENTHESIS arg_list R_PARENTHESIS\n");
	}
#line 1775 "TurtleC.tab.c"
    break;

  case 27: /* break: TERMINATE SEMICOLON  */
#line 168 "TurtleC.y"
                           {printf("break -> TERMINATE;\n");}
#line 1781 "TurtleC.tab.c"
    break;

  case 28: /* read: IDENTIFIER ASSIGNMENT READ L_PARENTHESIS IDENTIFIER R_PARENTHESIS  */
#line 171 "TurtleC.y"
                        {printf("read -> IDENTIFIER EQUIVALENT READ L_PARENTHESIS IDENTIFIER R_PARENTHESIS\n");}
#line 1787 "TurtleC.tab.c"
    break;

  case 29: /* write: WRITE L_PARENTHESIS IDENTIFIER R_PARENTHESIS  */
#line 174 "TurtleC.y"
                        {
				printf(".> %s\n" , (yyvsp[-1].strVal));
				// printf("write -> WRITE L_PARENTHESIS IDENTIFIER COMMA IDENTIFIER R_PARENTHESIS\n");
			}
#line 1796 "TurtleC.tab.c"
    break;

  case 30: /* add_operator: PLUS  */
#line 181 "TurtleC.y"
        {
		(yyval.operator) = "+";
		// printf("add_operator -> PLUS, strVal: %s\n", $$);
	}
#line 1805 "TurtleC.tab.c"
    break;

  case 31: /* add_operator: MINUS  */
#line 188 "TurtleC.y"
        {
		(yyval.operator) = "-";
		// printf("add_operator -> MINUS, strVal: %s\n", $$);
	}
#line 1814 "TurtleC.tab.c"
    break;

  case 32: /* mult_operator: DIVIDE  */
#line 196 "TurtleC.y"
        {
		(yyval.operator) = "/";
		// printf("mult_operator -> DIVIDE\n");
	}
#line 1823 "TurtleC.tab.c"
    break;

  case 33: /* mult_operator: TIMES  */
#line 204 "TurtleC.y"
        {
		(yyval.operator) = "*";
		// printf("mult_operator -> TIMES\n");
	}
#line 1832 "TurtleC.tab.c"
    break;

  case 34: /* term: term mult_operator factor  */
#line 212 "TurtleC.y"
    {
        (yyval.nameAndCode).name = genTempName();
        
		
		// print out the code

		// To initialize the new temp variable		
		printf(". %s\n", (yyval.nameAndCode).name);

		// To store the code
		printf("%s %s, %s, %s\n", (yyvsp[-1].operator), (yyval.nameAndCode).name, (yyvsp[-2].nameAndCode).name, (yyvsp[0].nameAndCode).name);

		// printf("term -> term mult_operator factor\n");


    }
#line 1853 "TurtleC.tab.c"
    break;

  case 35: /* term: factor  */
#line 233 "TurtleC.y"
        {
		// term.name = factor.name
		(yyval.nameAndCode).name = (yyvsp[0].nameAndCode).name;
		// printf("term -> factor, name: %s\n", $$.name);
	}
#line 1863 "TurtleC.tab.c"
    break;

  case 36: /* factor: L_PARENTHESIS numeric_expression R_PARENTHESIS  */
#line 243 "TurtleC.y"
        { 
			(yyval.nameAndCode).name = (yyvsp[-1].nameAndCode).name;
			// printf("factor -> L_PARENTHESIS numeric_expression R_PARENTHESIS\n"); 
		}
#line 1872 "TurtleC.tab.c"
    break;

  case 37: /* factor: NUM  */
#line 249 "TurtleC.y"
    {
		// Value of num should be stored in factor.name.
		// factor.name = num.strVal
        (yyval.nameAndCode).name = (yyvsp[0].strVal);
		// printf("factor -> NUM\n");
        // printf("factor -> NUM, name: %s\n", $$.name); // Comment out later
    }
#line 1884 "TurtleC.tab.c"
    break;

  case 38: /* factor: function_call  */
#line 258 "TurtleC.y"
        {
		// printf("factor -> function_call\n");
		(yyval.nameAndCode).name = (yyvsp[0].nameAndCode).name;
	}
#line 1893 "TurtleC.tab.c"
    break;

  case 39: /* factor: IDENTIFIER  */
#line 264 "TurtleC.y"
    {

        (yyval.nameAndCode).name = (yyvsp[0].strVal);
 
        // printf("factor -> IDENTIFIER, name: %s\n", $$.name); // Comment out later
    }
#line 1904 "TurtleC.tab.c"
    break;

  case 40: /* numeric_expression: numeric_expression add_operator term  */
#line 274 "TurtleC.y"
                {
			(yyval.nameAndCode).name = genTempName();

			// print code

			// to intialize temporary variable for num_exp.  ex: . t1
			printf(". %s\n", (yyval.nameAndCode).name);

			// assign value to the temp variable. ex: + t1, 2, 5 --> t1 = 2 + 5
			printf("%s %s, %s, %s\n" , (yyvsp[-1].operator), (yyval.nameAndCode).name, (yyvsp[-2].nameAndCode).name, (yyvsp[0].nameAndCode).name);

			// printf("numeric_expression -> numeric_expression add_operator term\n");
		}
#line 1922 "TurtleC.tab.c"
    break;

  case 41: /* numeric_expression: term  */
#line 292 "TurtleC.y"
                {
			(yyval.nameAndCode).name = (yyvsp[0].nameAndCode).name;
			// printf("numeric_expression -> term\n");
		
		}
#line 1932 "TurtleC.tab.c"
    break;

  case 42: /* assignment_statement: variable_declaration SEMICOLON  */
#line 300 "TurtleC.y"
        {
		printf("assignment_statement -> variable_declaration SEMICOLON\n");
	}
#line 1940 "TurtleC.tab.c"
    break;

  case 43: /* assignment_statement: variable_assignment SEMICOLON  */
#line 304 "TurtleC.y"
                                        {printf("assignment_statement -> variable_declaration SEMICOLON\n");}
#line 1946 "TurtleC.tab.c"
    break;

  case 44: /* variable_declaration: INTEGER_DATATYPE IDENTIFIER  */
#line 307 "TurtleC.y"
                {
			printf("variable_declaration -> INTEGER_DATATYPE IDENTIFIER ASSIGNMENT numeric_expression\n");
		}
#line 1954 "TurtleC.tab.c"
    break;

  case 45: /* variable_declaration: INTEGER_DATATYPE IDENTIFIER SEMICOLON  */
#line 311 "TurtleC.y"
                {printf("variable_declaration -> INTEGER_DATATYPE IDENTIFIER SEMICOLON\n");}
#line 1960 "TurtleC.tab.c"
    break;

  case 46: /* variable_assignment: IDENTIFIER ASSIGNMENT numeric_expression  */
#line 314 "TurtleC.y"
                {
			printf(". %s\n" , (yyvsp[-2].strVal));
			printf("= %s, %s\n" , (yyvsp[-2].strVal), (yyvsp[0].nameAndCode).name);
			// printf("variable_assignment -> IDENTIFIER ASSIGNMENT numeric_expression\n");
			
		}
#line 1971 "TurtleC.tab.c"
    break;

  case 47: /* array_declaration: INTEGER_ARRAY_DATATYPE NUM IDENTIFIER SEMICOLON  */
#line 322 "TurtleC.y"
                {printf("array_declaration ->  INTEGER_ARRAY_DATATYPE NUM IDENTIFIER SEMICOLON\n");}
#line 1977 "TurtleC.tab.c"
    break;

  case 48: /* relational_expression: LESS_THAN  */
#line 325 "TurtleC.y"
                        {printf("relational_expression -> LESS_THAN\n");}
#line 1983 "TurtleC.tab.c"
    break;

  case 49: /* relational_expression: GREATER_THAN  */
#line 327 "TurtleC.y"
                        {printf("relational_expression -> GREATER_THAN\n");}
#line 1989 "TurtleC.tab.c"
    break;

  case 50: /* relational_expression: LESS_THAN_EQUAL  */
#line 329 "TurtleC.y"
                        {printf("relational_expression -> LESS_THAN_EQUAL\n");}
#line 1995 "TurtleC.tab.c"
    break;

  case 51: /* relational_expression: GREATER_THAN_EQUAL  */
#line 331 "TurtleC.y"
                        {printf("relational_expression -> GREATER_THAN_EQUAL\n");}
#line 2001 "TurtleC.tab.c"
    break;

  case 52: /* while_statement: WHILE THIS COLON L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY  */
#line 334 "TurtleC.y"
                        {printf("while_statement -> WHILE THIS COLON L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY\n");}
#line 2007 "TurtleC.tab.c"
    break;

  case 53: /* while_statement: WHILE THIS COLON L_PARENTHESIS IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY  */
#line 336 "TurtleC.y"
                        {printf("WHILE THIS COLON L_PARENTHESIS bool R_PARENTHESIS L_CURLY statements R_CURLY\n");}
#line 2013 "TurtleC.tab.c"
    break;

  case 54: /* return_statement: RETURN IDENTIFIER SEMICOLON  */
#line 339 "TurtleC.y"
    {
        has_return_statement = 1;
        printf("ret %s\n" , (yyvsp[-1].strVal));
    }
#line 2022 "TurtleC.tab.c"
    break;

  case 55: /* if_then_else_statement: if_statement  */
#line 346 "TurtleC.y"
                        {printf("if_then_else_statement -> if_statement\n");}
#line 2028 "TurtleC.tab.c"
    break;

  case 56: /* if_then_else_statement: if_statement else_statement  */
#line 349 "TurtleC.y"
                        {printf("if_then_else_statement -> if_else_statement\n");}
#line 2034 "TurtleC.tab.c"
    break;

  case 57: /* if_then_else_statement: if_statement elif_statement else_statement  */
#line 352 "TurtleC.y"
                        {printf("if_then_else_statement -> if_statement elif_statement else_statement\n");}
#line 2040 "TurtleC.tab.c"
    break;

  case 58: /* if_statement: IF L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY  */
#line 355 "TurtleC.y"
                        {printf("if_statement -> IF L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY\n");}
#line 2046 "TurtleC.tab.c"
    break;

  case 59: /* else_statement: ELSE L_CURLY statements R_CURLY  */
#line 358 "TurtleC.y"
                        {printf("else_statement -> ELSE L_CURLY statements R_CURLY\n");}
#line 2052 "TurtleC.tab.c"
    break;

  case 60: /* elif_statement: ELIF L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY  */
#line 361 "TurtleC.y"
                        {printf("elif_statememt -> ELIF L_CURLY statements R_CURLY\n");}
#line 2058 "TurtleC.tab.c"
    break;

  case 61: /* single_comment: COMMENT  */
#line 364 "TurtleC.y"
                {printf("single_comment -> COMMENT VALID_CHAR\n");}
#line 2064 "TurtleC.tab.c"
    break;


#line 2068 "TurtleC.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 367 "TurtleC.y"



