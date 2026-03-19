#include <stdio.h>

int findPivotIndex(int nums[], int size) {
    int totalSum = 0, leftSum = 0;

    // Calculate total sum of the array
    for (int i = 0; i < size; i++) {
        totalSum += nums[i];
    }

    // Iterate to find the pivot index
    for (int i = 0; i < size; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main() {
    // Example input
    int nums[] = {1, 7, 3, 6, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);

    int pivotIndex = findPivotIndex(nums, size);
    printf("%d\n", pivotIndex);

    return 0;
}