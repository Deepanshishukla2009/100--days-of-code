#include <stdio.h>

int main()
{
    int n, i, j, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (i = n; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        for (k = 1; k <= 2 * (n - i) - 1; k++)
        {
            printf("  ");
        }
        if (i != n) 
        {
            for (j = i; j >= 1; j--)
            {
                printf("%d ", j);
            }
        }
        else
        {
            for (j = i - 1; j >= 1; j--)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}