prog: main.o
	gcc main.c clavier.c -o prog -lSDL -lSDL_image
main.o: main.c
	gcc -c main.c

