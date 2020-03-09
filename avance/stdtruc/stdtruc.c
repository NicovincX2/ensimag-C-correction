#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define TAMPSIZE 100    // Taille maximale de la chaine tampon de
			// saisie sécurisée : 100 caractères
#define REFLUX false    // true si on veut rediriger les flux stdin,
			// stdout et stderr vers des fichiers, false
			// sinon
#undef REFLUX
#define REFLUX true     // true si on veut rediriger les flux stdin,
			// stdout et stderr vers des fichiers, false
			// sinon

int main(void)
{
    char nom[20];   // Variable de stockage du nom saisi
    uint16_t age;   // Variable de stockage de l'age saisi
    /* A compléter */
    char tampon[TAMPSIZE];

    if (REFLUX) {
	freopen("out.txt", "wt", stdout);
	freopen("in.txt", "rt", stdin);
	freopen("err.txt", "wt", stderr);
    }

    fputs("Bienvenue chez les flux\nSaississez des couples nom age (ex : doe 35)\nsur une même ligne en validant par un retour chariot\nTapez Q pour quitter le programme\n", stdout);

    while (fgets(tampon, TAMPSIZE, stdin) != NULL && tampon[0] != 'Q') {
	if (sscanf(tampon, "%s%hu", nom, &age) < 2) {
	    fprintf(stderr, "Erreur de saisie, nom et/ou age manquant dans la chaine : %s", tampon);
	    fputs("####\n", stdout);
	} else {
	    fprintf(stdout, "nom = %s - age = %hu ans\n", nom, age);
	    /* Equivalent à :
	    printf("nom = %s - age = %hu\n", nom, age);
	    */
	}
    }
    return EXIT_SUCCESS;
}
