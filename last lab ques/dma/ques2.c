#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, count;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int)); 

    if (arr == NULL || visited == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }

    printf("\nFrequencies:\n");
    for (i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("Element %d appears %d time%s\n", arr[i], count, count > 1 ? "s" : "");
    }

    free(arr);
    free(visited);
    return 0;
}