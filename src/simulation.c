#include <stdlib.h>
#include "simulation.h"

/* ---------- Partie B : initialisation et apparition ---------- */

void initialiser_simulation(Simulation *s)
{
    s->nb_dechets   = 0;
    s->nb_collectes = 0;
    s->en_cours     = 1;
    /* TODO (B) : remplir la grille de LIBRE, placer des OBSTACLE,
       au moins un CENTRE, positionner drone et robot sur des cases libres */
}

void faire_apparaitre_dechet(Simulation *s)
{
    /* TODO (B) : tirer une case LIBRE au hasard, y mettre DECHET,
       ajouter le déchet dans s->dechets (si nb_dechets < MAX_DECHETS) */
    (void)s;
}

/* ---------- Partie C : drone et détection ---------- */

int deplacer_drone(Simulation *s, int dx, int dy)
{
    /* TODO (C) : calculer la nouvelle position, refuser si hors grille
       ou OBSTACLE, sinon déplacer et retourner 1 (0 sinon) */
    (void)s; (void)dx; (void)dy;
    return 0;
}

void detecter_dechets(Simulation *s)
{
    /* TODO (C) : pour chaque case de la zone 3x3 centrée sur le drone,
       si c'est un DECHET, marquer le déchet correspondant detecte = 1 */
    (void)s;
}

/* ---------- Partie D : robot, collecte, transport ---------- */

int deplacer_robot(Simulation *s, int dx, int dy)
{
    /* TODO (D) : même principe que le drone (obstacles, bords) */
    (void)s; (void)dx; (void)dy;
    return 0;
}

void collecter_dechet(Simulation *s)
{
    /* TODO (D) : si le robot est sur un déchet détecté et ne porte rien :
       porte_dechet = 1, déchet collecte = 1, case redevient LIBRE */
    (void)s;
}

void deposer_dechet(Simulation *s)
{
    /* TODO (D) : si le robot est sur un CENTRE et porte un déchet :
       porte_dechet = 0, nb_collectes++ */
    (void)s;
}
