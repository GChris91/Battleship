#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

int abs(int a)
{
    if(a<0)
    {
        a=-a;
    }

    return a;
}

void regle()
{
    printf("c'est un jeu de bataille navale, entrez les coordonnées des vos tirs au clavier pour couler les bateaux ennemis\n");
}

typedef enum
{
    VRAI,
    FAUX

}booleen;

typedef struct
{
    int ligne;
    int colonne;

}bateau;

typedef bateau bataillon[100];

void CHOIXCASES(int N,int NBB,bataillon armee[])
{
    int i;
    int j;

    for(i=0;i<NBB-1;i++)
    {
        srand(time(0));
        armee[i].ligne=1+rand()%(N-1+1);
        srand(time(0));
        armee[i].colonne=1+rand()%(N-1+1);

        for (i=0;i<NBB-1;i++)
        {
            for (j=0;j<NBB-1;i++)
            {
                if(armee[j].ligne==armee[i].ligne&&j!=i)
                {
                    while(armee[j].ligne==armee[i].ligne)
                    {
                        srand(time(0));
                        armee[i].ligne=1+rand()%(N-1+1);

                    }
                }

                if(armee[j].colonne==armee[i].colonne&&j!=i)
                {
                    while(armee[j].colonne==armee[i].colonne)
                    {
                        srand(time(0));
                        armee[i].colonne=1+rand()%(N-1+1);

                    }

                }
            }

        }
    }
}

void PROP(bateau prop,int N)
{

    printf("Ligne=");
    scanf("%d",&prop.ligne);
    while(prop.ligne<1||N<prop.ligne)
    {
        printf("Erreur,votre proposition est en dehors de la grille");
        printf("Ligne=");
        scanf("%d",&prop.ligne);
    }
    printf("Colonne=");
    scanf("%d",&prop.colonne);
    while(prop.colonne<1||N<prop.colonne)
    {
        printf("Erreur,votre proposition est en dehors de la grille");
        printf("Colonne=");
        scanf("%d",&prop.colonne);
    }
}

void VERIFIER(booleen gagner,bataillon armee[],bateau prop,int P,int NBB)
{
    int i;
    int Dist;

    for(i=0;i<NBB-1;i++)
    {
        if(armee[i].ligne==prop.ligne&&armee[i].colonne==prop.colonne)
        {
            printf("Le bateau %d est coulé",i);
            P=P+1;
            armee[i].ligne=0;
            armee[i].colonne=0;
        }
        else
        {
            if(armee[i].ligne==prop.ligne)
            {
                printf("Meme ligne que le bateau %d",i);

            }
            if(armee[i].colonne==prop.colonne)
            {
                printf("Meme colonne que le bateau %d",i);

            }
            if(armee[i].ligne+armee[i].colonne==prop.ligne+prop.colonne)
            {
                printf("Meme diagonale montante que le bateau %d",i);

            }
            if(armee[i].ligne-armee[i].colonne==prop.ligne-proposition.colonne)
            {
                printf("Meme diagonale descendante que le bateau %d",i);

            }
            Dist=abs(armee[i].ligne-prop.ligne)+abs(armee[i].colonne-prop.colonne);
            printf("Le bateau %d se trouve a %d cases de l'impact",i,Dist);

        }
    }
    if(P==NBB)
    {
        gagner=VRAI;
    }

}


int main()
{
    int NBB;
    int N;
    booleen gagner;
    int P;
    bateau prop;
    bataillon armee[100];

    regle();
    printf("Avec combien de bateaux voulez-vous jouer ?\n");
    printf("NBB=");

    do
    {
        scanf("%d",&NBB);

    }while(!(NBB>=1));

    printf("Avec combien de lignes et colonnes voulez-vous jouer ?\n");
    printf("N=");

    do
    {
        scanf("%d",&N);

    }while(!(N>=NBB));


    printf("vous jouerez donc avec %d bateaux sur une grille de %d colonnes et %d grilles",NBB,N,N);

    P=0;
    gagner=FAUX;

    CHOIXCASES(N,NBB,armee[NBB]);

    do
    {
        PROP(prop,N);

    }while(!(gagner==VRAI));

    printf("Victoire !");

    return 0;
}
