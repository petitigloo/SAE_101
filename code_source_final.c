/**
* \file puissance4.c
* \brief ce programme permet de jouer au puissance 4
* \author Elise MOALIGOU
* \version 1.0
* \date 20 novembre 2022
* 
* Ce programme permet de jouer une partie de puissance 4 avec deux utilisateurs reels. Chaque joueur choisi 
* un pion entre le pion X et le pion O au prealable et jouent chacun leur tour en deplacant leur pion au dessus de 
* la colonne choisie a l'aide des touches 'd' 'q' et 'espace'. A la fin de la partie le programme annonce le joueur 
* gagnant.
* 
*/

// inclusion de bibliotheques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// definition de la grille 

/** 
* \def NBLIG 6
*  definit le nombre de ligne pour le tableau
*/
/** 
* \def NBCOL 7
* definit le nombre de colonne pour le tableau
*/
#define NBLIG 6
#define NBCOL 7

/**
* \typedef t_Grille
* \brief creer le type tableau pour la grille du puissance 4, permet de stocker les indices des pions joues 
*/
typedef char t_Grille[NBLIG][NBCOL]; 



// declaration constantes

/**
* \def char PION_A = 'X'
* \brief defini l'apparence du pion du joueur A
*/

/**
* \def char PION_B = 'O'
* \brief defini l'apparence du pion du joueur B
*/

/**
* \def char VIDE = ' '
* \brief defini un caractere vide qui permet d'initialiser les cases de la grille de jeu 
*/

/**
* \def char INCONNU = ' '
* \brief defini un caractere espace afin que le joueur vainqueur soit inconnu jusqu'a ce que le joueur gagnant 
* soit connu
*/

/**
* \def char INCONNU = ' '
* \brief defini un caractere espace afin que le joueur vainqueur soit inconnu jusqu'a ce que le joueur gagnant 
* soit connu
*/

/**
* \def int COLONNE_DEB = NBCOL/2
* \brief defini la colonne ou doit se trouver le pion a l'affichage de chaque grille
*/

const char PION_A = 'X';
const char PION_B = 'O';
const char VIDE = ' ';
const char INCONNU = ' ';
const int COLONNE_DEB = NBCOL/2; 


// entetes des procedures 

/**
* \fn void initGrille(t_Grille)
* \brief Initialise la grille en affectant la constante VIDE a chacun de ses elements.
* \param g Grille, represente la grille de jeu
*/

/**
* \fn void afficher(t_Grille, char, int)
* \brief Realise l'affichage a l'ecran du contenu de la grille avec les pions deja joues. Cette procedure
* affiche aussi, au-dessus de la grille, le prochain pion a tomber : il sera affiche au-dessus de la
* colonne dont le numero est donne en parametre. Cette procedure commencera par effacer l'ecran.
* \param g Grille, represente la grille de jeu
* \param VIDE represente le pion a afficher au-dessus de la grille
* \param COLONNE_DEBUT indice de la colonne ou doit se trouver le pion au debut de chaque tour
*/

/**
* \fn void jouer(t_Grille, char, int *, int *)
* \brief Permet a un joueur de jouer son pion. La procedure fait appel a choisirColonne, afin que le
* joueur indique la colonne dans laquelle il veut jouer ; puis fait appel a trouverLigne pour definir
* la case ou ajouter le pion
* \param g Grille, represente la grille de jeu
* \param PION Caractere, correspond au pion a jouer
* \param ligne entier, correspond a la ligne ou est tombe le pion
* \param colonne  entier, correspond a la colonne ou est tombe le pion
*/

/**
* \fn void finDePartie(char)
* \brief Affiche le resultat d'une partie lorsqu'elle est terminee
* \param PION caractere qui represente le pion gagnant (PION_A ou PION_B) ou bien VIDE si
* match nul
*/

void initGrille(t_Grille);
void afficher(t_Grille, char, int);
void jouer(t_Grille, char, int *, int *);
void finDePartie(char);

// entetes des fonctions

/**
* \fn bool grillePleine(t_Grille)
* \brief Teste si toutes les cases de la grille sont occupees ou non.
* \param g Grille, represente la grille de jeu
* \return VRAI si toutes les cases de la grille sont occupees par les pions, FAUX sinon
*/

/**
* \fn int choisirColonne(t_Grille, char, int)
* \brief Un joueur voit son pion au-dessus de la grille et cette fonction doit lui permettre de "deplacer"
* son pion d'une colonne vers la gauche (par la touche 'q') ou d'une colonne vers la droite (par la
* touche 'd'). Apres chaque deplacement, la grille est reaffichee. Le joueur peut finalement
* choisir la colonne ou il souhaite faire tomber son pion (par la touche ESPACE).
* \param g Grille, represente la grille de jeu
* \param pion caractere, represente le pion a tester
* \param  colonne colonne de depart (celle au-dessus de laquelle se trouve le pion initialement)
* \return  indice de la colonne choisie par le joueur
*/

/**
* \fn int trouverLigne(t_Grille, int)
* \brief Consiste a trouver la premiere case non occupee de la colonne. Si la colonne est pleine, la
* fonction retourne -1.
* \param g Grille, represente la grille de jeu
* \param  colonne  indice de la colonne dans laquelle le pion doit tomber
* \return indice de la ligne ou le pion devra etre ajoute ou -1 si la colonne est pleine
*/

/**
* \fn bool estVainqueur(t_Grille, int, int)
* \brief Indique si le pion situe dans la case reperee par les parametres ligne et colonne a gagne la partie,
* c'est-a-dire s'il y a une ligne, une colonne ou une diagonale formee d'au moins 4 de ses pions (la
* ligne et la colonne passees en parametres correspondent a la case ou le joueur vient de jouer,
* c'est-a-dire la case a partir de laquelle il faut rechercher 4 pions successifs identiques).
* \param g Grille, represente la grille de jeu
* \param  colonne  indice de la colonne dans laquelle le pion se trouve
* \param ligne indice de la ligne dans laquelle le pion se trouve
* \return VRAI s'il y a une telle ligne de 4 a partir de la case indiquee, FAUX sinon
*/

/**
* \fn bool verif_col(t_Grille, int, int, char)
* \brief Indique si le pion situe dans la case reperee par les parametres ligne et colonne, est aligne verticalement 
* a trois autres pions egaux.
* \param g Grille, represente la grille de jeu
* \param  colonne  indice de la colonne dans laquelle le pion se trouve
* \param ligne indice de la ligne dans laquelle le pion se trouve
* \param pion caractere, represente le pion a tester
* \return VRAI s'il y a une telle ligne de 4 a partir de la case indiquee, FAUX sinon
*/
/**
* \fn bool verif_lig(t_Grille, int, int, char)
* \brief Indique si le pion situe dans la case reperee par les parametres ligne et colonne, est aligne horizontalement 
* a trois autres pions egaux.
* \param g Grille, represente la grille de jeu
* \param  colonne  indice de la colonne dans laquelle le pion se trouve
* \param ligne indice de la ligne dans laquelle le pion se trouve
* \param pion caractere, represente le pion a tester
* \return VRAI s'il y a une telle ligne de 4 a partir de la case indiquee, FAUX sinon
*/
/**
* \fn bool verif_diago_no_se(t_Grille, int, int, char)
* \brief Indique si le pion situe dans la case reperee par les parametres ligne et colonne, est aligne a trois autres pions egaux en diagonale du type : nord-ouest
* vers sud-est de la grille
* \param g Grille, represente la grille de jeu
* \param  colonne  indice de la colonne dans laquelle le pion se trouve
* \param ligne indice de la ligne dans laquelle le pion se trouve
* \param pion caractere, represente le pion a tester
* \return VRAI s'il y a une telle ligne de 4 a partir de la case indiquee, FAUX sinon
*/

/**
* \fn bool verif_diago_ne_so(t_Grille, int, int, char)
* \brief Indique si le pion situe dans la case reperee par les parametres ligne et colonne, est aligne a trois autres pions egaux en diagonale du type : nord-est
* vers sud-ouest de la grille
* \param g Grille, represente la grille de jeu
* \param  colonne  indice de la colonne dans laquelle le pion se trouve
* \param ligne indice de la ligne dans laquelle le pion se trouve
* \param pion caractere, represente le pion a tester
* \return VRAI s'il y a une telle ligne de 4 a partir de la case indiquee, FAUX sinon
*/
bool grillePleine(t_Grille);
int choisirColonne(t_Grille, char, int);
int trouverLigne(t_Grille, int);
bool estVainqueur(t_Grille, int, int);
bool verif_col(t_Grille, int, int, char);
bool verif_lig(t_Grille, int, int, char);
bool verif_diago_no_se(t_Grille, int, int, char);
bool verif_diago_ne_so(t_Grille, int, int, char);

// programme principal

/**
* \def int main()
* \brief Fonction principale, base du puissance 4 
* \return EXIT_SUCCESS
*/
int main(){

    char vainqueur;
    int ligne;
    int colonne;
    int rep;
    char commence;
    char entree;

    t_Grille g;

    initGrille(g);

    vainqueur = INCONNU;

    printf("\n\nBIENVENUE au jeu du puissance 4\n\n");
    

    printf("Connaissez-vous les regles du puissance 4 \n    si oui appuyez sur 1\n    si non appuyez sur 2\n");
    scanf("%d", &rep);

    while((rep !=1) && (rep !=2)){
        printf("Veuillez saisir 1 ou 2\n");
        scanf("%d", &rep);
    }

    if (rep == 2){
            printf("\nLes Regles du puissance 4 : \n\nCommencer une partie de puissance 4 : \n\nPour commencer une partie de puissance 4, on designe le premier joueur. Celui ci met un de ses jetons de couleur dans l'une des colonnes de son choix. Le jeton tombe alors en bas de la colonne. \nLe deuxieme joueur insere a son tour son jeton, de l'autre couleur dans la colonne de son choix. Et ainsi de suite jusqu'a obtenir une rangee de 4 jetons de meme couleur.\n\nComment gagner une partie de puissance 4 :\nPour gagner une partie de puissance 4, il suffit d'etre le premier a aligner 4 jetons de sa couleur horizontalement, verticalement et diagonalement.\nSi lors d'une partie, tous les jetons sont joues sans qu'il y est d'alignement de jetons, la partie est declaree nulle.\n\n");
            printf("\nMaintenant que vous connaissez les regles, le jeu peut commencer ! C'est parti !!!\n");
        }
    else {
        printf("\nC'est parti !!!\n");
    }

    scanf("%c%c", &commence, &entree);
    
    while((vainqueur == INCONNU) && ((grillePleine(g)) == false)){
        jouer(g, PION_A, &ligne, &colonne);

        if (estVainqueur(g, ligne, colonne)){
            system("clear");    //Linux
            //system("cls");    //Windows
            afficher(g, VIDE, COLONNE_DEB); 
            vainqueur = PION_A;
        }
        else if ((grillePleine(g)) == false){
            jouer(g, PION_B, &ligne, &colonne);
            
            if (estVainqueur(g, ligne, colonne)){
                system("clear");    //Linux
                //system("cls");    //Windows
                afficher(g, VIDE, COLONNE_DEB); 
                vainqueur = PION_B;
            }
        }

    }
    system("clear");    //Linux
    //system("cls");    //Windows
    afficher(g, VIDE, COLONNE_DEB); 
    finDePartie(vainqueur);


    return EXIT_SUCCESS;
}



// procedures et fonctions 

void initGrille(t_Grille grille){
    int ind_ligne;
    int ind_colonne;
    for (ind_ligne=0; ind_ligne < NBLIG; ind_ligne++){
        for (ind_colonne=0; ind_colonne < NBCOL; ind_colonne++){
            grille[ind_ligne][ind_colonne] = VIDE;
        }
    }
}


void afficher(t_Grille grille, char pion, int bonne_colonne){
    int i;  
    int j;
    printf("  "); 
    for (int ind = 1; ind <= bonne_colonne; ind++){
        printf("    "); 
    }
    printf("%c\n", pion);

    for (i=0; i< NBLIG; i++){
        for (j = 0; j < NBCOL; j++){
            if (grille[i][j] == VIDE){
                printf("| ");
                printf("%c", VIDE);
                printf(" ");
            }
            else if (grille[i][j] == PION_A){
                printf("| ");
                printf("%c", PION_A);
                printf(" ");
            }
            else {
                printf("| ");
                printf("%c", PION_B);
                printf(" ");
            }
        }
        printf("|\n-----------------------------\n");
    }
}


bool grillePleine(t_Grille grille){
    bool res;
    res = true;
    for (int i=0; ((i< NBLIG)&&(res== true)); i++){
        for (int j = 0; ((j < NBCOL)&&(res == true)); j++){
            if (grille[i][j] == VIDE){
                res = false;
            }
        }
    }
    return res; 
}


void jouer(t_Grille grille, char pion, int *ligne, int *colonne){
    system("clear");    //Linux
    //system("cls");    //Windows 

    *colonne = choisirColonne(grille, pion, COLONNE_DEB);
    *ligne = trouverLigne(grille, *colonne);

    while (*ligne == -1){
    system("clear");    //Linux
    //system("cls");    //Windows

        printf("La colonne est pleine ! Choisi une autre colonne \n");
        *colonne = choisirColonne(grille, pion, COLONNE_DEB);
        *ligne = trouverLigne(grille, *colonne);
    }

    grille[*ligne][*colonne] = pion;
}


int choisirColonne(t_Grille grille, char pion, int colonneDessus){

    int colonne;
    char bouger;
    char entree; 

    colonne = colonneDessus;
    
    printf("\nPion %c deplaces ton pion vers la gauche avec la touche 'q' et vers la droite avec la touche 'd', si la colonne te convient appuie sur 'espace' et valide par la touche entree\n\n", pion);

    afficher(grille, pion, colonne);
    scanf("%c%c", &bouger, &entree);

    while (bouger != ' '){
    system("clear");    //Linux
    //system("cls");    //Windows
        
        switch (bouger){
            case 'q':
                if (colonne > 0){
                colonne = colonne - 1;
                }
                else if (colonne <= 0){
                    printf("Ne sors pas !!!\n");
                }
                break;
            case 'd':
                if (colonne < (NBCOL-1)){
                    colonne = colonne + 1;
                }
                else if (colonne >= (NBCOL-1)){
                    printf("Ne sors pas !!!\n");
                }
                break;
            case ' ' : break;
            default : printf ("Probleme de saisie !\n");
                break;
        } 

        
        
        printf("\nPion %c deplaces ton pion vers la gauche avec la touche 'q' et vers la droite avec la touche 'd', si la colonne te convient appuie sur 'espace' et valide par la touche entree\n\n", pion);

        afficher(grille, pion, colonne);
        scanf("%c%c", &bouger, &entree);
        
    }

    return colonne;
}


int trouverLigne(t_Grille grille, int ind_col){

    int ind_lig;
    bool sortie;

    ind_lig = -1;
    sortie = false;

    for(int i = (NBLIG-1); ((i >= 0)&&(sortie == false)) ; i--){
        if ((grille[i][ind_col]) == VIDE){
            ind_lig = i;
            sortie = true;
        }
    }
    return ind_lig;
}


bool estVainqueur(t_Grille grille, int ligne, int colonne){

    char pion;
    bool res;

    pion = grille[ligne][colonne];
    res = false;

    if (((verif_col(grille, ligne, colonne, pion)) == true) ||
        ((verif_lig(grille, ligne, colonne, pion)) == true) ||
        ((verif_diago_no_se(grille, ligne, colonne, pion)) == true) || 
        ((verif_diago_ne_so(grille, ligne, colonne, pion)) == true))
        {
           res = true;
        }

    return res;
}


bool verif_col(t_Grille grille, int ligne, int colonne, char pion){
    bool valide;
    int compt;
    bool sortie;

    sortie = false;
    valide = false;
    compt = 1;
    for (int i = 1 ; (((ligne+i)<NBLIG)&&(compt <= 4)&&(sortie == false)) ; i++){
        if ((grille[ligne+i][colonne]) == pion){
            compt= compt +1;
        }
        else {
            sortie = true;
        }
    }
    if (compt == 4){
        valide = true;
    }
    return valide;
}


bool verif_lig(t_Grille grille, int ligne, int colonne, char pion){

    bool valide;
    int compt;
    bool sortie;

    sortie = false;
    valide = false;
    compt = 1;
    for (int i = 1; (((colonne + i) < NBCOL)&&(compt <= 4)&&(sortie == false)); i++){
        if ((grille[ligne][colonne + i]) == pion){
            compt= compt +1;
        }
        else {
            sortie = true;
        }
    }

    if(compt < 4){
        sortie = false;
        for (int i = 1; (((colonne - i) >= 0)&&(compt <= 4)&&(sortie == false)); i++){
            if ((grille[ligne][colonne - i]) == pion){
                compt = compt +1;
            }
            else {
                sortie = true;
            }
        }
    }

    if (compt >= 4){
        valide = true;
    }
    return valide;
} 


bool verif_diago_no_se(t_Grille grille, int ligne, int colonne, char pion){

    bool valide;
    int compt;
    bool sortie;

    sortie = false;
    valide = false;
    compt = 1;

    for (int i = 1; (((colonne + i) < NBCOL) &&((ligne + i) < NBLIG)&&(compt <= 4)&&(sortie == false)); i++){
        if ((grille[ligne + i][colonne + i]) == pion){
            compt= compt +1;
        }
        else {
            sortie = true;
        }
    }
    if(compt < 4){
        sortie = false;
        for (int i = 1; (((colonne - i) >= 0)&&((ligne - i) >= 0)&&(compt <= 4)&&(sortie == false)); i++){
            if ((grille[ligne - i][colonne - i]) == pion){
                compt = compt +1;
            }
            else {
                sortie = true;
            }
        }
    }

    if (compt >= 4){
        valide = true;
    }
    return valide;
}

bool verif_diago_ne_so(t_Grille grille, int ligne, int colonne, char pion){
    bool valide;
    int compt;
    bool sortie;

    sortie = false;
    valide = false;
    compt = 1;
    for (int i = 1; (((colonne - i) >= 0) && ((ligne + i) < NBLIG)&&(compt <= 4)&&(sortie == false)); i++){
        if ((grille[ligne + i][colonne - i]) == pion){
            compt= compt +1;
        }
        else {
            sortie = true;
        }
    }
    if(compt < 4){
        sortie = false;
        for (int i = 1; (((colonne + i) < NBCOL)&&((ligne - i) >= 0)&&(compt <= 4)&&(sortie == false)); i++){
            if ((grille[ligne - i][colonne + i]) == pion){
                compt = compt +1;
            }
            else {
                sortie = true;
            }
        }
    }

    if (compt >= 4){
        valide = true;
    }
    return valide;
}

void finDePartie(char vainqueur){
    if (vainqueur == PION_A){
        printf("Bravo pion X tu as gagne !!!");
    }
    else if (vainqueur == PION_B){
        printf("Bravo pion O tu as gagne !!!");
    }
    else {
        printf("Mince ... personne n'a gagne ... la grille est pleine !");
    }
}