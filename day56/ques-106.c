#include <stdio.h>

void findNextGreaterElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int nextGreater = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nextGreater = arr[j];
                break;
            }
        }
        printf("%d", nextGreater);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    // Example input
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    findNextGreaterElements(arr, n);

    return 0;
}