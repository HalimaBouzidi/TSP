#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Fonction_TP2.h"
#define godown 35
#define INFINI 10000

/**< ************************************************************************************************************************* */
/**<                                                Structures                                                                 */
/**< ************************************************************************************************************************* */

int **poids;    // matrice des poids (un tableau de tableaux d'entier)
int n;		// nb de sommets
typedef struct {
    unsigned int first;
    unsigned int second;
    unsigned int weight;
} weighted_edge;
typedef struct tchemin {
	int ns;		// nombre de sommets dans le chemin
	int cout;	// coût du chemin
	int *chem;	// le chemin (un tableau de sommets)
} TypeChemin;

typedef struct tmaillon {	// un élément de la file de chemin
	TypeChemin *val;
	struct tmaillon *adr;
} Maillon;

typedef struct tfile {		// la file de chemin
	Maillon *tete;
	Maillon *queue;
} TypeFile;

/**< ************************************************************************************************************************* */
/**<                                                fonctions                                                                  */
/**< ************************************************************************************************************************* */

    static int compare_weighted_edges(const weighted_edge *edge1, const weighted_edge *edge2)
    {
        return edge1->weight - edge2->weight;
    }

    static unsigned int cyclic_recursive(const weighted_edge *edges, unsigned int n,
            unsigned int *visited, unsigned int order, unsigned int vertex,
            unsigned int predecessor)
    {
        unsigned int i;
        unsigned int cycle_found = 0;
        visited[vertex] = 1;
        for (i = 0; i < n && !cycle_found; i++) {
            if (edges[i].first == vertex || edges[i].second == vertex) {
                /* Adjacent */
                const unsigned int neighbour = edges[i].first == vertex ?
                        edges[i].second : edges[i].first;
                if (visited[neighbour] == 0) {
                    /* Not yet visited */
                    cycle_found = cyclic_recursive(edges, n, visited, order, neighbour, vertex);
                }
                else if (neighbour != predecessor) {
                    /* Found a cycle */
                    cycle_found = 1;
                }
            }
        }
        return cycle_found;
    }

    unsigned int cyclic(const weighted_edge *edges, unsigned int n, unsigned int order)
    {
        unsigned int *visited = calloc(order, sizeof(unsigned int));
        unsigned int cycle_found;
        if (visited == NULL) {
            return 0;
        }
        cycle_found  = cyclic_recursive(edges, n, visited, order, 0, 0);
        free(visited);
        return cycle_found;
    }

    weighted_edge *cheapest_link_tsp(weighted_edge *edges, unsigned int size, unsigned int order)
    {
        unsigned int t, e = 0;
        weighted_edge *tour = malloc(order * sizeof(weighted_edge));
        unsigned int *degrees = calloc(order, sizeof(unsigned int));
        if (tour == NULL || degrees == NULL) {
            free(tour);
            free(degrees);
            return NULL;
        }
        /* Sort the edges by weight */
        qsort(edges, size, sizeof(weighted_edge),
                (int(*)(const void *, const void *))compare_weighted_edges);
        /* Main algorithm */
        for (t = 0; t < order; t++) {
            unsigned int added = 0;
            while (!added && e < size) {
                if (degrees[edges[e].first] < 2 && degrees[edges[e].second] < 2) {
                    tour[t] = edges[e];
                    if (t == order - 1 /* It's the last edge */
                        || !cyclic(tour, t + 1, order)) /* It doesn't close the circuit */
                    {
                        added = 1;
                        degrees[edges[e].first]++;
                        degrees[edges[e].second]++;
                    }
                }
                e++;
            }
            if (!added) {
                /* Edges were not correct */
                free(tour);
                free(degrees);
                return NULL;
            }
        }
        free(degrees);
        return tour;
    }
    /* Connect two edges */
    void connect_i(weighted_edge *edges, unsigned int first, unsigned int second,
            unsigned int weight, unsigned int *pos)
    {
        edges[*pos].first = first;
        edges[*pos].second = second;
        edges[*pos].weight = weight;
        (*pos)++;
    }

    static void print_edges(const weighted_edge *edges, unsigned int n)
    {
        unsigned int e;
        Color(3,0);
        for (e = 0; e < n; e++) {
            //printf("(%u, %u, %u) ", edges[e].first, edges[e].second, edges[e].weight);
            printf("\t\t\t\t\t\t\t\t      (%u, %u, %u) \n", edges[e].first, edges[e].second, edges[e].weight);
        }
        putchar('\n');
    }

    void init_graph( int nbsommet );	// initialise un graphe par des poids aléatoires
    void charger_graph(char *nomfich);	// charger une matrice des poids à partir d'un fichier
    void bfs( int depart );			// parcours en largeur à partir du sommet 'depart'
    void affich();				// affiche la matrice des poids
    int Existe_dans_chemin(int j, TypeChemin *ch);	// verifie si le sommet j appartient au chemin ch
    void CreerFile( TypeFile *f );			// file FIFO ... à transformer en file de priorité
    void Enfiler( TypeFile *f, TypeChemin *ch );	// enfiler un chemin
    void Defiler( TypeFile *f, TypeChemin **ch );	// defiler un chemin
    int FileVide( TypeFile f );

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

/********************************************************************************************************************************/

void init_graph( int nbsommet )
{
int i, j;
n = nbsommet;
poids = malloc( n*sizeof(int *) );
Color(7,0);
printf("\n\tLa saisie de la matrice des couts\n");
for (i=0; i<n; i++)
    {
       poids[i] = malloc( n*sizeof(int) );
    }
for (i=0; i<n; i++)
    {
printf("\n\tEnter %d Elements in Row[%d]\n", n, i + 1);
        for (j=0; j<n; j++)
        {
            printf("\t");
           scanf("%d",&poids[i][j]);
           poids[j][i] = poids[i][j];
        }
        poids[i][i] = 0;
    }
}


void charger_graph(char *nomfich)
{
   int i, j;
   FILE *f = fopen( nomfich, "r" );
   fscanf(f, " %d", &n);

   poids = malloc( n*sizeof(int *) );
   for (i=0; i<n; i++)
	poids[i] = malloc( n*sizeof(int) );

   for (i=0; i<n; i++)
	for (j=0; j<n; j++)
	    fscanf(f, " %d", &poids[i][j]);
   fclose(f);
}


void bfs( int depart )
{
   TypeFile f;
   int i, j, k;
   long cpt = 0;
   int cout_opt = INFINI;
   TypeChemin *nouv = NULL;
   TypeChemin *cycle_opt = malloc( sizeof(TypeChemin) );
   TypeChemin *ch = malloc( sizeof(TypeChemin) );

   cycle_opt->chem = malloc( (n+1)*sizeof(int) );
   ch->chem = malloc( sizeof(int) );
   ch->ns = 1; ch->chem[0] = depart; ch->cout = 0;
   CreerFile( &f );
   Enfiler(&f, ch);
   while ( !FileVide(f) ) {
	Defiler( &f, &ch );
	if ( ch->ns == n ) {
	   // chemin contenant tous les sommets
	   ch->ns = ch->ns + 1;
	   ch->chem[ ch->ns-1 ] = depart;
	   ch->cout = ch->cout + poids[ch->chem[ch->ns-2]][depart];
	   cpt++;
//printf("Solution %4d avec un cout = %d\n", cpt, ch->cout);
	   if ( ch->cout < cout_opt ) {
		// MAJ cycle optimal
		cout_opt = ch->cout;
   		for (i=0; i < n+1; i++)
   		    cycle_opt->chem[i] = ch->chem[i];
   		cycle_opt->ns = ch->ns;
   		cycle_opt->cout = ch->cout;
	   }
	}
	else {  // ifnot ( ch[0] == n )
	   i = ch->chem[ ch->ns-1 ];  // le dernier sommet du chemin
	   for (j=0; j<n; j++)
		if ( j != depart && j != i && !Existe_dans_chemin(j,ch) )  {
		   nouv = malloc( sizeof(TypeChemin) );
		   nouv->chem = malloc( (ch->ns+2)*sizeof(int) );
 		   //nouv->chem = malloc( (n+1)*sizeof(int) );
		   for (k=0; k < ch->ns; k++)
   		    	nouv->chem[k] = ch->chem[k];
		   nouv->chem[ ch->ns ] = j;
		   nouv->ns = ch->ns+1;
		   nouv->cout = ch->cout + poids[i][j];
		   Enfiler( &f, nouv );
		}
     	} // endif ( ch[0] == n )
	free(ch->chem);
	free(ch);
   } // while
   // Affichage de la solution optimale
           printf("\n");
           Color(7,0);
            printf("\t\t\t\t\t\t+************************************************+\n");
            Color(3,0);
            printf("\t\t\t\t\t\t|             Le cycle hamiltonien               |\n");
            Color(7,0);
            printf("\t\t\t\t\t\t+************************************************+\n\n");
            printf("\t\t\t\t\t\t\t\t");
            Color(3,0);
            for (i=0; i <= n; i++)
            printf("%2d ",cycle_opt->chem[i]);
           printf("\n\n");
           Color(7,0);
           printf("\t\t\t\t\t\t\t\tSon cout est = %3d\n\t\t\t\t\t\t\t  Nombre total de solutions = %ld\n", cycle_opt->cout, cpt);
}

void affich()
{
   int i, j;
   FILE *f = fopen("graph.txt", "w");
   fprintf(f, "%d\n", n);
   printf("\n matrice des poids des aretes:\n");
   for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
	    printf("%3d ", poids[i][j]);
	    fprintf(f, "%d\n", poids[i][j]);
	}
	printf("\n");
   }
   printf("\n");
   fclose(f);
}


int Existe_dans_chemin( int j, TypeChemin *ch)
{
   int i;
   int trouv = 0;
   for (i=0; i < ch->ns && !trouv; i++)
	if ( j == ch->chem[i] ) trouv = 1;
   return trouv;
}


void CreerFile( TypeFile *f )
{
   f->tete = f->queue = NULL;
}


void Enfiler( TypeFile *f, TypeChemin *ch )
{
   Maillon *p = malloc( sizeof(Maillon) );
   p->val = ch;
   p->adr = NULL;
   if (f->queue != NULL)
	f->queue->adr = p;
   else
	f->tete = p;
   f->queue = p;
}


void Defiler( TypeFile *f, TypeChemin **ch )
{
   Maillon *p;
   if (f->tete != NULL) {
	*ch = f->tete->val;
	p = f->tete;
	f->tete = f->tete->adr;
	free(p);
	if (f->tete == NULL) f->queue = NULL;
   }
}


int FileVide( TypeFile f )
{
   return (f.tete == NULL);
}

int main()
{
    /**< Le corps du programme principale */
      int menu1; char rep[3];

    system("color 0f");
    entree();
    printf("\n\n\n\n\n\n\n\n\t\t");

     menu:
        system("color 0f");
        system("cls");
       do
        {
        Color(7, 0);
        printf("\n\n");
        printf("\t\t\t\t                           **************************\n");
        printf("\t\t\t\t                           *");
        Color(3, 0);
        printf("     MENU PRINCIPAL:    * \n");
        Color(7, 0);
        printf("\t\t\t\t                           **************************\n");
        Color(15, 0);
        printf("\n\n\t\t---->Vous choisissez l'une des operations suivantes: \n\n\n");
        Color(0, 15);
        menu1= menu(3,"\t\t01.----->Resoudre le probleme PVC par la methode Glutton.","\t\t02.----->Resoudre le probleme PVC par la methode trivial.","\t\t03.----->Quitter le programme.");
        switch (menu1)
        {
        case 1:
            do
            {
            partie1:
            system("cls");
            system("color 0f");
            printf("\n\n");
            Color(7,0);
            printf("\t\t\t\t\t\t+************************************************+\n");
            Color(3,0);
            printf("\t\t\t\t\t\t|              La methode Glutton                |\n");
            Color(7,0);
            printf("\t\t\t\t\t\t+************************************************+\n");
            //printf("\t\t\t\t****************************** La methode Glutton ****************************** \n");
            Color(6,0);
            printf("\n\n\t---->La Generation du graphe: \n\n\n");
            /******************************** Partie glutton ************************************************/

            unsigned int ent = 0;
            const unsigned int size = 15; /* Edges */
            const unsigned int order = 6; /* Vertices */
            weighted_edge *edges = malloc(size * sizeof(weighted_edge));
            weighted_edge *tour;
           int matrix[25][25], visited_cities[10], limit, cost = 0;
            int i, j;
             Color(3,0);
             printf("\tVeuillez saisir le nombre total des sommets:\t");
             scanf("%d", &limit);
             Color(7,0);
             printf("\n\tLa saisie de la matrice des couts\n");
             Color(15,0);
             for(i = 0; i < limit; i++)
             {
             printf("\n\tEnter %d Elements in Row[%d]\n", limit, i + 1);
             for(j = 0; j < limit; j++)
             {
             printf("\t");
             scanf("%d", &matrix[i][j]);
             }
             visited_cities[i] = 0;
             }
             Color(7,0);
             printf("\n\tLa matrice des couts saisie\n");
             for(i = 0; i < limit; i++)
             {
             printf("\n");
             for(j = 0; j < limit; j++)
             {
             printf("\t%d ", matrix[i][j]);
             }
             }
             int cpt = 0;
                for(i = 0;i < limit; i++)
                    for(j=i+1; j<limit; j++)
                      {
                          connect_i(edges, i, j, matrix[i][j], &ent);cpt ++;

                      }

          tour = cheapest_link_tsp(edges, cpt, limit);
          //printf("\n\t\t\t************************************* Le cycle hamiltonien *****************************************\n\n");
          printf("\n");
          Color(7,0);
            printf("\t\t\t\t\t\t+************************************************+\n");
            Color(3,0);
            printf("\t\t\t\t\t\t|             Le cycle hamiltonien               |\n");
            Color(7,0);
            printf("\t\t\t\t\t\t+************************************************+\n\n");
          print_edges(tour, limit);

          free(tour);
          free(edges);
          Color(10,0);
                printf("\n\n\n\t\t\t\t- Voulez-vous essayer une autre fois ?(oui/non) ");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto menu;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto quit;
                    }

            /****Générer le graphe complet***/

                /*********************** Traitement glutton et affichage *****************/

            }while ((menu1 <1) || (menu1 >3));
            break;
            case 2:
                partie2:
                    do
                    {
                system("cls");
                system("color 0f");
                printf("\n\n");
                Color(7,0);
                printf("\t\t\t\t\t\t+************************************************+\n");
                Color(3,0);
                printf("\t\t\t\t\t\t|             La methode Triviale                |\n");
                Color(7,0);
                printf("\t\t\t\t\t\t+************************************************+\n");
                //printf("\t\t\t\t****************************** La methode Glutton ****************************** \n");
                Color(6,0);
                printf("\n\n\t---->La Generation du graphe: \n\n\n");
                Color(3,0);
                printf("\tVeuillez saisir le nombre total des sommets:\t");
                scanf("%d", &n);
                init_graph(n);
                bfs(0);
                Color(10,0);
                printf("\n\n\n\t\t\t\t- Voulez-vous essayer une autre fois ?(oui/non) ");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto menu;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto quit;
                    }
                /*****/

                }while ((menu1 <1) || (menu1 >7));
                break;
            case 3:
                quit:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(13,15);
                    printf("\t-Vous avez choisi de quitter ce programme.\n");
                    Color(8,15);
                    printf("\n\n\t\tVoulez-vous vraiment quitter ce programme.\n");
                    Color(12,15);
                    printf("                         01-oui          02-non     ");
                    Color(0,15);
                    printf("\n\n\tChoisissez votre reponse: ");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0)
                    {
                        goto end;
                    }
                    if (strcmpi (rep, "non")== 0)
                    {
                        goto menu;
                    }
                    break;
            default:
                    system("cls");
                    system("color f0");
                    printf("\n");
                    Color(12,15);
                    printf("\n\t-Votre choix est incorrecte. Le chois doit etre \n");
                    printf("              compris entre 1 et 5.\n");
                    Color(2,15);
                    printf("\n\n\n\t\t\t-Voulez vous essayer une autre fois ?(oui/non)");
                    scanf("%s", &rep);
                    if (strcmpi(rep, "oui")== 0 )
                    {
                        goto menu;
                    }
                    if (strcmpi(rep, "non")== 0)
                    {
                        goto quit;
                    }
            }
        }while ((menu1 <1) || (menu1 >4));
    end:
        return 0;
}
