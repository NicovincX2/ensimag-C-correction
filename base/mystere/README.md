#### Corrigé du fichier Makefile

```make
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

all: mystere

.PHONY: clean
clean:
	rm -f *~ *.o mystere

```

#### Corrigé du fichier mystere.c

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
int64_t f(int64_t n){int64_t x,y;if(n < 2){return n;}x=f(n-1);y=f(n-2);return x+y;}int main(void){int64_t z=42+1;printf("%ld\n",f(z));return 0;}

/*
    Un petit coup de "indent -linux mystere.c" dans un terminal, et hop!

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
int64_t f(int64_t n)
{
	int64_t x, y;
	if (n < 2) {
		return n;
	}
	x = f(n - 1);
	y = f(n - 2);
	return x + y;
}

int main(void)
{
	int64_t z = 42 + 1;
	printf("%ld\n", f(z));
	return 0;
}

    C'est à peine plus lisible, pas vrai?
*/


```

[Retour au sommaire](?)