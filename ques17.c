#include<stdio.h>
#include<conio.h>
int main()
{
    int roots,a,b,c;
    float d;
    printf("enter the coefficient of x^2:");
    scanf("%d",&a);
    printf("enter the coefficient of x:");
    scanf("%d",&b);
    printf("enter the constant term:");
    scanf("%d",&c);
    d=(b*b)-(4*a*c);
    if(d>0)
    {
        printf("the roots are real and distinct\n");
    }
    else if(d==0)
    {
        printf("the roots are real and equal\n");
    }
    else
    {
        printf("the roots are imaginary\n");
    }
    return 0;
}