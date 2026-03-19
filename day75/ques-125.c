#include <stdio.h>

int main() {
    FILE *fp;
    char text[1000];

    // Open file in append mode
    fp = fopen("data.txt", "a");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    // Get user input
    printf("Enter text to append: ");
    getchar(); // Clear newline left by previous input
    fgets(text, sizeof(text), stdin);

    // Append text to file
    fprintf(fp, "%s", text);

    // Close the file
    fclose(fp);

    // Confirmation message
    printf("File updated successfully with appended text.\n");

    return 0;
}