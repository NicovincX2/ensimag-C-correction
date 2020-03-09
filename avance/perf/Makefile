CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
# Cette ligne n'est utile que si votre programme
# utilise la lib maths (pour pow() par exemple).
LDFLAGS=-lm

all: perf

.PHONY: clean
clean:
	rm -f *~ *.o perf

.PHONY: progress

progress:
	@../../../.progress/update $(shell basename "$(shell pwd)")
