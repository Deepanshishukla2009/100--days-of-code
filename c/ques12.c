#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    printf("enter a number:");
    scanf("%d",&n);
    if(n>0)
    {
        printf("the number is positive");
    }
    else if(n<0)
    {
        printf("the number is negative");
    }
    else
    {
        printf("the number is zero");
    }
    return 0;
}