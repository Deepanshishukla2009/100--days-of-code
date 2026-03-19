#include <stdio.h>

// Define enum for operation status
enum Status { SUCCESS, FAILURE, TIMEOUT };

int main() {
    // Example input
    enum Status result = FAILURE;

    // Print message based on status
    switch (result) {
        case SUCCESS:
            printf("Operation successful\n");
            break;
        case FAILURE:
            printf("Operation failed\n");
            break;
        case TIMEOUT:
            printf("Operation timed out\n");
            break;
        default:
            printf("Unknown status\n");
    }

    return 0;
}