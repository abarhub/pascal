#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<process.h>
#include<time.h>
#include"arbre.h"
#include"genere.h"
#include"debogage.h"
#include"table_symbol.h"
#include"type.h"

typedef struct SVar86
{
	enum EVcode {EAEntier,EAReel,EARien,EARegistre,EAVar,EALabel} code;
	int val;
	double reel;
	int taille;
	int adr;
	char *nom;
} SVar86;

typedef struct SAsm86
{
	enum Ecode {EAPlus,EAMoins,EAFois,EADiv,EAMov,EAJmp,EACall,
		EAJe,EAJne,EADef_Label,EACmp,EAPush,EAPop,EAAnd,EAOr,
		EANot,EARet,EASete,EASetne,EAMovsx,EAMovzx,EAXor,
		EASetg,EASetge,EASetl,EASetle,EANeg,EAMod,EAFld,
		EAFstp,EAFinit,EAWait,EAFadd,EAFsubr,EAFmult,EAFdivr,
		EAFtst,EAFstsw,EASahf,EAFincstp,EAFdecstp,EAFcomp,
		EASeta,EASetae,EASetna,EASetnae,EASetb,EASetnb,
		EASetbe,EASetnbe,EAFnstsw} code;
	SVar86 var1,var2;
	struct SAsm86 *suivant,*precedant;
} SAsm86;

typedef struct SData
{
	int taille,position;
	char *texte;
	struct SData *suivant;
} SData;

typedef struct SFonction
{
	SAsm86 *liste_instr;
	SData *var_local,*param;
	struct SFonction *suivant;
} SFonction;

typedef struct SProgramme
{
	SData *var_global;
	//SFonction *liste_fonction;
	SAsm86 *code;
} SProgramme;

typedef struct SInstr_asm86
{
	enum Ecode code;//[5];
	char *nom;
	//enum EInter code_interm;
	int nb_param;
} SInstr_asm86;

#define REG_EAX	creer_var_registre(0,0)
#define REG_AL	creer_var_registre2(1,0,1)
#define REG_AH	creer_var_registre2(0,0,1)
#define REG_AX	creer_var_registre2(0,0,2)

static SInstr_asm86 liste_instr[]=
{{EAPlus,"add",2},
{EAMoins,"sub",2},
{EAFois,"mult",2},
{EADiv,"div",2},
{EAMov,"mov",2},
{EAJmp,"jmp",1},
{EACall,"call",1},
{EAJe,"je",1},
{EAJne,"jne",1},
{EADef_Label,"",0},
{EACmp,"cmp",2},
{EAPush,"push",1},
{EAPop,"pop",1},
{EAAnd,"and",2},
{EAOr,"or",2},
{EANot,"sete",1},
{EARet,"ret",1},
{EASete,"sete",1},
{EASetne,"setne",1},
{EAMovsx,"movsx",2},
{EASetg,"setg",1},
{EASetge,"setge",1},
{EASetl,"setl",1},
{EASetle,"setle",1},
{EANeg,"neg",1},
{EAXor,"xor",1},
{EAMod,"mod",2},
{EAFstp,"fstp",1},
{EAFld,"fld",1},
{EAFinit,"finit",0},
{EAWait,"wait",0},
{EAFadd,"fadd",1},
{EAFsubr,"fsubr",1},
{EAFmult,"fmult",1},
{EAFdivr,"fdivr",1},
{EAFtst,"ftst",0},
{EAFstsw,"fstsw",1},
{EASahf,"sahf",0},
{EAFincstp,"fincstp",0},
{EAFdecstp,"fdecstp",0},
{EAFcomp,"fcomp",1},
{EASetae,"setae",1},
{EASetnae,"setnae",1},
{EASeta,"seta",1},
{EASetna,"setna",1},
{EASetbe,"setbe",1},
{EASetnbe,"setnbe",1},
{EASetb,"setb",1},
{EASetnb,"setnb",1},
{EAFnstsw,"fnstsw",1},
//{EAXor,"xor",EIXor,2},
{EARien,"",0}
};

static struct SInstr_convert {enum Ecode code[5];
	enum EInter code_interm;} 
instr_conv[]=
{{{EAPlus,EAPlus,EAFadd,EAPlus,EAPlus},EIPlus},
{{EAMoins,EAMoins,EAFsubr,EAMoins,EAMoins},EIMoins},
{{EAFois,EAFois,EAFmult,EAFois,EAFois},EIFois},
{{EADiv,EADiv,EAFdivr,EADiv,EADiv},EIDiv},
{{EAMov,EAMov,EAMov,EAMov,EAMov},EIRien},
{{EAJmp,EAJmp,EAJmp,EAJmp,EAJmp},EIRien},
{{EACall,EACall,EACall,EACall,EACall},EIRien},
{{EAJe,EAJe,EAJe,EAJe,EAJe},EIRien},
{{EAJne,EAJne,EAJne,EAJne,EAJne},EIRien},
{{EADef_Label,EADef_Label,EADef_Label,EADef_Label,EADef_Label},EIRien},
{{EACmp,EACmp,EACmp,EACmp,EACmp},EIRien},
{{EAPush,EAPush,EAPush,EAPush,EAPush},EIRien},
{{EAPop,EAPop,EAPop,EAPop,EAPop},EIRien},
{{EAAnd,EAAnd,EAAnd,EAAnd,EAAnd},EIAnd},
{{EAOr,EAOr,EAOr,EAOr,EAOr},EIOr},
{{EANot,EANot,EANot,EANot,EANot},EINot},
{{EARet,EARet,EARet,EARet,EARet},EIRien},
{{EASete,EASete,EASete,EASete,EASete},EIEgal},
{{EASetne,EASetne,EASetne,EASetne,EASetne},EIDiff},
{{EAMovsx,EAMovsx,EAMovsx,EAMovsx,EAMovsx},EIRien},
{{EASetg,EASetg,EASeta,EASeta,EASetg},EISup_s},
{{EASetge,EASetge,EASetae,EASetae,EASetge},EISup},
{{EASetl,EASetl,EASetb,EASetb,EASetl},EIInf_s},
{{EASetle,EASetle,EASetbe,EASetbe,EASetle},EIInf},
{{EANeg,EANeg,EANeg,EANeg,EANeg},EIMoinsu},
{{EAXor,EAXor,EAXor,EAXor,EAXor},EIXor},
{{EAMod,EAMod,EAMod,EAMod,EAMod},EIMod},
//{EAXor,"xor",EIXor},
{{EARien,EARien,EARien,EARien,EARien},EIRien}
};


static char buf_str_var[512];

static SVar86 creer_var_label(char *nom,int adr)
{
	SVar86 var;

	var.nom=nom;
	var.code=EALabel;
	var.val=-1;
	var.reel=0.0;
	var.taille=4;
	var.adr=adr;
	
	return var;
}
static SVar86 creer_var_entier(int val,int adr)
{
	SVar86 var;
	
	var.nom=NULL;
	var.code=EAEntier;
	var.val=val;
	var.reel=0.0;
	var.taille=4;
	var.adr=adr;
	
	return var;
}

static SVar86 creer_var_reel(double val,int adr)
{
	SVar86 var;
	
	var.nom=NULL;
	var.code=EAReel;
	var.val=-1;
	var.reel=val;
	var.taille=4;
	var.adr=adr;
	
	return var;
}

static SVar86 creer_var_var(int val,int adr)
{
	SVar86 var;
	
	if(val>24)
	{
		printf("val=%d\n",val);
		assert(val<24);
	}
	var.nom=NULL;
	var.code=EAVar;
	var.val=val;
	var.reel=0.0;
	var.taille=4;
	var.adr=adr;
	
	return var;
}

static SVar86 creer_var_registre(int val,int adr)
{
	SVar86 var;
	
	var.nom=NULL;
	var.code=EARegistre;
	var.val=val;
	var.reel=0.0;
	var.taille=4;
	var.adr=adr;
	
	return var;
}

static SVar86 creer_var_registre2(int val,int adr,int taille)
{
	SVar86 var;
	
	assert(taille==1||taille==2||taille==4||(adr==1&&taille==8));
	var.nom=NULL;
	var.code=EARegistre;
	var.val=val;
	var.reel=0.0;
	var.taille=taille;
	var.adr=adr;
	
	return var;
}

static SAsm86 *creer_asm86_bi(enum Ecode code,SVar86 v1,SVar86 v2)
{
	SAsm86 *tmp;
	
	tmp=(SAsm86*)malloc(sizeof(SAsm86));
	tmp->code=code;
	tmp->var1=v1;
	tmp->var2=v2;
	tmp->suivant=NULL;
	tmp->precedant=NULL;
	
	return tmp;
}

static SAsm86 *creer_asm86_un(enum Ecode code,SVar86 v)
{
	SAsm86 *tmp;
	SVar86 v1;
	
	tmp=(SAsm86*)malloc(sizeof(SAsm86));
	tmp->code=code;
	tmp->var1=v;
	v1.code=EARien;
	tmp->var2=v1;
	tmp->suivant=NULL;
	tmp->precedant=NULL;
	
	return tmp;
}

static SAsm86 *creer_asm86_no(enum Ecode code)
{
	SAsm86 *tmp;
	SVar86 v1;
	
	tmp=(SAsm86*)malloc(sizeof(SAsm86));
	tmp->code=code;
	v1.code=EARien;
	tmp->var1=v1;
	tmp->var2=v1;
	tmp->suivant=NULL;
	tmp->precedant=NULL;
	
	return tmp;
}

static SAsm86 *ajoute_asm86(SAsm86 *debut,SAsm86 *elt)
{
	SAsm86 *tmp;
	
	if(debut==NULL)
		return elt;
	else
	{
		if(elt==NULL)
			return debut;
		tmp=debut;
		while(tmp->suivant!=NULL)
			tmp=tmp->suivant;
		tmp->suivant=elt;
		return debut;
	}
}

int creer_fichier_c(char *nom_fichier)
{
	FILE *f;
	
	f=fopen(nom_fichier,"w");
	if(f==NULL)
	{
		printf("Erreur:Impossible de creer le fichier %s\n",nom_fichier);
		return 1;
	}
	
	fprintf(f,"#include <stdio.h>\n\n"
	"extern void test1_asm(void);\n\n"
	"int main(int argc,char *argv) {\n\n"
	"\tprintf(\"Test pascal asm\\n\");\n\n"
	"\ttest1_asm();\n\n"
	"\tprintf(\"Fin du test\\n\");\n\treturn 0;\n\n}");
	fclose(f);
	
	return 0;
}

static SVar86 adr_var_asm86(SVar v)
{
	SVar86 v1;
	STable_symbol *symb;
	
	switch(v.code)
	{
		case EIVar:
			if(v.val>=nb_var_tsymb())
			{
				printf("v.val=%d,%d\n",v.val,nb_var_tsymb());
				assert(1==0);
			}
			symb=recherche_tsymb_no(v.val);
			assert(symb!=NULL);
			v1.nom=NULL;
			v1.reel=0.0;
			v1.code=EAVar;
			v1.val=v.val;
			v1.taille=symb->taille;
			if(symb->type==TSTRING)
				v1.adr=1;
			else
				v1.adr=1;
			return v1;
			//return creer_var_var(v.val,1);
		case EIVal:
			return creer_var_entier(v.val,0);
		case EIReel:
			return creer_var_reel(v.val,0);
		default:
			printf("code=%d\n",v.code);
			assert(1==0);
			v1.code=EARien;
			return v1;
	}
}

static SVar86 val_var_asm86(SVar v)
{
	SVar86 v2=adr_var_asm86(v);
	STable_symbol *symb;

	symb=recherche_tsymb_no(v2.val);
	assert(symb!=NULL);
	if(symb->type==TSTRING)
		v2.adr=0;
	else
		v2.adr=1;

	return v2;
}

static enum Ecode conversion2_asm86(SInterm *instr
		/*enum EInter code,enum EType_instr type_instr*/)
{
	int i,j;
	enum EInter code;
	enum EType_instr type_instr;
	
	/*switch(type_instr)
	{ETInt32,ETInt64,ETFloat32,ETFloat64,ETAutre
		case :
			j=
			break;
	}*/
	assert(instr!=NULL);
	assert(ETInt32+1==ETInt64);
	assert(ETInt64+1==ETFloat32);
	assert(ETFloat32+1==ETFloat64);
	assert(ETFloat64+1==ETAutre);
	type_instr=instr->type_instr;
	assert(type_instr>=ETInt32&&type_instr<=ETAutre);

	assert(code!=EIRien);
	j=instr->type_instr-ETInt32;
	code=instr->code;
	for(i=0;i<sizeof(instr_conv/*liste_instr*/)/sizeof(struct SInstr_convert
			/*SInstr_asm86*/);i++)
	{
		if(code==/*liste_instr*/instr_conv[i].code_interm)
			return /*liste_instr*/instr_conv[i].code[j];
	}
	printf("code=%d\n",code);
	assert(1==0);	

	/*switch(code)
	{
		case EIPlus: return EAPlus;
		case EIMoins: return EAMoins;
		case EIFois: return EAFois;
		case EIDiv: return EADiv;
		case EIAnd: return EAAnd;
		case EIOr: return EAOr;
		case EINot: return EANot;
		//case EIMoinsu: return EAMoinsu;
		case EISup: return EASetge;
		case EIEgal: return EASete;//EAJe;
		case EISup_s: return EASetg;
		case EIInf: return EASetle;
		case EIInf_s: return EASetl;
		case EIDiff: return EASetne;//EAJne;
		//case EIDiv_r: return strdup("/");
		//case EIMod: return strdup("%");
		default:
		printf("code=%d\n",code);
		assert(1==0);
	}*/
	return 0;
}

static void donne_taille(STable_symbol *s)
{
	assert(s!=NULL);
	switch(s->type)
	{
		case TINT:case TBOOL:
			s->taille=4;
			break;
		case TREEL:
			s->taille=4;
			break;
		case TCHAR:
			s->taille=1;
			break;
		case TSTRING:
			s->taille=4;
			break;
		default:
			printf("code=%d\n",s->type);
			assert(1==0);
	}
}

static void met_registre(SVar var,SVar86 *reg,SAsm86 **instr)
{
	STable_symbol *symbol;
	
	assert(reg!=NULL);
	assert(instr!=NULL);
	assert(var.code==EIVar);
	
	symbol=recherche_tsymb_no(var.val);
	assert(symbol!=NULL);
	
}

int reg_disp[4]={0,0,0,0};

static SVar86 donne_registre(int adr,SAsm86 **instr)
{
	SVar86 v;
	int i;

	assert(instr!=NULL);

	for(i=0;i<4;i++)
	{
		if(reg_disp[i]==0)
		{
			reg_disp[i]=1;
			v=creer_var_registre(i,adr);
			return v;
		}
	}
	
	return v;
}

#define ASM_BIN(X,Y,Z)	tmp=creer_asm86_bi((X),(Y),(Z)); \
				debut=ajoute_asm86(debut,tmp);
#define ASM_UN(X,Y)	tmp=creer_asm86_un((X),(Y)); \
				debut=ajoute_asm86(debut,tmp);
#define ASM_NO(X)		tmp=creer_asm86_no((X)); \
				debut=ajoute_asm86(debut,tmp);

static SProgramme *convertion(SBloc *bloc)
{
	SInterm *tmp1,*tmp2;
	FILE *file;
	int i,no_label=0,val;
	SAsm86 *debut=NULL,*tmp;
	SVar86 reg_eax,var,reg_al,reg_ah,reg_ax;
	char buffer[100];
	SProgramme *prog;
	char *p;
	
	assert(bloc!=NULL);
	reg_eax=creer_var_registre(0,0);
	reg_al=creer_var_registre2(1,0,1);
	reg_ah=creer_var_registre2(0,0,1);
	reg_ax=creer_var_registre2(0,0,2);
	
	printf("Generation du code asm 80x86\n");
	
	//parcourt_tsymb(donne_taille);
	debut=creer_asm86_un(EADef_Label,creer_var_label("_test1_asm",0));
	tmp1=bloc->code;
	if(tmp1!=NULL)
		ASM_NO(EAFinit);
						
	while(tmp1!=NULL)
	{
		switch(tmp1->code)
		{
			case EIPlus:case EIMoins:
			case EIFois:case EIDiv:
			case EIAnd:case EIOr:
			case EIMod:case EIDiv_r:
			case EIXor:
				switch(tmp1->type_instr)
				{
					case ETInt32:case ETAutre:
						ASM_BIN(EAMov,reg_eax,adr_var_asm86(tmp1->var2));
						ASM_BIN(conversion2_asm86(tmp1),
								reg_eax,adr_var_asm86(tmp1->var3));
						ASM_BIN(EAMov,adr_var_asm86(tmp1->var1),reg_eax);
					break;
					case ETFloat32:
						ASM_UN(EAFld,adr_var_asm86(tmp1->var2));
						ASM_UN(conversion2_asm86(tmp1),
								adr_var_asm86(tmp1->var3));
						ASM_UN(EAFstp,adr_var_asm86(tmp1->var1));
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
					case ETInt32:
						ASM_BIN(EAMov,reg_eax,adr_var_asm86(tmp1->var2));
						ASM_BIN(EACmp,reg_eax,adr_var_asm86(tmp1->var3));
						ASM_UN(conversion2_asm86(tmp1),reg_al);
						ASM_BIN(EAAnd,reg_eax,creer_var_entier(255,0));
						ASM_BIN(EAMov,adr_var_asm86(tmp1->var1),reg_eax);
						break;
					case ETFloat32:
						ASM_UN(EAFld,adr_var_asm86(tmp1->var2));
						ASM_UN(EAFcomp,adr_var_asm86(tmp1->var3));
						ASM_UN(EAFstsw,reg_ax);
						ASM_NO(EASahf);
						ASM_UN(conversion2_asm86(tmp1),reg_al);
						ASM_BIN(EAAnd,reg_eax,creer_var_entier(255,0));
						ASM_BIN(EAMov,adr_var_asm86(tmp1->var1),reg_eax);
						
						//ASM_UN(EAFstp,adr_var_asm86(tmp1->var1));
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EILabel:
				ASM_UN(EADef_Label,creer_var_label(strdup(tmp1->nom),0));
				break;
			case EICopie:
				switch(tmp1->type_instr)
				{
					case ETFloat32:case ETFloat64:
						ASM_UN(EAFld,adr_var_asm86(tmp1->var2));
						ASM_NO(EAWait);
						ASM_UN(EAFstp,adr_var_asm86(tmp1->var1));
						ASM_NO(EAWait);
						break;
					case ETInt32:case ETAutre:
						ASM_BIN(EAMov,reg_eax,adr_var_asm86(tmp1->var2));
						ASM_BIN(EAMov,adr_var_asm86(tmp1->var1),reg_eax);
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EIJmp:
				ASM_UN(EAJmp,creer_var_label(strdup(tmp1->nom),0));
				break;
			case EISiEgal:case EISiNonEgal:
				switch(tmp1->type_instr)
				{
					case ETInt32:
						ASM_BIN(EACmp,adr_var_asm86(tmp1->var1),
							creer_var_entier(0,0));
						ASM_UN((tmp1->code==EISiEgal)?EAJe:EAJne,
							creer_var_label(strdup(tmp1->nom),0));
						break;
					case ETFloat32:
						ASM_UN(EAFld,adr_var_asm86(tmp1->var1));
						ASM_NO(EAFtst);
						ASM_UN(EAFstsw,reg_ax);
						ASM_NO(EAFincstp);
						ASM_NO(EASahf);
						ASM_UN((tmp1->code==EISiEgal)?EAJe:EAJne,
							creer_var_label(strdup(tmp1->nom),0));
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EIAppel:
				val=8;
				if(tmp1->var1.code==EIVar)
				{// variable
					STable_symbol *t;
					
					t=recherche_tsymb_no(tmp1->var1.val);
					assert(t!=NULL);
					switch(tmp1->type_instr)
					{
						case ETInt32://case TBOOL:
							p="_str_printf_int";
							ASM_UN(EAPush,val_var_asm86(tmp1->var1));
							//v3=val_var_asm86(tmp1->var1);
							val=8;
							break;
						case ETAutre://TSTRING:
							p="_str_printf_str";
							ASM_UN(EAPush,val_var_asm86(tmp1->var1));
							//v3=val_var_asm86(tmp1->var1);
							val=8;
							break;
						case ETFloat32://TREEL:
							p="_str_printf_float";
							//v3=val_var_asm86(tmp1->var1);
							val=12;
							ASM_UN(EAFld,adr_var_asm86(tmp1->var1));
							ASM_NO(EAWait);
							ASM_BIN(EAPlus,creer_var_registre(4,0),
									creer_var_entier(-8,0));
							ASM_UN(EAFstp,creer_var_registre2(4,1,8));
							break;
						default:
							printf("code=%d\n",t->type);
							assert(1==0);
					}
				}
				else
				{//valeur immediate
					switch(tmp1->var1.code)
					{
						case EIVal:
							p="_str_printf_int";
							//v3=val_var_asm86(tmp1->var1);
							ASM_UN(EAPush,val_var_asm86(tmp1->var1));
							val=8;
							break;
						case EIReel:
							assert(1==0);
							break;
						default:
							printf("code=%d\n",tmp1->var1.code);
							assert(1==0);
					}
				}
				//ASM_UN(EAPush,val_var_asm86(tmp1->var1));
				ASM_UN(EAPush,creer_var_label(strdup(p),0));
				ASM_UN(EACall,creer_var_label(strdup("_printf"),0));
				ASM_BIN(EAPlus,creer_var_registre(4,0),
								creer_var_entier(val,0));
				break;
			case EINot:
				switch(tmp1->type_instr)
				{
					case ETInt32:
						ASM_BIN(EAXor,reg_eax,reg_eax);
						ASM_BIN(EACmp,adr_var_asm86(tmp1->var2),
								creer_var_entier(0,0));
						ASM_UN(conversion2_asm86(tmp1/*->code,tmp1->type_instr*/),reg_al);
						ASM_BIN(EAMov,adr_var_asm86(tmp1->var1),reg_eax);
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			case EIMoinsu:
				switch(tmp1->type_instr)
				{
					case ETInt32:
						ASM_BIN(EAMov,reg_eax,adr_var_asm86(tmp1->var2));
						ASM_UN(conversion2_asm86(tmp1/*->code*/),reg_eax);
						ASM_BIN(EAMov,adr_var_asm86(tmp1->var1),reg_eax);
						break;
					default:
						printf("code=%d\n",tmp1->type_instr);
						assert(1==0);
				}
				break;
			default:
				printf("code=%d\n",tmp1->code);
				assert(1==0);
		}
		tmp1=tmp1->suivant;
	}
	tmp=creer_asm86_no(EARet);
	debut=ajoute_asm86(debut,tmp);
	
	prog=(SProgramme*)malloc(sizeof(SProgramme));
	prog->code=debut;
	prog->var_global=NULL;

	return prog;
}

static int egal(SVar86 var1,SVar86 var2)
{
	if(var1.code==var2.code&&var1.val==var2.val&&
			var1.adr==var2.adr&&var1.taille==var2.taille//&&
			/*var1.reel==var2.reel*/)
	{
		if(var1.code==EAEntier||var1.code==EAReel||var1.code==EARegistre)
			return 1;
		return 1;
		if( (var1.nom==NULL&&var2.nom!=NULL) ||
			(var1.nom!=NULL&&var2.nom==NULL) )
			return 0;
		if(var1.nom==var2.nom)
			return 1;
		return strcmp(var1.nom,var2.nom)==0;
	}
	else
		return 0;
}

static void copie(SVar86 *v1,SVar86 v2)
{
	assert(v1!=NULL);
	
	v1->code=v2.code;
	v1->val=v2.val;
	v1->reel=v2.reel;
	v1->taille=v2.taille;
	v1->adr=v2.adr;
	if(v2.nom!=NULL)
		v1->nom=strdup(v2.nom);
}

static SProgramme *optimise(SProgramme *prog)
{
	SProgramme *p=NULL;
	SAsm86 *instr,*instr2;
	
	assert(prog!=NULL);
	
	instr=prog->code;
	while(instr!=NULL&&instr->suivant!=NULL)
	{
		switch(instr->code)
		{
			case EAMov:
				instr2=instr->suivant;
				if(instr2->code==EAMov)
				{
					if(egal(instr->var1,instr2->var1)&&
						egal(instr->var2,instr2->var2))
					{
						instr->suivant=instr2->suivant;
						instr=instr->suivant;
					}
					else if(egal(instr->var1,instr2->var2)&&
						egal(instr->var2,instr2->var1))
					{
						instr->suivant=instr2->suivant;
						instr=instr->suivant;
					}
					else
						instr=instr->suivant;
				}
				else if(instr2->code==EAPush)
				{
					if(egal(instr->var1,instr2->var1))
					{
						copie(&(instr2->var1),instr->var2);
						instr=instr->suivant;
					}
					else
						instr=instr->suivant;
				}
				else
					instr=instr->suivant;
				break;
			default:
				instr=instr->suivant;
				break;
		}
	}
	
	return prog;
}

char *conv_str(enum ECode code)
{
	int i;
	
	assert(code!=EARien);
	for(i=0;i<sizeof(liste_instr)/sizeof(SInstr_asm86);i++)
	{
		if(code==liste_instr[i].code)
			return strdup(liste_instr[i].nom);
	}
	assert(1==0);
	/*switch(code)
	{
		case EAPlus:return strdup("add");
		case EAMoins:return strdup("sub");
		case EAFois:return strdup("mult");
		case EADiv:return strdup("div");
		case EAAnd:return strdup("and");
		case EAOr:return strdup("or");
		case EANot:return strdup("not");
		case EACall:return strdup("call");
		case EAPop:return strdup("pop");
		case EAPush:return strdup("push");
		//case EAMod:return strdup("");
		case EARet:return strdup("ret");
		case EAMov:return strdup("mov");
		case EACmp:return strdup("cmp");
		case EAJmp:return strdup("jmp");
		case EAJe:return strdup("je");
		case EAJne:return strdup("jne");
		case EASete:return strdup("sete");
		case EASetne:return strdup("setne");
		case EAMovsx:return strdup("movsx");
		case EAMovzx:return strdup("movzx");
		case EAXor:return strdup("xor");
		//case :return strdup("");
		//case :return strdup("");
		//case :return strdup("");
		default:
			printf("code=%d\n",code);
			assert(1==0);
	}*/
}

char *str_taille(int taille)
{
	switch(taille)
	{
		case 4: return strdup("dword");
		case 2: return strdup("word");
		case 1: return strdup("byte");
		case 8: return strdup("qword");
		default:
			if(taille<=0)
			{
				printf("taille=%d\n",taille);
				assert(1==0);
			}
			else
			{// plus de 8 => c'est un ptr
				return strdup("dword");
			}
	}
}

char *str_reg(SVar86 v)
{
	char buf[30],buf2[30];
	assert(v.code==EARegistre);
	
	if(v.taille>=4)
	{
		switch(v.val)
		{
			case 0: strcpy(buf,"eax");break;
			case 1: strcpy(buf,"ebx");break;
			case 2: strcpy(buf,"ecx");break;
			case 3: strcpy(buf,"edx");break;
			case 4: strcpy(buf,"esp");break;
			default:
			printf("code=%d\n",v.val);		
			assert(1==0);
		}
	}
	else if(v.taille==1)
	{
		switch(v.val)
		{
			case 0: strcpy(buf,"ah");break;
			case 1: strcpy(buf,"al");break;
			case 2: strcpy(buf,"bh");break;
			case 3: strcpy(buf,"bl");break;
			case 4: strcpy(buf,"ch");break;
			case 5: strcpy(buf,"cl");break;
			case 6: strcpy(buf,"dh");break;
			case 7: strcpy(buf,"dl");break;
			default:
			printf("code=%d\n",v.val);		
			assert(1==0);
		}
	}
	else if(v.taille==2)
	{
		switch(v.val)
		{
			case 0: strcpy(buf,"ax");break;
			case 1: strcpy(buf,"bx");break;
			case 2: strcpy(buf,"cx");break;
			case 3: strcpy(buf,"dx");break;
			case 4: strcpy(buf,"sp");break;
			case 5: strcpy(buf,"bp");break;
			default:
			printf("code=%d\n",v.val);		
			assert(1==0);
		}
	}
	else
		assert(1==0);
	
	if(v.adr)
	{
		sprintf(buf2,"%s [%s]",str_taille(v.taille),buf);
		return strdup(buf2);
	}
	else
	{
		return strdup(buf);
	}
}

char *var_str(SVar86 v,int mettre_taille_label)
{
	char buf[100];
	STable_symbol *symb;
	
	switch(v.code)
	{
		case EALabel:
			if(v.adr!=0)
				sprintf(buf,"%s [%s]",str_taille(v.taille),v.nom);
			else
				sprintf(buf,"%s %s",(mettre_taille_label)?
						str_taille(v.taille):"",v.nom);
			return strdup(buf);
		case EAVar:
			assert(v.val<=nb_var_tsymb());
			symb=recherche_tsymb_no(v.val);
			assert(symb!=NULL);
			assert(symb->nom!=NULL);
			if(v.adr)
				sprintf(buf,"%s [%s]",str_taille(v.taille),symb->nom);
			else
				sprintf(buf,"%s %s",(mettre_taille_label)?
						str_taille(v.taille):"",symb->nom);
			return strdup(buf);
		case EAEntier:
			if(v.adr)
				sprintf(buf,"%s [%d]",str_taille(v.taille),v.val);
			else
				sprintf(buf,"%d",v.val);
			return strdup(buf);
		case EAReel:
			if(v.adr)
				sprintf(buf,"%s [%g]M",str_taille(v.taille),v.val);
			else
				sprintf(buf,"%gM",v.val);
			return strdup(buf);
		case EARegistre:
			sprintf(buf,"%s",str_reg(v));
			return strdup(buf);
		default:
			printf("code=%d\n",v.code);
			assert(1==0);
	}
	assert(1==0);
}

FILE *fich_tmp=NULL;

void aff_var(STable_symbol *s)
{
	assert(s!=NULL);
	assert(fich_tmp!=NULL);
	
	//switch()
	
	if(s->code==EGlobal||s->code==ETemp)
	{
		assert(s->nom!=NULL);
		if(s->init==NULL)
		{
			//assert(strcmp("s_glob",s->nom)!=0);
			/*if(s->nom==NULL)
				fprintf(fich_tmp,"\tp%d resb %d\n",s->no_temp,s->taille);
			else*/
			fprintf(fich_tmp,"\t%s resb %d\n",s->nom,s->taille);
		}
		else
		{
			switch(s->type)
			{
				case TSTRING:
					fprintf(fich_tmp,"\t%s db %s,0\n",s->nom,s->init);
					break;
				case TREEL:
					fprintf(fich_tmp,"\t%s dd %s\n",s->nom,s->init);
					break;
				default:
					fprintf(fich_tmp,"\t%s db %s\n",s->nom,s->init);
					break;
			}
		}
	}
}

int affiche_asm86(SProgramme *prog,char *nom_fichier,int djgpp)
{
	SAsm86 *tmp1,*tmp2;
	FILE *file;
	int i;
	time_t now;
	SAsm86 *debut;
	
	//assert(debut!=NULL);
	assert(nom_fichier!=NULL);
	assert(prog!=NULL);
	
	debut=prog->code;

	printf("Affichage\n");
	file=fopen(nom_fichier,"w");
	if(file==NULL)
	{
		printf("Erreur:Impossible de creer le fichier %s\n",nom_fichier);
		return 1;
	}
	//file=stdin;
	time(&now);
	fprintf(file,"; file %s\n; %s\n",nom_fichier,asctime(localtime(&now)));
	fprintf(file,"\tBITS 32\n\tGLOBAL _test1_asm\n\tEXTERN _printf\n\n");
	if(djgpp==1)
		fprintf(file,"\tSECTION .text\n\n\n");
	else
		fprintf(file,"\tSECTION _TEXT align=4 public class=CODE USE32\n\n\n");
	tmp1=debut;
	while(tmp1!=NULL)
	{
		switch(tmp1->code)
		{
			case EAPlus:case EAMoins:
			case EAFois:case EADiv:
			case EAAnd:case EAOr:
			//case EAMod:case EADiv_r:
			case EAMov:case EACmp:
			case EAMovsx:case EAMovzx:
			case EAXor:case EAMod:
				fprintf(file,"\t%s %s,%s\n",conv_str(tmp1->code),
						var_str(tmp1->var1,0),var_str(tmp1->var2,0));
				
				break;
			case EANot:case EANeg:
				fprintf(file,"\t%s %s\n",conv_str(tmp1->code),
						var_str(tmp1->var1,0));
				break;
			case EARet:
				fprintf(file,"\t%s\n",conv_str(tmp1->code));
				break;
			case EADef_Label:
				fprintf(file,"%s:\n",tmp1->var1.nom);
				break;
			case EACall:
				fprintf(file,"\tcall %s\n",var_str(tmp1->var1,0));				
				break;
			case EAJmp:case EAJe:
			case EAJne:
				fprintf(file,"\t%s %s\n",conv_str(tmp1->code),
						var_str(tmp1->var1,0));				
				break;
			case EAPush:case EAPop:
				fprintf(file,"\t%s %s\n",conv_str(tmp1->code),
						var_str(tmp1->var1,1));				
				break;
			case EASete:case EASetne:
			case EASetg:case EASetge:
			case EASetl:case EASetle:
			case EASeta:case EASetna:
			case EASetb:case EASetnb:
			case EASetae:case EASetnae:
			case EASetbe:case EASetnbe:
				fprintf(file,"\t%s %s\n",conv_str(tmp1->code),
						var_str(tmp1->var1,1));
				break;
			case EAFld:case EAFstp:
			case EAFadd:case EAFsubr:
			case EAFmult:case EAFdivr:
			case EAFstsw:case EAFcomp:
			case EAFnstsw:
				fprintf(file,"\t%s %s\n",conv_str(tmp1->code),
						var_str(tmp1->var1,1));
				break;
			case EAFinit:case EAWait:
			case EAFtst:case EAFincstp:
			case EAFdecstp:case EASahf:
				fprintf(file,"\t%s\n",conv_str(tmp1->code));
				break;				
			default:
				printf("code=%d\n",tmp1->code);
				assert(1==0);
		}
		tmp1=tmp1->suivant;
	}
	if(djgpp==1)
	{
		fprintf(file,"\tSECTION .data\n\n_str_printf db \"int=%%d\"\n\tdb 10,0\n");
		fprintf(file,"\tSECTION .bss\n\n");
	}
	else
	{
		fprintf(file,"\tSECTION _DATA align=4 public class=DATA USE32\n\n"
					"_str_printf_int db \"int=%%d\"\n\tdb 10,0\n");
		fprintf(file,"_str_printf_str db \"str=%%s\"\n\tdb 10,0\n");
		fprintf(file,"_str_printf_float db \"flt=%%g\"\n\tdb 10,0\n");
		fprintf(file,";\tSECTION _BBS align=4 public class=code USE32\n\n");
	}
	//for(i=0;i<nb_var_tsymb()/*derner_var*/;i++)
	/*{
		fprintf(file,"\t;p%d  resd 4\n",i);
	}*/
	fich_tmp=file;
	fprintf(file,"\t; nb de variable: %d\n",nb_var_tsymb());
	parcourt_tsymb(aff_var);
	fich_tmp=NULL;
	fclose(file);
	printf("Fin d'affichage\n");
	return 0;
}

int generation_asm86(SBloc *bloc,char *nom_fichier)
{
	int res,djgpp=0;
	char *nom_obj="code.o",*nom_c="main_pascal.c",*nom_obj2="code.obj";
	SInterm *interm;
	char *nom_c2="main_pascal.obj";
	
	assert(bloc!=NULL);
	assert(nom_fichier!=NULL);
	
	interm=bloc->code;
	affiche_asm86(optimise(convertion(bloc)),nom_fichier
				//"code2.asm"
				,djgpp);
	if(djgpp==1)
		res=spawnlp(P_WAIT,"nasmw","nasmw","-f coff",nom_fichier,NULL);
	else
		res=spawnlp(P_WAIT,"nasmw","nasmw","-g -f obj -F borland",nom_fichier,NULL);
	if(res==0)
	{
		printf("Ok pour nasm\n");
		if(creer_fichier_c(nom_c)!=0)
		{
			return 1;
		}
		printf("linkage...\n");
		DEBUT(link_var);
		if(djgpp==1)
			res=spawnlp(P_WAIT,"gcc","gcc","-g -o main",nom_obj,nom_c,NULL);
		else
			res=spawnlp(P_WAIT,"bcc32","bcc32","-q -w-par -y -v -emain.exe",
						nom_obj2,nom_c2,NULL);
		FIN(link_var,"temps de linkage");
		if(res==0)
		{
			printf("Pas d'erreur durant le linkage\n");
		}
		else
		{
			printf("Erreur pendant le linkage\n");
			return 1;
		}
	}
	else
	{
		printf("Erreur avec nasm\n");
		return 1;
	}
	
	return 0;
}