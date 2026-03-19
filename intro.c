#include <stdio.h>

int main() {
    char name[50];   // to store name
    int age;         // to store age

    // Input from user
    printf("Enter your name: ");
    scanf("%s", name);   // takes single word as input (without spaces)

    printf("Enter your age: ");
    scanf("%d", &age);

    // Output
    printf("\nYour Name: %s\n", name);
    printf("Your Age: %d\n", age);

    return 0;
}