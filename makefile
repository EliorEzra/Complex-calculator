mycomp: mycomp.o switch.o complex.o
	gcc -g -ansi mycomp.o switch.o complex.o -o mycomp -lm

mycomp.o: mycomp.c complex.h
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o

switch.o: switch.c complex.o p.h 
	gcc -c -Wall -ansi -pedantic switch.c -o switch.o

complex.o: complex.c complex.h
	gcc -c -Wall -ansi -pedantic complex.c -o complex.o -lm
