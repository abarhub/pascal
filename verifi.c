#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include"arbre.h"
#include"creer_arbre.h"
#include"table_symbol.h"
#include"type.h"

SArbre *arbre=NULL;
static int nb_erreurs=0;

void type_correct(SType *type)
{
	assert(type!=NULL);
	switch(type->code)
	{
	case SType_simple:
		assert( (stricmp(type->nom,"integer")==0) 
			||(stricmp(type->nom,"real")==0)
			||(stricmp(type->nom,"boolean")==0)
			||(stricmp(type->nom,"character")==0)
			||(stricmp(type->nom,"string")==0));
		break;
	case SType_nil:
		break;
	default:
		printf("Type inconnue\n");
		nb_erreurs++;
		return;
	}
}

int type_compatible(SType *t1,SType *t2)
{
	type_correct(t1);
	type_correct(t2);
	switch(t1->code)
	{
		case SType_simple:
			if(stricmp(t1->nom,t2->nom)==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case SType_nil:
			if(t2->code==SType_nil)
				return 1;
			else
				return 0;
		default:
			printf("code inconnue\n");
			nb_erreurs++;
			return -1;
	}
}

SListe_declare_var *donne_decl_var(SExpr *var)
{
	SListe_declare_var *tmp;
	SDeclare *decl;
	
	assert(var!=NULL);
	assert(var->nom!=NULL&&var->nom[0]!='\0');
	assert(var->code==EVar);
	assert(arbre!=NULL);
	
	decl=arbre->declare;
	while(decl!=NULL)
	{
		if(decl->code==EDecl_var)
		{
			tmp=decl->var;
			while(tmp!=NULL)
			{
				if(stricmp(tmp->nom,var->nom)==0)
				{
					type_correct(tmp->type);
					return tmp;
				}
				tmp=tmp->suivant;
			}
		}
		decl=decl->suivant;
	}
	return NULL;
}

static SType *type_exp(SExpr *exp)
{
	SType *type1,*type2;
	SListe_declare_var *var;
	
	assert(exp!=NULL);
	switch(exp->code)
	{
		case EEgal:
		case EInf:
		case ESup:
		case EInf_s:
		case ESup_s:
		case EDiff:
			type1=type_exp(exp->exp1);
			type2=type_exp(exp->exp2);
			if(type1==NULL)
				return NULL;
			if(type2==NULL)
				return NULL;
			if(!type_compatible(type1,type2))
			{
				printf("Type incompatible pour le biop\n");
				nb_erreurs++;
				return NULL;
			}
			return creer_type_simple("boolean");
			//break;
		case EPlus_u:
		case EMoins_u:
			type1=type_exp(exp->exp1);
			if(type1==NULL)
				return NULL;
			if(type1->code==SType_simple&&
				(stricmp(type1->nom,"integer")==0||
					stricmp(type1->nom,"real")==0))
			{
				return type1;
			}
			else
			{
				printf("Type incompatible unop\n");
				nb_erreurs++;
				return NULL;
			}
			//break;
		case EPlus:
		case EMoins:
		case EFois:
		case EDiv:
		case EDiv_r:
		case EMod:
			type1=type_exp(exp->exp1);
			type2=type_exp(exp->exp2);
			if(type1==NULL)
				return NULL;
			if(type2==NULL)
				return NULL;
			if(!type_compatible(type1,type2))
			{
				printf("Type incompatible pour le pmfd\n");
				nb_erreurs++;
				return NULL;
			}
			else if(type1->code==SType_simple&&
				(stricmp(type1->nom,"integer")==0||
					stricmp(type1->nom,"real")==0))
				return type1;
			else
			{
				printf("Type incompatible faut int ou real\n");
				nb_erreurs++;
				return NULL;
			}
		case EOr:
		case EAnd:
			type1=type_exp(exp->exp1);
			type2=type_exp(exp->exp2);
			if(type1==NULL)
				return NULL;
			if(type2==NULL)
				return NULL;
			if(!type_compatible(type1,type2))
			{
				printf("Type incompatible pour le and or\n");
				nb_erreurs++;
				return NULL;
			}
			else if(type1->code==SType_simple&&
				stricmp(type1->nom,"boolean")==0)
				return type1;
			else
			{
				printf("Type incompatible bool or\n");
				nb_erreurs++;
				return NULL;
			}
		case ENot:
			type1=type_exp(exp->exp1);
			if(type1==NULL)
				return NULL;
			if(type1->code==SType_simple&&
				stricmp(type1->nom,"boolean")==0)
				return type1;
			else
			{
				printf("Type incompatible pour le not\n");
				nb_erreurs++;
				return NULL;
			}
		case EEntier:
			return creer_type_simple("integer");
		case EReel:
			return creer_type_simple("real");
		case EVar:
			var=donne_decl_var(exp);
			if(var==NULL)
			{
				printf("Erreur:variable %s non declare\n",exp->nom);
				return NULL;
			}
			return var->type;
		case EIn:
			printf("In non gere\n");
			nb_erreurs++;
			return creer_type_simple("boolean");
		case ENil:
			type1=(SType *)malloc(sizeof(SType));
			type1->code=SType_nil;
			return type1;
		case EString:
			return creer_type_simple("string");
		case ETrue:
			return creer_type_simple("boolean");
		case EFalse:
			return creer_type_simple("boolean");
		default:
			printf("Erreur: code d'expression inconnue\n");
			nb_erreurs++;
			return NULL;
	}
}

int verifi_exp(SExpr *exp,SType *type)
{
	SType *t;
	assert(exp!=NULL);
	assert(type!=NULL);
	t=type_exp(exp);
	if(t==NULL)
		return 1;
	if(type_compatible(t,type)!=1)
	{
		//printf("Erreur:Type incompatible pour le exp\n");
		//nb_erreurs++;
		return 1;
	}
	return 0;
}

void verifi_bloc(SListe_instr *instr)
{
	SListe_declare_var *var1,*var2;
	SType type={SType_simple,"boolean"},type2={SType_simple,"string"};
	
	while(instr!=NULL)
	{
		switch(instr->code)
		{
			case EAffect:
				var1=donne_decl_var(instr->var);
				if(var1==NULL)
				{
					printf("Erreur: variable %s nom declare\n",
						instr->var->nom);
					nb_erreurs++;
					return;
				}
				verifi_exp(instr->exp,var1->type);
				break;
			case EIf:
				verifi_exp(instr->exp,&type);
				verifi_bloc(instr->ok);
				verifi_bloc(instr->pas_ok);
				break;
			case EWhile:case ERepeat:
				verifi_exp(instr->exp,&type);
				verifi_bloc(instr->ok);				
				break;
			case EGoto:
				
				break;
			case EAppel_proc:
			      if(stricmp(instr->nom_proc,"write")!=0)
				{
					printf("Erreur:Seul la procedure write est connue\n");
					nb_erreurs++;
					return;
				}
				if(instr->exp==NULL)
				{
					printf("Erreur: write a au moins 1 argument\n");
					nb_erreurs++;
					return;
				}
				//verifi_exp(instr->exp,&type);
				break;
			case EBloc:
				verifi_bloc(instr->ok);
				break;
			default:
				printf("Erreur:code inconnue\n");
				nb_erreurs++;
				return;
		}
		instr=instr->suivant;
	}
}

static char *str_nom=NULL;
static char *str_nom_fonc=NULL;

int var_doublee(STable_symbol *symbol)
{
	assert(symbol!=NULL);
	assert(str_nom!=NULL);
	
	if((symbol->code==EGlobal)&&
		(stricmp(symbol->nom,str_nom)==0))
	{
		printf("Erreur: la variable %s est declaree au moins 2 fois\n",
				symbol->nom);
		return 1;
	}
	return 0;
}

int verification(SArbre *arbre1)
{
	SDeclare *tmp1;
	SListe_declare_var *tmp2;
	
	assert(arbre1!=NULL);
	
	arbre=arbre1;nb_erreurs=0;
	
	if(arbre->nom_prog==NULL||(arbre->nom_prog)[0]=='\0')
	{
		nb_erreurs++;
		printf("Erreur: Il faut un nom de programme\n");
		return 1;
	}
	
	tmp1=arbre1->declare;
	while(tmp1!=NULL)
	{
		tmp2=tmp1->var;
		while(tmp2!=NULL)
		{
			assert(tmp2->type!=NULL);
			//assert(tmp2->type.!=NULL);
			str_nom=strdup(tmp2->nom);
			if(parcourt_tsymb2(var_doublee)!=0)
			{
				free(str_nom);
				str_nom=NULL;
				return 1;
			}
			ajoute_nom_tsymb(str_nom,conv_type_pascal(tmp2->type->nom),NULL);
			str_nom=NULL;
			tmp2=tmp2->suivant;
		}
		tmp1=tmp1->suivant;
	}

	verifi_bloc(arbre->pprincipal);
	
	return nb_erreurs;
}