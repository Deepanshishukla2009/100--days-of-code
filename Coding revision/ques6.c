#include<stdio.h>
#include<conio.h>
int main()
{
    int a,b,temp=0;
    printf("enter the value of a and b:");
    scanf("%d%d",&a,&b);
    printf("before swapping a=%d b=%d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("after swapping a=%d b=%d",a,b);
    return 0;
}