#ifndef FONCTION_TP2_H_INCLUDED
#define FONCTION_TP2_H_INCLUDED
#define ligne 1000
#define colonne 100
#define tmax 50
#define selected_color 0
#define selected_background 3
#define not_selected_color 15
#define not_selected_background 0

/**< ************************************************************************************************************************* */
/**<                                                    fonctions                                                              */
/**< ************************************************************************************************************************* */
void Color(int couleurDuTexte,int couleurDeFond);
void entree ();
void contacter ();
int menu(int max,...);

#endif // FONCTION_TP2_H_INCLUDED
