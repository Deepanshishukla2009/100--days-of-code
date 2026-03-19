#include <stdio.h>
#include<conio.h>
int main() 
{
    float population = 100000;
    int i;
    printf("Year\tPopulation\n");
    for (i = 1; i <= 10; i++) 
    {
        population = population *1.1;
        printf("%d\t%.0f\n", i, population);
    }
    return 0;
}
