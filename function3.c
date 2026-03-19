#include<stdio.h>
void swap(int a,int b);
void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("after swapping in function a=%d b=%d\n",a,b);
}
void main()
{
    int x,y;
    printf("enter two numbers:");
    scanf("%d%d",&x,&y);
    printf("before swapping in main x=%d y=%d\n",x,y);
    swap(x,y);
}