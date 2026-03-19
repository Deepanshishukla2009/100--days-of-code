#include <stdio.h>
#include <string.h>

// Define enum for operations
typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    INVALID
} Operation;

// Function to convert string to enum
Operation getOperation(char *opStr) {
    if (strcmp(opStr, "ADD") == 0) return ADD;
    if (strcmp(opStr, "SUBTRACT") == 0) return SUBTRACT;
    if (strcmp(opStr, "MULTIPLY") == 0) return MULTIPLY;
    return INVALID;
}

int main() {
    char opStr[20];
    int a, b;

    // Input: operation string and two integers
    scanf("%s %d %d", opStr, &a, &b);

    // Convert string to enum
    Operation op = getOperation(opStr);

    // Perform operation using switch
    switch (op) {
        case ADD:
            printf("%d\n", a + b);
            break;
        case SUBTRACT:
            printf("%d\n", a - b);
            break;
        case MULTIPLY:
            printf("%d\n", a * b);
            break;
        default:
            printf("Invalid operation\n");
    }

    return 0;
}