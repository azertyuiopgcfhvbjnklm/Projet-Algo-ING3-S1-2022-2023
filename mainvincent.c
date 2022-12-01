#include "header.h"

int main() {
    //initialisation des variables (très important)
    srand(time(NULL));
    bateau grilleHUMAIN[15][15],grilleROBOT[15][15];
    char grilleTIR[15][15];
    int nbfuseehumain=4;

    //initialiser les grilles
    initialisergrilles(grilleHUMAIN,grilleROBOT,grilleTIR);

    //fonctions à utiliser
    debutpartie(grilleHUMAIN,grilleROBOT,grilleTIR);
    affichagevincent(grilleHUMAIN,grilleROBOT,grilleTIR);
    sauvegarderpartie(grilleHUMAIN,grilleROBOT,grilleTIR,nbfuseehumain);
    chargerpartie(grilleHUMAIN,grilleROBOT,grilleTIR,&nbfuseehumain);

    return 0;
}

