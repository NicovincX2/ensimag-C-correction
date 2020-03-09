#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ETUS 7

/* Structure de données représentant un étudiant. */
struct etu {
    /* Nom de l'étudiant. */
    char *nom;
    /* Son score, sur 100. */
    float score;
};

/* Affiche le tableau d'étudiants passé en paramètre. */
static void afficher_etudiants(struct etu diants[NB_ETUS]) {
    for (size_t i = 0; i < NB_ETUS; i++) {
        printf("%s: %2.1f\n", diants[i].nom, diants[i].score);
    }
}

/*
    Le prototype de qsort est :
    void qsort(void *base, size_t nel, size_t width,
         int (*compar)(const void *, const void *));
    (cf man qsort)

    Le dernier paramètre est la fonction de comparaison
    qui sera utilisée pour trier le tableau d'adresse
    base.

    Le format du pointeur de fonction indique que le paramètre
    compar doit être une fonction qui retourne un int et qui
    prend deux variables de type const void * en paramètre.

    Ces variables contiendront les adresses des deux élements du
    tableau à comparer. Les fonctions compare_notes et compare_noms
    ci-dessous ont été définies pour être compatibles avec qsort.
    C'est pourquoi leur prototype correspond à celui imposé par le pointeur
    de fonction int (*compar)(const void *, const void *).
*/

static int compare_notes(const void *e1, const void *e2) {
    /* On récupère les adresses des deux étudiants à comparer. */
    struct etu *etu1 = (struct etu *)e1;
    struct etu *etu2 = (struct etu *)e2;

    /* Une fonction de comparaison doit renvoyer un entier strictement négatif
       si e1 < e2, nul si e1 == e2 et strictement positif si e1 > e2
       (voir man qsort encore une fois).
     */
    return etu1->score - etu2->score;
}

static int compare_noms(const void *e1, const void *e2) {
    struct etu *etu1 = (struct etu *)e1;
    struct etu *etu2 = (struct etu *)e2;

    /* Ici, on utilise directement strcmp pour comparer les deux chaines
       de caractères, qui renvoie exactement ce qu'on veut (bizarrement!)
     */
    return strcmp(etu1->nom, etu2->nom);
}

int main(void)
{
    struct etu diants[NB_ETUS] = {
        { "François", 44.1 },
        { "Jean-Frédéric", 1.5 },
        { "Alain", 28.6 },
        { "Bruno", 2.4},
        { "Nicolas", 20.7 },
        { "Nathalie", 2.6 },
        { "Jean-François", 0.3 }
    };

    /* TODO : On trie les étudiants en fonction de leurs notes en utilisant qsort() */
    qsort(diants, NB_ETUS, sizeof(struct etu), compare_notes);
    printf("Classés par notes croissantes :\n");
    afficher_etudiants(diants);

    /* TODO : On trie les étudiants par ordre alphabétique en utilisant qsort() */
    qsort(diants, NB_ETUS, sizeof(struct etu), compare_noms);
    printf("\nClassés par ordre alphabétique :\n");
    afficher_etudiants(diants);

    return EXIT_SUCCESS;
}
