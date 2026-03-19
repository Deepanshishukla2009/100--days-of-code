#include <stdio.h>

int main() {
    int a = 10; // Declared in main block
    printf("a in main block: %d\n", a);

    {
        int b = 20; // Declared in inner block
        printf("a in inner block: %d\n", a); // Accessible
        printf("b in inner block: %d\n", b); // Accessible
    }

    // printf("b outside inner block: %d\n", b); // Error: 'b' is not accessible here

    if (a == 10) {
        int c = 30; // Declared in if block
        printf("c in if block: %d\n", c); // Accessible
    }

    // printf("c outside if block: %d\n", c); // Error: 'c' is not accessible here

    return 0;
}