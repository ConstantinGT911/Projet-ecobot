#ifndef SIMULATION_H
#define SIMULATION_H

/* ===== Constantes ===== */
#define LARGEUR      30
#define HAUTEUR      15
#define MAX_DECHETS  50
#define DELAI        50   /* nb de tours entre deux apparitions de déchets */

#define LIBRE        0
#define OBSTACLE     1
#define CENTRE       2
#define DECHET       3

/* ===== Structures ===== */
typedef struct {
    int x;   /* colonne */
    int y;   /* ligne   */
} Position;

typedef struct {
    Position pos;
} Drone;

typedef struct {
    Position pos;
    int porte_dechet;   /* 0 ou 1 */
} Robot;

typedef struct {
    Position pos;
    int detecte;        /* 0 ou 1 */
    int collecte;       /* 0 ou 1 */
} Dechet;

typedef struct {
    int    grille[HAUTEUR][LARGEUR];
    Drone  drone;
    Robot  robot;
    Dechet dechets[MAX_DECHETS];
    int    nb_dechets;
    int    nb_collectes;
    int    en_cours;
} Simulation;

/* ===== Prototypes (aucun affichage ici) ===== */
void initialiser_simulation(Simulation *s);          /* B */
void faire_apparaitre_dechet(Simulation *s);         /* B */
int  deplacer_drone(Simulation *s, int dx, int dy);  /* C */
void detecter_dechets(Simulation *s);                /* C */
int  deplacer_robot(Simulation *s, int dx, int dy);  /* D */
void collecter_dechet(Simulation *s);                /* D */
void deposer_dechet(Simulation *s);                  /* D */

#endif
