#include <stdio.h>
float area(float l, float b) {
    return l * b;
}
float perimeter(float l, float b) {
    return 2 * (l + b);
}
int main() {
    float l, b;
    printf("enter the length of the rectangle: ");
    scanf("%f", &l);
    printf("enter the breadth of the rectangle: ");
    scanf("%f", &b);

    printf("area of the rectangle: %.2f\n", area(l,b));
    printf("perimeter of the rectangle: %.2f\n", perimeter(l,b));
    return 0;
}
