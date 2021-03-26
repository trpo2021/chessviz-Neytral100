#include <libchessviz/processing.h>
#include <libchessviz/struct.h>
#include <stdio.h>

void processing(Cell* board, struct Move* move, Color color)
{
    int check = 0;
    check = checking_for_errors(board, move, color);
    if (check == 0)
        action(board, move);
}

int checking_for_errors(Cell* board, struct Move* move, Color color)
{
    // checking for color
    if (selecting(board, move)->piece->color != color) {
        printf("Error, the selected piece is a different color\n");
        return -1;
    }
    // checking for shape
    if (selecting(board, move)->piece->shape != move->shape) {
        printf("Error, the selected piece is a different shape\n");
        return -1;
    }
    if (selecting(board, move)->piece->color == ColorBlack) {
        int check_for_black_pawn_coord;
        check_for_black_pawn_coord = (move->start_y) - (move->end_y);
        if (check_for_black_pawn_coord != -1) {
            printf("Error, the selected Pawn can't walk this way\n");
            return -1;
        }
    }
    if (selecting(board, move)->piece->color == ColorWhite) {
        int check_for_white_pawn_coord;
        check_for_white_pawn_coord = (move->start_y) - (move->end_y);
        if (check_for_white_pawn_coord != 1) {
            printf("Error, the selected Pawn can't walk this way\n");
            return -1;
        }
    }

    /*
    if (((board + (current_Move->move->start_x) * NUM_OF_ROWS
          + (current_Move->move->start_y))
                 ->piece->color
         == ColorBlack)
        && (((current_Move->move->start_y) - (current_Move->move->end_y))
            == -1)) {
        printf("Error, the selected Pawn can't walk this way\n");
        return -1;
    }
    if (((board + (current_Move->move->start_x) * NUM_OF_ROWS
          + (current_Move->move->start_y))
                 ->piece->color
         == ColorWhite)
        && (((current_Move->move->start_y - current_Move->move->end_y) == 1))) {
        printf("Error, the selected Pawn can't walk this way\n");
        return -1;
    }
    */
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
}