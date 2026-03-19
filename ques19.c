#include<stdio.h>
#include<conio.h>
int main()
{
    int a,b,c;
    printf("enter three sides of triangle:");
    scanf("%d%d%d",&a,&b,&c);
    if(a+b>c && b+c>a && c+a>b)
    {
        if(a==b && b==c)
        {
            printf("equilateral triangle\n");
        }
        else if(a==b || b==c || c==a)
        {
            printf("isosceles triangle\n");
        }
        else
        {
            printf("scalene triangle\n");
        }
    }
    else
    {
        printf("not a valid triangle\n");
    }
    return 0;
}