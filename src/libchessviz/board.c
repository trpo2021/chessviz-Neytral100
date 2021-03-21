#include <libchessviz/board.h>
#include <stdlib.h>

void board_init(Cell* board)
{
    for (int i = 0; i < NUM_OF_CELLS_IN_BOARD; i++) {
        (board + i)->piece = NULL;
    }
    for (int i = 0; i < NUM_OF_ROWS * 2; i++) {
        (board + i)->piece = malloc(sizeof(Piece));
    }
    for (int i = NUM_OF_ROWS * 6; i < NUM_OF_CELLS_IN_BOARD; i++) {
        (board + i)->piece = malloc(sizeof(Piece));
    }
    for (int x = 0; x < NUM_OF_ROWS; x++) {
        (board + 0 * NUM_OF_ROWS + x)->piece->color = BLACK;
        (board + 1 * NUM_OF_ROWS + x)->piece->color = BLACK;
        (board + 6 * NUM_OF_ROWS + x)->piece->color = WHITE;
        (board + 7 * NUM_OF_ROWS + x)->piece->color = WHITE;
        (board + 1 * NUM_OF_ROWS + x)->piece->shape = PAWN;
        (board + 6 * NUM_OF_ROWS + x)->piece->shape = PAWN;
    }
    (board + 0 * NUM_OF_ROWS + 0)->piece->shape = ROOK;
    (board + 0 * NUM_OF_ROWS + 7)->piece->shape = ROOK;
    (board + 7 * NUM_OF_ROWS + 0)->piece->shape = ROOK;
    (board + 7 * NUM_OF_ROWS + 7)->piece->shape = ROOK;

    (board + 0 * NUM_OF_ROWS + 1)->piece->shape = KNIGHT;
    (board + 0 * NUM_OF_ROWS + 6)->piece->shape = KNIGHT;
    (board + 7 * NUM_OF_ROWS + 1)->piece->shape = KNIGHT;
    (board + 7 * NUM_OF_ROWS + 6)->piece->shape = KNIGHT;

    (board + 0 * NUM_OF_ROWS + 2)->piece->shape = BISHOP;
    (board + 0 * NUM_OF_ROWS + 5)->piece->shape = BISHOP;
    (board + 7 * NUM_OF_ROWS + 2)->piece->shape = BISHOP;
    (board + 7 * NUM_OF_ROWS + 5)->piece->shape = BISHOP;

    (board + 0 * NUM_OF_ROWS + 3)->piece->shape = QUEEN;
    (board + 7 * NUM_OF_ROWS + 3)->piece->shape = QUEEN;

    (board + 0 * NUM_OF_ROWS + 4)->piece->shape = KING;
    (board + 7 * NUM_OF_ROWS + 4)->piece->shape = KING;
}