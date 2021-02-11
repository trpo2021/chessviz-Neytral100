#include <stdio.h>
#include <stdlib.h>

char* board_init();
void board_output(char*);

int main()
{
    char* board;
    board = board_init();
    board_output(board);
    return 0;
}

char* board_init()
{
    char* board = calloc(64, sizeof(char));
    char i;

    for (i = 8; i <= 15; i++)
        *(board + i) = 'P';

    for (i = 48; i <= 55; i++)
        *(board + i) = 'p';

    *(board + 0) = 'R';
    *(board + 1) = 'N';
    *(board + 2) = 'B';
    *(board + 3) = 'Q';
    *(board + 4) = 'K';
    *(board + 5) = 'B';
    *(board + 6) = 'N';
    *(board + 7) = 'R';
    *(board + 56) = 'r';
    *(board + 57) = 'n';
    *(board + 58) = 'b';
    *(board + 59) = 'q';
    *(board + 60) = 'k';
    *(board + 61) = 'b';
    *(board + 62) = 'n';
    *(board + 63) = 'r';

    for (i = 16; i < 48; i++){
        *(board + i) = ' ';
    }

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
        fprintf(pFileBoard, "%c ", *(board + i - 1));
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