#include<stdio.h>
#include<conio.h>
int main()
{
    int n,counter=1;
    printf("enter a number:");
    scanf("%d",&n);
    while(counter<=10)
    {
        printf("%d x %d = %d\n",n,counter,n*counter);
        counter++;
    }
    return 0;
}