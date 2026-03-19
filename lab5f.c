#include <stdio.h>

// Global variable declaration
int globalVar = 10;

void displayGlobal() {
    printf("Value of globalVar in displayGlobal(): %d\n", globalVar);
}

void modifyGlobal() {
    globalVar += 5;
    printf("Value of globalVar after modification in modifyGlobal(): %d\n", globalVar);
}

int main() {
    printf("Initial value of globalVar in main(): %d\n", globalVar);
    displayGlobal();
    modifyGlobal();
    printf("Final value of globalVar in main(): %d\n", globalVar);
    return 0;
}