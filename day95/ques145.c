#include <stdio.h>

// Define structure
struct Student {
    char name[50];
    int roll;
    int marks;
};

// Function to return top student
struct Student getTopStudent(struct Student arr[], int n) {
    struct Student top = arr[0];  // assume first is top initially
    for (int i = 1; i < n; i++) {
        if (arr[i].marks > top.marks) {
            top = arr[i];
        }
    }
    return top;
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input students
    for (int i = 0; i < n; i++) {
        printf("Enter details (Name Roll Marks) for student %d:\n", i+1);
        scanf("%s %d %d", students[i].name, &students[i].roll, &students[i].marks);
    }

    // Get top student
    struct Student topper = getTopStudent(students, n);

    // Output
    printf("Top Student: %s | Roll: %d | Marks: %d\n", topper.name, topper.roll, topper.marks);

    return 0;
}