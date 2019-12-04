# Makefile generated automatically by makeMake, version 1.0, on Thu Apr 12 08:38:06 EDT 2018

# Variables used by makefile

CC=gcc
CFLAGS=-Wall -g -std=c11
EXE=main
OBJECTS= StringList.o

# Recipes for targets

StringList.o: StringList.c StringList.h
	$(CC) $(CFLAGS) -c StringList.c

main: $(OBJECTS)
	$(CC) -o $(EXE) $(OBJECTS) $(EXE).c

# PHONY targets

.PHONY: clean
clean:
	rm -rf *~ $(OBJECTS) $(EXE) vgcore.*

# End of makefile
