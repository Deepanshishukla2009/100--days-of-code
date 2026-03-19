#include <stdio.h>
int BMI(float weight, float height) {
   float bmi=weight/(height*height);
   printf("bmi=%.2f",bmi);
    
    if (bmi < 15)
        return 0;
    else if (bmi >= 15.1 && bmi <= 17.5)
        return 1;
    else if (bmi >= 17.6 && bmi <= 18.5)
        return 2;
    else if (bmi >= 18.6 && bmi <= 24.9)
        return 3;
    else if (bmi >= 25 && bmi <= 25.9)
        return 4;
    else if (bmi >= 30 && bmi <= 39.9)
        return 5;
    else if (bmi >= 40)
        return 6;
    else
        return 7;
    
}

int main() {
    float weight, height;
    int result;
    printf("Enter weight in kg: ");
    scanf("%f", &weight);
    printf("Enter height in meters: ");
    scanf("%f", &height);
   result= BMI(weight, height);
    switch(result)
    {
        case 0:printf("starvation\n");break;
        case 1:printf("anorexic\n");break;
        case 2:printf("underweight\n");break;
        case 3:printf("ideal weight\n");break;
        case 4:printf("overweight\n");break;
        case 5:printf("obese\n");break;
        case 6:printf("morbidity obese\n");break;
        case 7:printf("not classified");
    }
    return 0;
}
