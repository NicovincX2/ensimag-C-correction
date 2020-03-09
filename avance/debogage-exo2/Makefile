# Compléter le Makefile effectuant les opérations suivantes :
# - Génération de l'exécutable : <nomexecutable>
# - <nomexecutable> : avec options de compilation standards et mode débogage pour utilisation de ddd/gdb et valgrind
# - Génération du fichier préprocesseur: <nomexecutable>_preprocesseur.txt
# - Règle clean : supprimer les fichiers .o ainsi que l'exécutable et le fichier préprocesseur générés 
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
LDFLAGS=
# Option -E pour géréner le fichier de sortie préprocesseur
PREFLAGS=-E
EXEC=debogage-exo2

all: $(EXEC) $(EXEC)_preprocesseur.txt

# Générer le fichier de sortie préprocesseur : <nomexecutable>_preprocesseur.txt
$(EXEC)_preprocesseur.txt: $(EXEC).c
	$(CC) -o $@ $^ $(CFLAGS) $(PREFLAGS) $(LDFLAGS)

$(EXEC): $(EXEC).c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f *~ *.o $(EXEC) $(EXEC)_preprocesseur.txt
# END CU

.PHONY: progress

progress:
	@../../../.progress/update $(shell basename "$(shell pwd)")
