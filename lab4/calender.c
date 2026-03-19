#include <stdio.h>
int isLeapyear(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;
    else
        return 0;
}
int firstJanDay(int year) {
    int total_days = 0;
    int i;
    for (i = 1; i < year; i++) {
        if (isLeapyear(i))
            total_days += 366;
        else
            total_days += 365;
    }
       return total_days % 7;
}

int main() {
    int year, dayofweek;
    printf("Enter any year: ");
    scanf("%d", &year);
    dayofweek=firstJanDay(year);
    printf("The day on 1st January of %d is ", year);
    switch(dayofweek) {
        case 0: printf("Monday\n"); break;
        case 1: printf("Tuesday\n"); break;
        case 2: printf("Wednesday\n"); break;
        case 3: printf("Thursday\n"); break;
        case 4: printf("Friday\n"); break;
        case 5: printf("Saturday\n"); break;
        case 6: printf("Sunday\n"); break;
    }
    return 0;
}

