#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
LDFLAGS=-lm

all: portee

portee: portee.o point.o

.PHONY: clean
clean:
	rm -f *~ *.o portee

```

#### Corrigé du fichier portee.c

```c
#include <stdlib.h>
#include <stdio.h>

#include "point.h"

/*
    En rajoutant le mot-clé static, on limite la visibilité de la
    fonction afficher au fichier portee.c. En dehors de ce fichier, la
    fonction n'est pas visible. Elle n'entrera donc plus en conflit
    avec la fonction afficher définie dans point.c.
*/
static
void afficher(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        printf("argument %i: %s\n", i, argv[i]);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s coordX coordY\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Affichage pour du debug... */
    afficher(argc, argv);

    struct point p;
    p.x = atoi(argv[1]);
    p.y = atoi(argv[2]);

    double d = distance_origine(p);
    printf("Distance de ce point à l'origine: %lf.\n", d);

    return EXIT_SUCCESS;
}

```

#### Corrigé du fichier point.c

```c
#include <stdio.h>
#include <math.h>

#include "point.h"

/* Voir commentaires identiques dans portee.c. */
static
void afficher(struct point p)
{
    printf("(%u, %u)\n", p.x, p.y);
}

double distance_origine(struct point p)
{
    afficher(p);
    return sqrt(p.x*p.x + p.y*p.y);
}

```

#### Corrigé du fichier point.h

```c
#ifndef _POINT_H_
#define _POINT_H_

#include <stdint.h>

struct point {
    uint32_t x;
    uint32_t y;
};

/* On fournit le prototype de la fonction distance_origine pour
 * qu'elle puisse être utilisée à l'extérieur du module point, ce qui
 * corrige le problème "implicit declaration". */
extern double distance_origine(struct point p);

#endif /* _POINT_H_ */

```

[Retour au sommaire](?)