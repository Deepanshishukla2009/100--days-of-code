#include <stdio.h>

// Define enum with explicit starting value
enum Letters { A = 10, B, C };

int main() {
    // Print each enum constant with its value
    printf("A=%d\n", A);
    printf("B=%d\n", B);
    printf("C=%d\n", C);

    return 0;
}