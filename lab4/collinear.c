#include <stdio.h>
int areCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("enter coordinates of first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("enter coordinates of second point (x2 ,y2): ");
    scanf("%d %d", &x2, &y2);
    printf("enter coordinates of third point (x3 ,y3): ");
    scanf("%d %d", &x3, &y3);

    if (areCollinear(x1, y1, x2, y2, x3, y3))
        printf("the points are collinear\n");
    else
        printf("the points are not collinear\n");
    return 0;
}
