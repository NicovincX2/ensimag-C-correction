#include <stdio.h>

const int TRUE = 1;
const int FALSE = 0;

int function_returning_false()
{
	return FALSE;
}

int main()
{
	/*
		function_returning_false() est un appel à la fonction
		function_returning_false Mais function_returning_false
		est l'adresse de la fonction
		function_returning_false. On l'appelle aussi pointeur
		de fonction.  function_returning_false renvoit donc un
		nombre différent de 0 et le test if... est toujours
		vrai
	*/
	if (function_returning_false) {
		printf("function returned true\n");
	}
}

/* MARKDOWN */

# Correction debogage-exo6

### Résumé : le nom d’une fonction est en fait l’adresse de cette fonction

## Compilation
RAS, aucun message

## Valgrind
RAS, pas d'erreur

## gdb/ddd

    gcc -o debogage-exo6 debogage-exo6.c -std=c99 -Wall -Wextra –g
    ddd ./debogage-exo6

On trace pas à pas pour comprendre ce qu’il se passe.
On place deux break (cf. copie d’écran ci-dessous) :

* un break au niveau du `if`
* un break dans la fonction `function_returning_false`

![](solution-ddd1.png)

On lance le programme (commande `run`).
On essaie d’utiliser la commande `stepi` pour rentrer pas à pas dans la fonction `function_returning_false`, mais cela ne fonctionne pas.
En utilisant la commande `step`, on s’aperçoit que le test `if` est vrai et qu’on rentre dans les instructions du `if` (cf. screenshot ci-dessous).

![](solution-ddd2.png)

On vérifie finalement l’expression contenue dans le `if`. On s’aperçoit que ce n’est pas la valeur 0 qui est affichée mais une valeur `0x4004b0` (cf. copie d’écran ci-dessous). Cette valeur est en fait l’adresse de la fonction `function_returning_false`, on l’appelle aussi pointeur de la fonction.

![](solution-ddd3.png)

## Conclusion

Rappel : `if` évalue l’expression qui suit. Si l’expression est différente de 0, le test est vrai, sinon il est faux.

En résumé :

* `function_returning_false()` : retourne le résultat de la fonction retourné par l’instruction `return` ;
* `function_returning_false` : contient l’adresse (pointeur) de la fonction.

Une adresse d’une fonction valide est toujours différente de 0.
Donc le test `if (function_returning_false)` est toujours vrai.

