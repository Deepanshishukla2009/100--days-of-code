#include <stdio.h>

int main() {
    FILE *fp;
    char name[100];
    int age;

    // Input from user
    printf("Enter your name: ");
    scanf("%s", name);  // For full names with spaces, use fgets instead
    printf("Enter your age: ");
    scanf("%d", &age);

    // Create and open file in write mode
    fp = fopen("info.txt", "w");

    // Check if file was created successfully
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    // Write data to file
    fprintf(fp, "Name: %s\nAge: %d\n", name, age);

    // Close the file
    fclose(fp);

    // Confirmation message
    printf("File created successfully! Data written to info.txt\n");

    return 0;
}