//
// Created by Pelet Kamoun on 01/12/2022.
//
#include"headeraff.h"



//taille des éléments
#define taille 15
#define porteavion 7
#define croiseur 5
#define destr 3
#define sousmarin 1

//valeur des éléments
#define v_porteavion 'P'
#define v_croiseur 'C'
#define v_destr 'D'
#define v_sousmarin 'S'
#define eau 'E'

//valeur élément touché
#define t_eau 'e'
#define t_porteavion 'p'
#define t_croiseur 'c'
#define t_destrt 'd'
#define t_sousmarin 's'


void afficherGrille(int g[taille][taille]) {
    int i, j;
    char type;
    const char ligne[] = "  +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+";
    puts("\n  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15  "
         " ");
    puts(ligne);
    for (i = 0; i < taille; i++) {
        printf("%c |", i + 'A');
        for (j = 0; j < taille; j++) {
           printf("%c",g[i][j].type);
        }
        printf("\n");
        puts(ligne);
    }



/*Grille initGrille() {
    Grille p;
    int i, j;
    p.PorteAvion = porteavion;
    p.Croiseur = croiseur;
    p.Destroyer = destr;
    p.SousMarin = sousmarin;


    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            p.g[i][j] = eau;
            p.gIa[i][j] = eau;
        }
    }

    return p;
}