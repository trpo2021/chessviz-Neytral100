#include <libchessviz/piece_check.h>
#include <libchessviz/struct.h>
#include <stdio.h>

int pawn_check(struct Move* move, Color color)
{
    int diff = 1;
    if (move->action_type == ActionTypeQuietMove) {
        if (move->start_x == move->end_x) {
            if (color == ColorBlack) {
                diff = -1;
                if (move->start_y == YCoord2)
                    diff *= 2;
                if ((int)(move->end_y - move->start_y) <= diff)
                    return 0;
            } else {
                if (move->start_y == YCoord7)
                    diff *= 2;
                if ((int)(move->end_y - move->start_y) >= diff)
                    return 0;
            }
        } else {
            printf("Error, a pawn can't move like this\n");
            return -1;
        }
    }

    if (move->action_type == ActionTypeCapture) {
        if (((int)(move->end_x - move->start_x) == 1)
            || ((int)(move->end_x - move->start_x) == -1)) {
            if (color == ColorBlack)
                diff = -1;
            if ((int)(move->end_y - move->start_y) == diff)
                return 0;
        } else {
            printf("Error, a pawn can't capture like this\n");
            return -1;
        }
    }

    return -1;
}