CC=clang
CFLAGS=-g -Wall

OBJS=main.o 

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -rf *.o main
