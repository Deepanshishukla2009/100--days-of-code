#include <stdio.h>
#include<conio.h>
int main()
 {
    int year, i, days = 0, dayOfWeek;
    printf("Enter the year:");
    scanf("%d", &year);
    for (i = 1; i < year; i++)
     {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) 
        {
            days += 366;
        } 
        else 
        {
            days += 365;
        }
    }
    days += 1; 
    dayOfWeek = days % 7;
    switch (dayOfWeek)
     {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
    }
    return 0;
}