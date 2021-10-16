CC := gcc

CFLAGS := -Wall -DDEBUG

all: count

count:
	$(CC) -o count count.c -lm

clean:
	rm -f count
