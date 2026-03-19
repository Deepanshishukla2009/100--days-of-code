#include<stdio.h>
#include<conio.h>
int main()
{
    float l,b,r,pi=3.14,area,perimeter,circumference;
    printf("enter the length and breadth of rectangle:");
    scanf("%f%f",&l,&b);
    area=l*b;
    printf("the area of rectangle is:%.2f\n",area);
    perimeter=2*(l+b);
    printf("the perimeter of rectangle is:%.2f\n",perimeter);
    printf("enter the radius of circle:");
    scanf("%f",&r);
    area=pi*r*r;
    printf("the area of circle is:%.2f\n",area);
    circumference=2*pi*r;
    printf("the circumference of circle is:%.2f",circumference);
    return 0;
}