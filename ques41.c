#include <stdio.h>
#include <math.h>
int swapFirstLast(int num) {
    int first, last, digits, pow10, middle, swapped;
    last = num % 10;
    digits = (int)log10(num);
    pow10 = (int)pow(10, digits);
    first = num / pow10;
    middle = (num % pow10) / 10;
    swapped = last * pow10 + middle * 10 + first;
    return swapped;
}
int main() {
    int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 10) {
        printf("Swapped number: %d\n", num);
    } else {
        result = swapFirstLast(num);
        printf("Swapped number: %d\n", result);
    }
    return 0;
}