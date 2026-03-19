#include <stdio.h>

int findMajorityElement(int nums[], int n) {
    int count = 0, candidate = -1;

    // Phase 1: Find a candidate using Boyer-Moore Voting Algorithm
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify if candidate is actually the majority
    count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    }

    return -1;
}

int main() {
    // Example input
    int nums[] = {2, 2, 1, 1, 1, 2, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    int majority = findMajorityElement(nums, n);
    printf("%d\n", majority);

    return 0;
}