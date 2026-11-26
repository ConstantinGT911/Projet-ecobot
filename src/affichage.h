#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "simulation.h"

/* Codes renvoyés par lire_touche() pour les flèches */
#define FLECHE_HAUT    1
#define FLECHE_BAS     2
#define FLECHE_GAUCHE  3
#define FLECHE_DROITE  4

void afficher_reserve(const Simulation *s);
void afficher_infos(const Simulation *s);
char lire_touche(void);   /* non bloquant : renvoie 0 si aucune touche */

#endif
