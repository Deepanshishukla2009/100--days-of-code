#include<stdio.h>
#include<conio.h>
int main()
{
    float temp,fahrenheit,celsius;
    printf("enter temperature in celsius:");
    scanf("%f",&celsius);
    fahrenheit=(celsius*9/5)+32;
    printf("the temperature in fahrenheit is:%.2f\n",fahrenheit);
    return 0;
}