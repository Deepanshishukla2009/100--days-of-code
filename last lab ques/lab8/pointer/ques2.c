#include <stdio.h>

int main() {
    int a[3] = {100,200,300};
    float b[3] = {4.5,6.5,8.5};
    char c[3] = {'p', 'q', 'r'};

    int *p1 = a;
    float *p2 = b;
    char *p3 = c;

    printf("Initial addresses:\n");
    printf("p1 (int)   = %p, value = %d\n", p1, *p1);
    printf("p2 (float) = %p, value = %.1f\n", p2, *p2);
    printf("p3 (char)  = %p, value = %c\n", p3, *p3);

   
    p1++;
    p2++;
    p3++;

    printf("\nAfter increment:\n");
    printf("p1 (int)   = %p, value = %d\n", p1, *p1);
    printf("p2 (float) = %p, value = %.1f\n", p2, *p2);
    printf("p3 (char)  = %p, value = %c\n", p3, *p3);


    return 0;
}