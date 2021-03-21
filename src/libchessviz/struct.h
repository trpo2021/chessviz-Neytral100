#pragma once

typedef enum {
    ShapeKing,
    ShapeQueen,
    ShapeBishop,
    ShapeKnight,
    ShapeRook,
    ShapePawn
} Shape;

typedef enum { ColorWhite, ColorBlack } Color;

typedef struct {
    Color color;
    Shape shape;
} Piece;

typedef struct {
    Piece* piece;
} Cell;

#define NUM_OF_ROWS 8
#define NUM_OF_CELLS_IN_BOARD (NUM_OF_ROWS) * (NUM_OF_ROWS)