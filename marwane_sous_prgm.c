#include "header.h"

// grille1: grille des tirs du joueur
// grille2: grille des bateaux du joueur
// grille3: grille des tirs de l'IA
// grille4: grille des bateaux de l'IA

void Partie(char**grille1,bateau **grille2,char**grille3,bateau **grille4,int *compt_fusee_joueur,int *compt_fusee_IA){
    char victoire=1;
    while (victoire){
        int quitter= TourJoueur(**grille1,bateau **grille2,**grille3,bateau **grille4,*compt_fusee_joueur,*compt_fusee_IA)
        if(quitter==0){
            testVictoire();
            TourIA();
            testVictoire();
        }
        else if(quitter==1){
            Sauvegarde(**grille1,bateau **grille2,**grille3,bateau **grille4,*compt_fusee_joueur,*compt_fusee_IA);
            break;
        }
        else if(quitter==2){
            break;
        }
    }

}

void TourJoueur(char**grille1,bateau **grille2,char**grille3,bateau **grille4,int *compt_fusee_joueur,int *compt_fusee_IA){
    int choixAction;
    const char *menuAction[5];
    int tailleMenuAction=5;
    choixAction=UtilMenu(menuAction,tailleMenuAction);
    switch (choixAction) {
        case 1:
            Tirer(**grille1,bateau **grille4);
            return 0;
            break;
        case 2:
            *compt_fusee_joueur= Eclairer(**grille1,bateau **grille4, *compt_fusee_joueur);
            return 0;
            break;
        case 3:
            Deplacer(bateau **grille2);
            return 0;
            break;
        case 4:
            return 1;
            break;
        case 5:
            return 2;
            break;

    }
}

void Tirer(char **grille1,bateau **grille4){
    char x;
    int y;
    printf("Saisissez les coordonées de votre frappe: (entrer d'abord la ligne puis la colonne)\n");
    fflush(stdin);
    scanf("%c",&x);
    scanf("%d",&y);
    x=x-'A';
    if(grille4[x][y].type ==' ' || grille4[x][y].type =='E'){
        grille1[x][y]='E';
    }
    else{
        grille1[x][y]='T';
        grille4[x][y].type= tolower(grille4[x][y].type);
    }


}

char Eclairer(char**grille1,bateau **grille4,int *compt_fusee_joueur){
    if(*compt_fusee_joueur!=0) {
        char x;
        int y;
        printf("Saissisez la coordonnée à éclairer:\n");
        fflush(stdin);
        scanf("%c", &x);
        scanf("%d", &y);
        x = x - 'A';
        *compt_fusee_joueur--;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                grille1[x+i][y+j]=grille4[x+i][y+j];
            }
        }
        return *compt_fusee_joueur;
    }
    else{
        printf("Vous n'avez plus de fusée d'éclairement :(");
        return *compt_fusee_joueur;
    }
}
