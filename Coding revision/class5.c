#include<stdio.h>
int main()
{
    int arr[100],n,i,sum=0;
    printf("enter how many elements you want to print:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    printf("Sum = %d\n", sum);
    return 0;
}