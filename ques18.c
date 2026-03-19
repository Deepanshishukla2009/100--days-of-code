#include<stdio.h>
#include<conio.h>
int main()
{
    float percentage;
    char grade;
    printf("enter the percentage:");
    scanf("%f",&percentage);
    switch((percentage>=90)?'A':(percentage>=80)?'B':(percentage>=70)?'C':(percentage>=60)?'D':(percentage>=50)?'E':'F')
    {
        case 'A':
        printf("grade:A\n");
        break;
        case 'B':
        printf("grade:B\n");
        break;
        case 'C':
        printf("grade:C\n");
        break;
        case 'D':
        printf("grade:D\n");
        break;
        case 'E':
        printf("grade:E\n");
        break;
        case 'F':
        printf("grade:F\n");
        break;
        default:
        printf("invalid percentage\n");
    }
    return 0;
}