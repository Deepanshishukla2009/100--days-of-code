#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,fact=1;
    printf("enter value of n:");
    scanf("%d",&n);
    if(n<0)
    {
        printf("factorial is not defined for negative integer");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            fact *= i;
        }
        printf("Factorial of %d is: %d\n", n, fact);
    }
    return 0;
}