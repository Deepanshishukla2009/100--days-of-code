#include<stdio.h>
int main()
{
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
