#include <stdlib.h>
#include <stdio.h>

#ifdef DOUBLE_PREC
#define MESSAGE "Mode double\n"
/*
    On demande ici au préprocesseur de remplacer dans le texte du programme (le code)
    toutes les occurrences du mot "float" par "double".

    Notez que c'est un peu bourrin par rapport à ce qu'on souhaite faire ici,
    parce qu'on ne fait pas la différence entre les réels qu'on utilise pour le calcul
    et d'autres variables de type float qu'on pourrait utiliser par ailleurs.

    On pourrait de manière plus portable définir les variables dont on souhaite
    définir la précision à la compilation comme étant de type "reel", puis utiliser
    le préprocesseur pour remplacer toutes les occurrences du mot "reel" dans le code
    par soit "float" soit "double", en fonction de la définition ou non de l'étiquette
    DOUBLE_PREC.
*/
#define float double
#else
#define MESSAGE "Mode float\n"
#endif /* DOUBLE_PREC */

int main(int argc, char **argv)
{
    /* Affiche un message d'erreur si l'utilisateur oublie l'argument
     * à passer en ligne de commandes. */
    if (argc < 3) {
	fprintf(stderr, "Usage: %s x y\n", argv[0]);
	exit(EXIT_FAILURE);
    }

    printf(MESSAGE);

    /* Convertit le premier argument passé par l'utilisateur en entier. */
    int x = atoi(argv[1]);

    /* Convertit le deuxième argument passé par l'utilisateur en entier. */
    int y = atoi(argv[2]);

    /* On effectue la division! */
    float res = (float)x / (float)y;

    /*
	On affiche le résultat avec jusqu'à 20 chiffres
	avant la virgule et jusqu'à 18 chiffres après la virgule.
    */
    printf("%d / %d = %20.18f\n", x, y, res);

    return EXIT_SUCCESS;
}
