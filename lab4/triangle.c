#include <stdio.h>
int istriangleValid(float a, float b, float c) {
    return (a + b > c) && (b + c > a) && (a + c > b);
}
void triangle(float a, float b, float c) {
    if (a == b && b == c) {
        printf("triangle is equilateral\n");
    }
    else if (a == b || b == c || a == c) {
        printf("triangle is isosceles\n");
    }
    else if ((a*a == b*b + c*c) || 
             (b*b == a*a + c*c) ||
             (c*c == a*a + b*b)) {
        printf("triangle is rightangled\n");
    }
    else {
        printf("triangle is scalene\n");
    }
}
int main() {
    float a, b, c;
    printf("enter three sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    if (istriangleValid(a, b, c)) {
        printf("triangle is valid\n");
        triangle(a, b, c);
    } else {
        printf("triangle is invalid\n");
    }
    return 0;
}
