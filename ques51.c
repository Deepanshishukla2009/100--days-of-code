#include <stdio.h>
int main() {
    int n;
    printf("enter no of rows:");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print numbers
        for (int j = n - i + 1; j <= n; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}