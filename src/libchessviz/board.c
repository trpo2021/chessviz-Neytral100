#include <libchessviz/board.h>
#include <stdlib.h>

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