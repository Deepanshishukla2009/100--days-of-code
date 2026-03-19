#include<stdio.h>
#include<conio.h>
int main()
{
    int l,b,area,perimeter;
    printf("enter the length of rectangle:");
    scanf("%d",&l);
    printf("enter the breadth of rectangle:");
    scanf("%d",&b);
    area=l*b;
    printf("the area of rectangle is:%d\n",area);
    perimeter=2*(l+b);
    printf("the perimeter of rectangle is:%d\n",perimeter);
    return 0;
}