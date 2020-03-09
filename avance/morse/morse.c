#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<stdbool.h> // bool
#include <ctype.h> // tolower
#include "morse.h"

#define NBCAR 37
#define NBMORSE 6

/* Constantes globales statiques */
static const char texte_ref[NBCAR] =
    {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
     's','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0',
     ' '};
static const char morse_ref[NBCAR][NBMORSE] =
    {{".-"},{"-..."},{"-.-."},{"-.."},{"."},{"..-."},{"--."},{"...."},{".."},
    {".---"},{"-.-"},{".-.."},{"--"},{"-."},{"---"},{".--."},{"--.-"},{".-."},
    {"..."},{"-"},{"..-"},{"...-"},{".--"},{"-..-"},{"-.--"},{"--.."},{".----"},
    {"..---"},{"...--"},{"....-"},{"....."},{"-...."},{"--..."},{"---.."},{"---."},
    {"-----"},{"//"}};


/* help : fonction affichant tout le tableau du code morse pouvant
   être codé ou décodé par ce programme */
void help()
{
    for (uint16_t i=0; i<NBCAR; i++) {
        printf(" %c :  %s\n",texte_ref[i],morse_ref[i]);
    }
}

/* affiche_texte : fonction affichant le texte correspondant au code
   morse passe en paramètre */
void affiche_texte(char *morse)
{
    uint16_t i;
    bool trouve;
    /* Utilisation de la fonction strtok permettant d'extraire des
       sous chaines */
    char temp_str[strlen(morse)+1];
    strcpy(temp_str, morse);
    char *mot;
    mot = strtok(temp_str, " ");
    while (mot != NULL) {
        trouve = false;
        for (i=0; i<NBCAR; i++) {
            if (strncmp(mot, morse_ref[i], NBMORSE) == 0) {
                printf("%c",texte_ref[i]);
                trouve = true;
                break;
            }
        }
        if (!trouve) {
            printf("\n\nCe code morse (%s) n'existe pas !\n\n", mot);
        }
        mot = strtok(NULL, " ");
    }
    printf("\n");
}

/* affiche_morse : fonction affichant le code Morse correspondant au
   texte passé en paramètre */
void affiche_morse(char *texte)
{
    for (uint16_t i=0; i<strlen(texte); i++) {
        for (uint16_t j=0; j<NBCAR; j++) {
            if (tolower(texte[i])==texte_ref[j]) {
                printf("%s ", morse_ref[j]);
            }
        }
    }
    printf("\n");
}
