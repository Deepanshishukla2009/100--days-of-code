#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{
    char ch;
    printf("enter a character:");
    scanf("%c",&ch);
    if(isalpha(ch))
    {
        if(isupper(ch))
        {
            printf("uppercase alphabet");
        }
        else
        {
            printf("lowercase alphabet");
        }
    }
    else if(isdigit(ch))
    {
        printf("digit");
    }
    else
    {
        printf("special character");
    }
    return 0;
}
