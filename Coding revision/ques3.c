#include<stdio.h>
#include<conio.h>
int main()
{
    float marks1,marks2,marks3,marks4,marks5,total,aggregate,percentage;
    printf("enter the marks of 5 subjects:");
    scanf("%f%f%f%f%f",&marks1,&marks2,&marks3,&marks4,&marks5);
    total=marks1+marks2+marks3+marks4+marks5;
    printf("the total marks is:%.2f\n",total);
    aggregate=total/5;
    printf("the aggregate marks is:%.2f\n",aggregate);
    percentage=(total/500)*100;
    printf("the percentage is:%.2f",percentage);
    return 0;
}