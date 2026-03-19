#include <stdio.h>

void demoFunction() {
    static int count = 0; // static local variable
    count++;
    printf("Function called %d times\n", count);
}

int main() {
    for (int i = 0; i < 5; i++) {
        demoFunction();
    }
    return 0;
}