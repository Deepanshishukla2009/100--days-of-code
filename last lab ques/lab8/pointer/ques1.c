#include <stdio.h>

int main() {
   
    int a = 50;
    float b = 1.73;
    char c = 'd';

   
    int *p1 = &a;
    float *p2 = &b;
    char *p3 = &c;

    
    printf("Value of a: %d\n", a);
    printf("Value of b: %.2f\n", b);
    printf("Value of c: %c\n", c);

   
    printf("Address stored in p1: %p\n", p1);
    printf("Address stored in p2: %p\n", p2);
    printf("Address stored in p3: %p\n", p3);

   
    printf("Value pointed by p1: %d\n", *p1);
    printf("Value pointed by p2: %.2f\n", *p2);
    printf("Value pointed by p3: %c\n", *p3);

    return 0;
}