#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>     // pour isupper

int main(void)
{
    char maj;

    do {
        /*
            A la différence d'une while classique, do ... while
            garantit qu'on entre au moins une fois dans le corps de
            la boucle. On évite ainsi d'initialiser la variable maj à
            une valeur particulière, puisqu'elle sera forcément
            affectée avant le test isupper(maj).
        */
        printf("Entrez une majuscule : ");

        /* On récupère un caractère au clavier. */
        maj = getc(stdin);

        /*
            Quand on entre un caractère au clavier, on en tape en
            fait deux: le caractère en question, puis le caractère
            'entrée' pour valider notre choix. Ce caractère
            supplémentaire est placé dans une mémoire tampon, en
            attendant d'être lu par un prochain appel à getc par
            exemple. Ce caractère ne doit pas être traité par notre
            boucle principale, c'est pourquoi on vide explicitement
            la mémoire tampon associée à l'entrée standard par un
            appel à getc jusqu'à tomber sur le charactère de retour
            a la ligne '\n'.
            La boucle ci-dessous permet également de gérer le cas ou
            l'utilisateur entre plusieurs caractères au clavier avant
            d'appuyer sur 'entrée'
         */
        char nl;
        do {
            nl = getc(stdin);
        } while (nl != '\n');

        /* On s'arrête dès que le caractère est une majuscule. */
    } while (!isupper(maj));

    printf("Votre majuscule : %c\n", maj);

    return EXIT_SUCCESS;
}
