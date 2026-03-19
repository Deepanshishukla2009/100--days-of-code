#include <stdio.h>

// Define enum for status codes
typedef enum {
    SUCCESS,
    FAILURE,
    TIMEOUT
} Status;

int main() {
    // Print enum names with their corresponding integer values
    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d\n", SUCCESS, FAILURE, TIMEOUT);
    return 0;
}