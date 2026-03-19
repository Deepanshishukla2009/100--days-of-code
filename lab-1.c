#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i=1,sum=0;
    printf("enter a value of n:");
    scanf("%d",&n);
    while(i<=n)
    {
        sum=sum+i;
        i++;
    }
    printf("sum of first %d natural numbers is:%d\n",n,sum);
    return 0;
}