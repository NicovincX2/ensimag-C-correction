#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: slab

.PHONY: clean
clean:
	rm -f *~ *.o slab

```

#### Corrigé du fichier slab.c

```c
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 12 /* taille max d'une allocation = 2^11 = 2048. */

/* Structure de données représentant une zone mémoire. */
struct data{
    /* L'adresse du début de la zone mémoire. */
    void *base;

    /* Sa taille, en octets. */
    size_t size;

    /* L'adresse de la prochaine zone mémoire disponible de même
     * taille (liste simplement chainée). */
    struct data *next;
};

/* Astuce pour calculer rapidement si un nombre est une puissance de
 * 2. */
static inline bool is_power_of_two(size_t size)
{
    return (size & (size - 1)) == 0;
}

/* Alloue et initialise à zéro la table passée en paramètre. La taille
 * de cette table est définie par la constante préprocesseur MAX. */
static void create_table(struct data ***table)
{
    /* calloc alloue + initialise à 0. */
    *table = calloc(MAX, sizeof(struct data *));
}

/* Libère la table passée en paramètre, de taille MAX. Pour chacune
 * des entrées de la table, libère aussi les zones mémoires
 * disponibles, si elles existent. */
static void destroy_table(struct data **table)
{
    for (size_t i = 0; i < MAX; i++) {
	struct data *d = table[i];
	/*
	   Attention à ne pas écrire un truc du genre :
	   free(table[i]);
	   table[i] = table[i]->next;

	   Il faut sauvegarder la cellule suivante du chainage avant
	   de libérer la cellule courante.
	   */
	while (d != NULL) {
	    table[i] = table[i]->next;
	    /* Attention, free(d) n'aurait pas suffi ici : vous
	     * devez libérez tout ce que vous avez alloué
	     * dynamiquement (autant de free que de malloc dans le
	     * code, pour être sûr de ne rien oublier :
	     * valgrind). */
	    free(d->base);
	    free(d);
	    d = table[i];
	}
    }
    free(table);
}

/*
   Alloue une nouvelle zone mémoire de taille size.
   Si il existe une zone mémoire disponible de taille size dans la table, on l'utilise.
   Sinon, on effectue une "vraie" allocation, via l'appel système malloc.

   Cett fonction arrête le programme de manière brutale (assert) si la
   taille passée en paramètre n'est pas une puissance de 2, ou dépasse MAX.
 */
static struct data *allocate(struct data **table, size_t size)
{
    struct data *ret = NULL;
    /* assert arrête le programme si la condition passée en paramètre
     * est fausse. */
    assert(size <= (1 << (MAX - 1)));
    assert(is_power_of_two(size));
    /* ffs calcule la position du premier bit à 1 en partant des
     * poids faibles (man ffs, #include <strings.h>). */
    uint8_t pos = ffs(size) - 1;
    if (table[pos] != NULL) {
	/* S'il existe une zone mémoire disponible, on la retire du
	 * chainage. */
	ret = table[pos];
	table[pos] = table[pos]->next;
    } else {
	/* Sinon, on alloue pour de vrai. */
	ret = malloc(sizeof(struct data));
	ret->base = malloc(size);
    }

    ret->size = size;
    ret->next = NULL;
    return ret;
}

/*
   Libère la zone mémoire d passée en paramètre.  Cette fonction
   n'appelle pas free : la zone mémoire libérée est chainée aux autres
   zones mémoires de même taille de la table.
 */
static void deallocate(struct data **table, struct data *d)
{
    /* Voir commentaire sur ffs ci-dessus. */
    size_t size = ffs(d->size) - 1;
    /* Insertion en tête de la liste table[size]. */
    d->next = table[size];
    table[size] = d;
}

static void test(void)
{
    struct data **table = NULL;
    printf("On cree la table des zones mémoire.\n");
    create_table(&table);

    struct data *data1 = allocate(table, 128);
    void *data1_addr = data1->base;
    printf("Nouvelle zone mémoire de taille 128 allouée à l'adresse %p.\n", data1_addr);

    deallocate(table, data1);
    printf("La zone mémoire %p a été libérée, elle est donc disponible pour une allocation future.\n",
	    data1_addr);

    struct data *data2 = allocate(table, 128);
    void *data2_addr = data2->base;
    printf("Nouvelle zone mémoire de taille 128 allouée à l'adresse %p.\n", data2_addr);
    if (data1_addr == data2_addr) {
	printf("Super! On a bien réutilisé la zone mémoire libérée précédemment!\n");
    } else {
	printf("Argh... On aurait dû réutiliser de la mémoire, et on a fait malloc à la place!\n");
    }

    struct data *data3 = allocate(table, 128);
    printf("Nouvelle zone mémoire de taille 128 allouée à l'adresse %p.\n", data3->base);

    deallocate(table, data2);
    printf("La zone mémoire %p a été libérée, elle est donc disponible pour une allocation future.\n",
	    data2->base);

    deallocate(table, data3);
    printf("La zone mémoire %p a été libérée, elle est donc disponible pour une allocation future.\n",
	    data3->base);

    printf("On détruit la table des zones mémoire.\n");
    destroy_table(table);
}


int main(void)
{
    /* Vous pourrez appeler la fonction test() qui teste le bon
     * fonctionnement de l'allocateur, dès que vous aurez implémenté
     * l'exercice. */
    test();
    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)