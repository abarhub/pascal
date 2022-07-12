#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"table_symbol.h"
#include"type.h"

#define VALIDE_NO(X)	assert((X)>=0&&(X)<nb_type)

static STable_type *debut=NULL;
static int nb_type=0;

void initialise_table_type(void)
{
	int no;
	
	if(debut!=NULL)
	{
		efface_table_type();
	}
	
	no=ajoute_type_simple("int",4);
	assert(no==0);
	no=ajoute_type_simple("char",1);
	assert(no==1);
	no=ajoute_type_simple("bool",4);
	assert(no==2);
	no=ajoute_type_simple("reel",4);
	assert(no==3);
	no=ajoute_type_simple("string",256);
	assert(no==4);
	assert(no==TSTRING);
	no=ajoute_type_simple("double",8);
	assert(no==5);
	no=ajoute_type_simple("long",8);
	assert(no==6);
	//ajoute_type("");
}

void efface_table_type(void)
{
	STable_type *tmp;
	SStruct_champs *tmp2,*tmp3;
	
	while(debut!=NULL)
	{
		tmp=debut->suivant;
		if(debut->nom!=NULL)
			free(debut->nom);
		tmp2=debut->champs;
		while(tmp2!=NULL)
		{
			tmp3=tmp2->suivant;
			if(tmp2->nom!=NULL)
				free(tmp2->nom);
			free(tmp2);
			tmp2=tmp3;
		}
		free(debut);
		debut=tmp;
	}
	debut=NULL;
	nb_type=0;
}

void affiche_table_type(void)
{
	STable_type *tmp;
	
	printf("Affichage de la table des types:\n");
	tmp=debut;
	while(tmp!=NULL)
	{
		switch(tmp->code)
		{
			case ETScalaire:
				printf("%d) %s(%d)\n",tmp->no,tmp->nom,tmp->taille);
				break;
			case ETTab:
				printf("%d) %s[%d]\n",tmp->no,tmp->nom,tmp->taille);
				break;
			case ETStruct:
				printf("%d) struct %s\n",tmp->no,tmp->nom);
				break;
			case ETPtr:
				printf("%d) *%s\n",tmp->no,tmp->nom);
				break;
		}
		tmp=tmp->suivant;
	}
	printf("Fin de la table des types\n");
}

static void ajoute_type(STable_type *t)
{
	STable_type *tmp;
	
	if(debut==NULL)
	{
		debut=t;
	}
	else
	{
		tmp=debut;
		while(tmp->suivant!=NULL)
		{
			tmp=tmp->suivant;
		}
		tmp->suivant=t;
	}
}

int ajoute_type_simple(char *nom,int taille)
{
	STable_type *tmp,*tmp2;
	
	assert(taille>0);
	tmp=(STable_type*)malloc(sizeof(STable_type));
	tmp->no=nb_type;
	tmp->nom=strdup(nom);
	tmp->taille=taille;
	tmp->code=ETScalaire;
	tmp->champs=NULL;
	tmp->ptr=-1;
	tmp->suivant=NULL;
	nb_type++;
	ajoute_type(tmp);
	
	return tmp->no;
}

int ajoute_type_tab(char *nom,int taille,int ptr)
{
	STable_type *tmp,*tmp2;
	
	VALIDE_NO(ptr);
	assert(taille>0);
	tmp=(STable_type*)malloc(sizeof(STable_type));
	tmp->no=nb_type;
	tmp->nom=strdup(nom);
	tmp->taille=taille;
	tmp->champs=NULL;
	tmp->code=ETTab;
	tmp->ptr=ptr;
	tmp->suivant=NULL;
	nb_type++;
	ajoute_type(tmp);
	
	return tmp->no;
}

int ajoute_type_struct(char *nom)
{
	STable_type *tmp,*tmp2;
	
	//assert(taille>0);
	tmp=(STable_type*)malloc(sizeof(STable_type));
	tmp->no=nb_type;
	tmp->nom=strdup(nom);
	tmp->taille=-1;
	tmp->code=ETStruct;
	tmp->champs=NULL;
	tmp->suivant=NULL;
	nb_type++;
	ajoute_type(tmp);
	
	return tmp->no;
}

int ajoute_type_ptr(char *nom,int ptr)
{
	STable_type *tmp,*tmp2;
	
	VALIDE_NO(ptr);
	tmp=(STable_type*)malloc(sizeof(STable_type));
	tmp->no=nb_type;
	tmp->nom=strdup(nom);
	tmp->taille=-1;
	tmp->ptr=ptr;
	tmp->code=ETPtr;
	tmp->champs=NULL;
	tmp->suivant=NULL;
	nb_type++;
	ajoute_type(tmp);
	
	return tmp->no;
}

void ajoute_type_struct_champs(int no,char *nom,int champs)
{
	STable_type *tmp;
	SStruct_champs *tmp2,*tmp3;
	
	VALIDE_NO(no);
	VALIDE_NO(champs);	
	tmp=cherche_type(no);
	assert(tmp!=NULL);
	assert(tmp->code==ETStruct);
	tmp2=(SStruct_champs*)malloc(sizeof(SStruct_champs));
	tmp2->no=champs;
	tmp2->nom=strdup(nom);
	tmp2->suivant=NULL;
	
	if(tmp->champs==NULL)
	{
		tmp->champs=tmp2;
	}
	else
	{
		tmp3=tmp->champs;
		while(tmp3->suivant!=NULL)
		{
			tmp3=tmp3->suivant;
		}
		tmp3->suivant=tmp2;
	}
}

STable_type *cherche_type(int no)
{
	STable_type *tmp;
	
	//VALIDE_NO(no);
	tmp=debut;
	while(tmp!=NULL)
	{
		if(tmp->no==no)
			return tmp;
		tmp=tmp->suivant;
	}
	
	return NULL;
}

int taille_type(int no)
{
	STable_type *tmp;
	
	VALIDE_NO(no);
	tmp=debut;
	while(tmp!=NULL)
	{
		if(tmp->no==no)
		{
			assert(tmp->taille>0);
			return tmp->taille;
		}
		tmp=tmp->suivant;
	}
	printf("code=%d\n",no);
	assert(1==0);
	return NULL;
}

void parcourt_ttype(void (*f)(STable_type*))
{
	STable_type *tmp;
	
	tmp=debut;
	while(tmp!=NULL)
	{
		f(tmp);
		tmp=tmp->suivant;
	}
}

int conv_type_pascal(char *nom)
{
	if(stricmp(nom,"integer")==0)
	{
		return TINT;
	}
	else if(stricmp(nom,"boolean")==0)
	{
		return TBOOL;
	}
	else if(stricmp(nom,"char")==0)
	{
		return TCHAR;
	}
	else if(stricmp(nom,"real")==0)
	{
		return TREEL;
	}
	else if(stricmp(nom,"string")==0)
	{
		return TSTRING;
	}
	else
	{
		printf("code=%s\n",nom);
		assert(1==0);
		return TINT;
	}
}

char *conv_type_pascal2(int type)
{
	switch(type)
	{
		case TINT:
			return strdup("integer");
		case TREEL:
			return strdup("real");
		case TBOOL:
			return strdup("boolean");
		case TCHAR:
			return strdup("char");
		case TSTRING:
			return strdup("string");
		default:
			printf("code=%d\n",type);
			assert(1==0);
			return NULL;
	}
}