#include <stdio.h>
#include <string.h>

// Define struct
struct Student {
    char name[50];
    int roll;
    int marks;
};

// Function to compare two students
int areSame(struct Student s1, struct Student s2) {
    if (strcmp(s1.name, s2.name) == 0 && s1.roll == s2.roll && s1.marks == s2.marks) {
        return 1; // identical
    }
    return 0; // not identical
}

int main() {
    struct Student s1, s2;

    // Input for student 1
    printf("Enter Student1 (Name Roll Marks): ");
    scanf("%s %d %d", s1.name, &s1.roll, &s1.marks);

    // Input for student 2
    printf("Enter Student2 (Name Roll Marks): ");
    scanf("%s %d %d", s2.name, &s2.roll, &s2.marks);

    // Compare
    if (areSame(s1, s2)) {
        printf("Same\n");
    } else {
        printf("Not Same\n");
    }

    return 0;
}