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


extern YYSTYPE yylval;
