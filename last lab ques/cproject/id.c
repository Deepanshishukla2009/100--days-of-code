#include <stdio.h>

int main() {
    int num;
    int status;

    printf("Enter an integer: ");
    status = scanf("%d", &num);

    if (status == 1) {
        printf("Valid integer: %d\n", num);
    } else {
        printf("Invalid input! Only integers are allowed.\n");
    }

    return 0;
}