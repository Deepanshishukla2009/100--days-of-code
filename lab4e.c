#include<stdio.h>
#include<conio.h>
int main()
{
    float l1,l2,l3,b1,b2,b3,perimeter1,perimeter2,perimeter3,highest_perimeter;
    printf("enter dimensions of first rectangle:");
    scanf("%f%f",&l1,&b1);
    printf("enter dimensions of second rectangle:");
    scanf("%f%f",&l2,&b2);
    printf("enter dimensions of third rectangle:");
    scanf("%f%f",&l3,&b3);
    perimeter1=2*(l1+b1);
    perimeter2=2*(l2+b2);
    perimeter3=2*(l3+b3);
    (perimeter1>perimeter2)?
((perimeter1>perimeter3)?printf("rectangle1 has highest perimeter")
:printf("rectangle3 has highest perimeter")):
((perimeter2>perimeter3)?printf("rectangle2 has highest perimeter")
:printf("rectangle3 has highest perimeter"));
    return 0;
}