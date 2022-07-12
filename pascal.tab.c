
/*  A Bison parser, made from pascal.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	UNSIGNED_INT	257
#define	UNSIGNED_REAL	258
#define	STRING	259
#define	IDENTIFIER	260
#define	NE	261
#define	LE	262
#define	GE	263
#define	BECOMES	264
#define	DIV	265
#define	MOD	266
#define	NIL	267
#define	IN	268
#define	OR	269
#define	AND	270
#define	NOT	271
#define	DOTDOT	272
#define	IF	273
#define	THEN	274
#define	ELSE	275
#define	CASE	276
#define	OF	277
#define	REPEAT	278
#define	UNTIL	279
#define	WHILE	280
#define	DO	281
#define	FOR	282
#define	TO	283
#define	DOWNTO	284
#define	SBEGIN	285
#define	END	286
#define	WITH	287
#define	GOTO	288
#define	CONST	289
#define	VAR	290
#define	TYPE	291
#define	ARRAY	292
#define	RECORD	293
#define	SET	294
#define	SFILE	295
#define	FUNCTION	296
#define	PROCEDURE	297
#define	LABEL	298
#define	PACKED	299
#define	PROGRAM	300
#define	TRUE	301
#define	FALSE	302

#line 1 "pascal.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "types.h"
#include "arbre.h"
#include "creer_arbre.h"
#include "verifi.h"
#include"debogage.h"
#include"table_symbol.h"

int genere(SArbre *arbre1);


extern	int	yylineno;
extern	char	yytext[];
extern	char	numbertext[80];
extern	char	*laststring;
extern	char	lastident[];

extern  char	*create_string();

//#define YYSTYPE item

extern FILE *yyin;

int	lexical_level = 0;

static	int	param_level = 0;
static	char *its_a = "error - uninitialised";

int yyerror(char*);
int yylex(void);
char *token_name(int);
int yyparse(void);

SArbre *res=NULL;


#line 42 "pascal.y"
typedef union {
int entier;
double reel;
char *text;
struct SListe_instr *instr;
struct SExpr *exp;
struct SListe_declare_var *decl_var;
struct SType *type;
struct SDeclare *declare;
void **couple;
void *generique;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		343
#define	YYFLAG		-32768
#define	YYNTBASE	66

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 164)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
    52,    64,    55,    53,    56,    50,    65,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    60,    49,    62,
    54,    63,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    58,     2,    59,    57,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    61
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     9,    10,    11,    16,    19,    20,    22,    25,
    27,    29,    31,    33,    35,    37,    41,    45,    47,    49,
    53,    57,    59,    60,    65,    67,    70,    73,    75,    78,
    81,    83,    85,    87,    91,    95,    97,    98,   103,   105,
   108,   110,   113,   114,   119,   123,   125,   132,   136,   140,
   144,   148,   150,   152,   156,   158,   162,   164,   165,   170,
   171,   172,   178,   182,   184,   188,   190,   196,   197,   201,
   205,   207,   208,   213,   214,   217,   221,   223,   225,   230,
   235,   236,   237,   243,   244,   245,   251,   252,   256,   258,
   260,   261,   262,   267,   271,   273,   274,   277,   278,   282,
   283,   286,   287,   290,   294,   296,   303,   311,   315,   317,
   318,   325,   327,   331,   335,   337,   338,   342,   344,   346,
   348,   351,   356,   363,   369,   374,   379,   388,   393,   395,
   397,   401,   404,   405,   409,   413,   415,   417,   420,   423,
   428,   432,   434,   438,   439,   443,   445,   447,   451,   453,
   455,   459,   461,   463,   465,   467,   469,   471,   473,   475,
   478,   481,   485,   487,   489,   491,   493,   497,   499,   501,
   503,   505,   507,   509,   511,   515,   517,   520,   522,   524,
   526,   528,   530,   534,   535,   537,   541,   543,   545,   549,
   552,   557,   561,   564,   568,   570,   572,   574
};

static const short yyrhs[] = {    -1,
    46,    67,   163,    68,    49,    70,    50,     0,     0,     0,
    51,    69,   105,    52,     0,    71,   131,     0,     0,    72,
     0,    72,    73,     0,    73,     0,    74,     0,    77,     0,
    83,     0,   101,     0,   108,     0,    44,    75,    49,     0,
    75,    53,    76,     0,    76,     0,     3,     0,    35,    78,
    49,     0,    78,    49,    79,     0,    79,     0,     0,    80,
   163,    54,    81,     0,    82,     0,    55,    82,     0,    56,
    82,     0,   162,     0,    55,   162,     0,    56,   162,     0,
     5,     0,     3,     0,     4,     0,    37,    84,    49,     0,
    84,    49,    85,     0,    85,     0,     0,    86,   163,    54,
    87,     0,    88,     0,    45,    90,     0,    90,     0,    57,
     6,     0,     0,    51,    89,   105,    52,     0,    81,    18,
    81,     0,   162,     0,    38,    58,    91,    59,    23,    87,
     0,    39,    92,    32,     0,    40,    23,    88,     0,    41,
    23,    87,     0,    91,    53,    88,     0,    88,     0,    93,
     0,    93,    49,    96,     0,    96,     0,    93,    49,    94,
     0,    94,     0,     0,    95,   105,    60,    87,     0,     0,
     0,    22,    97,    98,    23,    99,     0,   163,    60,   162,
     0,   162,     0,    99,    49,   100,     0,   100,     0,   144,
    60,    51,    92,    52,     0,     0,    36,   102,    49,     0,
   102,    49,   103,     0,   103,     0,     0,   104,   105,    60,
    87,     0,     0,   107,   106,     0,   107,    53,   163,     0,
   163,     0,   109,     0,   110,    49,   117,    49,     0,   113,
    49,   117,    49,     0,     0,     0,    43,   111,   163,   112,
   118,     0,     0,     0,    42,   114,   163,   115,   116,     0,
     0,   118,    60,   162,     0,    70,     0,     6,     0,     0,
     0,    51,   119,   120,    52,     0,   120,    49,   121,     0,
   121,     0,     0,   122,   126,     0,     0,    36,   123,   126,
     0,     0,   124,   110,     0,     0,   125,   113,     0,   105,
    60,   127,     0,   162,     0,    38,    58,   128,    59,    23,
   127,     0,    45,    38,    58,   129,    59,    23,   162,     0,
   128,    49,   129,     0,   129,     0,     0,   130,   163,    18,
   163,    60,   162,     0,   132,     0,    31,   133,    32,     0,
   133,    49,   134,     0,   134,     0,     0,    76,    60,   134,
     0,   132,     0,   136,     0,   137,     0,    34,    76,     0,
    19,   147,    20,   134,     0,    19,   147,    20,   134,    21,
   134,     0,    22,   147,    23,   142,    32,     0,    26,   147,
    27,   134,     0,    24,   133,    25,   147,     0,    28,   162,
    10,   147,   135,   147,    27,   134,     0,    33,   146,    27,
   134,     0,    29,     0,    30,     0,   159,    10,   147,     0,
   162,   138,     0,     0,    51,   139,    52,     0,   139,    53,
   140,     0,   140,     0,   147,     0,   147,   141,     0,    61,
   147,     0,    61,   147,    61,   147,     0,   142,    49,   143,
     0,   143,     0,   144,    60,   134,     0,     0,   144,    53,
   145,     0,   145,     0,    81,     0,   146,    53,   161,     0,
   161,     0,   149,     0,   149,   148,   149,     0,    54,     0,
    62,     0,    63,     0,     8,     0,     9,     0,     7,     0,
    14,     0,   151,     0,    55,   151,     0,    56,   151,     0,
   149,   150,   151,     0,    55,     0,    56,     0,    15,     0,
   153,     0,   151,   152,   153,     0,    64,     0,    65,     0,
    11,     0,    12,     0,    16,     0,   159,     0,   154,     0,
    51,   147,    52,     0,   155,     0,    17,   153,     0,    82,
     0,     5,     0,    13,     0,    47,     0,    48,     0,    58,
   156,    59,     0,     0,   157,     0,   157,    53,   158,     0,
   158,     0,   147,     0,   147,    18,   147,     0,   162,   138,
     0,   159,    58,   160,    59,     0,   159,    50,   162,     0,
   159,    57,     0,   160,    53,   147,     0,   147,     0,   159,
     0,     6,     0,     6,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    77,    77,    82,    83,    83,    86,    89,    90,    92,    94,
    96,    97,    98,    99,   100,   103,   105,   106,   108,   112,
   114,   115,   117,   117,   120,   121,   122,   123,   125,   127,
   129,   133,   134,   137,   139,   140,   142,   142,   145,   146,
   147,   148,   152,   152,   154,   155,   158,   159,   160,   161,
   163,   164,   166,   167,   168,   170,   171,   173,   173,   174,
   176,   176,   178,   179,   181,   182,   184,   185,   188,   190,
   192,   194,   194,   197,   198,   200,   202,   206,   208,   211,
   215,   217,   219,   220,   222,   224,   225,   226,   229,   232,
   235,   236,   236,   238,   239,   241,   242,   242,   243,   243,
   244,   245,   245,   247,   250,   251,   253,   256,   257,   259,
   259,   262,   264,   266,   267,   269,   270,   271,   272,   273,
   274,   275,   277,   279,   281,   283,   285,   287,   290,   291,
   294,   299,   303,   304,   307,   308,   310,   312,   315,   316,
   319,   320,   322,   323,   325,   326,   328,   331,   332,   335,
   336,   339,   340,   341,   342,   343,   344,   345,   348,   349,
   350,   351,   354,   355,   356,   359,   360,   363,   364,   365,
   366,   367,   370,   372,   373,   375,   376,   379,   381,   383,
   384,   385,   392,   394,   395,   397,   398,   400,   401,   406,
   408,   410,   412,   415,   416,   418,   420,   422
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","UNSIGNED_INT",
"UNSIGNED_REAL","STRING","IDENTIFIER","NE","LE","GE","BECOMES","DIV","MOD","NIL",
"IN","OR","AND","NOT","DOTDOT","IF","THEN","ELSE","CASE","OF","REPEAT","UNTIL",
"WHILE","DO","FOR","TO","DOWNTO","SBEGIN","END","WITH","GOTO","CONST","VAR",
"TYPE","ARRAY","RECORD","SET","SFILE","FUNCTION","PROCEDURE","LABEL","PACKED",
"PROGRAM","TRUE","FALSE","';'","'.'","'('","')'","','","'='","'+'","'-'","'^'",
"'['","']'","':'","\":\"","'<'","'>'","'*'","'/'","program","@1","external_files",
"@2","block","opt_declarations","declarations","declaration","label_dcl_part",
"labels","label","const_dcl_part","const_defs","const_def","@3","constant","unsigned_num",
"type_dcl_part","type_defs","type_def","@4","type","simple_type","@5","struct_type",
"index_t_list","field_list","fixed_part","record_section","@6","variant_part",
"@7","tag_field","variants","variant","var_dcl_part","variable_dcls","variable_dcl",
"@8","newident_list","@9","new_id_list","proc_dcl_part","proc_or_func","proc_heading",
"@10","@11","func_heading","@12","@13","function_form","body","formal_params",
"@14","formal_p_sects","formal_p_sect","@15","@16","@17","@18","param_group",
"paramtype","index_specs","index_spec","@19","statement_part","compound_stmt",
"statements","statement","direction","assignment","procedure_call","actual_params",
"actuals_list","actual_param","colon_things","case_list","case_list_elem","case_label_list",
"case_label","rec_var_list","expression","relational_op","simple_expr","add_op",
"term","mult_op","factor","unsigned_lit","set","member_list","members","member",
"variable","expressions","record_var","ident","newident", NULL
};
#endif

static const short yyr1[] = {     0,
    67,    66,    68,    69,    68,    70,    71,    71,    72,    72,
    73,    73,    73,    73,    73,    74,    75,    75,    76,    77,
    78,    78,    80,    79,    81,    81,    81,    81,    81,    81,
    81,    82,    82,    83,    84,    84,    86,    85,    87,    87,
    87,    87,    89,    88,    88,    88,    90,    90,    90,    90,
    91,    91,    92,    92,    92,    93,    93,    95,    94,    94,
    97,    96,    98,    98,    99,    99,   100,   100,   101,   102,
   102,   104,   103,   106,   105,   107,   107,   108,   109,   109,
   111,   112,   110,   114,   115,   113,   116,   116,   117,   117,
   118,   119,   118,   120,   120,   122,   121,   123,   121,   124,
   121,   125,   121,   126,   127,   127,   127,   128,   128,   130,
   129,   131,   132,   133,   133,   134,   134,   134,   134,   134,
   134,   134,   134,   134,   134,   134,   134,   134,   135,   135,
   136,   137,   138,   138,   139,   139,   140,   140,   141,   141,
   142,   142,   143,   143,   144,   144,   145,   146,   146,   147,
   147,   148,   148,   148,   148,   148,   148,   148,   149,   149,
   149,   149,   150,   150,   150,   151,   151,   152,   152,   152,
   152,   152,   153,   153,   153,   153,   153,   154,   154,   154,
   154,   154,   155,   156,   156,   157,   157,   158,   158,   159,
   159,   159,   159,   160,   160,   161,   162,   163
};

static const short yyr2[] = {     0,
     0,     7,     0,     0,     4,     2,     0,     1,     2,     1,
     1,     1,     1,     1,     1,     3,     3,     1,     1,     3,
     3,     1,     0,     4,     1,     2,     2,     1,     2,     2,
     1,     1,     1,     3,     3,     1,     0,     4,     1,     2,
     1,     2,     0,     4,     3,     1,     6,     3,     3,     3,
     3,     1,     1,     3,     1,     3,     1,     0,     4,     0,
     0,     5,     3,     1,     3,     1,     5,     0,     3,     3,
     1,     0,     4,     0,     2,     3,     1,     1,     4,     4,
     0,     0,     5,     0,     0,     5,     0,     3,     1,     1,
     0,     0,     4,     3,     1,     0,     2,     0,     3,     0,
     2,     0,     2,     3,     1,     6,     7,     3,     1,     0,
     6,     1,     3,     3,     1,     0,     3,     1,     1,     1,
     2,     4,     6,     5,     4,     4,     8,     4,     1,     1,
     3,     2,     0,     3,     3,     1,     1,     2,     2,     4,
     3,     1,     3,     0,     3,     1,     1,     3,     1,     1,
     3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
     2,     3,     1,     1,     1,     1,     3,     1,     1,     1,
     1,     1,     1,     1,     3,     1,     2,     1,     1,     1,
     1,     1,     3,     0,     1,     3,     1,     1,     3,     2,
     4,     3,     2,     3,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     1,     0,   198,     3,     4,     0,     0,     7,     0,    74,
    77,    23,    72,    37,    84,    81,     0,     0,     0,     8,
    10,    11,    12,    13,    14,    15,    78,     0,     0,     5,
     0,    75,     0,    22,     0,     0,    71,     0,     0,    36,
     0,     0,     0,    19,     0,    18,     2,   116,     6,   112,
     9,     7,     7,    76,    20,     0,    69,     0,    34,     0,
    85,    82,    16,     0,   197,     0,     0,   116,     0,     0,
     0,     0,     0,   118,     0,   115,   119,   120,     0,   133,
    90,    89,     0,     0,    21,     0,    70,     0,    35,     0,
    87,    91,    17,    32,    33,   179,   180,     0,   181,   182,
     0,     0,     0,   184,   178,     0,   150,   159,   166,   174,
   176,   173,   133,     0,     0,     0,     0,     0,   196,   149,
   121,   116,   113,   116,     0,     0,   193,     0,     0,   132,
    79,    80,    31,     0,     0,    24,    25,    28,     0,    60,
     0,     0,     0,    43,     0,     0,    73,    39,    41,    46,
    38,    92,    86,     0,    83,   177,     0,   160,   161,   188,
     0,   185,   187,   116,   157,   155,   156,   158,   165,   152,
   163,   164,   153,   154,     0,     0,   170,   171,   172,   168,
   169,     0,   190,   144,     0,   116,     0,   116,     0,   117,
   114,   131,   192,   195,     0,     0,   136,   137,    26,    29,
    27,    30,     0,    61,     0,    53,    57,     0,    55,     0,
     0,    40,     0,    42,     0,    96,     0,   175,     0,   183,
     0,   122,   151,   162,   167,   147,     0,   142,     0,   146,
   126,   125,     0,   128,   148,     0,   191,   134,     0,     0,
   138,    52,     0,     0,    48,    60,     0,    49,    50,     0,
    45,    98,     0,    95,     0,     0,     0,    88,   189,   186,
   116,   124,   144,     0,   116,   129,   130,     0,   194,   135,
   139,     0,     0,   197,     0,    64,     0,    56,    54,     0,
    44,     0,    96,    93,     0,    97,   101,   103,   123,   141,
   145,   143,     0,     0,    51,     0,    68,     0,    59,    99,
    94,     0,   116,   140,    47,    62,    66,     0,    63,     0,
     0,   104,   105,   127,    68,     0,   110,     0,    65,    60,
     0,   109,     0,   110,     0,   110,     0,     0,     0,    67,
   108,     0,     0,     0,   106,     0,     0,     0,   107,   111,
     0,     0,     0
};

static const short yydefgoto[] = {   341,
     2,     6,     7,    82,    19,    20,    21,    22,    45,    73,
    23,    33,    34,    35,   146,   105,    24,    39,    40,    41,
   147,   148,   213,   149,   243,   205,   206,   207,   208,   209,
   244,   275,   306,   307,    25,    36,    37,    38,   285,    32,
    10,    26,    27,    28,    43,    92,    29,    42,    91,   153,
    83,   154,   216,   253,   254,   255,   282,   256,   257,   286,
   312,   321,   322,   323,    49,    74,    75,    76,   268,    77,
    78,   130,   196,   197,   241,   227,   228,   229,   230,   118,
   160,   175,   107,   176,   108,   182,   109,   110,   111,   161,
   162,   163,   112,   195,   120,   113,    11
};

static const short yypact[] = {    24,
-32768,    45,-32768,    42,-32768,    54,    45,   119,    82,    96,
-32768,-32768,-32768,-32768,-32768,-32768,   136,   102,   122,   119,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   116,   121,-32768,
    45,-32768,   126,-32768,    45,   133,-32768,    45,   139,-32768,
    45,    45,    45,-32768,    35,-32768,-32768,   177,-32768,-32768,
-32768,    88,    88,-32768,   162,   118,   186,   134,   206,   161,
-32768,-32768,-32768,   136,-32768,   261,   261,   177,   261,   210,
   210,   136,   164,-32768,     6,-32768,-32768,-32768,    57,   174,
-32768,-32768,   184,   188,-32768,    92,-32768,   294,-32768,   294,
   -33,   175,-32768,-32768,-32768,-32768,-32768,   279,-32768,-32768,
   261,   279,   279,   261,-32768,   215,    50,     4,-32768,-32768,
-32768,   156,   174,   216,   -12,   213,   233,    -8,   156,-32768,
-32768,   177,-32768,   177,   261,   210,-32768,   261,   261,    61,
-32768,-32768,-32768,   228,   228,-32768,-32768,-32768,   187,    25,
   226,   227,   146,-32768,   245,   237,-32768,-32768,-32768,   238,
-32768,-32768,-32768,   197,-32768,-32768,   209,     4,     4,   250,
   211,   219,-32768,   177,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   261,   279,-32768,-32768,-32768,-32768,
-32768,   279,-32768,    92,   261,   177,   261,   177,   210,-32768,
-32768,-32768,-32768,-32768,   -23,    64,-32768,   208,-32768,-32768,
-32768,-32768,   123,-32768,   241,   230,-32768,    45,-32768,   123,
   294,-32768,    45,-32768,    92,   115,   210,-32768,   261,-32768,
   261,   254,    -7,     4,-32768,-32768,    40,-32768,    13,-32768,
-32768,-32768,   168,-32768,-32768,   261,-32768,-32768,   261,   261,
-32768,-32768,    49,   271,-32768,    25,   220,-32768,-32768,   234,
-32768,-32768,    86,-32768,    45,   244,   247,-32768,-32768,-32768,
   177,-32768,    92,    92,   177,-32768,-32768,   261,-32768,-32768,
   229,   123,   268,   235,   278,-32768,   243,-32768,-32768,   294,
-32768,    45,   115,-32768,   246,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   277,   261,-32768,   294,    92,   210,-32768,-32768,
-32768,     5,   177,-32768,-32768,   256,-32768,    39,-32768,   249,
   272,-32768,-32768,-32768,    92,   260,-32768,   255,-32768,    25,
   -27,-32768,    45,-32768,   262,-32768,   292,   300,   263,-32768,
-32768,     5,    45,   297,-32768,   264,   210,   210,-32768,-32768,
   323,   325,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,   320,-32768,-32768,   309,-32768,-32768,   -11,
-32768,-32768,   281,-32768,   -74,   -34,-32768,-32768,   282,-32768,
   -89,  -196,-32768,   195,-32768,    20,-32768,    97,-32768,    98,
-32768,-32768,-32768,    27,-32768,-32768,   289,-32768,    -4,-32768,
-32768,-32768,-32768,    91,-32768,-32768,    95,-32768,-32768,-32768,
   295,   265,-32768,-32768,    70,-32768,-32768,-32768,-32768,    72,
    23,-32768,  -264,-32768,-32768,   337,   290,  -101,-32768,-32768,
-32768,   248,-32768,   120,-32768,-32768,    99,  -280,   100,-32768,
     8,-32768,   185,-32768,   -93,-32768,   -96,-32768,-32768,-32768,
-32768,   142,   -43,-32768,   176,   -44,    -2
};


#define	YYLAST		365


static const short yytable[] = {     4,
   151,   156,     9,    80,    79,    46,   242,   169,   158,   159,
    65,   136,   185,   248,   177,   178,   308,   152,   188,   179,
   190,   326,   191,    80,    79,   117,   -91,   119,    54,   236,
   -58,   327,    56,    58,   308,   237,   124,   123,    60,    61,
    62,   138,   310,   150,   189,   150,   204,   171,   172,   311,
     3,   137,    93,   137,   124,   137,   165,   166,   167,   329,
   121,   331,   222,   168,   169,   264,   125,   180,   181,     1,
  -190,   262,   265,   106,   114,   295,   116,    80,    79,    80,
    79,   193,   224,    63,   232,   225,   234,    64,   263,   200,
   202,   264,     5,    81,    94,    95,   133,    65,   316,   199,
   201,   272,     8,   170,   171,   172,   126,   273,   157,   226,
  -190,   173,   174,   127,   128,   238,   239,  -190,  -190,    80,
    79,   249,    12,    13,    14,    94,    95,   133,    65,    15,
    16,    17,   192,    30,   283,   194,   198,   284,    44,   138,
   251,    80,    79,    80,    79,   119,   134,   135,    31,   137,
   252,    47,    48,    12,    13,    14,  -102,  -100,   150,   289,
    15,    16,    17,   292,    52,   150,   150,   -23,   137,    53,
   138,    86,   258,   144,    55,   137,   137,   134,   135,    44,
   137,    57,    65,   139,   140,   141,   142,    59,   226,   226,
   299,   -72,   231,    88,   233,    66,   266,   267,    67,   276,
    68,   314,    69,   247,    70,   126,   305,    48,   250,    71,
    72,   -37,   127,   128,    90,    65,    80,    79,   138,   138,
    80,    79,   226,   122,   129,   152,   259,   150,   137,   137,
    94,    95,   131,    65,   164,   150,   132,   137,   184,   186,
   226,   277,   187,   269,   203,   137,   198,   271,   210,   211,
   214,   150,   138,   309,   215,   -28,   217,   313,    80,    79,
   218,   137,   137,    94,    95,    96,    65,   219,   240,   220,
   138,   221,   245,    97,   261,   293,   274,    98,   246,   280,
   137,    94,    95,    96,    65,   281,    16,   313,    15,   294,
   296,    97,   339,   340,  -198,    98,    94,    95,   133,    65,
   297,   304,   298,   303,   315,   302,   317,    99,   100,   318,
   320,   101,   324,   330,   332,   102,   103,   333,   104,   337,
   328,   334,   342,   338,   343,    99,   100,    18,    51,   101,
   336,   139,   140,   141,   142,    85,   104,   212,   143,   325,
    89,   319,   278,   279,   144,    87,   287,    84,   134,   135,
   145,   288,   301,   300,   335,    50,   155,   115,   270,   223,
   183,   290,   260,   291,   235
};

static const short yycheck[] = {     2,
    90,    98,     7,    48,    48,    17,   203,    15,   102,   103,
     6,    86,    25,   210,    11,    12,   297,    51,    27,    16,
   122,    49,   124,    68,    68,    70,    60,    71,    31,    53,
     6,    59,    35,    38,   315,    59,    49,    32,    41,    42,
    43,    86,    38,    88,    53,    90,    22,    55,    56,    45,
     6,    86,    64,    88,    49,    90,     7,     8,     9,   324,
    72,   326,   164,    14,    15,    53,    10,    64,    65,    46,
    10,    32,    60,    66,    67,   272,    69,   122,   122,   124,
   124,   126,   176,    49,   186,   182,   188,    53,    49,   134,
   135,    53,    51,     6,     3,     4,     5,     6,    60,   134,
   135,    53,    49,    54,    55,    56,    50,    59,   101,   184,
    50,    62,    63,    57,    58,    52,    53,    57,    58,   164,
   164,   211,    35,    36,    37,     3,     4,     5,     6,    42,
    43,    44,   125,    52,    49,   128,   129,    52,     3,   184,
   215,   186,   186,   188,   188,   189,    55,    56,    53,   184,
    36,    50,    31,    35,    36,    37,    42,    43,   203,   261,
    42,    43,    44,   265,    49,   210,   211,     6,   203,    49,
   215,    54,   217,    51,    49,   210,   211,    55,    56,     3,
   215,    49,     6,    38,    39,    40,    41,    49,   263,   264,
   280,     6,   185,    60,   187,    19,    29,    30,    22,   244,
    24,   303,    26,   208,    28,    50,   296,    31,   213,    33,
    34,     6,    57,    58,    54,     6,   261,   261,   263,   264,
   265,   265,   297,    60,    51,    51,   219,   272,   263,   264,
     3,     4,    49,     6,    20,   280,    49,   272,    23,    27,
   315,   244,    10,   236,    58,   280,   239,   240,    23,    23,
     6,   296,   297,   298,    18,    18,    60,   302,   303,   303,
    52,   296,   297,     3,     4,     5,     6,    18,    61,    59,
   315,    53,    32,    13,    21,   268,     6,    17,    49,    60,
   315,     3,     4,     5,     6,    52,    43,   332,    42,    61,
    23,    13,   337,   338,    60,    17,     3,     4,     5,     6,
    23,   294,    60,    27,    49,    60,    58,    47,    48,    38,
    51,    51,    58,    52,    23,    55,    56,    18,    58,    23,
   323,    59,     0,    60,     0,    47,    48,     8,    20,    51,
   333,    38,    39,    40,    41,    55,    58,   143,    45,   320,
    59,   315,   246,   246,    51,    57,   256,    53,    55,    56,
    57,   257,   283,   282,   332,    19,    92,    68,   239,   175,
   113,   263,   221,   264,   189
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/dev/env/DJDIR/share/bison.simple"
/* This file comes from bison-1.28.  */

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (__MSDOS__)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not __MSDOS__, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not __MSDOS__, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
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

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
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
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/dev/env/DJDIR/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
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
  int yyfree_stacks = 0;

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
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
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

case 1:
#line 77 "pascal.y"
{its_a="program";;
    break;}
case 2:
#line 79 "pascal.y"
{ res=creer_arbre(yyvsp[-4].text,(SDeclare *)(yyvsp[-1].couple)[0],
				(SListe_instr *)(yyvsp[-1].couple)[1]); ;
    break;}
case 4:
#line 83 "pascal.y"
{its_a="external-file";;
    break;}
case 6:
#line 87 "pascal.y"
{yyval.couple=creer_couple(yyvsp[-1].generique,yyvsp[0].generique);;
    break;}
case 7:
#line 89 "pascal.y"
{yyval.declare=NULL;;
    break;}
case 8:
#line 90 "pascal.y"
{yyval.declare=yyvsp[0].declare;;
    break;}
case 9:
#line 93 "pascal.y"
{ yyval.declare=ajoute_declare(yyvsp[-1].declare,yyvsp[0].declare); ;
    break;}
case 10:
#line 94 "pascal.y"
{yyval.declare=yyvsp[0].declare;;
    break;}
case 11:
#line 96 "pascal.y"
{;
    break;}
case 12:
#line 97 "pascal.y"
{;
    break;}
case 13:
#line 98 "pascal.y"
{;
    break;}
case 14:
#line 99 "pascal.y"
{ yyval.declare=creer_declare_var(yyvsp[0].decl_var); ;
    break;}
case 15:
#line 100 "pascal.y"
{;
    break;}
case 18:
#line 106 "pascal.y"
{;
    break;}
case 19:
#line 109 "pascal.y"
{ yyval.text=strdup(itoa(yyvsp[0].entier,NULL,10)); ;
    break;}
case 23:
#line 117 "pascal.y"
{its_a="constant";;
    break;}
case 25:
#line 120 "pascal.y"
{yyval.exp=yyvsp[0].exp;;
    break;}
case 26:
#line 121 "pascal.y"
{yyval.exp=creer_exp_unaire(EPlus_u,yyvsp[0].exp);;
    break;}
case 27:
#line 122 "pascal.y"
{yyval.exp=creer_exp_unaire(EMoins_u,yyvsp[0].exp);;
    break;}
case 28:
#line 124 "pascal.y"
{yyval.exp=creer_exp_var(yyvsp[0].text);;
    break;}
case 29:
#line 126 "pascal.y"
{yyval.exp=creer_exp_unaire(EPlus_u,creer_exp_var(yyvsp[0].text));;
    break;}
case 30:
#line 128 "pascal.y"
{yyval.exp=creer_exp_unaire(EMoins_u,creer_exp_var(yyvsp[0].text));;
    break;}
case 31:
#line 130 "pascal.y"
{yyval.exp=creer_exp_string(yyvsp[0].text);;
    break;}
case 32:
#line 133 "pascal.y"
{yyval.exp=creer_exp_entier(yyvsp[0].entier);;
    break;}
case 33:
#line 134 "pascal.y"
{yyval.exp=creer_exp_reel(yyvsp[0].reel);;
    break;}
case 37:
#line 142 "pascal.y"
{its_a="type";;
    break;}
case 39:
#line 145 "pascal.y"
{ yyval.type=yyvsp[0].type;;
    break;}
case 40:
#line 146 "pascal.y"
{;
    break;}
case 41:
#line 147 "pascal.y"
{;
    break;}
case 42:
#line 149 "pascal.y"
{;
    break;}
case 43:
#line 152 "pascal.y"
{its_a="enumerated-literal";;
    break;}
case 44:
#line 153 "pascal.y"
{;
    break;}
case 45:
#line 154 "pascal.y"
{;
    break;}
case 46:
#line 155 "pascal.y"
{ yyval.type=creer_type_simple(yyvsp[0].text); ;
    break;}
case 51:
#line 163 "pascal.y"
{;
    break;}
case 52:
#line 164 "pascal.y"
{;
    break;}
case 58:
#line 173 "pascal.y"
{its_a="field";;
    break;}
case 61:
#line 176 "pascal.y"
{its_a="field";;
    break;}
case 63:
#line 178 "pascal.y"
{;
    break;}
case 64:
#line 179 "pascal.y"
{;
    break;}
case 69:
#line 188 "pascal.y"
{ yyval.decl_var=yyvsp[-1].decl_var;;
    break;}
case 70:
#line 191 "pascal.y"
{ yyval.decl_var=ajoute_decl_var(yyvsp[-2].decl_var,yyvsp[0].decl_var); ;
    break;}
case 71:
#line 192 "pascal.y"
{ yyval.decl_var=yyvsp[0].decl_var; ;
    break;}
case 72:
#line 194 "pascal.y"
{its_a="variable";;
    break;}
case 73:
#line 195 "pascal.y"
{ yyval.decl_var=ajoute_var_type(yyvsp[-2].decl_var,yyvsp[0].type); ;
    break;}
case 74:
#line 197 "pascal.y"
{its_a="don't know";;
    break;}
case 75:
#line 198 "pascal.y"
{ yyval.decl_var=yyvsp[-1].decl_var; ;
    break;}
case 76:
#line 201 "pascal.y"
{ yyval.decl_var=ajoute_decl_var(yyvsp[-2].decl_var,creer_decl_var(yyvsp[0].text)); ;
    break;}
case 77:
#line 203 "pascal.y"
{ yyval.decl_var=creer_decl_var(yyvsp[0].text); ;
    break;}
case 79:
#line 209 "pascal.y"
{lexical_level--;
			;
    break;}
case 80:
#line 212 "pascal.y"
{lexical_level--;
			;
    break;}
case 81:
#line 216 "pascal.y"
{if(param_level==0)its_a="procedure";;
    break;}
case 82:
#line 217 "pascal.y"
{lexical_level++;;
    break;}
case 84:
#line 221 "pascal.y"
{if(param_level==0)its_a="function";;
    break;}
case 85:
#line 222 "pascal.y"
{lexical_level++;;
    break;}
case 89:
#line 231 "pascal.y"
{;
    break;}
case 90:
#line 233 "pascal.y"
{;
    break;}
case 92:
#line 236 "pascal.y"
{param_level++;;
    break;}
case 93:
#line 236 "pascal.y"
{param_level--;;
    break;}
case 96:
#line 241 "pascal.y"
{its_a="value-parameter";;
    break;}
case 98:
#line 242 "pascal.y"
{its_a="var-parameter";;
    break;}
case 100:
#line 243 "pascal.y"
{its_a="procedure-parameter";;
    break;}
case 101:
#line 244 "pascal.y"
{lexical_level--;;
    break;}
case 102:
#line 245 "pascal.y"
{its_a="function-parameter";;
    break;}
case 103:
#line 245 "pascal.y"
{lexical_level--;;
    break;}
case 104:
#line 248 "pascal.y"
{;
    break;}
case 105:
#line 250 "pascal.y"
{;
    break;}
case 106:
#line 252 "pascal.y"
{;
    break;}
case 107:
#line 254 "pascal.y"
{;
    break;}
case 110:
#line 259 "pascal.y"
{its_a="conformant-bound";;
    break;}
case 112:
#line 262 "pascal.y"
{yyval.instr=yyvsp[0].instr;;
    break;}
case 113:
#line 264 "pascal.y"
{ yyval.instr=instr_bloc(yyvsp[-1].instr,NULL); ;
    break;}
case 114:
#line 266 "pascal.y"
{ yyval.instr=ajoute_instr(yyvsp[-2].instr,yyvsp[0].instr); ;
    break;}
case 115:
#line 267 "pascal.y"
{ yyval.instr=yyvsp[0].instr ;
    break;}
case 116:
#line 269 "pascal.y"
{ yyval.instr=NULL; ;
    break;}
case 117:
#line 270 "pascal.y"
{ yyval.instr=ajoute_instr_label(yyvsp[0].instr,yyvsp[-2].text); ;
    break;}
case 118:
#line 271 "pascal.y"
{ yyval.instr=yyvsp[0].instr; ;
    break;}
case 119:
#line 272 "pascal.y"
{ yyval.instr=yyvsp[0].instr; ;
    break;}
case 120:
#line 273 "pascal.y"
{ yyval.instr=yyvsp[0].instr; ;
    break;}
case 121:
#line 274 "pascal.y"
{ yyval.instr=instr_goto(yyvsp[0].text,NULL); ;
    break;}
case 122:
#line 276 "pascal.y"
{ yyval.instr=instr_if(yyvsp[-2].exp,yyvsp[0].instr,NULL,NULL); ;
    break;}
case 123:
#line 278 "pascal.y"
{ yyval.instr=instr_if(yyvsp[-4].exp,yyvsp[-2].instr,yyvsp[0].instr,NULL); ;
    break;}
case 124:
#line 280 "pascal.y"
{ yyval.instr=NULL; ;
    break;}
case 125:
#line 282 "pascal.y"
{ yyval.instr=instr_while(yyvsp[-2].exp,yyvsp[0].instr,NULL); ;
    break;}
case 126:
#line 284 "pascal.y"
{ yyval.instr=instr_repeat(yyvsp[0].exp,yyvsp[-2].instr,NULL); ;
    break;}
case 127:
#line 286 "pascal.y"
{ yyval.instr=NULL; ;
    break;}
case 128:
#line 288 "pascal.y"
{ yyval.instr=NULL; ;
    break;}
case 131:
#line 295 "pascal.y"
{ yyval.instr=instr_affect(creer_exp_var(yyvsp[-2].text),yyvsp[0].exp,NULL); ;
    break;}
case 132:
#line 300 "pascal.y"
{ yyval.instr=instr_appel(yyvsp[-1].text,yyvsp[0].exp,NULL); ;
    break;}
case 133:
#line 303 "pascal.y"
{ yyval.exp=NULL; ;
    break;}
case 134:
#line 305 "pascal.y"
{ yyval.exp=yyvsp[-1].exp; ;
    break;}
case 135:
#line 307 "pascal.y"
{yyval.exp=ajoute_exp(yyvsp[-2].exp,yyvsp[0].exp);;
    break;}
case 136:
#line 308 "pascal.y"
{yyval.exp=yyvsp[0].exp;
    break;}
case 137:
#line 311 "pascal.y"
{yyval.exp=yyvsp[0].exp;;
    break;}
case 138:
#line 313 "pascal.y"
{yyval.exp=yyvsp[-1].exp;;
    break;}
case 147:
#line 328 "pascal.y"
{;
    break;}
case 150:
#line 335 "pascal.y"
{ yyval.exp=yyvsp[0].exp; ;
    break;}
case 151:
#line 337 "pascal.y"
{ yyval.exp=creer_exp_binaire(yyvsp[-1].entier,yyvsp[-2].exp,yyvsp[0].exp); ;
    break;}
case 152:
#line 339 "pascal.y"
{ yyval.entier=EEgal; ;
    break;}
case 153:
#line 340 "pascal.y"
{ yyval.entier=EInf_s; ;
    break;}
case 154:
#line 341 "pascal.y"
{ yyval.entier=ESup_s; ;
    break;}
case 155:
#line 342 "pascal.y"
{ yyval.entier=EInf; ;
    break;}
case 156:
#line 343 "pascal.y"
{ yyval.entier=ESup; ;
    break;}
case 157:
#line 344 "pascal.y"
{ yyval.entier=EDiff; ;
    break;}
case 158:
#line 345 "pascal.y"
{ yyval.entier=EIn; ;
    break;}
case 159:
#line 348 "pascal.y"
{ yyval.exp=yyvsp[0].exp; ;
    break;}
case 160:
#line 349 "pascal.y"
{ yyval.exp=creer_exp_unaire(EPlus_u,yyvsp[0].exp); ;
    break;}
case 161:
#line 350 "pascal.y"
{ yyval.exp=creer_exp_unaire(EMoins_u,yyvsp[0].exp); ;
    break;}
case 162:
#line 352 "pascal.y"
{ yyval.exp=creer_exp_binaire(yyvsp[-1].entier,yyvsp[-2].exp,yyvsp[0].exp); ;
    break;}
case 163:
#line 354 "pascal.y"
{ yyval.entier=EPlus; ;
    break;}
case 164:
#line 355 "pascal.y"
{ yyval.entier=EMoins; ;
    break;}
case 165:
#line 356 "pascal.y"
{ yyval.entier=EOr; ;
    break;}
case 166:
#line 359 "pascal.y"
{ yyval.exp=yyvsp[0].exp; ;
    break;}
case 167:
#line 361 "pascal.y"
{ yyval.exp=creer_exp_binaire(yyvsp[-1].entier,yyvsp[-2].exp,yyvsp[0].exp); ;
    break;}
case 168:
#line 363 "pascal.y"
{ yyval.entier=EFois; ;
    break;}
case 169:
#line 364 "pascal.y"
{ yyval.entier=EDiv_r; ;
    break;}
case 170:
#line 365 "pascal.y"
{ yyval.entier=EDiv; ;
    break;}
case 171:
#line 366 "pascal.y"
{ yyval.entier=EMod; ;
    break;}
case 172:
#line 367 "pascal.y"
{ yyval.entier=EAnd; ;
    break;}
case 173:
#line 371 "pascal.y"
{ yyval.exp=creer_exp_var(yyvsp[0].text); ;
    break;}
case 174:
#line 372 "pascal.y"
{yyval.exp=yyvsp[0].exp;;
    break;}
case 175:
#line 373 "pascal.y"
{ yyval.exp=yyvsp[-1].exp; ;
    break;}
case 176:
#line 375 "pascal.y"
{ yyval.exp=NULL; ;
    break;}
case 177:
#line 376 "pascal.y"
{ yyval.exp=creer_exp_unaire(ENot,yyvsp[0].exp);; ;
    break;}
case 178:
#line 380 "pascal.y"
{ yyval.exp=yyvsp[0].exp; ;
    break;}
case 179:
#line 382 "pascal.y"
{ yyval.exp=creer_exp_string(yyvsp[0].text); ;
    break;}
case 180:
#line 383 "pascal.y"
{ yyval.exp=creer_exp_nil(); ;
    break;}
case 181:
#line 384 "pascal.y"
{ yyval.exp=creer_exp_true(); ;
    break;}
case 182:
#line 385 "pascal.y"
{ yyval.exp=creer_exp_false(); ;
    break;}
case 188:
#line 400 "pascal.y"
{;
    break;}
case 189:
#line 402 "pascal.y"
{;
    break;}
case 190:
#line 407 "pascal.y"
{ yyval.text=yyvsp[-1].text; ;
    break;}
case 191:
#line 409 "pascal.y"
{ yyval.text=NULL; ;
    break;}
case 192:
#line 411 "pascal.y"
{ yyval.text=NULL; ;
    break;}
case 193:
#line 413 "pascal.y"
{ yyval.text=NULL; ;
    break;}
case 194:
#line 415 "pascal.y"
{ yyval.exp=ajoute_exp(yyvsp[-2].exp,yyvsp[0].exp); ;
    break;}
case 195:
#line 416 "pascal.y"
{ yyval.exp=yyvsp[0].exp; ;
    break;}
case 196:
#line 418 "pascal.y"
{;
    break;}
case 197:
#line 420 "pascal.y"
{ yyval.text=yyvsp[0].text; ;
    break;}
case 198:
#line 423 "pascal.y"
{ 
			if(param_level<2)
			    printf("%s\t%s\n", its_a, lastident);
			yyval.text=yyvsp[0].text;
		    ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/dev/env/DJDIR/share/bison.simple"

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

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 429 "pascal.y"
   /*start of routines*/

yyerror(msg) char *msg;
{
    if(msg==NULL || *msg=='\0')
	fprintf(stderr, "Error at %s near line %d\n",
				token_name(yychar), yylineno);
    else
	fprintf(stderr, "Error at %s near line %d : %s\n",
				token_name(yychar), yylineno, msg);
    exit(1);
    return 0;
}

void parser_info(void)
{
    printf("\n%d line%s parsed\n", yylineno, plural(yylineno));
}


void internal_error(char *s,int a1,int a2,int a3,int a4)
{
    fprintf(stderr, "Internal error: ");
    fprintf(stderr, s, a1, a2, a3, a4);
    exit(2);
}

void warning(char *fmt,int a1,int a2,int a3,int a4)
{
    fprintf(stderr, "Warning line %d: ", yylineno);
    fprintf(stderr, fmt, a1, a2, a3, a4);
    fprintf(stderr, "\n");
}

int main(int argc,char *argv[])
{
	int res_parse,res_verif,res_genere;
	
	//temp_debut=clock();
	DEBUT(temp_clock);
	if(argc==2)
	{
		yyin=fopen(argv[1],"r");
		if(yyin==NULL)
		{
			printf("Erreur:impossible d'ouvrir le fichier %s\n",argv[1]);
			return 1;
		}
	}
	
	DEBUT(parse_var);
	initialise_table_symbol();
	res_parse=yyparse();
	FIN(parse_var,"duree parse");
	if(res_parse==0)
	{
		affiche(res);
		printf("correcte\n");
		initialise_table_type();
		DEBUT(verif_var);
		res_verif=verification(res);
		FIN(verif_var,"temps verification");
		if(res_verif==0)
		{
			printf("Pas d'erreur sementique\n");
			DEBUT(genere_var);
			res_genere=genere(res);
			FIN(genere_var,"temps generation + linkage");
			if(res_genere==0)
			{
				printf("Pas d'erreur durant la generation\n"
					"Compilation reussi !!!\n");
				affiche_table_symbol();
			}
			else
			{
				printf("Erreurs durant la generation\n");
			}
		}
		else
		{
			printf("Erreur dans le programme\n");
		}
		efface_table_type();
	}
	else
	{
		printf("erreurs syntaxiques\n");
	}

	efface_table_symbol();
	//temp_fin=clock();
	//printf("temp total = %d secondes\n",(int)((temp_fin-temp_debut)/CLOCKS_PER_SEC));
	FIN(temp_clock,"temp total")
	
	return 0;
}