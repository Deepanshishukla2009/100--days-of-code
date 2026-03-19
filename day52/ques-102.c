#include <stdio.h>

// Function to find index of ceil of x
int findCeil(int arr[], int size, int x) {
    int low = 0, high = size - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            result = mid;       // potential ceil found
            high = mid - 1;     // search left half for earlier occurrence
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 8, 10, 11, 12, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter x: ");
    scanf("%d", &x);

    int index = findCeil(arr, size, x);
    printf("%d\n", index);

    return 0;
}