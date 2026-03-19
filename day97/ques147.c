#include <stdio.h>
#include <stdlib.h>

// Define employee structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp, emp_read;
    FILE *fp;

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // consume newline

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    // Open file in binary write mode
    fp = fopen("employee.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write structure to file
    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("\nEmployee details entered and stored in file.\n");

    // Open file in binary read mode
    fp = fopen("employee.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read structure from file
    fread(&emp_read, sizeof(struct Employee), 1, fp);
    fclose(fp);

    // Display employee details
    printf("\nEmployee details read from file:\n");
    printf("ID: %d\n", emp_read.id);
    printf("Name: %s", emp_read.name);
    printf("Salary: %.2f\n", emp_read.salary);

    return 0;
}