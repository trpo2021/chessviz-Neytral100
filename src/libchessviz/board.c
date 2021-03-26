#include <libchessviz/board.h>
#include <libchessviz/struct.h>
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
        (board + 0 * NUM_OF_ROWS + x)->piece->color = ColorWhite;
        (board + 1 * NUM_OF_ROWS + x)->piece->color = ColorWhite;
        (board + 6 * NUM_OF_ROWS + x)->piece->color = ColorBlack;
        (board + 7 * NUM_OF_ROWS + x)->piece->color = ColorBlack;
        (board + 1 * NUM_OF_ROWS + x)->piece->shape = ShapePawn;
        (board + 6 * NUM_OF_ROWS + x)->piece->shape = ShapePawn;
    }
    (board + 0 * NUM_OF_ROWS + 0)->piece->shape = ShapeRook;
    (board + 0 * NUM_OF_ROWS + 7)->piece->shape = ShapeRook;
    (board + 7 * NUM_OF_ROWS + 0)->piece->shape = ShapeRook;
    (board + 7 * NUM_OF_ROWS + 7)->piece->shape = ShapeRook;

    (board + 0 * NUM_OF_ROWS + 1)->piece->shape = ShapeKnight;
    (board + 0 * NUM_OF_ROWS + 6)->piece->shape = ShapeKnight;
    (board + 7 * NUM_OF_ROWS + 1)->piece->shape = ShapeKnight;
    (board + 7 * NUM_OF_ROWS + 6)->piece->shape = ShapeKnight;

    (board + 0 * NUM_OF_ROWS + 2)->piece->shape = ShapeBishop;
    (board + 0 * NUM_OF_ROWS + 5)->piece->shape = ShapeBishop;
    (board + 7 * NUM_OF_ROWS + 2)->piece->shape = ShapeBishop;
    (board + 7 * NUM_OF_ROWS + 5)->piece->shape = ShapeBishop;

    (board + 0 * NUM_OF_ROWS + 3)->piece->shape = ShapeQueen;
    (board + 7 * NUM_OF_ROWS + 3)->piece->shape = ShapeQueen;

    (board + 0 * NUM_OF_ROWS + 4)->piece->shape = ShapeKing;
    (board + 7 * NUM_OF_ROWS + 4)->piece->shape = ShapeKing;
}

void board_free(Cell* board)
{
    for (int i = 0; i < NUM_OF_CELLS_IN_BOARD; i++)
        free((board + i)->piece);
}