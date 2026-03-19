#include <stdio.h>

#define MAX 1000

void printFirstNegative(int arr[], int n, int k) {
    int queue[MAX], front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        // Add current element to queue if it's negative
        if (arr[i] < 0)
            queue[++rear] = i;

        // Remove elements out of current window
        if (front <= rear && queue[front] < i - k + 1)
            front++;

        // Print result for window ending at i
        if (i >= k - 1) {
            if (front <= rear)
                printf("%d ", arr[queue[front]]);
            else
                printf("0 ");
        }
    }
}

int main() {
    // Sample Input 1
    int arr1[] = {-8, 2, 3, -6, 10};
    int k1 = 2;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printFirstNegative(arr1, n1, k1);
    printf("\n");

    // Sample Input 2
    int arr2[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int k2 = 3;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printFirstNegative(arr2, n2, k2);
    printf("\n");

    // Sample Input 3
    int arr3[] = {12, 1, 3, 5};
    int k3 = 3;
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printFirstNegative(arr3, n3, k3);
    printf("\n");

    return 0;
}