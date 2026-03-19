#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int main() {
    int p, q, sum;
    printf("enter the first number: ");
    scanf("%d", &p);
    printf("enter the second number: ");
    scanf("%d", &q);

    sum = add(p, q); 
    printf("sum = %d\n", sum);
    return 0;
}
