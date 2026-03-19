#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[1000];

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Convert to sentence case
    int capitalize = 1; // Flag to capitalize the next character
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            capitalize = 1;
        } else if (capitalize && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            capitalize = 0;
        } else {
            str[i] = tolower(str[i]);
        }
    }

    // Output the result
    printf("Sentence case: %s\n", str);

    return 0;
}