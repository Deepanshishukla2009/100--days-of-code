#include<stdio.h>
#include<conio.h>
int main()
{
    int r;
    float area,circumference,pi=3.14;
    printf("enter radius of circle:");
    scanf("%d",&r);
    area=pi*r*r;
    printf("area of circle:%.2f\n",area);
    circumference=2*pi*r;
    printf("circumference of circle:%.2f",circumference);
    return 0;
}
