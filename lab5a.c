#include<stdio.h>
int main() {
    int num, positivecount = 0, negetivecount = 0, zerocount = 0;
    char choice;
    for (;;) {
        printf("enter the number\n");
        scanf("%d", &num);
        if (num > 0) {
            positivecount++;
        } else if (num < 0) {
            negetivecount++;
        } else {
            zerocount++;
        }
        printf("do you want to continue y/n\n");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }
    printf("positive count is %d\n", positivecount);
    printf("negetive count is %d\n", negetivecount);
    printf("zero count is %d\n", zerocount);
return 0;
}