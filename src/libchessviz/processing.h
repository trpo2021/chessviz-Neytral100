#pragma once
#include <libchessviz/struct.h>

void processing(Cell*, struct Move*, Color);
int checking_for_errors(Cell*, struct Move*, Color);
void action(Cell*, struct Move*);
Cell* selecting(Cell*, struct Move*);