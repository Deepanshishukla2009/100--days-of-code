#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int p,r,t;
    float si,ci,amount;
    printf("enter the principle amount:");
    scanf("%d",&p);
    printf("enter the rate of interest:");
    scanf("%d",&r);
    printf("enter the time period:");
    scanf("%d",&t);
    si=(p*r*t)/100.0;
    amount=p*pow((1+r/100.0),t);
    ci=amount-p;    
    printf("the simple interest is%.2f\n",si);
    printf("the compound interest is:%.2f\n",ci);
    return 0;
}