#include <stdio.h>

int main() {
    int a, b, c, d;
    int L;

    printf("Enter the limit (L): ");
    scanf("%d", &L);

    printf("Ramanujan Numbers up to %d are:\n", L);

    // check all possible combinations
    for (a = 1; a <= L; a++) {
        for (b = a; b <= L; b++) {
            for (c = a + 1; c <= L; c++) {
                for (d = c; d <= L; d++) {
                    if ((a*a*a + b*b*b) == (c*c*c + d*d*d)) {
                        printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n",
                               a*a*a + b*b*b, a, b, c, d);
                    }
                }
            }
        }
    }

    return 0;
}
