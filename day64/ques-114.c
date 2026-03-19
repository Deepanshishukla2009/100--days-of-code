#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

int main() {
    char s[1000];
    printf("Enter the string: ");
    scanf("%s", s);

    int n = strlen(s);
    int last_index[MAX_CHARS];
    for(int i = 0; i < MAX_CHARS; i++)
        last_index[i] = -1;                    // Initialize all indices to -1

    int max_len = 0, start = 0;
    for(int i = 0; i < n; i++) {
        // If character seen before and within window, move start after last occurrence
        if(last_index[(unsigned char)s[i]] >= start)
            start = last_index[(unsigned char)s[i]] + 1;
        // Update last seen index
        last_index[(unsigned char)s[i]] = i;

        int curr_len = i - start + 1;
        if(curr_len > max_len)
            max_len = curr_len;
    }

    printf("Length of longest substring without repeating characters: %d\n", max_len);

    return 0;
}
