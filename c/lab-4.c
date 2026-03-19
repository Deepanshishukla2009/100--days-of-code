#include<stdio.h>
#include<conio.h>
int main()
{
    int unit;
    float bill;
    printf("enter the number of units consumed:");
    scanf("%d",&unit);
    if(unit<=100)
    {
        bill=unit*5;
    }
    else if(unit<=300)
    {
        bill=100*5+(unit-100)*7;
    }
    else
    {
        bill=100*5+200*7+(unit-300)*10;
    }
    printf("total electricity bill is:%.2f\n",bill);
    return 0;
}
