#include <stdio.h>
int perimeter(int l, int b) {
    return 2 * (l + b);
}

int main() {
    int l1, b1, l2, b2, l3, b3;
    int p1, p2, p3;
    printf("Enter length and breadth of rectangle 1: ");
    scanf("%d %d", &l1, &b1);

    printf("Enter length and breadth of rectangle 2: ");
    scanf("%d %d", &l2, &b2);

    printf("Enter length and breadth of rectangle 3: ");
    scanf("%d %d", &l3, &b3);

    p1 = perimeter(l1, b1);
    p2 = perimeter(l2, b2);
    p3 = perimeter(l3, b3);
    (p1>p2)?
    ((p1>p3)?printf("rectangle1 has highest perimeter"):printf("rectangle3 has highest perimeter")):
    ((p2>p3)?printf("rectangle2 has highest perimeter"):printf("rectangle3 has highest perimeter"));
    return 0;
}
