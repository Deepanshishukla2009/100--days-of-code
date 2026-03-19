#include<stdio.h>
#include<conio.h>
int main()
{
    float weight,height,BMI;
    printf("enter weight in kg:");
    scanf("%f",&weight);
    printf("enter height in meters:");
    scanf("%f",&height);
    if(height>=0)
    {
        printf("height cannot be zero or negative\n");
    }
    else
    {
    BMI=weight/(height*height);
    printf("BMI is %f\n",BMI);
    if(BMI<=15)
    {
        printf("suffering from starvation\n");
    }
    else if(BMI>=15.1 && BMI<=17.5)
    {
        printf("suffering from anorexic\n");
    }
    else if(BMI>=17.6 && BMI<=18.5)
    {
        printf("underweight\n");
    }
    else if(BMI>=18.6 && BMI<=24.9)
    {
        printf("ideal weight\n");
    }
    else if(BMI>=25 && BMI<=29.9)
    {
        printf("overweight\n");
    }
    else if(BMI>=30 && BMI<=40)
    {
        printf("suffering from obeseity\n");
    }
    else
    {
        printf("suffering from morbid obeseity\n");
    }
}
    return 0;
}