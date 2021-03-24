#pragma once
#include <libchessviz/struct.h>

Shape check_for_shape(char current_char);
XCoord check_for_coord_x(char current_char);
YCoord check_for_coord_y(char current_char);
ActionType check_for_action(char current_char);
ResultMove check_for_result_move(char current_char);