#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<process.h>
#include"arbre.h"
#include"genere.h"
#include"genere_asm86.h"
#include"genere_jvm.h"
#include"table_symbol.h"
#include"type.h"

static char buf_str_var[512];
static SDeclare *declare_var=NULL;
static int dernier_label=0;

static char *donne_label(void)
{
	char buf[512];
	sprintf(buf,"label_%d",dernier_label);
	dernier_label++;
	return strdup(buf);
}

static enum EType_instr type_param(SVar v1)
{
	switch(v1.code)
	{
		case EIVar:
			switch(v1.type)
			{
				case TINT:case TBOOL:
				case TCHAR:
					return ETInt32;
				case TREEL:
					return ETFloat32;
				case TSTRING:
					return ETAutre;
				case TLONG:
					return ETInt64;
				case TDOUBLE:
					return ETFloat64;
				default:
					printf("code=%d\n",v1.type);
					assert(1==0);	
			}
			break;
		case EIReel:
			return ETFloat64;
		case EIVal:
			return ETInt32;
		default:
			printf("code=%d\n",v1.code);
			assert(1==0);
	}
	return ETInt32;	
}

static SInterm *creer_int_bin(enum EInter code,SVar v1,SVar v2,SVar v3,
		enum EType_instr type_instr)
{
	SInterm *tmp;
	
	tmp=(SInterm*)malloc(sizeof(SInterm));
	tmp->suivant=NULL;
	tmp->code=code;
	tmp->var1=v1;
	tmp->var2=v2;
	tmp->var3=v3;
	tmp->nom=NULL;
	tmp->type_instr=type_instr;
	
	return tmp;
}

static SInterm *creer_int_un(enum EInter code,SVar v1,SVar v2,
		enum EType_instr type_instr)
{
	SInterm *tmp;
	
	tmp=(SInterm*)malloc(sizeof(SInterm));
	tmp->suivant=NULL;
	tmp->code=code;
	tmp->var1=v1;
	tmp->var2=v2;
	tmp->var3.code=EIRien;
	tmp->nom=NULL;
	tmp->type_instr=type_instr;
	
	return tmp;
}

static SInterm *creer_int_appel(char *nom,SVar v1)
{
	SInterm *tmp;
	
	assert(stricmp(nom,"write")==0);
	if(stricmp("write",nom)==0)
	{
		tmp=(SInterm*)malloc(sizeof(SInterm));
		tmp->suivant=NULL;
		tmp->code=EIAppel;
		tmp->var1=v1;
		tmp->var2.code=EIRien;
		tmp->var3.code=EIRien;
		tmp->nom=nom;
		tmp->type_instr=type_param(v1);
	}
	else
	{
		printf("fonction inconnue:%s\n",nom);
		assert(1==0);
	}
	
	return tmp;
}

static SInterm *creer_int_label(char *s)
{
	SInterm *tmp;
	
	tmp=(SInterm*)malloc(sizeof(SInterm));
	tmp->suivant=NULL;
	tmp->code=EILabel;
	tmp->var1.code=EIRien;
	tmp->var2.code=EIRien;
	tmp->var3.code=EIRien;
	tmp->nom=s;
	tmp->type_instr=ETInt32;
	
	return tmp;
}

static SInterm *creer_int_saut_cond(enum EInter code,SVar v1,char *label,
		enum EType_instr type_instr)
{
	SInterm *tmp;
	
	tmp=(SInterm*)malloc(sizeof(SInterm));
	tmp->suivant=NULL;
	tmp->code=code;
	tmp->var1=v1;
	tmp->var2.code=EIRien;
	tmp->var3.code=EIRien;
	tmp->nom=label;
	tmp->type_instr=type_instr;
	
	return tmp;
}

static SInterm *creer_int_saut(char *label)
{
	SInterm *tmp;
	
	tmp=(SInterm*)malloc(sizeof(SInterm));
	tmp->suivant=NULL;
	tmp->code=EIJmp;
	tmp->var1.code=EIRien;
	tmp->var2.code=EIRien;
	tmp->var3.code=EIRien;
	tmp->nom=label;
	tmp->type_instr=ETInt32;
	
	return tmp;
}

static SInterm *ajoute_inter(SInterm *debut,SInterm *elt)
{
	SInterm *tmp;
	
	if(debut==NULL)
		return elt;
	
	tmp=debut;
	while(tmp->suivant!=NULL)
		tmp=tmp->suivant;
	tmp->suivant=elt;
	
	return debut;
}

static void efface_interm(SInterm *interm)
{
	SInterm *tmp;
	
	tmp=interm;
	while(tmp!=NULL)
	{
		interm=tmp->suivant;
		if(tmp->nom!=NULL)
			free(tmp->nom);
		free(tmp);
		tmp=interm;
	}
}

static char *str_var(SVar v)
{
	switch(v.code)
	{
		case EIVar:
			sprintf(buf_str_var,"p%d",v.val);
			return strdup(buf_str_var);
		case EIVal:
			sprintf(buf_str_var,"%d",v.val);
			return strdup(buf_str_var);
		case EIReel:
			sprintf(buf_str_var,"%f",v.reel);
			return strdup(buf_str_var);
		/*case EIString:
			sprintf(buf_str_var,"\"\"",);
			return strdup(buf_str_var);*/
		default:
			printf("code=%d\n",v.code);
			assert(1==0);
			return NULL;
	}
}

static char *conversion_str(enum EInter code)
{
	switch(code)
	{
		case EIPlus: return strdup("+");
		case EIMoins: return strdup("-");
		case EIFois: return strdup("*");
		case EIDiv: return strdup(" div ");
		case EIAnd: return strdup(" and ");
		case EIOr: return strdup(" or ");
		case EINot: return strdup(" not ");
		case EIMoinsu: return strdup("-");
		case EISup: return strdup(">=");
		case EIEgal: return strdup("=");
		case EISup_s: return strdup(">");
		case EIInf: return strdup("<=");
		case EIInf_s: return strdup("<=");
		case EIDiff: return strdup("!=");
		case EIDiv_r: return strdup("/");
		case EIMod: return strdup("%");
		case EIXor: return strdup(" xor ");
		default:
		printf("code=%d\n",code);
		assert(1==0);
	}
	return 0;
}

static void affiche_interm(SInterm *interm)
{
	SInterm *tmp;
	
	tmp=interm;
	while(tmp!=NULL)
	{
		switch(tmp->code)
		{
			case EIPlus:case EIMoins:
			case EIFois:case EIDiv:
			case EISup:case EIAnd:
			case EIOr:case EIEgal:
			case EISup_s:case EIInf_s:
			case EIInf:case EIDiff:
			case EIXor:
				printf("%s:=%s%s%s\n",str_var(tmp->var1),
						str_var(tmp->var2),conversion_str(tmp->code),
						str_var(tmp->var3));
				break;
			case EILabel:
				printf("%s:\n",tmp->nom);
				break;
			case EIJmp:
				printf("jmp %s\n",tmp->nom);
				break;
			case EISiEgal:
				printf("if %s=0 jmp %s\n",str_var(tmp->var1),tmp->nom);
				break;
			case EISiNonEgal:
				printf("if %s!=0 jmp %s\n",str_var(tmp->var1),tmp->nom);
				break;
			case EINot:
			case EIMoinsu:
				printf("%s:=%s %s\n",str_var(tmp->var1),
						conversion_str(tmp->code),
						str_var(tmp->var2));
				break;
			case EICopie:
				printf("%s:=%s\n",str_var(tmp->var1),
						str_var(tmp->var2));
				break;
			case EIAppel:
				printf("%s(%s)\n",tmp->nom,str_var(tmp->var1));
				break;
			default:
				printf("code=%d\n",tmp->code);
				assert(1==0);
		}
		tmp=tmp->suivant;
	}
}

static SVar donne_var(SExpr *var)
{
	SVar v1,v2;
	SDeclare *decl=declare_var;
	SListe_declare_var *var1,*var2;
	STable_symbol *tmp;
	
	assert(var!=NULL);
	assert(var->code==EVar);
	assert(var->nom!=NULL);
	
	tmp=cherche_tsymb(var->nom,NULL);
	if(tmp==NULL)
	{
		printf("tmp=%p,nom=%s\n",tmp,var->nom);
		assert(tmp!=NULL);
	}
	memset(&v1,0,sizeof(SVar));
	v1.code=EIVar;
	v1.val=tmp->no;
	v1.type=tmp->type;
	return v1;
}

static SVar donne_new_var(int signe,int taille,int type)
{
	SVar tmp;
	
	assert(taille>0);
	
	
	memset(&tmp,0,sizeof(SVar));
	tmp.code=EIVar;
	tmp.val=ajoute_nom_tsymb_temp(type,NULL);
	tmp.type=type;

	return tmp;
}

static SVar donne_new_var_int(void)
{
	return donne_new_var(1,4,TINT);
}

static SVar donne_new_var_reel(void)
{
	return donne_new_var(1,8,TREEL);
}

static SVar donne_new_var_reel_init(float f)
{
	//return donne_new_var(1,8,TREEL);
	SVar tmp;
	char *p;
	
	//assert(s!=NULL);
	
	//p=strdup(s);
	//p[strlen(p)-1]='\"';
	//p[0]='\"';
	p=(char*)malloc(30);
	sprintf(p,"%f",f);
	memset(&tmp,0,sizeof(SVar));
	tmp.code=EIVar;
	tmp.val=ajoute_nom_tsymb_temp(TREEL,p);
	tmp.type=TREEL;
	return tmp;
}

static SVar donne_new_var_char(void)
{
	return donne_new_var(0,1,TCHAR);
}

static SVar donne_new_var_bool(void)
{
	return donne_new_var(0,4,TBOOL);
}

static SVar donne_new_var_string(char *s)
{
	SVar tmp;
	char *p;
	
	assert(s!=NULL);
	
	p=strdup(s);
	p[strlen(p)-1]='\"';
	p[0]='\"';
	memset(&tmp,0,sizeof(SVar));
	tmp.code=EIVar;
	tmp.val=ajoute_nom_tsymb_temp(TSTRING,p);
	tmp.type=TSTRING;
	return tmp;
}

static SVar donne_new_var_type(SVar v)
{
	int i;
	//return donne_new_var(1,4,);
	switch(i=type_param(v))
	{
		/*case TBOOL:
			return donne_new_var_bool();
			break;
		case TCHAR:
			return donne_new_var_char();
			break;
		case TREEL:
			return donne_new_var_reel();
			break;
		case TINT:
			return donne_new_var_int();
			break;
		case TSTRING:
			return donne_new_var_string(NULL);
			break;*/
		case ETInt32:
			return donne_new_var_int();
			break;
		case ETFloat32:
			return donne_new_var_reel();
			break;
		case ETAutre:
			return donne_new_var_string(NULL);
			break;
		default:
			printf("code=%d\n",i);
			assert(1==0);
	}
}

static enum EInter conversion(enum ECode_exp code)
{
	switch(code)
	{
		case EPlus: return EIPlus;
		case EMoins: return EIMoins;
		case EFois: return EIFois;
		case EDiv: return EIDiv;
		case EAnd: return EIAnd;
		case EOr: return EIOr;
		case ENot: return EINot;
		case EMoins_u: return EIMoinsu;
		case ESup: return EISup;
		case EEgal: return EIEgal;
		case ESup_s: return EISup_s;
		case EInf: return EIInf;
		case EInf_s: return EIInf_s;
		case EDiff: return EIDiff;
		case EDiv_r: return EIDiv_r;
		case EMod: return EIMod;
		default:
		printf("code=%d\n",code);
		assert(1==0);
	}
	return 0;
}

static SInterm *genere_exp(SExpr *exp,SVar *var)
{
	SInterm *tmp,*debut=NULL,*tmp2,*tmp3;
	SVar var2,var3;
	
	assert(exp!=NULL);
	assert(var!=NULL);
	switch(exp->code)
	{
		case EPlus:case EMoins:
		case EFois:case EDiv:
		case EMod:case EDiv_r:		
			tmp2=genere_exp(exp->exp1,&var2);
			tmp3=genere_exp(exp->exp2,&var3);
			tmp2=ajoute_inter(tmp2,tmp3);
			*var=donne_new_var_type(var2);
				//donne_new_var();//donne_new_var_int();
			tmp3=creer_int_bin(conversion(exp->code),*var,var2,var3,
					type_param(var2));
			tmp2=ajoute_inter(tmp2,tmp3);
			debut=ajoute_inter(debut,tmp2);
			break;
		case EAnd:case EOr:
		case ESup:case EDiff:
		case EEgal:case ESup_s:
		case EInf:case EInf_s:		
			tmp2=genere_exp(exp->exp1,&var2);
			tmp3=genere_exp(exp->exp2,&var3);
			tmp2=ajoute_inter(tmp2,tmp3);
			*var=donne_new_var_bool(); //donne_new_var_type(var2);
				//donne_new_var();//donne_new_var_int();
			tmp3=creer_int_bin(conversion(exp->code),*var,var2,var3,
					type_param(var2));
			tmp2=ajoute_inter(tmp2,tmp3);
			debut=ajoute_inter(debut,tmp2);
			break;
		case EMoins_u:case ENot:
			tmp2=genere_exp(exp->exp1,&var2);
			debut=ajoute_inter(debut,tmp2);
			*var=donne_new_var_type(var2);//donne_new_var_int();
			tmp2=creer_int_un(conversion(exp->code),*var,var2,type_param(*var));
			debut=ajoute_inter(debut,tmp2);
			break;
		case EPlus_u:
			tmp2=genere_exp(exp->exp1,var);
			debut=ajoute_inter(debut,tmp2);
			break;
		case EEntier:
			*var=donne_new_var_int();
			var2.code=EIVal;
			var2.val=exp->entier;
			/*var->code=EIVal;
			var->val=exp->entier;*/
			tmp3=creer_int_un(EICopie,*var,var2,type_param(*var));
			debut=ajoute_inter(debut,tmp3);
			break;
		case EReel:
			*var=donne_new_var_reel();
			var2=donne_new_var_reel_init(exp->reel);
			//var2.code=EIReel;
			//var2.val=exp->reel;
			tmp3=creer_int_un(EICopie,*var,var2,type_param(*var));
			debut=ajoute_inter(debut,tmp3);
			break;
		case EVar:
			*var=donne_var(exp);
			debut=NULL;
			break;
		case ETrue:case EFalse:
			*var=donne_new_var_bool();
			var2.code=EIVal;
			var2.val=(exp->code==ETrue)?1:0;
			tmp3=creer_int_un(EICopie,*var,var2,type_param(*var));
			debut=ajoute_inter(debut,tmp3);
			break;
		case ENil:
			*var=donne_new_var_int();
			var2.code=EIVal;
			var2.val=0;
			tmp3=creer_int_un(EICopie,*var,var2,type_param(*var));
			debut=ajoute_inter(debut,tmp3);
			break;
		case EString:
			*var=donne_new_var_string(exp->nom);
			//creer_decl_bloc();
			//var2.code=EIVar;
			//var2.val=0;
			//tmp3=creer_int_un(EICopie,*var,var2);
			//debut=ajoute_inter(debut,tmp3);
			break;
		default:
			printf("code=%d\n",exp->code);
			assert(1==0);
	}
	
	return debut;
}

static SInterm *construit_instr(SListe_instr *instr)
{
	SInterm *tmp,*debut=NULL;
	SDeclare *decl;
	int adr=0;
	SListe_declare_var *var1,*var2;
	SVar var3,var4;
	SListe_instr *instr1,*instr2;
	char *label1,*label2;
	
	instr1=instr;
	while(instr1!=NULL)
	{
		if(instr1->label!=NULL)
		{
			tmp=creer_int_label(instr1->label);
			debut=ajoute_inter(debut,tmp);
		}
		switch(instr1->code)
		{
			case EAffect:
				tmp=genere_exp(instr1->exp,&var3);
				debut=ajoute_inter(debut,tmp);
				var4=donne_var(instr1->var);
				tmp=creer_int_un(EICopie,var4,var3,type_param(var4));
				//tmp=ajoute_inter(tmp,);
				debut=ajoute_inter(debut,tmp);
				break;
			case EBloc:
				debut=ajoute_inter(debut,construit_instr(instr1->ok));
				break;
			case EGoto:
				debut=ajoute_inter(debut,creer_int_saut(instr1->label));
				break;
			case EAppel_proc:
				if(stricmp(instr1->nom_proc,"write")!=0)
				{
					printf("Erreur:seul write est connue\n");
					return NULL;
				}
				if(instr1->exp==NULL||instr1->exp->suivant!=NULL)
				{
					printf("Erreur:write n'a qu'un seul parametre\n");
					return NULL;
				}
				tmp=genere_exp(instr1->exp,&var3);
				debut=ajoute_inter(debut,tmp);
				tmp=creer_int_appel(strdup("write"),var3);
				debut=ajoute_inter(debut,tmp);
				break;
			case EIf:
				tmp=genere_exp(instr1->exp,&var3);
				debut=ajoute_inter(debut,tmp);
				label1=donne_label();
				label2=donne_label();
				tmp=creer_int_saut_cond(EISiEgal,var3,label1,
						type_param(var3));
				debut=ajoute_inter(debut,tmp);
				tmp=construit_instr(instr1->ok);
				tmp=ajoute_inter(tmp,creer_int_saut(label2));
				debut=ajoute_inter(debut,tmp);
				debut=ajoute_inter(debut,creer_int_label(label1));
				tmp=construit_instr(instr1->pas_ok);
				debut=ajoute_inter(debut,tmp);
				debut=ajoute_inter(debut,creer_int_label(label2));
				break;
			case EWhile:
				label1=donne_label();
				label2=donne_label();
				debut=ajoute_inter(debut,creer_int_label(label1));
				tmp=genere_exp(instr1->exp,&var3);
				debut=ajoute_inter(debut,tmp);
				tmp=creer_int_saut_cond(EISiEgal,var3,label2,
						type_param(var3));
				debut=ajoute_inter(debut,tmp);
				tmp=construit_instr(instr1->ok);
				debut=ajoute_inter(debut,tmp);
				tmp=ajoute_inter(tmp,creer_int_saut(label1));
				debut=ajoute_inter(debut,creer_int_label(label2));				
				break;
			case ERepeat:
				label1=donne_label();
				debut=ajoute_inter(debut,creer_int_label(label1));
				tmp=construit_instr(instr1->ok);
				debut=ajoute_inter(debut,tmp);
				tmp=genere_exp(instr1->exp,&var3);
				debut=ajoute_inter(debut,tmp);
				tmp=creer_int_saut_cond(EISiEgal,var3,label1,
						type_param(var3));
				debut=ajoute_inter(debut,tmp);
				break;
			default:
				assert(1==0);
		}
		instr1=instr1->suivant;
	}
	return debut;
}

static SBloc *construit(SArbre *arbre1)
{
	SInterm *tmp,*debut;
	SDeclare *decl;
	int adr=0;
	SListe_declare_var *var1,*var2;
	SVar var3,var4;
	SListe_instr *instr1,*instr2;
	SBloc *bloc;
	
	decl=arbre1->declare;
	declare_var=decl;	
	
	bloc=(SBloc*)malloc(sizeof(SBloc));
	debut=construit_instr(arbre1->pprincipal);
	bloc->code=debut;
	bloc->type=EPrincipal;
	bloc->suivant=NULL;
	return bloc;
}

int genere(SArbre *arbre1)
{
	SInterm *interm;
	char *nom_fichier="code.asm",*nom_obj="code.o",*nom_fichier_jvm="codej.j";
	int res;
	char cmdline[512];
	SBloc *bloc;
	
	assert(arbre1!=NULL);
	bloc=construit(arbre1);
	affiche_interm(bloc->code);
	
	if(generation_asm86(bloc/*->code*/,nom_fichier)!=0)
	{
		return 1;
	}
	
#define TOTO_JVM
	
#ifdef TOTO_JVM
	if(generation_jvm(bloc,nom_fichier_jvm)!=0)
	{
		return 1;
	}
#else
	printf("Pas de JVM\n");
#endif
	
	affiche_table_type();
	//efface_interm(interm);
	
	return 0;
}