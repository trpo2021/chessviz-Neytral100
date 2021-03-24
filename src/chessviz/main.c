#include <chessviz/move_read.h>
#include <libchessviz/board.h>
#include <libchessviz/board_print.h>
#include <libchessviz/struct.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct List* list_of_moves;
    struct List* current_list;

    char name_of_input_file[18] = "notation.txt";

    list_of_moves = moves_read(name_of_input_file);
    current_list = list_of_moves;

    while (current_list->next != NULL) {
        /*
        printf("%d ", current_list->move->shape);
        printf("%d ", current_list->move->start_x);
        printf("%d ", current_list->move->start_y);
        printf("%d ", current_list->move->end_x);
        printf("%d ", current_list->move->end_y);
        printf("%d ", current_list->move->action_type);
        printf("%d\n", current_list->move->result_move);
        */
        current_list = current_list->next;
    }

    Cell my_board[NUM_OF_CELLS_IN_BOARD];

    board_init(my_board);
    moves_read(name_of_input_file);
    board_print(my_board);
    board_free(my_board);

    return 0;
}
