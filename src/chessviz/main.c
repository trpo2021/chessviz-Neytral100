#include <libchessviz/board.h>
#include <libchessviz/board_print.h>
#include <libchessviz/struct.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Cell my_board[NUM_OF_CELLS_IN_BOARD];

    board_init(my_board);
    board_print(my_board);
    board_free(my_board);

    return 0;
}
