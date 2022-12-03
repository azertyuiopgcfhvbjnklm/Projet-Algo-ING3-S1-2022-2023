//
// Created by Pelet Kamoun on 03/12/2022.
//
#include "headermenu.h"



#include"headermenu.h"
#define reset   "\x1b[0m"
#define blue   "\x1b[34m"
#define red "\x1b[31m"
#define yellow "\x1b[33m"
#define cyan "\x1B[36m"
#define green  "\x1b[32m"





int MenuSauvegarde(){
    printf("Completer");
}



int MenuAide() {
    printf(blue"Menu aide:\n\n"reset);
    printf(cyan"Les grilles\n"reset);
    printf("Grille 1: grille du joueur (affichage des navires)\n");
    printf("Grille 2: grille de l'IA qui au départ est vide(à part en mode visible)\n\n");
    printf(cyan"Les différents types de bateaux:\n"reset);
    printf("- 1 Porte-avion (7 cases)\n");
    printf("- 2 croiseurs (5 cases)\n");
    printf("- 3 destroyers (3 cases)\n");
    printf("- 4 sous-marins (1 case)\n\n");
    printf(cyan"Début de la partie\n"reset);
    printf("Au début de la partie les navires du joueur et de l'IA sont répartis aléatoirement sur la grille. C'est au joueur de commencer.\n\n");
    printf(cyan"Les actions des navires par tour de jeu\n"reset);
    printf("Il y a 3 actions possibles:\n");
    printf(yellow "1)"reset " Tirer. Le joueur tire en choisissant les coordonnées d’une case valide de l’adversaire (grille n°2).\n - Ce tir peut tomber à l’Eau, on fera apparaitre la lettre E dans la grille 2.\n"
           " - Ce tir peut toucher un navire, on utilisera un T pour symboliser que le navire a été touché. Pour couler un navire, il faut avoir touché toutes les cases qu’il occupe : un porte-avion est plus résistant qu’un simple destroyer. Dans ce cas, le navire adverse coulé disparaît de la grille n°2.\n");

    printf(yellow"2)"reset" Eclairer. Chaque joueur dispose de 4 fusées éclairantes. Le tir d’une de ces fusées dévoile un carré de 4*4 cases dans la grille adverse à partir du coin haut et gauche dont on choisit les coordonnées. Mais attention, les cases adverses de ce carré ne seront révélées que lors du tour du jeu (quelques secondes, le temps que la fusée se consume).\n");
    printf(yellow"3)"reset" Déplacer un de ses propres navires (grille 1) d’une seule case sauf s’il est coulé (un navire touché peut se déplacer) en choisissant n’importe laquelle des cases occupées par le navire concerné. Un navire ne peut pas se déplacer en diagonale. Il ne peut se déplacer que dans sa direction logique, horizontale ou verticale, et d'une seule case à la fois, et le joueur précisera le point cardinal de déplacement (est ou ouest s’il est horizontal, nord ou sud s’il est vertical). Evidemment, en cas d'obstacle (case de déplacement occupée par un autre navire ou le bord de la grille) ou de mauvaise orientation du déplacement, un navire ne pourra pas effectuer son déplacement. Une tentative de mouvement erronée devra être signalée au joueur et lui faire perdre son tour.\n\n");
    printf(cyan"Condition de victoire\n"reset);
    printf("Un joueur a gagné lorsque tous les bateaux de l'adversaire sont coulés.\n\n");
    return MenuAccueil();
}

int Quitter(){
    return 0;
}

int MenuAccueil(){

    int menu;

    printf(blue"Menu :\n");
    printf(yellow"1." blue" Lancer une partie\n"reset);
    printf(yellow"2." blue" Charger une partie \n"reset);
    printf(yellow"3."blue " Aide\n");
    printf(yellow"4."blue " Quitter\n"reset);
    printf("Entrer l'entier corespondant à votre choix >\n");
    scanf("%d", &menu);

    if(menu<1 || menu>4){
        printf(red"ERREUR: Choisissez un chiffre disponible dans le menu\n"reset);
        return MenuAccueil();
    }
    switch (menu) {

        case 1:
            //Lancer la partie
            break;

        case 2:
            return MenuSauvegarde();
            break;

        case 3:
            return MenuAide();
            break;

        case 4:
            return Quitter();


    }

}



int AffichageVictoire(){
    printf(green"VICTOIRE\n"reset);

}

int AffichageDefaite(){
    printf(red"DEFAITE\n"reset);

}



int Updategrille(){

}

int compteur(){

}





////////AVEC MENU UTIL

int MenuUtil() {
    const char *liste[] = {};
    int taille;
    int menu;

    printf(blue"Menu :\n");
    printf(yellow"1." blue" Lancer une partie\n"reset);
    printf(yellow"2." blue" Charger une partie \n"reset);
    printf(yellow"3."blue " Aide\n");
    printf(yellow"4."blue " Quitter\n"reset);
    printf("Entrer l'entier corespondant à votre choix >\n");
    scanf("%d", &menu);

    if (menu < 1 || menu > 4) {
        printf(red"ERREUR: Choisissez un chiffre disponible dans le menu\n"reset);
        return MenuUtil();

   for (int i = 0; i < taille; i++) {
            printf("%d", liste[i]);

        }

    }


}