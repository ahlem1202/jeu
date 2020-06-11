prog: main.o
	gcc main.c test.c -o prog -lSDL -lSDL_image
main.o: main.c
	gcc -c main.c
