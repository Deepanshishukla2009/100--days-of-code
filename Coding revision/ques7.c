#include<stdio.h>
#include<conio.h>
int main()
{
    float total_sp,profit,cp;
    printf("enter the total selling price of 15 items:");
    scanf("%f",&total_sp);
    printf("enter the total profit earned:");
    scanf("%f",&profit);
    cp=(total_sp-profit)/15;
    printf("the cost price of one item is:%.2f",cp);
    return 0;
}