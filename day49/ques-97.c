#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printInitials(char *name) {
    int i = 0;

    // Print the first initial
    if (isalpha(name[i])) {
        printf("%c.", toupper(name[i]));
    }

    // Traverse the rest of the string
    while (name[i] != '\0') {
        if (name[i] == ' ' && isalpha(name[i + 1])) {
            printf("%c.", toupper(name[i + 1]));
        }
        i++;
    }

    printf("\n");
}

int main() {
    char name[100];
    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);

    // Remove trailing newline if present
    name[strcspn(name, "\n")] = '\0';

    printInitials(name);
    return 0;
}