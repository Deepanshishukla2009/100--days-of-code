#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[5],i;
    printf("enter five numbers:");
    for(i=4;i>=0;i--)
    {
        scanf("%d",&arr[i]);
    }
    printf("The entered numbers in array are :");
    for(i=4;i>=0;i--)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
