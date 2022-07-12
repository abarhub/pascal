%{
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

%}

%union {
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
}

%start program

%token <entier> UNSIGNED_INT 
%token <reel> UNSIGNED_REAL 
%token <text> STRING IDENTIFIER
%token NE LE GE BECOMES DIV MOD NIL IN OR AND NOT DOTDOT
%token IF THEN ELSE CASE OF REPEAT UNTIL WHILE DO FOR TO DOWNTO
%token SBEGIN END WITH GOTO CONST VAR TYPE ARRAY RECORD SET SFILE FUNCTION
%token PROCEDURE LABEL PACKED PROGRAM TRUE FALSE

%type <text> newident ident variable newident label
%type <instr> statement_part compound_stmt statements statement assignment
%type <instr> procedure_call
%type <exp> expression simple_expr term constant unsigned_num actual_params
%type <entier> relational_op add_op mult_op
%type <exp> factor unsigned_lit expressions actuals_list actual_param
%type <type> type simple_type 
%type <decl_var> var_dcl_part variable_dcls variable_dcl new_id_list newident_list
%type <declare> declaration declarations opt_declarations
%type <couple> block

%%   /*start of rules*/
program		: PROGRAM {its_a="program";} newident external_files ';' 
			block '.' 
			{ res=creer_arbre($3,(SDeclare *)($6)[0],
				(SListe_instr *)($6)[1]); }
		;
external_files  : /*empty*/
		| '(' {its_a="external-file";} newident_list ')'
		;

block		: opt_declarations  statement_part	
			{$$=creer_couple($<generique>1,$<generique>2);}
		;
opt_declarations: /*empty*/	{$$=NULL;}
		| declarations	{$$=$1;}
		;
declarations	: declarations declaration	/*should be left-recursive*/
			{ $$=ajoute_declare($1,$2); }
		| declaration	{$$=$1;}
		;
declaration	: label_dcl_part	{}
		| const_dcl_part	{}
		| type_dcl_part	{}
		| var_dcl_part	{ $$=creer_declare_var($1); }
		| proc_dcl_part	{}
		;

label_dcl_part	: LABEL labels ';'
		;
labels		: labels ',' label
		| label	{}
		;
label		: UNSIGNED_INT		/* 0 <= value <= 9999 [6.1.6] */
		{ $$=strdup(itoa($1,NULL,10)); }
		;

const_dcl_part	: CONST const_defs ';'
		;
const_defs	: const_defs ';' const_def
		| const_def
		;
const_def	: {its_a="constant";} newident '=' constant
		;

constant	: unsigned_num	{$$=$1;}
		| '+' unsigned_num	{$$=creer_exp_unaire(EPlus_u,$2);}
		| '-' unsigned_num	{$$=creer_exp_unaire(EMoins_u,$2);}
		| ident				/*check it is constant*/
				{$$=creer_exp_var($1);}
		| '+' ident
			{$$=creer_exp_unaire(EPlus_u,creer_exp_var($2));}
		| '-' ident
			{$$=creer_exp_unaire(EMoins_u,creer_exp_var($2));}
		| STRING			/*type is char if len=1*/
			{$$=creer_exp_string($1);}
		;

unsigned_num	: UNSIGNED_INT	{$$=creer_exp_entier($1);}
		| UNSIGNED_REAL		{$$=creer_exp_reel($1);}
		;

type_dcl_part	: TYPE type_defs ';'
		;
type_defs	: type_defs ';' type_def
		| type_def
		;
type_def	: {its_a="type";} newident '=' type
		;

type		: simple_type	{ $$=$1;}
		| PACKED struct_type	{}
		| struct_type		{}
		| '^' IDENTIFIER    /*check forward reference semantics*/
			{}
		;

simple_type	: '(' {its_a="enumerated-literal";} newident_list ')'
			{}
		| constant DOTDOT constant	{}
		| ident			{ $$=creer_type_simple($1); }
		;

struct_type	: ARRAY '[' index_t_list ']' OF type
		| RECORD /*consider this a scope*/ field_list END
		| SET OF simple_type
		| SFILE OF type
		;
index_t_list	: index_t_list ',' simple_type	{}
		| simple_type	{}
		;
field_list	: fixed_part
		| fixed_part ';' variant_part
		| variant_part
		;
fixed_part	: fixed_part ';' record_section
		| record_section
		;
record_section	: {its_a="field";} newident_list ':' type
		| /*empty*/
		;
variant_part	: CASE {its_a="field";} tag_field OF variants
		;
tag_field	: newident ':' ident {}
		| ident /*type*/		{}
		;
variants	: variants ';' variant
		| variant
		;
variant		: case_label_list ':' '(' field_list ')'
		| /*empty*/
		;

var_dcl_part	: VAR variable_dcls ';'		{ $$=$2;}
		;
variable_dcls	: variable_dcls ';' variable_dcl
				{ $$=ajoute_decl_var($1,$3); }
		| variable_dcl	{ $$=$1; }
		;
variable_dcl	: {its_a="variable";} newident_list ':' type
			{ $$=ajoute_var_type($2,$4); }
		;
newident_list	: new_id_list {its_a="don't know";}
			{ $$=$1; }
		;
new_id_list	: new_id_list ',' newident	
			{ $$=ajoute_decl_var($1,creer_decl_var($3)); }
		| newident	
			{ $$=creer_decl_var($1); }
		;

proc_dcl_part	: proc_or_func
		;
proc_or_func	: proc_heading ';' body ';'     /*check if forward or fwd refd*/
			{lexical_level--;
			}
		| func_heading ';' body ';'  /*also func heading may be -type */
			{lexical_level--;
			}
		;
proc_heading	: PROCEDURE
			{if(param_level==0)its_a="procedure";}
		  newident {lexical_level++;}
			formal_params
		;
func_heading	: FUNCTION
			{if(param_level==0)its_a="function";}
		  newident {lexical_level++;}
			function_form
		;
function_form	: /*empty*/			/*if forward referenced*/
		| formal_params ':' ident
		;

body		: block
			/* result determined in block */
			{}
		| IDENTIFIER				/*directive-FORWARD*/
			{}
		;
formal_params	: /*empty*/
		| '(' {param_level++;} formal_p_sects ')' {param_level--;}
		;
formal_p_sects	: formal_p_sects ';' formal_p_sect
		| formal_p_sect
		;
formal_p_sect	: {its_a="value-parameter";} param_group
		| VAR {its_a="var-parameter";} param_group
		| {its_a="procedure-parameter";} proc_heading
			{lexical_level--;}
		| {its_a="function-parameter";} func_heading  {lexical_level--;}
		;
param_group	: newident_list ':' paramtype
			{}
		;
paramtype	: ident	{}
		| ARRAY '[' index_specs ']' OF paramtype
			{}
		| PACKED ARRAY '[' index_spec ']' OF ident
			{}
		;
index_specs	: index_specs ';' index_spec
		| index_spec
		;
index_spec	: {its_a="conformant-bound";} newident DOTDOT newident ':' ident
		;

statement_part	: compound_stmt	{$$=$1;}
		;
compound_stmt	: SBEGIN statements END	{ $$=instr_bloc($2,NULL); }
		;
statements	: statements ';' statement	{ $$=ajoute_instr($1,$3); }
		| statement		{ $$=$1 }
		;
statement	: /*empty*/		{ $$=NULL; }
		| label ':' statement	{ $$=ajoute_instr_label($3,$1); }
		| compound_stmt	{ $$=$1; }
		| assignment	{ $$=$1; }
		| procedure_call	{ $$=$1; }
		| GOTO label	{ $$=instr_goto($2,NULL); }
		| IF expression THEN statement	
			{ $$=instr_if($2,$4,NULL,NULL); }
		| IF expression THEN statement ELSE statement
			{ $$=instr_if($2,$4,$6,NULL); }
		| CASE expression OF case_list END
			{ $$=NULL; }
		| WHILE expression DO statement
			{ $$=instr_while($2,$4,NULL); }
		| REPEAT statements UNTIL expression
			{ $$=instr_repeat($4,$2,NULL); }
		| FOR ident BECOMES expression direction expression DO statement
			{ $$=NULL; }
		| WITH rec_var_list DO statement 
			{ $$=NULL; }
		;
direction	: TO
		| DOWNTO
		;

assignment	: variable BECOMES expression	/* must test for fn_ident */
			{ $$=instr_affect(creer_exp_var($1),$3,NULL); }
	/*	| ident BECOMES expression	*/
		;

procedure_call	: ident actual_params
			{ $$=instr_appel($1,$2,NULL); }
		;

actual_params	:  /*empty*/	{ $$=NULL; }
		| '(' actuals_list ')'
			{ $$=$2; }
		;
actuals_list	: actuals_list ',' actual_param	{$$=ajoute_exp($1,$3);}
		| actual_param	{$$=$1}
		;
actual_param	: expression    /* which could be a variable or a proc/fn id */
			{$$=$1;}
		| expression colon_things  /* only in i/o */
			{$$=$1;}
		;
colon_things    : ":" expression	/*integer*/
		| ":" expression ":" expression 
		;

case_list	: case_list ';' case_list_elem
		| case_list_elem
		;
case_list_elem	: case_label_list ':' statement
		| /*empty*/
		;
case_label_list	: case_label_list ',' case_label
		| case_label
		;
case_label	: constant	{}
		;

rec_var_list	: rec_var_list ',' record_var
		| record_var
		;

expression	: simple_expr	{ $$=$1; }
		| simple_expr relational_op simple_expr
			{ $$=creer_exp_binaire($2,$1,$3); }
		;
relational_op	: '='	{ $$=EEgal; }
		| '<'		{ $$=EInf_s; }
		| '>'		{ $$=ESup_s; }
		| LE		{ $$=EInf; }
		| GE		{ $$=ESup; }
		| NE		{ $$=EDiff; }
		| IN		{ $$=EIn; }
		;

simple_expr	: term	{ $$=$1; }
		| '+' term	{ $$=creer_exp_unaire(EPlus_u,$2); }
		| '-' term	{ $$=creer_exp_unaire(EMoins_u,$2); }
		| simple_expr add_op term
				{ $$=creer_exp_binaire($2,$1,$3); }
		;
add_op		: '+'	{ $$=EPlus; }
		| '-'		{ $$=EMoins; }
		| OR		{ $$=EOr; }
		;

term		: factor	{ $$=$1; }
		| term mult_op factor
				{ $$=creer_exp_binaire($2,$1,$3); }
		;
mult_op		: '*'	{ $$=EFois; }
		| '/'		{ $$=EDiv_r; }
		| DIV		{ $$=EDiv; }
		| MOD		{ $$=EMod; }
		| AND		{ $$=EAnd; }
		;

factor		: variable		/* could be a const_ident of fn_call*/
			{ $$=creer_exp_var($1); }
		| unsigned_lit		{$$=$1;}
		| '(' expression ')'	{ $$=$2; }
	/*	| function_call		*/
		| set			{ $$=NULL; }
		| NOT factor	{ $$=creer_exp_unaire(ENot,$2);; }
		;

unsigned_lit	: unsigned_num	
				{ $$=$1; }
		| STRING			/*type is char if len=1*/
				{ $$=creer_exp_string($1); }
		| NIL		{ $$=creer_exp_nil(); }
		| TRUE		{ $$=creer_exp_true(); }
		| FALSE		{ $$=creer_exp_false(); }
		;
/*
function_call	: ident actual_params
		;
*/

set		: '[' member_list ']'
		;
member_list	: /*empty*/
		| members
		;
members		: members ',' member
		| member
		;
member		: expression	{}
		| expression DOTDOT expression
			{}
		;

/* kludge */
variable	: ident actual_params	/* check variable, const_id, fn_call */
			{ $$=$1; }
		| variable '[' expressions ']'
			{ $$=NULL; }
		| variable '.' ident
			{ $$=NULL; }
		| variable '^'
			{ $$=NULL; }
		;
expressions	: expressions ',' expression	{ $$=ajoute_exp($1,$3); }
		| expression	{ $$=$1; }
		;
record_var	: variable	{}
		;
ident		: IDENTIFIER	{ $$=$1; }
		;
newident	: IDENTIFIER
		    { 
			if(param_level<2)
			    printf("%s\t%s\n", its_a, lastident);
			$$=$1;
		    }
		;
%%   /*start of routines*/

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