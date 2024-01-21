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
#line 1 "2005105.y"

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "2005105_Symboltable.cpp"

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE* yyin;

int line_count = 1;  // NOTICE
int error_count = 0;
int scope_count = 1;

FILE* input;
ofstream logStream;
ofstream error;

//int scopeTablesSize = 10;

//Root scopetable for global scope, with new SymbolTable
//ScopeTable* scopeTable = new ScopeTable(scopeTablesSize);
//SymbolTable* symbolTable = new SymbolTable(scopeTable, scopeTablesSize, logStream);

SymbolTable* symbolTable;

/* auxiliary variables and structures and containers */
string type, type_final;  // basially for function declaration-definition
string name, name_final;  // basically for function declaration-definition

struct var{
    string var_name;
    int var_size;  // it is set to -1 for variables
} temp_var;

vector<var> var_list;  /* for identifier(variable, array) insertion into symbolTable */
string tempTypeSpecifier; // Holds type specifier temporarily while variable declaration;

Parameter tempParameter; //Holds parameter temporarily before pushing into parameter List
vector<Parameter> parameterList;  // parameter list for identifiers such as function declaration, definition

vector<string> argumentList;  // argument list for function call

/*
void insertVariable(string _type, var var_in) {
    // symbolTable insertion for variable and array 
    SymbolInfo* symbolInfo = new SymbolInfo(var_in.var_name, "ID");
    symbolInfo->setReturnType(_type);  // setting variable type
    symbolInfo->setArraySize(var_in.var_size);

    symbolTable->insertSymbol(*symbolInfo);
    return ;
}
*/

//Functions for inserting identifiers into SymbolTable

//For variables and arrays
//arraySize set to -1 for variables
void insertVariable(string Type, string Name, int arraySize) {

    SymbolInfo* symbolInfo = new SymbolInfo(Name, "ID");
    symbolInfo->setReturnType(Type);  // setting variable type
    symbolInfo->setArraySize(arraySize);

    symbolTable->Insert(symbolInfo);
    return;
}

//For function declarations and definitions
//FuncDecDefBySize = -2 for declarations and -3 for definitions
void insertFunction(string Type, string Name, int FuncDecDefBySize) {

    SymbolInfo* symbolInfo = new SymbolInfo(Name, "ID");
    symbolInfo->setReturnType(Type);  // setting return type of function
    symbolInfo->setArraySize(FuncDecDefBySize);

    for(Parameter p : parameterList){
        symbolInfo->addToParameterList(p);
    }

    symbolTable->Insert(symbolInfo);
    return;
}

/* yyerror prototype function for reporting syntax error */
void yyerror(string s);

#line 166 "2005105.tab.c"

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

#include "2005105.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST_INT = 3,                  /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 4,                /* CONST_FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_DO = 6,                         /* DO  */
  YYSYMBOL_SWITCH = 7,                     /* SWITCH  */
  YYSYMBOL_DEFAULT = 8,                    /* DEFAULT  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_CONST_CHAR = 12,                /* CONST_CHAR  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_FLOAT = 14,                     /* FLOAT  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_PRINTLN = 20,                   /* PRINTLN  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_MAIN = 22,                      /* MAIN  */
  YYSYMBOL_CHAR = 23,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 24,                    /* DOUBLE  */
  YYSYMBOL_ASSIGNOP = 25,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_INCOP = 27,                     /* INCOP  */
  YYSYMBOL_DECOP = 28,                     /* DECOP  */
  YYSYMBOL_LOGICOP = 29,                   /* LOGICOP  */
  YYSYMBOL_RELOP = 30,                     /* RELOP  */
  YYSYMBOL_ADDOP = 31,                     /* ADDOP  */
  YYSYMBOL_MULOP = 32,                     /* MULOP  */
  YYSYMBOL_BITOP = 33,                     /* BITOP  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_LCURL = 36,                     /* LCURL  */
  YYSYMBOL_RCURL = 37,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 38,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 39,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_SINGLE_LINE_STRING = 42,        /* SINGLE_LINE_STRING  */
  YYSYMBOL_MULTI_LINE_STRING = 43,         /* MULTI_LINE_STRING  */
  YYSYMBOL_UNFINISHED_STRING = 44,         /* UNFINISHED_STRING  */
  YYSYMBOL_MULTI_LINE_COMMENT = 45,        /* MULTI_LINE_COMMENT  */
  YYSYMBOL_UNFINISHED_COMMENT = 46,        /* UNFINISHED_COMMENT  */
  YYSYMBOL_SINGLE_LINE_COMMENT = 47,       /* SINGLE_LINE_COMMENT  */
  YYSYMBOL_UNFINISHED_NUMBER = 48,         /* UNFINISHED_NUMBER  */
  YYSYMBOL_TOO_MANY_DECIMAL_POINTS = 49,   /* TOO_MANY_DECIMAL_POINTS  */
  YYSYMBOL_ILLFORMED_NUMBER = 50,          /* ILLFORMED_NUMBER  */
  YYSYMBOL_EMPTY_CONST_CHAR = 51,          /* EMPTY_CONST_CHAR  */
  YYSYMBOL_UNFINISHED_CONST_CHAR = 52,     /* UNFINISHED_CONST_CHAR  */
  YYSYMBOL_MULTICHAR_CONST_CHAR = 53,      /* MULTICHAR_CONST_CHAR  */
  YYSYMBOL_UNRECOGNIZED_CHAR = 54,         /* UNRECOGNIZED_CHAR  */
  YYSYMBOL_INVALID_ID_SUFFIX_NUM_PREFIX = 55, /* INVALID_ID_SUFFIX_NUM_PREFIX  */
  YYSYMBOL_LOWER_THAN_ELSE = 56,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_start = 58,                     /* start  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_unit = 60,                      /* unit  */
  YYSYMBOL_func_declaration = 61,          /* func_declaration  */
  YYSYMBOL_func_definition = 62,           /* func_definition  */
  YYSYMBOL_embedded = 63,                  /* embedded  */
  YYSYMBOL_embedded_out_dec = 64,          /* embedded_out_dec  */
  YYSYMBOL_embedded_out_def = 65,          /* embedded_out_def  */
  YYSYMBOL_parameter_list = 66,            /* parameter_list  */
  YYSYMBOL_compound_statement = 67,        /* compound_statement  */
  YYSYMBOL_embedded_in = 68,               /* embedded_in  */
  YYSYMBOL_var_declaration = 69,           /* var_declaration  */
  YYSYMBOL_type_specifier = 70,            /* type_specifier  */
  YYSYMBOL_id = 71,                        /* id  */
  YYSYMBOL_declaration_list = 72,          /* declaration_list  */
  YYSYMBOL_statements = 73,                /* statements  */
  YYSYMBOL_statement = 74,                 /* statement  */
  YYSYMBOL_embedded_exp = 75,              /* embedded_exp  */
  YYSYMBOL_embedded_void = 76,             /* embedded_void  */
  YYSYMBOL_expression_statement = 77,      /* expression_statement  */
  YYSYMBOL_variable = 78,                  /* variable  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_logic_expression = 80,          /* logic_expression  */
  YYSYMBOL_rel_expression = 81,            /* rel_expression  */
  YYSYMBOL_simple_expression = 82,         /* simple_expression  */
  YYSYMBOL_term = 83,                      /* term  */
  YYSYMBOL_unary_expression = 84,          /* unary_expression  */
  YYSYMBOL_factor = 85,                    /* factor  */
  YYSYMBOL_argument_list = 86,             /* argument_list  */
  YYSYMBOL_arguments = 87                  /* arguments  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   124,   130,   138,   144,   150,   158,   167,
     178,   186,   196,   203,   218,   300,   312,   324,   336,   350,
     360,   372,   397,   431,   438,   445,   454,   460,   485,   513,
     538,   568,   574,   582,   588,   594,   600,   606,   612,   618,
     624,   630,   645,   651,   662,   672,   684,   715,   758,   768,
     794,   803,   833,   842,   872,   881,   916,   925,   975,   995,
    1012,  1022,  1030,  1091,  1108,  1116,  1124,  1132,  1142,  1148,
    1157,  1175
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
  "\"end of file\"", "error", "\"invalid token\"", "CONST_INT",
  "CONST_FLOAT", "ID", "DO", "SWITCH", "DEFAULT", "BREAK", "CASE",
  "CONTINUE", "CONST_CHAR", "INT", "FLOAT", "VOID", "IF", "ELSE", "FOR",
  "WHILE", "PRINTLN", "RETURN", "MAIN", "CHAR", "DOUBLE", "ASSIGNOP",
  "NOT", "INCOP", "DECOP", "LOGICOP", "RELOP", "ADDOP", "MULOP", "BITOP",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "SINGLE_LINE_STRING", "MULTI_LINE_STRING",
  "UNFINISHED_STRING", "MULTI_LINE_COMMENT", "UNFINISHED_COMMENT",
  "SINGLE_LINE_COMMENT", "UNFINISHED_NUMBER", "TOO_MANY_DECIMAL_POINTS",
  "ILLFORMED_NUMBER", "EMPTY_CONST_CHAR", "UNFINISHED_CONST_CHAR",
  "MULTICHAR_CONST_CHAR", "UNRECOGNIZED_CHAR",
  "INVALID_ID_SUFFIX_NUM_PREFIX", "LOWER_THAN_ELSE", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "embedded",
  "embedded_out_dec", "embedded_out_def", "parameter_list",
  "compound_statement", "embedded_in", "var_declaration", "type_specifier",
  "id", "declaration_list", "statements", "statement", "embedded_exp",
  "embedded_void", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-27)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      79,   -91,   -91,   -91,    12,    79,   -91,   -91,   -91,   -91,
      20,   -91,   -91,    -1,     3,    -2,    25,    69,    71,   -91,
       0,    35,    44,    52,   -19,    90,   -91,    97,    66,    72,
      52,    79,   -91,   -91,    73,   -91,   -91,   -91,    68,    72,
     105,   -91,    65,   -91,   -91,   -91,   -91,   -91,    37,    77,
      83,    88,    89,   139,   139,   139,   139,   -91,   -91,   -91,
     -91,   119,    87,   100,   -91,   -91,    62,    86,   -91,    99,
      26,    98,   -91,   -91,   139,   139,    24,   139,   124,    91,
      70,   -91,   -91,   110,    95,   139,   -91,   -91,   139,   -91,
     -91,   -91,   139,   139,   139,   139,   -91,   111,   107,   -91,
     -91,   -91,   117,   -91,   -91,    96,   -91,   -91,   126,    98,
     -91,   -91,   139,   123,   -91,   125,   118,   -91,   -91,   -91,
      24,   -91,   -91,   135,   -91,   135,   145,   -91,   -91,   135,
     139,   -91,   -91,   -91,   128,   135,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    29,     0,     0,     0,     0,     0,    22,
       0,     0,    27,    13,     0,    18,    30,     0,     0,     0,
      13,     0,    26,    17,     0,     9,    21,    11,     0,     0,
      16,    28,     0,     8,    10,    15,    64,    65,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    44,    35,
      33,     0,     0,     0,    31,    34,    61,     0,    48,    50,
      52,    54,    56,    60,    69,     0,     0,     0,     0,     0,
      61,    59,    58,     0,    29,     0,    19,    32,     0,    66,
      67,    45,     0,     0,     0,     0,    71,     0,    68,    42,
      42,    42,     0,    41,    63,     0,    49,    51,    53,    55,
      57,    62,     0,     0,    43,     0,     0,    47,    70,    43,
       0,    43,    40,     0,    42,     0,    37,    43,    39,     0,
       0,    38,    42,    43,     0,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   159,   -91,   -91,   -91,   137,   138,   -91,
      -9,   -91,    18,    31,    -8,   -91,   -91,   -62,   -90,   -67,
     -72,   -48,   -53,   -69,    80,    81,    84,   -46,   -91,   -91,
     -91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    16,    28,    29,    24,
      59,    42,    60,    61,    62,    15,    63,    64,   113,   120,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    97,
      98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    87,    14,    83,   100,    96,    80,    80,    81,    82,
     114,   115,    11,     1,     2,     3,    30,    33,     9,   106,
      37,    31,    99,     9,   101,    13,    80,    46,    47,    48,
      44,    10,   105,   -12,   127,    23,    10,   -26,    18,    19,
      80,    17,   133,   118,    80,    80,    80,    80,   124,   110,
      54,    25,   123,    14,   125,    55,    93,    94,    56,    20,
     130,   126,    40,   128,    80,    58,   134,   131,    46,    47,
      48,    74,    21,   136,    26,   -26,    22,   132,     1,     2,
       3,    49,    27,    50,    51,    52,    53,    88,   -14,    89,
      90,    54,     1,     2,     3,    32,    55,    89,    90,    56,
      34,    36,    57,    46,    47,    48,    58,    35,    36,    43,
      45,    75,    41,     1,     2,     3,    49,    76,    50,    51,
      52,    53,    77,    78,    84,    85,    54,    91,    92,   102,
      95,    55,   103,   -26,    56,   117,    36,    86,    46,    47,
      48,    58,    46,    47,    48,   104,   111,   112,     1,     2,
       3,    49,   116,    50,    51,    52,    53,    94,   119,   122,
     121,    54,   129,   135,    12,    54,    55,    38,    39,    56,
      55,    36,   107,    56,   108,     0,    58,     0,   109
};

static const yytype_int16 yycheck[] =
{
      53,    63,    10,    56,    76,    74,    54,    55,    54,    55,
     100,   101,     0,    13,    14,    15,    35,    25,     0,    88,
      29,    40,    75,     5,    77,     5,    74,     3,     4,     5,
      39,     0,    85,    34,   124,    35,     5,    38,    40,    41,
      88,    38,   132,   112,    92,    93,    94,    95,   120,    95,
      26,    20,   119,    61,   121,    31,    30,    31,    34,    34,
     127,   123,    31,   125,   112,    41,   133,   129,     3,     4,
       5,    34,     3,   135,    39,    38,     5,   130,    13,    14,
      15,    16,    38,    18,    19,    20,    21,    25,    36,    27,
      28,    26,    13,    14,    15,     5,    31,    27,    28,    34,
       3,    36,    37,     3,     4,     5,    41,    41,    36,    41,
       5,    34,    39,    13,    14,    15,    16,    34,    18,    19,
      20,    21,    34,    34,     5,    38,    26,    41,    29,     5,
      32,    31,    41,    38,    34,    39,    36,    37,     3,     4,
       5,    41,     3,     4,     5,    35,    35,    40,    13,    14,
      15,    16,    35,    18,    19,    20,    21,    31,    35,    41,
      35,    26,    17,    35,     5,    26,    31,    30,    30,    34,
      31,    36,    92,    34,    93,    -1,    41,    -1,    94
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    14,    15,    58,    59,    60,    61,    62,    69,
      70,     0,    60,     5,    71,    72,    63,    38,    40,    41,
      34,     3,     5,    35,    66,    70,    39,    38,    64,    65,
      35,    40,     5,    71,     3,    41,    36,    67,    64,    65,
      70,    39,    68,    41,    67,     5,     3,     4,     5,    16,
      18,    19,    20,    21,    26,    31,    34,    37,    41,    67,
      69,    70,    71,    73,    74,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    34,    34,    34,    34,    34,    79,
      78,    84,    84,    79,     5,    38,    37,    74,    25,    27,
      28,    41,    29,    30,    31,    32,    80,    86,    87,    79,
      77,    79,     5,    41,    35,    79,    80,    81,    82,    83,
      84,    35,    40,    75,    75,    75,    35,    39,    80,    35,
      76,    35,    41,    76,    77,    76,    74,    75,    74,    17,
      76,    74,    79,    75,    76,    35,    74
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    61,    61,
      62,    62,    63,    64,    65,    66,    66,    66,    66,    67,
      67,    68,    69,    70,    70,    70,    71,    72,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     8,     7,
       8,     7,     0,     0,     0,     4,     3,     2,     1,     4,
       3,     0,     3,     1,     1,     1,     1,     3,     6,     1,
       4,     1,     2,     1,     1,     1,    13,     7,     9,     7,
       5,     3,     0,     0,     1,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
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
  case 2: /* start: program  */
#line 116 "2005105.y"
               {
        logStream << "At line no: " << (line_count-1) << " start: program" << "\n"  << endl;

        yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
        logStream << yyvsp[0]->getName() << "\n"  << endl;
	}
#line 1354 "2005105.tab.c"
    break;

  case 3: /* program: program unit  */
#line 124 "2005105.y"
                      {   
        logStream << "At line no: " << line_count << " program: program unit" << "\n"  << endl;

        yyval = new SymbolInfo((string)yyvsp[-1]->getName()+(string)yyvsp[0]->getName(), "NON_TERMINAL");
        logStream << yyval->getName() << "\n"  << endl;
    }
#line 1365 "2005105.tab.c"
    break;

  case 4: /* program: unit  */
#line 130 "2005105.y"
               {
        logStream << "At line no: " << line_count << " program: unit" << "\n"  << endl;

        yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
        logStream << yyvsp[0]->getName() << "\n"  << endl;
    }
#line 1376 "2005105.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 138 "2005105.y"
                      {
        logStream << "At line no: " << line_count << " unit: var_declaration" << "\n"  << endl;

        yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
        logStream << yyvsp[0]->getName() << "\n"  << endl;
    }
#line 1387 "2005105.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 144 "2005105.y"
                       {
        logStream << "At line no: " << line_count << " unit: func_declaration" << "\n"  << endl;

        yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
        logStream << yyvsp[0]->getName() << "\n"  << endl;
    }
#line 1398 "2005105.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 150 "2005105.y"
                      {
        logStream << "At line no: " << line_count << " unit: func_definition" << "\n"  << endl;

        yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
        logStream << yyvsp[0]->getName() << "\n"  << endl;
    }
#line 1409 "2005105.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID embedded LPAREN parameter_list RPAREN embedded_out_dec SEMICOLON  */
#line 158 "2005105.y"
                                                                                                     {
        logStream << "At line no: " << line_count << " func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON" << "\n"  << endl;

        yyval = new SymbolInfo((string)yyvsp[-7]->getName()+(string)" "+(string)yyvsp[-6]->getName()+(string)"("+(string)yyvsp[-3]->getName()+(string)")"+(string)";"+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << yyval->getName() << endl;

        name = (string)yyvsp[-6]->getName();
        parameterList.clear();
    }
#line 1423 "2005105.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID embedded LPAREN RPAREN embedded_out_dec SEMICOLON  */
#line 167 "2005105.y"
                                                                          {
        logStream << "At line no: " << line_count << " func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON" << "\n"  << endl;

        yyval = new SymbolInfo((string)yyvsp[-6]->getName()+(string)" "+(string)yyvsp[-5]->getName()+(string)"("+(string)")"+(string)";"+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << yyval->getName() << endl;

        name = (string)yyvsp[-5]->getName();
        parameterList.clear();
    }
#line 1437 "2005105.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID embedded LPAREN parameter_list RPAREN embedded_out_def compound_statement  */
#line 178 "2005105.y"
                                                                                                             {
        logStream << "At line no: " << line_count << " func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement" << "\n"  << endl;

        yyval = new SymbolInfo((string)yyvsp[-7]->getName()+(string)" "+(string)yyvsp[-6]->getName()+(string)"("+(string)yyvsp[-3]->getName()+(string)")"+(string)yyvsp[0]->getName()+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << yyval->getName() << endl;

        name = (string)yyvsp[-6]->getName();
    }
#line 1450 "2005105.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID embedded LPAREN RPAREN embedded_out_def compound_statement  */
#line 186 "2005105.y"
                                                                                   {
        logStream << "At line no: " << line_count << " func_definition: type_specifier ID LPAREN RPAREN compound_statement" << "\n"  << endl;

        yyval = new SymbolInfo((string)yyvsp[-6]->getName()+(string)" "+(string)yyvsp[-5]->getName()+(string)"("+(string)")"+(string)yyvsp[0]->getName()+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << yyval->getName() << endl;

        name = (string)yyvsp[-5]->getName();
    }
#line 1463 "2005105.tab.c"
    break;

  case 12: /* embedded: %empty  */
#line 196 "2005105.y"
          {
            /* NOTICE: embedded action */
            type_final = type;
            name_final = name;
    }
#line 1473 "2005105.tab.c"
    break;

  case 13: /* embedded_out_dec: %empty  */
#line 203 "2005105.y"
                  {

            SymbolInfo* lookupNode = symbolTable->Lookup(name_final);

            if(lookupNode == NULL){ //Not previously declared/defined
                //Inserting into symbolTable, -2 denoting function declaration
                insertFunction(type_final, name_final, -2); 
            }
            else{//Previously declared
                error << "Error at line no: " << line_count << " multiple declaration of " << name_final << "\n" << endl;
                error_count++;
            }
    }
#line 1491 "2005105.tab.c"
    break;

  case 14: /* embedded_out_def: %empty  */
#line 218 "2005105.y"
                  {

            SymbolInfo* lookupNode = symbolTable->Lookup(name_final);

            if(lookupNode == NULL) { //Not previously declared/defined
                //Inserting into symbolTable, -3 denoting function definition
                insertFunction(type_final, name_final, -3);
            } 

            else if(lookupNode->getArraySize() == -1) {
                /* Previously declared variable found */
                error << "Error at line no: " << line_count << " variable with name " << name_final << " declared earlier\n" << endl;
                error_count++;
            }

            else if(lookupNode->getArraySize() == -3) {
                /* Previously defined function found */
                error << "Error at line no: " << line_count << " multiple definition of " << name_final << "\n" << endl;
                error_count++;
            } 

            else {/* Previously declared function found, so no problem */

                /* Checking consistencies within declaration and definition*/
                if(lookupNode->getReturnType() != type_final) {
                    /* return type not matching */
                    error << "Error at line no: " << line_count << " inconsistent function definition with its declaration for " << name_final << "\n" << endl;
                    error_count++;

                } 

                //Two cases for void param**
                //Void param provided in declaration, no param provided in definition, no problem
                else if(lookupNode->getParameterListSize()==1 && parameterList.size()==0 && lookupNode->getParameter(0).getType()=="void") {
                    lookupNode->setArraySize(-3);  // NOTICE: given function declaration has a matching definition, so it can be called
                } 
                //No param provided in declaration, void param provided in definition, no problem
                else if(lookupNode->getParameterListSize()==0 && parameterList.size()==1 && parameterList[0].getType()=="void") {
                    lookupNode->setArraySize(-3);  // NOTICE: given function declaration has a matching definition, so it can be called
                } 
                //Two cases for void param**

                //Parameter list size between declaration and definition not matching 
                else if(lookupNode->getParameterListSize() != parameterList.size()) {
                    error << "Error at line no: " << line_count << " inconsistent function definition with its declaration for " << name_final << "\n" << endl;
                    error_count++;
                } 

                //Parameter list size between declaration and definiton matching, so now we match params' types
                else {

                    bool validParameterList = true; //Valid if all parameters are valid

                    // Checking parameter list size 
                    if(lookupNode->getParameterListSize() == parameterList.size()) {
                        //Size matched, set identifier as function defintion
                        lookupNode->setArraySize(-3);
                    } else {
                        //Size not matched, function definition not valid
                        validParameterList = false;
                    }

                    // Checking params' types
                    if(validParameterList){ //If sizes matched, only then we check types
                        for(int i=0; i<parameterList.size(); i++) {
                            if(lookupNode->getParameter(i).getType() != parameterList[i].getType()) {
                                validParameterList = false; //If any of the param's type does not match
                                break;                      //function definition is invalid
                            }
                        }
                    }

                    if(!validParameterList){
                        error << "Error at line no: " << line_count << " inconsistent function definition with its declaration for " << name_final << "\n" << endl;
                        error_count++;
                    }

                }
            }
    }
#line 1576 "2005105.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 300 "2005105.y"
                                                       {
            logStream << "At line no: " << line_count << " parameter_list: parameter_list COMMA type_specifier ID" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-3]->getName()+(string)","+(string)yyvsp[-1]->getName()+(string)" "+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << endl;

            //Adding parameter to list
            tempParameter.setType((string)yyvsp[-1]->getName());
            tempParameter.setName((string)yyvsp[0]->getName());

            parameterList.push_back(tempParameter);
    }
#line 1593 "2005105.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA type_specifier  */
#line 312 "2005105.y"
                                              {
            logStream << "At line no: " << line_count << " parameter_list: parameter_list COMMA type_specifier" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)","+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << endl;

            //Adding parameter to list            
            tempParameter.setType((string)yyvsp[0]->getName());
            tempParameter.setName("");

            parameterList.push_back(tempParameter);
    }
#line 1610 "2005105.tab.c"
    break;

  case 17: /* parameter_list: type_specifier id  */
#line 324 "2005105.y"
                            {
            logStream << "At line no: " << line_count << " parameter_list: type_specifier ID" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-1]->getName()+(string)" "+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << endl;

            //Adding parameter to list            
            tempParameter.setType((string)yyvsp[-1]->getName());
            tempParameter.setName((string)yyvsp[0]->getName());

            parameterList.push_back(tempParameter);
    }
#line 1627 "2005105.tab.c"
    break;

  case 18: /* parameter_list: type_specifier  */
#line 336 "2005105.y"
                         {
            logStream << "At line no: " << line_count << " parameter_list: type_specifier" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << endl;

            //Adding parameter to list
            tempParameter.setType((string)yyvsp[0]->getName());
            tempParameter.setName("");

            parameterList.push_back(tempParameter);
    }
#line 1644 "2005105.tab.c"
    break;

  case 19: /* compound_statement: LCURL embedded_in statements RCURL  */
#line 350 "2005105.y"
                                                       {
            logStream << "At line no: " << line_count << " compound_statement: LCURL statements RCURL" << "\n"  << endl;

            yyval = new SymbolInfo((string)"{ "+(string)"\n"+(string)yyvsp[-1]->getName()+(string)"}"+(string)"\n", "NON_TERMINAL");  // NOTICE
            logStream << yyval->getName() << endl;

            //Printing all scopetables before exiting current scopetable as per offline requirement
            symbolTable->printAllScopeTable(logStream);
            symbolTable->ExitScope();
    }
#line 1659 "2005105.tab.c"
    break;

  case 20: /* compound_statement: LCURL embedded_in RCURL  */
#line 360 "2005105.y"
                              {
            logStream << "At line no: " << line_count << " compound_statement: LCURL RCURL" << "\n"  << endl;

            yyval = new SymbolInfo((string)"{ "+(string)"\n"+(string)"\n"+(string)"}"+(string)"\n", "NON_TERMINAL");  // NOTICE
            logStream << yyval->getName() << endl;

            //Printing all scopetables before exiting current scopetable as per offline requirement
            symbolTable->printAllScopeTable(logStream);
            symbolTable->ExitScope();
    }
#line 1674 "2005105.tab.c"
    break;

  case 21: /* embedded_in: %empty  */
#line 372 "2005105.y"
             {
            /* NOTICE: embedded action */
            symbolTable->EnterScope();

            /* If a new parameter list is applicable for new scope, we need to insert them into 
            SymbolTable as identifiers (variable) */

            //No params, or void provided
            if(parameterList.size()==1 && parameterList[0].getType()=="void") {
                //No actions necessary
            } 
            //At least one non-void param provided
            else {

                for(Parameter p : parameterList){
                    insertVariable(p.getType(), p.getName(), -1);
                }

            }

            //Clearing parameter list for next usage
            parameterList.clear(); 
    }
#line 1702 "2005105.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 397 "2005105.y"
                                                           {
            logStream << "At line no: " << line_count << " var_declaration: type_specifier declaration_list SEMICOLON" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)" "+(string)yyvsp[-1]->getName()+(string)";"+(string)"\n"+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << endl;

            tempTypeSpecifier = (string)yyvsp[-2]->getName();
            if(tempTypeSpecifier == "void"){
                error << "Error at line no: " << line_count << " variable type can not be void " << "\n" << endl;
                error_count++;

                tempTypeSpecifier = "float"; //by default, void type specifier, mistakenly provided, will be converted to floats
            }

            /* //NOTICE: symbolTable insertion
            if($1->getName() == "void") {
                error << "Error at line no: " << line_count << " variable type can not be void " << "\n" << endl;
                error_count++;

                for(int i=0; i<var_list.size(); i++) {
                    insertVariable("float", var_list[i]);  // NOTICE: by default, void type variables are float type
                }
            } 
            else {
                for(int i=0; i<var_list.size(); i++) {
                    insertVariable((string)$1->getName(), var_list[i]);
                }
            }

            var_list.clear();
            */
    }
#line 1739 "2005105.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 431 "2005105.y"
                    {
            //$$ = new SymbolInfo("int", "NON_TERMINAL");
            logStream << "At line no: " << line_count << " type_specifier: INT" << "\n"  << endl;
            logStream << "int" << "\n"  << endl;

            type = "int";
    }
#line 1751 "2005105.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 438 "2005105.y"
                        {
            //$$ = new SymbolInfo("float", "NON_TERMINAL");
            logStream << "At line no: " << line_count << " type_specifier: FLOAT" << "\n"  << endl;
            logStream << "float" << "\n"  << endl;

            type = "float";
    }
#line 1763 "2005105.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 445 "2005105.y"
                       {
            //$$ = new SymbolInfo("void", "NON_TERMINAL");
            logStream << "At line no: " << line_count << " type_specifier: VOID" << "\n"  << endl;
            logStream << "void" << "\n"  << endl;

            type = "void";
    }
#line 1775 "2005105.tab.c"
    break;

  case 26: /* id: ID  */
#line 454 "2005105.y"
       {
            //$$ = new SymbolInfo((string)$1->getName(), "NON_TERMINAL");
            name = yyvsp[0]->getName();
    }
#line 1784 "2005105.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID  */
#line 460 "2005105.y"
                                            {
            logStream << "At line no: " << line_count << " declaration_list: declaration_list COMMA ID" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)","+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << endl;

            string variableName = (string)yyvsp[0]->getName();

            // Checking if variable was previously declared
            SymbolInfo* lookupNode = symbolTable->Lookup(variableName);

            if(lookupNode != NULL) {
                error << "Error at line no: " << line_count << " multiple declaration of " << variableName << "\n" << endl;
                error_count++;
            }

            insertVariable(tempTypeSpecifier, variableName, -1); //-1 will be set as arraySize for denoting variable as identifier

            /* //keeping track of identifier(variable) 
            temp_var.var_name = (string)$3->getName();
            temp_var.var_size = -1;

            var_list.push_back(temp_var);
            */
    }
#line 1814 "2005105.tab.c"
    break;

  case 28: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 485 "2005105.y"
                                                                    {
            logStream << "At line no: " << line_count << " declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-5]->getName()+(string)","+(string)yyvsp[-3]->getName()+(string)"["+(string)yyvsp[-1]->getName()+(string)"]", "NON_TERMINAL");
            logStream << yyval->getName() << endl;

            string variableName = (string)yyvsp[-3]->getName();
            int variableSize = stoi( (string)yyvsp[-1]->getName() );

            // Checking if variable was previously declared
            SymbolInfo* lookupNode = symbolTable->Lookup(variableName);

            if(lookupNode != NULL) {
                error << "Error at line no: " << line_count << " multiple declaration of " << variableName << "\n" << endl;
                error_count++;
            }

            insertVariable(tempTypeSpecifier, variableName, variableSize); //variableSize will be set as arraySize for array

            /* //keeping track of identifier(array)
            temp_var.var_name = (string)$3->getName();

            stringstream temp_str((string) $5->getName());
            temp_str >> temp_var.var_size;

            var_list.push_back(temp_var);
            */
    }
#line 1847 "2005105.tab.c"
    break;

  case 29: /* declaration_list: ID  */
#line 513 "2005105.y"
                     {
            logStream << "At line no: " << line_count << " declaration_list: ID" << "\n"  << endl;

            //$$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
            logStream << (string)yyvsp[0]->getName() << "\n"  << endl;

            string variableName = (string)yyvsp[0]->getName();

            // Checking if variable was previously declared
            SymbolInfo* lookupNode = symbolTable->Lookup(variableName);

            if(lookupNode != NULL) {
                error << "Error at line no: " << line_count << " multiple declaration of " << variableName << "\n" << endl;
                error_count++;
            }

            insertVariable(tempTypeSpecifier, variableName, -1); //-1 will be set as arraySize for denoting variable as identifier

            /* //keeping track of identifier(variable) 
            temp_var.var_name = (string)$1->getName();
            temp_var.var_size = -1;

            var_list.push_back(temp_var);
            */
    }
#line 1877 "2005105.tab.c"
    break;

  case 30: /* declaration_list: id LTHIRD CONST_INT RTHIRD  */
#line 538 "2005105.y"
                                             {
            logStream << "At line no: " << line_count << " declaration_list: ID LTHIRD CONST_INT RTHIRD" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-3]->getName()+(string)"["+(string)yyvsp[-1]->getName()+(string)"]", "NON_TERMINAL");
            logStream << yyval->getName() << endl;

            string variableName = (string)yyvsp[-3]->getName();
            int variableSize = stoi( (string)yyvsp[-1]->getName() );

            // Checking if variable was previously declared
            SymbolInfo* lookupNode = symbolTable->Lookup(variableName);

            if(lookupNode != NULL) {
                error << "Error at line no: " << line_count << " multiple declaration of " << variableName << "\n" << endl;
                error_count++;
            }

            insertVariable(tempTypeSpecifier, variableName, variableSize); //variableSize will be set as arraySize for array

            /* //keeping track of identifier(array) 
            temp_var.var_name = (string)$1->getName();

            stringstream temp_str((string) $3->getName());
            temp_str >> temp_var.var_size;

            var_list.push_back(temp_var);
            */
    }
#line 1910 "2005105.tab.c"
    break;

  case 31: /* statements: statement  */
#line 568 "2005105.y"
                      {
            logStream << "At line no: " << line_count << " statements: statement" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 1921 "2005105.tab.c"
    break;

  case 32: /* statements: statements statement  */
#line 574 "2005105.y"
                                   {
            logStream << "At line no: " << line_count << " statements: statements statement" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-1]->getName()+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 1932 "2005105.tab.c"
    break;

  case 33: /* statement: var_declaration  */
#line 582 "2005105.y"
                           {
            logStream << "At line no: " << line_count << " statement: var_declaration" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 1943 "2005105.tab.c"
    break;

  case 34: /* statement: expression_statement  */
#line 588 "2005105.y"
                               {
            logStream << "At line no: " << line_count << " statement: expression_statement" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 1954 "2005105.tab.c"
    break;

  case 35: /* statement: compound_statement  */
#line 594 "2005105.y"
                             {
            logStream << "At line no: " << line_count << " statement: compound_statement" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)yyvsp[0]->getName()+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 1965 "2005105.tab.c"
    break;

  case 36: /* statement: FOR LPAREN expression_statement embedded_exp embedded_void expression_statement embedded_exp embedded_void expression embedded_exp embedded_void RPAREN statement  */
#line 600 "2005105.y"
                                                                                                                                                                            {
            logStream << "At line no: " << line_count << " statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)"for"+(string)"("+(string)yyvsp[-10]->getName()+(string)yyvsp[-7]->getName()+(string)yyvsp[-4]->getName()+(string)")"+(string)yyvsp[0]->getName()+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 1976 "2005105.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression embedded_exp RPAREN embedded_void statement  */
#line 606 "2005105.y"
                                                                                                 {
            logStream << "At line no: " << line_count << " statement: IF LPAREN expression RPAREN statement" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)"if"+(string)"("+(string)yyvsp[-4]->getName()+(string)")"+(string)yyvsp[0]->getName()+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 1987 "2005105.tab.c"
    break;

  case 38: /* statement: IF LPAREN expression embedded_exp RPAREN embedded_void statement ELSE statement  */
#line 612 "2005105.y"
                                                                                          {
            logStream << "At line no: " << line_count << " statement: IF LPAREN expression RPAREN statement ELSE statement" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)"if"+(string)"("+(string)yyvsp[-6]->getName()+(string)")"+(string)yyvsp[-2]->getName()+(string)" else"+(string)yyvsp[0]->getName()+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 1998 "2005105.tab.c"
    break;

  case 39: /* statement: WHILE LPAREN expression embedded_exp RPAREN embedded_void statement  */
#line 618 "2005105.y"
                                                                              {
            logStream << "At line no: " << line_count << " statement: WHILE LPAREN expression RPAREN statement" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)"while"+(string)"("+(string)yyvsp[-4]->getName()+(string)")"+(string)yyvsp[0]->getName()+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 2009 "2005105.tab.c"
    break;

  case 40: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 624 "2005105.y"
                                             {
            logStream << "At line no: " << line_count << " statement: PRINTLN LPAREN ID RPAREN SEMICOLON" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)"println"+(string)"("+(string)yyvsp[-2]->getName()+(string)")"+(string)";"+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 2020 "2005105.tab.c"
    break;

  case 41: /* statement: RETURN expression SEMICOLON  */
#line 630 "2005105.y"
                                      {
            logStream << "At line no: " << line_count << " statement: RETURN expression SEMICOLON" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)"return "+(string)yyvsp[-1]->getName()+(string)";"+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            // Can not return void expression here 
            if(yyvsp[-1]->getReturnType() == "void") {
                /* void function call within expression */
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;
            } 
    }
#line 2038 "2005105.tab.c"
    break;

  case 42: /* embedded_exp: %empty  */
#line 645 "2005105.y"
              {
            /* NOTICE: embedded action */
            type_final = type;
    }
#line 2047 "2005105.tab.c"
    break;

  case 43: /* embedded_void: %empty  */
#line 651 "2005105.y"
               {
            
            /* void checking  */
            if(type_final == "void") {
                /* void function call within expression */
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;
            } 
    }
#line 2061 "2005105.tab.c"
    break;

  case 44: /* expression_statement: SEMICOLON  */
#line 662 "2005105.y"
                                {
            logStream << "At line no: " << line_count << " expression_statement: SEMICOLON" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)";"+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            // type setting -> **************************
            yyval->setReturnType("int");
            type = "int";
    }
#line 2076 "2005105.tab.c"
    break;

  case 45: /* expression_statement: expression SEMICOLON  */
#line 672 "2005105.y"
                               {
            logStream << "At line no: " << line_count << " expression_statement: expression SEMICOLON" << "\n"  << endl;

            yyval = new SymbolInfo((string)"\t"+(string)yyvsp[-1]->getName()+(string)";"+(string)"\n", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

           // type setting -> **************************
           yyval->setReturnType(yyvsp[-1]->getReturnType());
           type = yyvsp[-1]->getReturnType();
    }
#line 2091 "2005105.tab.c"
    break;

  case 46: /* variable: ID  */
#line 684 "2005105.y"
             {
            //Since it is not called as a function, it is a variable
            //This is not variable declaration, this is variable being used in an expression
            logStream << "At line no: " << line_count << " variable: ID" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;         

            /* declaration checking & type setting */
            SymbolInfo* temp = symbolTable->Lookup(yyvsp[0]->getName());

            if(temp == NULL) {
                error << "Error at line no: " << line_count << " undeclared variable " << yyvsp[0]->getName() << "\n" << endl;
                error_count++;
                
                //**********************************************************************************
                yyval->setReturnType("float");  // NOTICE: by default, undeclared variables are of float type
            } 
            else { //Variable previously declared
                if(temp->getReturnType() != "void") yyval->setReturnType(temp->getReturnType()); //void type checking

                else yyval->setReturnType("float");  //matching function found with return type void, $$ modified(not required)
            }

            //Checking whether it is variable or not
            //Can be an array or a function with the same name
            if((temp!=NULL) && (temp->getArraySize()!=-1)) {
                error << "Error at line no: " << line_count << " type mismatch(not variable)" << "\n" << endl;
                error_count++;
            }
    }
#line 2127 "2005105.tab.c"
    break;

  case 47: /* variable: id LTHIRD expression RTHIRD  */
#line 715 "2005105.y"
                                      {
            //An array
            logStream << "At line no: " << line_count << " variable: ID LTHIRD expression RTHIRD" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-3]->getName()+(string)"["+(string)yyvsp[-1]->getName()+(string)"]", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            /* declaration checking & type setting */
            SymbolInfo* temp = symbolTable->Lookup(yyvsp[-3]->getName());

            if(temp == NULL) {
                error << "Error at line no: " << line_count << " undeclared variable " << yyvsp[-3]->getName() << "\n" << endl;
                error_count++;

                yyval->setReturnType("float");  // NOTICE: by default, undeclared variables are of float type
            } 
            else { //Variable previously declared
                if(temp->getReturnType() != "void") yyval->setReturnType(temp->getReturnType()); //void type checking

                else yyval->setReturnType("float");  //matching function found with return type void, $$ modified(not required)
            }

            /* checking whether it is array or not */
            if((temp!=NULL) && (temp->getArraySize() < 0)) {
                error << "Error at line no: " << line_count << " type mismatch(not array)" << "\n" << endl;
                error_count++;
            }

            //SemA:  Array index checking
            if(yyvsp[-1]->getReturnType() != "int") {
                error << "Error at line no: " << line_count << " non-integer array index" << "\n" << endl;
                error_count++;
            }            

            //SemA: If it's a function, it cannot have void return type when called within an expression
            if(yyvsp[-1]->getReturnType() == "void") {
                /* void function call within expression */
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;
            } 
    }
#line 2173 "2005105.tab.c"
    break;

  case 48: /* expression: logic_expression  */
#line 758 "2005105.y"
                             {
            logStream << "At line no: " << line_count << " expression: logic_expression" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            /* type setting -> NOTICE: semantic analysis might be required -> NOTICE: think about void function */
            yyval->setReturnType(yyvsp[0]->getReturnType());
            type = yyvsp[0]->getReturnType();
    }
#line 2188 "2005105.tab.c"
    break;

  case 49: /* expression: variable ASSIGNOP logic_expression  */
#line 768 "2005105.y"
                                             {
            logStream << "At line no: " << line_count << " expression: variable ASSIGNOP logic_expression" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)" = "+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            //Void function cannot be called within expression
            if(yyvsp[0]->getReturnType() == "void") {

                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                yyvsp[0]->setReturnType("float");  // by default, float type
            } 

            //Checking type consistency for assignment
            if(yyvsp[-2]->getReturnType() != yyvsp[0]->getReturnType()) {
                error << "Error at line no: " << line_count << " type mismatch(" << yyvsp[-2]->getReturnType() << "=" << yyvsp[0]->getReturnType() << ")" << "\n" << endl;
                error_count++;
            }

            yyval->setReturnType(yyvsp[-2]->getReturnType());
            type = yyvsp[-2]->getReturnType();
    }
#line 2217 "2005105.tab.c"
    break;

  case 50: /* logic_expression: rel_expression  */
#line 794 "2005105.y"
                                 {
            logStream << "At line no: " << line_count << " logic_expression: rel_expression" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            /* type setting -> NOTICE: semantic analysis might be required */
            yyval->setReturnType(yyvsp[0]->getReturnType());
    }
#line 2231 "2005105.tab.c"
    break;

  case 51: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 803 "2005105.y"
                                                {
            logStream << "At line no: " << line_count << " logic_expression: rel_expression LOGICOP rel_expression" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)yyvsp[-1]->getName()+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            /* type setting -> NOTICE: semantic analysis (type-casting) might be required */

            /* void checking  */
            if(yyvsp[-2]->getReturnType() == "void") {
                /* void function call within expression */
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                /* type setting (if necessary) */
            } 

            if(yyvsp[0]->getReturnType() == "void") {
                /* void function call within expression */
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                /* type setting (if necessary) */
            }

            /* type casting */
            yyval->setReturnType("int");
    }
#line 2264 "2005105.tab.c"
    break;

  case 52: /* rel_expression: simple_expression  */
#line 833 "2005105.y"
                                  {
            logStream << "At line no: " << line_count << " rel_expression: simple_expression" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            /* type setting -> NOTICE: semantic analysis might be required */
            yyval->setReturnType(yyvsp[0]->getReturnType());
    }
#line 2278 "2005105.tab.c"
    break;

  case 53: /* rel_expression: simple_expression RELOP simple_expression  */
#line 842 "2005105.y"
                                                                {
            logStream << "At line no: " << line_count << " rel_expression: simple_expression RELOP simple_expression" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)yyvsp[-1]->getName()+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            /* type setting -> NOTICE: semantic analysis (type-casting) might be required */

            /* void checking  */
            if(yyvsp[-2]->getReturnType() == "void") {
                /* void function call within expression */
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                /* type setting (if necessary) */
            } 

            if(yyvsp[0]->getReturnType() == "void") {
                /* void function call within expression */
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                /* type setting (if necessary) */
            }

            /* type casting */
            yyval->setReturnType("int");
    }
#line 2311 "2005105.tab.c"
    break;

  case 54: /* simple_expression: term  */
#line 872 "2005105.y"
                        {
            logStream << "At line no: " << line_count << " simple_expression: term" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl; 

            /* type setting  */
            yyval->setReturnType(yyvsp[0]->getReturnType());
    }
#line 2325 "2005105.tab.c"
    break;

  case 55: /* simple_expression: simple_expression ADDOP term  */
#line 881 "2005105.y"
                                       {
            logStream << "At line no: " << line_count << " simple_expression: simple_expression ADDOP term" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)yyvsp[-1]->getName()+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            /* type setting -> NOTICE: semantic analysis (type-casting) required  */

            //If type is void, must be a function
            if(yyvsp[-2]->getReturnType() == "void") {
                //Cannot call void function within expression
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                 yyvsp[-2]->setReturnType("float");  // by default, float type
            } 

            //If type is void, must be a function
            if(yyvsp[0]->getReturnType() == "void") {
                //Cannot call void function within expression
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                yyvsp[0]->setReturnType("float");  // by default, float type
            }

            //Type casting for ADDOP
            if(yyvsp[-2]->getReturnType()=="float" || yyvsp[0]->getReturnType()=="float") {
                yyval->setReturnType("float");
            } else {
                yyval->setReturnType(yyvsp[-2]->getReturnType());  // basically, int
            }
    }
#line 2363 "2005105.tab.c"
    break;

  case 56: /* term: unary_expression  */
#line 916 "2005105.y"
                       {
            logStream << "At line no: " << line_count << " term: unary_expression" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            //Type setting
            yyval->setReturnType(yyvsp[0]->getReturnType());
    }
#line 2377 "2005105.tab.c"
    break;

  case 57: /* term: term MULOP unary_expression  */
#line 925 "2005105.y"
                                       {
            logStream << "At line no: " << line_count << " term: term MULOP unary_expression" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)yyvsp[-1]->getName()+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            /* type setting -> NOTICE: semantic analysis (type-casting, mod-operands checking) required */

            //If type is void, must be a function
            if(yyvsp[-2]->getReturnType() == "void") {
                //Cannot call void function within expression
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                yyvsp[-2]->setReturnType("float");  //default
            } 

            //If type is void, must be a function
            if(yyvsp[0]->getReturnType() == "void") {
                //Cannot call void function within expression
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                yyvsp[0]->setReturnType("float");  //default
            } 

            //SemA: Operand type checking, type casting if necessary

            //For modulus operator, both operands need to be of type int
            if((yyvsp[-1]->getName() == "%") && (yyvsp[-2]->getReturnType() != "int" || yyvsp[0]->getReturnType() != "int")) {
                
                error << "Error at line no: " << line_count << " operand type mismatch for modulus operator" << "\n" << endl;
                error_count++;

                yyval->setReturnType("int");  //Type casting

            } 

            //For other operators, ensuring precedence of float
            else if((yyvsp[-1]->getName() != "%") && (yyvsp[-2]->getReturnType() == "float" || yyvsp[0]->getReturnType() == "float")) {
                yyval->setReturnType("float");  
            } 

            //Other types are allowed
            else {
                yyval->setReturnType(yyvsp[-2]->getReturnType());
            }
    }
#line 2430 "2005105.tab.c"
    break;

  case 58: /* unary_expression: ADDOP unary_expression  */
#line 975 "2005105.y"
                                         {
            logStream << "At line no: " << line_count << " unary_expression: ADDOP unary_expression" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-1]->getName()+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            //If type is void, must be a function 
            if(yyvsp[0]->getReturnType() == "void") {
                //Cannot call void function within expression 
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                /* type setting (if necessary) */
                yyval->setReturnType("float");  // by default, float type
            } 
            else {
                //Type allowed
                yyval->setReturnType(yyvsp[0]->getReturnType());
            }
    }
#line 2455 "2005105.tab.c"
    break;

  case 59: /* unary_expression: NOT unary_expression  */
#line 995 "2005105.y"
                               {
            logStream << "At line no: " << line_count << " unary_expression: NOT unary_expression" << "\n"  << endl;

            yyval = new SymbolInfo((string)"!"+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            //If type is void, must be a function
            if(yyvsp[0]->getReturnType() == "void") {
                //Cannot call void function within expression 
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                /* type setting (if necessary) */
            }

            yyval->setReturnType("int");
    }
#line 2477 "2005105.tab.c"
    break;

  case 60: /* unary_expression: factor  */
#line 1012 "2005105.y"
                 {
            logStream << "At line no: " << line_count << " unary_expression: factor" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            yyval->setReturnType(yyvsp[0]->getReturnType());
    }
#line 2490 "2005105.tab.c"
    break;

  case 61: /* factor: variable  */
#line 1022 "2005105.y"
                 {
            logStream << "At line no: " << line_count << " factor: variable" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            yyval->setReturnType(yyvsp[0]->getReturnType());
    }
#line 2503 "2005105.tab.c"
    break;

  case 62: /* factor: ID LPAREN argument_list RPAREN  */
#line 1030 "2005105.y"
                                         {
            logStream << "At line no: " << line_count << " factor: ID LPAREN argument_list RPAREN" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-3]->getName()+(string)"("+(string)yyvsp[-1]->getName()+(string)")", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            //SemA: 
            SymbolInfo* lookupNode = symbolTable->Lookup(yyvsp[-3]->getName());

            if(lookupNode == NULL) {
                //No matching function to call
                error << "Error at line no: " << line_count << " no such identifier found" << "\n" << endl;
                error_count++;

                yyval->setReturnType("float");  //default

            } 
            //For function call, function has to be defined
            else if(lookupNode->getArraySize() != -3) {
                error << "Error at line no: " << line_count << " no such function definition found" << "\n" << endl;
                error_count++;

                yyval->setReturnType("float");  //default

            } 

            //Function defintion found, so now we match argument list with function's parameter list
            else {
                //Function has no parameter, no argumnet passed
                if(lookupNode->getParameterListSize()==1 && argumentList.size()==0 && lookupNode->getParameter(0).getType()=="void") {
                    yyval->setReturnType(lookupNode->getReturnType()); //Allowed
                } 

                //Parameter List and Argument List Size matching
                else if(lookupNode->getParameterListSize() != argumentList.size()) {
                    //No match -> error
                    error << "Error at line no: " << line_count << " inconsistent function call" << "\n" << endl;
                    error_count++;

                    yyval->setReturnType("float");  //default

                } 
                else {

                    bool validFunctionCall = true;

                    for(int i=0; i<argumentList.size(); i++) {
                        if(lookupNode->getParameter(i).getType() != argumentList[i]) {
                            validFunctionCall = false;
                            break;
                        }
                    }
                    
                    //Type casting
                    if(validFunctionCall) yyval->setReturnType(lookupNode->getReturnType());
                    
                }
            }

            argumentList.clear(); 
    }
#line 2569 "2005105.tab.c"
    break;

  case 63: /* factor: LPAREN expression RPAREN  */
#line 1091 "2005105.y"
                                   {
            logStream << "At line no: " << line_count << " factor: LPAREN expression RPAREN" << "\n"  << endl;

            yyval = new SymbolInfo((string)"("+(string)yyvsp[-1]->getName()+(string)")", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            //If type is void, must be a function
            if(yyvsp[-1]->getReturnType() == "void") {
                //Cannot call void function within expression
                error << "Error at line no: " << line_count << " void function called within expression" << "\n" << endl;
                error_count++;

                yyvsp[-1]->setReturnType("float");  //default
            } 

            yyval->setReturnType(yyvsp[-1]->getReturnType());
    }
#line 2591 "2005105.tab.c"
    break;

  case 64: /* factor: CONST_INT  */
#line 1108 "2005105.y"
                    {
            logStream << "At line no: " << line_count << " factor: CONST_INT" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            yyval->setReturnType("int");
    }
#line 2604 "2005105.tab.c"
    break;

  case 65: /* factor: CONST_FLOAT  */
#line 1116 "2005105.y"
                      {
            logStream << "At line no: " << line_count << " factor: CONST_FLOAT" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            yyval->setReturnType("float");
    }
#line 2617 "2005105.tab.c"
    break;

  case 66: /* factor: variable INCOP  */
#line 1124 "2005105.y"
                         {
            logStream << "At line no: " << line_count << " factor: variable INCOP" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-1]->getName()+(string)"++", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            yyval->setReturnType(yyvsp[-1]->getReturnType());
    }
#line 2630 "2005105.tab.c"
    break;

  case 67: /* factor: variable DECOP  */
#line 1132 "2005105.y"
                         {
            logStream << "At line no: " << line_count << " factor: variable DECOP" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-1]->getName()+(string)"--", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            yyval->setReturnType(yyvsp[-1]->getReturnType());
    }
#line 2643 "2005105.tab.c"
    break;

  case 68: /* argument_list: arguments  */
#line 1142 "2005105.y"
                         {
            logStream << "At line no: " << line_count << " argument_list: arguments" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 2654 "2005105.tab.c"
    break;

  case 69: /* argument_list: %empty  */
#line 1148 "2005105.y"
          {
            //Empty/ epsilin production rule************************************
            logStream << "At line no: " << line_count << " argument_list: <epsilon-production>" << "\n"  << endl;
            
            yyval = new SymbolInfo("", "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;
    }
#line 2666 "2005105.tab.c"
    break;

  case 70: /* arguments: arguments COMMA logic_expression  */
#line 1157 "2005105.y"
                                            {
            logStream << "At line no: " << line_count << " arguments: arguments COMMA logic_expression" << "\n"  << endl;

            yyval = new SymbolInfo((string)yyvsp[-2]->getName()+(string)", "+(string)yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            //If type is void, must be a function
            if(yyvsp[0]->getReturnType() == "void") {
                //Cannot call void function within argument of function
                error << "Error at line no: " << line_count << " void function called within argument of function" << "\n" << endl;
                error_count++;

                yyvsp[0]->setReturnType("float");  //default
            } 

            /* keeping track of encountered argument */
            argumentList.push_back(yyvsp[0]->getReturnType());
    }
#line 2689 "2005105.tab.c"
    break;

  case 71: /* arguments: logic_expression  */
#line 1175 "2005105.y"
                           {
            logStream << "At line no: " << line_count << " arguments: logic_expression" << "\n"  << endl;

            yyval = new SymbolInfo(yyvsp[0]->getName(), "NON_TERMINAL");
            logStream << yyval->getName() << "\n"  << endl;

            //If type is void, must be a function
            if(yyvsp[0]->getReturnType() == "void") {
                //Cannot call void function within argument of function
                error << "Error at line no: " << line_count << " void function called within argument of function" << "\n" << endl;
                error_count++;

                yyvsp[0]->setReturnType("float"); //default
            } 

            /* keeping track of encountered argument */
            argumentList.push_back(yyvsp[0]->getReturnType());
    }
#line 2712 "2005105.tab.c"
    break;


#line 2716 "2005105.tab.c"

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

  return yyresult;
}

#line 1196 "2005105.y"



int main(int argc, char* argv[]) {
	if(argc != 2) {
		cout << "Input file name not provided for parsing." << endl;
		return 0;
	}

    input = fopen(argv[1], "r");

    if(input == NULL) {
		cout << "input file not opened properly, terminating program..." << endl;
		exit(0);
	}

	logStream.open("2005105_log.txt", ios::out);
	error.open("2005105_error.txt", ios::out);
	
	if(logStream.is_open() != true) {
		cout << "Log file not available" << endl;
		fclose(input);
		
		exit(0);
	}
	
	if(error.is_open() != true) {
		cout << "Error file not available" << endl;
		fclose(input);
		logStream.close();
		
		exit(0);
	}
	
    int scopeTablesSize = 10;
	ScopeTable* scopeTable = new ScopeTable(scopeTablesSize);
    symbolTable = new SymbolTable(scopeTable, scopeTablesSize, logStream);
	
	yyin = input;
    yyparse();  // processing starts

    logStream << endl;
	symbolTable->printAllScopeTable(logStream);
	symbolTable->ExitScope();

	logStream << "Total Lines: " << (--line_count) << endl;  // NOTICE here: line_count changed (July 19) -> works for sample
	logStream << "\n" << "Total Errors: " << error_count << endl;
    error << "\n" << "Total Errors: " << error_count << endl;
	
	fclose(yyin);
	logStream.close();
	error.close();
	
	return 0;
} 

void yyerror(string s) {
    /* it may be modified later */
    logStream << "At line no: " << line_count << " " << s << endl;

    line_count++;
    error_count++;
    
    return ;
}
