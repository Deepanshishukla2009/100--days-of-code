#include <stdio.h>
int main() {
    int n, i, pos, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n+1];
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &value);

    // Find the position to insert the new value
    pos = n;
    for (i = 0; i < n; i++) {
        if (value < arr[i]) {
            pos = i;
            break;
        }
    }

    // Shift elements to make room for the new element
    for (i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;

    printf("Array after insertion:\n");
    for (i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
