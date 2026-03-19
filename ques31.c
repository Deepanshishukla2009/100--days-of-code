#include<stdio.h>
#include<conio.h>
int main()
{
    int n,binary[32],i=0,j;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n == 0)
     {
        printf("Binary representation: 0\n");
        return 0;
    }
    // Convert to binary
    while (n > 0) 
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    // Print binary in reverse order
    printf("Binary representation: ");
    for (j = i - 1; j >= 0; j--)
     {
        printf("%d", binary[j]);
    }
    printf("\n");
    return 0;
}
