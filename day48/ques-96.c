#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseWord(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseEachWord(char *sentence) {
    char *wordStart = NULL;
    char *temp = sentence;

    while (*temp) {
        if (wordStart == NULL && !isspace(*temp)) {
            wordStart = temp;
        }

        if (wordStart && (isspace(*temp) || *(temp + 1) == '\0')) {
            char *wordEnd = (isspace(*temp)) ? temp - 1 : temp;
            reverseWord(wordStart, wordEnd);
            wordStart = NULL;
        }
        temp++;
    }
}

int main() {
    char sentence[200];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove trailing newline if present
    sentence[strcspn(sentence, "\n")] = '\0';

    reverseEachWord(sentence);
    printf("Output: %s\n", sentence);

    return 0;
}