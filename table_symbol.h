#ifndef _TABLE_SYMBOL_H_

typedef struct STable_symbol
{
	enum ETSymb {EGlobal,ELocal,EParam,ETemp} code;
	/*enum EType_Var2 {ETInt,ETDouble,ETBool,ETChar,ETString} code_type;*/
	int type;
	char *nom_fonct,*nom;
	char *init;
	int signee,taille;
	int no_asm,no,no_temp;
	struct STable_symbol *suivant;
} STable_symbol;

void initialise_table_symbol(void);
int ajoute_nom_tsymb_temp(int type,char *init);
int ajoute_nom_tsymb_local(char *nom,char *nom_fonction,
			int type,char *init);
int ajoute_nom_tsymb_param(char *nom,char *nom_fonction,
			int type,char *init);
int ajoute_nom_tsymb(char *nom,int type,char *init);
void affiche_table_symbol(void);
void efface_table_symbol(void);
void parcourt_tsymb(void (*f)(STable_symbol *));
int parcourt_tsymb2(int (*f)(STable_symbol *));
STable_symbol *cherche_tsymb(char *nom,char *nom_fonct);
int nb_var_tsymb(void);

//enum EType_Var2 conv_type_pascal(char *nom);
//char *conv_type_pascal2(/*enum EType_Var2 code*/int type);

STable_symbol *recherche_tsymb_no(int no);

#endif