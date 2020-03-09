#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: somme-pairs

.PHONY: clean
clean:
	rm -f *~ *.o somme-pairs

```

#### Corrigé du fichier somme-pairs.c

```c
/*
    Enoncé :

    L'objectif de cet exercice est de calculer la somme des 10 premiers entiers
    pairs positifs (0 compris). On utilisera un tableau pour stocker ces
    entiers, et on calculera ainsi la somme de ses éléments.  Le résultat sera
    affiché sur la sortie standard.

*/

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
/*
    Ici, le nombre d'éléments du tableau est relativement petit.  On peut donc
    l'initialiser directement à l'aide de la notation :
*/
    uint8_t tab[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };

/*
    Cette écriture permet de ne pas spécifier la taille du tableau quand on le
    déclare. Elle sera automatiquement détectée par le compilateur.
    Si on ne fait pas ça, on peut toujours déclarer un tableau de 10 éléments et
    les initialiser un à un :
        uint8_t tab[10];
        tab[0] = 0;
        tab[1] = 2;
        tab[2] = 4;
        tab[3] = 6;
        tab[4] = 8;
        tab[5] = 10;
        tab[6] = 12;
        tab[7] = 14;
        tab[8] = 16;
        tab[9] = 18;

    Ou, de manière plus concise :
        uint8_t tab[10];
        for (uint8_t i = 0; i < 10; i++) {
            tab[i] = 2*i;
        }
*/
    uint8_t somme = 0;
    for (uint8_t i = 0; i < 10; i++) {
        somme += tab[i];
    }

    printf("Valeur attendue: %u.\n", somme);

    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)