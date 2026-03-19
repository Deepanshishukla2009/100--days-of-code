#include<stdio.h>
#include<conio.h>
int main()
{
    int n,remainder,reverse=0;
    printf("enter value of n:");
    scanf("%d",&n);
     while(n>0)
    {  
        remainder=n%10;
        reverse=reverse*10+remainder;
        n=n/10;
    }
    printf("reverse of the number is:%d\n",reverse);
    return 0;
}