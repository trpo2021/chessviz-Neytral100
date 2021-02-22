#include "main.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Cell myboard[64];

    board_init(myboard);
    board_output(myboard);

    return 0;
}

void board_init(Cell* board)
{
    for (int i = 0; i < 64; i++) {
        (board + i)->piece = NULL;
    }
    for (int i = 0; i < 16; i++) {
        (board + i)->piece = malloc(sizeof(Piece));
    }
    for (int i = 48; i < 64; i++) {
        (board + i)->piece = malloc(sizeof(Piece));
    }
    for (int x = 0; x <= 7; x++) {
        (board + 0 * 8 + x)->piece->color = BLACK;
        (board + 1 * 8 + x)->piece->color = BLACK;
        (board + 6 * 8 + x)->piece->color = WHITE;
        (board + 7 * 8 + x)->piece->color = WHITE;
        (board + 1 * 8 + x)->piece->shape = PAWN;
        (board + 6 * 8 + x)->piece->shape = PAWN;
    }
    (board + 0 * 8 + 0)->piece->shape = ROOK;
    (board + 0 * 8 + 7)->piece->shape = ROOK;
    (board + 7 * 8 + 0)->piece->shape = ROOK;
    (board + 7 * 8 + 7)->piece->shape = ROOK;

    (board + 0 * 8 + 1)->piece->shape = KNIGHT;
    (board + 0 * 8 + 6)->piece->shape = KNIGHT;
    (board + 7 * 8 + 1)->piece->shape = KNIGHT;
    (board + 7 * 8 + 6)->piece->shape = KNIGHT;

    (board + 0 * 8 + 2)->piece->shape = BISHOP;
    (board + 0 * 8 + 5)->piece->shape = BISHOP;
    (board + 7 * 8 + 2)->piece->shape = BISHOP;
    (board + 7 * 8 + 5)->piece->shape = BISHOP;

    (board + 0 * 8 + 3)->piece->shape = QUEEN;
    (board + 7 * 8 + 3)->piece->shape = QUEEN;

    (board + 0 * 8 + 4)->piece->shape = KING;
    (board + 7 * 8 + 4)->piece->shape = KING;
}

char interpret(Cell* choosecell)
{
    char output_piece;
    if (choosecell->piece == NULL)
        output_piece = ' ';
    else {
        if (choosecell->piece->shape == ROOK)
            output_piece = 'r';
        else if (choosecell->piece->shape == KNIGHT)
            output_piece = 'n';
        else if (choosecell->piece->shape == BISHOP)
            output_piece = 'b';
        else if (choosecell->piece->shape == QUEEN)
            output_piece = 'q';
        else if (choosecell->piece->shape == KING)
            output_piece = 'k';
        else if (choosecell->piece->shape == PAWN)
            output_piece = 'p';
        if (choosecell->piece->color == BLACK)
            output_piece = toupper(output_piece);
    }
    return output_piece;
}

void board_output(Cell* board)
{
    FILE* pFileBoard = fopen("Сhessboard.txt", "w");
    if (pFileBoard == NULL) {
        printf("Error with open the file");
        return;
    }

    int numberofline = 8;
    for (int y = 0; y <= 7; y++) {
        fprintf(pFileBoard, "%d ", numberofline);
        numberofline--;
        for (int x = 0; x <= 7; x++)
            fprintf(pFileBoard, "%c ", interpret(board + y * 8 + x));
        fprintf(pFileBoard, "\n");
    }

    fprintf(pFileBoard, "  ");
    char c;
    for (c = 'a'; c <= 'h'; c++)
        fprintf(pFileBoard, "%c ", c);
    fprintf(pFileBoard, "\n");

    fclose(pFileBoard);
}