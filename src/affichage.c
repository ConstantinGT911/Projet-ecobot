#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "affichage.h"

void afficher_reserve(const Simulation *s)
{
    /* TODO : parcourir la grille et afficher un caractère par case,
       puis afficher le drone et le robot à leur position.
       Utiliser affichage_console.h fourni en cours. */
    (void)s;
}

void afficher_infos(const Simulation *s)
{
    printf("Dechets ramasses : %d\n", s->nb_collectes);
    printf("Drone : ZQSD | Robot : fleches | Espace : collecter/deposer | X : quitter\n");
}

char lire_touche(void)
{
    if (!_kbhit())
        return 0;

    int c = _getch();
    if (c == 0 || c == 224) {          /* touche spéciale (flèches) */
        switch (_getch()) {
            case 72: return FLECHE_HAUT;
            case 80: return FLECHE_BAS;
            case 75: return FLECHE_GAUCHE;
            case 77: return FLECHE_DROITE;
        }
        return 0;
    }
    return (char)toupper(c);
}
