#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    float a,b,c;
    printf("enter sides of triangle:");
    scanf("%f%f%f",&a,&b,&c);
    if(a+b>c && a+c>b && b+c>a)
    {
        printf("triangle is valid\n");
    }
    else
    {
        printf("triangle in invalid\n");
    }
    if(a==b && b==c)
    {
        printf("triangle is equilateral\n");
    }
    else if(a==b || b==c || a==c)
    {
        printf("triangle is isosceles\n");
    }
     else if ((a * a == b * b + c * c) ||(b * b == a * a + c * c) || (c * c == a * a + b * b))
    {
        printf("triangle is right angeled\n");
    }
    else
    {
        printf("triangle is scalene\n");
    }
    return 0;
}