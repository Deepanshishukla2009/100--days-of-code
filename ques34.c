#include<stdio.h>
#include<conio.h>
int main()
{
    int n,temp=1,i;
    printf("enter the number:");
    scanf("%d",&n);
    if(n<=1)
    {
        temp=0;
    }
    else
    {
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                temp=0;
                break;
            }
        }
    }
    if(temp){
    printf("prime\n");
    }
    else{
    printf("not prime");
    }
    return 0;
}