all: sieve.o main.o
	gcc sieve.o main.o

run:
	./a.out

clear:
	rm *.o

primes.o: sieve.c sieve.h
	gcc -c -g -lm sieve.c

main.o: main.c sieve.h
	gcc -c -g main.c
