#include<stdio.h>
#include<conio.h>
int main()
{
    float temperature,celcius,fahrenheit;
    printf("enter the temperature in fahrenheit:");
    scanf("%f",&temperature);
    celcius=(temperature-32)*5/9;
    printf("the temperature in celcius is:%.2f",celcius);
    return 0;
}