#include <stdio.h>
#include <stdlib.h>

char* board_init();

int main()
{
    char* board;
    board = board_init();
    return 0;
}

char* board_init()
{
    char* board = calloc(64, sizeof(int));
    char i;

    for (i = 8; i <= 15; i++)
        *(board + i) = -1;

    for (i = 48; i <= 55; i++)
        *(board + i) = 1;

    *(board + 0) = -2;
    *(board + 1) = -3;
    *(board + 2) = -4;
    *(board + 3) = -5;
    *(board + 4) = -6;
    *(board + 5) = -4;
    *(board + 6) = -3;
    *(board + 7) = -2;
    *(board + 56) = 2;
    *(board + 57) = 3;
    *(board + 58) = 4;
    *(board + 59) = 5;
    *(board + 60) = 6;
    *(board + 61) = 4;
    *(board + 62) = 3;
    *(board + 63) = 2;

    return board;
}