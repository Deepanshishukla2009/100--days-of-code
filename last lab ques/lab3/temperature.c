#include <stdio.h>
float temperaturechange(float c) {
    return (c * 9 / 5) + 32;
}
int main() {
    float c, f;
    printf("enter temperature in celsius: ");
    scanf("%f", &c);
    f = temperaturechange(c);
    printf("temperature in fahrenheit:%.2f\n", f);
    return 0;
}

