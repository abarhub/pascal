#ifndef _CREER_ARBRE_H_
#define _CREER_ARBRE_H_

#include"arbre.h"

void **creer_couple(void *a,void *b);
SType *creer_type_simple(char *nom);
SListe_declare_var *creer_decl_var(char *nom);
SListe_declare_var *ajoute_var_type(SListe_declare_var *var,SType *type);
SListe_declare_var *ajoute_decl_var(SListe_declare_var *liste,
	SListe_declare_var *var);
SDeclare *creer_declare_type(SType *type);
SDeclare *creer_declare_var(SListe_declare_var *var);
SDeclare *creer_proc_fonct(char *nom);
void complete_proc_fonct(SProc_fonct *elt,SListe_instr *instr);
SDeclare *ajoute_declare(SDeclare *liste,SDeclare *elt);
SExpr *creer_exp_binaire(enum ECode_exp code,SExpr *e1,SExpr *e2);
SExpr *creer_exp_unaire(enum ECode_exp code,SExpr *e);
SExpr *creer_exp_entier(int val);
SExpr *creer_exp_reel(double val);
SExpr *creer_exp_var(char *nom);
SExpr *creer_exp_string(char *nom);
SExpr *creer_exp_nil(void);
SExpr *creer_exp_true(void);
SExpr *creer_exp_false(void);
SExpr *ajoute_exp(SExpr *liste,SExpr *e);
SListe_instr *instr_affect(SExpr *var,SExpr *exp,char *label);
SListe_instr *instr_if(SExpr *exp,SListe_instr *ok,SListe_instr *pas_ok,char *label);
SListe_instr *instr_goto(char *vers_label,char *label);
SListe_instr *instr_appel(char *nom_proc,SExpr *param,char *label);
SListe_instr *instr_bloc(SListe_instr *liste,char *label);
SListe_instr *ajoute_instr(SListe_instr *liste,SListe_instr *instr);
SListe_instr *ajoute_instr_label(SListe_instr *instr,char *label);
SArbre *creer_arbre(char *nom_prog,SDeclare *decl,SListe_instr *prog_principal);
SListe_instr *instr_repeat(SExpr *exp,SListe_instr *ok,char *label);
SListe_instr *instr_while(SExpr *exp,SListe_instr *ok,char *label);

void affiche(SArbre *arbre);

#endif