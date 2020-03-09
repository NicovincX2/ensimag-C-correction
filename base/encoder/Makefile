CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g
TARGETS=encoder
TARGETS += enonce-decoder

all: $(TARGETS)

enonce-decoder:
	$(MAKE) -C ./decodeur

.PHONY: clean
clean:
	rm -f *~ *.o $(TARGETS)
	$(MAKE) -C ./decodeur clean

.PHONY: progress

progress:
	@../../../.progress/update $(shell basename "$(shell pwd)")
