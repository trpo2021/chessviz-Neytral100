#include <stdio.h>
#include <stdlib.h>

char* board_init();
void board_output(char*);
char interpret(char*);

int main()
{
    char* board;
    board = board_init();
    board_output(board);
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

void board_output(char* board)
{
    FILE* pFileBoard = fopen("Сhessboard.txt", "w");
    if (pFileBoard == NULL) {
        printf("Error with open the file");
        return;
    }
    int i;
    int j = 8;
    for (i = 1; i <= 64; i++) {
        fprintf(pFileBoard, "%c ", interpret(board + i - 1));
        if ((i % 8) == 0) {
            fprintf(pFileBoard, "%d ", j);
            j--;
        }
        if ((i % 8) == 0)
            fprintf(pFileBoard, "\n");
    }
    char c;
    for (c = 'a'; c <= 'h'; c++)
        fprintf(pFileBoard, "%c ", c);
    fprintf(pFileBoard, "\n");

    fclose(pFileBoard);
}

char interpret(char* figure_number)
{
    switch (*figure_number) {
    case 1:
        return 'p';
        break;
    case 2:
        return 'r';
        break;
    case 3:
        return 'n';
        break;
    case 4:
        return 'b';
        break;
    case 5:
        return 'q';
        break;
    case 6:
        return 'k';
        break;
    case -1:
        return 'P';
        break;
    case -2:
        return 'R';
        break;
    case -3:
        return 'N';
        break;
    case -4:
        return 'B';
        break;
    case -5:
        return 'Q';
        break;
    case -6:
        return 'K';
        break;
    case 0:
        return ' ';
        break;
    }
    return '\0';
}