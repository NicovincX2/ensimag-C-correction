#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: concatenation

.PHONY: clean
clean:
	rm -f *~ *.o concatenation

```

#### Corrigé du fichier concatenation.c

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    size_t taille_chaine = 0;
    for (int i = 1; i < argc; i++) {
        /* On calcule la taille de la chaine qui contiendra la
         * concaténation des arguments en appelant strlen, qui
         * renvoie la longueur de la chaine passée en paramètres,
         * sur chaque argument stocké dans le tableau argv. L'indice
         * 0 de ce tableau étant réservé au nom du programme
         * (./concatenation), on démarre la boucle à 1. */
        taille_chaine += strlen(argv[i]);
    }

    /* taille_chaine vaut 0 si l'utilisateur exécute le
     * programme sans argument. */
    if (taille_chaine > 0) {
        /* On réserve une place pour le caractère spécial qui marque
         * la fin d'une chaine de caractère (\0), qui n'est pas
         * comptabilisé par strlen. */
        char chaine[taille_chaine + 1];
        /* la fonction memset permet d'initialiser une zone mémoire en
         * définissant sa taille en octets et la valeur intiale désirée. */
        memset(chaine,0,taille_chaine + 1);
        for (int i = 1; i < argc; i++) {
            /* On concatène l'argument i à la suite des arguments
             * 1..i-1 déjà concaténés dans chaine. */
            strcat(chaine, argv[i]);
        }
        /* Et... tada! */
        printf("Arguments concaténés: %s.\n", chaine);
    }

    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)