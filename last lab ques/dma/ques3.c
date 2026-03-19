#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, evenCount = 0, oddCount = 0;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    
    int *even = (int *)malloc(evenCount * sizeof(int));
    int *odd = (int *)malloc(oddCount * sizeof(int));

    if (even == NULL || odd == NULL) {
        printf("Memory allocation failed.\n");
        free(arr);
        return 1;
    }

   
    int e = 0, o = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even[e++] = arr[i];
        else
            odd[o++] = arr[i];
    }

    
    printf("Even elements: ");
    for (i = 0; i < evenCount; i++)
        printf("%d ", even[i]);

    printf("\nOdd elements: ");
    for (i = 0; i < oddCount; i++)
        printf("%d ", odd[i]);

    
    free(arr);
    free(even);
    free(odd);

    return 0;
}