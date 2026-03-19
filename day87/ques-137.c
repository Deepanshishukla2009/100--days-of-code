#include <stdio.h>
#include <string.h>

// Define enum for user roles
typedef enum {
    ADMIN,
    USER,
    GUEST,
    INVALID
} Role;

// Convert string to enum
Role getRole(char *roleStr) {
    if (strcmp(roleStr, "ADMIN") == 0) return ADMIN;
    if (strcmp(roleStr, "USER") == 0) return USER;
    if (strcmp(roleStr, "GUEST") == 0) return GUEST;
    return INVALID;
}

int main() {
    char roleStr[20];

    // Input: role as string
    scanf("%s", roleStr);

    // Convert string to enum
    Role role = getRole(roleStr);

    // Display message based on role
    switch (role) {
        case ADMIN:
            printf("Welcome Admin!\n");
            break;
        case USER:
            printf("Welcome User!\n");
            break;
        case GUEST:
            printf("Welcome Guest!\n");
            break;
        default:
            printf("Invalid role!\n");
    }

    return 0;
}