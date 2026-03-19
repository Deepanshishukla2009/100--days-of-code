#include <stdio.h>
int main() {
    int ROWS, COLS, i, j;
    printf("enter number of rows and columns:");
    scanf("%d %d", &ROWS, &COLS);
    int a[ROWS][COLS], b[ROWS][COLS], sum[ROWS][COLS];

    // Input first matrix
    printf("Enter elements of first matrix (%dx%d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix (%dx%d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Add matrices
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print result
    printf("Sum of the matrices:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}