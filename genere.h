#ifndef _GENERE_H_
#define _GENERE_H_

#include"arbre.h"

typedef struct SVar
{
	enum EIVar {EIVar,EIVal,EIReel,EIRien} code;
	int val,type;
	double reel;
} SVar;

typedef struct SInterm
{
	enum EInter {EIPlus,EIMoins,EIFois,EIDiv,EIAppel,EILabel,EIJmp,
			EISiEgal,EISiNonEgal,EISup,EIAnd,EIOr,EINot,EIMoinsu,
			EIEgal,EICopie,EISup_s,EIInf,EIInf_s,EIDiff,EIDiv_r,EIMod,
			EIXor} code;
	enum EType_instr {ETInt32,ETInt64,ETFloat32,ETFloat64,ETAutre} type_instr;
	SVar var1,var2,var3;
	char *nom;
	struct SInterm *suivant;
} SInterm;

typedef struct SBloc
{
	enum EBloc {EFonction,EPrincipal} type;
	//SDecl_var *declaration;
	char *nom;
	SInterm *code;
	struct SBloc *suivant;
} SBloc;

int genere(SArbre *arbre1);

#endif