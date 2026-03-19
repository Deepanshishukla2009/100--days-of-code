#include<stdio.h>
#include<conio.h>
int main() 
{
    int num,i,a, positivecount = 0, negativecount = 0, zerocount = 0;
    char choice;
    printf("enter how many times you want to check approximately:");
    scanf("%d",&a);
    for (i=1;i<a;i++) {
        printf("enter the number\n");
        scanf("%d", &num);
        if (num > 0) 
        {
            positivecount++;
        } else if (num < 0)
         {
            negativecount++;
        } else
         {
            zerocount++;
        }
        printf("do you want to continue y/n\n");
        scanf(" %c", &choice);
        if (choice == 'n') 
        {
            break;
        }
    }
    printf("positive count is %d\n", positivecount);
    printf("negetive count is %d\n", negativecount);
    printf("zero count is %d\n", zerocount);
return 0;
}