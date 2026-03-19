#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter %d integers where only one element is repeated:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int xor_all = 0;
    // XOR all elements of the array
    for(int i = 0; i < n; i++) {
        xor_all ^= nums[i];
    }

    // XOR numbers from 0 to n-2 (since one number is repeated)
    for(int i = 0; i < n - 1; i++) {
        xor_all ^= i;
    }

    // xor_all now contains the repeated number
    printf("Repeated element: %d\n", xor_all);

    return 0;
}
