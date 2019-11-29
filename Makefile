all: decodage.o memoire.o registre.o main.o
	gcc -o main decodage.o memoire.o registre.o main.o

main.o: main.c
	gcc -g -c main.c -Wall -o main.o

decodage.o: decodage.c decodage.h
	gcc -g -c decodage.c -Wall -o decodage.o

memoire.o: memoire.c memoire.h
	gcc -g -c memoire.c -Wall -o memoire.o

registre.o: registre.c registre.h
	gcc -g -c registre.c -Wall -o registre.o

clean: 
	rm *.o