//
// Created by Pelet Kamoun on 01/12/2022.
//

#ifndef AFFICHAGE_HEADERAFF_H
#define AFFICHAGE_HEADERAFF_H

#include<stdio.h>
#define taille 15

typedef struct bateau
{
    char type; // ' ' pour vide, 'P' (ou 'p' si touché) pour porte avion, 'C' ou ('c' si touché) pour croiseur, 'D' ou ('d' si touché) pour destroyer ('S' ou 's' si touché) pour sous marin
    char orientation; //  'H' pour horizontal 'V' pour vertical
    int X; // correspond au premier crochet de la grille
    int Y; // correspond au deuxième crochet de la grille
    struct bateau *prec;
    struct bateau *suiv;
}bateau;




#endif //AFFICHAGE_HEADERAFF_H


/*typedef struct {
    int PorteAvion, Croiseur, Destroyer, SousMarin,TPorteAvion, TCroiseur, TDestroyer, TSousMarin;
    int g[taille][taille];
    int gIa[taille][taille];
} Grille;
