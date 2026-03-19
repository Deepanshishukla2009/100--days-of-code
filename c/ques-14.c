#include<stdio.h>
#include<conio.h>
int main()
{
    char alphabet,vowel,consonant;
    printf("enter an alphabet:");
    scanf("%c",&alphabet);
    if(alphabet=='a' || alphabet=='e' || alphabet=='i' || alphabet=='o' || alphabet=='u' || alphabet=='A' || alphabet== 'E' || alphabet=='I' || alphabet=='O' || alphabet=='U')
    {
        printf("%c is a vowel\n",alphabet);
    }
    else
    {
        printf("%c is a consonant\n",alphabet);
    }
    return 0;
}