CC=clang
CFLAGS=-g -Wall -Wextra -pedantic
LDFLAGS=-lm
SOURCES=multiples.c
STDFLAGS=-std=c11
OPTFLAGS=-O0
OBJECTS=$(SOURCES:.c=.o)
BINARY=sumMultiplesOf3And5

all: $(BINARY) $(OBJECTS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BINARY): $(OBJECTS)
	$(CC) $(STDFLAGS) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	
clean:
	rm $(PROGRAM) *.o

