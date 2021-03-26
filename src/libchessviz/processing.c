#include <libchessviz/piece_check.h>
#include <libchessviz/processing.h>
#include <libchessviz/struct.h>
#include <stdio.h>
#include <stdlib.h>

void processing(Cell* board, struct Move* move, Color color)
{
    int check = 0;
    check = checking_for_errors(board, move, color);
    if (check == 0)
        action(board, move);
}

int checking_for_errors(Cell* board, struct Move* move, Color color)
{
    if (selecting(board, move)->piece->color != color) {
        printf("Error, the selected piece is a different color\n");
        return -1;
    }

    if (selecting(board, move)->piece->shape != move->shape) {
        printf("Error, the selected piece is a different shape\n");
        return -1;
    }
    if (move->shape == ShapePawn) {
        return pawn_check(move, color);
    }
    return 0;
}

Cell* selecting(Cell* board, struct Move* move)
{
    return (board + (move->start_y) * NUM_OF_ROWS + (move->start_x));
}

void action(Cell* board, struct Move* move)
{
    if (move->action_type == ActionTypeQuietMove) {
        Cell boofer;
        boofer = *(board + (move->end_y) * NUM_OF_ROWS + (move->end_x));
        *(board + (move->end_y) * NUM_OF_ROWS + (move->end_x))
                = *(board + (move->start_y) * NUM_OF_ROWS + (move->start_x));
        *(board + (move->start_y) * NUM_OF_ROWS + (move->start_x)) = boofer;
    }
    if (move->action_type == ActionTypeCapture) {
        *(board + (move->end_y) * NUM_OF_ROWS + (move->end_x))
                = *(board + (move->start_y) * NUM_OF_ROWS + (move->start_x));
        (board + (move->start_y) * NUM_OF_ROWS + (move->start_x))->piece = NULL;
    }
}