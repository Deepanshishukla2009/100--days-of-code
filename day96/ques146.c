#include <stdio.h>

// Nested structure for Date
struct Date {
    int day;
    int month;
    int year;
};

// Employee structure containing Date
struct Employee {
    char name[50];
    int id;
    struct Date joiningDate;
};

// Function to print employee details
void printEmployee(struct Employee e) {
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           e.name, e.id, e.joiningDate.day, e.joiningDate.month, e.joiningDate.year);
}

int main() {
    struct Employee emp;

    // Input
    printf("Enter employee details (Name ID Day Month Year):\n");
    scanf("%s %d %d %d %d", emp.name, &emp.id,
          &emp.joiningDate.day, &emp.joiningDate.month, &emp.joiningDate.year);

    // Output
    printEmployee(emp);

    return 0;
}