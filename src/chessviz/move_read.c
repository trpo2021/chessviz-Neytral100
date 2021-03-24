#include <chessviz/checks.h>
#include <chessviz/move_read.h>
#include <ctype.h>
#include <libchessviz/struct.h>
#include <stdio.h>
#include <stdlib.h>

struct List* moves_read(char* name_of_input_file)
{
    FILE* p_file_moves;
    struct List* list_of_moves;
    Move* pointer_on_move;
    pointer_on_move = malloc(sizeof(Move));
    list_of_moves = malloc(sizeof(List));
    list_of_moves->move = pointer_on_move;
    list_of_moves->next = NULL;
    struct List* current_on_list = list_of_moves;

    if ((p_file_moves = fopen(name_of_input_file, "r")) == NULL) {
        printf("The chess notations file could not be found\n");
        // return NULL;
    }
    while (!feof(p_file_moves)) {
        char current_move[15];
        fscanf(p_file_moves, "%s", current_move);

        if (isdigit(current_move[0])) {
        } else {
            Move* pointer_on_move = malloc(sizeof(Move));
            current_on_list->move = pointer_on_move;
            read_current_move(current_on_list->move, current_move);
            struct List* pointer_on_list;
            pointer_on_list = malloc(sizeof(List));
            current_on_list->next = pointer_on_list;
            current_on_list = current_on_list->next;
            current_on_list->next = NULL;
        }
    }
    return list_of_moves;
}

void read_current_move(Move* move, char* current_move)
{
    int num_of_char = 0;
    move->shape = check_for_shape(*(current_move + num_of_char));
    if (move->shape != ShapePawn)
        num_of_char++;
    move->start_x = check_for_coord_x(*(current_move + num_of_char));
    num_of_char++;
    move->start_y = check_for_coord_y(*(current_move + num_of_char));
    num_of_char++;
    move->action_type = check_for_action(*(current_move + num_of_char));
    num_of_char++;
    move->end_x = check_for_coord_x(*(current_move + num_of_char));
    num_of_char++;
    move->end_y = check_for_coord_y(*(current_move + num_of_char));
    num_of_char++;
    move->result_move = check_for_result_move(*(current_move + num_of_char));
}