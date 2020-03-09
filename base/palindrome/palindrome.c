#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static bool est_palindrome(const char *mot)
{
    int32_t i = 0, j = strlen(mot) - 1;

    /*
        On itère sur les caractères de la chaine mot de gauche à
        droite avec l'indice i et de droite à gauche avec l'indice
        j. Notez qu'il est possible de passer une série d'instructions
        à une boucle for si on les sépare par une virgule: ici, à
        chaque itération, on exécute i++ ET j--.
    */
    for (i = 0; i <= j; i++, j--) {
        if (mot[i] != mot[j]) {
            return false;
        }
    }
    return true;
}

/*
    Ce prototype de fonction main permet de récupérer les arguments
    passés au programme sur la ligne de commande (ici, le mot sur
    lequel travailler).
*/
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s mot\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (est_palindrome(argv[1])) {
        printf("%s est bien un palindrome!\n", argv[1]);
    } else {
        printf("%s n'est pas un palindrome...\n", argv[1]);
    }

    return EXIT_SUCCESS;
}
