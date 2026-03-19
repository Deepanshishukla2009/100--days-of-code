#include<stdio.h>
#include<conio.h>
int main()
{
    char grade;
    printf("enter your grade:");
    scanf("%c",&grade);
    switch(grade)
    {
        case 'A':
        case 'a':
        printf("excellent");
        break;
        case 'B':
        case 'b':
        printf("very good");
        break;
        case 'C':
        case 'c':
        printf("good");
        break;
        case 'D':
        case 'd':
        printf("fair");
        break;
        case 'E':
        case 'e':
        printf("meets expectations");
        break;
        case 'F':
        case 'f':
        printf("fails to meet expectations");
        break;
        default:
        printf("invalid grade");
    }
    return 0;
}