//Q56: Read and print elements of a one-dimensional array.//

/*
Sample Test Cases:
Input 1:
3
10 20 30
Output 1:
10 20 30

Input 2:
5
1 2 3 4 5
Output 2:
1 2 3 4 5

*/
#include<stdio.h>
int main()
{
    int arr[5];
    printf("enter the elements of the array\n:");
    for(int i=1;i<=5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for( int i=1;i<=5;i++)
    {
        printf("the elements of array are:%d\n",arr[i]);
    }
    return 0;
}