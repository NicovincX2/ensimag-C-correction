#### Corrigé du fichier Makefile

```make
CC = gcc
LD = gcc

CFLAGS=-std=c99 -Wall -Wextra -g
LDFLAGS=

# Enoncé : compléter ce Makefile avec les objectifs suivants
# Objectifs du Makefile :
# Générer la bibliothèque statique libmorseLS.a à partir du fichier objet morse.o fourni
# Générer la bibliothèque dynamique libmorseLD.so à partir du fichier objet morse.o fourni
# Générer le programme test_morse_LS à partir du code source test_morse.c fourni et de la bibliothèque statique créée libmorseLS.a
# Générer le programme test_morse_LD à partir du code source test_morse.c fourni et de la bibliothèque dynamique créée libmorseLD.so
# NOTA BENE :
#     * Ne pas générer directement test_morse_LS ou test_morse_LD à partir de test_morse.o et morse.o.
#     * L'objectif de l'exercice est de générer des bibliothèques statique (libmorseLS.a) et dynamique (libmorseLD.so)
#       et de les utiliser pour créer les programmes test_morse_LS test_morse_LD.

all: test_morse_LS test_morse_LD

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

libmorseLS.a: morse.o
	ar scr $@ $^

libmorseLD.so: morse.o
	$(LD) -shared $^ $(LDFLAGS) -o $@

test_morse_LS: test_morse.o libmorseLS.a
	$(LD) $< $(LDFLAGS) -lmorseLS -L. -o $@

test_morse_LD: test_morse.o libmorseLD.so
	$(LD) $< $(LDFLAGS) -lmorseLD -L. -o $@

.PHONY  : clean

clean:
	rm -rf test_morse.o test_morse_LS test_morse_LD libmorseLS.a libmorseLD.so


```

#### Corrigé du fichier morse.h

```c
#ifndef _MORSE_H_
#define _MORSE_H_

/* Prototypes module morse*/
extern void affiche_morse(char *);
extern void affiche_texte(char *);
extern void help();

#endif

```

#### Corrigé du fichier test_morse.c

```c
#include <stdio.h>
#include <stdlib.h>
#include "morse.h"

int main(void)
{
    /* Chaine de caractères à encoder en morse. */
    const char *message = "RMS Titanic SOS";

    /*
        Code morse à déchiffrer. Le caractère '\' indique que la définition
        de la chaine de caractères continue à la ligne suivante.
    */
    const char *code_morse = ".-. -- ... // - .. - .- -. .. -.-. // \
                              ... --- ... // .---- ..... // \
                              .- ...- .-. .. .-.. // .---- ---. .---- ..---";

    /*
        Affiche la correspondance des caractères pris en charge
        et des codes morse.
    */
    help();

    /* Allez, au boulot! */
    printf("Affichage du code Morse de la phrase : %s\n", message);
    affiche_morse(message);
    printf("Affichage de la traduction du code Morse : %s\n", code_morse);
    affiche_texte(code_morse);

    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)