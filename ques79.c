#include <stdio.h>

#define ROWS 4
#define COLS 4

void diagonalTraversal(int mat[ROWS][COLS], int rows, int cols) {
    for (int d = 0; d < rows + cols - 1; d++) {
        int row = (d < cols) ? 0 : d - cols + 1;
        int col = (d < cols) ? d : cols - 1;
        while (row < rows && col >= 0) {
            printf("%d ", mat[row][col]);
            row++;
            col--;
        }
    }
    printf("\n");
}

int main() {
    int mat[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Diagonal Traversal of the matrix:\n");
    diagonalTraversal(mat, ROWS, COLS);

    return 0;
}