#include <ctype.h>
#include <libchessviz/board_print.h>
#include <libchessviz/struct.h>
#include <stdio.h>

void board_print(Cell* board)
{
    FILE* pFileBoard = fopen("Сhessboard.txt", "w");
    if (pFileBoard == NULL) {
        printf("Error with open the file");
        return;
    }

    int numberofline = 8;
    for (int y = 0; y <= 7; y++) {
        fprintf(pFileBoard, "%d ", numberofline);
        numberofline--;
        for (int x = 0; x <= 7; x++)
            fprintf(pFileBoard, "%c ", interpret(board + y * 8 + x));
        fprintf(pFileBoard, "\n");
    }

    fprintf(pFileBoard, "  ");
    char c;
    for (c = 'a'; c <= 'h'; c++)
        fprintf(pFileBoard, "%c ", c);
    fprintf(pFileBoard, "\n");

    fclose(pFileBoard);
}

char interpret(Cell* choosecell)
{
    char output_piece;
    if (choosecell->piece == NULL)
        output_piece = ' ';
    else {
        if (choosecell->piece->shape == ROOK)
            output_piece = 'r';
        else if (choosecell->piece->shape == KNIGHT)
            output_piece = 'n';
        else if (choosecell->piece->shape == BISHOP)
            output_piece = 'b';
        else if (choosecell->piece->shape == QUEEN)
            output_piece = 'q';
        else if (choosecell->piece->shape == KING)
            output_piece = 'k';
        else if (choosecell->piece->shape == PAWN)
            output_piece = 'p';
        if (choosecell->piece->color == BLACK)
            output_piece = toupper(output_piece);
    }
    return output_piece;
}