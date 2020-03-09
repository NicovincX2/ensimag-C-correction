CC=gcc
# On rajoute aux options de compilation l'emplacement de SDL.h.
CFLAGS=-Wall -Wextra -g -std=c99 -I/usr/include/SDL
# On rajoute aux options de l'éditeur de liens les bibliothèques SDL et m.
LDFLAGS=-lSDL -lm

all: main

.PHONY: enonce
enonce:
	@echo "Commencez par compléter le Makefile de cet exercice."

# On indique au compilateur que l'exécutable est construit à partir des fichiers objet main.o ET dessin.o
main: main.o dessin.o

# et que si quelqu'un modifie dessin.h, il faut regénérer main.o et dessin.o
main.o: main.c dessin.h

dessin.o: dessin.c dessin.h

# et... c'est tout! Les règles implicites de make feront le reste!
# En pratique, on aurait pu écrire ça:

# main.o: main.c dessin.h
# 	$(CC) $(CFLAGS) -c $<

# dessin.o: dessin.c dessin.h
# 	$(CC) $(CFLAGS) -c $<

# main: main.o dessin.o
# 	$(CC) $^ -o $@ $(LDFLAGS)

# mais "make" fait ça tout seul!

.PHONY: clean
clean:
	rm -rf *.o *~ main

.PHONY: progress

progress:
	@../../../.progress/update $(shell basename "$(shell pwd)")
