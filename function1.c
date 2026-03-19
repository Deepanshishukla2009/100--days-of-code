#include<stdio.h>
int sum(int a,int b);
int sum (int a,int b)
{
    int c;
    c=a+b;
    return c;
}
void main()
{
    int x,y,z;
    printf("enter two numbers:");
    scanf("%d%d",&x,&y);
    z=sum(x,y);
    printf("sum=%d",z);
}