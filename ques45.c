#include <stdio.h>

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    double sum = 0.0;
    int num = 2, den = 3;

    for (int i = 0; i < n; i++) {
        sum += (double)num / den;
        num += 2;
        den += 4;
    }

    printf("Approximate sum: %.2lf\n", sum);
    return 0;
}