#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: errno

.PHONY: clean

clean:
	rm -f *~ *.o errno

```

#### Corrigé du fichier errno.c

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/* Ouvre le fichier filename avec le mode d'accès mode. Retourne le FILE *
 * correspondant. */
static FILE *ouvrir_fichier(const char *filename, const char *mode) {
     FILE *fichier = fopen(filename, mode);
     /*
       Cf man fopen:

       RETURN VALUE
       Upon successful completion fopen(), fdopen() and freopen() return a FILE
       pointer. Otherwise, NULL is returned and errno is set to indicate the
       error.
     */
     if (fichier == NULL) {
          /* Erreur! On affiche un message explicite correspondant à la valeur
           * de errno à l'aide de perror(). */
          perror("[ouvrir_fichier] fopen");
          /* On arrête le programme, parce que l'utilisation de la variable
           * fichier par le reste du programme provoquerait une erreur à coup
           * sûr. */
          exit(EXIT_FAILURE);
     }
     return fichier;
}

/* Ferme le fichier passé en paramètre. */
static void fermer_fichier(FILE *fichier) {
     int ret = fclose(fichier);
     if (ret != 0) {
          perror("[fermer_fichier] fclose");
          exit(EXIT_FAILURE);
     }
}

/* Fonction appelée quand la liste des arguments passés en ligne de commande
 * n'est pas correcte. */
static void usage(const char *progname) {
     /* On commence par râler... */
     fprintf(stderr, "Usage: %s n\n", progname);
     fprintf(stderr, "\toù n l'entier 1 ou 2.\n");
     /* ... puis on s'en va en claquant la porte. (la fonction exit(code) permet
      * de quitter le programme avec le code de retour passé en paramètre.)*/
     exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
     /* argv est un tableau de chaines de caractères, de taille argc, dont
      * chaque élément est un mot de la ligne de commande. Ainsi, argv[0]
      * représente le nom du programme, argv[1] le premier argument. */
     if (argc != 2) {
          /* On doit obligatoirement saisir un numéro de scénario sur la ligne
           * de commande. */
          usage(argv[0]);
     }

     /* On convertit l'argument en ligne de commande, qui est une chaine de
      * caractères en C, en entier. */
     uint8_t id = atoi(argv[1]);

     /* On aurait pu faire un switch() ici. */
     if (id == 1) {
          /* Premier scénario. */
          FILE *lecture_seule = ouvrir_fichier("lecture-seule.txt", "w");
          fermer_fichier(lecture_seule);
     } else if (id == 2) {
          /* Deuxième scénario. */
          FILE *inexistant = ouvrir_fichier("t-es-pas-la-mais-t-es-ou.txt", "r");
          fermer_fichier(inexistant);
     } else {
          /* Le numéro de scénario n'est pas bon, on râle. */
          usage(argv[0]);
     }

     return EXIT_SUCCESS;
}

```

[Retour au sommaire](?)