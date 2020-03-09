CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
# Activer la ligne suivante pour tester la solution 2 avec fscanf
#CFLAGS+=-DSOL2

all: jedi

.PHONY: clean
clean:
	rm -f *~ *.o jedi

.PHONY: progress

progress:
	@../../../.progress/update $(shell basename "$(shell pwd)")
