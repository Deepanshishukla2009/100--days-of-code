#include<stdio.h>
#include<conio.h>
int main()
{
    float basic_salary,DA,HRA,gross_salary;
    printf("enter the basic salary:");
    scanf("%f",&basic_salary);
    DA=0.4*basic_salary;
    printf("the DA is:%.2f\n",DA);
    HRA=0.2*basic_salary;
    printf("the HRA is:%.2f\n",HRA);
    gross_salary=basic_salary+DA+HRA;
    printf("the gross salary is:%.2f",gross_salary);
    return 0;
}