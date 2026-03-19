#include <stdio.h>
#include <string.h>
#include <ctype.h>

int areAnagrams(const char *str1, const char *str2) {
    int freq[26] = {0}; // For lowercase letters a-z

    // If lengths differ, they can't be anagrams
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    // Count frequency of each character in str1
    for (int i = 0; str1[i] != '\0'; i++) {
        if (islower(str1[i])) {
            freq[str1[i] - 'a']++;
        }
    }

    // Subtract frequency using str2
    for (int i = 0; str2[i] != '\0'; i++) {
        if (islower(str2[i])) {
            freq[str2[i] - 'a']--;
        }
    }

    // Check if all frequencies are zero
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) {
        printf("Anagrams\n");
    } else {
        printf("Not anagrams\n");
    }

    return 0;
}