#include<stdio.h>
#include<conio.h>
int main()
{
    float weight,height,BMI;
    printf("enter weight in kg:");
    scanf("%f",&weight);
    printf("enter height in meters:");
    scanf("%f",&height);
    if(height==0)
    {
      printf("height cannot be zero");
    }
    else{
    BMI=weight/(height*height);
    printf("BMI is %.2f\n",BMI);
    switch((BMI<=15)?1:(BMI>=15.1 && BMI<=17.5)?2:(BMI>=17.6 && BMI<=18.5)?3:(BMI>=18.6 && BMI<=24.9)?4:(BMI>=25 && BMI<=29.9)?6:7)
    {
        case 1:
        printf("suffering from starvation\n");
        break;
        case 2:
        printf("suffering from anorexic\n");
        break;
        case 3:
        printf("underweight\n");
        break;
        case 4:
        printf("ideal weight\n");
        break;
        case 5:
        printf("overweight\n");
        break;
        case 6:
        printf("suffering from obeseity\n");
        break;
        case 7:
        printf("suffering from morbid obeseity\n");
        break;
        default:
        printf("invalid BMI\n");
    }
}
    return 0;
}