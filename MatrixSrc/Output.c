#include <stdio.h>
#include "Output.h"

int rows;
int columns;
int matrix[dimension][dimension];

void DrawAHorizontalLine();
void DrawVerticalRightBorder();


void OutputMatrix()
{
    DrawAHorizontalLine();
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            printf("|%4.0d  ", matrix[row][column]);
        }

        DrawVerticalRightBorder();
        DrawAHorizontalLine();
    }
}

void DrawAHorizontalLine() {
    for (int i = 0; i < columns; ++i) {
        printf("-------");
    }
    printf("\n");
}

void DrawVerticalRightBorder() {
    printf("| \n");
}
