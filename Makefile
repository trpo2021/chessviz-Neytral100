all: chess

chess: main.o
	gcc -o chess -Wall -Werror main.o