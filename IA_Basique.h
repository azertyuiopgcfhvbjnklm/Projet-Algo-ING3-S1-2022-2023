#ifndef IAMINPROJETALGO_IA_BASIQUE_H
#define IAMINPROJETALGO_IA_BASIQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct bateau
{
    char type; // ' ' pour vide, 'P' (ou 'p' si touché) pour porte avion, 'C' ou ('c' si touché) pour croiseur, 'D' ou ('d' si touché) pour destroyer ('S' ou 's' si touché) pour sous marin
    char orientation; //  'H' pour horizontal 'V' pour vertical
    int X; // correspond au premier crochet de la grille
    int Y; // correspond au deuxième crochet de la grille
    struct bateau *prec;
    struct bateau *suiv;
}bateau;

unsigned char EstCoule(bateau **Grille, int X, int Y);
void TirIA(int Xtir, int Ytir, bateau **GrillePlacementJoueur, char **GrilleTirIA, unsigned char *touche);
void  TourIA(bateau **GrillePlacementJoueur, char **GrilleTirIA, unsigned char *touche);

#endif //IAMINPROJETALGO_IA_BASIQUE_H
