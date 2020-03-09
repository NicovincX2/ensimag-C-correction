#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

struct equipe;

struct equipe
{
    /*
        Le nom ici est juste un pointeur vers une chaine de
        caractères. Vous pouvez aussi déclarer une taille fixe de la
        forme char nom[TAILLE_NOM] et recopier le nom dans cette
        chaine.
    */
    char *nom;
    /*
        Pour le reste, on essaye d'utiliser les types les plus petits
        possibles.
    */
    uint8_t victoires;
    uint8_t defaites;
    uint8_t nuls;
    uint8_t buts_marques;
    uint8_t buts_encaisses;
    int8_t diff_buts;
    uint8_t points;
};

static void jouer_match(struct equipe *e1, struct equipe *e2)
{
    /* Tirage de nombre aléatoire dans l'intervalle [0;5] */
    uint8_t buts_marques_e1 = rand() % 6;
    uint8_t buts_marques_e2 = rand() % 6;

    e1->buts_marques += buts_marques_e1;
    e2->buts_marques += buts_marques_e2;

    e1->buts_encaisses += buts_marques_e2;
    e2->buts_encaisses += buts_marques_e1;

    /*
        Astuce: transtypé en entier, un booléen vaut 1 s'il est vrai
        et 0 sinon.
    */
    e1->victoires += (buts_marques_e1 > buts_marques_e2);
    e2->victoires += (buts_marques_e2 > buts_marques_e1);

    e1->defaites += (buts_marques_e1 < buts_marques_e2);
    e2->defaites += (buts_marques_e2 < buts_marques_e1);

    e1->nuls += (buts_marques_e1 == buts_marques_e2);
    e2->nuls += (buts_marques_e1 == buts_marques_e2);

    e1->diff_buts = e1->buts_marques - e1->buts_encaisses;
    e2->diff_buts = e2->buts_marques - e2->buts_encaisses;

    /* Pour maitriser la compétence 63! */
    if (buts_marques_e1 > buts_marques_e2) {
        e1->points += 3;
    } else if (buts_marques_e1 < buts_marques_e2) {
        e2->points += 3;
    } else {
        e1->points++;
        e2->points++;
    }
}

static void afficher_equipe(struct equipe *e)
{
    /* \t pour afficher une tabulation. */
    printf("%s\t%u\t%u\t%u\t%u\t%u\t%i\t%u\n",
            e->nom,
            e->victoires,
            e->defaites,
            e->nuls,
            e->buts_marques,
            e->buts_encaisses,
            e->diff_buts,
            e->points);
}

int main(void)
{
    /* Initialisation du générateur de nombres aléatoires, utilisé
     * dans jouer_match(). */
    srand(time(NULL));

    /*
        Initialisation contractée du tableau groupeA. Chaque case du
        tableau est en fait une struct equipe, qu'un initialise avec
        la notation { champ1, champ2, ..., champN }. Notez qu'on ne
        fait pas d'allocation dynamique pour les noms d'équipe. C'est
        un choix (et pas un bug), puisqu'on est sûrs ici que la chaine
        de caractères perdure jusqu'à la fin du programme (si vous ne
        comprenez pas cette dernière remarque, vous la comprendrez
        peut-être après avoir travaillé sur les pointeurs et
        l'allocation dynamique).
    */
    struct equipe groupeA[4] = {
        { "Albanie", 0, 0, 0, 0, 0, 0, 0 },
        { "France", 0, 0, 0, 0, 0, 0, 0 },
        /*
            Romania au lieu de Roumanie, pour ne pas avoir à
            s'embêter avec l'alignement des colonnes. Ouais, c'est
            petit, je sais.
        */
        { "Romania", 0, 0, 0, 0, 0, 0, 0 },
        { "Suisse", 0, 0, 0, 0, 0, 0, 0 }
    };

    /*
        On simule tous les matchs! Chaque équipe fait 3 matches au
        total.
    */
    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = i + 1; j < 4; j++) {
            jouer_match(&groupeA[i], &groupeA[j]);
        }
    }

    /* On finit par l'affichage formaté des équipes. */
    printf("Equipe\tV\tD\tN\tbp\tpc\tdiff\tpts\n");
    for (uint8_t i = 0; i < 4; i++) {
        afficher_equipe(&groupeA[i]);
    }

    return EXIT_SUCCESS;
}
