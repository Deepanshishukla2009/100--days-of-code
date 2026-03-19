#include<stdio.h>
int main()
{
    int arr[5]={10,20,30,40,50},i;
    printf("in reverse the elements of array are:");
    for(i=4;i>=0;i--)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}