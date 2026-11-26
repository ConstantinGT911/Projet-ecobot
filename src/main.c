#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>      /* Sleep() */
#include "simulation.h"
#include "affichage.h"

int main(void)
{
    Simulation s;
    int compteur = 0;

    srand((unsigned)time(NULL));
    initialiser_simulation(&s);
    detecter_dechets(&s);

    while (s.en_cours) {
        afficher_reserve(&s);
        afficher_infos(&s);

        char touche = lire_touche();

        switch (touche) {
            case 'X': s.en_cours = 0; break;

            case 'Z': deplacer_drone(&s,  0, -1); detecter_dechets(&s); break;
            case 'S': deplacer_drone(&s,  0,  1); detecter_dechets(&s); break;
            case 'Q': deplacer_drone(&s, -1,  0); detecter_dechets(&s); break;
            case 'D': deplacer_drone(&s,  1,  0); detecter_dechets(&s); break;

            case FLECHE_HAUT:   deplacer_robot(&s,  0, -1); break;
            case FLECHE_BAS:    deplacer_robot(&s,  0,  1); break;
            case FLECHE_GAUCHE: deplacer_robot(&s, -1,  0); break;
            case FLECHE_DROITE: deplacer_robot(&s,  1,  0); break;

            case ' ':
                collecter_dechet(&s);   /* ne fait rien si conditions non remplies */
                deposer_dechet(&s);
                break;
        }

        compteur++;
        if (compteur >= DELAI) {
            faire_apparaitre_dechet(&s);
            compteur = 0;
        }
        Sleep(100);
    }

    printf("Fin de la simulation. Score : %d\n", s.nb_collectes);
    return 0;
}
