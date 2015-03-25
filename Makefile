clean:
	# clean

build: clean
	gcc -ansi -o main.out main.c mergesort.c -Wall
