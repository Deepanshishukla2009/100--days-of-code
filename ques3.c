#include<stdio.h>
#include<conio.h>
int main()
{
    int l,b,area,perimeter;
    printf("enter length of recctangle:");
    scanf("%d",&l);
    printf("enter breadth of rectangle:");
    scanf("%d",&b);
    area=l*b;
    printf("area of rectangle:%d\n",area);
    perimeter=2*(l+b);
    printf("perimeter of rectangle:%d",perimeter);
    return 0;
}
