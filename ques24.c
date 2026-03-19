#include<stdio.h>
#include<conio.h>
int main()
{
    float unit,bill;
    printf("enter number of units consumed:");
    scanf("%f",&unit);
    if(unit<=100)
    {
        bill=unit*5;
        printf("bill is %.2f\n",bill);
    }
    else if(unit<=200)
    {
        bill=100*5+(unit-100)*7;
        printf("bill is %.2f\n", bill);
    }
    else if(unit<=300)
    {
        bill=100*5+100*7+(unit-200)*10;
        printf("bill is %.2f\n",bill);
    }
    else
    {
        bill=100*5+100*7+100*10+(unit-300)*12;
        printf("bill is %.2f\n",bill);
    }
    return 0;
}