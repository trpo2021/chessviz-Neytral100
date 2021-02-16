enum Shape { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN };

enum Color { WHITE, BLACK };

struct piece {
    enum Color color;
    enum Shape shape;
} piece;

void board_init(struct piece* board);
void board_output(char*);