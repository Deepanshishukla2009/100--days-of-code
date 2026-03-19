#include<stdio.h>
#include<conio.h>
int main()
{
    float distance,meter,feet,inches,centimeter;
    printf("enter the distance in kilometers:");
    scanf("%f",&distance);
    meter=distance*1000;
    printf("the distance in meter is:%.2f\n",meter);
    feet=distance*3280.84;
    printf("the distance in feet is:%.2f\n",feet);
    inches=distance*39370.1;
    printf("the distance in inches is:%.2f\n",inches);
    centimeter=distance*100000;
    printf("the distance in centimeter is:%.2f",centimeter);
    return 0;
}