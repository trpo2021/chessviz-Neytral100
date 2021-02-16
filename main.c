#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct piece board[8][8];
    board_init(&board[0][0]);
    // board_output(board);
    return 0;
}

void board_init(struct piece* board)
{
    for (int x = 0; x <= 7; x++) {
        (board + 1 * 8 + x)->color = BLACK;
        (board + 2 * 8 + x)->color = BLACK;
        (board + 6 * 8 + x)->color = WHITE;
        (board + 7 * 8 + x)->color = WHITE;
    }
    (board + 0 * 8 + 0)->shape = ROOK;
    (board + 0 * 8 + 7)->shape = ROOK;
    (board + 7 * 8 + 0)->shape = ROOK;
    (board + 7 * 8 + 7)->shape = ROOK;

    (board + 0 * 8 + 1)->shape = KNIGHT;
    (board + 0 * 8 + 6)->shape = KNIGHT;
    (board + 7 * 8 + 1)->shape = KNIGHT;
    (board + 7 * 8 + 6)->shape = KNIGHT;

    (board + 0 * 8 + 2)->shape = BISHOP;
    (board + 0 * 8 + 5)->shape = BISHOP;
    (board + 7 * 8 + 2)->shape = BISHOP;
    (board + 7 * 8 + 5)->shape = BISHOP;

    (board + 0 * 8 + 3)->shape = QUEEN;
    (board + 7 * 8 + 3)->shape = QUEEN;

    (board + 0 * 8 + 4)->shape = KING;
    (board + 7 * 8 + 4)->shape = KING;
}

/*
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
*/