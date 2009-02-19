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

/* All symbols defined below should begin with yy or YY, to avoid
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
   enum yytokentype {
     QSTRING = 258,
     ADDR = 259,
     BOOL = 260,
     NUMBER = 261,
     DECIMAL = 262,
     NUMPAIR = 263,
     MIP6ENTITY = 264,
     DEBUGLEVEL = 265,
     DEBUGLOGFILE = 266,
     DOROUTEOPTIMIZATIONCN = 267,
     DOROUTEOPTIMIZATIONMN = 268,
     HOMEADDRESS = 269,
     HOMEAGENTADDRESS = 270,
     INITIALBINDACKTIMEOUTFIRSTREG = 271,
     INITIALBINDACKTIMEOUTREREG = 272,
     LINKNAME = 273,
     HAMAXBINDINGLIFE = 274,
     MNMAXHABINDINGLIFE = 275,
     MNMAXCNBINDINGLIFE = 276,
     MAXMOBPFXADVINTERVAL = 277,
     MINMOBPFXADVINTERVAL = 278,
     MNHOMELINK = 279,
     HAHOMELINK = 280,
     NONVOLATILEBINDINGCACHE = 281,
     SENDMOBPFXSOLS = 282,
     SENDUNSOLMOBPFXADVS = 283,
     SENDMOBPFXADVS = 284,
     IPSECPOLICYSET = 285,
     IPSECPOLICY = 286,
     IPSECTYPE = 287,
     USEALTCOA = 288,
     USEESP = 289,
     USEAH = 290,
     USEIPCOMP = 291,
     BLOCK = 292,
     USEMNHAIPSEC = 293,
     KEYMNGMOBCAPABILITY = 294,
     HOMEREGBINDING = 295,
     MH = 296,
     MOBPFXDISC = 297,
     TUNNELHOMETESTING = 298,
     TUNNELMH = 299,
     TUNNELPAYLOAD = 300,
     USEMOVEMENTMODULE = 301,
     USEPOLICYMODULE = 302,
     MIP6CN = 303,
     MIP6MN = 304,
     MIP6HA = 305,
     INTERNAL = 306,
     MNROPOLICY = 307,
     ICMP = 308,
     ANY = 309,
     DOROUTEOPT = 310,
     DEFAULTBINDINGACLPOLICY = 311,
     BINDINGACLPOLICY = 312,
     MNADDRESS = 313,
     USECNBUACK = 314,
     INTERFACE = 315,
     IFNAME = 316,
     IFTYPE = 317,
     MNIFPREFERENCE = 318,
     MNUSEALLINTERFACES = 319,
     MNROUTERPROBES = 320,
     MNROUTERPROBETIMEOUT = 321,
     MNDISCARDHAPARAMPROB = 322,
     OPTIMISTICHANDOFF = 323,
     INV_TOKEN = 324
   };
#endif
/* Tokens.  */
#define QSTRING 258
#define ADDR 259
#define BOOL 260
#define NUMBER 261
#define DECIMAL 262
#define NUMPAIR 263
#define MIP6ENTITY 264
#define DEBUGLEVEL 265
#define DEBUGLOGFILE 266
#define DOROUTEOPTIMIZATIONCN 267
#define DOROUTEOPTIMIZATIONMN 268
#define HOMEADDRESS 269
#define HOMEAGENTADDRESS 270
#define INITIALBINDACKTIMEOUTFIRSTREG 271
#define INITIALBINDACKTIMEOUTREREG 272
#define LINKNAME 273
#define HAMAXBINDINGLIFE 274
#define MNMAXHABINDINGLIFE 275
#define MNMAXCNBINDINGLIFE 276
#define MAXMOBPFXADVINTERVAL 277
#define MINMOBPFXADVINTERVAL 278
#define MNHOMELINK 279
#define HAHOMELINK 280
#define NONVOLATILEBINDINGCACHE 281
#define SENDMOBPFXSOLS 282
#define SENDUNSOLMOBPFXADVS 283
#define SENDMOBPFXADVS 284
#define IPSECPOLICYSET 285
#define IPSECPOLICY 286
#define IPSECTYPE 287
#define USEALTCOA 288
#define USEESP 289
#define USEAH 290
#define USEIPCOMP 291
#define BLOCK 292
#define USEMNHAIPSEC 293
#define KEYMNGMOBCAPABILITY 294
#define HOMEREGBINDING 295
#define MH 296
#define MOBPFXDISC 297
#define TUNNELHOMETESTING 298
#define TUNNELMH 299
#define TUNNELPAYLOAD 300
#define USEMOVEMENTMODULE 301
#define USEPOLICYMODULE 302
#define MIP6CN 303
#define MIP6MN 304
#define MIP6HA 305
#define INTERNAL 306
#define MNROPOLICY 307
#define ICMP 308
#define ANY 309
#define DOROUTEOPT 310
#define DEFAULTBINDINGACLPOLICY 311
#define BINDINGACLPOLICY 312
#define MNADDRESS 313
#define USECNBUACK 314
#define INTERFACE 315
#define IFNAME 316
#define IFTYPE 317
#define MNIFPREFERENCE 318
#define MNUSEALLINTERFACES 319
#define MNROUTERPROBES 320
#define MNROUTERPROBETIMEOUT 321
#define MNDISCARDHAPARAMPROB 322
#define OPTIMISTICHANDOFF 323
#define INV_TOKEN 324




/* Copy the first part of user declarations.  */
#line 28 "gram.y"


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <pthread.h>
#include <netinet/in.h>
#include <net/if.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <netinet/ip6mh.h>
#include "mipv6.h"
#include "ha.h"
#include "mn.h"
#include "conf.h"
#include "policy.h"
#include "xfrm.h"
#include "prefix.h"
#include "util.h"
#include "ipsec.h"
#include "rtnl.h"

struct net_iface ni = {
	.mip6_if_entity = MIP6_ENTITY_NO,
	.mn_if_preference = POL_MN_IF_DEF_PREFERENCE,
};
	
struct home_addr_info hai = {
	.ro_policies = LIST_HEAD_INIT(hai.ro_policies)
};

struct policy_bind_acl_entry *bae = NULL;

struct ipsec_policy_set {
	struct in6_addr ha;
	struct list_head hoa_list;
};

struct ipsec_policy_set ipsec_ps = {
	.hoa_list = LIST_HEAD_INIT(ipsec_ps.hoa_list)
};

extern int lineno;
extern char *yytext;

static void yyerror(char *s) {
	fprintf(stderr, "Error in configuration file %s\n", conf.config_file);
	fprintf(stderr, "line %d: %s at '%s'\n", lineno, s, yytext);
}

static void uerror(const char *fmt, ...) {
	char s[1024];
	va_list args;

	fprintf(stderr, "Error in configuration file %s\n", conf.config_file);
	va_start(args, fmt);
	vsprintf(s, fmt, args);
	fprintf(stderr, "line %d: %s\n", lineno, s);
	va_end(args);
}



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
#line 92 "gram.y"
{
	char *string;
	struct in6_addr addr;
	char bool;
	unsigned int num;
	unsigned int numpair[2];
	double dec;
}
/* Line 187 of yacc.c.  */
#line 307 "gram.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 320 "gram.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
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
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,    72,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    16,    20,    24,    27,
      31,    35,    39,    43,    47,    51,    55,    59,    63,    67,
      71,    75,    78,    82,    86,    90,    94,    98,   102,   106,
     111,   115,   119,   123,   127,   131,   133,   135,   137,   140,
     144,   146,   148,   151,   155,   159,   164,   166,   169,   173,
     179,   183,   187,   191,   195,   197,   200,   204,   208,   210,
     213,   219,   222,   224,   226,   228,   230,   232,   234,   236,
     238,   239,   241,   244,   248,   250,   252,   254,   255,   257,
     260,   261,   263,   266,   267,   269,   271,   273,   275,   277,
     279,   281,   284
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,    76,    -1,    75,    76,    -1,     9,    77,
      70,    -1,    10,     6,    70,    -1,    11,     3,    70,    -1,
      26,     5,    70,    -1,    60,    78,    -1,    27,     5,    70,
      -1,    28,     5,    70,    -1,    29,     5,    70,    -1,    22,
       6,    70,    -1,    23,     6,    70,    -1,    12,     5,    70,
      -1,    13,     5,    70,    -1,    19,     6,    70,    -1,    20,
       6,    70,    -1,    21,     6,    70,    -1,    16,     7,    70,
      -1,    17,     7,    70,    -1,    24,    82,    -1,    38,     5,
      70,    -1,    39,     5,    70,    -1,    46,   101,    70,    -1,
      47,   102,    70,    -1,    56,   103,    70,    -1,    57,   104,
      70,    -1,    59,     5,    70,    -1,    30,    71,    85,    72,
      -1,    64,     5,    70,    -1,    65,     6,    70,    -1,    66,
       7,    70,    -1,    67,     5,    70,    -1,    68,     5,    70,
      -1,    48,    -1,    49,    -1,    50,    -1,     3,    79,    -1,
      71,    80,    72,    -1,    70,    -1,    81,    -1,    80,    81,
      -1,    62,    77,    70,    -1,    63,     6,    70,    -1,     3,
      71,    83,    72,    -1,    84,    -1,    83,    84,    -1,    15,
       4,    70,    -1,    14,     4,    73,   105,    70,    -1,    33,
       5,    70,    -1,    52,    98,    70,    -1,    86,    87,    90,
      -1,    15,     4,    70,    -1,    88,    -1,    87,    88,    -1,
      14,    89,    70,    -1,     4,    73,   105,    -1,    91,    -1,
      90,    91,    -1,    92,    94,    96,    97,    70,    -1,    31,
      93,    -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,
      44,    -1,    45,    -1,    53,    -1,    54,    -1,    -1,    95,
      -1,    95,    95,    -1,    95,    95,    95,    -1,    34,    -1,
      35,    -1,    36,    -1,    -1,     6,    -1,     6,     6,    -1,
      -1,     5,    -1,    99,   100,    -1,    -1,     4,    -1,     5,
      -1,    51,    -1,     3,    -1,     3,    -1,     5,    -1,     6,
      -1,     4,   103,    -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   186,   186,   187,   190,   194,   198,   202,   206,   207,
     211,   215,   219,   223,   227,   231,   235,   244,   253,   262,
     266,   270,   271,   275,   279,   280,   281,   285,   289,   293,
     294,   298,   302,   307,   311,   317,   318,   319,   322,   348,
     349,   352,   353,   356,   360,   366,   410,   411,   414,   418,
     423,   427,   430,   453,   459,   460,   463,   466,   482,   483,
     486,   554,   557,   558,   559,   560,   561,   562,   563,   564,
     568,   572,   573,   574,   577,   578,   579,   582,   583,   584,
     587,   588,   591,   606,   607,   610,   613,   617,   623,   632,
     639,   642,   657
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QSTRING", "ADDR", "BOOL", "NUMBER",
  "DECIMAL", "NUMPAIR", "MIP6ENTITY", "DEBUGLEVEL", "DEBUGLOGFILE",
  "DOROUTEOPTIMIZATIONCN", "DOROUTEOPTIMIZATIONMN", "HOMEADDRESS",
  "HOMEAGENTADDRESS", "INITIALBINDACKTIMEOUTFIRSTREG",
  "INITIALBINDACKTIMEOUTREREG", "LINKNAME", "HAMAXBINDINGLIFE",
  "MNMAXHABINDINGLIFE", "MNMAXCNBINDINGLIFE", "MAXMOBPFXADVINTERVAL",
  "MINMOBPFXADVINTERVAL", "MNHOMELINK", "HAHOMELINK",
  "NONVOLATILEBINDINGCACHE", "SENDMOBPFXSOLS", "SENDUNSOLMOBPFXADVS",
  "SENDMOBPFXADVS", "IPSECPOLICYSET", "IPSECPOLICY", "IPSECTYPE",
  "USEALTCOA", "USEESP", "USEAH", "USEIPCOMP", "BLOCK", "USEMNHAIPSEC",
  "KEYMNGMOBCAPABILITY", "HOMEREGBINDING", "MH", "MOBPFXDISC",
  "TUNNELHOMETESTING", "TUNNELMH", "TUNNELPAYLOAD", "USEMOVEMENTMODULE",
  "USEPOLICYMODULE", "MIP6CN", "MIP6MN", "MIP6HA", "INTERNAL",
  "MNROPOLICY", "ICMP", "ANY", "DOROUTEOPT", "DEFAULTBINDINGACLPOLICY",
  "BINDINGACLPOLICY", "MNADDRESS", "USECNBUACK", "INTERFACE", "IFNAME",
  "IFTYPE", "MNIFPREFERENCE", "MNUSEALLINTERFACES", "MNROUTERPROBES",
  "MNROUTERPROBETIMEOUT", "MNDISCARDHAPARAMPROB", "OPTIMISTICHANDOFF",
  "INV_TOKEN", "';'", "'{'", "'}'", "'/'", "$accept", "grammar", "topdef",
  "mip6entity", "ifacedef", "ifacesub", "ifaceopts", "ifaceopt", "linksub",
  "linkdefs", "linkdef", "ipsecpolicyset", "ipsechaaddrdef",
  "ipsecmnaddrdefs", "ipsecmnaddrdef", "ipsecmnaddr", "ipsecpolicydefs",
  "ipsecpolicydef", "ipsectype", "ipsectypeval", "ipsecprotos",
  "ipsecproto", "ipsecreqid", "xfrmaction", "mnropolicy", "mnropolicyaddr",
  "dorouteopt", "movemodule", "policymodule", "bindaclpolval",
  "bindaclpolicy", "prefixlen", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      59,   123,   125,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    78,    79,
      79,    80,    80,    81,    81,    82,    83,    83,    84,    84,
      84,    84,    85,    86,    87,    87,    88,    89,    90,    90,
      91,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    98,    99,    99,   100,   101,   101,   102,   103,
     103,   104,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     3,     1,     1,     1,     2,     3,
       1,     1,     2,     3,     3,     4,     1,     2,     3,     5,
       3,     3,     3,     3,     1,     2,     3,     3,     1,     2,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     3,     1,     1,     1,     0,     1,     2,
       0,     1,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,    35,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,    87,    86,
       0,    88,     0,    89,    90,     0,     0,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     1,     3,     4,     5,
       6,    14,    15,    19,    20,    16,    17,    18,    12,    13,
       0,     7,     9,    10,    11,     0,     0,     0,    22,    23,
      24,    25,    26,    91,    27,    28,    40,     0,    38,    30,
      31,    32,    33,    34,     0,     0,     0,    83,     0,    46,
       0,    29,     0,     0,    54,     0,     0,     0,    41,     0,
       0,     0,    84,     0,     0,    45,    47,    53,     0,     0,
       0,    55,    52,    58,    70,     0,     0,    39,    42,     0,
      48,    50,    51,    85,    82,     0,    56,    62,    63,    64,
      65,    66,    67,    68,    69,    61,    59,    74,    75,    76,
      77,    71,    43,    44,    92,     0,    57,    78,    80,    72,
      49,    79,    81,     0,    73,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    37,    70,   108,   127,   128,    50,   118,
     119,    96,    97,   123,   124,   139,   142,   143,   144,   165,
     170,   171,   178,   183,   133,   134,   154,    60,    62,    65,
      67,   175
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -139
static const yytype_int16 yypact[] =
{
      60,     2,    12,     5,    26,    35,    38,    41,    47,    48,
      52,    69,    72,    82,    86,    87,    88,    90,    25,    92,
      95,    -2,    98,    -3,    99,    97,   101,   100,   108,   111,
     110,   118,     0,  -139,  -139,  -139,  -139,    59,    61,    62,
      63,    64,    65,    66,    67,    70,    71,    73,    74,    75,
    -139,    77,    78,    79,    80,   115,    81,    83,  -139,  -139,
      84,  -139,    85,  -139,  -139,    89,    -3,    91,    93,   -36,
    -139,    94,    96,   102,   103,   104,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
      -8,  -139,  -139,  -139,  -139,   134,   105,   125,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,   -20,  -139,  -139,
    -139,  -139,  -139,  -139,   138,   141,   147,   152,    22,  -139,
     106,  -139,   153,     1,  -139,     2,   154,   -58,  -139,   107,
     109,   112,  -139,   113,   157,  -139,  -139,  -139,   114,   116,
      68,  -139,   127,  -139,    27,   119,   120,  -139,  -139,   159,
    -139,  -139,  -139,  -139,  -139,   159,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
     161,    27,  -139,  -139,  -139,   121,  -139,   162,   164,    27,
    -139,  -139,  -139,   122,  -139,  -139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,   139,    45,  -139,  -139,  -139,    51,  -139,  -139,
      57,  -139,  -139,  -139,    58,  -139,  -139,    42,  -139,  -139,
    -139,  -138,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   128,
    -139,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      76,    58,    63,    64,   125,   126,   114,   115,    39,     1,
       2,     3,     4,     5,   147,   122,     6,     7,    38,     8,
       9,    10,    11,    12,    13,   116,    14,    15,    16,    17,
      18,    40,   140,   179,   106,   107,   114,   115,    19,    20,
      41,   184,   125,   126,   117,    42,    21,    22,    43,    59,
      34,    35,    36,    44,    45,   116,    23,    24,    46,    25,
      26,   167,   168,   169,    27,    28,    29,    30,    31,     1,
       2,     3,     4,     5,   117,    47,     6,     7,    48,     8,
       9,    10,    11,    12,    13,    49,    14,    15,    16,    17,
      18,    51,    52,    53,   135,    54,    55,    56,    19,    20,
      57,    61,    68,    66,    69,    71,    21,    22,   157,   158,
     159,   160,   161,   162,    72,    74,    23,    24,    73,    25,
      26,   163,   164,    75,    27,    28,    29,    30,    31,    78,
      95,    79,    80,    81,    82,    83,    84,    85,   120,   122,
      86,    87,   129,    88,    89,   130,    90,    91,    92,    93,
      94,    98,   131,    99,   100,   101,   132,   138,   140,   102,
     146,   104,   153,   105,   109,   174,   110,   177,   181,   182,
     145,    77,   111,   112,   113,   136,   137,   121,   148,   150,
     149,   141,   151,   152,   166,   176,   156,   155,     0,   172,
     173,   180,   185,     0,   103
};

static const yytype_int16 yycheck[] =
{
       0,     3,     5,     6,    62,    63,    14,    15,     3,     9,
      10,    11,    12,    13,    72,    14,    16,    17,     6,    19,
      20,    21,    22,    23,    24,    33,    26,    27,    28,    29,
      30,     5,    31,   171,    70,    71,    14,    15,    38,    39,
       5,   179,    62,    63,    52,     7,    46,    47,     7,    51,
      48,    49,    50,     6,     6,    33,    56,    57,     6,    59,
      60,    34,    35,    36,    64,    65,    66,    67,    68,     9,
      10,    11,    12,    13,    52,     6,    16,    17,     6,    19,
      20,    21,    22,    23,    24,     3,    26,    27,    28,    29,
      30,     5,     5,     5,    72,     5,    71,     5,    38,    39,
       5,     3,     5,     4,     3,     5,    46,    47,    40,    41,
      42,    43,    44,    45,     6,     5,    56,    57,     7,    59,
      60,    53,    54,     5,    64,    65,    66,    67,    68,    70,
      15,    70,    70,    70,    70,    70,    70,    70,     4,    14,
      70,    70,     4,    70,    70,     4,    71,    70,    70,    70,
      70,    70,     5,    70,    70,    70,     4,     4,    31,    70,
       6,    70,     5,    70,    70,     6,    70,     6,     6,     5,
     125,    32,    70,    70,    70,   118,    70,    72,   127,    70,
      73,   123,    70,    70,   142,   155,    70,    73,    -1,    70,
      70,    70,    70,    -1,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    16,    17,    19,    20,
      21,    22,    23,    24,    26,    27,    28,    29,    30,    38,
      39,    46,    47,    56,    57,    59,    60,    64,    65,    66,
      67,    68,    75,    76,    48,    49,    50,    77,     6,     3,
       5,     5,     7,     7,     6,     6,     6,     6,     6,     3,
      82,     5,     5,     5,     5,    71,     5,     5,     3,    51,
     101,     3,   102,     5,     6,   103,     4,   104,     5,     3,
      78,     5,     6,     7,     5,     5,     0,    76,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    70,    70,    70,    70,    15,    85,    86,    70,    70,
      70,    70,    70,   103,    70,    70,    70,    71,    79,    70,
      70,    70,    70,    70,    14,    15,    33,    52,    83,    84,
       4,    72,    14,    87,    88,    62,    63,    80,    81,     4,
       4,     5,     4,    98,    99,    72,    84,    70,     4,    89,
      31,    88,    90,    91,    92,    77,     6,    72,    81,    73,
      70,    70,    70,     5,   100,    73,    70,    40,    41,    42,
      43,    44,    45,    53,    54,    93,    91,    34,    35,    36,
      94,    95,    70,    70,     6,   105,   105,     6,    96,    95,
      70,     6,     5,    97,    95,    70
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
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


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 191 "gram.y"
    {
			conf.mip6_entity = (yyvsp[(2) - (3)].num);
		}
    break;

  case 5:
#line 195 "gram.y"
    {
			conf.debug_level = (yyvsp[(2) - (3)].num);
		}
    break;

  case 6:
#line 199 "gram.y"
    {
			conf.debug_log_file = (yyvsp[(2) - (3)].string);
		}
    break;

  case 7:
#line 203 "gram.y"
    {
			conf.NonVolatileBindingCache = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 9:
#line 208 "gram.y"
    {
			conf.SendMobPfxSols = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 10:
#line 212 "gram.y"
    {
			conf.SendUnsolMobPfxAdvs = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 11:
#line 216 "gram.y"
    {
			conf.SendMobPfxAdvs = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 12:
#line 220 "gram.y"
    {
			conf.MaxMobPfxAdvInterval = (yyvsp[(2) - (3)].num);
		}
    break;

  case 13:
#line 224 "gram.y"
    {
			conf.MinMobPfxAdvInterval = (yyvsp[(2) - (3)].num);
		}
    break;

  case 14:
#line 228 "gram.y"
    {
			conf.DoRouteOptimizationCN = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 15:
#line 232 "gram.y"
    {
			conf.DoRouteOptimizationMN = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 16:
#line 236 "gram.y"
    {
			if ((yyvsp[(2) - (3)].num) > MAX_BINDING_LIFETIME) {
				uerror("max allowed binding lifetime is %d", 
				       MAX_BINDING_LIFETIME);
				return -1;
			}
			conf.HaMaxBindingLife = (yyvsp[(2) - (3)].num);
		}
    break;

  case 17:
#line 245 "gram.y"
    {
			if ((yyvsp[(2) - (3)].num) > MAX_BINDING_LIFETIME) {
				uerror("max allowed binding lifetime is %d", 
				       MAX_BINDING_LIFETIME);
				return -1;
			}
			conf.MnMaxHaBindingLife = (yyvsp[(2) - (3)].num);
		}
    break;

  case 18:
#line 254 "gram.y"
    {
			if ((yyvsp[(2) - (3)].num) > MAX_RR_BINDING_LIFETIME) {
				uerror("max allowed binding lifetime is %d", 
				       MAX_RR_BINDING_LIFETIME);
				return -1;
			}
			conf.MnMaxCnBindingLife = (yyvsp[(2) - (3)].num);
		}
    break;

  case 19:
#line 263 "gram.y"
    {
			tssetdsec(conf.InitialBindackTimeoutFirstReg_ts, (yyvsp[(2) - (3)].dec));
		}
    break;

  case 20:
#line 267 "gram.y"
    {
			tssetdsec(conf.InitialBindackTimeoutReReg_ts, (yyvsp[(2) - (3)].dec));
		}
    break;

  case 22:
#line 272 "gram.y"
    {
			conf.UseMnHaIPsec = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 23:
#line 276 "gram.y"
    {
			conf.KeyMngMobCapability = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 26:
#line 282 "gram.y"
    {
			conf.DefaultBindingAclPolicy = (yyvsp[(2) - (3)].num);
		}
    break;

  case 27:
#line 286 "gram.y"
    {
			bae = NULL;
		}
    break;

  case 28:
#line 290 "gram.y"
    {
			conf.CnBuAck = (yyvsp[(2) - (3)].bool) ? IP6_MH_BU_ACK : 0;
		}
    break;

  case 30:
#line 295 "gram.y"
    {
			conf.MnUseAllInterfaces = (yyvsp[(2) - (3)].bool) ? POL_MN_IF_DEF_PREFERENCE : 0;
		}
    break;

  case 31:
#line 299 "gram.y"
    {
			conf.MnRouterProbes = (yyvsp[(2) - (3)].num);
		}
    break;

  case 32:
#line 303 "gram.y"
    {
			if ((yyvsp[(2) - (3)].dec) > 0)
				tssetdsec(conf.MnRouterProbeTimeout_ts, (yyvsp[(2) - (3)].dec));
		}
    break;

  case 33:
#line 308 "gram.y"
    {
			conf.MnDiscardHaParamProb = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 34:
#line 312 "gram.y"
    {
			conf.OptimisticHandoff = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 35:
#line 317 "gram.y"
    { (yyval.num) = MIP6_ENTITY_CN;	}
    break;

  case 36:
#line 318 "gram.y"
    { (yyval.num) = MIP6_ENTITY_MN; }
    break;

  case 37:
#line 319 "gram.y"
    { (yyval.num) = MIP6_ENTITY_HA; }
    break;

  case 38:
#line 323 "gram.y"
    {
			struct net_iface *nni;
			strncpy(ni.name, (yyvsp[(1) - (2)].string), IF_NAMESIZE - 1);
			ni.ifindex = if_nametoindex((yyvsp[(1) - (2)].string));
			free((yyvsp[(1) - (2)].string));
			if (ni.ifindex <= 0) {
				uerror("invalid interface");
				return -1;
			}
			nni = malloc(sizeof(struct net_iface));
			if (nni == NULL) {
				uerror("out of memory");
				return -1;
			}
			memcpy(nni, &ni, sizeof(struct net_iface));
			list_add_tail(&nni->list, &conf.net_ifaces);
			if (is_if_ha(nni))
				homeagent_if_init(nni->ifindex);

			memset(&ni, 0, sizeof(struct net_iface));
			ni.mip6_if_entity = MIP6_ENTITY_NO;
			ni.mn_if_preference = POL_MN_IF_DEF_PREFERENCE;
		}
    break;

  case 43:
#line 357 "gram.y"
    {
			ni.mip6_if_entity = (yyvsp[(2) - (3)].num);
		}
    break;

  case 44:
#line 361 "gram.y"
    {
			ni.mn_if_preference = (yyvsp[(2) - (3)].num);
		}
    break;

  case 45:
#line 367 "gram.y"
    {
			struct home_addr_info *nhai;
			if (IN6_IS_ADDR_UNSPECIFIED(&hai.hoa.addr)) {
				uerror("No home addresses defined"
					"for homelink %d", hai.if_home);
				return -1;
			}
			strncpy(hai.name, (yyvsp[(1) - (4)].string), IF_NAMESIZE - 1);
			hai.if_home = if_nametoindex((yyvsp[(1) - (4)].string));
			free((yyvsp[(1) - (4)].string));
			if (hai.if_home <= 0) {
				uerror("invalid interface");
				return -1;
			}
			nhai = malloc(sizeof(struct home_addr_info));
			if (nhai == NULL) {
				uerror("out of memory");
				return -1;
			}
			if (hai.plen == 64) {
				struct in6_addr lladdr;
				ipv6_addr_llocal(&hai.hoa.addr, &lladdr);
				if (!addr_do(&lladdr, 64, 
					     hai.if_home, NULL, NULL))
					hai.lladdr_comp = IP6_MH_BU_LLOCAL;
			}
			if (IN6_IS_ADDR_UNSPECIFIED(&hai.home_prefix)) {
				ipv6_addr_prefix(&hai.home_prefix, 
						 &hai.hoa.addr, hai.plen);
				hai.home_plen = hai.plen;
			}
			memcpy(nhai, &hai, sizeof(struct home_addr_info));
			INIT_LIST_HEAD(&nhai->ro_policies);
			INIT_LIST_HEAD(&nhai->ha_list.home_agents);
			nhai->ha_list.dhaad_id = -1;
			list_splice(&hai.ro_policies, &nhai->ro_policies);
			list_add_tail(&nhai->list, &conf.home_addrs);

			memset(&hai, 0, sizeof(struct home_addr_info));
			INIT_LIST_HEAD(&hai.ro_policies);
		}
    break;

  case 48:
#line 415 "gram.y"
    {
			memcpy(&hai.ha_addr, &(yyvsp[(2) - (3)].addr), sizeof(struct in6_addr));
		}
    break;

  case 49:
#line 419 "gram.y"
    {
			hai.hoa.addr = (yyvsp[(2) - (5)].addr);
			hai.plen = (yyvsp[(4) - (5)].num);
		}
    break;

  case 50:
#line 424 "gram.y"
    {
		        hai.altcoa = (yyvsp[(2) - (3)].bool);
		}
    break;

  case 52:
#line 431 "gram.y"
    {
			if (!list_empty(&ipsec_ps.hoa_list)) {
				struct list_head *lp, *tmp;

				/* free each hoa entry */
				list_for_each_safe(lp, tmp,
						   &ipsec_ps.hoa_list) {
					struct home_addr_info *hoa;

					list_del(lp);
					hoa = list_entry(lp,
							 struct home_addr_info,
							 list);

					free(hoa);
				}
			}
			memset(&ipsec_ps, 0, sizeof(ipsec_ps));
			INIT_LIST_HEAD(&ipsec_ps.hoa_list);
		}
    break;

  case 53:
#line 454 "gram.y"
    {
			ipsec_ps.ha = (yyvsp[(2) - (3)].addr);
		}
    break;

  case 57:
#line 467 "gram.y"
    {
			struct home_addr_info *hai;

			hai = malloc(sizeof(struct home_addr_info));
			if (hai == NULL) {
				uerror("out of memory");
				return -1;
			}
			memset(hai, 0, sizeof(struct home_addr_info)); 
			hai->hoa.addr = (yyvsp[(1) - (3)].addr);
			hai->plen = (yyvsp[(3) - (3)].num);
			list_add_tail(&hai->list, &ipsec_ps.hoa_list);
		}
    break;

  case 60:
#line 487 "gram.y"
    {
			struct list_head *lp;

			if (IN6_IS_ADDR_UNSPECIFIED(&ipsec_ps.ha)) {
				uerror("HomeAgentAddress missing for IPsecPolicy");
				return -1;
			}
			if (list_empty(&ipsec_ps.hoa_list)) {
				uerror("HomeAddress missing for IPsecPolicy");
				return -1;
			}

			list_for_each(lp, &ipsec_ps.hoa_list) {
				struct home_addr_info *hai;
				struct ipsec_policy_entry *e;

				hai = list_entry(lp, struct home_addr_info,
						 list);

				e = malloc(sizeof(*e));
				if (e == NULL) {
					uerror("out of memory");
					return -1;
				}
				memset(e, 0, sizeof(*e));
				e->ha_addr = ipsec_ps.ha;
				e->mn_addr = hai->hoa.addr;
				e->type = (yyvsp[(1) - (5)].num);
#ifndef XFRM_MSG_MIGRATE
				switch (e->type) {
				case IPSEC_POLICY_TYPE_TUNNELHOMETESTING:
				case IPSEC_POLICY_TYPE_TUNNELMH:
				case IPSEC_POLICY_TYPE_TUNNELPAYLOAD:
					uerror("cannot use IPsec tunnel because it is not built with MIGRATE");
					return -1;
				default:
					break;
				}
#endif
#ifndef MULTIPROTO_MIGRATE
				if ((yyvsp[(2) - (5)].num) != IPSEC_PROTO_ESP) {
					uerror("only UseESP is allowed");
					return -1;
				}
#endif
				e->ipsec_protos = (yyvsp[(2) - (5)].num);
				e->reqid_toha = (yyvsp[(3) - (5)].numpair)[0];
				e->reqid_tomn = (yyvsp[(3) - (5)].numpair)[1];
				e->action = (yyvsp[(4) - (5)].bool);

				if (ipsec_policy_entry_check(&e->ha_addr,
							     &e->mn_addr,
							     e->type)) {
					uerror("overlapping IPsec policies "
					       "found for "
					       "HA %x:%x:%x:%x:%x:%x:%x:%x "
					       "MN %x:%x:%x:%x:%x:%x:%x:%x "
					       "pair\n",
					       NIP6ADDR(&e->ha_addr),
					       NIP6ADDR(&e->mn_addr));
					return -1;
				}
				list_add_tail(&e->list, &conf.ipsec_policies);
			}
		}
    break;

  case 61:
#line 554 "gram.y"
    { (yyval.num) = (yyvsp[(2) - (2)].num); }
    break;

  case 62:
#line 557 "gram.y"
    { (yyval.num) = IPSEC_POLICY_TYPE_HOMEREGBINDING; }
    break;

  case 63:
#line 558 "gram.y"
    { (yyval.num) = IPSEC_POLICY_TYPE_MH; }
    break;

  case 64:
#line 559 "gram.y"
    { (yyval.num) = IPSEC_POLICY_TYPE_MOBPFXDISC; }
    break;

  case 65:
#line 560 "gram.y"
    { (yyval.num) = IPSEC_POLICY_TYPE_TUNNELHOMETESTING; }
    break;

  case 66:
#line 561 "gram.y"
    { (yyval.num) = IPSEC_POLICY_TYPE_TUNNELMH; }
    break;

  case 67:
#line 562 "gram.y"
    { (yyval.num) = IPSEC_POLICY_TYPE_TUNNELPAYLOAD; }
    break;

  case 68:
#line 563 "gram.y"
    { (yyval.num) = IPSEC_POLICY_TYPE_ICMP; }
    break;

  case 69:
#line 564 "gram.y"
    { (yyval.num) = IPSEC_POLICY_TYPE_ANY; }
    break;

  case 70:
#line 568 "gram.y"
    {
			uerror("IPsecPolicy must set at least one protocol");
			return -1;
		}
    break;

  case 71:
#line 572 "gram.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); }
    break;

  case 72:
#line 573 "gram.y"
    { (yyval.num) = (yyvsp[(1) - (2)].num) | (yyvsp[(2) - (2)].num); }
    break;

  case 73:
#line 574 "gram.y"
    { (yyval.num) = (yyvsp[(1) - (3)].num) | (yyvsp[(2) - (3)].num) | (yyvsp[(3) - (3)].num); }
    break;

  case 74:
#line 577 "gram.y"
    { (yyval.num) = IPSEC_PROTO_ESP; }
    break;

  case 75:
#line 578 "gram.y"
    { (yyval.num) = IPSEC_PROTO_AH; }
    break;

  case 76:
#line 579 "gram.y"
    { (yyval.num) = IPSEC_PROTO_IPCOMP; }
    break;

  case 77:
#line 582 "gram.y"
    { (yyval.numpair)[0] = (yyval.numpair)[1] = 0; }
    break;

  case 78:
#line 583 "gram.y"
    { (yyval.numpair)[0] = (yyval.numpair)[1] = (yyvsp[(1) - (1)].num); }
    break;

  case 79:
#line 584 "gram.y"
    { (yyval.numpair)[0] = (yyvsp[(1) - (2)].num); (yyval.numpair)[1] = (yyvsp[(2) - (2)].num); }
    break;

  case 80:
#line 587 "gram.y"
    { (yyval.bool) = XFRM_POLICY_ALLOW; }
    break;

  case 81:
#line 588 "gram.y"
    { (yyval.bool) = (yyvsp[(1) - (1)].bool) ? XFRM_POLICY_ALLOW : XFRM_POLICY_BLOCK; }
    break;

  case 82:
#line 592 "gram.y"
    { 
			struct xfrm_ro_pol *rp;
			rp = malloc(sizeof(struct xfrm_ro_pol));
			if (rp == NULL) {
				uerror("out of memory");
				return -1;
			}
			memset(rp, 0, sizeof(struct xfrm_ro_pol)); 
			rp->cn_addr = (yyvsp[(1) - (2)].addr);
			rp->do_ro = (yyvsp[(2) - (2)].bool);
			list_add_tail(&rp->list, &hai.ro_policies);
		}
    break;

  case 83:
#line 606 "gram.y"
    { (yyval.addr) = in6addr_any; }
    break;

  case 84:
#line 607 "gram.y"
    { (yyval.addr) = (yyvsp[(1) - (1)].addr); }
    break;

  case 85:
#line 610 "gram.y"
    { (yyval.bool) = (yyvsp[(1) - (1)].bool); }
    break;

  case 86:
#line 614 "gram.y"
    {
			conf.MoveModulePath = NULL;
		}
    break;

  case 87:
#line 618 "gram.y"
    {
			conf.MoveModulePath = NULL;
		}
    break;

  case 88:
#line 624 "gram.y"
    {
			if (pmgr_init((yyvsp[(1) - (1)].string), &conf.pmgr) < 0) {
				uerror("error loading shared object %s", (yyvsp[(1) - (1)].string));
				return -1;
			}
		}
    break;

  case 89:
#line 633 "gram.y"
    { 
			if ((yyvsp[(1) - (1)].bool))
				(yyval.num) = IP6_MH_BAS_ACCEPTED;
			else
				(yyval.num) = IP6_MH_BAS_PROHIBIT;
		}
    break;

  case 90:
#line 639 "gram.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); }
    break;

  case 91:
#line 643 "gram.y"
    {
			bae = malloc(sizeof(struct policy_bind_acl_entry));
			if (bae == NULL) {
				uerror("out of memory");
				return -1;
			}
			memset(bae, 0, sizeof(struct policy_bind_acl_entry)); 
			bae->hoa = (yyvsp[(1) - (2)].addr);
			bae->plen = 128;
			bae->bind_policy = (yyvsp[(2) - (2)].num);
			list_add_tail(&bae->list, &conf.bind_acl);
		}
    break;

  case 92:
#line 658 "gram.y"
    {
			if ((yyvsp[(1) - (1)].num) > 128) {
				uerror("invalid prefix length %d", (yyvsp[(1) - (1)].num));
				return -1;
			}
			(yyval.num) = (yyvsp[(1) - (1)].num);
		}
    break;


/* Line 1267 of yacc.c.  */
#line 2341 "gram.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 667 "gram.y"


