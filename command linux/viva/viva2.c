#include <stdio.h>
int main() {
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        int count = rows - i + 1;
               for (int j = 1; j <= count; j++) {
            printf("%d ", j);
        }
               if (i > 1) {
            for (int k = 1; k <= 2 * i - 3; k++) {
                printf("  ");
            }
        }
               for (int l = count; l >= 1; l--) {
                   if (i == 1 && l == 5) continue;
            printf("%d ", l);
        }
        printf("\n");
    }
    return 0;
}
