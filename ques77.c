#include <stdio.h>

#define N 100

int main() {
    int n, i, j, flag = 1;
    int mat[N][N];
    int diag[N];

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    // Store diagonal elements
    for (i = 0; i < n; i++)
        diag[i] = mat[i][i];

    // Check for distinctness
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (diag[i] == diag[j]) {
                flag = 0;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag)
        printf("Diagonal elements are distinct.\n");
    else
        printf("Diagonal elements are not distinct.\n");

    return 0;
}