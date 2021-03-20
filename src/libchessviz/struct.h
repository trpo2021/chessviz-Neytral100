#pragma once

typedef enum Shape { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN } Shape;

typedef enum Color { WHITE, BLACK } Color;

typedef struct chess_piece {
    Color color;
    Shape shape;
} Piece;

typedef struct chess_cell {
    Piece* piece;
} Cell;