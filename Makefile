all: decodage.o main.o
	gcc -o main decodage.o main.o

decodage.o: decodage.c decodage.h
	gcc -g -c decodage.c -Wall -o decodage.o

main.o: main.c
	gcc -g -c main.c -Wall -o main.o

clean: 
	rm *.o