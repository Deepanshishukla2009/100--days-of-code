#include <stdio.h>
#include <string.h>

// Define enum for gender
typedef enum {
    MALE,
    FEMALE,
    OTHER,
    INVALID
} Gender;

// Convert string to enum
Gender getGender(char *genderStr) {
    if (strcmp(genderStr, "MALE") == 0) return MALE;
    if (strcmp(genderStr, "FEMALE") == 0) return FEMALE;
    if (strcmp(genderStr, "OTHER") == 0) return OTHER;
    return INVALID;
}

// Define struct for person
typedef struct {
    Gender gender;
} Person;

int main() {
    char genderStr[20];

    // Input: gender as string
    scanf("%s", genderStr);

    // Create person and assign gender
    Person p;
    p.gender = getGender(genderStr);

    // Print gender
    switch (p.gender) {
        case MALE:
            printf("Male\n");
            break;
        case FEMALE:
            printf("Female\n");
            break;
        case OTHER:
            printf("Other\n");
            break;
        default:
            printf("Invalid gender\n");
    }

    return 0;
}