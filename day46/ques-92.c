#include <stdio.h>
#include <string.h>

char firstRepeatingChar(const char *str) {
    int freq[26] = {0}; // For lowercase letters a-z

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
            if (freq[ch - 'a'] == 2) {
                return ch;
            }
        }
    }
    return '\0'; // No repeating character found
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstRepeatingChar(str);
    if (result != '\0') {
        printf("First repeating lowercase alphabet: %c\n", result);
    } else {
        printf("No repeating lowercase alphabet found.\n");
    }

    return 0;
}