#include <stdio.h>

int main() {
    int n, i;
    double sum = 0.0;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        int numerator = 2 * i - 1;
        int denominator = (i == 1) ? 1 : (2 * i);
        sum += (double)numerator / denominator;
    }

    printf("Approximate sum: %.1lf\n", sum);

    return 0;
}