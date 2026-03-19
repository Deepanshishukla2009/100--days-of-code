#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter %d integers between 0 and %d except one missing number:\n", n, n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Calculate expected sum of numbers from 0 to n
    int total = (n * (n + 1)) / 2;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    int missing = total - sum;
    printf("Missing number: %d\n", missing);

    return 0;
}
