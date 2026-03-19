#include <stdio.h>
#include <string.h>

void printSubstrings(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            for (int k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf(","); // Separate substrings with commas
        }
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("All substrings: ");
    printSubstrings(str);

    return 0;
}