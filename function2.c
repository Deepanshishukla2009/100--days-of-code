#include <stdio.h>
void calculateBMI(float weight, float height) {
    if (height == 0) {
        printf("Height cannot be zero.\n");
        return;
    }
    float BMI = weight / (height * height);
    printf("BMI is %.2f\n", BMI);
    int category = (BMI <= 15) ? 1 :
                   (BMI > 15 && BMI <= 17.5) ? 2 :
                   (BMI > 17.5 && BMI <= 18.5) ? 3 :
                   (BMI > 18.5 && BMI <= 24.9) ? 4 :
                   (BMI >= 25 && BMI <= 29.9) ? 5 :
                   (BMI >= 30 && BMI <= 39.9) ? 6 : 7;
    switch (category) {
        case 1:
            printf("Suffering from starvation\n");
            break;
        case 2:
            printf("Suffering from anorexia\n");
            break;
        case 3:
            printf("Underweight\n");
            break;
        case 4:
            printf("Ideal weight\n");
            break;
        case 5:
            printf("Overweight\n");
            break;
        case 6:
            printf("Suffering from obesity\n");
            break;
        case 7:
            printf("Suffering from morbid obesity\n");
            break;
        default:
            printf("Invalid BMI\n");
    }
}

int main() {
    float weight, height;
    printf("Enter weight in kg: ");
    scanf("%f", &weight);
    printf("Enter height in meters: ");
    scanf("%f", &height);
    calculateBMI(weight, height);
    return 0;
}
