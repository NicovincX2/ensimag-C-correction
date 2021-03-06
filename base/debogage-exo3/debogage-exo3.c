#include <stdio.h>
#include <stdint.h>

int main()
{
    /*
      i est un entier non signé. Il ne sera jamais inférieur à 0.
    */
    uint16_t i;
    /*
      Quand i arrive à 0, --i affecte la borne maximale 65 535 du type uint16_t à i
      et non pas -1. Le test i >= 0 est donc toujours vrai, d'où la boucle infinie.
      i est décrémenté de façon infinie depuis cette borne maximale 65 535 jusqu'à 0.
    */
    for (i = 12; i >= 0; --i) {
	printf("i = %d\n", i);
    }
}

/* MARKDOWN */
/*
# Correction debogage-exo3

Résumé : variable `i` de type entier non signé

### Warnings compilation : aucun

### Valgrind : pas d'erreur

### gdb/ddd :

Cela permet de voir ce qui se passe quand i = 0, `--i` donne comme résultat la valeur maximale d'un `uint16_t`

	gcc debogage-exo3.c -o debogage-exo3 -std=c99 -Wall -Wextra –g
	ddd ./ debogage-exo3
		# break au niveau de la boucle for
		graph display i

![screenshot ddd](solution-ddd.jpg)

<video controls src="http://ensiwiki.ensimag.fr/images/9/9d/Solution-debogage-exo3.mp4"> Vidéo de démonstration d'utilisation de ddd </video>

### Conclusion :

`i`, de type `uint16_t`, est ici codé sur 16 bits et peut donc prendre une valeur entre _0_ et _2^16 – 1_ soit _65 535_.
Quand `i` est égal à 0 et que l’opération `i = i -1` (ou : `--i`) est effectuée, le résultat n’est pas une erreur :
`i` ayant atteint le début (minimum) de la plage de valeurs qu’il peut prendre, `i = i - 1` va positionner `i`
_à la fin_ (maximum) de la plage de valeurs soit _65 535_. On aura donc le test `i >= 0` toujours vrai.
*/

