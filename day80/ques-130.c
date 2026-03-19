
#include <stdio.h>

int main() {
    FILE *file;
    char name[50];
    int roll, marks;

    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error: Cannot open file for writing.\n");
        return 1;
    }

    fprintf(file, "%s %d %d\n", "Asha", 101, 85);
    fprintf(file, "%s %d %d\n", "Ravi", 102, 92);

    fclose(file);

    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file for reading.\n");
        return 1;
    }

    printf("Student Records:\n");
    while (fscanf(file, "%s %d %d", name, &roll, &marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);
    }

    fclose(file);
    return 0;
}