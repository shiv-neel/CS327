all: sandpile.o sandpile clean

sandpile: sandpile.o
	gcc sandpile.o -o sandpile

sandpile.o: sandpile.c
	gcc -c sandpile.c

clean:
	rm -f *.o *~