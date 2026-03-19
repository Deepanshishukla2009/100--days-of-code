#include <stdio.h>

// Global variable
int globalVar = 10;

void myFunction() {
    // Local variable
    int localVar = 20;
    printf("Inside function: localVar = %d\n", localVar);
    printf("Inside function: globalVar = %d\n", globalVar);
}

int main() {
    myFunction();

    // Uncommenting the next line will cause a compile error,
    // because localVar is not accessible outside myFunction.
    // printf("Outside function: localVar = %d\n", localVar);

    // But globalVar can be accessed anywhere in this file.
    printf("Outside function: globalVar = %d\n", globalVar);

    return 0;
}