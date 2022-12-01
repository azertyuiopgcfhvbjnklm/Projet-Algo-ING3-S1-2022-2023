#ifndef BATAILLENAVALEPROJET_HEADER_H
#define BATAILLENAVALEPROJET_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>

typedef struct bateau{
    char type;
    char orientation;
    int x;
    int y;
    struct bateau* prec;
    struct bateau* suiv;
}bateau;

void initialisergrilles(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15]);
void debutpartie(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15]);
void sauvegarderpartie(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15], int nbfuseehumain);
void chargerpartie(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15], int* pointeurnbfuseehumain);
void affichagevincent(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15]);

#endif
