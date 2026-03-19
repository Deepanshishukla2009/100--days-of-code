#include<stdio.h>
#include<conio.h>
int main()
{
    int days;
    int fine=0;
    printf("enter number of days the book is late:");
    scanf("%d",&days);
    if(days<=0)
    {
        printf("no fine\n");
    }
    else if(days<=5)
    {
        fine=days*2;
        printf("fine is %d\n",fine);
    }
    else if (days<=10)
     {
        fine = days*4;
        printf("fine is %d\n", fine);
    }
    else if (days<=30)
     {
        fine = days*6;
        printf("fine is %d\n", fine);
    }
    else
     {
        printf("Membership Cancelled\n");
    }
        return 0;
}