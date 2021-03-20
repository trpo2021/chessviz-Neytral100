//#include "../src/libchessviz/board.h"

#include <libchessviz/board.h>
#include <libchessviz/board_print.h>
#include <libchessviz/struct.h>
#include <stdio.h>
#include <stdlib.h>

void board_print(Cell* board);
char interpret(Cell* choosecell);
void board_init(Cell* board);

int main()
{
    Cell myboard[64];

    board_init(myboard);
    board_print(myboard);

    return 0;
}
