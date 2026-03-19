#include<stdio.h>
#include<conio.h>
int main()
{
    int c,ac;
    float percentage;
    printf("enter the total classes held:");
    scanf("%d",&c);
    printf("enter the total classes attended:");
    scanf("%d",&ac);
    percentage=(ac*100)/c;
    printf("the attendance percentage is:%.2f\n",percentage);
    if(percentage>=75)
    {
        printf("you are allowed to sit in exam\n");
    }
    else
    {
        printf("you are not allowed to sit in exam\n");
    }
    return 0;
}