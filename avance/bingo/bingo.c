#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

/* Alloue et initialise un tableau contenant la suite des entiers
 * naturels strictement positifs de l'intervalle [1; val_max] rangés à
 * des positions aléatoires. */
static uint32_t *generer_tab_aleatoire(uint32_t val_max)
{
    uint32_t *tab = NULL;
    tab = calloc(val_max, sizeof(uint32_t));
    if (tab == NULL) {
        perror("[bingo.c] Allocation du tableau");
        exit(EXIT_FAILURE);
    }
    /* Initialisation du générateur de nombres aléatoires. A chaque
     * seconde, la graine change. */
    srand(time(NULL));

    for (uint32_t i = 1; i <= val_max; i++) {
        uint32_t pos;
        do {
            pos = rand() % val_max;
        } while(tab[pos] != 0);
        tab[pos] = i;
    }

    return tab;
}

int main(void)
{
    uint32_t val = 42;
    uint32_t *tab = generer_tab_aleatoire(512);

    /* A compléter */
    for (uint32_t i = 0; i < 512; i++) {
        if (tab[i] == val) {
            printf("%u est en position %u.\n", val, i);
            /* break permet de sortir de la boucle (mais pas de la
             * fonction englobante (return) ni du programme
             * (exit)! */
            break;
        }
    }
    /* Si on avait exécuté return à la place de break ci-dessus, on
     * n'aurait pas pu atteindre cette ligne. */
    /* Consigne: cette ligne doit rester la dernière du programme. */
    free(tab);

    return EXIT_SUCCESS;
}
