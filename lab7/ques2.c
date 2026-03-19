#include <stdio.h>
int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a%b);
}

int main() {
    int x, y, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    result = GCD(x, y);

    printf("The GCD of %d and %d is %d\n", x, y, result);

    return 0;
}
