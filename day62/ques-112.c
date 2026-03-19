#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers separated by spaces:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = arr[0];
    int curr_sum = arr[0];

    for(int i = 1; i < n; i++) {
        // Update current subarray sum: either start fresh from arr[i], or continue
        curr_sum = (curr_sum + arr[i] > arr[i]) ? (curr_sum + arr[i]) : arr[i];

        // Update max_sum if we've found a new larger sum
        if(curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    printf("Maximum subarray sum: %d\n", max_sum);

    return 0;
}
