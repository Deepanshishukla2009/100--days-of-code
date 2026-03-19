#include<stdio.h>
#include<conio.h>
int main()
{
    int n,sum=0,i;
    printf("enter a value of n:");
    scanf("%d",&n);
     for(i = 1; i <= n; i++)
      {
        sum += (2 * i - 1);
      }
      printf("Sum of first %d odd numbers = %d\n", n, sum);
    return 0;
}