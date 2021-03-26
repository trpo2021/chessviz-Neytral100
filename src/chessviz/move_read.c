#include <chessviz/checks.h>
#include <chessviz/move_read.h>
#include <ctype.h>
#include <libchessviz/struct.h>
#include <stdio.h>
#include <stdlib.h>

struct Move* moves_read(char* name_of_input_file)
{
    FILE* p_file_moves;

    struct Move* empty_move;
    empty_move = malloc(sizeof(struct Move));

    struct Move* current_move = empty_move;

    if ((p_file_moves = fopen(name_of_input_file, "r")) == NULL) {
        printf("The chess notations file could not be found\n");
        // return NULL;
    }
    while (!feof(p_file_moves)) {
        char notation[15];
        fscanf(p_file_moves, "%s", notation);

        if (!(isdigit(notation[0]))) {
            struct Move* new_move;
            new_move = malloc(sizeof(struct Move));
            new_move->next = NULL;
            read_current_move(new_move, notation);
            current_move->next = new_move;
            current_move = new_move;
        }
    }

    struct Move* move;
    move = empty_move->next;
    free(empty_move);

    return move;
}

void read_current_move(Move* move, char* notation)
{
    int num_of_char = 0;
    move->shape = check_for_shape(*(notation + num_of_char));
    if (move->shape != ShapePawn)
        num_of_char++;
    move->start_x = check_for_coord_x(*(notation + num_of_char));
    num_of_char++;
    move->start_y = check_for_coord_y(*(notation + num_of_char));
    num_of_char++;
    move->action_type = check_for_action(*(notation + num_of_char));
    num_of_char++;
    move->end_x = check_for_coord_x(*(notation + num_of_char));
    num_of_char++;
    move->end_y = check_for_coord_y(*(notation + num_of_char));
    num_of_char++;
    move->result_move = check_for_result_move(*(notation + num_of_char));
}