#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int min1 = i < j ? i : j;
            int min2 = (size - 1 - i) < (size - 1 - j) ? (size - 1 - i) : (size - 1 - j);
            int val = n - (min1 < min2 ? min1 : min2);
            printf("%d ", val);
        }
        printf("\n");
    }
    return 0;
}
