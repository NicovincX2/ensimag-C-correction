#### Corrigé du fichier main.c

```c
#include <stdlib.h>

#include "mon_super_module.h"

/*
   == version complete, compilation separée + édition de liens

   Si on compile main.c seul, par exemple avec la commande:

   gcc -Wall -Wextra -std=c99 main.c

   on obtient une erreur de référence indéfinie vers la fonction
   mon_super_message_de_reussite(). Le code binaire de cette fonction se
   trouve dans mon_super_module.o, qu'on obtient par compilation du
   fichier source mon_super_module.c (notez bien l'option -c):

   gcc -Wall -Wextra -std=c99 -c mon_super_module.c

   On génère de la même façon main.o à partir de main.c:

   gcc -Wall -Wextra -std=c99 -c main.c

   Il ne reste plus qu'à lier les deux fichiers objets pour générer un
   exécutable:

   gcc -Wall -Wextra -std=c99 mon_super_module.o main.o -o maino


   == version plus simple

   Une autre solution (que vous avez peut-être trouvé) est simplement:

   gcc -Wall -Wextra -std=c99 mon_super_module.c main.c -o main

   Ca marche très bien, et c'est facile. Alors pourquoi s'embêter?
   En fait cette solution compile systématiquement TOUS les fichiers fournis.
   Avec cet exemple, aucun pb.
   Essayez maintenant avec le noyau Linux (écrit en C, oui oui): si vous
   modifiez un ";" vous devrez tout recompiler!
   La première solution, bien plus complète, est donc indispensable
   dès que vous ferez un projet un peu complexe que nos petits exercices.

   (Sur le fond, les notions de compilation séparée et d'édition de liens
   sont très importantes!
   Inconvénient: vous aurez moins de temps pour boire des kfés pendant la
   compilation de votre noyau...)

*/

int main(void)
{
    mon_super_message_de_reussite();
    return EXIT_SUCCESS;
}

```

#### Corrigé du fichier mon_super_module.c

```c
#include <stdio.h>

#include "mon_super_module.h"

void mon_super_message_de_reussite(void)
{
    printf("F*ck yeah!\n");
}

```

#### Corrigé du fichier mon_super_module.h

```c
#ifndef _MON_SUPER_MODULE_H_
#define _MON_SUPER_MODULE_H_

extern void mon_super_message_de_reussite(void);

#endif /* _MON_SUPER_MODULE_H_ */

```

[Retour au sommaire](?)