#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Fonction_TP2.h"
#define Tfen 170
#define godown 30
#define p1 10

void entree ()
{
    system("cls");

    textcolor(5);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\t\t\t\t");
    printf("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("\t\t\t\t");
    printf(" *");
    textcolor(3);
    printf("             _");
    textcolor(15);
    printf("      REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE ");

    textcolor(5);
    printf("       *\n");
    printf("\t\t\t\t");
    printf(" *            ");

    textcolor(3);
    printf("|_|");
    textcolor(15);
    printf("    MINISTERE DE L'ENSEIGNEMENT SUPERIEUR ET DE LA ");
    textcolor(5);
    printf("        *\n");
    printf("\t\t\t\t");
    printf(" *           ");
    textcolor(3);
    printf("/_/");
    textcolor(15);
    printf("                   RECHERCHE SCIENTIFIQUE ");
    textcolor(5);
    printf("                   *\n");
    printf("\t\t\t\t");
    printf(" *   ");
    textcolor(15);
    printf("___  ___ _");

    textcolor(5);
    printf("                                                            *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(15);

    printf("/ _ \\/ __| |");

    textcolor(5);
    printf("                                                             *\n");
    printf("\t\t\t\t");
    printf(" * ");
    textcolor(15);

    printf("|  __/\\__ \\ |        ECOLE NATIONALE SUPERIEURE D'INFORMATIQUE");

    textcolor(5);
    printf("          *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(15);

    printf("\\___||___/_|     THEORIE DE LA PROGRAMMATION ET GRAPHES ORIENTES");

    textcolor(5);
    printf("         * \n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(15);
    printf("                                  -TPGO-");
    textcolor(5);
    printf("                              *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(3);
    printf("         --------------------------------------------------------      ");
    textcolor(5);
    printf("  *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(3);
    printf("         -");
    textcolor(15);
    printf("        Le troisieme tavail pratique de TPGO.");
    textcolor(3);
    printf("         -");
    textcolor(5);
    printf("      *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(3);
    printf("         -");
    textcolor(15);;
    printf("  Le theme est: Probleme de voyageur commerce -PVC-.");
    textcolor(3);
    printf("  -");
    textcolor(5);
    printf("        *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(3);
    printf("         -");
    textcolor(15);
    printf("  Realise par: BOUZIDI Halima et DJEBROUNI Yasmine");
    textcolor(3);
    printf("    -");
    textcolor(5);
    printf("      *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(3);
    printf("         -");
    textcolor(15);
    printf("      Option: SIQ           Groupe: 03         ");
    textcolor(3);
    printf("       -");
    textcolor(5);
    printf("        *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(3);
    printf("         -");
    textcolor(15);
    printf("  Encadre par: Dr Hadim               ");
    textcolor(3);
    printf("                -");
    textcolor(5);
    printf("      *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(3);
    printf("         -");
    textcolor(15);
    printf("  Annee Universitaire:   2018/2019         ");
    textcolor(3);
    printf("           -");
    textcolor(5);
    printf("        *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    textcolor(3);
    printf("         --------------------------------------------------------      ");
    textcolor(5);
    printf("*\n");
    printf("\t\t\t\t");
    textcolor(5);
    printf(" *  ");
    printf("                                                                         *\n");
    printf("\t\t\t\t");
    printf(" *  ");
    printf("                                                                       *\n");
    printf("\t\t\t\t");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\t\t\t\t");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

    textcolor(3);
    printf("\n\n\t\t");
    system("pause");
}


/*-----------------------------------------------------------------------------------------------------------------------------*/
void contacter ()
{
    printf("\n");
    Color(12,15);
    printf("                         **************************\n");
    printf("                         *");
    printf("  POUR NOUS CONTACTER:  * \n");
    printf("                         **************************\n");
    Color(10,15);
     printf("\n\n \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Mr. IKHERBANE Jugurta Etudiant a l'esi          |\n");
     printf(" \t|Melle.  SADI LYNDA Etudiante a l'esi            |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Adresse: Tizi-Ouzou,Algerie.                    |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Telephone: 0552-05-33-86                        |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|E_mail: dj_ikherbane@esi.dz                     |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Facebook: Jugurta Lier                          |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Adresse de l'ecole: OUED SMAR,Alger,Algerie.    |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n");
     Color(0,15);
     printf(" \t|Site web de l'ecole: www.esi.dz                 |\n");
     Color(10,15);
     printf(" \t+------------------------------------------------+\n\n");
}

int menu(int max,...)
{
   int choi,a,i,b,d,y;
   char p[tmax];
   char **choix=NULL;
   choix=malloc(max*sizeof(p));
   va_list marker;
   va_start( marker,max );     /* Initialize variable arguments. */
   for (i=0;i<max;i++)
   {
      choix[i] = va_arg( marker,char*);
   }
    va_end( marker );
    d=wherey();
    y=d;
    textcolor (selected_color);
    textbackground (selected_background);
    printf("%s\n",choix[0]);
    textbackground (not_selected_background);
    textcolor(not_selected_color);
    for (i=1;i<max;i++)
    {
        printf("%s\n",choix[i]);
    }
    abbbbb:
    while((a=getch())==224)
    {
        b=getch();
        if(b==80 && y<d+max-1)
        {
            gotoxy(1,y);
            textcolor(not_selected_color);
            i=y-d;
            textbackground (not_selected_background);
            printf("%s",choix[i]);
            y++;
            textcolor (selected_color);
            gotoxy(1,y);
            textbackground (selected_background);
            printf("%s",choix[i+1]);
        }
        if(b==72 && y>d)
        {
            gotoxy(1,y);
            textcolor(not_selected_color);
            i=y-d;
            textbackground (not_selected_background);
            printf("%s",choix[i]);
            y--;
            textcolor (selected_color);
            gotoxy(1,y);
            textbackground (selected_background);
            printf("%s",choix[i-1]);
        }


        }
        if (a!=13)goto abbbbb;

    choi=y-d;
    textbackground (not_selected_background);
    textcolor(not_selected_color);
    gotoxy(1,d+4);
    return choi+1;
}
