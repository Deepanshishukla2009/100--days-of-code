#include <stdio.h>
int isprime(int n) {
    if (n <= 1) return 0;
    if (n % 2== 0) return 0;
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main() {
    int lower, upper, i;
    printf("Enter lower and upper range: ");
    scanf("%d %d", &lower, &upper);

    printf("Prime numbers between %d and %d are:\n", lower, upper);
    for (i = lower; i <= upper; i++) {
        if (isprime(i))
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
