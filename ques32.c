#include<stdio.h>
#include<conio.h>
int main()
{
    int num, original, reversed = 0, remainder;
    // Input number
    printf("Enter a number: ");
    scanf("%d", &num);
    original = num; // Store original number
    // Reverse the number
    while (num != 0) 
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    // Check palindrome
    if (original == reversed)
    {
        printf("%d is a Palindrome.\n", original);
    }
    else
    {
        printf("%d is not a Palindrome.\n", original);
    }
    return 0;
}