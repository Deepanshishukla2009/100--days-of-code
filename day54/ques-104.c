#include <stdio.h>

int findPivotInteger(int n) {
    int totalSum = n * (n + 1) / 2;

    for (int x = 1; x <= n; x++) {
        int leftSum = x * (x + 1) / 2;
        int rightSum = totalSum - (x - 1) * x / 2;
        if (leftSum == rightSum) {
            return x;
        }
    }

    return -1;
}

int main() {
    int n;

    // Input
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // Output
    int pivot = findPivotInteger(n);
    printf("%d\n", pivot);

    return 0;
}