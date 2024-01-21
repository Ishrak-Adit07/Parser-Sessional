/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_2005105_TAB_H_INCLUDED
# define YY_YY_2005105_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    CONST_INT = 258,               /* CONST_INT  */
    CONST_FLOAT = 259,             /* CONST_FLOAT  */
    ID = 260,                      /* ID  */
    DO = 261,                      /* DO  */
    SWITCH = 262,                  /* SWITCH  */
    DEFAULT = 263,                 /* DEFAULT  */
    BREAK = 264,                   /* BREAK  */
    CASE = 265,                    /* CASE  */
    CONTINUE = 266,                /* CONTINUE  */
    CONST_CHAR = 267,              /* CONST_CHAR  */
    INT = 268,                     /* INT  */
    FLOAT = 269,                   /* FLOAT  */
    VOID = 270,                    /* VOID  */
    IF = 271,                      /* IF  */
    ELSE = 272,                    /* ELSE  */
    FOR = 273,                     /* FOR  */
    WHILE = 274,                   /* WHILE  */
    PRINTLN = 275,                 /* PRINTLN  */
    RETURN = 276,                  /* RETURN  */
    MAIN = 277,                    /* MAIN  */
    CHAR = 278,                    /* CHAR  */
    DOUBLE = 279,                  /* DOUBLE  */
    ASSIGNOP = 280,                /* ASSIGNOP  */
    NOT = 281,                     /* NOT  */
    INCOP = 282,                   /* INCOP  */
    DECOP = 283,                   /* DECOP  */
    LOGICOP = 284,                 /* LOGICOP  */
    RELOP = 285,                   /* RELOP  */
    ADDOP = 286,                   /* ADDOP  */
    MULOP = 287,                   /* MULOP  */
    BITOP = 288,                   /* BITOP  */
    LPAREN = 289,                  /* LPAREN  */
    RPAREN = 290,                  /* RPAREN  */
    LCURL = 291,                   /* LCURL  */
    RCURL = 292,                   /* RCURL  */
    LTHIRD = 293,                  /* LTHIRD  */
    RTHIRD = 294,                  /* RTHIRD  */
    COMMA = 295,                   /* COMMA  */
    SEMICOLON = 296,               /* SEMICOLON  */
    SINGLE_LINE_STRING = 297,      /* SINGLE_LINE_STRING  */
    MULTI_LINE_STRING = 298,       /* MULTI_LINE_STRING  */
    UNFINISHED_STRING = 299,       /* UNFINISHED_STRING  */
    MULTI_LINE_COMMENT = 300,      /* MULTI_LINE_COMMENT  */
    UNFINISHED_COMMENT = 301,      /* UNFINISHED_COMMENT  */
    SINGLE_LINE_COMMENT = 302,     /* SINGLE_LINE_COMMENT  */
    UNFINISHED_NUMBER = 303,       /* UNFINISHED_NUMBER  */
    TOO_MANY_DECIMAL_POINTS = 304, /* TOO_MANY_DECIMAL_POINTS  */
    ILLFORMED_NUMBER = 305,        /* ILLFORMED_NUMBER  */
    EMPTY_CONST_CHAR = 306,        /* EMPTY_CONST_CHAR  */
    UNFINISHED_CONST_CHAR = 307,   /* UNFINISHED_CONST_CHAR  */
    MULTICHAR_CONST_CHAR = 308,    /* MULTICHAR_CONST_CHAR  */
    UNRECOGNIZED_CHAR = 309,       /* UNRECOGNIZED_CHAR  */
    INVALID_ID_SUFFIX_NUM_PREFIX = 310, /* INVALID_ID_SUFFIX_NUM_PREFIX  */
    LOWER_THAN_ELSE = 311          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef SymbolInfo* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_2005105_TAB_H_INCLUDED  */
