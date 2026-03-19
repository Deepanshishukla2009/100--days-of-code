#include <stdio.h>

// Define structure
struct Student {
    char name[50];
    int roll;
    int marks;
};

// Function to print structure members
void printStudent(struct Student s) {
    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll, s.marks);
}

int main() {
    struct Student st;

    // Prompt user for input
    printf("Enter student details (Name Roll Marks):\n");
    scanf("%s %d %d", st.name, &st.roll, &st.marks);

    // Call function to print
    printStudent(st);

    return 0;
}