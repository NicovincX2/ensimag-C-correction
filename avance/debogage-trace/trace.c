#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void affiche_et_libere_tab(uint8_t** tab, uint8_t taille, uint8_t offset){
    /* Affiche la ligne courante */
    uint8_t i;
    for(i = 0; i < taille; i++) {
	printf("%3u ", tab[taille - offset][i]);
    }
    printf("\n");
    /* libere la memoire associee a la ligne qui vient d'etre lue */
    free(tab[taille - offset]);
    /* Affiche le reste du tableau par recursion */
    /*       Ici on boucle sur le tableau avec la variable offset allant de
     * 'taille' a 0, soit (taille+1) iterations, ce qui provoque un depassement
     * de memoire. La trace de notre progamme montre bien les 11 appels a la
     * fonction affiche_et_libere_tab alors que notre tableau n'a que 10 lignes.
     * De plus on sait que l'erreur a lieu lors de l'appel avec le parametre
     * offset a la valeur 0. Il faut donc corriger le code en remplacant le test
     * ci dessous par ceci : if (offset>1)
     */
    if (offset > 0) {
	affiche_et_libere_tab(tab, taille, offset - 1);
    }
}

int main(void)
{
    /* Construit un simple tableau a deux dimmensions contenant les tables de
     * multiplications
     */
    uint8_t taille = 10;
    uint8_t **tab = malloc(taille * sizeof(uint8_t *));
    uint8_t i, j;
    for(i = 0; i < taille; i++) {
	tab[i] = malloc(taille * sizeof(uint8_t));
	for(j = 0; j < taille; j++) {
	    tab[i][j] = (i + 1) * (j + 1);
	}
    }
    /* On affiche notre tableau */
    affiche_et_libere_tab(tab, taille, taille);
    /* On libere le dernier pointeur */
    free(tab);

    return EXIT_SUCCESS;
}
