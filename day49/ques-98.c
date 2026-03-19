#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printInitialsWithSurname(char *name) {
    int i = 0;
    int len = strlen(name);
    int wordStart = 0;
    int spaceCount = 0;

    // Count spaces to identify number of words
    for (i = 0; i < len; i++) {
        if (name[i] == ' ') {
            spaceCount++;
        }
    }

    // Print initials for all words except the last
    int wordIndex = 0;
    for (i = 0; i < len; i++) {
        if (wordIndex < spaceCount) {
            if (i == 0 || name[i - 1] == ' ') {
                printf("%c.", toupper(name[i]));
                wordIndex++;
            }
        } else {
            // Print the surname (last word) in full
            if (name[i] == ' ') {
                printf(" ");
            } else {
                printf("%c", name[i]);
            }
        }
    }

    printf("\n");
}

int main() {
    char name[100];
    printf("Enter a full name: ");
    fgets(name, sizeof(name), stdin);

    // Remove trailing newline if present
    name[strcspn(name, "\n")] = '\0';

    printInitialsWithSurname(name);
    return 0;
}