#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
TARGETS=encoder
TARGETS += enonce-decoder

all: $(TARGETS)

enonce-decoder:
	$(MAKE) -C ./decodeur

.PHONY: clean
clean:
	rm -f *~ *.o $(TARGETS)
	$(MAKE) -C ./decodeur clean

```

#### Corrigé du fichier encoder.c

```c
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void verif_params(int argc, char **argv)
{
    if (argc != 4 || atoi(argv[3]) < 1 || atoi(argv[3]) > 25) {
        fprintf(stderr, "Usage: %s input.txt output.txt key\n", argv[0]);
        fprintf(stderr, "où:\n");
        fprintf(stderr, "\t- input.txt est le nom du fichier texte a coder ;\n");
        fprintf(stderr, "\t- output.txt est le nom du fichier dans lequel enregistrer le texte codé ;\n");
        fprintf(stderr, "\t- key est un entier compris entre 1 et 25.\n");
        exit(EXIT_FAILURE);
    }
}

static char coder_lettre(char c, uint8_t cle)
{
    /*
        islower est une fonction de ctype.h qui renvoie vrai si le
        caractère est alphabétique et minuscule.
    */
    char base = islower(c) ? 'a' : 'A';
    /*
        isalpha est une fonction de ctype.h qui renvoie vrai si le
        caractère est alphabétique.
    */
    if (isalpha(c)) {
        /*
            On fait un parcours circulaire sur l'intervalle a-z ou
            A-Z. cf man ascii.
        */
        c = (c - base + cle) % 26 + base;
    }
    /*
        #if 0 est une utilisation astucieuse du préprocesseur pour
       commenter du code.
    */
#if 0
    /* Solution alternative plus lisible mais moins performante. */
    if (isalpha(c)) {
        for (uint8_t i = 0; i < cle; i++) {
            switch(c) {
                /* Deux cas particuliers à traiter ici: le suivant de
                 * 'z' et celui de 'Z'. */
                case 'z':
                    c = 'a';
                    break;
                case 'Z':
                    c = 'A';
                    break;
                default:
                    c++;
            }
        }
    }
#endif
    /* Pour que le compilateur soit content. */
    return c;
}


int main(int argc, char **argv)
{
    verif_params(argc, argv);

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    uint8_t cle = atoi(argv[3]);

    /*
        Ecrire la clé en première position dans le fichier de
        sortie...
    */
    fputc(cle, output);

    /*
        ... puis le contenu du fichier à coder auquel on a appliqué la
        méthode d'encodage.
    */
    while (!feof(input)) {
        char c = fgetc(input);
        if (feof(input)) {
            /*
                Si le caractère qu'on vient de lire avec fgetc est
                le caractère spécial de fin de fichier (eof), on
                s'arrête.
            */
            break;
        }
        c = coder_lettre(c, cle);
        fputc(c, output);
    }

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)