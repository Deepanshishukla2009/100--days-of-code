#include <stdio.h>
int factRecursive(int n) {
    if (n == 0)
        return 1;
    else
        return n * factRecursive(n - 1);
}

int factnonrecursive(int n) {
    int result = 1, i;
    for (i = 1; i <= n; i++)
        result *= i;
    return result;
}
int binomialCoefficient(int n, int r) {
    return factnonrecursive(n) / (factnonrecursive(r) * factnonrecursive(n - r));
}
int main() {
    int n, r;
    printf("Binomial Coefficient Table using FACT(n):\n");
    printf("  n      r      n!      r!     (n-r)!    C(n,r)\n");
    for (n = 0; n <= 5; n++) {
        for (r = 0; r <= n; r++) {
            int fn = factRecursive(n);
            int fr = factnonrecursive(r);
            int fnr = factnonrecursive(n - r);
            int c = binomialCoefficient(n, r);
            printf("%3d   %3d   %5d   %5d   %5d   %8d\n", n, r, fn, fr, fnr, c);
        }
    }
    return 0;
}
