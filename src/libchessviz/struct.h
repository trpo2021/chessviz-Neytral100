#pragma once

typedef enum {
    ShapeKing,
    ShapeQueen,
    ShapeBishop,
    ShapeKnight,
    ShapeRook,
    ShapePawn,
} Shape;

typedef enum { ColorWhite, ColorBlack } Color;

typedef enum {
    XCoordA = 0,
    XCoordB = 1,
    XCoordC = 2,
    XCoordD = 3,
    XCoordE = 4,
    XCoordF = 5,
    XCoordG = 6,
    XCoordH = 7,
} XCoord;

typedef enum {
    YCoord1 = 7,
    YCoord2 = 6,
    YCoord3 = 5,
    YCoord4 = 4,
    YCoord5 = 3,
    YCoord6 = 2,
    YCoord7 = 1,
    YCoord8 = 0,
} YCoord;

typedef enum {
    ActionTypeQuietMove,
    ActionTypeCapture,
} ActionType;

typedef enum {
    ResultMoveCheck,
    ResultMoveMate,
    ResultMoveEnPassant,
    ResultMoveNoResult,
} ResultMove;

typedef struct Move {
    Shape shape;
    XCoord start_x;
    YCoord start_y;
    XCoord end_x;
    YCoord end_y;
    ActionType action_type;
    ResultMove result_move;
    struct Move* next;
} Move;

typedef struct {
    Color color;
    Shape shape;
} Piece;

typedef struct {
    Piece* piece;
} Cell;

#define NUM_OF_ROWS 8
#define NUM_OF_CELLS_IN_BOARD (NUM_OF_ROWS) * (NUM_OF_ROWS)