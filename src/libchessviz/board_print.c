#include <ctype.h>
#include <libchessviz/board_print.h>
#include <libchessviz/struct.h>
#include <stdio.h>

void board_print(Cell* board)
{
    FILE* p_file_board = fopen("Сhessboard.txt", "w");
    if (p_file_board == NULL) {
        printf("Error with open the file");
        return;
    }

    int number_of_line = NUM_OF_ROWS;
    for (int y = 0; y < NUM_OF_ROWS; y++) {
        fprintf(p_file_board, "%d ", number_of_line);
        number_of_line--;
        for (int x = 0; x < NUM_OF_ROWS; x++)
            fprintf(p_file_board,
                    "%c ",
                    interpret(board + y * NUM_OF_ROWS + x));
        fprintf(p_file_board, "\n");
    }

    fprintf(p_file_board, "  ");
    char c;
    for (c = 'a'; c <= 'h'; c++)
        fprintf(p_file_board, "%c ", c);
    fprintf(p_file_board, "\n");

    fclose(p_file_board);
}

char interpret(Cell* choose_cell)
{
    char output_piece;
    if (choose_cell->piece == NULL)
        output_piece = ' ';
    else {
        if (choose_cell->piece->shape == ShapeRook)
            output_piece = 'r';
        else if (choose_cell->piece->shape == ShapeKnight)
            output_piece = 'n';
        else if (choose_cell->piece->shape == ShapeBishop)
            output_piece = 'b';
        else if (choose_cell->piece->shape == ShapeQueen)
            output_piece = 'q';
        else if (choose_cell->piece->shape == ShapeKing)
            output_piece = 'k';
        else if (choose_cell->piece->shape == ShapePawn)
            output_piece = 'p';
        if (choose_cell->piece->color == ColorBlack)
            output_piece = toupper(output_piece);
    }
    return output_piece;
}