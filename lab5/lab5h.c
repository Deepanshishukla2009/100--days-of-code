#include <stdio.h>
int main() {
    int a = 10;
    printf("a in main block: %d\n", a);
    {
        int b = 20;
        printf("a in inner block: %d\n", a);
        printf("b in inner block: %d\n", b);
    }
    if (a == 10) {
        int c = 30;
        printf("c in if block: %d\n", c);
    }
    return 0;
}