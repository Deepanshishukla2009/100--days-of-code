#include <stdio.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k (1-based index for kth smallest): ");
    scanf("%d", &k);

    // Sort the array in ascending order
    qsort(arr, n, sizeof(int), compare);

    // kth smallest element is at index k-1 (assuming k is valid)
    if (k >= 1 && k <= n) {
        printf("The %dth smallest element is: %d\n", k, arr[k-1]);
    } else {
        printf("Invalid value of k.\n");
    }

    return 0;
}
