CC=clang
CFLAGS=-g -Wall -Wextra -pedantic
LDFLAGS=-lm
SOURCES=b_tree.c
STDFLAGS=-std=c23
OPTFLAGS=-O0
OBJECTS=$(SOURCES:.c=.o)
BINARY=b_tree

all: $(BINARY) $(OBJECTS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BINARY): $(OBJECTS)
	$(CC) $(STDFLAGS) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	
clean:
	rm $(BINARY) *.o

