#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Need at least two integers.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int first = arr[0], second = -2147483648;
    for (i = 1; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == -2147483648) {
        printf("There is no second largest integer.\n");
    } else {
        printf("The second largest integer is: %d\n", second);
    }

    return 0;
}