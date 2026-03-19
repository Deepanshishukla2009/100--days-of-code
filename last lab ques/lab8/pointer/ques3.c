#include <stdio.h>


void updateValues(int *x, float *y, char *z) {
    *x = *x + 10;       
    *y = *y * 4;        
    *z = 'q';         
}

int main() {
    int a = 30;
    float b = 9.5;
    char c = 'p';

    printf("Before function call:\n");
    printf("a = %d, b = %.2f, c = %c\n", a, b, c);

    
    updateValues(&a, &b, &c);

    printf("\nAfter function call:\n");
    printf("a = %d, b = %.2f, c = %c\n", a, b, c);

    return 0;
}