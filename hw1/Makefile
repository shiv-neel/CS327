all: terrain terrain.o map.o main.o clean

terrain: terrain.o main.o map.o
	gcc terrain.o main.o map.o -o main

terrain.o: terrain.c terrain.h
	gcc -c terrain.c

map.o: map.c terrain.h map.h
	gcc -c map.c

main.o: main.c terrain.h
	gcc -c main.c

clean:
	rm -f *.o ~*