# Compléter le Makefile effectuant les opérations suivantes :
# - Génération de l'exécutable : <nomexecutable>
# - <nomexecutable> : avec options de compilation standards et mode débogage pour utilisation de ddd/gdb et valgrind
# - Règle clean : supprimer les fichiers .o et l'exécutable généré
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
LDFLAGS=
EXEC=debogage-exo7

all: $(EXEC)

$(EXEC): $(EXEC).c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f *~ *.o $(EXEC)

.PHONY: pouetpouet
pouetpouet:
	echo "Ce Makefile ne fait rien, c'est à vous de le compléter!"

.PHONY: progress

progress:
	@../../../.progress/update $(shell basename "$(shell pwd)")
