#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"table_symbol.h"
#include"type.h"

static STable_symbol *debut_table_symbol=NULL;
static int no_dernier=-1;
static int no_dernier_temp=0;

/*enum EType_Var2 conv_type_pascal(char *nom)
{
	if(stricmp(nom,"integer")==0)
	{
		return ETInt;
	}
	else if(stricmp(nom,"boolean")==0)
	{
		return ETBool;
	}
	else if(stricmp(nom,"char")==0)
	{
		return ETChar;
	}
	else if(stricmp(nom,"real")==0)
	{
		return ETDouble;
	}
	else if(stricmp(nom,"string")==0)
	{
		return ETString;
	}
	else
	{
		printf("code=%s\n",nom);
		assert(1==0);
		return ETInt;
	}
}

char *conv_type_pascal2(enum EType_Var2 code)
{
	switch(code)
	{
		case ETInt:
			return strdup("integer");
		case ETDouble:
			return strdup("real");
		case ETBool:
			return strdup("boolean");
		case ETChar:
			return strdup("char");
		case ETString:
			return strdup("string");
		default:
			printf("code=%d\n",code);
			assert(1==0);
			return NULL;
	}
}*/

void initialise_table_symbol(void)
{
	debut_table_symbol=NULL;
	no_dernier=0;
}

static void complete_type(STable_symbol *symbol)
{
	assert(symbol!=NULL);
	//~~~##
	symbol->taille=taille_type(symbol->type);
	/*switch(symbol->code_type)
	{
		case TINT:
			break;
		case TDOUBLE:
			break;
		case TBOOL:
			break;
		case TCHAR:
			break;
		case TSTRING:
			break;
		default:
			printf("code=%d\n",symbol->code_type);
			assert(1==0);
			break;
	}*/
}

int ajoute_nom_tsymb_temp(/*enum EType_Var2 code_type*/int type,char *init)
{
	STable_symbol *tmp;
	char buf[256];
	
	//assert();
	//printf("##############################\n");
	tmp=(STable_symbol *)malloc(sizeof(STable_symbol));
	tmp->code=ETemp;
	//tmp->code_type=code_type;
	tmp->type=type;
	sprintf(buf,"p%d_tmp",no_dernier_temp);
	tmp->nom=strdup(buf);
	tmp->no_temp=no_dernier_temp;
	tmp->nom_fonct=NULL;
	tmp->init=init;
	complete_type(tmp);
	tmp->no=no_dernier;
	no_dernier++;
	tmp->suivant=debut_table_symbol;
	debut_table_symbol=tmp;
	no_dernier_temp++;
	
	return tmp->no;
}

int ajoute_nom_tsymb_local(char *nom,char *nom_fonction,
			/*enum EType_Var2 code_type*/int type,char *init)
{
	STable_symbol *tmp;
	char buf[256];
	
	assert(nom!=NULL);
	assert(nom_fonction!=NULL);
	tmp=(STable_symbol *)malloc(sizeof(STable_symbol));
	tmp->code=ELocal;
	//tmp->code_type=code_type;
	tmp->type=type;
	sprintf(buf,"%s_local",nom);
	tmp->nom=strdup(buf);
	tmp->nom_fonct=nom_fonction;
	tmp->init=init;
	complete_type(tmp);
	tmp->no=no_dernier;
	no_dernier++;
	tmp->suivant=debut_table_symbol;
	debut_table_symbol=tmp;
	
	return tmp->no;
}

int ajoute_nom_tsymb_param(char *nom,char *nom_fonction,
			/*enum EType_Var2 code_type*/int type,char *init)
{
	STable_symbol *tmp;
	char buf[256];
	
	assert(nom!=NULL);
	assert(nom_fonction!=NULL);
	tmp=(STable_symbol *)malloc(sizeof(STable_symbol));
	tmp->code=EParam;
	//tmp->code_type=code_type;
	tmp->type=type;
	sprintf(buf,"%s_param",nom);
	tmp->nom=strdup(buf);
	tmp->nom_fonct=nom_fonction;
	tmp->init=init;
	complete_type(tmp);
	tmp->no=no_dernier;
	no_dernier++;
	tmp->suivant=debut_table_symbol;
	debut_table_symbol=tmp;
	
	return tmp->no;
}


int ajoute_nom_tsymb(char *nom,/*enum EType_Var2 code_type*/int type,char *init)
{
	STable_symbol *tmp;
	char buf[256];
	
	assert(nom!=NULL);
	tmp=(STable_symbol *)malloc(sizeof(STable_symbol));
	tmp->code=EGlobal;
	//tmp->code_type=code_type;
	tmp->type=type;
	sprintf(buf,"%s_glob",nom);
	tmp->nom=strdup(buf);
	//tmp->type=type;
	tmp->nom_fonct=NULL;
	tmp->init=init;
	complete_type(tmp);
	tmp->no=no_dernier;
	no_dernier++;
	tmp->suivant=debut_table_symbol;
	debut_table_symbol=tmp;
	
	return tmp->no;
}

void affiche_table_symbol(void)
{
	STable_symbol *tmp;
	
	printf("table des symbol:\n");
	tmp=debut_table_symbol;
	while(tmp!=NULL)
	{
		switch(tmp->code)
		{
			case EGlobal:
				printf("%d) %s:%s (global)\n",tmp->no,tmp->nom,
						conv_type_pascal2(tmp->type));
				break;
			case ELocal:
				printf("%d) %s:%s (local %s)\n",tmp->no,tmp->nom,
						conv_type_pascal2(tmp->type),
						tmp->nom_fonct);
				break;
			case EParam:
				printf("%d) %s:%s (param %s)\n",tmp->no,tmp->nom,
						conv_type_pascal2(tmp->type),
						tmp->nom_fonct);
				break;
			case ETemp:
				printf("%d) %s:%s (temp %s)\n",tmp->no,tmp->nom,
						conv_type_pascal2(tmp->type),
						(tmp->nom_fonct==NULL)? "Global":tmp->nom_fonct);
				break;
			default:
				printf("code=%d,%s:%s\n",tmp->code,tmp->nom,
						conv_type_pascal2(tmp->type));
				assert(1!=0);
		}
		tmp=tmp->suivant;
	}
}

void efface_table_symbol(void)
{
	STable_symbol *tmp1,*tmp2;
	
	tmp1=debut_table_symbol;
	while(tmp1!=NULL)
	{
		tmp2=tmp1->suivant;
		free(tmp1);
		tmp1=tmp2;
	}
	debut_table_symbol=NULL;
	no_dernier=-1;
}

void parcourt_tsymb(void (*f)(STable_symbol *))
{
	STable_symbol *tmp;
	
	assert(f!=NULL);
	
	tmp=debut_table_symbol;
	while(tmp!=NULL)
	{
		f(tmp);
		tmp=tmp->suivant;
	}
}

int parcourt_tsymb2(int (*f)(STable_symbol *))
{
	STable_symbol *tmp;
	int res=0;
	
	assert(f!=NULL);
	
	tmp=debut_table_symbol;
	while(tmp!=NULL)
	{
		res+=f(tmp);
		tmp=tmp->suivant;
	}
	
	return res;
}

STable_symbol *cherche_tsymb(char *nom,char *nom_fonct)
{
	STable_symbol *tmp;
	char buf1[256],*p;//,buf2[256],buf3[256],buf4[256];
	
	assert(nom!=NULL);
	
	/*sprintf(buf1,"%s_local",nom);
	sprintf(buf2,"%s_param",nom);
	sprintf(buf3,"%s_glob",nom);
	sprintf(buf4,"%s_tmp",nom);*/
	tmp=debut_table_symbol;
	while(tmp!=NULL)
	{
		//switch(tmp->code)
		strcpy(buf1,tmp->nom);
		p=strrchr(buf1,'_');
		if(p!=NULL)
			*p='\0';
		if(stricmp(/*tmp->nom*/buf1,nom)==0)
		{
			if(nom_fonct==NULL)
			{
				//if(stricmp(buf1,nom)==0||stricmp(buf3,nom)==0||
				//	stricmp(buf4,nom)==0)
				{
					if(tmp->nom_fonct==NULL)
						return tmp;
				}
			}
			else //if(stricmp(buf1,nom)==0||stricmp(buf3,nom)==0||
				//	stricmp(buf4,nom)==0||stricmp(buf2,nom)==0)
				{
					if(stricmp(nom_fonct,tmp->nom_fonct)==0)
						return tmp;
				}
		}
		tmp=tmp->suivant;
	}
	
	return NULL;
}

int nb_var_tsymb(void)
{
	STable_symbol *tmp;
	int nb;
	
	nb=0;
	tmp=debut_table_symbol;
	while(tmp!=NULL)
	{
		nb++;
		tmp=tmp->suivant;
	}
	
	return nb;
}

STable_symbol *recherche_tsymb_no(int no)
{
	STable_symbol *tmp;
	
	tmp=debut_table_symbol;
	while(tmp!=NULL)
	{
		if(tmp->no==no)
			return tmp;
		tmp=tmp->suivant;
	}
	
	return NULL;
}