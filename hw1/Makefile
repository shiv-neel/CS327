all: terrain.o terrain clean

terrain: terrain.o
	gcc terrain.o -o terrain

terrain.o: terrain.c
	gcc -c terrain.c

clean:
	rm -f *.o terrain