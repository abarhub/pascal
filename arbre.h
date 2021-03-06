#ifndef _ARBRE_H_
#define _ARBRE_H_

typedef struct SType
{
	enum ECode_type {SType_simple,SType_nil} code;
	char *nom;
} SType;

typedef struct SListe_declare_var
{
	char *nom;
	SType *type;
	int no_asm;
	struct SListe_declare_var *suivant;
} SListe_declare_var;

typedef struct SExpr
{
	enum ECode_exp {EEgal,EInf,ESup,EInf_s,ESup_s,
		EPlus,EMoins,EPlus_u,EMoins_u,EFois,EDiv,
		EOr,EAnd,EDiv_r,ENot,EMod,EEntier,EReel,
		EVar,EDiff,EIn,ENil,EString,ETrue,EFalse} code;
	char *nom;
	int entier;
	double reel;
	struct SExpr *exp1,*exp2;
	struct SExpr *suivant;
} SExpr;

typedef struct SListe_instr
{
	enum ECode_instr {EAffect,EIf,EGoto,EAppel_proc,EBloc,EWhile,ERepeat} code;
	char *label,*va_label,*nom_proc;
	SExpr *exp,*var;
	struct SListe_instr *ok,*pas_ok;
	struct SListe_instr *suivant;
} SListe_instr;

typedef struct SProc_fonct
{
	char *nom;
	SListe_instr *instr;
} SProc_fonct;

typedef struct SDeclare
{
	enum EDeclare {EType,EDecl_var,EProc_fonct} code;
	char *nom;
	SType *type;
	SListe_declare_var *var;
	//SProc_fonct *proc;
	SListe_instr *instr;
	struct SDeclare *suivant;
} SDeclare;

typedef struct SArbre
{
	char *nom_prog;
	SDeclare *declare;
	SListe_instr *pprincipal;
} SArbre;

#endif