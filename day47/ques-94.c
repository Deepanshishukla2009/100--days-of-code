#include <stdio.h>
#include <string.h>

void findLongestWord(char *sentence) {
    int maxLen = 0, currLen = 0;
    char longest[100], word[100];
    int i = 0, j = 0;

    while (1) {
        char ch = sentence[i];
        if (ch != ' ' && ch != '\0') {
            word[j++] = ch;
        } else {
            word[j] = '\0';
            currLen = strlen(word);
            if (currLen > maxLen) {
                maxLen = currLen;
                strcpy(longest, word);
            }
            j = 0;
        }
        if (ch == '\0') break;
        i++;
    }

    printf("Longest word: %s\n", longest);
}

int main() {
    char sentence[200];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove trailing newline if present
    sentence[strcspn(sentence, "\n")] = '\0';

    findLongestWord(sentence);
    return 0;
}