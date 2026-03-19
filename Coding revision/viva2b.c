#include <stdio.h>
#include <string.h>
int main() {
    char word[21];
    printf("enter the word:");
    scanf("%s", word);

    int z_count = 0, o_count = 0;
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == 'z') {
            z_count++;
        } 
        else if(word[i] == 'o') 
        {
            o_count++;
        }
    }

    if (o_count >= 2 * z_count) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}