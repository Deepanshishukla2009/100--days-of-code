#include <stdio.h>
#include<conio.h>
int main() 
{
    int L = 10; // Limit for cubes
    int max = L * L * L + L * L * L; // Maximum number to check

    printf("Ramanujan numbers up to %d^3 + %d^3:\n", L, L);

    for (int n = 2; n <= max; n++) {
        int count = 0;
        // Find all pairs (a, b) such that a^3 + b^3 = n and a > b
        for (int a = 1; a <= L; a++) {
            for (int b = 1; b < a; b++) {
                if (a*a*a + b*b*b == n) {
                    count++;
                    if (count == 1) {
                        printf("%d = %d^3 + %d^3", n, a, b);
                    } else if (count == 2) {
                        printf(" = %d^3 + %d^3", a, b);
                    }
                }
            }
        }
        if (count >= 2) {
            printf("\n");
        }
    }
    return 0;
}