
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDENT	258
#define	TNUMBER	259
#define	TCONST	260
#define	TELSE	261
#define	TIF	262
#define	TINT	263
#define	TRETURN	264
#define	TVOID	265
#define	TWHILE	266
#define	TADDASSIGN	267
#define	TSUBASSIGN	268
#define	TMULASSIGN	269
#define	TDIVASSIGN	270
#define	TMODASSIGN	271
#define	TOR	272
#define	TAND	273
#define	TEQUAL	274
#define	TNOTEQU	275
#define	TGREAT	276
#define	TLESS	277
#define	TGREATE	278
#define	TLESSE	279
#define	TINC	280
#define	TDEC	281
#define	TPLUS	282
#define	TMINUS	283
#define	TMULTIPLY	284
#define	TDIVIDE	285
#define	TMOD	286
#define	TNOT	287
#define	TASSIGN	288
#define	TLPAREN	289
#define	TRPAREN	290
#define	TCOMMA	291
#define	TSEMI	292
#define	TLBRACKET	293
#define	TRBRACKET	294
#define	TLBRACE	295
#define	TRBRACE	296
#define	LOWER_THAN_ELSE	297

#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "glob.h"

extern yylex();
extern yyerror(s);
extern PrintError(err);

extern HTpointer ScopeTrace;

/*yacc source for Mini C*/

void a();
void b();

func_in = 0;


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		167
#define	YYFLAG		-32768
#define	YYNTBASE	43

#define YYTRANSLATE(x) ((unsigned)(x) <= 297 ? yytranslate[x] : 88)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    16,    19,    22,    25,
    28,    31,    35,    37,    39,    42,    44,    46,    48,    50,
    52,    54,    58,    60,    61,    63,    67,    70,    75,    80,
    82,    83,    85,    88,    92,    96,    98,   102,   104,   108,
   110,   115,   120,   122,   123,   125,   126,   128,   131,   133,
   135,   137,   139,   141,   144,   147,   149,   150,   156,   164,
   170,   174,   176,   178,   182,   186,   190,   194,   198,   202,
   204,   208,   210,   214,   216,   220,   224,   227,   231,   235,
   239,   243,   245,   249,   253,   255,   259,   263,   267,   269,
   272,   275,   278,   281,   283,   288,   293,   296,   299,   301,
   302,   304,   306,   310,   312,   314
};

static const short yyrhs[] = {    44,
     0,    45,     0,    44,    45,     0,    46,     0,    61,     0,
     3,    33,     4,    37,     0,     3,    37,     0,     3,     1,
     0,    47,    58,     0,    47,    37,     0,    47,     1,     0,
    48,    53,    54,     0,    49,     0,    50,     0,    49,    50,
     0,    51,     0,    52,     0,     5,     0,     8,     0,    10,
     0,     3,     0,    34,    55,    35,     0,    56,     0,     0,
    57,     0,    56,    36,    57,     0,    48,    64,     0,    40,
    59,    66,    41,     0,    40,    59,    66,     1,     0,    60,
     0,     0,    61,     0,    60,    61,     0,    48,    62,    37,
     0,    48,    62,     1,     0,    63,     0,    62,    36,    63,
     0,    64,     0,    64,    33,     4,     0,     3,     0,     3,
    38,    65,    39,     0,     3,    38,    65,     1,     0,     4,
     0,     0,    67,     0,     0,    68,     0,    67,    68,     0,
    58,     0,    69,     0,    71,     0,    72,     0,    73,     0,
    70,    37,     0,    74,     1,     0,    74,     0,     0,     7,
    34,    74,    35,    68,     0,     7,    34,    74,    35,    68,
     6,    68,     0,    11,    34,    74,    35,    68,     0,     9,
    70,    37,     0,    75,     0,    76,     0,    82,    33,    75,
     0,    82,    12,    75,     0,    82,    13,    75,     0,    82,
    14,    75,     0,    82,    15,    75,     0,    82,    16,    75,
     0,    77,     0,    76,    17,    77,     0,    78,     0,    77,
    18,    78,     0,    79,     0,    78,    19,    79,     0,    78,
    20,    79,     0,    80,    37,     0,    79,    21,    80,     0,
    79,    22,    80,     0,    79,    23,    80,     0,    79,    24,
    80,     0,    81,     0,    80,    27,    81,     0,    80,    28,
    81,     0,    82,     0,    81,    29,    82,     0,    81,    30,
    82,     0,    81,    31,    82,     0,    83,     0,    28,    82,
     0,    32,    82,     0,    25,    82,     0,    26,    82,     0,
    87,     0,    83,    38,    74,    39,     0,    83,    34,    84,
    35,     0,    83,    25,     0,    83,    26,     0,    85,     0,
     0,    86,     0,    75,     0,    86,    36,    75,     0,     3,
     0,     4,     0,    34,    74,    35,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    36,    37,    38,    39,    40,    41,    42,    43,    48,    49,
    50,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    76,    77,    78,    79,    80,    81,    82,    83,    88,
    89,    90,    91,    92,    93,    98,    99,   100,   101,   102,
   108,   114,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   131,   132,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
   173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
   183,   184,   185,   186,   187,   188
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TCONST","TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TADDASSIGN",
"TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TOR","TAND","TEQUAL","TNOTEQU",
"TGREAT","TLESS","TGREATE","TLESSE","TINC","TDEC","TPLUS","TMINUS","TMULTIPLY",
"TDIVIDE","TMOD","TNOT","TASSIGN","TLPAREN","TRPAREN","TCOMMA","TSEMI","TLBRACKET",
"TRBRACKET","TLBRACE","TRBRACE","LOWER_THAN_ELSE","mini_c","translation_unit",
"external_dcl","function_def","function_header","dcl_spec","dcl_specifiers",
"dcl_specifier","type_qualifier","type_specifier","function_name","formal_param",
"opt_formal_param","formal_param_list","param_dcl","compound_st","opt_dcl_list",
"declaration_list","declaration","init_dcl_list","init_declarator","declarator",
"opt_number","opt_stat_list","statement_list","statement","expression_st","opt_expression",
"if_st","while_st","return_st","expression","assignment_exp","logical_or_exp",
"logical_and_exp","equality_exp","relational_exp","additive_exp","multiplicative_exp",
"unary_exp","postfix_exp","opt_actual_param","actual_param","actual_param_list",
"primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    43,    44,    44,    45,    45,    45,    45,    45,    46,    46,
    46,    47,    48,    49,    49,    50,    50,    51,    52,    52,
    53,    54,    55,    55,    56,    56,    57,    58,    58,    59,
    59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
    64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
    68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
    73,    74,    75,    75,    75,    75,    75,    75,    75,    76,
    76,    77,    77,    78,    78,    78,    79,    79,    79,    79,
    79,    80,    80,    80,    81,    81,    81,    81,    82,    82,
    82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
    85,    86,    86,    87,    87,    87
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     4,     2,     2,     2,     2,
     2,     3,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     3,     1,     0,     1,     3,     2,     4,     4,     1,
     0,     1,     2,     3,     3,     1,     3,     1,     3,     1,
     4,     4,     1,     0,     1,     0,     1,     2,     1,     1,
     1,     1,     1,     2,     2,     1,     0,     5,     7,     5,
     3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
     3,     1,     3,     1,     3,     3,     2,     3,     3,     3,
     3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
     2,     2,     2,     1,     4,     4,     2,     2,     1,     0,
     1,     1,     3,     1,     1,     3
};

static const short yydefact[] = {     0,
     0,    18,    19,    20,     1,     2,     4,     0,     0,    13,
    14,    16,    17,     5,     8,     0,     7,     3,    11,    10,
    31,     9,    40,     0,     0,    36,    38,    15,     0,     0,
    46,    30,    32,    44,    24,    12,    35,     0,    34,     0,
     6,    40,   104,   105,     0,    57,     0,     0,     0,     0,
     0,     0,    49,     0,    45,    47,    50,     0,    51,    52,
    53,     0,    62,    63,    70,    72,    74,     0,    82,    85,
    89,    94,    33,    43,     0,     0,     0,    23,    25,    37,
    39,     0,     0,    56,     0,    92,    93,    90,    91,     0,
    29,    28,    48,    54,    55,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    97,    98,   100,     0,    42,
    41,    27,    22,     0,     0,    61,     0,   106,    71,    85,
    73,    75,    76,    78,    79,    80,    81,    83,    84,    86,
    87,    88,    65,    66,    67,    68,    69,    64,   102,     0,
    99,   101,     0,    26,    57,    57,    96,     0,    95,    58,
    60,   103,    57,    59,     0,     0,     0
};

static const short yydefgoto[] = {   165,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    24,
    36,    77,    78,    79,    53,    31,    32,    14,    25,    26,
    27,    75,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
   150,   151,   152,    72
};

static const short yypact[] = {   113,
     9,-32768,-32768,-32768,   113,-32768,-32768,     8,    23,   104,
-32768,-32768,-32768,-32768,-32768,    24,-32768,-32768,-32768,-32768,
   104,-32768,    -1,   -21,    30,-32768,     7,-32768,    36,    58,
    65,   104,-32768,    77,   104,-32768,-32768,    58,-32768,    83,
-32768,    57,-32768,-32768,    64,   103,    81,   103,   103,   103,
   103,   103,-32768,     6,    65,-32768,-32768,    87,-32768,-32768,
-32768,    13,-32768,   105,   102,    15,    56,     2,   114,    70,
    -2,-32768,-32768,-32768,    10,    58,    95,    96,-32768,-32768,
-32768,   103,    97,-32768,   103,-32768,-32768,-32768,-32768,    98,
-32768,-32768,-32768,-32768,-32768,   103,   103,   103,   103,   103,
   103,   103,   103,   103,   103,-32768,   103,   103,   103,   103,
   103,   103,   103,   103,   103,-32768,-32768,   103,   103,-32768,
-32768,-32768,-32768,   104,   101,-32768,   107,-32768,   102,-32768,
    15,    56,    56,    16,    16,    16,    16,   114,   114,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   111,
-32768,   112,   108,-32768,    85,    85,-32768,   103,-32768,   143,
-32768,-32768,    85,-32768,   150,   151,-32768
};

static const short yypgoto[] = {-32768,
-32768,   147,-32768,-32768,   -20,-32768,   144,-32768,-32768,-32768,
-32768,-32768,-32768,    29,   148,-32768,-32768,    -5,-32768,   117,
    82,-32768,-32768,-32768,   -55,-32768,   115,-32768,-32768,-32768,
   -44,   -93,-32768,    61,    62,   -28,    38,    22,   -45,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		161


static const short yytable[] = {    93,
    30,    84,    86,    87,    88,    89,    91,    90,    19,    15,
   120,    30,    35,    95,    76,    33,   143,   144,   145,   146,
   147,   148,   116,   117,   149,    23,    73,    29,   104,   105,
    37,   118,   -21,    98,    99,   119,    34,   125,   106,    40,
   127,    16,   104,   105,    20,    17,    92,    21,   121,   -56,
   130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
    42,   140,   141,   142,   162,    38,    39,    43,    44,   132,
   133,    45,    41,    46,   153,    47,   100,   101,   102,   103,
    74,   110,   111,   112,   113,   114,    81,    43,    44,    48,
    49,    45,    50,    46,    34,    47,    51,    82,    52,   160,
   161,   -57,   115,    76,    21,    43,    44,   164,     2,    48,
    49,     3,    50,     4,    85,     1,    51,     2,    52,    97,
     3,    96,     4,    94,    21,   138,   139,    48,    49,   123,
    50,   124,   128,   126,    51,   155,    52,   134,   135,   136,
   137,   156,   107,   108,   109,   157,   159,   158,   163,   166,
   167,    18,   154,    28,    80,    22,   129,   122,   131,     0,
    83
};

static const short yycheck[] = {    55,
    21,    46,    48,    49,    50,    51,     1,    52,     1,     1,
     1,    32,    34,     1,    35,    21,   110,   111,   112,   113,
   114,   115,    25,    26,   118,     3,    32,     4,    27,    28,
     1,    34,    34,    19,    20,    38,    38,    82,    37,    33,
    85,    33,    27,    28,    37,    37,    41,    40,    39,    37,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     3,   107,   108,   109,   158,    36,    37,     3,     4,    98,
    99,     7,    37,     9,   119,    11,    21,    22,    23,    24,
     4,    12,    13,    14,    15,    16,     4,     3,     4,    25,
    26,     7,    28,     9,    38,    11,    32,    34,    34,   155,
   156,    37,    33,   124,    40,     3,     4,   163,     5,    25,
    26,     8,    28,    10,    34,     3,    32,     5,    34,    18,
     8,    17,    10,    37,    40,   104,   105,    25,    26,    35,
    28,    36,    35,    37,    32,    35,    34,   100,   101,   102,
   103,    35,    29,    30,    31,    35,    39,    36,     6,     0,
     0,     5,   124,    10,    38,     8,    96,    76,    97,    -1,
    46
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 8:
#line 44 "parser.y"
{
				yyerrok;
				PrintError(wstat);
			;
    break;}
case 11:
#line 51 "parser.y"
{
				T2 = defa;
				a();

				yyerrok;
				PrintError(wfunc);
			;
    break;}
case 19:
#line 65 "parser.y"
{T1 = in;;
    break;}
case 20:
#line 66 "parser.y"
{T1 = vo;;
    break;}
case 21:
#line 68 "parser.y"
{
			T2 = func; 
			a();
			temp->scope = func_in;
			
			b();

		;
    break;}
case 28:
#line 82 "parser.y"
{ func_in--; ;
    break;}
case 29:
#line 84 "parser.y"
{
			yyerrok;
			PrintError(nobrace);
		;
    break;}
case 35:
#line 94 "parser.y"
{
				yyerrok;
				PrintError(nosemi);
			;
    break;}
case 40:
#line 103 "parser.y"
{
				T2=scal; 
				a();
				temp->scope = func_in;
			;
    break;}
case 41:
#line 109 "parser.y"
{
				T2 = arra; 
				a();					
				temp->scope = func_in;
			;
    break;}
case 42:
#line 115 "parser.y"
{
				yyerrok;
				PrintError(nobracket);
			;
    break;}
case 55:
#line 133 "parser.y"
{
			yyerrok;
			PrintError(nosemi);
		;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 189 "parser.y"



void a()
{
		if(T2 == func)
			temp -> type3 = 4;
		else if( (T2 == scal) || (T2 == arra) )
		{
			if(T2 == scal)
			{
				if(T1 == in)
					temp -> type3 = 0;
				else if(T1 == vo)
					temp -> type3 = 2;
			}
			else if(T2 == arra)
			{
				if(T1 == in)
					temp -> type3 = 1;
				else if(T1 == vo)
					temp -> type3 = 3;
			}
		}
}

void b()
{
	HTpointer cur;

	if(ScopeTrace == NULL){
		ScopeTrace = temp;
	}
	else
	{
		cur = ScopeTrace;
		
		while(cur->func_next != NULL)
			cur = cur->func_next;
		
		cur->func_next = temp;

	}

	func_in++;
}
