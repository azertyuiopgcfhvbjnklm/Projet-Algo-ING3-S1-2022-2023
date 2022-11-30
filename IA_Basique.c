#include "IA_Basique.h"

unsigned char EstCoule(bateau **Grille, int X, int Y)
{
    bateau maillon = Grille[X][Y];

    // Renvoie 0 si la case aux coord passés en param est touchée
    if(maillon.type > 'A' && maillon.type < 'Z')
    {
        return 0;
    }

    bateau *here = &maillon;

    // Renvoie 0 si les cases après celle passée en param sont touchées
    while(here->suiv != NULL)
    {
        here = here->suiv;
        if(here->type > 'A' && here->type < 'Z')
        {
            return 0;
        }
    }

    here = &maillon;

    // Renvoie 0 si les cases avant celle passée en param sont touchées
    while(here->prec != NULL)
    {
        here = here->prec;
        if(here->type > 'A' && here->type < 'Z')
        {
            return 0;
        }
    }
    return 1;
}

void TirIA(int Xtir, int Ytir, bateau **GrillePlacementJoueur, char **GrilleTirIA, unsigned char *touche)
{
    if(GrillePlacementJoueur[Xtir][Ytir].type == ' ' || GrillePlacementJoueur[Xtir][Ytir].type == 'E')
    {
        GrilleTirIA[Xtir][Ytir] = 'E';
        GrillePlacementJoueur[Xtir][Ytir].type = 'E';
    }
    else
    {
        GrillePlacementJoueur[Xtir][Ytir].type = tolower(GrillePlacementJoueur[Xtir][Ytir].type);
        if(EstCoule(GrillePlacementJoueur, Xtir, Ytir))
        {
            GrilleTirIA[Xtir][Ytir] = 'X';
            *touche = 0;
        }
        else
        {
            GrilleTirIA[Xtir][Ytir] = 'T';
            *touche = 1;
        }
    }
}

void  TourIA(bateau **GrillePlacementJoueur, char **GrilleTirIA, unsigned char *touche)
{
    int Xtir = rand()%15;
    int Ytir = rand()%15;
    TirIA(Xtir, Ytir, GrillePlacementJoueur, GrilleTirIA, touche);
}