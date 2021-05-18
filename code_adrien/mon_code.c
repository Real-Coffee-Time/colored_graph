// ATTENTION
// C'est de la merde

#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX 2048

/**
 * comencer a p edge x y
 * e = liaison
 * 
*/

typedef struct s_sommet {
    int nom;
    int couleur;
    int* liaisons[TAILLE_MAX];
    int nb_liaisons;
} t_sommet;

typedef t_sommet* a_sommet;


a_sommet nouveau_sommet ( int nom ) {

    a_sommet mon_sommet = malloc(sizeof(t_sommet));

    mon_sommet->nom = nom;
    mon_sommet->couleur = 0;
    mon_sommet->nb_liaisons = 0;

    return mon_sommet;

}

char* la_couleur ( int couleur ) {

    if (couleur == 0) {
        return "blanc";
    }
    else if (couleur == 1) {
        return "rouge";
    }
    else if (couleur == 2) {
        return "bleu";
    }
    else if (couleur == 3) {
        return "vert";
    }
    else {
        return "zut";
    }
    
}

void afficher_sommet ( a_sommet sommet ) {

    printf("[%d, %s]\n", sommet->nom, la_couleur(sommet->couleur));

}


int main ( int argc, char* argv[] ) {

    FILE* fichier = fopen ( argv[1], "r" );
    int nb_sommets, nb_arretes;

    fscanf(fichier, "p edge %d %d", nb_sommets, nb_arretes);

    a_sommet liste_des_sommets[nb_sommets];
    long debut = ftell(fichier);
    int sommet1, sommet2;

    for (int i=0 ; i<nb_sommets ; i++) {

        a_sommet mon_sommet = nouveau_sommet(i+1);
        liste_des_sommets[i] = mon_sommet;

        fseek(fichier, debut, 0);

        for (int j=0 ; j<nb_arretes ; j++) {

            fscanf(fichier, "e %d %d", sommet1, sommet2);

            if ( sommet1 == i ) {

                mon_sommet->liaisons[mon_sommet->nb_liaisons] = sommet2;
                mon_sommet->nb_liaisons++;

            }
            else if ( sommet2 == i ) {

                mon_sommet->liaisons[mon_sommet->nb_liaisons] = sommet1;
                mon_sommet->nb_liaisons++;

            }
        }
    }

    fclose(fichier);

    for (int i=0 ; i<nb_sommets ; i++) {

        afficher_sommet(liste_des_sommets[i]);

    }

    return 0;

}

main();