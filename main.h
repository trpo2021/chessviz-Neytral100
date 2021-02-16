enum Shape { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN };

enum Color { WHITE, BLACK };

struct piece {
    enum Color color;
    enum Shape shape;
} piece;

char* board_init();
void board_output(char*);