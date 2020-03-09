#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: preproc

.PHONY: clean
clean:
	rm -f *~ *.o preproc

```

#### Corrigé du fichier preproc.c

```c
#include <stdlib.h>
#include <stdio.h>

#define BOWIE "ch?v=AZKcl4-tcuo\n"
#define oO printf(
#define DAVID "be.com/wat"
#define TO "utu"
#define TRIBUTE "https://www.yo"
#define Oo );

int main(void)
{
    /*
        On peut demander au compilateur de s'arrêter juste après l'action
        du préprocesseur avec l'option -E :

            gcc -E preproc.c

        On retrouve alors le texte du programme source après
        modification par le préprocesseur.  La fin de cette sortie est
        la plus intéressante, puisqu'on y retrouve la version modifiée
        du main (celle qui sera effectivement compilée et exécutée
        lorsqu'on exécute gcc preproc.c -o preproc) :

            int main(void)
            {
                printf( "https://www.yo" "utu" "be.com/wat" "ch?v=v--IqqusnNQ\n" );

                return 0;
            }
       */
    oO TRIBUTE TO DAVID BOWIE Oo

    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)