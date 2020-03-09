#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void afficher_papous(bool est_papa, bool a_poux)
{
    printf("y'a des papous ");
    if (est_papa && a_poux) {
        printf("papa à poux\n");
    } else if (est_papa && !a_poux) {
        printf("papa pas à poux\n");
    } else if (!est_papa && a_poux) {
        printf("pas papa à poux\n");
    } else {
        printf("pas papa pas à poux\n");
    }

    /*
       On pouvait aussi tout afficher en une fois, en utilisant l'opérateur ternaire ?, qui s'utilise de cette façon :
       x = condition ? val_vrai : val_faux;
       et qui affecte la valeur val_vrai dans x si condition est vraie, et affecte val_faux sinon.
       (voir plus tard compétence avancée n°38)

       printf("y'a des papous %s papa %s à poux\n",
       est_papa ? "" : "pas",
       a_poux ? "" : "pas");
       */
}

int main(void)
{
    printf("Chez les papous...\n");
    afficher_papous(true, true);
    afficher_papous(true, false);
    afficher_papous(false, true);
    afficher_papous(false, false);

    return EXIT_SUCCESS;
}
