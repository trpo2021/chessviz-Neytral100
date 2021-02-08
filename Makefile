all: chess

chess: main.o
	gcc -o chess -Wall -Werror main.o

main.o: main.c
	gcc -c main.c -o main.o