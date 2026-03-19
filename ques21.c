#include<stdio.h>
#include<conio.h>
int main()
{
    int month,days;
    printf("enter month number(1-12):");
    scanf("%d",&month);
    switch(month)
    {
        case 1:
        days=31;
        printf("january,%d days\n",days);
        break;
        case 2:
        days=28;
        printf("february, %d days\n",days);
        break;
        case 3:
        days=31;
        printf("march,%d days\n",days);
        break;
        case 4:
        days=30;
        printf("april,%d days\n",days);
        break;
        case 5:
        days=31;
        printf("may,%d days\n",days);
        break;
        case 6:
        days=30;
        printf("june,%d days\n",days);
        break;
        case 7:
        days=31;
        printf("july,%d days\n",days);
        break;
        case 8:
        days=31;
        printf("august,%d days\n",days);
        break;
        case 9:
        days=30;
        printf("september,%d days\n",days);
        break;
        case 10:
        days=31;
        printf("october, %d days\n",days);
        break;
        case 11:
        days=30;
        printf("november,%d days\n",days);
        break;
        case 12:
        days=31;
        printf("december,%d days\n",days);
        break;
        default:
        printf("invalid month number\n");
    }
    return 0;
}