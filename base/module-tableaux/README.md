#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: test_tableau

test_tableau: test_tableau.o tableau.o

tableau.o: tableau.c tableau.h

.PHONY: clean
clean:
	rm -f *~ *.o test_tableau
	rm -rf *.dSYM # mac-erie

```

#### Corrigé du fichier tableau.c

```c
/* L'énoncé de l'exercice se trouve dans le fichier test_tableau.c.  */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "tableau.h"

void affiche(int32_t tab[], uint32_t taille)
{
    /* A implémenter! */
    for (uint32_t i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void init_interactive(int32_t tab[], uint32_t taille)
{
    /* A implémenter! */
    char tampon[11];
    printf("Entrer %d valeurs entieres\n", taille);
    for (uint32_t i = 0; i < taille; i++) {
        tab[i] = atoi(fgets(tampon, 11, stdin));
    }
}

void init_aleatoire(int32_t tab[], uint32_t taille)
{
    /* A implémenter! */
    for (uint32_t i = 0; i < taille; i++) {
        tab[i] = (rand() % 100) - 50;
    }
}

void tri_insertion(int32_t tab[], uint32_t taille)
{
    /* A implémenter! */
    /*
        Si taille <= 1, le tableau est deja trié.
        Sinon, on parcourt du 2eme au dernier élément.
    */

    for (uint32_t i = 1; i < taille; i++) {
        /*
            invariant : tab trié de 0 à i-1
        */
        int32_t tmp = tab[i]; // valeur à insérer
        /*
            Parcours du tableau dans l'ordre décroissant avec l'indice j.
            j est déclaré signé pour pouvoir comparer sa valeur à 0.
        */
        int32_t j = i - 1;
        while (j >= 0 && tab[j] > tmp) {
            tab[j+1] = tab[j]; // décalage de la case du tableau testée
            j--;
        }
        /*
            On sort du parcours à la position d'insertion pour la valeur tmp.
            Couvre le cas encadrement trouvé entre les indices j et j+1 et
            aussi le cas pas d'encadrement trouvé (j == -1). Dans les 2 cas, il
            faut mettre tmp dans la case j+1.
        */
        tab[j+1] = tmp;
    }
}

```

#### Corrigé du fichier tableau.h

```c
/* L'énoncé de l'exercice se trouve dans le fichier test_tableau.c.  */

/* Utilisation du préprocesseur C pour se protéger de l'inclusion multiple */
#ifndef _TABLEAU_H_
#define _TABLEAU_H_

#include <stdint.h>

/* Affiche les taille éléments du tableau tab. */
extern void affiche(int32_t tab[], uint32_t taille);

/* Initialise les taille éléments du tableau tab par des valeurs
 * entières entrées au clavier par l'utilisateur. */
extern void init_interactive(int32_t tab[], uint32_t taille);

/* Initialise les taille éléments du tableau tab par des valeurs
 * entières tirées aléatoirement. */
extern void init_aleatoire(int32_t tab[], uint32_t taille);

/* Trie le tableau tab à l'aide de l'algorithme de tri par
 * insertion. */
extern void tri_insertion(int32_t tab[], uint32_t taille);

#endif /* _TABLEAU_H_ */

```

#### Corrigé du fichier test_tableau.c

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "tableau.h"

int main(void)
{
    printf("nb d'elements?\n");
    char tampon[11];
    fgets(tampon, 11, stdin);
    uint32_t n = atoi(tampon);
    /* Définition d'un tableau de dimension variable*/
    int32_t tab[n];

#ifdef INTERACTIF
    /*
        On peut utiliser le préprocessur pour compiler le code avec cette
        version en ajoutant -DINTERACTIF comme option dans la ligne de
        compilation.
    */
    init_interactive(tab, n);
#else
    srand(time(NULL));	// init du générateur de nombres aléatoires
    init_aleatoire(tab, n);
#endif

    affiche(tab, n);
    tri_insertion(tab, n);
    affiche(tab, n);
    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)