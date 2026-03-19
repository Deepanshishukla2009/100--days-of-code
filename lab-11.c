#include<stdio.h>
#include<conio.h>
int main()
{ 
    float r,area,circumference,pi=3.14;
    printf("enter radius of circle:");
    scanf("%f",&r);
    area=pi*r*r;
    printf("area of circle is %.2f\n",area);
    circumference=2*pi*r;
    printf("circumference of circle is %.2f\n",circumference);
    return 0;
}