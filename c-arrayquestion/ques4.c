//Search for an element in an array using linear search.
#include <stdio.h>

int linear(int n, int arr[], int k) {
    for (int i = 0; i < n; i++) {  // Start from 0
        if (arr[i] == k) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found (outside loop)
}

int main() {
    int n, k, result;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {  // Start from 0
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you want to find: ");
    scanf("%d", &k);

    result = linear(n, arr, k);
    if (result != -1) {
        printf("Found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}