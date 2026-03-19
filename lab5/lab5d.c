#include <stdio.h>
int main() {
    int years = 10;
    double population = 100000.0;
    double rate = 0.10;

    printf("Year\tPopulation\n");
    for (int i = 1; i <= 10; i++) {
        population = population + (population * rate);
        printf("%d\t%.0f\n", i, population);
    }

    return 0;
}