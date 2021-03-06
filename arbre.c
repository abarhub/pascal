#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"arbre.h"
#include"table_symbol.h"

void **creer_couple(void *a,void *b)
{
	void **tmp;
	
	tmp=(void**)calloc(sizeof(void*),2);
	//((void*)tmp)[0]=a;
	//((void*)tmp)[1]=b;
	tmp[0]=a;
	tmp[1]=b;
	return tmp;
}

SType *creer_type_simple(char *nom)
{
	SType *tmp;
	
	tmp=(SType*)malloc(sizeof(SType));
	tmp->code=SType_simple;
	tmp->nom=nom;
	
	return tmp;
}

SListe_declare_var *creer_decl_var(char *nom)
{
	SListe_declare_var *tmp;
	
	tmp=(SListe_declare_var *)malloc(sizeof(SListe_declare_var));
	tmp->suivant=NULL;
	tmp->nom=nom;
	tmp->type=NULL;
	
	return tmp;
}

SListe_declare_var *ajoute_var_type(SListe_declare_var *var,SType *type)
{
	SListe_declare_var *tmp;
	
	tmp=var;
	assert(type!=NULL);
	assert(var!=NULL&&var->type==NULL);
	while(tmp!=NULL&&tmp->type==NULL)
	{
		tmp->type=type;
		tmp=tmp->suivant;
	}
	return var;
}

SListe_declare_var *ajoute_decl_var(SListe_declare_var *liste,
	SListe_declare_var *var)
{
	SListe_declare_var *tmp;
	
	if(var==NULL)
		return liste;
	else
	{
		tmp=var;
		while(tmp->suivant!=NULL) tmp=tmp->suivant;
		tmp->suivant=liste;
		return var;
	}
}

SDeclare *creer_declare_type(SType *type)
{
	SDeclare *tmp;
	
	tmp=(SDeclare *)malloc(sizeof(SDeclare));
	tmp->suivant=NULL;
	tmp->type=type;
	tmp->code=EType;
	
	return tmp;
}

SDeclare *creer_declare_var(SListe_declare_var *var)
{
	SDeclare *tmp;
	
	tmp=(SDeclare *)malloc(sizeof(SDeclare));
	tmp->suivant=NULL;
	tmp->var=var;
	tmp->code=EDecl_var;
	
	return tmp;
}

SDeclare *creer_proc_fonct(char *nom)
{
	SDeclare *tmp;
	
	assert(nom!=NULL);
	tmp=(SDeclare *)malloc(sizeof(SDeclare));
	tmp->suivant=NULL;
	//tmp->var=var;
	tmp->code=EProc_fonct;
	tmp->type=NULL;
	tmp->nom=nom;
	
	return tmp;
}

void complete_proc_fonct(SProc_fonct *elt,SListe_instr *instr)
{
	assert(elt!=NULL);
	
	elt->instr=instr;
}

SDeclare *ajoute_declare(SDeclare *liste,SDeclare *elt)
{
	SDeclare *tmp;
	
	if(liste==NULL)
		return elt;
	else
	{
		tmp=liste;
		while(tmp->suivant!=NULL) tmp=tmp->suivant;
		tmp->suivant=elt;
		return liste;
	}
}

SExpr *creer_exp_binaire(enum ECode_exp code,SExpr *e1,SExpr *e2)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=code;
	tmp->exp1=e1;
	tmp->exp2=e2;
	tmp->suivant=NULL;
	return tmp;
}

SExpr *creer_exp_unaire(enum ECode_exp code,SExpr *e)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=code;
	tmp->exp1=e;
	tmp->exp2=NULL;
	tmp->suivant=NULL;
	return tmp;
}

SExpr *creer_exp_entier(int val)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=EEntier;
	tmp->exp1=NULL;
	tmp->exp2=NULL;
	tmp->entier=val;
	tmp->suivant=NULL;
	return tmp;
}

SExpr *creer_exp_reel(double val)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=EReel;
	tmp->exp1=NULL;
	tmp->exp2=NULL;
	tmp->reel=val;
	tmp->suivant=NULL;
	return tmp;
}

SExpr *creer_exp_var(char *nom)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=EVar;
	tmp->exp1=NULL;
	tmp->exp2=NULL;
	tmp->nom=nom;
	tmp->suivant=NULL;
	return tmp;
}

SExpr *creer_exp_string(char *nom)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=EString;
	tmp->exp1=NULL;
	tmp->exp2=NULL;
	tmp->nom=nom;
	tmp->suivant=NULL;
	return tmp;
}


SExpr *creer_exp_nil(void)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=ENil;
	tmp->exp1=NULL;
	tmp->exp2=NULL;
	tmp->suivant=NULL;
	return tmp;
}


SExpr *creer_exp_true(void)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=ETrue;
	tmp->exp1=NULL;
	tmp->exp2=NULL;
	tmp->suivant=NULL;
	return tmp;
}


SExpr *creer_exp_false(void)
{
	SExpr *tmp;

	tmp=(SExpr*)malloc(sizeof(SExpr));
	tmp->code=EFalse;
	tmp->exp1=NULL;
	tmp->exp2=NULL;
	tmp->suivant=NULL;
	return tmp;
}


SExpr *ajoute_exp(SExpr *liste,SExpr *e)
{
	SExpr *tmp;
	
	if(liste==NULL) 
		return e;
	else
	{
		if(e==NULL) return liste;
		tmp=liste;
		while(tmp->suivant!=NULL) tmp=tmp->suivant;
		tmp->suivant=e;
		return tmp;
	}
}

SListe_instr *instr_affect(SExpr *var,SExpr *exp,char *label)
{
	SListe_instr *instr;
	
	instr=(SListe_instr *)malloc(sizeof(SListe_instr));
	instr->code=EAffect;
	instr->label=label;
	instr->var=var;
	instr->exp=exp;
	instr->suivant=NULL;
	
	return instr;
}

SListe_instr *instr_if(SExpr *exp,SListe_instr *ok,SListe_instr *pas_ok,char *label)
{
	SListe_instr *instr;
	
	instr=(SListe_instr *)malloc(sizeof(SListe_instr));
	instr->code=EIf;
	instr->label=label;
	instr->ok=ok;
	instr->exp=exp;
	instr->pas_ok=pas_ok;
	instr->suivant=NULL;
	
	return instr;
}

SListe_instr *instr_while(SExpr *exp,SListe_instr *ok,char *label)
{
	SListe_instr *instr;
	
	instr=(SListe_instr *)malloc(sizeof(SListe_instr));
	instr->code=EWhile;
	instr->label=label;
	instr->ok=ok;
	instr->exp=exp;
	instr->pas_ok=NULL;
	instr->suivant=NULL;
	
	return instr;
}

SListe_instr *instr_repeat(SExpr *exp,SListe_instr *ok,char *label)
{
	SListe_instr *instr;
	
	instr=(SListe_instr *)malloc(sizeof(SListe_instr));
	instr->code=ERepeat;
	instr->label=label;
	instr->ok=ok;
	instr->exp=exp;
	instr->pas_ok=NULL;
	instr->suivant=NULL;
	
	return instr;
}


SListe_instr *instr_goto(char *vers_label,char *label)
{
	SListe_instr *instr;
	
	instr=(SListe_instr *)malloc(sizeof(SListe_instr));
	instr->code=EGoto;
	instr->label=label;
	instr->va_label=vers_label;
	instr->suivant=NULL;
	
	return instr;
}

SListe_instr *instr_appel(char *nom_proc,SExpr *param,char *label)
{
	SListe_instr *instr;
	
	instr=(SListe_instr *)malloc(sizeof(SListe_instr));
	instr->code=EAppel_proc;
	instr->label=label;
	instr->nom_proc=nom_proc;
	instr->exp=param;
	instr->suivant=NULL;
	
	return instr;
}

SListe_instr *instr_bloc(SListe_instr *liste,char *label)
{
	SListe_instr *instr;
	
	instr=(SListe_instr *)malloc(sizeof(SListe_instr));
	instr->code=EBloc;
	instr->label=label;
	instr->ok=liste;
	instr->suivant=NULL;
	
	return instr;
}

SListe_instr *ajoute_instr(SListe_instr *liste,SListe_instr *instr)
{
	SListe_instr *tmp;
	
	if(liste==NULL)
		return instr;
	else
	{
		if(instr==NULL) return liste;
		tmp=liste;
		while(tmp->suivant!=NULL) tmp=tmp->suivant;
		tmp->suivant=instr;
		return liste;
	}
}

SListe_instr *ajoute_instr_label(SListe_instr *instr,char *label)
{
	if(instr==NULL)
		return NULL;
	else
	{
		instr->label=label;
		return instr;
	}
}


SArbre *creer_arbre(char *nom_prog,SDeclare *decl,SListe_instr *prog_principal)
{
	SArbre *arbre;
	
	arbre=(SArbre *)malloc(sizeof(SArbre));
	arbre->nom_prog=nom_prog;
	arbre->pprincipal=prog_principal;
	arbre->declare=decl;
	return arbre;
}

/* affiche */

void affiche_type(SType *type)
{
	assert(type!=NULL);
	switch(type->code)
	{
		case SType_simple:
			printf("%s",type->nom);
			break;
		default:
			printf("Code %d inconnue\n",type->code);
			assert(1);
	}
}

void affiche_decl_var(SListe_declare_var *liste)
{
	SListe_declare_var *tmp;
	
	tmp=liste;
	while(tmp!=NULL)
	{
		printf("%s:",tmp->nom);
		affiche_type(tmp->type);
		printf(";\n");
		tmp=tmp->suivant;
	}
}

void affiche_declare(SDeclare *decl)
{
	SDeclare *tmp;
	
	tmp=decl;
	while(tmp!=NULL)
	{
		switch(tmp->code)
		{
			case EType:
				assert(1);
			case EDecl_var:
				printf("Var ");
				affiche_decl_var(tmp->var);
				break;
			default:
				printf("Erreur: code %d inconnue\n");
				assert(1);
				return;
		}
		tmp=tmp->suivant;
	}
}

/*int prio(enum ECode_exp code)
{
	//switch()
}

int est_plus_prio(enum ECode_exp code1, enum ECode_exp code2)
{
	
}*/

void affiche_exp(SExpr *exp)
{
	SExpr *tmp;
	
	tmp=exp;
	while(exp!=NULL)
	{
		switch(tmp->code)
		{
			case EEgal:
				printf("(");
				affiche_exp(exp->exp1);
				printf("=");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EInf:
				printf("(");
				affiche_exp(exp->exp1);
				printf("<=");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case ESup:
				printf("(");
				affiche_exp(exp->exp1);
				printf(">=");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EInf_s:
				printf("(");
				affiche_exp(exp->exp1);
				printf("<");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case ESup_s:
				printf("(");
				affiche_exp(exp->exp1);
				printf(">");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EPlus:
				printf("(");
				affiche_exp(exp->exp1);
				printf("+");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EMoins:
				printf("(");
				affiche_exp(exp->exp1);
				printf("-");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EPlus_u:
				printf(" +");
				affiche_exp(exp->exp1);
				break;
			case EMoins_u:
				printf(" -");
				affiche_exp(exp->exp1);
				break;
			case EFois:
				printf("(");
				affiche_exp(exp->exp1);
				printf("*");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EDiv:
				printf("(");
				affiche_exp(exp->exp1);
				printf(") div (");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EOr:
				printf("(");
				affiche_exp(exp->exp1);
				printf(") or (");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EAnd:
				printf("(");
				affiche_exp(exp->exp1);
				printf(") and (");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EDiv_r:
				printf("(");
				affiche_exp(exp->exp1);
				printf("/");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case ENot:
				printf(" not (");
				affiche_exp(exp->exp1);
				printf(")");
				break;
			case EMod:
				printf("(");
				affiche_exp(exp->exp1);
				printf(") mod (");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EEntier:
				printf(" %d ",exp->entier);
				break;
			case EReel:
				printf(" %g ",exp->reel);
				break;
			case EVar:
				printf(" %s ",exp->nom);
				break;
			case EDiff:
				printf("(");
				affiche_exp(exp->exp1);
				printf("<>");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case EIn:
				printf("(");
				affiche_exp(exp->exp1);
				printf(") in (");
				affiche_exp(exp->exp2);
				printf(")");
				break;
			case ENil:
				printf("(Nil)");
				break;
			case EString:
				printf("%s",exp->nom);
				break;
			case EFalse:
				printf("false");
				break;
			case ETrue:
				printf("true");
				break;
			default:
				printf("Erreur: code d'expression %d inconnue\n",exp->code);
				return;
		}
		if(exp->suivant!=NULL)
			printf(",");
		exp=exp->suivant;
	}
}

void affiche_instr(SListe_instr *instr)
{
	SListe_instr *tmp;
	
	tmp=instr;
	/*if(tmp!=NULL&&tmp->suivant!=NULL)
		printf("begin\n");*/
	while(tmp!=NULL)
	{
		if(tmp->label!=NULL)
			printf("%s:",tmp->label);
		switch(tmp->code)
		{
			case EAffect:
				assert(tmp->var!=NULL&&tmp->var->code==EVar);
				printf("%s:=",tmp->var->nom);
				affiche_exp(tmp->exp);
				break;
			case EIf:
				printf("if ");
				affiche_exp(tmp->exp);
				printf(" then ");
				affiche_instr(tmp->ok);
				if(tmp->pas_ok!=NULL)
				{
					printf("\nelse ");
					affiche_instr(tmp->pas_ok);
				}
				printf(" endif");
				break;
			case EWhile:
				printf("while ");
				affiche_exp(tmp->exp);
				printf(" do ");
				affiche_instr(tmp->ok);
				//assert(tmp->pas_ok!=NULL)
				//printf("\nelse ");
				//affiche_instr(tmp->pas_ok);
				//}
				//printf(" endif");
				break;
			case ERepeat:
				printf("repeat ");
				affiche_instr(tmp->ok);
				printf(" until ");
				affiche_exp(tmp->exp);				
				break;
			case EGoto:
				printf("goto %s",tmp->va_label);
				break;
			case EAppel_proc:
				printf("%s(",tmp->nom_proc);
				affiche_exp(tmp->exp);
				printf(")");
				break;
			case EBloc:
				printf("Begin\n");
				affiche_instr(tmp->ok);
				printf("end");
				break;
			default:
				printf("Erreur:Code %d inconnue\n",tmp->code);
				return;
		}
		if(tmp->suivant!=NULL)
			printf(";\n");
		//else
			//printf("\n");
		tmp=tmp->suivant;
	}
	/*if(instr!=NULL&&instr->suivant!=NULL)
		printf("\nend");*/
}

void affiche(SArbre *arbre)
{
	if(arbre==NULL)
	{
		printf("Erreur: arbre null\n");
		return ;
	}
	printf("Arbre %s\n",arbre->nom_prog);
	affiche_declare(arbre->declare);
	affiche_instr(arbre->pprincipal);
	printf(".\n");
}