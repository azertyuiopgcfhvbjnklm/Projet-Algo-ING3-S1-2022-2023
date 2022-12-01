#include "header.h"

int testcheminlibre(bateau grille[15][15],int i,int j,int direction,int longueur){
    if (direction==0)
    {
        for(int k=i;k<i+longueur;k++)
        {
            if(grille[k][j].type!=' ')
            {
                return 0;
            }
        }
        return 1;
    }
    else if (direction==1)
    {
        for(int k=j;k<j+longueur;k++)
        {
            if(grille[i][k].type!=' ')
            {
                return 0;
            }
        }
        return 1;
    }
}

int longueurbateau(char type){
    if(type=='S' || type=='s') return 1;
    if(type=='D' || type=='d') return 3;
    if(type=='C' || type=='c') return 5;
    if(type=='P' || type=='p') return 7;
}

void placementaleatoirebateau(char type, bateau grille[15][15]){
    int longueur=longueurbateau(type);
    while(1)
    {
        int i=rand()%15,j=rand()%15;
        int direction=rand()%2;
        if(direction==0)
        {
            if(i+longueur-1<15 && testcheminlibre(grille,i,j,direction,longueur))
            {
                for(int k=i;k<i+longueur;k++)
                {
                    grille[k][j].type=type;
                    grille[k][j].orientation='v';
                    grille[k][j].x=k;
                    grille[k][j].y=j;
                    if(k!=i){
                        grille[k][j].prec=&grille[k-1][j];
                    }
                    if(k!=i+longueur-1){
                        grille[k][j].suiv=&grille[k+1][j];
                    }
                }
                break;
            }
        }
        else if(direction==1)
        {
            if(j+longueur-1<15 && testcheminlibre(grille,i,j,direction,longueur))
            {
                for(int k=j;k<j+longueur;k++)
                {
                    grille[i][k].type=type;
                    grille[i][k].orientation='h';
                    grille[i][k].x=i;
                    grille[i][k].y=k;
                    if(k!=j){
                        grille[i][k].prec=&grille[i][k-1];
                    }
                    if(k!=j+longueur-1){
                        grille[i][k].suiv=&grille[i][k+1];
                    }
                }
                break;
            }
        }
    }
}

void initialisergrilles(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15]){
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            grilleHUMAIN[i][j].type=' ';
            grilleHUMAIN[i][j].orientation=' ';
            grilleHUMAIN[i][j].x=i;
            grilleHUMAIN[i][j].y=j;
            grilleHUMAIN[i][j].prec=NULL;
            grilleHUMAIN[i][j].suiv=NULL;
            grilleROBOT[i][j].type=' ';
            grilleROBOT[i][j].orientation=' ';
            grilleROBOT[i][j].x=i;
            grilleROBOT[i][j].y=j;
            grilleROBOT[i][j].prec=NULL;
            grilleROBOT[i][j].suiv=NULL;
            grilleTIR[i][j]=' ';
        }
    }
}

void debutpartie(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15]){
    for(int i=0;i<1;i++)
    {
        placementaleatoirebateau('P',grilleHUMAIN);
        placementaleatoirebateau('P',grilleROBOT);
    }
    for(int i=0;i<2;i++)
    {
        placementaleatoirebateau('C',grilleHUMAIN);
        placementaleatoirebateau('C',grilleROBOT);
    }

    for(int i=0;i<3;i++)
    {
        placementaleatoirebateau('D',grilleHUMAIN);
        placementaleatoirebateau('D',grilleROBOT);
    }

    for(int i=0;i<4;i++)
    {
        placementaleatoirebateau('S',grilleHUMAIN);
        placementaleatoirebateau('S',grilleROBOT);
    }
}

char cherchetype(bateau boat){
    bateau* ancre=&boat;
    while(ancre->prec!=NULL)
    {
        ancre=ancre->prec;
    }
    while(ancre->suiv!=NULL)
    {
        if(ancre->type=='P' || ancre->type=='C' || ancre->type=='D' || ancre->type=='S')
        {
            return ancre->type;
        }
        ancre=ancre->suiv;
    }
    return ancre->type;
}

void sauvegardegrillejoueur(FILE* pf,bateau grillejoueur[15][15]){
    int tab[15][15];
    for (int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            tab[i][j]=0;
        }
    }
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(grillejoueur[i][j].type==' '&&!tab[i][j])
            {
                tab[i][j]=1;
            }
            else if(grillejoueur[i][j].type!=' ' && !tab[i][j])
            {
                char type;
                type=cherchetype(grillejoueur[i][j]);
                fprintf(pf,"%c\n",type);
                bateau* ancre=&grillejoueur[i][j];
                while(ancre->prec!=NULL)
                {
                    ancre=ancre->prec;
                }
                fprintf(pf,"%d\n",ancre->x);
                fprintf(pf,"%d\n",ancre->y);
                while(ancre->suiv!=NULL)
                {
                    fprintf(pf,"%c\n",ancre->type);
                    tab[ancre->x][ancre->y]=1;
                    ancre=ancre->suiv;
                }
                tab[ancre->x][ancre->y]=1;
                fprintf(pf,"%c\n",ancre->type);
                fprintf(pf,"%c\n",grillejoueur[i][j].orientation);
            }
        }
    }
}

void sauvegarderpartie(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15], int nbfuseehumain){
    char chemin[50];
    printf("Veuillez saisir le chemin pour enregister la partie(ex: test.txt) :\n");
    gets(chemin);
    FILE* pf=NULL;
    pf=fopen(chemin,"w");
    if(pf==NULL)
    {
        printf("Probleme avec votre chemin... partie perdue :( :\n");
    }
    fprintf(pf,"%d\n",nbfuseehumain);
    sauvegardegrillejoueur(pf,grilleHUMAIN);
    sauvegardegrillejoueur(pf,grilleROBOT);
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            fprintf(pf,"%c\n",grilleTIR[i][j]);
        }
    }
    fclose(pf);
    pf=NULL;
}

void chargerbateau(int longueur, int i, int j, char orientation,char tab[7], bateau grille[15][15]){
    if (orientation=='v')
    {
        for(int k=0;k<longueur;k++)
        {
            grille[i+k][j].type=tab[k];
            grille[i+k][j].orientation='v';
            grille[i+k][j].x=i+k;
            grille[i+k][j].y=j;
            if(k!=0)
            {
                grille[i+k][j].prec=&grille[i+k-1][j];
            }
            if(k!=longueur-1)
            {
                grille[i+k][j].suiv=&grille[i+k+1][j];
            }
        }
    }
    if (orientation=='h')
    {
        for(int k=0;k<longueur;k++)
        {
            grille[i][j+k].type=tab[k];
            grille[i][j+k].orientation='h';
            grille[i][j+k].x=i;
            grille[i][j+k].y=j+k;
            if(k!=0)
            {
                grille[i][j+k].prec=&grille[i][j+k-1];
            }
            if(k!=longueur-1)
            {
                grille[i][j+k].suiv=&grille[i][j+k+1];
            }
        }
    }
}

void chargergrillejoueur(FILE* pf, bateau grille[15][15],char tab[7]){
    printf("chargement grille joueur\n");
    for(int p=0;p<10;p++)
    {
        char type,orientation;
        int longueur;
        int i,j;
        fscanf(pf,"%s",&type);
        longueur=longueurbateau(type);
        fscanf(pf,"%d",&i);
        fscanf(pf,"%d",&j);
        printf("affichage du bateau %d :\n",p+1);
        printf("type du bateau %c\n",type);
        printf("longueur du bateau %d \n",longueur);
        printf("position du bateau : i %d j %d\n",i,j);
        for(int k=0;k<longueur;k++)
        {
            printf("k %d\n",k);
            fscanf(pf,"%s",&tab[k]);
            printf("case %d : %c\n",k+1,tab[k]);
        }
        fscanf(pf,"%s",&orientation);
        printf("orientation %c\n",orientation);
        chargerbateau(longueur,i,j,orientation,tab,grille);
    }
}

void chargerpartie(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15], int* pointeurnbfuseehumain){
    char chemin[50];
    char tab[7];
    printf("Voici les parties enregistrer :\n ");
    //ICI ON AFFICHE LE REPERTOIRE
    //VOIR https://waytolearnx.com/2019/09/lister-les-fichiers-dans-un-repertoire-en-c.html
    struct dirent *dir;
    DIR *d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    printf("Quelle partie souhaitez-vous reprendre ?\n");
    gets(chemin);
    FILE* pf=fopen(chemin,"r");
    fscanf(pf,"%d\n",pointeurnbfuseehumain);
    chargergrillejoueur(pf,grilleHUMAIN,tab);
    for(int i=0;i<15;i++) {
        for (int j = 0; j < 15; j++) {
            if (grilleHUMAIN[i][j].type != ' ') {
                printf("%c  ", grilleHUMAIN[i][j].type);
            } else {
                printf(".  ");
            }
        }
        printf("\n");
    }
    chargergrillejoueur(pf,grilleROBOT,tab);
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            fscanf(pf,"%c\n",&grilleTIR[i][j]);
        }
    }
    fclose(pf);
    pf=NULL;
}

void affichagevincent(bateau grilleHUMAIN[15][15], bateau grilleROBOT[15][15], char grilleTIR[15][15]){
    printf("VOICI VOTRE GRILLE\n");
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(grilleHUMAIN[i][j].type!=' ')
            {
                printf("%c  ",grilleHUMAIN[i][j].type);
            }
            else
            {
                printf(".  ");
            }
        }
        printf("||");
        for(int j=0;j<15;j++){
            if(grilleROBOT[i][j].type!=' ')
            {
                printf("%c  ",grilleROBOT[i][j].type);
            }
            else
            {
                printf(".  ");
            }
        }
        printf("\n");
    }
}
