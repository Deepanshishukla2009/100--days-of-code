#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    struct Student s;          // Normal structure variable
    struct Student *ptr;       // Pointer to structure

    ptr = &s;  // Point to the structure variable

    // Modify values using -> operator
    strcpy(ptr->name, "John");
    ptr->roll = 106;
    ptr->marks = 91;

    // Display modified data
    printf("Modified Data: Name: %s | Roll: %d | Marks: %d\n",
           ptr->name, ptr->roll, ptr->marks);

    return 0;
}