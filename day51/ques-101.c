#include <stdio.h>

// Function to find first occurrence of target
int findFirst(int nums[], int size, int target) {
    int low = 0, high = size - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            high = mid - 1; // search left half
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to find last occurrence of target
int findLast(int nums[], int size, int target) {
    int low = 0, high = size - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            low = mid + 1; // search right half
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target;

    printf("Enter target: ");
    scanf("%d", &target);

    int first = findFirst(nums, size, target);
    int last = findLast(nums, size, target);

    printf("%d,%d\n", first, last);
    return 0;
}