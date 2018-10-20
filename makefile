all: sieve.o main.o
	gcc sieve.o main.o -lm

run:
	./a.out

clear:
	rm *.o

sieve.o: sieve.c sieve.h
	gcc -c -g sieve.c

main.o: main.c sieve.h
	gcc -c -g main.c
