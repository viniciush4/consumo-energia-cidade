all: compila clean executa

compila: tad.o main.o
	gcc -o main tad.o main.o
tad.o: tad.c
	gcc -c tad.c
main.o: main.c tad.h
	gcc -c main.c	
clean:
	rm -rf *.o
executa:
	./main
