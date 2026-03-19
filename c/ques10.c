#include<stdio.h>
#include<conio.h>
int main()
{
    int time,hour,minute,second;
    printf("enter time in seconds:");
    scanf("%d",&time);
    hour=time/3600;
    minute=(time%3600)/60;
    second=(time%60);
    printf("time= %2d:%2d:%2d\n", hour, minute, second);
    return 0;
}