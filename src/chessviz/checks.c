#include <ctype.h>
#include <libchessviz/struct.h>
#include <stdio.h>

Shape check_for_shape(char current_char)
{
    Shape shape_result;
    if (islower(current_char) != 0)
        shape_result = ShapePawn;
    else {
        switch (current_char) {
        case 'K':
            shape_result = ShapeKing;
            break;
        case 'Q':
            shape_result = ShapeQueen;
            break;
        case 'R':
            shape_result = ShapeRook;
            break;
        case 'B':
            shape_result = ShapeBishop;
            break;
        case 'N':
            shape_result = ShapeKnight;
            break;
        default:
            printf("Error reading from file: ");
            printf("Incorrect shape");
        }
    }
    return shape_result;
}

XCoord check_for_coord_x(char current_char)
{
    XCoord x_coord_result;
    switch (current_char) {
    case 'a':
        x_coord_result = XCoordA;
        break;
    case 'b':
        x_coord_result = XCoordB;
        break;
    case 'c':
        x_coord_result = XCoordC;
        break;
    case 'd':
        x_coord_result = XCoordD;
        break;
    case 'e':
        x_coord_result = XCoordE;
        break;
    case 'f':
        x_coord_result = XCoordF;
        break;
    case 'g':
        x_coord_result = XCoordG;
        break;
    case 'h':
        x_coord_result = XCoordH;
        break;
    default:
        printf("Error reading from file: ");
        printf("Incorrect coordinate x\n");
    }
    return x_coord_result;
}

YCoord check_for_coord_y(char current_char)
{
    YCoord y_coord_result;
    switch (current_char) {
    case '1':
        y_coord_result = YCoord1;
        break;
    case '2':
        y_coord_result = YCoord2;
        break;
    case '3':
        y_coord_result = YCoord3;
        break;
    case '4':
        y_coord_result = YCoord4;
        break;
    case '5':
        y_coord_result = YCoord5;
        break;
    case '6':
        y_coord_result = YCoord6;
        break;
    case '7':
        y_coord_result = YCoord7;
        break;
    case '8':
        y_coord_result = YCoord8;
        break;
    default:
        printf("Error reading from file: ");
        printf("Incorrect coordinate y\n");
    }
    return y_coord_result;
}

ActionType check_for_action(char current_char)
{
    ActionType action_type_result;
    switch (current_char) {
    case '-':
        action_type_result = ActionTypeQuietMove;
        break;
    case 'x':
        action_type_result = ActionTypeCapture;
        break;
    default:
        printf("Error reading from file: ");
        printf("Incorrect action\n");
    }
    return action_type_result;
}

ResultMove check_for_result_move(char current_char)
{
    ResultMove result_move_result;
    switch (current_char) {
    case '+':
        result_move_result = ResultMoveCheck;
        break;
    case '#':
        result_move_result = ResultMoveMate;
        break;
    case '\0':
        result_move_result = ResultMoveNoResult;
        break;
    default:
        printf("Error reading from file: ");
        printf("Incorrect result move\n");
    }
    return result_move_result;
}