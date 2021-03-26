#include <libchessviz/piece_check.h>
#include <libchessviz/struct.h>

int pawn_check(struct Move* move, Color color)
{
    int diff = 1;
    if (move->action_type == ActionTypeQuietMove) {
        if (color == ColorWhite) {
            diff = -1;
            if (move->start_y == YCoord2)
                diff *= 2;
            if ((int)(move->end_y - move->start_y) >= diff)
                return 0;

        } else {
            if (move->start_y == YCoord7)
                diff *= 2;
            if ((int)(move->end_y - move->start_y) <= diff)
                return 0;
        }
    }

    if (move->action_type == ActionTypeCapture) {
        if (((int)(move->end_x - move->start_x) == 1)
            || ((int)(move->end_x - move->start_x) == -1)) {
            if (color == ColorWhite)
                diff = -1;
            if ((int)(move->end_y - move->start_y) == diff)
                return 0;
        }
    }

    return -1;
}