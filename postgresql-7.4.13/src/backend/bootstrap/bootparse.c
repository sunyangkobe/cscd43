/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with Int_yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum Int_yytokentype {
     CONST_P = 258,
     ID = 259,
     OPEN = 260,
     XCLOSE = 261,
     XCREATE = 262,
     INSERT_TUPLE = 263,
     STRING = 264,
     XDEFINE = 265,
     XDECLARE = 266,
     INDEX = 267,
     ON = 268,
     USING = 269,
     XBUILD = 270,
     INDICES = 271,
     UNIQUE = 272,
     COMMA = 273,
     EQUALS = 274,
     LPAREN = 275,
     RPAREN = 276,
     OBJ_ID = 277,
     XBOOTSTRAP = 278,
     XSHARED_RELATION = 279,
     XWITHOUT_OIDS = 280,
     NULLVAL = 281,
     low = 282,
     high = 283
   };
#endif
/* Tokens.  */
#define CONST_P 258
#define ID 259
#define OPEN 260
#define XCLOSE 261
#define XCREATE 262
#define INSERT_TUPLE 263
#define STRING 264
#define XDEFINE 265
#define XDECLARE 266
#define INDEX 267
#define ON 268
#define USING 269
#define XBUILD 270
#define INDICES 271
#define UNIQUE 272
#define COMMA 273
#define EQUALS 274
#define LPAREN 275
#define RPAREN 276
#define OBJ_ID 277
#define XBOOTSTRAP 278
#define XSHARED_RELATION 279
#define XWITHOUT_OIDS 280
#define NULLVAL 281
#define low 282
#define high 283




/* Copy the first part of user declarations.  */
#line 1 "bootparse.y"

/*-------------------------------------------------------------------------
 *
 * bootparse.y
 *	  yacc parser grammar for the "backend" initialization program.
 *
 * Portions Copyright (c) 1996-2003, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  $Header: /cvsroot/pgsql/src/backend/bootstrap/bootparse.y,v 1.60 2003/08/04 02:39:57 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"

#include <time.h>
#include <unistd.h>

#include "access/attnum.h"
#include "access/htup.h"
#include "access/itup.h"
#include "access/skey.h"
#include "access/strat.h"
#include "access/tupdesc.h"
#include "access/xact.h"
#include "bootstrap/bootstrap.h"
#include "catalog/catalog.h"
#include "catalog/heap.h"
#include "catalog/pg_am.h"
#include "catalog/pg_attribute.h"
#include "catalog/pg_class.h"
#include "catalog/pg_namespace.h"
#include "commands/defrem.h"
#include "miscadmin.h"
#include "nodes/makefuncs.h"
#include "nodes/nodes.h"
#include "nodes/parsenodes.h"
#include "nodes/pg_list.h"
#include "nodes/primnodes.h"
#include "rewrite/prs2lock.h"
#include "storage/block.h"
#include "storage/fd.h"
#include "storage/ipc.h"
#include "storage/itemptr.h"
#include "storage/off.h"
#include "storage/smgr.h"
#include "tcop/dest.h"
#include "utils/nabstime.h"
#include "utils/rel.h"


static void
do_start()
{
	StartTransactionCommand();
	elog(DEBUG4, "start transaction");
}


static void
do_end()
{
	CommitTransactionCommand();
	elog(DEBUG4, "commit transaction");
	if (isatty(0))
	{
		printf("bootstrap> ");
		fflush(stdout);
	}
}


int num_columns_read = 0;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 81 "bootparse.y"
{
	List		*list;
	IndexElem	*ielem;
	char		*str;
	int			ival;
	Oid			oidval;
}
/* Line 187 of yacc.c.  */
#line 239 "y.tab.c"
	YYSTYPE;
# define Int_yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 252 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 Int_yytype_uint8;
#else
typedef unsigned char Int_yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 Int_yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char Int_yytype_int8;
#else
typedef short int Int_yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 Int_yytype_uint16;
#else
typedef unsigned short int Int_yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 Int_yytype_int16;
#else
typedef short int Int_yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined Int_yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined Int_yyoverflow || YYERROR_VERBOSE */


#if (! defined Int_yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union Int_yyalloc
{
  Int_yytype_int16 Int_yyss;
  YYSTYPE Int_yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union Int_yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (Int_yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T Int_yyi;				\
	  for (Int_yyi = 0; Int_yyi < (Count); Int_yyi++)	\
	    (To)[Int_yyi] = (From)[Int_yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T Int_yynewbytes;						\
	YYCOPY (&Int_yyptr->Stack, Stack, Int_yysize);				\
	Stack = &Int_yyptr->Stack;						\
	Int_yynewbytes = Int_yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	Int_yyptr += Int_yynewbytes / sizeof (*Int_yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   74

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNRULES -- Number of states.  */
#define YYNSTATES  81

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? Int_yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const Int_yytype_uint8 Int_yytranslate[] =
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const Int_yytype_uint8 Int_yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    28,    31,    33,    34,    35,    46,
      47,    54,    65,    77,    80,    84,    86,    89,    91,    92,
      94,    95,    97,    98,   100,   104,   108,   112,   113,   115,
     118,   122,   124,   126,   128,   130
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const Int_yytype_int8 Int_yyrhs[] =
{
      30,     0,    -1,    31,    -1,    -1,    32,    -1,    31,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    38,    -1,    40,
      -1,    41,    -1,    42,    -1,     5,    54,    -1,     6,    54,
      -1,     6,    -1,    -1,    -1,     7,    45,    46,    47,    54,
      20,    36,    48,    37,    21,    -1,    -1,     8,    50,    39,
      20,    51,    21,    -1,    11,    12,    54,    13,    54,    14,
      54,    20,    43,    21,    -1,    11,    17,    12,    54,    13,
      54,    14,    54,    20,    43,    21,    -1,    15,    16,    -1,
      43,    18,    44,    -1,    44,    -1,    54,    54,    -1,    23,
      -1,    -1,    24,    -1,    -1,    25,    -1,    -1,    49,    -1,
      48,    18,    49,    -1,    54,    19,    54,    -1,    22,    19,
      54,    -1,    -1,    52,    -1,    51,    52,    -1,    51,    18,
      52,    -1,    54,    -1,    53,    -1,    26,    -1,     3,    -1,
       4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const Int_yytype_uint16 Int_yyrline[] =
{
       0,   110,   110,   111,   115,   116,   120,   121,   122,   123,
     124,   125,   126,   130,   139,   145,   155,   164,   154,   210,
     209,   234,   248,   262,   267,   268,   272,   283,   284,   288,
     289,   293,   294,   298,   299,   303,   312,   313,   317,   318,
     319,   323,   325,   327,   332,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const Int_yytname[] =
{
  "$end", "error", "$undefined", "CONST_P", "ID", "OPEN", "XCLOSE",
  "XCREATE", "INSERT_TUPLE", "STRING", "XDEFINE", "XDECLARE", "INDEX",
  "ON", "USING", "XBUILD", "INDICES", "UNIQUE", "COMMA", "EQUALS",
  "LPAREN", "RPAREN", "OBJ_ID", "XBOOTSTRAP", "XSHARED_RELATION",
  "XWITHOUT_OIDS", "NULLVAL", "low", "high", "$accept", "TopLevel",
  "Boot_Queries", "Boot_Query", "Boot_OpenStmt", "Boot_CloseStmt",
  "Boot_CreateStmt", "@1", "@2", "Boot_InsertStmt", "@3",
  "Boot_DeclareIndexStmt", "Boot_DeclareUniqueIndexStmt",
  "Boot_BuildIndsStmt", "boot_index_params", "boot_index_param",
  "optbootstrap", "optsharedrelation", "optwithoutoids", "boot_typelist",
  "boot_type_thing", "optoideq", "boot_tuplelist", "boot_tuple",
  "boot_const", "boot_ident", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const Int_yytype_uint16 Int_yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const Int_yytype_uint8 Int_yyr1[] =
{
       0,    29,    30,    30,    31,    31,    32,    32,    32,    32,
      32,    32,    32,    33,    34,    34,    36,    37,    35,    39,
      38,    40,    41,    42,    43,    43,    44,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    50,    50,    51,    51,
      51,    52,    52,    52,    53,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const Int_yytype_uint8 Int_yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     0,     0,    10,     0,
       6,    10,    11,     2,     3,     1,     2,     1,     0,     1,
       0,     1,     0,     1,     3,     3,     3,     0,     1,     2,
       3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const Int_yytype_uint8 Int_yydefact[] =
{
       3,     0,    15,    28,    37,     0,     0,     0,     2,     4,
       6,     7,     8,     9,    10,    11,    12,    45,    13,    14,
      27,    30,     0,    19,     0,     0,    23,     1,     5,    29,
      32,     0,     0,     0,     0,    31,     0,    36,     0,     0,
       0,     0,    44,    43,     0,    38,    42,    41,     0,     0,
      16,     0,    20,    39,     0,     0,     0,    40,     0,     0,
      17,    33,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,    34,    18,    35,     0,    21,    26,     0,    24,
      22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const Int_yytype_int8 Int_yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    12,    56,    66,    13,
      32,    14,    15,    16,    68,    69,    21,    30,    36,    60,
      61,    23,    44,    45,    46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -38
static const Int_yytype_int8 Int_yypact[] =
{
       4,    -2,    -2,    -7,    -5,    -4,     9,    20,     4,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,     7,     3,   -38,    -2,    22,   -38,   -38,   -38,   -38,
      12,    -2,    16,    26,    -2,   -38,    -2,   -38,     2,    -2,
      27,    21,   -38,   -38,     0,   -38,   -38,   -38,    28,    -2,
     -38,     2,   -38,   -38,    -2,    29,    -2,   -38,    24,    -2,
      31,   -38,    32,    -2,    25,    -2,    33,    -2,     6,   -38,
      -2,    -2,   -38,   -38,   -38,    -2,   -38,   -38,    11,   -38,
     -38
};

/* YYPGOTO[NTERM-NUM].  */
static const Int_yytype_int8 Int_yypgoto[] =
{
     -38,   -38,   -38,    38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -24,   -25,   -38,   -38,   -38,   -38,
     -13,   -38,   -38,   -37,   -38,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const Int_yytype_uint8 Int_yytable[] =
{
      18,    19,    17,    42,    17,    42,    17,    53,    24,     1,
       2,     3,     4,    25,    57,     5,    20,    22,    51,     6,
      27,    52,    31,    33,    75,    26,    43,    76,    43,    75,
      37,    29,    80,    40,    34,    41,    38,    35,    48,    39,
      49,    50,    54,    59,    63,    71,    28,    78,    55,    65,
      79,    67,    72,    58,    73,    62,     0,     0,    64,     0,
       0,     0,    70,     0,    62,     0,    74,     0,     0,    77,
      70,     0,     0,     0,    70
};

static const Int_yytype_int8 Int_yycheck[] =
{
       1,     2,     4,     3,     4,     3,     4,    44,    12,     5,
       6,     7,     8,    17,    51,    11,    23,    22,    18,    15,
       0,    21,    19,    24,    18,    16,    26,    21,    26,    18,
      31,    24,    21,    34,    12,    36,    20,    25,    39,    13,
      13,    20,    14,    14,    20,    20,     8,    71,    49,    18,
      75,    19,    65,    54,    21,    56,    -1,    -1,    59,    -1,
      -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,    70,
      71,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const Int_yytype_uint8 Int_yystos[] =
{
       0,     5,     6,     7,     8,    11,    15,    30,    31,    32,
      33,    34,    35,    38,    40,    41,    42,     4,    54,    54,
      23,    45,    22,    50,    12,    17,    16,     0,    32,    24,
      46,    19,    39,    54,    12,    25,    47,    54,    20,    13,
      54,    54,     3,    26,    51,    52,    53,    54,    54,    13,
      20,    18,    21,    52,    14,    54,    36,    52,    54,    14,
      48,    49,    54,    20,    54,    18,    37,    19,    43,    44,
      54,    20,    49,    21,    54,    18,    21,    54,    43,    44,
      21
};

#define Int_yyerrok		(Int_yyerrstatus = 0)
#define Int_yyclearin	(Int_yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto Int_yyacceptlab
#define YYABORT		goto Int_yyabortlab
#define YYERROR		goto Int_yyerrorlab


/* Like YYERROR except do call Int_yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto Int_yyerrlab

#define YYRECOVERING()  (!!Int_yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (Int_yychar == YYEMPTY && Int_yylen == 1)				\
    {								\
      Int_yychar = (Token);						\
      Int_yylval = (Value);						\
      Int_yytoken = YYTRANSLATE (Int_yychar);				\
      YYPOPSTACK (1);						\
      goto Int_yybackup;						\
    }								\
  else								\
    {								\
      Int_yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `Int_yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX Int_yylex (YYLEX_PARAM)
#else
# define YYLEX Int_yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (Int_yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (Int_yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      Int_yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
Int_yy_symbol_value_print (FILE *Int_yyoutput, int Int_yytype, YYSTYPE const * const Int_yyvaluep)
#else
static void
Int_yy_symbol_value_print (Int_yyoutput, Int_yytype, Int_yyvaluep)
    FILE *Int_yyoutput;
    int Int_yytype;
    YYSTYPE const * const Int_yyvaluep;
#endif
{
  if (!Int_yyvaluep)
    return;
# ifdef YYPRINT
  if (Int_yytype < YYNTOKENS)
    YYPRINT (Int_yyoutput, Int_yytoknum[Int_yytype], *Int_yyvaluep);
# else
  YYUSE (Int_yyoutput);
# endif
  switch (Int_yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
Int_yy_symbol_print (FILE *Int_yyoutput, int Int_yytype, YYSTYPE const * const Int_yyvaluep)
#else
static void
Int_yy_symbol_print (Int_yyoutput, Int_yytype, Int_yyvaluep)
    FILE *Int_yyoutput;
    int Int_yytype;
    YYSTYPE const * const Int_yyvaluep;
#endif
{
  if (Int_yytype < YYNTOKENS)
    YYFPRINTF (Int_yyoutput, "token %s (", Int_yytname[Int_yytype]);
  else
    YYFPRINTF (Int_yyoutput, "nterm %s (", Int_yytname[Int_yytype]);

  Int_yy_symbol_value_print (Int_yyoutput, Int_yytype, Int_yyvaluep);
  YYFPRINTF (Int_yyoutput, ")");
}

/*------------------------------------------------------------------.
| Int_yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
Int_yy_stack_print (Int_yytype_int16 *bottom, Int_yytype_int16 *top)
#else
static void
Int_yy_stack_print (bottom, top)
    Int_yytype_int16 *bottom;
    Int_yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (Int_yydebug)							\
    Int_yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
Int_yy_reduce_print (YYSTYPE *Int_yyvsp, int Int_yyrule)
#else
static void
Int_yy_reduce_print (Int_yyvsp, Int_yyrule)
    YYSTYPE *Int_yyvsp;
    int Int_yyrule;
#endif
{
  int Int_yynrhs = Int_yyr2[Int_yyrule];
  int Int_yyi;
  unsigned long int Int_yylno = Int_yyrline[Int_yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     Int_yyrule - 1, Int_yylno);
  /* The symbols being reduced.  */
  for (Int_yyi = 0; Int_yyi < Int_yynrhs; Int_yyi++)
    {
      fprintf (stderr, "   $%d = ", Int_yyi + 1);
      Int_yy_symbol_print (stderr, Int_yyrhs[Int_yyprhs[Int_yyrule] + Int_yyi],
		       &(Int_yyvsp[(Int_yyi + 1) - (Int_yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (Int_yydebug)				\
    Int_yy_reduce_print (Int_yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int Int_yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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

# ifndef Int_yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define Int_yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
Int_yystrlen (const char *Int_yystr)
#else
static YYSIZE_T
Int_yystrlen (Int_yystr)
    const char *Int_yystr;
#endif
{
  YYSIZE_T Int_yylen;
  for (Int_yylen = 0; Int_yystr[Int_yylen]; Int_yylen++)
    continue;
  return Int_yylen;
}
#  endif
# endif

# ifndef Int_yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define Int_yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
Int_yystpcpy (char *Int_yydest, const char *Int_yysrc)
#else
static char *
Int_yystpcpy (Int_yydest, Int_yysrc)
    char *Int_yydest;
    const char *Int_yysrc;
#endif
{
  char *Int_yyd = Int_yydest;
  const char *Int_yys = Int_yysrc;

  while ((*Int_yyd++ = *Int_yys++) != '\0')
    continue;

  return Int_yyd - 1;
}
#  endif
# endif

# ifndef Int_yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for Int_yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from Int_yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
Int_yytnamerr (char *Int_yyres, const char *Int_yystr)
{
  if (*Int_yystr == '"')
    {
      YYSIZE_T Int_yyn = 0;
      char const *Int_yyp = Int_yystr;

      for (;;)
	switch (*++Int_yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++Int_yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (Int_yyres)
	      Int_yyres[Int_yyn] = *Int_yyp;
	    Int_yyn++;
	    break;

	  case '"':
	    if (Int_yyres)
	      Int_yyres[Int_yyn] = '\0';
	    return Int_yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! Int_yyres)
    return Int_yystrlen (Int_yystr);

  return Int_yystpcpy (Int_yyres, Int_yystr) - Int_yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
Int_yysyntax_error (char *Int_yyresult, int Int_yystate, int Int_yychar)
{
  int Int_yyn = Int_yypact[Int_yystate];

  if (! (YYPACT_NINF < Int_yyn && Int_yyn <= YYLAST))
    return 0;
  else
    {
      int Int_yytype = YYTRANSLATE (Int_yychar);
      YYSIZE_T Int_yysize0 = Int_yytnamerr (0, Int_yytname[Int_yytype]);
      YYSIZE_T Int_yysize = Int_yysize0;
      YYSIZE_T Int_yysize1;
      int Int_yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *Int_yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int Int_yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *Int_yyfmt;
      char const *Int_yyf;
      static char const Int_yyunexpected[] = "syntax error, unexpected %s";
      static char const Int_yyexpecting[] = ", expecting %s";
      static char const Int_yyor[] = " or %s";
      char Int_yyformat[sizeof Int_yyunexpected
		    + sizeof Int_yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof Int_yyor - 1))];
      char const *Int_yyprefix = Int_yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int Int_yyxbegin = Int_yyn < 0 ? -Int_yyn : 0;

      /* Stay within bounds of both Int_yycheck and Int_yytname.  */
      int Int_yychecklim = YYLAST - Int_yyn + 1;
      int Int_yyxend = Int_yychecklim < YYNTOKENS ? Int_yychecklim : YYNTOKENS;
      int Int_yycount = 1;

      Int_yyarg[0] = Int_yytname[Int_yytype];
      Int_yyfmt = Int_yystpcpy (Int_yyformat, Int_yyunexpected);

      for (Int_yyx = Int_yyxbegin; Int_yyx < Int_yyxend; ++Int_yyx)
	if (Int_yycheck[Int_yyx + Int_yyn] == Int_yyx && Int_yyx != YYTERROR)
	  {
	    if (Int_yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		Int_yycount = 1;
		Int_yysize = Int_yysize0;
		Int_yyformat[sizeof Int_yyunexpected - 1] = '\0';
		break;
	      }
	    Int_yyarg[Int_yycount++] = Int_yytname[Int_yyx];
	    Int_yysize1 = Int_yysize + Int_yytnamerr (0, Int_yytname[Int_yyx]);
	    Int_yysize_overflow |= (Int_yysize1 < Int_yysize);
	    Int_yysize = Int_yysize1;
	    Int_yyfmt = Int_yystpcpy (Int_yyfmt, Int_yyprefix);
	    Int_yyprefix = Int_yyor;
	  }

      Int_yyf = YY_(Int_yyformat);
      Int_yysize1 = Int_yysize + Int_yystrlen (Int_yyf);
      Int_yysize_overflow |= (Int_yysize1 < Int_yysize);
      Int_yysize = Int_yysize1;

      if (Int_yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (Int_yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *Int_yyp = Int_yyresult;
	  int Int_yyi = 0;
	  while ((*Int_yyp = *Int_yyf) != '\0')
	    {
	      if (*Int_yyp == '%' && Int_yyf[1] == 's' && Int_yyi < Int_yycount)
		{
		  Int_yyp += Int_yytnamerr (Int_yyp, Int_yyarg[Int_yyi++]);
		  Int_yyf += 2;
		}
	      else
		{
		  Int_yyp++;
		  Int_yyf++;
		}
	    }
	}
      return Int_yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
Int_yydestruct (const char *Int_yymsg, int Int_yytype, YYSTYPE *Int_yyvaluep)
#else
static void
Int_yydestruct (Int_yymsg, Int_yytype, Int_yyvaluep)
    const char *Int_yymsg;
    int Int_yytype;
    YYSTYPE *Int_yyvaluep;
#endif
{
  YYUSE (Int_yyvaluep);

  if (!Int_yymsg)
    Int_yymsg = "Deleting";
  YY_SYMBOL_PRINT (Int_yymsg, Int_yytype, Int_yyvaluep, Int_yylocationp);

  switch (Int_yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int Int_yyparse (void *YYPARSE_PARAM);
#else
int Int_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int Int_yyparse (void);
#else
int Int_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int Int_yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE Int_yylval;

/* Number of syntax errors so far.  */
int Int_yynerrs;



/*----------.
| Int_yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
Int_yyparse (void *YYPARSE_PARAM)
#else
int
Int_yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
Int_yyparse (void)
#else
int
Int_yyparse ()

#endif
#endif
{
  
  int Int_yystate;
  int Int_yyn;
  int Int_yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int Int_yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int Int_yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char Int_yymsgbuf[128];
  char *Int_yymsg = Int_yymsgbuf;
  YYSIZE_T Int_yymsg_alloc = sizeof Int_yymsgbuf;
#endif

  /* Three stacks and their tools:
     `Int_yyss': related to states,
     `Int_yyvs': related to semantic values,
     `Int_yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow Int_yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  Int_yytype_int16 Int_yyssa[YYINITDEPTH];
  Int_yytype_int16 *Int_yyss = Int_yyssa;
  Int_yytype_int16 *Int_yyssp;

  /* The semantic value stack.  */
  YYSTYPE Int_yyvsa[YYINITDEPTH];
  YYSTYPE *Int_yyvs = Int_yyvsa;
  YYSTYPE *Int_yyvsp;



#define YYPOPSTACK(N)   (Int_yyvsp -= (N), Int_yyssp -= (N))

  YYSIZE_T Int_yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE Int_yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int Int_yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  Int_yystate = 0;
  Int_yyerrstatus = 0;
  Int_yynerrs = 0;
  Int_yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  Int_yyssp = Int_yyss;
  Int_yyvsp = Int_yyvs;

  goto Int_yysetstate;

/*------------------------------------------------------------.
| Int_yynewstate -- Push a new state, which is found in Int_yystate.  |
`------------------------------------------------------------*/
 Int_yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  Int_yyssp++;

 Int_yysetstate:
  *Int_yyssp = Int_yystate;

  if (Int_yyss + Int_yystacksize - 1 <= Int_yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T Int_yysize = Int_yyssp - Int_yyss + 1;

#ifdef Int_yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *Int_yyvs1 = Int_yyvs;
	Int_yytype_int16 *Int_yyss1 = Int_yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if Int_yyoverflow is a macro.  */
	Int_yyoverflow (YY_("memory exhausted"),
		    &Int_yyss1, Int_yysize * sizeof (*Int_yyssp),
		    &Int_yyvs1, Int_yysize * sizeof (*Int_yyvsp),

		    &Int_yystacksize);

	Int_yyss = Int_yyss1;
	Int_yyvs = Int_yyvs1;
      }
#else /* no Int_yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto Int_yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= Int_yystacksize)
	goto Int_yyexhaustedlab;
      Int_yystacksize *= 2;
      if (YYMAXDEPTH < Int_yystacksize)
	Int_yystacksize = YYMAXDEPTH;

      {
	Int_yytype_int16 *Int_yyss1 = Int_yyss;
	union Int_yyalloc *Int_yyptr =
	  (union Int_yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (Int_yystacksize));
	if (! Int_yyptr)
	  goto Int_yyexhaustedlab;
	YYSTACK_RELOCATE (Int_yyss);
	YYSTACK_RELOCATE (Int_yyvs);

#  undef YYSTACK_RELOCATE
	if (Int_yyss1 != Int_yyssa)
	  YYSTACK_FREE (Int_yyss1);
      }
# endif
#endif /* no Int_yyoverflow */

      Int_yyssp = Int_yyss + Int_yysize - 1;
      Int_yyvsp = Int_yyvs + Int_yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) Int_yystacksize));

      if (Int_yyss + Int_yystacksize - 1 <= Int_yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", Int_yystate));

  goto Int_yybackup;

/*-----------.
| Int_yybackup.  |
`-----------*/
Int_yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  Int_yyn = Int_yypact[Int_yystate];
  if (Int_yyn == YYPACT_NINF)
    goto Int_yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (Int_yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      Int_yychar = YYLEX;
    }

  if (Int_yychar <= YYEOF)
    {
      Int_yychar = Int_yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      Int_yytoken = YYTRANSLATE (Int_yychar);
      YY_SYMBOL_PRINT ("Next token is", Int_yytoken, &Int_yylval, &Int_yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  Int_yyn += Int_yytoken;
  if (Int_yyn < 0 || YYLAST < Int_yyn || Int_yycheck[Int_yyn] != Int_yytoken)
    goto Int_yydefault;
  Int_yyn = Int_yytable[Int_yyn];
  if (Int_yyn <= 0)
    {
      if (Int_yyn == 0 || Int_yyn == YYTABLE_NINF)
	goto Int_yyerrlab;
      Int_yyn = -Int_yyn;
      goto Int_yyreduce;
    }

  if (Int_yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (Int_yyerrstatus)
    Int_yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", Int_yytoken, &Int_yylval, &Int_yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (Int_yychar != YYEOF)
    Int_yychar = YYEMPTY;

  Int_yystate = Int_yyn;
  *++Int_yyvsp = Int_yylval;

  goto Int_yynewstate;


/*-----------------------------------------------------------.
| Int_yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
Int_yydefault:
  Int_yyn = Int_yydefact[Int_yystate];
  if (Int_yyn == 0)
    goto Int_yyerrlab;
  goto Int_yyreduce;


/*-----------------------------.
| Int_yyreduce -- Do a reduction.  |
`-----------------------------*/
Int_yyreduce:
  /* Int_yyn is the number of a rule to reduce with.  */
  Int_yylen = Int_yyr2[Int_yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  Int_yyval = Int_yyvsp[1-Int_yylen];


  YY_REDUCE_PRINT (Int_yyn);
  switch (Int_yyn)
    {
        case 13:
#line 131 "bootparse.y"
    {
					do_start();
					boot_openrel(LexIDStr((Int_yyvsp[(2) - (2)].ival)));
					do_end();
				}
    break;

  case 14:
#line 140 "bootparse.y"
    {
					do_start();
					closerel(LexIDStr((Int_yyvsp[(2) - (2)].ival)));
					do_end();
				}
    break;

  case 15:
#line 146 "bootparse.y"
    {
					do_start();
					closerel(NULL);
					do_end();
				}
    break;

  case 16:
#line 155 "bootparse.y"
    {
					do_start();
					numattr = 0;
					elog(DEBUG4, "creating%s%s relation %s",
						 (Int_yyvsp[(2) - (6)].ival) ? " bootstrap" : "",
						 (Int_yyvsp[(3) - (6)].ival) ? " shared" : "",
						 LexIDStr((Int_yyvsp[(5) - (6)].ival)));
				}
    break;

  case 17:
#line 164 "bootparse.y"
    {
					do_end();
				}
    break;

  case 18:
#line 168 "bootparse.y"
    {
					TupleDesc tupdesc;

					do_start();

					tupdesc = CreateTupleDesc(numattr, !((Int_yyvsp[(4) - (10)].ival)), attrtypes);

					if ((Int_yyvsp[(2) - (10)].ival))
					{
						if (boot_reldesc)
						{
							elog(DEBUG4, "create bootstrap: warning, open relation exists, closing first");
							closerel(NULL);
						}

						boot_reldesc = heap_create(LexIDStr((Int_yyvsp[(5) - (10)].ival)),
												   PG_CATALOG_NAMESPACE,
												   tupdesc,
												   (Int_yyvsp[(3) - (10)].ival),
												   true,
												   true);
						elog(DEBUG4, "bootstrap relation created");
					}
					else
					{
						Oid id;

						id = heap_create_with_catalog(LexIDStr((Int_yyvsp[(5) - (10)].ival)),
													  PG_CATALOG_NAMESPACE,
													  tupdesc,
													  RELKIND_RELATION,
													  (Int_yyvsp[(3) - (10)].ival),
													  ONCOMMIT_NOOP,
													  true);
						elog(DEBUG4, "relation created with oid %u", id);
					}
					do_end();
				}
    break;

  case 19:
#line 210 "bootparse.y"
    {
					do_start();
					if ((Int_yyvsp[(2) - (2)].oidval))
						elog(DEBUG4, "inserting row with oid %u", (Int_yyvsp[(2) - (2)].oidval));
					else
						elog(DEBUG4, "inserting row");
					num_columns_read = 0;
				}
    break;

  case 20:
#line 219 "bootparse.y"
    {
					if (num_columns_read != numattr)
						elog(ERROR, "incorrect number of columns in row (expected %d, got %d)",
							 numattr, num_columns_read);
					if (boot_reldesc == (Relation) NULL)
					{
						elog(ERROR, "relation not open");
						err_out();
					}
					InsertOneTuple((Int_yyvsp[(2) - (6)].oidval));
					do_end();
				}
    break;

  case 21:
#line 235 "bootparse.y"
    {
					do_start();

					DefineIndex(makeRangeVar(NULL, LexIDStr((Int_yyvsp[(5) - (10)].ival))),
								LexIDStr((Int_yyvsp[(3) - (10)].ival)),
								LexIDStr((Int_yyvsp[(7) - (10)].ival)),
								(Int_yyvsp[(9) - (10)].list),
								false, false, false, NULL, NIL);
					do_end();
				}
    break;

  case 22:
#line 249 "bootparse.y"
    {
					do_start();

					DefineIndex(makeRangeVar(NULL, LexIDStr((Int_yyvsp[(6) - (11)].ival))),
								LexIDStr((Int_yyvsp[(4) - (11)].ival)),
								LexIDStr((Int_yyvsp[(8) - (11)].ival)),
								(Int_yyvsp[(10) - (11)].list),
								true, false, false, NULL, NIL);
					do_end();
				}
    break;

  case 23:
#line 262 "bootparse.y"
    { build_indices(); }
    break;

  case 24:
#line 267 "bootparse.y"
    { (Int_yyval.list) = lappend((Int_yyvsp[(1) - (3)].list), (Int_yyvsp[(3) - (3)].ielem)); }
    break;

  case 25:
#line 268 "bootparse.y"
    { (Int_yyval.list) = makeList1((Int_yyvsp[(1) - (1)].ielem)); }
    break;

  case 26:
#line 273 "bootparse.y"
    {
					IndexElem *n = makeNode(IndexElem);
					n->name = LexIDStr((Int_yyvsp[(1) - (2)].ival));
					n->expr = NULL;
					n->opclass = makeList1(makeString(LexIDStr((Int_yyvsp[(2) - (2)].ival))));
					(Int_yyval.ielem) = n;
				}
    break;

  case 27:
#line 283 "bootparse.y"
    { (Int_yyval.ival) = 1; }
    break;

  case 28:
#line 284 "bootparse.y"
    { (Int_yyval.ival) = 0; }
    break;

  case 29:
#line 288 "bootparse.y"
    { (Int_yyval.ival) = 1; }
    break;

  case 30:
#line 289 "bootparse.y"
    { (Int_yyval.ival) = 0; }
    break;

  case 31:
#line 293 "bootparse.y"
    { (Int_yyval.ival) = 1; }
    break;

  case 32:
#line 294 "bootparse.y"
    { (Int_yyval.ival) = 0; }
    break;

  case 35:
#line 304 "bootparse.y"
    {
				   if (++numattr > MAXATTR)
						elog(FATAL, "too many columns");
				   DefineAttr(LexIDStr((Int_yyvsp[(1) - (3)].ival)),LexIDStr((Int_yyvsp[(3) - (3)].ival)),numattr-1);
				}
    break;

  case 36:
#line 312 "bootparse.y"
    { (Int_yyval.oidval) = atol(LexIDStr((Int_yyvsp[(3) - (3)].ival)));	}
    break;

  case 37:
#line 313 "bootparse.y"
    { (Int_yyval.oidval) = (Oid) 0;	}
    break;

  case 41:
#line 324 "bootparse.y"
    { InsertOneValue(LexIDStr((Int_yyvsp[(1) - (1)].ival)), num_columns_read++); }
    break;

  case 42:
#line 326 "bootparse.y"
    { InsertOneValue(LexIDStr((Int_yyvsp[(1) - (1)].ival)), num_columns_read++); }
    break;

  case 43:
#line 328 "bootparse.y"
    { InsertOneNull(num_columns_read++); }
    break;

  case 44:
#line 332 "bootparse.y"
    { (Int_yyval.ival)=Int_yylval.ival; }
    break;

  case 45:
#line 336 "bootparse.y"
    { (Int_yyval.ival)=Int_yylval.ival; }
    break;


/* Line 1267 of yacc.c.  */
#line 1761 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", Int_yyr1[Int_yyn], &Int_yyval, &Int_yyloc);

  YYPOPSTACK (Int_yylen);
  Int_yylen = 0;
  YY_STACK_PRINT (Int_yyss, Int_yyssp);

  *++Int_yyvsp = Int_yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  Int_yyn = Int_yyr1[Int_yyn];

  Int_yystate = Int_yypgoto[Int_yyn - YYNTOKENS] + *Int_yyssp;
  if (0 <= Int_yystate && Int_yystate <= YYLAST && Int_yycheck[Int_yystate] == *Int_yyssp)
    Int_yystate = Int_yytable[Int_yystate];
  else
    Int_yystate = Int_yydefgoto[Int_yyn - YYNTOKENS];

  goto Int_yynewstate;


/*------------------------------------.
| Int_yyerrlab -- here on detecting error |
`------------------------------------*/
Int_yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!Int_yyerrstatus)
    {
      ++Int_yynerrs;
#if ! YYERROR_VERBOSE
      Int_yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T Int_yysize = Int_yysyntax_error (0, Int_yystate, Int_yychar);
	if (Int_yymsg_alloc < Int_yysize && Int_yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T Int_yyalloc = 2 * Int_yysize;
	    if (! (Int_yysize <= Int_yyalloc && Int_yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      Int_yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (Int_yymsg != Int_yymsgbuf)
	      YYSTACK_FREE (Int_yymsg);
	    Int_yymsg = (char *) YYSTACK_ALLOC (Int_yyalloc);
	    if (Int_yymsg)
	      Int_yymsg_alloc = Int_yyalloc;
	    else
	      {
		Int_yymsg = Int_yymsgbuf;
		Int_yymsg_alloc = sizeof Int_yymsgbuf;
	      }
	  }

	if (0 < Int_yysize && Int_yysize <= Int_yymsg_alloc)
	  {
	    (void) Int_yysyntax_error (Int_yymsg, Int_yystate, Int_yychar);
	    Int_yyerror (Int_yymsg);
	  }
	else
	  {
	    Int_yyerror (YY_("syntax error"));
	    if (Int_yysize != 0)
	      goto Int_yyexhaustedlab;
	  }
      }
#endif
    }



  if (Int_yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (Int_yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (Int_yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  Int_yydestruct ("Error: discarding",
		      Int_yytoken, &Int_yylval);
	  Int_yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto Int_yyerrlab1;


/*---------------------------------------------------.
| Int_yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
Int_yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label Int_yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto Int_yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (Int_yylen);
  Int_yylen = 0;
  YY_STACK_PRINT (Int_yyss, Int_yyssp);
  Int_yystate = *Int_yyssp;
  goto Int_yyerrlab1;


/*-------------------------------------------------------------.
| Int_yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
Int_yyerrlab1:
  Int_yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      Int_yyn = Int_yypact[Int_yystate];
      if (Int_yyn != YYPACT_NINF)
	{
	  Int_yyn += YYTERROR;
	  if (0 <= Int_yyn && Int_yyn <= YYLAST && Int_yycheck[Int_yyn] == YYTERROR)
	    {
	      Int_yyn = Int_yytable[Int_yyn];
	      if (0 < Int_yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (Int_yyssp == Int_yyss)
	YYABORT;


      Int_yydestruct ("Error: popping",
		  Int_yystos[Int_yystate], Int_yyvsp);
      YYPOPSTACK (1);
      Int_yystate = *Int_yyssp;
      YY_STACK_PRINT (Int_yyss, Int_yyssp);
    }

  if (Int_yyn == YYFINAL)
    YYACCEPT;

  *++Int_yyvsp = Int_yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", Int_yystos[Int_yyn], Int_yyvsp, Int_yylsp);

  Int_yystate = Int_yyn;
  goto Int_yynewstate;


/*-------------------------------------.
| Int_yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
Int_yyacceptlab:
  Int_yyresult = 0;
  goto Int_yyreturn;

/*-----------------------------------.
| Int_yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
Int_yyabortlab:
  Int_yyresult = 1;
  goto Int_yyreturn;

#ifndef Int_yyoverflow
/*-------------------------------------------------.
| Int_yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
Int_yyexhaustedlab:
  Int_yyerror (YY_("memory exhausted"));
  Int_yyresult = 2;
  /* Fall through.  */
#endif

Int_yyreturn:
  if (Int_yychar != YYEOF && Int_yychar != YYEMPTY)
     Int_yydestruct ("Cleanup: discarding lookahead",
		 Int_yytoken, &Int_yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (Int_yylen);
  YY_STACK_PRINT (Int_yyss, Int_yyssp);
  while (Int_yyssp != Int_yyss)
    {
      Int_yydestruct ("Cleanup: popping",
		  Int_yystos[*Int_yyssp], Int_yyvsp);
      YYPOPSTACK (1);
    }
#ifndef Int_yyoverflow
  if (Int_yyss != Int_yyssa)
    YYSTACK_FREE (Int_yyss);
#endif
#if YYERROR_VERBOSE
  if (Int_yymsg != Int_yymsgbuf)
    YYSTACK_FREE (Int_yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (Int_yyresult);
}


#line 338 "bootparse.y"


#include "bootscanner.c"

