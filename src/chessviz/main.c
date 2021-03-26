#include <chessviz/move_read.h>
#include <libchessviz/board.h>
#include <libchessviz/board_print.h>
#include <libchessviz/processing.h>
#include <libchessviz/struct.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Move* moves;

    char name_of_input_file[18] = "notation.txt";

    moves = moves_read(name_of_input_file);

    struct Move* current_move = moves;

    Cell my_board[NUM_OF_CELLS_IN_BOARD];

    board_init(my_board);
    Color current_color = ColorWhite;
    while (current_move != NULL) {
        if (processing(my_board, current_move, current_color) != 0)
            return -1;
        board_print(my_board);
        current_move = current_move->next;
        if (current_color == ColorBlack)
            current_color = ColorWhite;
        else
            current_color = ColorBlack;
    }
    board_free(my_board);

    return 0;
}
