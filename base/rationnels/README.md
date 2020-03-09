#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: rationnels

.PHONY: clean
clean:
	rm -f *~ *.o rationnels

```

#### Corrigé du fichier rationnels.c

```c
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/*
    On définit le type "struct rationnel" contenant deux champs:
    un numérateur et un dénominateur.
*/
struct rationnel
{
    /* numérateur */
    uint32_t n;

    /* dénominateur */
    uint32_t d;
};

/* Retourne la valeur réelle associée au rationnel r. */
static float valeur_rationnel(struct rationnel r)
{
    float ret;
    /*
        Le fait de convertir l'une des opérandes de la division en
        flottant oblige le compilateur à effectuer une division
        réelle. Si on ne fait pas ça, on effectue une division
        entière, puis on stocke le résultat (entier) de cette division
        dans un réel.
    */
    ret = (float)r.n / r.d;
    return ret;
}

/*
    Effectue la somme des rationnels r1 et r2 dans un nouveau rationnel
    r, puis retourne la valeur réelle qui lui est associée.
*/
static float somme_puis_convertit(struct rationnel r1,
                                  struct rationnel r2)
{
    float ret = 0.0;
    /*
        On utilise ici l'initialisation directe des champs de la
        structure rationnel. On aurait pu tout aussi bien déclarer r
        puis affecter ses différents champs de cette façon :

            struct rationnel r;
            r.n = r2.d * r1.n + r1.d * r2.n;
            r.d = r1.d * r2.d;
     */
    struct rationnel r = {
        r2.d * r1.n + r1.d * r2.n,
        r1.d * r2.d
    };
    ret = valeur_rationnel(r);
    return ret;
}

/*
    Retourne la somme des valeurs réelles associées aux rationnels r1
    et r2.
*/
static float convertit_puis_somme(struct rationnel r1,
                                  struct rationnel r2)
{
    float ret = 0.0;
    ret = valeur_rationnel(r1) + valeur_rationnel(r2);
    return ret;
}

int main(void)
{
    struct rationnel r1 = { 1, 7 };
    struct rationnel r2 = { 3, 4 };

    printf("%f est-il égal à %f?\n",
            somme_puis_convertit(r1, r2),
            convertit_puis_somme(r1, r2));

    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)