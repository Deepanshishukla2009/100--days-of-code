#include <stdio.h>

int main() {
    int L = 20; // Limit for cubes
    int max = L * L * L + L * L * L;
    int found = 0;

    printf("Ramanujan numbers up to %d^3 + %d^3:\n", L, L);

    for (int n = 2; n <= max; n++) {
        int count = 0;
        // Check all pairs (a, b) such that a^3 + b^3 = n and a > b
        for (int a = 1; a <= L; a++) {
            for (int b = 1; b < a; b++) {
                if (a*a*a + b*b*b == n) {
                    count++;
                }
            }
        }
        if (count >= 2) {
            printf("%d\n", n);
            found = 1;
        }
    }

    if (!found) {
        printf("No Ramanujan numbers found up to the given limit.\n");
    }

    return 0;
}