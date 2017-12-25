CC=clang
CFLAGS=-Wall -Wextra -pedantic
LDFLAGS=
SOURCES=eFib.c
STDFLAGS=-std=c11
OPTFLAGS=-O3
OBJECTS=$(SOURCES:.c=.o)
BINARY=evenFibonacci

all: $(BINARY) $(OBJECTS)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BINARY): $(OBJECTS)
	$(CC) $(STDFLAGS) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	
clean:
	rm $(PROGRAM) *.o

