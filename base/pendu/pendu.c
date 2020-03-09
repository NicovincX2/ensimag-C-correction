#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    /* La chaine de caractères à trouver, à changer selon votre inspiration. */
    const char *a_trouver = "bounty";
    /*
        Le tampon représentant les lettres trouvées / à trouver.
        Sa taille est bien strlen(a_trouver) + 1, puisque la fonction
        strlen() retourne le nombre de caractères précédant le caractère
        de fin de chaine (\0) qu'il faut donc compter à part.
    */
    size_t taille_chaine = strlen(a_trouver) + 1;
    char tampon[taille_chaine];

    /* Compteur de propositions, si on fait plus de 2^32 - 1 propositions, on est mal! */
    uint32_t n_fois = 0;

    /*
        On initialise le tampon à l'aide de snprintf(),
        qui permet d'écrire dans une chaine de caractères
        une autre chaine obtenue à l'aide d'une chaine de format
        (%quelquechose, comme ce qu'on passe en paramètre de
        printf pour afficher la valeur d'une variable).

        Ici, %s est remplacé par la chaine de caractères constante
        "______" pour former une chaine qui sera écrite dans tampon.

        snprintf(tampon, taille_chaine, "%s%s%d%s", "trop ", "bi", 1, " snprintf!");
        aurait fait tout autre chose! Si vous ne savez pas quoi, ben... Essayez!
    */
    snprintf(tampon, taille_chaine, "%s", "______");

    /*
        On utilise strcmp pour tester l'égalité de deux chaines de caractères,
        ici la chaine à trouver et le tampon. Vous remarquerez que strcmp() ne
        renvoie pas un booléen mais le nombre de différences entre les deux chaines.
        Du coup, si c'est 0, les chaines sont identiques!
     */
    while (strcmp(tampon, a_trouver) != 0) {
        printf("%s : choisissez une lettre :\n", tampon);
        char c;
        do {
            /* Ici, on récupère un caractère entré au clavier ... */
            c = getchar();
            /* ... et on boucle tant que ce caractère n'est pas une lettre. */
        } while (!isalpha(c));

        /*
            Cette variable permettra d'indiquer si la lettre proposée
            était bien dans le mot à trouver.
        */
        bool appartient = false;
        /* On parcourt les caractères de la chaine à trouver. */
        for (size_t i = 0; i < strlen(a_trouver); i++) {
            /*
                Si le caractère en position i est identique au caractère proposé,
                on dévoile le caractère en position i dans le tampon.
            */
            if (c == a_trouver[i]) {
                tampon[i] = c;
                appartient = true;
            }
        }

        /* On n'a trouvé aucune occurrence du caractère dans le mot à trouver... */
        if (!appartient) {
            printf("Raté! '%c' ne figure pas dans le mot à trouver...\n", c);
        }

        /* On n'oublie pas d'incrémenter le compteurs de propositions! */
        n_fois++;
    }

    printf("Mot trouvé en %u coups!\n", n_fois);

    return EXIT_SUCCESS;
}
