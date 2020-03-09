#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "salarie.h"


struct salarie {
    /* Le prénom, sous forme d'un tableau de 16 caractères. */
    char prenom[16];

    /* Le nom, sous forme d'un tableau de 32 caractères. */
    char nom[32];

    /*
        Il est à noter qu'on aurait pu définir les champs nom et prenom
        comme suit :
        char *prenom;
        char *nom;

        Dans ce cas, la structure salarie ne contient plus les 16 caractères
        du prenom et les 32 caractères du nom directement, mais deux pointeurs :
        un vers la chaine de caractères contenant le prenom, l'autre vers celle
        contenant le prénom.

        Du coup, en terme d'organisation en mémoire, les deux solutions ne sont pas
        équivalentes, et seule celle donnée dans ce corrigé est compatible avec la
        fonction afficher_salarie() donnée dans le fichier bigbuck.c.
     */
    uint8_t age;
    uint8_t anciennete;
    uint32_t salaire;
};

/* Alloue et retourne un struct salarie. */
struct salarie *allouer_salarie(void) {
    /*
        Avec notre implémentation, sizeof(struct salarie) =
            16 * sizeof(char)
            + 32 * sizeof(char)
            + sizeof(uint8_t)
            + sizeof(uint8_t)
            + sizeof(uint32_t)
            = 54

        Pourtant, si vous executez :
        printf("%d\n", sizeof(struct salarie));

        56 s'affiche! (et non 54)

        Il existe en pratique un "trou" de 2 octets entre le champ ancienneté
        et le champ salaire, parce qu'un mot de 4 octets ne peut être stocké
        qu'à une adresse multiple de 4.

        De la même manière, si on avait voulu stocker une variable de type
        uint64_t (8 octets), elle aurait été stockée en mémoire à une adresse
        multiple de 8.

        C'est ce qu'on appelle les contraintes d'alignement.
    */
    return malloc(sizeof(struct salarie));
}

/*
    Initialise le salarié passé en paramètre.
    Le salarié s a déjà été alloué avant l'appel
    à init_salarie().
*/
void init_salarie(struct salarie *s,
                  const char *prenom,
                  const char *nom,
                  uint8_t age,
                  uint8_t anciennete,
                  uint32_t salaire) {
    s->age = age;
    s->anciennete = anciennete;
    s->salaire = salaire;
    /*
        Pas d'allocation nécessaire pour s->prenom et s->nom, puisque la place
        qu'elles occupent a été réservée par allouer_salarie().
    */
    strncpy(s->prenom, prenom, 16);
    strncpy(s->nom, nom, 32);
}

/* Effectue l'allocation ET l'initialisation du salarie passé en paramètre. */
void creer_salarie(struct salarie **s,
                   const char *prenom,
                   const char *nom,
                   uint8_t age,
                   uint8_t anciennete,
                   uint32_t salaire) {
    /*
        Cette fonction va modifier le paramètre de type struct salarie *,
        puisqu'elle va changer sa valeur pour qu'elle représente l'adresse
        d'un struct salarie fraichement alloué.

        Comme on souhaite modifier ce paramètre, on passe son adresse à la fonction,
        et on se retrouve donc à travailler sur un struct salarie ** (l'adresse
        d'un struct salarie *).
    */
    *s = allouer_salarie();
    init_salarie(*s, prenom, nom, age, anciennete, salaire);
}

/*
    Libère la mémoire associée au salarié passé en paramètre.
    En sortie, s doit valoir NULL.
*/
void plan_social(struct salarie **s) {
    /*
        Même remarque qu'au dessus : on va modifier le paramètre s ici,
        qui est de type struct salarie *. On passe donc son adresse et on se
        retrouve avec un struct salarie **.
    */
    free(*s);
    *s = NULL;
}

