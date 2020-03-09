#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: void

.PHONY: clean
clean:
	rm -f *~ *.o void

```

#### Corrigé du fichier void.c

```c
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

static void print_byte(uint8_t byte)
{
    /* On parcourt les bits de l'octet passé en paramètre, des poids
     * forts aux poids faibles. */
    for (int8_t pos = 7; pos >= 0; pos--) {
	/* On récupère la valeur du bits en position k dans l'octet
	   byte :

	   - on commence par construire un masque dans lequel le seul
	   bit à 1 est le bit en position k : 1 << k ;

	   - on applique un AND bit-à-bit entre l'octet byte et ce
	     masque. Par exemple, pour savoir si le bit en position 2
	     vaut 1 dans l'octet byte = 6 (00000110 en binaire), on
	     calcule:

	     byte = 0b00000110
	     mask = 0b00000010
	     0b00000110 & 0b00000010 = 0b00000010

	     Si le résultat est différent de 0, c'est que le 2e bit de
	     byte vaut 1.

	   On utilise ici l'opérateur ternaire x = cond ? val1 : val2;
	   qui affecte la valeur val1 à la variable x si la condition
	   cond est vraie, et qui affecte la valeur val2 sinon.
	   */
	uint8_t bit = (byte & (1 << pos)) != 0 ? 1 : 0;
	printf("%u", bit);
    }
    printf(" ");
}

static void print_memory(void *base, size_t size)
{
    for (uint8_t offset = 0; offset < size; offset++) {
	/* On parcourt la mémoire à partir de l'adresse base, et on
	 * avant d'octet en octet. On utilise les propriétés
	 * d'arithmétique sur les pointeurs :

	     Etant donné un pointeur p pointant sur un type t (déclaré
	     t *p par exemple), p + k fait référence à l'adresse
	     mémoire positionnée k * sizeof(t) octets après l'adresse
	     p.

	     Ici, le paramètre base représente une adresse mémoire
	     sans type (void *). Pour pouvoir récupérer le contenu de
	     la mémoire à cette adresse, on transtype cette variable :

	     uint8_t *byte = (uint8_t *)base;

	     A partir de là, on peut récupérer la valeur de l'octet pointé par :
	     *byte
	     ce qui est équivalent à :
	     *(uint8_t *)base

	     On passe ensuite à l'octet suivant en appliquant +1 à ce pointeur :
	     (uint8_t *)base + 1

	     On récupère l'octet pointé en déréférençant le pointeur :
	     *((uint8_t *)base + 1)

	     Et ainsi de suite...
	     */
	uint8_t val = *((uint8_t *)(base) + offset);
	print_byte(val);
    }
    printf("\n");
}


int main(void)
{
    uint8_t un = 1;
    print_memory(&un, sizeof(uint8_t));

    uint8_t tab[4] = { 255, 0, 255, 0 };
    print_memory(tab, 4 * sizeof(uint8_t));

    uint32_t foo = 123456;
    printf("%u = ", foo);
    print_memory(&foo, sizeof(uint32_t));
    printf("\n");

    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)