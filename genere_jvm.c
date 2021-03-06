#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<process.h>
#include"arbre.h"
#include"genere.h"
#include"debogage.h"
#include"table_symbol.h"
#include"type.h"

typedef struct SVar_Jvm
{
	enum EVCode {EJEntier,EJReel,EJVar,EJChaine} code;
	int val;
	double val2;
	char *nom;
} SVar_Jvm;

typedef struct SJvm
{
	enum ECode {EJIAdd,EJISub,EJIMul,EJIDiv,EJIAnd,EJIOr,//EJINot,
		EJIf_icmpge,EJIf_icmpgt,EJIf_icmple,EJIf_icmplt,EJIf_icmpe,
		EJIf_icmpne,EJIRien,EJLdc,EJIStore,EJILoad,EJALoad,
		EJAStore,EJBipush,EJLabel,EJIfeq,EJIfne,EJGetstatic,
		EJInvokevirtual,EJInvokestatic,EJGoto,EJReturn,
		EJINeg,EJIXor,EJIConst_1,EJFLoad,EJFStore,EJFComp,EJFcmpg,
		EJFAdd,EJFSub,EJFMul,EJFDiv,EJFNeg,EJPutstatic} code;
	SVar_Jvm var1,var2;
	//char *nom;
	struct SJvm *suivant;
} SJvm;

typedef struct SInstr_Jvm
{
	enum ECode code;
	char *nom;
	//enum EInter code_interm;
	int nb_param;
} SInstr_Jvm;

static char buf_str_var[512];

static SInstr_Jvm liste_instr[]=
{{EJIAdd,"iadd",0},
{EJISub,"isub",0},
{EJIMul,"imul",0},
{EJIDiv,"idiv",0},
{EJIAnd,"iand",0},
{EJIOr,"ior",0},
//{EJINot,"inot",0},
{EJINeg,"ineg",0},
{EJIf_icmpge,"if_icmpge",1},
{EJIf_icmpgt,"if_icmpgt",1},
{EJIf_icmple,"if_icmple",1},
{EJIf_icmplt,"if_icmplt",1},
{EJIf_icmpe,"if_icmpeq",1},
{EJIf_icmpne,"if_icmpne",1},
{EJReturn,"return",0},
{EJLdc,"ldc",1},
{EJIStore,"istore",1},
{EJILoad,"iload",1},
{EJALoad,"aload",1},
{EJAStore,"astore",1},
{EJBipush,"bipush",1},
{EJGoto,"goto",1},
{EJIfeq,"ifeq",1},
{EJIfne,"ifne",1},
{EJGetstatic,"getstatic",1},
{EJInvokevirtual,"invokevirtual",1},
{EJInvokestatic,"invokestatic",1},
{EJIXor,"ixor",2},
{EJIConst_1,"iconst_1",2},
{EJFLoad,"fload",1},
{EJFStore,"fstore",1},
{EJFComp,"fcomp",1},
{EJFcmpg,"fcmpg",1},
{EJFAdd,"fadd",0},
{EJFSub,"fsub",0},
{EJFMul,"fmul",0},
{EJFDiv,"fdiv",0},
{EJFNeg,"fneg",0},
{EJPutstatic,"putstatic",1},
{EJIRien,"",0}
};

static struct SInstr_convert {enum ECode code[5];
	enum EInter code_interm;} 
instr_conv[]=
{{{EJIAdd,EJIAdd,EJFAdd,EJIAdd,EJIAdd},EIPlus},
{{EJISub,EJISub,EJFSub,EJISub,EJISub},EIMoins},
{{EJIMul,EJIMul,EJFMul,EJIMul,EJIMul},EIFois},
{{EJIDiv,EJIDiv,EJFDiv,EJIDiv,EJIDiv},EIDiv},
{{EJIAnd,EJIAnd,EJIAnd,EJIAnd,EJIAnd},EIAnd},
{{EJIOr,EJIOr,EJIOr,EJIOr,EJIOr},EIOr},
//{{EJINot,EJINot,EJINot,EJINot,EJINot},EINot},
{{EJINeg,EJINeg,EJFNeg,EJINeg,EJINeg},EIMoinsu},
{{EJIf_icmpge,EJIf_icmpge,EJIf_icmpge,EJIf_icmpge,EJIf_icmpge},EISup},
{{EJIf_icmpgt,EJIf_icmpgt,EJIf_icmpgt,EJIf_icmpgt,EJIf_icmpgt},EISup_s},
{{EJIf_icmple,EJIf_icmple,EJIf_icmple,EJIf_icmple,EJIf_icmple},EIInf},
{{EJIf_icmplt,EJIf_icmplt,EJIf_icmplt,EJIf_icmplt,EJIf_icmplt},EIInf_s},
{{EJIf_icmpe,EJIf_icmpe,EJIf_icmpe,EJIf_icmpe,EJIf_icmpe},EIEgal},
{{EJIf_icmpne,EJIf_icmpne,EJIf_icmpne,EJIf_icmpne,EJIf_icmpne},EIDiff},
{{EJReturn,EJReturn,EJReturn,EJReturn,EJReturn},EIRien},
{{EJLdc,EJLdc,EJLdc,EJLdc,EJLdc},EIRien},
{{EJIStore,EJIStore,EJFStore,EJIStore,EJIStore},EIRien},
{{EJILoad,EJILoad,EJFLoad,EJILoad,EJILoad},EIRien},
{{EJALoad,EJALoad,EJALoad,EJALoad,EJALoad},EIRien},
{{EJAStore,EJAStore,EJAStore,EJAStore,EJAStore},EIRien},
{{EJBipush,EJBipush,EJBipush,EJBipush,EJBipush},EIRien},
{{EJGoto,EJGoto,EJGoto,EJGoto,EJGoto},EIRien},
{{EJIfeq,EJIfeq,EJIfeq,EJIfeq,EJIfeq},EIRien},
{{EJIfne,EJIfne,EJIfne,EJIfne,EJIfne},EIRien},
{{EJGetstatic,EJGetstatic,EJGetstatic,EJGetstatic,EJGetstatic},EIRien},
{{EJInvokevirtual,EJInvokevirtual,EJInvokevirtual,EJInvokevirtual,EJInvokevirtual},EIRien},
{{EJInvokestatic,EJInvokestatic,EJInvokestatic,EJInvokestatic,EJInvokestatic},EIRien},
{{EJIXor,EJIXor,EJIXor,EJIXor,EJIXor},EIRien},
{{EJIConst_1,EJIConst_1,EJIConst_1,EJIConst_1,EJIConst_1},EIRien},
{{EJFLoad,EJFLoad,EJFLoad,EJFLoad,EJFLoad},EIRien},
{{EJFStore,EJFStore,EJFStore,EJFStore,EJFStore},EIRien},
{{EJIRien,EJIRien,EJIRien,EJIRien,EJIRien},EIRien}
};

char nom_classe[256];

static char *descr_type(int type)
{
	switch(type)
	{
		case TINT:
			return strdup("I");
		case TBOOL:
			return strdup("Z");
		case TCHAR:
			return strdup("C");
		case TREEL:
			return strdup("F");
		case TSTRING:
			return strdup("Ljava/lang/String;");
		default:
			printf("code=%d\n",type);
			assert(1==0);
	}
	return NULL;
}

static enum ECode conversion_jvm2(SInterm *instr)
{
	struct SInstr_convert *tmp;
	enum EInter code;
	
	assert(instr!=NULL);
	code=instr->code;
	assert(code!=EIRien);	
	tmp=instr_conv;
	while(tmp!=NULL)
	{
		if(tmp->code_interm==code)
			return tmp->code[instr->type_instr];
		tmp++;
	}
	printf("code=%d\n",code);
	assert(1==0);
	return NULL;
}
/*
static char *conversion_jvm(enum EInter code)
{
	SInstr_Jvm *tmp;
	
/*	tmp=liste_instr;
	while(tmp!=NULL)
	{
		if(tmp->code_interm==code)
			return strdup(tmp->nom);
		tmp++;
	}
	printf("code=%d\n",code);
	assert(1==0);
	return NULL;
	/*switch(code)
	{
		case EIPlus: return strdup("iadd");
		case EIMoins: return strdup("isub");
		case EIFois: return strdup("imul");
		case EIDiv: return strdup("idiv");
		case EIAnd: return strdup("iand");
		case EIOr: return strdup("ior");
		case EINot: return strdup("inot");
		case EIMoinsu: return strdup("-");
		case EISup: return strdup("if_icmpge");
		case EIEgal: return strdup("if_icmpeq");
		case EISup_s: return strdup("if_icmpgt");
		case EIInf: return strdup("if_icmple");
		case EIInf_s: return strdup("if_icmplt");
		case EIDiff: return strdup("if_icmpne");
		case EIDiv_r: return strdup("/");
		case EIMod: return strdup("%");
		default:
		printf("code=%d\n",code);
		assert(1==0);
	}
	return 0;*/
//}

static SVar_Jvm creer_entier_jvm(int val)
{
	SVar_Jvm tmp;
	
	tmp.code=EJEntier;
	tmp.val=val;
	
	return tmp;
}

static SVar_Jvm creer_reel_jvm(double val)
{
	SVar_Jvm tmp;
	
	tmp.code=EJReel;
	tmp.val2=val;
	tmp.val=-1;
		
	return tmp;
}

static SVar_Jvm creer_var_jvm(int val)
{
	SVar_Jvm tmp;
	
	tmp.code=EJVar;
	tmp.val=val;
	
	return tmp;
}

static SVar_Jvm creer_chaine_jvm(char *nom)
{
	SVar_Jvm tmp;
	
	tmp.code=EJChaine;
	tmp.nom=strdup(nom);
	
	return tmp;
}

static SJvm *creer_instr_jvm_un(enum ECode code,SVar_Jvm var1)
{
	SJvm *tmp;
	
	tmp=(SJvm*)malloc(sizeof(SJvm));
	tmp->code=code;
	tmp->var1=var1;
	//tmp->nom=NULL;
	tmp->suivant=NULL;
	
	return tmp;
}

static SJvm *creer_instr_jvm_zero(enum ECode code)
{
	SJvm *tmp;
	
	tmp=(SJvm*)malloc(sizeof(SJvm));
	tmp->code=code;
	//tmp->nom=NULL;
	tmp->suivant=NULL;
	
	return tmp;
}

static SJvm *creer_instr_jvm_deux(enum ECode code,SVar_Jvm var1,SVar_Jvm var2)
{
	SJvm *tmp;
	
	tmp=(SJvm*)malloc(sizeof(SJvm));
	tmp->code=code;
	tmp->var1=var1;
	tmp->var2=var2;
	//tmp->nom=NULL;
	tmp->suivant=NULL;
	
	return tmp;
}


static SJvm *ajoute_instr(SJvm *debut,SJvm *elt)
{
	SJvm *tmp;
	
	if(debut==NULL)
		return elt;
	else
	{
		tmp=debut;
		while(tmp->suivant!=NULL)
			tmp=tmp->suivant;
		tmp->suivant=elt;
		return debut;
	}
}

static SJvm *load_var1(SVar v)
{
	STable_symbol *symb;
	SJvm *tmp=NULL;
	char buf[256];
	
	switch(v.code)
	{
		case EIVar:
			symb=recherche_tsymb_no(v.val);
			assert(symb!=NULL);
			if(symb->code==EGlobal)
			{
				sprintf(buf,"%s/%s",nom_classe,symb->nom);
				tmp=creer_instr_jvm_deux(EJGetstatic,
					creer_chaine_jvm(buf),
					creer_chaine_jvm(descr_type(symb->type)));
			}
			else
			{
				switch(symb->type)
				{
					case TSTRING:
						if(symb->init!=NULL)
							tmp=creer_instr_jvm_un(EJLdc,
								creer_chaine_jvm(symb->init));
						else
							tmp=creer_instr_jvm_un(EJALoad,
								creer_var_jvm(v.val));
						break;
					case TINT: case TCHAR:case TBOOL:
						tmp=creer_instr_jvm_un(EJILoad,
							creer_var_jvm(v.val));
						break;
					case TREEL:
						if(symb->init!=NULL)
						{
							tmp=creer_instr_jvm_un(EJLdc,
								creer_reel_jvm(atof(symb->init)));
						}
						else
						{
							tmp=creer_instr_jvm_un(EJFLoad,
								creer_var_jvm(v.val));
						}
						break;
					default:
						printf("code=%d\n",symb->type);
						assert(1==0);
				}
			}
			break;
		case EIVal:
			tmp=creer_instr_jvm_un(EJBipush,creer_entier_jvm(v.val));
			break;
		case EIReel:
			tmp=creer_instr_jvm_un(EJLdc,creer_reel_jvm(v.reel));
		default:
			printf("code=%d\n",v.code);
			assert(1==0);
			return NULL;
	}
	return tmp;
}

static SJvm *store_var1(SVar v)
{
	STable_symbol *symb;
	SJvm *tmp=NULL;
	char buf[256];
	
	switch(v.code)
	{
		case EIVar:
			symb=recherche_tsymb_no(v.val);
			assert(symb!=NULL);
			if(symb->code==EGlobal)
			{
				sprintf(buf,"%s/%s",nom_classe,symb->nom);
				tmp=creer_instr_jvm_deux(EJPutstatic,
					creer_chaine_jvm(buf),
					creer_chaine_jvm(descr_type(symb->type)));
			}
			else
			{
				switch(symb->type)
				{
					case TSTRING:
						tmp=creer_instr_jvm_un(EJAStore,
							creer_var_jvm(v.val));
						break;
					case TINT: case TCHAR:case TBOOL:
						tmp=creer_instr_jvm_un(EJIStore,
							creer_var_jvm(v.val));
						break;
					case TREEL:
						tmp=creer_instr_jvm_un(EJFStore,
							creer_var_jvm(v.val));
						break;
					default:
						printf("code=%d\n",symb->type);
						assert(1==0);
				}
			}
			return tmp;
		default:
			printf("code=%d\n",v.code);
			assert(1==0);
			return NULL;
	}
	
	return NULL;
}

static int donne_temp(void)
{
	return ajoute_nom_tsymb_temp(TINT,NULL);
}

#define ADD_INSTR(X)	debut=ajoute_instr(debut,(X))

static SJvm *genere_asm_jvm1(SInterm *interm,char *nom_fichier)
{
	SInterm *tmp1,*tmp2;
	//FILE *file;
	int i,no_label=0,obj_string,obj_string2;
	char nom_classe[30],*p,buf[256];
	STable_symbol *symb;
	SJvm *debut=NULL,*tmp;
	
	printf("Generation du code JVM\n");
	
	strcpy(nom_classe,nom_fichier);
	p=nom_classe;
	while(*p!='\0'&&*p!='.')
	{
		p++;
	}
	if(*p=='.') *p='\0';
	/*fprintf(file,".class public %s\n"
			".super java/lang/Object\n"
			".method public <init>()V\n"
			"\taload_0\n"
 			"\tinvokenonvirtual java/lang/Object/<init>()V\n"
			"\treturn\n"
			".end method\n\n"
			".method public static main([Ljava/lang/String;)V\n"
			".limit locals %d\n"
			".limit stack %d\n",nom_classe,nb_var_tsymb(),256);*/
	//fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
	//		"\tastore %d\n",obj_string);
	tmp1=interm;
	while(tmp1!=NULL)
	{
		switch(tmp1->code)
		{
			case EIPlus:case EIMoins:
			case EIFois:case EIDiv:
			case EIAnd:case EIOr:
			case EIMod:case EIDiv_r:
				switch(tmp1->type_instr)
				{
					case ETInt32:case ETFloat32:
						ADD_INSTR(load_var1(tmp1->var2));
						ADD_INSTR(load_var1(tmp1->var3));
						ADD_INSTR(
							creer_instr_jvm_zero(conversion_jvm2(tmp1)));
						ADD_INSTR(store_var1(tmp1->var1));
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EIEgal:case EISup_s:
			case EIInf:case EIInf_s:
			case EIDiff:case EISup:
				switch(tmp1->type_instr)
				{
					case ETInt32:case ETFloat32:
						if(tmp1->type_instr==ETInt32)
						{
							ADD_INSTR(load_var1(tmp1->var2));
							ADD_INSTR(load_var1(tmp1->var3));
						}
						else if(tmp1->type_instr==ETFloat32)
						{
							ADD_INSTR(load_var1(tmp1->var2));
							ADD_INSTR(load_var1(tmp1->var3));
							ADD_INSTR(creer_instr_jvm_zero(EJFcmpg));
							ADD_INSTR(creer_instr_jvm_zero(EJIConst_1));
						}
						sprintf(buf,"label_test%d",no_label);
						tmp=creer_instr_jvm_un(conversion_jvm2(tmp1),
							creer_chaine_jvm(buf));
						ADD_INSTR(tmp);
						ADD_INSTR(
							creer_instr_jvm_un(EJBipush,creer_entier_jvm(0)));
						sprintf(buf,"label_test%d",no_label+1);
						ADD_INSTR(
							creer_instr_jvm_un(EJGoto,creer_chaine_jvm(buf)));
						sprintf(buf,"label_test%d",no_label);
						ADD_INSTR(creer_instr_jvm_un(EJLabel,
							creer_chaine_jvm(buf)));
						ADD_INSTR(
							creer_instr_jvm_un(EJBipush,creer_entier_jvm(1)));
						sprintf(buf,"label_test%d",no_label+1);
						ADD_INSTR(creer_instr_jvm_un(EJLabel,
							creer_chaine_jvm(buf)));
						ADD_INSTR(store_var1(tmp1->var1));
						no_label+=2;
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EILabel:
				ADD_INSTR(creer_instr_jvm_un(EJLabel,
					creer_chaine_jvm(tmp1->nom)));
				break;
			case EICopie:
				switch(tmp1->type_instr)
				{
					case ETInt32:case ETFloat32:case ETAutre:
						ADD_INSTR(load_var1(tmp1->var2));
						ADD_INSTR(store_var1(tmp1->var1));
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EIJmp:
				ADD_INSTR(creer_instr_jvm_un(EJGoto,
					creer_chaine_jvm(tmp1->nom)));
				break;
			case EISiEgal:case EISiNonEgal:
				switch(tmp1->type_instr)
				{
					case ETInt32:
						ADD_INSTR(load_var1(tmp1->var1));
						ADD_INSTR(creer_instr_jvm_un(
							(tmp1->code==EISiEgal)?EJIfeq:EJIfne,
								creer_chaine_jvm(tmp1->nom)));
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EINot:
				switch(tmp1->type_instr)
				{
					case ETInt32:
						ADD_INSTR(load_var1(tmp1->var2));
						ADD_INSTR(creer_instr_jvm_zero(EJIConst_1));
						ADD_INSTR(
							creer_instr_jvm_zero(EJIXor));
						ADD_INSTR(store_var1(tmp1->var1));
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EIMoinsu:
				switch(tmp1->type_instr)
				{
					case ETInt32:case ETFloat32:
						ADD_INSTR(load_var1(tmp1->var2));
						ADD_INSTR(
							creer_instr_jvm_zero(conversion_jvm2(tmp1)));
						ADD_INSTR(store_var1(tmp1->var1));
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EIAppel:
				ADD_INSTR(creer_instr_jvm_deux(EJGetstatic,
					creer_chaine_jvm("java/lang/System/out"),
					creer_chaine_jvm("Ljava/io/PrintStream;")));
				symb=recherche_tsymb_no(tmp1->var1.val);
				assert(symb!=NULL);
				switch(symb->type)
				{
					case TSTRING:
						ADD_INSTR(load_var1(tmp1->var1));
						break;
					case TINT:case TBOOL:
						ADD_INSTR(load_var1(tmp1->var1));
						ADD_INSTR(creer_instr_jvm_un(EJInvokestatic,
							creer_chaine_jvm("java/lang/String/valueOf(I)Ljava/lang/String;")));
						break;
					case TREEL:
						ADD_INSTR(load_var1(tmp1->var1));
						ADD_INSTR(creer_instr_jvm_un(EJInvokestatic,
							creer_chaine_jvm("java/lang/String/valueOf(F)Ljava/lang/String;")));
						break;						
					default:
						printf("code=%d\n",symb->type);
						assert(1==0);
				}
				//fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
				ADD_INSTR(creer_instr_jvm_un(
					EJInvokevirtual,creer_chaine_jvm("java/io/PrintStream/println(Ljava/lang/String;)V")));
				break;
			default:
				printf("code=%d\n",tmp1->code);
				assert(1==0);
		}
		tmp1=tmp1->suivant;
	}

	ADD_INSTR(creer_instr_jvm_zero(EJReturn));
	
	
	return debut;
}

static char *str_instr(enum ECode code)
{
	SInstr_Jvm *tmp;
	
	tmp=liste_instr;
	while(tmp!=NULL)
	{
		if(tmp->code==code)
			return strdup(tmp->nom);
		tmp++;
	}
	
	assert(1==0);
	return NULL;
}

static char *str_var(SVar_Jvm var)
{
	char buf[256];
	STable_symbol *table;
	
	//assert(var!=NULL);
	switch(var.code)
	{
		case EJEntier:
			sprintf(buf,"%d",var.val);
			break;
		case EJReel:
			sprintf(buf,"%lf",var.val2);
			break;
		case EJVar:
			//table=recherche_tsymb_no(var.val);
			//assert(table!=NULL);
			//if()
			//{
				sprintf(buf,"%d",var.val);
			//}
			break;
		case EJChaine:
			sprintf(buf,"%s",var.nom);
			break;
		default:
			printf("code=%d\n",var.code);
			assert(1==0);
	}
	return strdup(buf);
}

static FILE *file_var;
void affiche_var_global(STable_symbol *tsym)
{
	assert(tsym!=NULL);
	
	if(tsym->code==EGlobal)
	{
		assert(tsym->nom!=NULL);
		fprintf(file_var,".field public static final %s %s\n",tsym->nom,
			descr_type(tsym->type));
	}
}

static void affiche(char *nom_fichier,SJvm *instr)
{
	FILE *f;
	SJvm *tmp;
	char nom_classe[256],*p;
	
	f=fopen(nom_fichier,"w");
	if(f==NULL)
	{
		printf("Erreur: Impossible de creer le fichier %s\n",nom_fichier);
		return;
	}
	
	strcpy(nom_classe,nom_fichier);
	p=nom_classe;
	while(*p!='\0'&&*p!='.')
	{
		p++;
	}
	if(*p=='.') *p='\0';
	fprintf(f,".source %s\n.class public %s\n"
			".super java/lang/Object\n\n",nom_fichier,nom_classe);
	
	file_var=f;
	parcourt_tsymb(affiche_var_global);
	file_var=NULL;
	
	fprintf(f,"\n.method public <init>()V\n"
			"\taload_0\n"
 			"\tinvokenonvirtual java/lang/Object/<init>()V\n"
			"\treturn\n"
			".end method\n\n"
			".method public static main([Ljava/lang/String;)V\n"
			".limit locals %d\n"
			".limit stack %d\n",nb_var_tsymb(),256);
	tmp=instr;
	while(tmp!=NULL)
	{
		switch(tmp->code)
		{
			case EJIAdd:case EJISub:case EJIMul:case EJIDiv:
			case EJIAnd:case EJIOr:case EJIConst_1:case EJReturn:
			case EJINeg:case EJIXor:case EJFComp:case EJFAdd:
			case EJFSub:case EJFMul:case EJFDiv:case EJFNeg:
			case EJFcmpg:
				fprintf(f,"\t%s\n",str_instr(tmp->code));
				break;
			case EJLdc:case EJIStore:case EJILoad:
			case EJALoad:case EJAStore:case EJBipush:
			case EJFLoad:case EJFStore:
				fprintf(f,"\t%s %s\n",str_instr(tmp->code),
					str_var(tmp->var1));
				break;
			case EJIf_icmpge:case EJIf_icmpgt:case EJIf_icmple:
			case EJIf_icmplt:case EJIf_icmpe:case EJIf_icmpne:
			case EJIfeq:case EJIfne:case EJGoto:
			case EJInvokevirtual:case EJInvokestatic:
				fprintf(f,"\t%s %s\n",str_instr(tmp->code),
					str_var(tmp->var1));
				break;
			case EJLabel:
				fprintf(f,"%s:\n",str_var(tmp->var1));
				break;
			case EJGetstatic:case EJPutstatic:
				fprintf(f,"\t%s %s %s\n",str_instr(tmp->code),
					str_var(tmp->var1),str_var(tmp->var2));
				break;
			default:
				printf("code=%d\n",tmp->code);
				assert(1==0);
		}
		tmp=tmp->suivant;
	}
	fprintf(f,".end method\n");
	fclose(f);
}

/* les variables doivent etre initialise avant d'etre utilise */

int generation_jvm(SBloc *bloc,char *nom_fichier_jvm)
{
	int res;
	char cmdline[512],nom_fichier_jvm2[]="codej2.j";
	
	assert(bloc!=NULL);
	assert(nom_fichier_jvm!=NULL);
	printf("2eme generation de code java...(%s)\n",nom_fichier_jvm);
	strcpy(nom_classe,nom_fichier_jvm);
	nom_classe[strlen(nom_classe)-2]='\0';
	affiche(nom_fichier_jvm,genere_asm_jvm1(bloc->code,nom_fichier_jvm));
	//res=spawnlp(P_WAIT,"c:\jasmin\bin\jasmin.bat","jasmin.bat",nom_fichier_jvm,NULL);
	sprintf(cmdline,"c:\\jasmin\\bin\\jasmin.bat %s",nom_fichier_jvm);
	//printf("jasmin:%s!\n",cmdline);
	res=system(cmdline);
	if(res==0)
	{
		printf("Ok pour jasmin2\n");
	}
	else
		printf("Erreur avec jasmin2\n");
	
	return 0;
}