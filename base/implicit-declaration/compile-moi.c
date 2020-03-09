#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    /*
        Si on compile ce programme à l'aide de la commande :

            make

        alors on obtient un message d'erreur de ce type :

            compile-moi.c:36:10: error: implicit declaration of function 'isupper' is invalid in C99

        En effet, le compilateur indique qu'au moment de la
        compilation du fichier compile-moi.c, il ne connait pas le
        prototype de la fonction isupper. Il ne peut donc pas vérifier
        que le programme l'utilise d'une façon syntaxiquement
        correcte, à savoir que la valeur de retour est traitée
        correctement et que les paramètres qui sont passés à 'isupper'
        sont du bon type. Le prototype de la fonction 'isupper' étant
        donné dans l'entête ctype.h (voir man isupper), il suffit de
        rajouter #include <ctype.h> pour que ce programme compile
        correctement.
    */
    char lettre = 'L';

    if (isupper(lettre)) {
        printf("La lettre %c est une majuscule.\n", lettre);
    } else {
        printf("La lettre %c est une minuscule.\n", lettre);
    }

    return EXIT_SUCCESS;
}
