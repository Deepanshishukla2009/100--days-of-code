#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, position, newElement;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 1) * sizeof(int)); 
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    printf("Enter element to insert: ");
    scanf("%d", &newElement);

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &position);

    if (position < 1 || position > n + 1) {
        printf("Invalid position.\n");
        free(arr);
        return 1;
    }


    for (i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = newElement; 

    printf("Array after insertion: ");
    for (i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); 
    return 0;
}