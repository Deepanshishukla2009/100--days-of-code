#include <stdio.h>
#include <string.h>
int main() {
    char binary[100], onesComp[100];
    int i;
    printf("Enter a binary number: ");
    scanf("%s", binary);
    for(i = 0; binary[i] != '\0'; i++) {
        if(binary[i] == '0')
            onesComp[i] = '1';
        else if(binary[i] == '1')
            onesComp[i] = '0';
        else {
            printf("Invalid binary digit detected.\n");
            return 1;
        }
    }
    onesComp[i] = '\0';
    printf("1's complement: %s\n", onesComp);
    return 0;
}