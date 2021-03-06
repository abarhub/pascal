#ifndef _TYPE_H_
#define _TYPE_H_

typedef struct SStruct_champs
{
	int no;
	char *nom;
	struct SStruct_champs *suivant;
} SStruct_champs;

typedef struct STable_type
{
	enum {ETScalaire,ETTab,ETStruct,ETPtr} code;
	int no,ptr;
	char *nom;
	int taille;
	SStruct_champs *champs;
	struct STable_type *suivant;
} STable_type;

#define TINT  (0)
#define TCHAR  (1)
#define TBOOL  (2)
#define TREEL  (3)
#define TSTRING  (4)
#define TDOUBLE  (5)
#define TLONG  (6)

void initialise_table_type(void);
void efface_table_type(void);
void affiche_table_type(void);
int ajoute_type_simple(char *nom,int taille);
int ajoute_type_tab(char *nom,int taille,int ptr);
int ajoute_type_struct(char *nom);
int ajoute_type_ptr(char *nom,int ptr);
STable_type *cherche_type(int no);
int taille_type(int no);
void parcourt_ttype(void (*f)(STable_type*));
void ajoute_type_struct_champs(int no,char *nom,int champs);

/*enum EType_Var2*/int conv_type_pascal(char *nom);
char *conv_type_pascal2(/*enum EType_Var2 code*/int type);


#endif