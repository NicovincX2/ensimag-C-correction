#### Corrigé du fichier ifdef.c

```c
#include <stdlib.h>
#include <stdio.h>

/* On définit une macro à la compilation à l'aide de l'option -D.
 * On pourra par exemple compiler ce programme de cette façon:
 *
 *     gcc -Wall -Wextra -std=c99 -DV1 ifdef.c -o ifdef
 */
int main(void)
{
    const char *blabla;

#ifdef V1
    blabla = "Félicitations, vous avez compilé la version 1 de ce programme!\n";
#elif defined(V2)
    blabla = "Félicitations, vous avez compilé la version 2 de ce programme!\n";
#else
    blabla = "Raté! Vous n'avez défini ni V1 ni V2 à la compilation.\n";
#endif

    printf("%s\n", blabla);
     /* Ici, on vérifie que la macro BIEN_COMPRIS a bien été définie à
      * une valeur supérieure à 42. Pour la définir, on utilise
      * l'option -DBIEN_COMPRIS=43 par exemple. */
#if BIEN_COMPRIS >= 42
    printf("J'ai tout compris, en fait!\n");
#endif
    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)